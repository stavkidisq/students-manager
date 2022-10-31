#ifndef FILE_H
#define FILE_H

#include <stdio.h>

#include "student.h"

void readfile(const char*, struct student*, int);
void write2file(const char*, struct student*, int);

FILE* open_file(const char* filename, const char* mode);

#endif // FILE_H
