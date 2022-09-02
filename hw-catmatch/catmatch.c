// A. Executable program - > 1
// B. System Call ->  2
// C. Library call -> 3

// Section numbers for kill ->  1, 2
// Section numbers for exit -> 2, 3
// Section number for open -> 2

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
//
// Section numbers for socket -> 2,7
// SO_ACCEPTCONN3
// 3 man pages contain keyword references to getaddrinfo
// Null - terminated
// Integer greater than 0
//
// I completed the TMUX exercise from Part 2



#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
	int processId = getpid();
	fprintf(stderr,"%d\n\n", processId);
	//printf(stderr,"%d\n\n", processId);

	FILE *txtFile = fopen("lorem-ipsum.txt","r");
	int MAX = 100;
	char display[MAX];
	char* keyVal = getenv("CATMATCH_PATTERN");
       // printf("%s\n", keyVal);
	while(1){
		fgets(display, MAX, txtFile);
		
		if(feof(txtFile)){
			break;
		}
		char *isin = strstr(display, keyVal);
		if(isin == NULL) 
		{
			fprintf(stdout, "0 ");
		}
		else
		{
			fprintf(stdout, "1 ");
		}
		fprintf(stdout, "%s", display);
	}

	fclose(txtFile);

	return 0;
}

