#include <stdio.h>

int main() {
	int i;
	char *s;
	char *lol="lol";
	char *derp="derp";
	static void *lab[]={&&LABEL1,&&LOL1,&&LOL2};

	goto SKP;
	LABEL1:; {
		printf("%s\n",s);
	} goto *lab[i];
	SKP:;

	i=1;
	s=lol;
	goto LABEL1;
	LOL1:;

	i=2;
	s=derp;
	goto LABEL1;
	LOL2:;

	printf("OP!\n");
	return 0;
}
