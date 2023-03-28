/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

char *Number_text[] = {"KHONG","MOT","HAI","BA","BON","NAM","SAU","BAY","TAM","CHIN"};

char *Unit_Even[] = {"NGHIN","TRIEU","TY"};

char *Unit_Odd[] = {"MUOI","TRAM"};

// typedef enum
// {
//     NGHIN = 1,
//     TRIEU = 2,
//     TY = 3,
// }Unit_Even;

// typedef enum
// {
//     MUOI = 1,
//     TRAM = 2,
// }Unit_Odd;

void Read_Pos(int num)
{
    if(num > 0)
    {
        int mod_num = num%3;
        int div_num = num/3;
    
        if(mod_num != 0)
        {
            printf("%s ",Unit_Odd[mod_num - 1]);            
        }
    
        else
        {
            printf("%s ", Unit_Even[div_num - 1]);
        }          
    }
}

void Read_Num(int num)
{
    //int arr[];
    int arr_num[15] = {0};
    int count_num = 0;
    
    while(num > 0)
    {
        arr_num[count_num] = num%10;
        num = num/10;
        count_num++;
    }
    
    //printf("%d",count_num);
    
    for(int pos = count_num - 1; pos >= 0; pos--)
    {
        //printf("%s ", Number_text[arr_num[pos]]);
        
        //Read_Pos(pos);
        int check_pos = 0;
        
        if(pos%3 == 1)
        {
            if(arr_num[pos] == 0)
            {
                check_pos = 1; 
                printf("LINH ");
            }
            else if(arr_num[pos] == 1)
            {
                check_pos = 1;
                printf("MUOI ");
            }
            else
            {
                check_pos = 0;
            }
        }
        
        if(check_pos == 0)
        {
            if(arr_num[pos] != 0 || pos%3 != 0)
            {
                printf("%s ", Number_text[arr_num[pos]]);                
            }
            Read_Pos(pos);
        }
    }
}

int main()
{    
    Read_Num(1005719);
    
    return 0;
}
