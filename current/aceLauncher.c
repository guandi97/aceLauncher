#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define el else if

#ifdef __linux__
	#define ACES	"/.steam/steam/steamapps/common/War Thunder/aces"
	#define PROF 	"/.steam/steam/steamapps/common/War Thunder/profiles"
	#define INDEX 	"/.steam/steam/steamapps/common/War Thunder/profiles/index"
	#define CONFIG	"/.steam/steam/steamapps/common/War Thunder/config.blk"
#endif

int spicy(int);
int wolf();

char selection=0;
char selection_max=8;
char *profiles[8];
char *aces=0;
char *prof=0;
char *home;
int s_home;
int indexFd=0;

int main(int argc,char **argv) {
	int i,j;
	int spicyP[2];
	int wolfP[2];
	int spicyId, wolfId;
	home=getenv("HOME");
	s_home=strlen(home);

	int checkRet;
	void *checkAddr[]={&&ICHECK,&&ACHECK,&&PCHECK};
	goto CHECKSKIP;
	CHECKARG:;
		if(argv[i][0]!='-') {
			printf( 
				"acesLauncher: used to manage config.blk files\n"
				"\t	usage: acesLauncher\n"
				"\t	[-i] <file>\t	index file\n"
				"\t	[-a] <exec>\t	aces\n"
				"\t	[-p] <dir>\t	profiles\n"
				"\t	[-s] <num 0-7>\tselection\n"
			);
			return -1;
		}
	goto *checkAddr[checkRet];
	CHECKSKIP:;

	for(i=1;i<argc;i++) {
		printf("%s\n",argv[i]);
		if(memcmp(argv[i],"-i",2)) {
			i++;
			checkRet=0;
			goto CHECKARG;
			ICHECK:;
			if((indexFd=open(argv[i]))==0) {
				printf("error openning index file\n");
				return errno;
			}
		}
		el(memcmp(argv[i],"-a",2)) {
			i++;
			goto CHECKARG;
			ACHECK:;
			aces=argv[i];
		}
		el(memcmp(argv[i],"-w",2)) {
			i++;
			goto CHECKARG;
			PCHECK:;
			prof=argv[i];
		}
		el(memcmp(argv[i],"-s",2)) {
			selection=atoi(argv[++i]);
		}
	}
	

	pipe(spicyP);
	pipe(wolfP);

	if(indexFd) {
		char *index_loc=malloc(s_home+sizeof(INDEX));
		memcpy(home,index_loc,i);
		if((indexFd=open(index_loc))==-1) {
			printf("error openning index file");
			return errno;
		}
	} 
	else {
			 
	}

	for(i=0;i<8;i++) {
		if(scanf("%[^\n]",profiles[i])==EOF) {
			break;	
		}
	}
	selection_max=i;

	if((wolfId=fork())) wolf(wolfP[0]);

	if(prof) {
		prof=malloc(s_home+sizeof(PROF));
		memcpy(home,prof,s_home);
		memcpy(PROF,prof,sizeof(PROF));
	}
	chdir(prof);

	if((spicyId=fork())) spicy(spicyP[1]);

	unlink(CONFIG);
	
	read(spicyP[0],&j,8);			//overflow into int i;
	if(j!=0) {
		kill((pid_t)wolfId,16);			//sigusr1
		return j;
	}
	write(wolfP[1],&i,4);
	selection=i;
	
	return 0;
}
int spicy(int pfd) {	
	int i,j=0;
	printf("choose a profile");
	scanf("%d",&i);
	if(i<0 || i>=selection_max) {
		printf("selection index too large, must be between 0-%d",selection_max);
		j=-1;
		write(pfd,&j,8);
		return -1;
	}
	write(pfd,&j,4);
	write(pfd,&i,4);

	if(link(profiles[i],CONFIG)==-1) {
		printf("Link error");
		return errno;
	}
	
	return 0;
}
int wolf(int pfd) {
	if(aces==0) {
		aces=malloc(s_home+sizeof(ACES));
		memcpy(home,aces,s_home);
		memcpy(ACES,aces,sizeof(ACES));
	}
		
	read(pfd,&pfd,4);			//ghetto block
	execl(aces,"aces",0);
}
