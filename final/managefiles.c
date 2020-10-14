#include "headers.h"

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

//mainly from lecture 9
int copyFile(char *source, char *destination){

    int source_desc = open(source, O_RDONLY);
    if (source_desc == -1){
        printf("sourcefailed\n");
        return -1;
    }

    int destination_desc = open(destination, O_WRONLY);
    if (destination_desc == -1){
        printf("destfailed\n");
        close(source_desc);
        return -1;
    }

    char BUFFER[BUFFER_SIZE];
    int read_value;

    while ((read_value = read(source_desc, BUFFER, sizeof BUFFER)) > 0)
    {
        if(write(destination_desc, BUFFER, read_value) != read_value){
            printf("copyFile failed \n");
            close(source_desc); close(destination_desc);
            return -1;
        }
    }
    close(source_desc); close(destination_desc);
    return 0;
}


//this tests copyfile
/**
int main(int argc, char *argv[]){
    char *f1 = argv[1];
    char *f2 = argv[2];
    printf("running...");
    if (copyFile(f1,f2) == -1){
        printf("failed...\n");
        return -1;
    }
    printf(" ! didntcrashthatsgood ! \n");
    return 0;
}
**/