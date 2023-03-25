/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdint.h>

//char arr[] = "Code, Compile, Run";
char arr[] = "Make a mistake. All your attempts to create a chilling effect, a throttling effect, a strangulating effect on open fearless speech relating to public influence will not stop either Rahul Gandhi or the Congress Party";
char rev_arr[] = "";  

// Reverse Arry
void REVERSE_ARR(char old_arr[],char new_arr[])
{
    // calculator length of array 
    int length_arr = strlen(old_arr);   

    // new_index : variable counter of new_arr array    
    int new_index = 0;  

    // s_char_index : start position of a word in the array            
    int s_char_index;   

    // e_char_index : end position of a word in the array
    int e_char_index = length_arr - 1;   

    // check_pos : check character at current position 
    int check_pos = length_arr - 1; 
    
    // Verify first word in array old_arr
    while(check_pos >= -1)  
    {
        // Check character spacer or position = -1(Verify first word in array)
        if(old_arr[check_pos] == ' ' || check_pos == -1)    
        {
            // For Loop : start to end of each word in array old_arr and assign for array arr
            for(s_char_index = check_pos + 1; s_char_index <= e_char_index; s_char_index++) 
            {
                // assign character old_arr to new_arr
                new_arr[new_index] = old_arr[s_char_index]; 
                // Increase variable counter of new_arr array   
                new_index++;    
            }

            // Assign next end position of a word in array old_arr
            e_char_index = check_pos - 1;   

            // Check end position of a word to verify add character spacer
            if(e_char_index >= 0)   
            {
                // add character spacer for new_array
                new_arr[new_index] = ' ';   
                // Increase variable counter of array after add character spacer
                new_index++;    
            }
        }

        // Decrease position to cotinue check 
        check_pos--;          
    } 
}

int main(int argc, char const *argv[]) 
{
    REVERSE_ARR(arr,rev_arr);
    int n = strlen(rev_arr);
    
    printf("%s", rev_arr);
    printf("\n");
    printf("%d", n);
}


