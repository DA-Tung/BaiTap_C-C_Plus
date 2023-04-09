#include <string.h>
#include <stdint.h>

void *calc[10];

int check_calc[10];

void *calc[10];

int check_calc[10];

/*
    This funcion is used to convert a chr to string
    first character of string is chr
    sencond character of string is '\0'
*/
void Conv_char_to_String(char conv_char,char *conv_str)
{
    conv_str[0] = conv_char;
    conv_str[1] = '\0';
}

/*
    This funcion is used to compare two string

    return value :
        0 : equal
        1 : str1 < str2
        2 : str1 > str2
*/
int comp_str(const char *str1, const char *str2)
{
    int pos_arr = 0;
    
    int comp_flag = 0;

    while(1)
    {
        if(str1[pos_arr] == str2[pos_arr])                          // increase position in array if two characters together position is equal
        {
            pos_arr++;
            if(str1[pos_arr] == '\0' && str2[pos_arr] == '\0')      // if the last two position of two strings is '\0' -> two strings is equal
            {
                break;
            }
        } 

        else if(str1[pos_arr] < str2[pos_arr])                      // compare two characters has together position
        {
            comp_flag = 1;                                          // return 1 if str1 < str2
            break;
        }

        else if(str1[pos_arr] > str2[pos_arr])                      // compare two characters has together position                     
        {
            comp_flag = 2;                                          // return 2 if str1 > str2
            break;
        }
    }
    
    return comp_flag;
}

/*
    This funcion is used to select and save type data 

    Num 0 : exit funcion
    Num 1 : type double
    Num 2 : type Integer
    Num 3 : type Character
    Num 4 : type Word (String)

    count : count value. The maximum number is 10 times
    press_num : store the value corresponding to the data type 
*/
void SELECT_PRESS_NUM(int *count_calc)
{
    int press_num = 0;
    int count = 0;
    do
    {
        scanf("%d", &press_num);

        switch (press_num)
        {
               
        case 1:
            double value_typedouble;                // save value in Calc with type data is double
            scanf("%lf", &value_typedouble);       
            calc[count] = &value_typedouble;       
            check_calc[count] = press_num;          // mark array with type data double

        case 2:
            int value_typeint;                      // save value in Calc with type data is integer
            scanf("%d", &value_typeint);
            calc[count] = &value_typeint;
            check_calc[count] = press_num;          // mark array with type data integer       
            break;

        case 3:
            char value_typechr;                     // save value in Calc with type data is character
            scanf(" %c", &value_typechr);
            calc[count] = &value_typechr;      
            check_calc[count] = press_num;          // mark array with type data character   
            break;    

        case 4:
            char value_typestr[10];                 // save value in Calc with type data is string
            scanf("%s", value_typestr);
            calc[count] = value_typestr;
            check_calc[count] = press_num;          // mark array with type data string          
            //printf("%s\n ",((char *)*(calc + count)));
            break;        

        // default
        default:
            break;
        }

        count++;                                    /* increase value of count                          */
        if(count == 10) press_num = 0;              /* and compare with 10 (maximun 10 times)           */ 
    } while (press_num);  

    *count_calc = count;
}

/*
    This funcion is used to show all calculation type data at pointer void Calc

    use mark array check_calc to check type data in pointer void Calc
*/
void SHOW_CALC(int count_calc)
{
    SELECT_PRESS_NUM(&count_calc);

    int sum_calc_int = 0;

    double sum_calc_double = 0;

    double show_sum_calc = 0;

    char chr_calc[20] = "";
    int count_chr = 0;

    char str_calc[10][10];
    int count_str = 0;

    char show_calc_str[100] = "";
    /*
        loop for to check type data and save in variable
    */

    for(int count = 0; count < count_calc; count++)
    {
        if(check_calc[count] == 1)
        {
            sum_calc_double += *((double *)*(calc + count));        // assign value type double                                                
        }

        else if(check_calc[count] == 2)
        {
            sum_calc_int += *((int *)*(calc + count));              // assign value type integer
        }

        else if(check_calc[count] == 3)
        {
            chr_calc[count_chr] = *((char *)*(calc + count));       // assign value type character
            count_chr++;
        }

        else if(check_calc[count] == 4)
        {           
            int length_calc = strlen((char *)calc[count]);
            for(int count_str_calc = 0; count_str_calc < length_calc; count_str_calc++)             // assign value type string
            {
                str_calc[count_str][count_str_calc] = *((char *)*(calc + count) + count_str_calc);  // assign each character in two-dimensional array
            }
            count_str++;
        }
    }

    // Print sum of all value integer and double
    show_sum_calc = sum_calc_double + (double)sum_calc_int;
    printf("Sum numbers of calc : %lf\n",show_sum_calc);

    // Printf string of all character and string
    printf("\n");
    for(int count_1 = 0; count_1 < count_str; count_1++)
    {
        printf("string : %s\n",str_calc[count_1]);
    }

    printf("\n");
    printf("char : %s", chr_calc);
}

int main()
{
    int calc_count;

    //SELECT_PRESS_NUM(&calc_count);
    
    SHOW_CALC(calc_count);

    return 0;
}





