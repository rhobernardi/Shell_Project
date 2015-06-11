/* fillpipe.c - Auxiliary program


   Copyright (c) 2015, Monaco F. J. <moanco@icmc.usp.br>

   This file is part of POSIXeg.

   POSIXeg is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <debug.h>


int main (int argc, char **argv)
{
  long int i, pipe_size;
  int flags, pipefd[2];
  

  /* Check the pipe buffer size. */

  sysfatal (pipe(pipefd)<0);

  flags = fcntl(pipefd[1], F_GETFL, 0);
  fcntl(pipefd[1], F_SETFL, flags | O_NONBLOCK);

  pipe_size=0;
  while (write(pipefd[1],"a",1)==1)
    pipe_size++;

  flags = fcntl(pipefd[1], F_GETFL, 0);
  fcntl(pipefd[1], F_SETFL, flags | O_NONBLOCK);

  close (pipefd[0]);
  close (pipefd[1]);

  fprintf (stderr, "%ld\n", 2*pipe_size);

  /* Fill in the pipe. */

  for (i=0; i<2*pipe_size; i++)
    write (1, "a", 1);
  

  return EXIT_SUCCESS;
}
