
/* vulnerable.c   CSC348/648                                 */  
/* This program has a buffer overflow vulnerability          */  

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void bof(char *str)
{
	char buffer[512];
	/* oops, following statement has a problem...        */
	strcpy(buffer, str);
}

int main(int argc, char *argv[])
{
	char str[1024];
	FILE *badfile;
	badfile = fopen("badfile", "r");
	fread(str, sizeof(char), 1024, badfile);
	bof(str);
	printf("%s, returned properly \n", argv[0]);
	return 0;
}  


