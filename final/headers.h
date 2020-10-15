#include <dirent.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h> //cp
#include <sys/sysmacros.h>
#include <sys/param.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>
#include <sys/time.h>

#include "globals.c"