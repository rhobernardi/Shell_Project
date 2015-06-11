/* foo.h - Header of our example-library.

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

#ifndef FOO_H
#define FOO_H

#define ABNORMAL_TERMINATION 0
#define NORMAL_TERMINATION 1

/* This struct is passed to function runcommand. */

typedef struct 
{
  char **args;			/* A command vector as it is passed to exec. */
  int exit_status;		/* Exit status code returned by the program. */
  int termination;
  int *io;
} command_t;


/* Run a command in a subprocess. */

int runcommand (command_t *command);



#endif	/* FOO_H */
