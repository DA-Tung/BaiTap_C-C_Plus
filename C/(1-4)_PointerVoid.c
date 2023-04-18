#include <string.h>
#include <stdint.h>
#include <stdio.h>

/*INITIALIZE GLOBAL ---------------------------------------------------*/
void *Calc[10];

int Check_Calc[10];

/*INITIALIZE FUNCION --------------------------------------------------*/ 
void Conv_char_to_String(char conv_char,char *conv_str);        // Convert one character to string
int COMP_STR(const char *str1, const char *str2);               // Compare two string
void ADD_ARR(char *arr, char *add_arr);                         // Add a string to another string
void SHOW_SORT_STR(char arr[][10], int len_arr);                // Display all string after sorting 
void SELECT_PRESS_NUM(int *Count_Calc);                         // Select number to printf value of each typedata
void SHOW_CALC(int Count_Calc);                                 // Display all calculation of all typedata

/*FUNCION CODE --------------------------------------------------------*/ 

/*
    * This funcion is used to convert a chr to string
        first character of string is chr
        sencond character of string is '\0'
*/
void Conv_char_to_String(char conv_char,char *conv_str)
{
    conv_str[0] = conv_char;
    conv_str[1] = '\0';
}

/*
    * This funcion is used to compare two string
    * return value :
        0 : equal
        1 : str1 < str2
        2 : str1 > str2
*/
int COMP_STR(const char *str1, const char *str2)
{
    int Pos_arr = 0;
    int comp_flag = 0;

    while(1)
    {
        if(str1[Pos_arr] == str2[Pos_arr])                          // increase position in array if two characters together position is equal
        {
            Pos_arr++;
            if(str1[Pos_arr] == '\0' && str2[Pos_arr] == '\0')      // if the last two position of two strings is '\0' -> two strings is equal
            {
                break;
            }
        } 
        else if(str1[Pos_arr] < str2[Pos_arr])                      // compare two characters has together position
        {
            comp_flag = 1;                                          // return 1 if str1 < str2
            break;
        }
        else if(str1[Pos_arr] > str2[Pos_arr])                      // compare two characters has together position                     
        {
            comp_flag = 2;                                          // return 2 if str1 > str2
            break;
        }
    }
    
    return comp_flag;
}

/*
    * This funcion is used to add a string in another string
*/
void ADD_ARR(char *arr, char *add_arr)
{
    int len_add_arr = strlen(add_arr);                  // Calculation length of string 
    int len_arr = strlen(arr);                          // Calculation length of string 

    if(len_arr != 0)                                    // Check string is empty or not
    {
        arr[len_arr] = ' ';                             // Add space if it is not empty string (create empty distance between words) 
        len_arr++;                                      // Increase length of string                                                 
    }
    for(int pos = 0; pos < len_add_arr; pos++)          // Assign each character of string to another string
    {
        arr[len_arr + pos] = add_arr[pos];
    }
    arr[len_arr + len_add_arr] = '\0';                  
}

/*
    * This funcion is used to display all string with position of table characters
*/
void SHOW_SORT_STR(char arr[][10], int len_arr)
{
    char new_str[110] = "";                                         // New string need display
    int Pos_Min_Str = 0;                                            // Position minium word of array                                       

    int mark_arr[len_arr];                                          /* Create a mark array                   */
    for(int Pos_mark = 0; Pos_mark < len_arr; Pos_mark++)           /* all value in array will assign 1      */
    {                                                               /*      1 : word is not check            */
        mark_arr[Pos_mark] = 1;                                     /*      0 : word is checked              */
    }

    for(int Pos_1 = 0; Pos_1 < len_arr; Pos_1++)                                    // First Loop For
    {
        if(mark_arr[Pos_1] == 1)                                                    // word is check or not
        {
            Pos_Min_Str = Pos_1;                                                    // Assign position word at first Loop for position minium word of array 
            for(int Pos_2 = 0; Pos_2 < len_arr; Pos_2++)                            // Second Loop For
            {
                if(mark_arr[Pos_2] == 1 && Pos_2 != Pos_1)                          // Word is check or not && position word at first loop and second loop is equal or not
                {                                           
                    int value_comp = COMP_STR(arr[Pos_Min_Str], arr[Pos_2]);        // Compare two string
                    if(value_comp == 2)                                             // arr[pos_Min_Str] < arr[Pos_2]
                    {
                        Pos_Min_Str = Pos_2;                                        // Assign new value for position minium word of array
                    }
                }
            }
            mark_arr[Pos_Min_Str] = 0;                                              // Mark position minium word of array is 0            
            ADD_ARR(new_str,arr[Pos_Min_Str]);                                      // Add minium word of array in new array
        }
    }
    
    for(int check = 0; check < len_arr; check++)                                    // Maxium word of array still mark is 1. Find and check position of it
    {                                                                                
        if(mark_arr[check] == 1)                                                    
        {
            ADD_ARR(new_str,arr[check]);                                            // printf maxium word of array in new array
        }
    }
    
    printf("String of Calc : %s", new_str);                                         // Display new array
}

/*
    * This funcion is used to select and save type data 
    * Number :
        Num 0 : exit funcion
        Num 1 : type double
        Num 2 : type Integer
        Num 3 : type Character
        Num 4 : type Word (String)
    * Count : Count value. The maximum number is 10 times
    * Press_Num : store the value corresponding to the data type 
*/
void SELECT_PRESS_NUM(int *Count_Calc)
{
    int Press_Num = 0;
    int Count = 0;
    int Count_TypeStr = 0;
    do
    {
        scanf("%d", &Press_Num);
        switch (Press_Num)
        {            
        case 1:
            double *Value_TypeDouble;               // save value in Calc with type data is double
            Value_TypeDouble = (double *)calloc(10, sizeof(double));
            scanf("%lf", Value_TypeDouble);       
            Calc[Count] = Value_TypeDouble;       
            Check_Calc[Count] = Press_Num;          // mark array is 1 with type data double
            break;

        case 2:
            int *Value_TypeInt;                     // save value in Calc with type data is integer                        
            Value_TypeInt = (int *)calloc(10, sizeof(int));
            scanf("%d", Value_TypeInt);
            Calc[Count] = Value_TypeInt;
            Check_Calc[Count] = Press_Num;          // mark array is 2 with type data integer       
            //Count_typeInt++;
            break;

        case 3:
            char *Value_TypeChr;                    // save value in Calc with type data is character
            Value_TypeChr = (char *)calloc(10, sizeof(char));
            scanf(" %c", Value_TypeChr);
            Calc[Count] = Value_TypeChr;      
            Check_Calc[Count] = Press_Num;          // mark array is 3 with type data character   
            break;    

        case 4:
            char Value_TypeStr[10][10];             // save value in Calc with type data is string
            scanf(" %s", Value_TypeStr[Count_TypeStr]);
            Calc[Count] = Value_TypeStr[Count_TypeStr];
            Check_Calc[Count] = Press_Num;          // mark array is 4 with type data string          
            Count_TypeStr++;
            break;        

        // default
        default:
            break;
        }
        Count++;                                    /* increase value of Count                          */
        if(Count == 10) Press_Num = 0;              /* and compare with 10 (maximun 10 times)           */ 
    } while (Press_Num);  

    *Count_Calc = Count;
}

/*
    * This funcion is used to show all Calculation type data at pointer void Calc
    * check typedata : use mark array Check_Calc to check type data in pointer void Calc
*/
void SHOW_CALC(int Count_Calc)
{
    SELECT_PRESS_NUM(&Count_Calc);

    int sum_Calc_int = 0;
    double sum_Calc_double = 0;
    double show_sum_Calc = 0;
    char chr_Calc[10] = "";
    int Count_chr = 0;
    char str_Calc[10][10];
    int Count_str = 0;
    
    /*
        loop for to check type data and save in variable
    */
    for(int Count = 0; Count < Count_Calc; Count++)
    {
        if(Check_Calc[Count] == 1)
        {
            sum_Calc_double += *((double *)*(Calc + Count));        // assign value type double                                                
        }
        else if(Check_Calc[Count] == 2)
        {
            sum_Calc_int += *((int *)*(Calc + Count));              // assign value type integer
        }
        else if(Check_Calc[Count] == 3)
        {
            chr_Calc[Count_chr] = *((char *)*(Calc + Count));       // assign value type character
            Conv_char_to_String(chr_Calc[Count_chr],str_Calc[Count_str]);
            Count_chr++;
            Count_str++;
        }
        else if(Check_Calc[Count] == 4)
        {           
            int length_Calc = strlen((char *)Calc[Count]);
            for(int Count_str_Calc = 0; Count_str_Calc < length_Calc; Count_str_Calc++)             // assign value type string
            {
                str_Calc[Count_str][Count_str_Calc] = *((char *)*(Calc + Count) + Count_str_Calc);  // assign each character in two-dimensional array
            }
            str_Calc[Count_str][length_Calc + 1] = '\0';
            Count_str++;
        }
    }

    printf("\n");
    // Print sum of all value integer and double
    show_sum_Calc = sum_Calc_double + (double)sum_Calc_int;
    printf("Sum numbers of Calc : %lf\n",show_sum_Calc);

    // Printf string of all character and string
    for(int Count_1 = 0; Count_1 < Count_str; Count_1++)
    {
        printf("string : %s\n",str_Calc[Count_1]);
    }
    SHOW_SORT_STR(str_Calc,Count_str);
}

/*MAIN CODE -----------------------------------------------------------*/

int main()
{
    int Calc_Count;
    SHOW_CALC(Calc_Count);
    return 0;
}

