#include <stdio.h> 
#include <stdint.h> 
#include <string.h>

uint8_t arr[] = {1,7,9,3,7,1,2,6,7,8,2,9,9,3};

// Sort array
void SORT_ARRAY(uint8_t sort_arr[]) 
{ 
    // For Loop : 
    for(int i = 0 ; i < strlen(sort_arr) - 1; i++) 
    { 
        // For Loop : compare value at position i with all value at next position to find min value 
        for(int j = i+1; j < strlen(sort_arr); j++) 
        { 
            // Compare value between arr[i] and arr[j] to find less value. If value at position i greater value at position j, we need swap value of two position
            if(sort_arr[i] > sort_arr[j]) 
            { 
                // Assign value position i for a temporary variable 
                uint8_t temp = sort_arr[i]; 
                // Assign value position j for position i
                sort_arr[i] = sort_arr[j]; 
                // Assign value position j for temp (value at position i)
                sort_arr[j] = temp;
            }
        }
    }
}

// Count occurrences
void COUNT_NUM(uint8_t t_arr[]) 
{ 
    // Assing count = 1 <=> element of array will appear at least one time in array
    int COUNT = 1;

    // For Loop : 
    for(int i = 0; i < strlen(t_arr); i++)
    {
        // Assign value position i for temporary variable 
        uint8_t temp = t_arr[i];    

        // compare value next position and temporary variable(value at position i)
        if(t_arr[i+1] == temp)
        {
            // If equal, increase value of count add 1
            COUNT++;
        }
        else
        {
            printf("\n");
            // Printf count occurrences
            printf("Number %d appear : %d",temp,COUNT);

            // give back value count = 1, count occurrences of next element in array
            COUNT = 1;
        }
    }
}

int main(int argc, char const *argv[]) 
{ 
    SORT_ARRAY(arr);
    for(int i = 0; i < strlen(arr);i++)
    {
        printf("%d ", arr[i]);
    }

    COUNT_NUM(arr);

    return 0;
}


