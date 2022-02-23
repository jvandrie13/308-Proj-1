#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


#define clear() printf("\033[H\033[J")
#define BUFFER_SIZE BUFSIZ

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

//Print Working Directory (pwd)
void printDir()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("Working Directory: %s\n", cwd);
}


//Change Directory (cd)
void changeDir(char dir[]){
	
	if(dir){
		chdir(dir);
	}
	else{
		chdir(getenv("HOME"));
	}
	char cwd[1024];
    	getcwd(cwd, sizeof(cwd));
	printf("Changed Directory to: %s\n", cwd);
}

//Print Process ID (pid)
void printPID(){
	printf("Current Process ID: %d\n", getpid());
}

//Print Parent Procces ID (ppid)
void printPPID(){
	printf("Current Parent Process ID: %d\n", getppid());
}


int main(int argc, char **argv)
{
	char *p = "308sh> ";
	char cmd[100];
	char *cmds[10];
	int i, k;
	
	//check for custom name
	if (argv[1]){
		if (strcmp(argv[1], "-p") == 0){
			p = argv[2];
		}
	}

		
	while(1){
		printf("%s ", p);
		fgets(cmd, 100, stdin);

		i=0;
		cmds[i] = strtok(cmd, " \n");
		while(cmds[i] !=NULL){
			cmds[++i] = strtok (NULL, " \n");
		}
	
		if (strcmp(cmds[0], "pwd") == 0){
			printDir();
		}
		else if (strcmp(cmds[0], "pid") == 0){
			printPID();
		}
		else if (strcmp(cmds[0], "ppid") == 0){
			printPPID();
		}
		else if (strcmp(cmds[0], "cd") == 0){
			changeDir(cmds[1]);
		}
		else if (strcmp(cmds[0], "exit") == 0){
			return 0;
		}
	}
}
