#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <pwd.h>
#include <string.h>

#define WAR "/My Games/WarThunder"
#define ACE "/Library/Application Support/Steam/SteamApps/common/War Thunder/WarThunderLauncher.app/Contents/WarThunder.app/Contents/MacOS"

void ace(char*);

int main() {
	size_t j;
	int i;
	char *profiles[8]={0};
	uid_t udi=getuid();

	struct passwd *pwd=getpwuid(udi);
	if(pwd==0) {
		printf("getwuid failure");
		return errno;
	}
	i=strlen(pwd->pw_dir);
	char *wd=malloc(sizeof(WAR)+i);
	memcpy(wd,pwd->pw_dir,i);
	memcpy(wd+i,WAR,sizeof(WAR));
	chdir(wd);

	FILE *index=fopen("./index","r");
	if(index==0) {
		printf("error opening index\n");
		return errno;
	}

	{
		i=j=0;
		auto int k;
		while((k=getline((char**)&profiles[i],&j,index))!=-1) {
			*(profiles[i]+k-1)=0;
			if(i>7) {
				printf("8 entries max");
				return 0;
			}
			i++;
		}
	}
	fclose(index);

	for(j=0;j<i;j++) printf("[%zu]: %s\n",j,profiles[j]);
	printf("choose one: ");
	scanf("%d",&i);
	if(i<0 || i>j) {
		printf("invalid value\n");
		return 0;
	}
	j=i;

	if(rename(profiles[j],"./Saves/profile.config.blk")==-1) {
		printf("error renaming to profile\n");
		return errno;
	}

	int pid=fork();
	if(pid==0) ace(pwd->pw_dir);
	waitpid(pid,&i,0);

	rename("./Saves/profile.config.blk",profiles[j]);
	
	printf("exiting\n");
	return 0;

}
void ace(char *pw_dir) {
	int i=strlen(pw_dir);
	char *wd=malloc(sizeof(ACE)+i);
	memcpy(wd,pw_dir,i);
	memcpy(wd+i,ACE,sizeof(ACE));
	chdir(wd);

	execl("aces","aces",0);
}
