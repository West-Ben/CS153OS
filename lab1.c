bplist00�_WebMainResource�	
_WebResourceTextEncodingName^WebResourceURL_WebResourceFrameName_WebResourceData_WebResourceMIMETypeUUTF-8_lhttps://ilearn.ucr.edu/bbcswebdav/pid-3418936-dt-content-rid-29559438_1/courses/CS_153_001_19W/lab1%281%29.cPO�<html><head></head><body><pre style="word-wrap: break-word; white-space: pre-wrap;">#include "types.h"
#include "user.h"

#define WNOHANG 	1

int main(int argc, char *argv[])
{
	
	int exitWait(void);
	int waitPid(void);
	int CELEBW02(void);

  printf(1, "\n This program tests the correctness of your lab#1\n");
  
  if (atoi(argv[1]) == 1)
	exitWait();
  else if (atoi(argv[1]) == 2)
	waitPid();
  else if (atoi(argv[1]) == 3)
	CELEBW02();
  else 
   printf(1, "\ntype \"lab1 1\" to test exit and wait, \"lab1 2\" to test waitpid and \"lab1 3\" to test the extra credit WNOHANG option \n");
  
    // End of test
	 exitS(0);
	 return 0;
 }
  
int exitWait(void) {
	  int pid, ret_pid, exit_status;
       int i;
  // use this part to test exit(int status) and wait(int* status)
 
  printf(1, "\n  Parts a &amp; b) testing exit(int status) and wait(int* status):\n");

  for (i = 0; i &lt; 2; i++) {
    pid = fork();
    if (pid == 0) { // only the child executed this code
      if (i == 0)
      {
      printf(1, "\nThis is child with PID# %d and I will exit with status %d\n", getpid(), 0);
      exitS(0);
  }
      else
      {
	 printf(1, "\nThis is child with PID# %d and I will exit with status %d\n" ,getpid(), -1);
      exitS(-1);
  } 
    } else if (pid &gt; 0) { // only the parent executes this code
      ret_pid = wait(&amp;exit_status);
      printf(1, "\n This is the parent: child with PID# %d has exited with status %d\n", ret_pid, exit_status);
    } else  // something went wrong with fork system call
    {  
	  printf(2, "\nError using fork\n");
      exitS(-1);
    }
  }
  return 0;
}

int waitPid(void){
	
  int ret_pid, exit_status;
  int i;
  int pid_a[5]={0, 0, 0, 0, 0};
 // use this part to test wait(int pid, int* status, int options)

 printf(1, "\n  Part c) testing waitpid(int pid, int* status, int options):\n");

	for (i = 0; i &lt;5; i++) {
		pid_a[i] = fork();
		if (pid_a[i] == 0) { // only the child executed this code
			printf(1, "\n The is child with PID# %d and I will exit with status %d\n", getpid(), getpid() + 4);
			exitS(getpid() + 4);
		}
	}
       
      sleep(5);
      printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid_a[3]);
      ret_pid = waitpid(pid_a[3], &amp;exit_status, 0);
      printf(1, "\n This is the partent: Child# %d has exited with status %d\n",ret_pid, exit_status);
      sleep(5);
      printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid_a[1]);
      ret_pid = waitpid(pid_a[1], &amp;exit_status, 0);
      printf(1, "\n This is the partent: Child# %d has exited with status %d\n",ret_pid, exit_status);
      sleep(5);
      printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid_a[2]);
      ret_pid = waitpid(pid_a[2], &amp;exit_status, 0);
      printf(1, "\n This is the partent: Child# %d has exited with status %d\n",ret_pid, exit_status);
      sleep(5);
      printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid_a[0]);
      ret_pid = waitpid(pid_a[0], &amp;exit_status, 0);
      printf(1, "\n This is the partent: Child# %d has exited with status %d\n",ret_pid, exit_status);
      sleep(5);
      printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid_a[4]);
      ret_pid = waitpid(pid_a[4], &amp;exit_status, 0);
      printf(1, "\n This is the partent: Child# %d has exited with status %d\n",ret_pid, exit_status);
      
      return 0;
  }

int CELEBW02(void){
	
 printf(1, "\n  Part e) the waitpid option WNOHANG, test program CELEBW02 \n");

  int pid, retpid;
  int status;

  if ((pid = fork()) &lt; 0)
    printf(2, "fork() error");
  else if (pid == 0) {
    sleep(5);
    exitS(1);
  }
  else do {
    if ((retpid = waitpid(pid, &amp;status, WNOHANG)) == -1)
      printf(2, "wait() error");
    else if (retpid == 0) {
      printf(1, "child is still running \n");
      sleep(1);
    }
    else {
        printf(1, "child exited with status of %d\n", status);
    }
  } while (retpid == 0);
  
  return 0;
  
  }
</pre></body></html>Xtext/x-c    ( F U l ~ � �	
�                           �