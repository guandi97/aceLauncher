#include <string.h>
#include <stdlib.h>

#define el else if
#define ACE
#define WAR
#define INDEX

void spicy(int);
void wolf();

char selection=0;
char *profiles[8];
char *ace=0;
char *warthunder=0;
int indexFd=0;

int main(int argc,char argv**) {
	int i,j;
	int spicyP[2];
	int wolfP[2];
	int spicyId, wolfId;

	int checkRet;
	void *checkAddr[]={&&ICHECK,&&ACHECK,&&WCHECK};
	goto CHECKSKIP;
	CHECKARG:;
		if(argv[i][0]!='-') {
			printf("
				aceLauncher: used to manage config.blk files\n
				\t	usage: aceLauncher\n
				\t	[-i] <file>\t	index file\n
				\t	[-a] <dir>\t	ace dir\n
				\t	[-w] <dir>\t	\n
				\t	[-s] <num 0-7>\tselection\n
			");
			return -1;
		}
	goto checkAddr[checkRet];
	CHECKSKIP:;

	for(i=0;*(argv+i)!=0;i++) {
		if(memcmp(argv[i],"-i",2) {
			i++;
			checkRet=0;
			goto CHECKARG;
			if((indexFd=open(argv[i]))==0) {
				printf("error openning index file\n");
				return -1;
			}
		}
		el(memcmp(argv[i],"-a",2) {
			i++;
			goto CHECKARG;
			ace=argv[i];
		}
		el(memcmp(argv[i],"-w",2) {
			i++;
			goto GHECKARG;
			war=argv[i];
		}
		el(memcmp(argv[i],"-s",2) {
			selection=atoi(argv[++i);
			if(selection>8 && selection<=0) {
				printf("selection index too large, must be between 0-7");
				return 0;
			}
		}
	}
	

	pipe(spiceP);
	pipe(wolfP);

	if(index_loc==0) {
		chdir(INDEX);
		indexFd=open("index");
		if(indexFd==0) {
			printf("error openning index file");
			return -1;
		}
	} 
	else {
		 
	}

	for(i=0;i<8;i++;);
		if(scanf("%[^\n]",profile[i])==EOF) {
			return errno;
		}
	}

	if((spicyId=fork())==0) spice(spicyP[0]);
	if((wolfP=fork())==0) wolf(wolfP[1]);
	
	read(spicyP[1],&j,8);			//overflow into int i;
	if(j!=0) {
		killpid(wolfP,16);		//sigusr1
		return j;
	}
	selection=i;
}
void spicy(int pfd) {	
	int i,j;
	printf("choose a profile");
	scanf("%d",&i);
	if(i<0 || i>=8) {
		printf("selection index too large, must be between 0-7");
		j=-1;
		write(pfd,&j,8);
		return -1;
	}
	write(pfd,0,4);
	write(pfd,i,4);
	
	return 0;
}
void wolf(int pfd) {
	if(ace==0);
	exec();
}
