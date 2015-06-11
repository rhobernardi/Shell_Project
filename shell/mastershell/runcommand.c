/* runcommand.c - Execute a user-specified command as a subprocess. 

   Copyright (c) 2014, Francisco José Monaco <moanco@icmc.usp.br>

   This file is part of POSIXeg

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

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "mastershell.h"
#include "debug.h"

/* Execute a command in a subprocess as specified by argument 'command'. 
   See documentation of command_t for further information. */

int runcommand (command_t *command) 
{
  int pid, status;
  int aux;

  if(strcmp(command->args[0] , "cd") == 0){
    aux = chdir(command->args[1]);
    if(aux == -1){
      printf("%s\n", strerror(errno));
    }
    return aux;
  }else if(strcmp(command->args[0], "exit") == 0){
    exit(0);
  } 
  
  /* Create the subproccess. */

  pid = fork();
  fail (pid<0, -1);

  if (pid>0)			/* Parent (caller). */
    {
      aux = wait (&status);
      fail (aux<0, -1);
      command->exit_status = WEXITSTATUS (status);
    }
  else				/* Child (subprocess). */
    {
      aux = execvp (command->args[0], command->args);
      if (aux<0)
	exit (-1);
    }
  return pid;			/* Only parent reaches this point. */
}