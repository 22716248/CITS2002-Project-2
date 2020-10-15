#include "headers.h"
#include "compare.c"

void processFiles(char *basedir, char *finalpath)
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
            strcat(entpath, basedir);
            strcat(entpath, "/");
            strcat(entpath, ent->d_name);

            
            char currentpath[MAXPATHLEN] = "";
            strcat(currentpath, "/");
            strcat(currentpath, ent->d_name);
            

            int dir_check = getDir(entpath);

            if (dir_check) //folder
            {   
                processFiles(entpath, finalpath);
            }
            else //file itself
            {
                printf("\n\tFILE: %s\n\tBASEDIR: %s\n\tENTPATH: %s\n \tFINALPATH: %s\n \tENTCOMP: %s\n", ent->d_name, basedir, entpath, finalpath, currentpath);
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

int main (){
    processFiles("./test", "/tmp/FILE.Ad2AD1/");
}