
//make a temporary directory
//https://stackoverflow.com/questions/18792489/how-to-create-a-temporary-directory-in-c

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int make_temp_dir()
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