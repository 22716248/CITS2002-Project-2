
//  CITS2002 Project 2 2020
//  Name(s):             Jakub Wysocki (, student-name2)
//  Student number(s):   22716248 (, student-number2)

#include <dirent.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>


int isDir(const char *file_path)
{
    struct stat s;
    stat(file_path, &s);
    int test = S_ISDIR(s.st_mode);
    return test;
}

void walkDir(char *basedir)
{

    DIR *dir;
    //char b[512];
    struct dirent *ent;

    dir = opendir(basedir);

    if (dir != NULL)
    {
        printf("\n\tWalking \"%s\n", basedir);

        while ((ent = readdir(dir)) != NULL)
        {
            //ignore . or ..
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, ".." ) == 0){
                continue;
            }
            
            char entpath[] = "";
            strcat(entpath, basedir);
            strcat(entpath, "/");
            strcat(entpath, ent->d_name);

            int dir_check = isDir(entpath);

            if (dir_check) //folder
            {
                printf("\n\tDIR: %s\n", ent->d_name);

                walkDir(entpath);
            }
            else //file itself
            {
                printf("\n\tFILE: %s\n", ent->d_name);
            }


        }
        
        closedir(dir);

    }
    else
    {
        fprintf(stderr, "\nFailed to access dir \"%s\"\n", basedir);
        perror("opendir()");
    }
}


int main(int argc, char *argv[])
{
    printf("\n====START====");

    char basedir[] = "/mnt/c/Users/Kuba/Documents/github/CITS2002-Project-2/test";
    walkDir(basedir);

    printf("\n====DONE====\n");
}