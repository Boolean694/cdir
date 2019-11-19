#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *dirn = malloc(100);
  if(argc <= 1) {
    printf("Enter directory to search for: ");
    fgets(dirn, 100, stdin);
    dirn[strlen(dirn) - 1] = 0;
  }
  else {
    dirn = argv[1];
  }
  DIR *ret1 = opendir(dirn);
  if(ret1 == NULL) {
    printf("Invalid entry");
  }
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
