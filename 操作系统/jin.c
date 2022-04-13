#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int a = 10;
void *fun1(void *arg) {
  pthread_detach(pthread_self());
  a = 100;
  printf("??? ???:%d, ???:%lu\n", getpid(), pthread_self());
}
int main() {
  pthread_t tid;
  printf("??? ???:%d, ???:%lu\n", getpid(), pthread_self());
  //????
  printf("a=%d\n", a);
  int ret = pthread_create(&tid, NULL, fun1, NULL);
  if (ret == 0) {
    printf("??????????! \n");
  }
  sleep(2);
  printf("a=%d\n", a);
  return 0;
}