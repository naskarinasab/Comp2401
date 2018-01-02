#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <unistd.h>
#include <sys/wait.h>

//PROTOTYPES 
int morph(char *number);
int fexists(char *fileName);

int morph(char *number){
	char * fileName = "./isPrime";
	char * paramList[3] = {"isPrime",number};
	int result = execvp(fileName,paramList);
	return result;
}


int main(int argc, char* argv[]) {
	int rc =0;
	int num;
	int status;
	int cValue;
	FILE *fp;
	char str[80];
	//check if file was given
	if(argv[1] != NULL){
		// check if file exists
  		rc = fexists(argv[1]);
		if(rc == 1){
			fp = fopen(argv[1], "r");
			fread(&num, sizeof(int), 1, fp);
			fclose(fp);
			sprintf(str, "%d", num);
			pid_t pid = fork();
			if (pid == 0) {
				morph(str);
			} 
			// parent process instructions
			while (wait(&status) != pid){
				//Gotta wait for child to finish	
			}
			cValue = WEXITSTATUS(status);
			if(cValue == 1) printf("%d is a prime number.\n", num);
			else if(cValue == 0) printf("%d is not a prime number.\n", num);
			else printf("There was an error. The number evaluated to 2.\n");
			return 0;
 		 }
		printf("File %s.bin does not exist\n",argv[1]);
		return 1;
	}
	printf("Missing file in command entered. Usage: singlePrime fileName.\n");
 	return 1;
}

int fexists(char *fileName)
{

    FILE *fp = NULL;
    int rc = 0;

	// open the file
	fp = fopen(fileName, "r");

	if(fp != NULL){
		fclose(fp);
		return 1;
	}
	return 0;
}
