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
                    option_b(file_to_read);
                    break;

        
            case 'C': printf ("Fewest steps: ");
                    option_c();
                    break;

            case 'D': printf ("Largest steps: ");
                    option_d();
                    break;
            
            case 'E': printf ("Mean step count: ");
                    option_e();
                    break;

            case 'F': printf ("Longest period start, Longest period end");
                    option_f();
                    break;

            default:  break;
        
        }
   



    }



}


int main(){

        menu();


        
        return 0;
}