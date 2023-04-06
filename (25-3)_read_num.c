#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*INITIALIZE CONSTANT -------------------------------------------------*/

const char *Number_text[] = {"KHONG","MOT","HAI","BA","BON","NAM","SAU","BAY","TAM","CHIN"};

const char *Unit_Even[] = {"NGHIN","TRIEU","TY"};

const char *Unit_Odd[] = {"MUOI","TRAM"};

/*INITIALIZE FUNCION --------------------------------------------------*/ 

void READ_POSITION(int num);
void READ_NUMBER(int num);

/*FUNCION CODE --------------------------------------------------------*/ 

/*
    This funcion is used to read position of each number
*/ 
void READ_POSITION(int num)
{
    if(num > 0)
    {
        int mod_num = num%3;    // check position unit thousand, million, billion
        int div_num = num/3;    // check position uint hundred ... 
    
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

/*
    This funcion is used to read number
*/ 
void READ_NUMBER(int num)
{
    /*
        This code is used to save each number in array and check how many numbers in number
    */     
    int arr_num[15] = {0};
    int count_num = 0;
    
    while(num > 0)
    {
        arr_num[count_num] = num%10;
        num = num/10;
        count_num++;
    }
    
    /*
        Read Number
    */ 
    for(int pos = count_num - 1; pos >= 0; pos--)
    {
        // bit check special position
        int check_pos = 0;
        
        // Check position to read number 5
        if(pos%3 == 0)
        {
            if(arr_num[pos] == 5 && arr_num[pos+1] != 0)
            {
                printf("LAM ");
                check_pos = 1;
            }
        }
        
        // Check position to read number 0,1
        else if(pos%3 == 1)
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
        
        // Check position of number 000 at uint thousand,million,billion to ingore
        else if(pos%3 == 2)
        {
            if(arr_num[pos] == 0 && arr_num[pos-1] == 0 && arr_num[pos-2] == 0)
            {
                pos = pos - 2;
                check_pos = 1;
            }
        }
        
        // Read number and position number
        if(check_pos == 0)
        {
            if(arr_num[pos] != 0 || pos%3 != 0)
            {
                printf("%s ", Number_text[arr_num[pos]]);                
            }
            READ_POSITION(pos);
        }
    }
}

/*MAIN CODE -----------------------------------------------------------*/

int main()
{    
    int num;
    scanf("%d",&num);
    READ_NUMBER(num);
    
    return 0;
}



