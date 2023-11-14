#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;


//define variables
const int buffer_size = 40;
char line_buffer[40];
char file_to_read[100];
char option;
int counter = 0;
char dates [11];
char time [6];
char steps [4];
FITNESS_DATA records [100];

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

int tokenise_file(FILE *file){
        while (fgets(line_buffer, buffer_size, file) != NULL) {
                tokeniseRecord(line_buffer, ",", dates, time, steps);
                
                //Save the date in the array
                strcpy(records[counter].date,dates);
                //save the time in the array
                strcpy(records[counter].time,time);
                //I used google so I could save the integer steps as a string
                records[counter].steps=atoi(steps);

                //increment the counter
                counter=counter+1;
    }
}


int option_b(){


}


int option_a(char file_to_read[]){
    FILE *file;
    file = fopen(file_to_read , "r");
    //check if the file is empty
    //If it is return an error
    if(file == NULL) {
        perror("");
        exit(1);

    }
    tokenise_file(file);
    
}