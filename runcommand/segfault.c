/* sefault.c - This program causes a segfault. */
#include <stdlib.h>
int main (int argc, char **argv)
{
  int *p;  
  p = 0;
  *p = 1;
  
  return EXIT_SUCCESS;
}
