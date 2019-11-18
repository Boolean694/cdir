#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int main() {
  DIR *ret1 =  opendir(".");
  struct dirent *dst;
  dst = readdir(ret1);
  int sz = 0;
  char *fn;
  printf("Directory being read: %s\n", dst->d_name);
  struct stat ind = malloc(sizeof(ind));
  while(dst != NULL) {
    fn = dst->d_name;
    printf("File: %s\n", fn);
    stat(fn, &ind);
    sz += ind->st_size;
    dst = readdir(".");
  }
  printf("Size of dir: %d\n", sz);
  return 0;
}
