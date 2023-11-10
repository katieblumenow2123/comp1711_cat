#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int option_a(char file_to_read[]){
    FILE *file = fopen(file_to_read , "r");
    //check if the file is empty
    //If it is return an error
    if(file == NULL) {
        perror("");
        exit(1);
    }
    
    
}