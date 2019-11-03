#include <stdio.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
	int opt;
	int nlf = 1; // New line flag.
	int hf = 0; // Help flag. 

	if (argc == 1)
		return 0;

	while ((opt = getopt(argc, argv, "nh")) != -1)
	{
		switch(opt)
		{
			case 'n':
				nlf = 0;
				break;
			case 'h':
				hf = 1;
				break;
			default:
				fprintf(stderr, "Unkown option. Use -h for help.");
		}
	}

	if (hf)
	{
		fprintf(stdout, "Writes all the arguments to the stdout separated by a ' ' blank character followed by a new line character. \n");
		fprintf(stdout, "Use the -n flag to skip the newline. \n");

	}

	for(int i = 1; i < argc; i++)
		fprintf(stdout, "%s ", argv[i]);

	if (nlf)
		fprintf(stdout, "\n");
	
	return 0;
}
