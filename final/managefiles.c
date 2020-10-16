#include "headers.h"
#include "managefiles.h"

/**
 * This provides the stat structure for a given file.
 * Returning: struct stat s
 * Arguments: a filepath string
 **/
struct stat getStat(const char *file_path){
    struct stat s;
    stat(file_path, &s);
    return s;
}

/**
 * Extracts a given tar archive into a location.
 * Returning: 0 upon success, exits otherwise
 * Arguments: tarfile, and a filepath.
 **/
int unTar(char tarfile[], char *endDir)
{
    pid_t pid;
    int waiting;

    char *tarcommand[] = {"tar", "xfp", tarfile, "-C", endDir, NULL};
    char *tgzcommand[] = {"tar", "xzfp", tarfile, "-C", endDir, NULL};

    char tar[] = ".tar"; char tgz[] = ".tgz"; char gz[] = ".gz";
    char *fileType, *tarOp, *tgzOp, *gzOp;
    fileType = tarfile; tarOp = tar; tgzOp = tgz; gzOp = gz;

    char *fileTar = strstr(fileType, tarOp);
    char *fileTgz = strstr(fileType, tgzOp);
    char *fileGz = strstr(fileType, gzOp);

    switch (pid = fork())
    {
        case -1:
            perror("fork() [managefiles.c] failed: ");
            exit(EXIT_FAILURE);
        case 0:
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
                perror("unTar() [managefiles.c] failed: Not a valid file type.\n");
                exit(EXIT_FAILURE);
                break;
            }
        default:
            wait(&waiting);
            break;

    }
    return 0;
}

/**
 * Creates a given tar archive into from a location.
 * Returning: 0 upon success, exit's otherwise
 * Arguments: tarfile, and a filepath.
 **/
int Tar(char tarname[], char *tarfile)
{   
    char finalLocation[200] = "./";
    strcat(finalLocation, tarname);

    pid_t pid;
    int waiting;
    char *tarcommand[] = {"tar" , "cfp" ,finalLocation, "-C", tarfile, ".", NULL};

    switch (pid = fork())
    {
        case -1:
            perror("fork() [managefiles.c] failed: ");
            exit(EXIT_FAILURE);
        case 0:
            execvp(tarcommand[0], tarcommand);
            exit(waiting);
            break;
        default:
            wait(&waiting);
            break;

    }
    return 0;
}

/**
 * Creates a temporary directory
 * Returning: the tempfile path
 * Arguments: none
 **/
char * makeTempFile(void){
    char template[] = "/tmp/tmpdir.XXXXXX";
    char *mkdtemp(char *template);
    char *dir_name = mkdtemp(template);

    if(dir_name == NULL)
    {
            perror("mkdtemp() [mergefiles.c] failed: ");
            exit(EXIT_FAILURE);
    }

    return dir_name;
}

/**
 * Removes a directory, and it's contents using the rm -r command
 * Returning: nothing
 * Arguments: directory location
 **/
void removeFile(char *location){
    pid_t pid;
    int waiting;
    char *rmcommand[] = {"rm", "-r", location, NULL};

    switch (pid = fork())
    {
        case -1:
            perror("fork() [managefiles.c] failed: ");
            exit(EXIT_FAILURE);
        case 0:
            execvp(rmcommand[0], rmcommand);
            exit(waiting);
            break;
        default:
            wait(&waiting);
            break;

    }
}

/**
 * Copies a file, it's contents and, its last modified time and permissions.
 * Returning: 0 upon success, -1 for a failure
 * Arguments: source file path, destination file path
 **/
int copyFile(char source[], char destination[]){
    int f;
    FILE *stream_source;
    FILE *stream_distination;
    
    stream_source = fopen(source, "r");
    if (stream_source == NULL){
        printf("fopen() [managefiles.c] failed: Couldn't open source file.\n");
        return -1;
    }

    stream_distination = fopen(destination, "w");
    if (stream_distination == NULL){
        printf("fopen() [managefiles.c] failed: Couldn't open destination file.\n");
        fclose(stream_source);
        return -1;
    }

    while ((f = fgetc(stream_source)) != EOF){
        fputc (f, stream_distination);
    }

    fclose (stream_source); fclose (stream_distination);

    struct stat s = getStat(source);
    int cherror = chmod(destination, s.st_mode);
    if (cherror != 0){
        perror("chmod() [managefiles.c] failed: ");
        return -1;
    }

    struct utimbuf new_s_time;
    new_s_time.modtime = s.st_mtime;
    new_s_time.actime = s.st_atime;
    int cherror2 = utime(destination, &new_s_time);
    if (cherror2 != 0){
        perror("utime() [managefiles.c] failed: ");
        return -1;
    }

    return 0;
}