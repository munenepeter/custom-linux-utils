#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


#define DISPLAY_NORMAL 0
#define DISPLAY_ALL 1



void print_help() {
    printf(
        "usage: custom-ls ls [OPTION]\n"
        "List information about the FILEs in the current directory."
        "Options are:\n"
        "    --help: display what you are reading now\n"
    );
}

void print_files_in_dir(const char* directory_path, int mode) {
    DIR* dir_path_p = opendir(directory_path);

    if (dir_path_p == NULL) {
        fprintf(stderr, "E: Could not open %s:%s", directory_path, strerror(errno));
        exit(-1);
    }
    //reset the errno
    errno = 0;

    //read dir
    struct dirent* dir_entry = readdir(dir_path_p);

    if (errno != 0) {
        fprintf(stderr, "E: Could not read %s:%s", directory_path, strerror(errno));
        exit(-1);
    }
    //list items
    while (dir_entry != NULL) {
        switch (mode) {
        case 1:
            printf("%s", dir_entry->d_name);
            break;

        default:
            printf("%s", dir_entry->d_name);;
        }

        dir_entry = readdir(dir_path_p);
    }
}

int main(int argc, char** argv) {

    (void)argv;


    //Open dir
    const char* dir_path = ".";

    //print_help();

    if (argc < 2) print_files_in_dir(dir_path, NULL);


    return 0;
}