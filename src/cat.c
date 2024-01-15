#include <stdio.h>
#include <stdlib.h>

void cat(char *files[], int number_of_files){
    for(int i = 0; i < number_of_files; ++i){
        FILE *file = fopen(files[i], "r");
        
        if(file == NULL){
            fprintf(stderr, "E: could not open file %s:%s", files[i], errno); 
            return 1;
        }
        
        char line[256];
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }

        fclose(file);
    }
}
int main(int argc, char* argv[]) {
   if (argc < 2) {
       printf(
        "usage: %s file1 [file2, file3, ....]\n List information about the  in the current directory.", argv[0]);
        return 1;
    }

    cat(argv + 1, argc - 1);

    return 0;
}
