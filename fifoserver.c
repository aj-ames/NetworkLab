#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define fifo1 "fifox"
#define fifo2 "fifoy"

int main() {
  char filename[100], c[2000];
  int num, fd, fd1, fd2;

  mknod(fifo1, S_IFIFO|0777, 0);
  mknod(fifo2, S_IFIFO|0777, 0);

  printf("Server Online\n");
  fd1 = open(fifo1, O_RDONLY);

  while((num = read(fd1, filename, 100)) < 0);

  filename[num] = '\0';
  printf("Filename: %s", filename);
  fd = open(filename, O_RDONLY, 0);
  read(fd, c, 1999);

  fd2 = open(fifo2, O_WRONLY);
  write(fd2, c, 1999);
  printf("Dont writing!\n");
  return 0;
}
