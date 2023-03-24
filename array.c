#include <stdio.h> 
#include <stdint.h> 
#include <string.h>

uint8_t arr[] = {1,7,9,3,7,1,2,6,7,8,2,9,9,3};

// Sort array
void SORT_ARRAY(uint8_t t_arr[]) 
{ 
    for(int i = 0 ; i < strlen(t_arr) - 1; i++) 
    { 
        for(int j = i+1; j < strlen(t_arr); j++) 
        { 
            if(t_arr[i] > t_arr[j]) 
            { 
                uint8_t temp = t_arr[i]; 
                t_arr[i] = t_arr[j]; 
                t_arr[j] = temp; 
            }
        }
    }
}

// Count occurrences
void COUNT_NUM(uint8_t t_arr[]) 
{ 
    int COUNT = 1;

    for(int i = 0; i < strlen(t_arr); i++)
    {
        uint8_t temp = t_arr[i];    
        if(t_arr[i+1] == temp)
        {
            COUNT++;
        }
        else
        {
            printf("\n");
            printf("So %d xuat hien : %d",temp,COUNT);
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


