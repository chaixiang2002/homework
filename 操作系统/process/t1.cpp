#include <iostream>
using namespace std;

#include <stdio.h>
#include <unistd.h>
int main() {
  pid_t fpid;
  int count = 0;
  fpid = fork(); //返回子进程的进程ID
  if (fpid < 0)  //如果返回负数，则出错了
    cout << "failed to fork";
  else if (fpid == 0) //如果fork返回0，则下面进入子程序
  {
    cout << "I am the child process, my pid is  " << getpid() << endl;
    count++;
  } else //如果fork返回值大于0，则依旧在父进程中执行
  {
    cout << "I am the parent process, my pid is " << getpid() << endl;
    cout << "fpid =" << fpid << endl;
    count++;
  }
  printf("count=%d\n", count);
  return 0;
}