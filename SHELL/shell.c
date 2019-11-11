#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char* argv[]) {
	char* garden[30];
	int length = 0,i;
	char s[100];
	printf("Enter command:  ");
	fgets(s,100,stdin);
	char *token;

       
	token = strtok(s," \n");	
	while (token != NULL){

		garden[length]=token;
		length++;
		token = strtok(NULL," \n");  
	}

	for(i=0; i<length;i++){
             if(garden[i]=="&"){
                 execve(garden[i],garden,NULL);
}
printf("%s\n",garden[i]);

	}
 
      
	int x = fork();
	if (x==0){
		//child
		execvp(garden[0],garden);
		exit(-1);
	}

	// parent
	wait(NULL);           
}


