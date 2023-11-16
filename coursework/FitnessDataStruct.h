#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
int number_of_records = 0;
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
    number_of_records = counter;
}




int option_a(char file_to_read[]){
    FILE *file;
    file = fopen(file_to_read , "r");
    //check if the file is empty
    //If it is return an error
    if(file == NULL) {
        perror("");
        printf("Error could not open file");
        exit(1);

    }
    tokenise_file(file);
    
}

void option_b(){
    //output the number of records in the given file
    printf("Number of records in file: %d\n", number_of_records);


}

int option_c(){
    int count_c = 0;
    int fewest_steps = 9999;
    int index_position_c;

    while (count_c < number_of_records){
        if (records[count_c].steps<fewest_steps){
            fewest_steps = records[count_c].steps;
            index_position_c = count_c;
        }
        count_c+=1;
        
    }
    printf("%s %d\n",records[index_position_c].date, records[index_position_c].steps);
    



}


int option_d(){
    int count_d = 0;
    int largest_steps = 0;
    int index_position_d = 0;
    while (count_d < number_of_records){
        if (records[count_d].steps>largest_steps){
            largest_steps = records[count_d].steps;
            index_position_d = count_d;
        }
        count_d+=1;
        
    }
    printf("%s %d\n",records[index_position_d].date, records[index_position_d].steps);
    



}

int option_e(){
    int count_e = 0;
    int total = 0;
    while (count_e < number_of_records){
        total = total + records[count_e].steps;
        count_e+=1;
    }
    int mean = round(total/number_of_records);

    printf("%d\n", mean);
}

int option_f(){
    int count_f = 0;
    int current_longest = 0;
    char* period_start = 0;
    char* period_end = 0;
    while (count_f < number_of_records){
        if(records[count_f].steps>500&&count_f!=0){
             return 0;  
            }

    }
    return 0;
}