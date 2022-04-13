#include <bits/types/time_t.h>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void *b(void *args) {
  while (true) {
    time_t now_time = time(0);
    char *dt = ctime(&now_time);
    cout << "Those output come from chlid, " << dt << endl;
    sleep(1);
  }
  return 0;
}

int main() {
  pthread_t tid;
  int ret = pthread_create(&tid, NULL, b, NULL);
  if (ret != 0) {
    cout << "pthread_create failed\n";
  }
  pthread_exit(NULL);
}