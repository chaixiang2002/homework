#include <pthread.h>
#include <stdio.h>
void *workThreadEntry(void *args) {
  char *str = (char *)args;
  printf("threadId:%lu,argv:%s\n", pthread_self(), str);
}
int main(int argc, char *agrv[]) {
  pthread_t thread_id;
  char *str = "hello world";
  pthread_create(&thread_id, NULL, workThreadEntry, str);
  printf("threadId=%lu\n", pthread_self());
  pthread_join(thread_id, NULL);
}