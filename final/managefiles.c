
//  CITS2002 Project 2 2020
//  Name(s):             Jakub Wysocki, Brandon Petkovic
//  Student number(s):   22716248, 22502051
#include <headers.h>

#define tarfile "file.tar"
#define checkDir "/temp/test"


int unTar()
{
    pid_t pid;
    int waiting;
    char *tarcommand[] = {"/bin/tar", "-xfp", tarfile, "-C", checkDir, NULL};

    switch (pid = fork())
    {
        case -1:
            perror("forking error");
            exit(1);
        case 0:
            printf("THIS IS THE CHILD\n");
            execvp(tarcommand[0], tarcommand);
            exit(waiting);
            break;
        default:
            printf("THIS IS THE PARENT\n");
            wait(&waiting);
            break;

    }
    return 0;
}

int Tar()
{
    pid_t pid;
    int waiting;
    char *tarcommand[] = {"/bin/tar", "-xfp", tarfile, "-C", checkDir, NULL};

    switch (pid = fork())
    {
        case -1:
            perror("forking error");
            exit(1);
        case 0:
            printf("THIS IS THE CHILD\n");
            execvp(tarcommand[0], tarcommand);
            exit(waiting);
            break;
        default:
            printf("THIS IS THE PARENT\n");
            wait(&waiting);
            break;

    }
    return 0;
}

void removeFile(char *finalpath){

}

void copyFile(){

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

