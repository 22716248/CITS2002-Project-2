#include "headers.h"
#include "managefiles.h"

struct stat getStat(const char *file_path){
    struct stat s;
    stat(file_path, &s);
    return s;
}

int unTar(char tarfile[], char *checkDir)
{
    pid_t pid;
    int waiting;
    char *tarcommand[] = {"/bin/tar", "-xfp", tarfile, "-C", checkDir, NULL};
    char *tgzcommand[] = {"/bin/tar", "-xzfp", tarfile, "-C", checkDir, NULL};
    
    char tar[] = ".tar"; char tgz[] = ".tgz"; char gz[] = ".gz";
    char *fileType, *tarOp, *tgzOp, *gzOp;
    fileType = tarfile; tarOp = tar; tgzOp = tgz; gzOp = gz;

    char *fileTar = strstr(fileType, tarOp);
    char *fileTgz = strstr(fileType, tgzOp);
    char *fileGz = strstr(fileType, gzOp);

    switch (pid = fork())
    {
        case -1:
            perror("forking error");
            exit(1);
        case 0:
            printf("THIS IS THE CHILD\n");

            if(fileTar){
                execvp(tarcommand[0], tarcommand);
                exit(waiting);
                break;
            }
            else if(fileTgz){
                execvp(tgzcommand[0], tgzcommand);
                exit(waiting);
                break;
            }
            else if(fileGz){
                execvp(tgzcommand[0], tgzcommand);
                exit(waiting);
                break;   
            }
            else{
                perror("not a valid file type");
                exit(1);
                break;
            }
        default:
            printf("THIS IS THE PARENT\n");
            wait(&waiting);
            break;

    }
}

int Tar(char tarfile[], char *checkDir)
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

char * makeTempFile(void){
    char template[] = "/tmp/tmpdir.XXXXXX";
    char *mkdtemp(char *template);
    char *dir_name = mkdtemp(template);

    if(dir_name == NULL)
    {
            perror("mkdtemp failed: ");
    }

    return dir_name;
}


void removeFile(char *location){
    if(rmdir(location) == -1)
    {
        perror("rmdir failed: ");
    }
}

int copyFile(char source[], char destination[]){
    int f;
    FILE *stream_source;
    FILE *stream_distination;
    
    stream_source = fopen(source, "r");
    if (stream_source == NULL){
        printf("sourcefailed\n");
        return -1;
    }

    stream_distination = fopen(destination, "w");
    if (stream_distination == NULL){
        printf("destfailed\n");
        fclose(stream_source);
        return -2;
    }

    while ((f = fgetc(stream_source)) != EOF){
        fputc (f, stream_distination);
    }

    fclose (stream_source); fclose (stream_distination);

    struct stat s = getStat(source);
    int cherror = chmod(destination, s.st_mode);
    if (cherror != 0){
        perror("chmod()");
        return -1;
    }

    struct utimbuf new_s_time;
    new_s_time.modtime = s.st_mtime;
    new_s_time.actime = s.st_atime;
    int cherror2 = utime(destination, &new_s_time);
    if (cherror2 != 0){
        perror("utime()");
        return -1;
    }

    return 0;
}

/**
int main(int argc, char *argv[]){
    char *f1 = argv[1];
    char *f2 = argv[2];
    printf("running...");
    if (copyFilef(f1,f2,f1,f2) == -1){
        printf("failed...\n");
        return -1;
    }
    printf(" ! didntcrashthatsgood ! \n");
    return 0;
}
**/
