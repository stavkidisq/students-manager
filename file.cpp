#include "file.h"

void readfile(const char* filename, struct student* buff, int index)
{
    FILE* fstream = open_file(filename, "r");
    fread(buff, sizeof(struct student), index, fstream);

    fclose(fstream);
}

void write2file(const char* filename, struct student* buff, int index)
{
    FILE* fstream = open_file(filename, "w");
    fwrite(buff, sizeof(struct student), index, fstream);

    fclose(fstream);
}

FILE* open_file(const char* filename, const char* mode)
{
    FILE* fstream = NULL;

    if((fstream = fopen(filename, mode)) == NULL)
    {
        printf("No such file");
        exit(EXIT_FAILURE);
    }

    return fstream;
}
