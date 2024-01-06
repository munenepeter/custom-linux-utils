#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void print_help() {
    printf(
        "usage: custom-ls ls [OPTION]\n"
        "List information about the FILEs in the current directory."
        "Options are:\n"
        "    --help: display what you are reading now\n"
    );
}

void print_files_in_dir(const char* directory_path) {
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
        printf("file: %s\n", dir_entry->d_name);
        dir_entry = readdir(dir_path_p);
    }
}

int main(int argc, char** argv) {

 

    //Open dir
   // const char* dir_path = ".";
  //  print_files_in_dir(dir_path);

    //print_help();

    int flags, opt = 0;
    int nsecs, tfnd = 0;


    while ((opt = getopt(argc, argv, "ali:")) != -1) {
        switch (opt) {
        case 'n':
            flags = 1;
            break;
        case 't':
            nsecs = atoi(optarg);
            tfnd = 1;
            break;
        default: /* '?' */
            fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n",
        flags, tfnd, nsecs, optind);

    if (optind >= argc) {
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
    }

    printf("name argument = %s\n", argv[optind]);


    return 0;
}