/* debug.h - Debug utilities (non-public).

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

#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DEFAULT_ERR "Something wrong"

/* 
   System errors.
 */

/* Report system error and exit. */

#define sysfatal(expression) \
  do { if ((expression)) {fprintf (stderr, "%s: %s: %d: %s: %s\n",	\
    "Fatal ", __FILE__, __LINE__,\
		__PRETTY_FUNCTION__, strerror (errno)); \
  exit (EXIT_FAILURE);}} while (0)


/* Report a system error and returns withe the specified code. */

#define sysfault(expression, return_status)						\
  do { if (expression) {fprintf (stderr, "%s: %s: %d: %s: %s\n",	\
    "Fault ", __FILE__, __LINE__,\
		__PRETTY_FUNCTION__, strerror (errno)); \
      return (return_status);}} while (0)

/* Report a system error. */

#define sysdebug(expression)						\
  do { if (expression) {fprintf (stderr, "%s: %s: %d: %s: %s\n",	\
    "Debug ", __FILE__, __LINE__,\
		__PRETTY_FUNCTION__, strerror (errno)); \
      }} while (0)

/* 
   Custom errors.
 */

/* Rerport a custom error and exit.*/

#define fatal(expression, message)						\
  do { if ((expression)) {fprintf (stderr, "%s: %s: %d: %s: %s\n",	\
    "Fatal ", __FILE__, __LINE__,\
	   __PRETTY_FUNCTION__, message ? message : DEFAULT_ERR ); \
  exit (EXIT_FAILURE);}} while (0)

/* Report a custom error and returns withe the specified code. */

#define fault(expression, return_status, message)				\
  do { if (expression) {fprintf (stderr, "%s: %s: %d: %s: %s\n",	\
    "Fault ", __FILE__, __LINE__,\
	   __PRETTY_FUNCTION__, message ? message : DEFAULT_ERR ); \
      return (return_status);}} while (0)

/* Report a custom error. */

#define debug(expression, message)				\
  do { if (expression) {fprintf (stderr, "%s: %s: %d: %s: %s\n",	\
    "Debug ", __FILE__, __LINE__,\
	   __PRETTY_FUNCTION__, message ? message : DEFAULT_ERR ); \
      }} while (0)




#endif/* DEBUG_H */

