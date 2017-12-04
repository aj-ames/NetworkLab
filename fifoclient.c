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

  printf("Client Online\n");
  printf("Enter the name of the file: ");
  scanf("%s", filename);
  fd1 = open(fifo1, O_WRONLY);
  write(fd1, filename, 100);

  fd2 = open(fifo2, O_RDONLY);
  while(num = read(fd2, c, 1999) < 0);

  printf("Data received is: %s \n", c);
  printf("Done!\n");
  return 0;
}
