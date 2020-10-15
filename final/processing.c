#include "headers.h"

void processFiles(char *basedir)
{
    DIR *dir;
    struct dirent *ent;

    dir = opendir(basedir);

    if (dir != NULL)
    {

        while ((ent = readdir(dir)) != NULL)
        {
            //ignore . or ..
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, ".." ) == 0){
                continue;
            }

            char entpath[MAXPATHLEN] = "";
            char endpath[] = entpath;
            strcat(entpath, basedir);
            strcat(entpath, "/");
            strcat(entpath, ent->d_name);

            int dir_check = getDir(entpath);

            if (dir_check) //folder
            {   
                walkDir(entpath);
            }
            else //file itself
            {

                
                printf("\n\tFILE: %s\n\tBASEDIR: %s\n\tENDPATH: %s\n", ent->d_name, basedir, endpath);
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

