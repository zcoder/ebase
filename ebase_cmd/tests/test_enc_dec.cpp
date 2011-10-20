/* 
 * File:   test_enc_dec.cpp
 * Author: zhenka
 *
 * Created on 19.10.2011, 7:30:52
 */

#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <iostream>
#include "../common/run/run.h"
/*
 * Simple C++ Test Suite
 */

/*
int main(int argc, char *argv[])
       {
           int pipefd[2];
           pid_t cpid;
           char buf;

           if (argc != 2) {
            fprintf(stderr, "Usage: %s <string>\n", argv[0]);
            exit(EXIT_FAILURE);
           }

           if (pipe(pipefd) == -1) {
               perror("pipe");
               exit(EXIT_FAILURE);
           }

           cpid = fork();
           if (cpid == -1) {
               perror("fork");
               exit(EXIT_FAILURE);
           }

           if (cpid == 0) {    // Child reads from pipe 
               close(pipefd[1]);          // Close unused write end

               while (read(pipefd[0], &buf, 1) > 0)
                   write(STDOUT_FILENO, &buf, 1);

               write(STDOUT_FILENO, "\n", 1);
               close(pipefd[0]);
               _exit(EXIT_SUCCESS);

           } else {            // Parent writes argv[1] to pipe 
               close(pipefd[0]);          // Close unused read end 
               write(pipefd[1], argv[1], strlen(argv[1]));
               close(pipefd[1]);          // Reader will see EOF 
               wait(NULL);                // Wait for child 
               exit(EXIT_SUCCESS);
           }
       }
 */

void test1(char* const argv[]) {
    std::cout << "test_enc_dec test 1" << std::endl;
   
    
    
    
    
    
    
    
    FILE* fpipe;
    if ( !(fpipe = (FILE*)popen("/usr/bin/ebase_cmd_dbg","r")) )
    {
        perror("Pipe fail");
        std::cout << "%TEST_FAILED% time=0 testname=test1 (test_enc_dec) message=Pipe fail, ret=" << ret << ", errno="<< errno << std::endl;
        return;
    }

    pclose(fpipe);
    //int ret = run_fork_execv_waitpid("/usr/bin/ebase_cmd_dbg", argv, STDOUT_FILENO, STDIN_FILENO);
            //execl("/bin/ls", "/bin/ls", "-l", "-a", (char *) 0);
    //char *newargv[] = { "-d", "-i/tmp/file1", "-o/tmp/file2", NULL };
    //int ret=execvpe("/bin/echo", newargv, NULL);
           
    if (ret>0) 
    {
        std::cout << "test_enc_dec test 1 [PASS] ret=" <<  ret << std::endl;
    }
    else
    {
        std::cout << "%TEST_FAILED% time=0 testname=test1 (test_enc_dec) message=ret=" << ret << " errno="<< errno << std::endl;
    }
}

void test2() {
    std::cout << "test_enc_dec test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (test_enc_dec) message=error message sample" << std::endl;
}

int main(int argc, char*  const argv[]) {

    std::cout << "%SUITE_STARTING% test_enc_dec" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (test_enc_dec)" << std::endl;
    test1(argv);
    std::cout << "%TEST_FINISHED% time=0 test1 (test_enc_dec)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (test_enc_dec)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (test_enc_dec)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

