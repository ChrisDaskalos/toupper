#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUF 100

int main(void)
{
	FILE *target,*source;
	int ch;
	char sourcef[BUF],targetf[BUF];

	printf("Enter name of the source file:\n");
	scanf("%s",sourcef);
	printf("Enter name of the target file:\n");
	scanf("%s",targetf);

	if((source=fopen(sourcef,"r"))==NULL)
	{
		fprintf(stderr,"Error opening file\n");
		exit(EXIT_FAILURE);
	}
	
	if((target=fopen(targetf,"w"))==NULL)
	{	
		fclose(source);
		fprintf(stderr,"Error writing to file\n");
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(source)) != EOF)
    {
        if (islower(ch))
            ch = toupper(ch);
        putc(ch, target);
    }

	if (fclose(source) != 0)
        printf("Could not close file %s\n", sourcef);

    if (fclose(target) != 0)
        printf("Could not close file %s\n", targetf);

    return 0;


}
