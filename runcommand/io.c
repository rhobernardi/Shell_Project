#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <foo.h>
#include <debug.h>

#define infile "in.txt"
#define outfile "out.txt"
#define errfile "err.txt"

int main (int argc, char **argv)
{
  int aux, fd;
  int errors = 0;
  char c;

  close(0);
  fatal ((fd = open (infile, O_WRONLY,  S_IRUSR | S_IWUSR)) <0);
  dup(fd);

  printf("TESTE 1\n");
  /* Try to read from standard input (infile) */
  aux = read (0,&c,1);
  errors += (aux<0) ? 1 : 0;
  errors += (c!='a') ? 1 : 0;
  
  close(0);
  fatal ((open ("/dev/null", O_WRONLY)) <0);


  close(1);
  fatal ((fd = open (outfile, O_CREAT | O_TRUNC | O_RDWR,  S_IRUSR | S_IWUSR)) <0);
  dup(fd);

  /* Try to write to standard output (outfile) and read it again.*/
  aux = write (1,"b",1);
  errors += (aux<0) ? 1 : 0;
  close(1);
  fatal ((open ("/dev/null", O_WRONLY)) <0);

  fatal ((fd = open (outfile, O_RDONLY)) <0);
  aux = read (fd,&c,1);
  errors += (aux<0) ? 1 : 0;
  errors += (c!='b') ? 1 : 0;
  fatal (close(fd)<0);

  close(2);
  fatal ((fd = open (errfile, O_CREAT | O_TRUNC | O_RDWR,  S_IRUSR | S_IWUSR)) <0);
  dup(fd);

  /* Try to write to standard error (errnfile) and read it again.*/
  aux = write (2,"c",1);
  errors += (aux<0) ? 1 : 0;
  close(2);
  fatal ((open ("/dev/null", O_WRONLY)) <0);

  fatal ((fd = open (errfile, O_RDONLY)) <0);
  aux = read (fd,&c,1);
  errors += (aux<0) ? 1 : 0;
  errors += (c!='c') ? 1 : 0;
  fatal (close(fd)<0);


  return errors;
}
