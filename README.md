# bai_tap_c_interview_T3


/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint8_t arr[] = {1,7,9,3,7,1,2,6,7,8,2,9,9,3};

// Sort
void sort_array(uint8_t t_arr[])
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

// 
void count_num(uint8_t t_arr[])
{
    int count = 1;
    
    for(int i = 0; i < strlen(t_arr); i++)
    {
        uint8_t temp = t_arr[i];    
        if(t_arr[i+1] == temp)
        {
            count++;
        }
        else
        {
            printf("\n");
            printf("So %d xuat hien : %d",temp,count);
            count = 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    sort_array(arr);
    
    for(int i = 0; i < strlen(arr);i++)
    {
        printf("%d ", arr[i]);
    }
    
    count_num(arr);
}





