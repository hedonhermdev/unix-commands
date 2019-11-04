#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_COUNT 10
#define MAXLEN 1024
int main(int argc, char **argv)
{
	int opt;
	int count = 0;
	int bflag = 0;
	int bytes = 0;

	FILE *f;
	
	while ((opt = getopt(argc, argv, "n:c:")) != -1)
	{
		switch(opt)
		{
			case 'n':
				count = atoi(optarg);
				if(!count)
				{
					fprintf(stderr ,"ILLEGAL HEAD COUNT: %s", optarg);
					exit(EXIT_FAILURE);
				}
				break;

			case 'b':
				bytes = atoi(optarg);
				bflag = 1;
				if (!bytes)
				{
					fprintf(stderr, "ILLEGAL BYTES COUNT: %s", optarg);
					exit(EXIT_FAILURE);
				}
				break;
		}
	}
	
	argc -= optind;
	argv +=optind;

	if (!bflag && !count)
	{
		count = DEFAULT_COUNT;
	}

	for(int i = 0; i < argc; i++)
	{

		f = fopen(argv[i], "r");
		if (f == NULL)
		{
			fprintf(stderr, "Could not open file");
			exit(EXIT_FAILURE);
		}
		printf("\n==>%s<==\n", argv[i]);
		
		if (!bflag)
		{
			char line[MAXLEN];
			int lc = count;
			while(fgets(line, MAXLEN, f) && lc != 0)
			{
				fprintf(stdout, "%s", line);
				lc--;
			}
		} else {
			unsigned long bc = bytes;
			char c;
			while ((c = fgetc(f)) && bc > sizeof(char))
			{
				printf("%c", c);
				bc -= sizeof(char);
			}
		}
	}
	return 0;
}
