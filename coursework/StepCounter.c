#include "FitnessDataStruct.h"




int menu(){
    //create a while loop so the program will run until the user quits 
    while (option!='Q'){
        printf ("PICK AN OPTION: ");
        scanf ("%s", &option);
        //switch case for each option

        switch (option)
        {
            case 'A': printf ("Input filename:");
                    scanf("%s", file_to_read);
                    option_a(file_to_read);
                    break;

            case 'B': printf ("Total records: ");
                    break;

        
            case 'C': printf ("Fewest steps: ");
                    break;

            case 'D': printf ("Largest steps: ");
                    break;
            
            case 'E': printf ("Mean step count: ");
                    break;

            case 'F': printf ("Longest period start, Longest perido end");
                    break;

            default:  break;
        
        }
   



    }



}


int main(){

        menu();


        
        return 0;
}