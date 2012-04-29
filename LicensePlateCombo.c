//Inport the standard input output library
#include <stdio.h>

int main(void){
    
    //Declare a variable to store the input population
    int pop;
    
    //Ask for a population from the user and assign that value to pop
    printf("Please enter the population of the town: ");
    scanf("%d", &pop);   

    //Repeat the program until the user enters a negative population
    while(pop >= 0){
        
        //Checks if user entered 0, which is a special case
        if(pop == 0){
            printf("The town has no people and thus no one needs any license plates\n");  
        //Otherwise perform the normal calculations
        }else{
            //Declare variables
            //  maxNums is the greatest total possible combinations for a plate based on how many digits it has. 
            //  N is the current amount of numbers used in the plate
            //  L is the current amount of letters used in the plate
            //  N_Final and L_Final are the same as N and L except that they correspond to the letter and number combo that yields the smallest excess plates
            int maxNums = 1, N = 0, L = 0, N_Final, L_Final;
            
            //Multiplys maxNum by 26 until it is larger than the population, and increments L each time
            //At the end of the loop L represents the numbers of digits in the license plate
            while(maxNums < pop){
                maxNums *= 26;
                L++;   
            }
        
            //Now that we know the number of digits in the plate, we now must test all the
            //possible combinations of letters and numbers in the license plate
        
            //Declare a mininum excess variable and set it to the maximum number of combinations as a starting value 
            int minExcess = maxNums;
            
            //Loop through each combination of L and N where with each loop L is
            //decremented and N is incremented. This is done until L passes 0
            for(L = L; L >= 0; L--, N++){
                //Calculates the number of combinations with this combination of N and L
                int combinations = pow(26, L) * pow(10, N);
                
                //Determine the excess plates made with this combination 
                int excess = combinations - pop;
                
                //If the excess is less than the current minimum excess, then make
                //it the new minimum excess and record the combination in N_Final and
                //L_Final
                if(excess < minExcess && excess >= 0){
                    minExcess = excess;
                    N_Final = N;
                    L_Final = L;  
                }    
            }
            //Print the results
            printf("The plate will have %d letters and %d numbers\n\n", L_Final, N_Final);
        }
        
        //Ask for another population
        printf("Please enter the population of the town: ");
        scanf("%d", &pop);
    }
    
}
