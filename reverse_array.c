/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h> 
#include <stdint.h> 
#include <string.h>

//char arr[] = "Make a mistake. All your attempts to create a chilling effect, a throttling effect, a strangulating effect on open fearless speech relating to public influence will not stop either Rahul Gandhi or the Congress Party";
char arr[] = "Code, Compile, Run and Debug C program online";


void concatenation_str(char before_str[],char after_str[])
{
    int length_before = strlen(before_str);
    int length_after = strlen(after_str);
    int j = 0;
    int i;
    before_str[length_before] = ' ';
    for(i = length_before + 1; i < length_before + length_after; i++)
    {
        
        before_str[i] = after_str[j];
        j++;
    }
}

void reverse_char(char rev_arr[])
{
    int n = strlen(rev_arr) - 1;
    int i = 0;
    char rev;
    while(i < n)
    {
        rev = rev_arr[i];
        rev_arr[i] = rev_arr[n];
        rev_arr[n] = rev; 
        n--;
        i++;
    }
}

void reverse_array(char old_arr[], char new_array[])
{
    int n = strlen(old_arr);
    int j;
    for(int i = n - 1; i >= 0; i++)
    {   
        char temp[] = "";
        for(j = 0; i >= 0 && old_arr[i] != ' ';i-- , j++)
        {
            temp[j] = old_arr[i];
        }


    }
}

int main(int argc, char const *argv[]) 
{    
    //concatenation_str(new_arr,arr1);
    return 0;
}


