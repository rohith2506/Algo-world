#include <iostream>
#include <fstream>
#include <pthread.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/user.h>
int ORIG_EAX = 11;
using namespace std;

int main(int argc,char* arv[]){
    pid_t child;
    long orig_eax;
    child = fork();

    if (child == 0){
        ptrace(PTRACE_TRACEME,0,NULL,NULL);
        ifstream fin;
        fin.open("/home/infinity/Algo/spoj/abcdef.cpp",ios::in);
        string str2;
        while(getline(fin,str2))
            cout<<str2<<endl;
    }
    else{
        wait(NULL);
        orig_eax = ptrace(PTRACE_PEEKUSER,child,4*ORIG_EAX,NULL);
        printf("The Child made a system call %ld\n",orig_eax);
        ptrace(PTRACE_CONT,child,NULL,NULL);
    }
    return 0;
}
