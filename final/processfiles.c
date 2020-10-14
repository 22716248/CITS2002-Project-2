
//make a temporary directory
//https://stackoverflow.com/questions/18792489/how-to-create-a-temporary-directory-in-c

#include <headers.h>

int isDir(const char *file_path)
{
    struct stat s;
    stat(file_path, &s);
    int test = S_ISDIR(s.st_mode);
    return test;
}

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

            //c/user/documents/check
            char entpath[MAXPATHLEN] = "";
            char endpath[] = entpath;
            strcat(entpath, basedir);
            strcat(entpath, "/");
            strcat(entpath, ent->d_name);

            int dir_check = isDir(entpath);

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

int makeTempFile()
{
        char template[] = "/tmp/tmpdir.XXXXXX";
        char *dir_name = mkdtemp(template);

        if(dir_name == NULL)
        {
                perror("mkdtemp failed: ");
                return 0;
        }

        /* Use it here */
        printf("%s", dir_name);



        /* Don't forget to delete the folder afterwards. */
        if(rmdir(dir_name) == -1)
        {
                perror("rmdir failed: ");
                return 0;
        }


        return 0;

}