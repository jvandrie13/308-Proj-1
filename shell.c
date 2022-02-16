#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


#define clear() printf("\033[H\033[J")

// Function to print out beginning information
void initialize()
{
	clear();
    	printf("\n\n\n\n******************************************");
	printf("\n\n\n\t****308 Unix Shell****");
	printf("\n\n\t-It's Mental Innit?-");
	printf("\n\n\n\n******************************************");

	char* username = getenv("USER");
	printf("\n\n\nUSER is: @%s", username);
	printf("\n");
	sleep(10);
	clear();
}

//Print Working Directory
void printDir()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\n%s\n", cwd);
}

//Change Directory
void changeDir(char dir[]){
	
	if(dir){
		chdir(dir);
	}
	else{
		chdir(getenv("HOME"));
	}

	printf("Changed Directory to:");
	printDir();
}

int main(int argc, char **argv)
{
char wd[128];

changeDir("..");
//printDir();
//initialize();
}
