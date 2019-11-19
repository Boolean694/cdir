#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
  DIR *ret1 =  opendir(argv[0]);
  struct dirent *dst;
  dst = readdir(ret1);
  int sz = 0;
  char *fn;
  printf("Directory being read: %s\n", dst->d_name);
  struct stat ind;
  while(dst != NULL) {
    fn = dst->d_name;
    printf("File: %s\n", fn);
    if((int)dst->d_type == 4) {
      printf("File type: Directory\n");
    }
    else {
      printf("File type: Regular File\n");
    }
    stat(fn, &ind);
    printf("File size: %d bytes\n\n", ind.st_size);
    sz += ind.st_size;
    dst = readdir(ret1);
  }
  printf("--------\nSize of dir: %d bytes\n", sz);
  return 0;
}
