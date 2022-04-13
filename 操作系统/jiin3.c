#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
pthread_t ntid;
int shared_var = 0;
void mainloop() {
  while (1) {
    printf("%d\n", shared_var++);
  }
}
void *tloop(void *arg) {
  // tloop??*,?????????
  while (1)
    printf("%d\n", shared_var--);
}
int main(void) {
  if (pthread_create(&ntid, NULL, tloop, NULL) != 0)
    printf("can't creat thread:%s\n");
  //??pthread_creat??????
  //????????,????,
  // pthread_create?????,?????????
  mainloop();
  return 0;
}