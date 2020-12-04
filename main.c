//Ivan Rao
//Systems

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(){
	srand(time(NULL));
	int status;
	int pid = getpid();
	printf("I am the parent! pid: %d\n", pid);
	int c1, c2;
	c1 = fork();
	if (getpid() == pid) c2 = fork();
	if (!c1){
		printf("I am Child 1, pid: %d\n", getpid());
		int random = (rand() % (10-2+1))+2;
		sleep(random);
		printf("Child 1 is done\n");
		return random;
	}
	else {
		if (!c2) {
			printf("I am Child 2, pid: %d\n", getpid());
			rand();
			int random = (rand() % (10-2+1))+2;
			sleep(random);
			printf("Child 2 is done\n");
			return random;
		}
		else{
		int childpid = wait (&status);
		int time = WEXITSTATUS(status);
		printf("Completed child's PID: %d, time asleep: %d\n", childpid, time);
		}
	}
	return 0;

}
