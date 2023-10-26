#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here

//Assign the file to read to the variable file_to_read
char file_to_read [] = "FitnessData_2023.csv";
//set buffer size for each line (used const to be accepted by line_buffer)
const int buffer_size = 40;
//create a variable to hold the line
char line_buffer[40];
//variable to count how many lines are in the file
int counter = 0;
//create a variable for dates
char dates [11];
//create a variable for time
char time [6];
//create a variable for steps
char steps [4];
//create an array
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

// Complete the main function
int main() {
    //file_to_read is opened
    FILE *file = fopen(file_to_read , "r");
    //check if the file is empty
    //If it is return an error
    if(file == NULL) {
        perror("");
        return 1;
    }
    
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        tokeniseRecord(line_buffer, ",", dates, time, steps);
        
        //Save the date in the array
        strcpy(records[counter].date,dates);
        //save the time in the array
        strcpy(records[counter].time,time);
        //I used google so I could save the integer steps as a string
        //https://www.geeksforgeeks.org/convert-string-to-int-in-c/
        records[counter].steps=atoi(steps);

        //increment the counter
        counter=counter+1;
    }
    //output the number of records in the given file
    printf("Number of records in file: %d\n", counter);

    //use a for loop to output the first three records
    for (int i = 0; i<3; i++)
    {
        printf("%s/%s/%d\n",records[i].date, records[i].time, records[i].steps);
    }

    //close the file;
    fclose(file);

    return 0;

    


}
