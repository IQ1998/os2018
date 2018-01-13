#include <stdio.h>
#include<unistd.h>

int main(){
	int pid = fork();
	
	if(pid == 0){
		printf("Child1 launching ps -ef\n");
		char *args[] = {"bin/ps", "-ef", NULL};
		execvp("/bin/ps", args);
		printf("blahblah");
		
	}
	else{	
		
		printf("Parent after 1st fork\n");
		int pid2 = fork();
		if(pid2 == 0){
			printf("Child2 launching free -h\n");
			char *args2[] = {"bin/free", "-h", NULL};
			printf("blah");
			execvp("free", args2);
		}
		
	}
	return 0;
}
