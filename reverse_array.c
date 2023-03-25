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
void reverse_arr(char old_arr[],char new_arr[])
{
    int n = strlen(old_arr);
    int new_pos = 0;
    int old_pos;
    int last_pos = n - 1;
    int pos;
    
    for(pos = n - 1; pos >= -1; pos--)
    {
        if(old_arr[pos] == ' ' || pos == -1)
        {
            for(old_pos = pos + 1; old_pos <= last_pos; old_pos++)
            {
                new_arr[new_pos] = old_arr[old_pos];
                new_pos++;
            }
            last_pos = pos - 1;
            if(last_pos >= 0)
            {
                new_arr[new_pos] = ' ';
                new_pos++;
            }
        }
    }
}

int main(int argc, char const *argv[]) 
{
    reverse_arr(arr,rev_arr);
    int n = strlen(rev_arr);
    
    printf("%s", rev_arr);
    printf("\n");
    printf("%d", n);
}


