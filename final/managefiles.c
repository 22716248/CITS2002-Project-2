#include <headers.h>

#define tarfile "file.tar"
#define checkDir "/temp/test"

//also need to check  if compressed or not in Tar and untar

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

int unTgz()
{
    pid_t pid;
    int waiting;
    char *tarcommand[] = {"/bin/tar", "-xzfp", tarfile, "-C", checkDir, NULL};

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
    char *tarcommand[] = {"/bin/tar", "-cfp", tarfile, "-C", checkDir, NULL};

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

void copyFile(){
    ;
}

char * makeTemporary(void){
    char template[] = "/tmp/tmpdir.XXXXXX";
    char *dir_name = mkdtemp(template);

    if(dir_name == NULL)
    {
            perror("mkdtemp failed: ");
    }

    return dir_name;
}


void removeTemporary(char *location){
    if(rmdir(location) == -1)
    {
        perror("rmdir failed: ");
    }
}

char * makeFinal(void){
    char template[] = "/tmp/tmpdir.XXXXXX";
    char *dir_name = mkdtemp(template);

    if(dir_name == NULL)
    {
            perror("mkdtemp failed: ");
    }

    return dir_name;
}


void removeFinal(char *location){
    if(rmdir(location) == -1)
    {
        perror("rmdir failed: ");
    }
}


