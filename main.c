#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int main() {
  DIR *ret1 =  opendir(".");
  struct dirent *dst;
  dst = readdir(ret1);
  printf("File being read: %s\n", dst->d_name);
  printf("File type: %c\n", dst->d_type);
  return 0;
}
