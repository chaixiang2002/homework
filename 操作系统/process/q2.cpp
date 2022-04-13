#include <bits/types/time_t.h>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;
int var = 0;
int *p = &var;

void *set_var(void *tt) {
  int b = *((int *)tt);
  while (true) {
    if (b)
      cout << *p << "==>" << ++*p << endl;
    else
      cout << *p << "==>" << --*p << endl;
    sleep(2);
  }
  return 0;
}

int main() {
  pthread_t tids[2];
  int b[2];
  for (int i = 0; i < 2; ++i) {
    b[i] = i;
    //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
    int ret = pthread_create(&tids[i], NULL, set_var, (void *)&(b[i]));
    if (ret != 0) {
      cout << "pthread_create error: error_code=" << ret << endl;
    }
    sleep(1);
  }
  pthread_exit(NULL);
}