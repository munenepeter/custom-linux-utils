#include <stdio.h>
#include <stdlib.h>
/*
function cat(files):
    for each file in files:
        open file
        while not end of file:
            read line from file
            print line
        close file

*/

void cat(char *files[], int number_of_files){
    for(int i = 0; i < number_of_files; ++i){
        FILE *file = fopen(files[i], "r");
        
        if(file == NULL){
            fprintf(stderr, "E: could not open file %s:%s", files[i], errno); 
            return 1;
        }
        
        while(){
            
        }
    }
}
int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    printf("I am a duplicate implementation of the cat command");

    return 0;
}
