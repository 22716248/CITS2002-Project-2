

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

int main(void)
{
    char temporary[19];
    memcpy(temporary, makeTemporary(), 19);
    removeTemporary(temporary);

    char final[19];
    memcpy(final, makeFinal(), 19);
    removeFinal(final);

    return 0;
}