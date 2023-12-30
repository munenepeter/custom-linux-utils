#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv) {

    //Open dir
    const char* dir_path = ".";
    DIR* dir_path_p = opendir(dir_path);

    if (dir_path_p == NULL) {
        fprintf(stderr, "E: Could not open %s:%s", dir_path, strerror(errno));
        exit(-1);
    }
    errno = 0;

    //read dir
    struct dirent* dir_entry = readdir(dir_path_p);

    if (errno != 0) {
        fprintf(stderr, "E: Could not read %s:%s", dir_path, strerror(errno));
        exit(-1);
    }
    //list items

    while (dir_entry != NULL) {
        printf("file: %s\n", dir_entry->d_name);
        dir_entry = readdir(dir_path_p);
    }

    return 0;
}