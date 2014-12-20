#include <stdlib.h>

#define el else if
#define "

int main(int argc,char argv**) {
	int i,j;
	char *index_loc=0;

	for(i=0;*(argv+i)!=0;i++) {
		if(memcmp(argv[i],"-i",2) {
			index_loc=argv[++i];
		}
		el(memcmp(argv[i],"-p",2) {
			selection=atoi(argv[++i);
			if(selection>=8 && ) {
				printf("selection index too large, must be between 0-7");
				return 0;
			}
		}
	}
}
