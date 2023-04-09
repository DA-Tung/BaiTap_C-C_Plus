#include <string.h>
#include <stdint.h>

void *calc[10];

int check_calc[10];

void show_press_num(int *count_calc)
{
    int press_num = 0;
    int count = 0;
    do
    {
        scanf("%d", &press_num);

        switch (press_num)
        {
        case 1:
            double value_typedouble;
            scanf("%lf", &value_typedouble);
            calc[count] = &value_typedouble;
            check_calc[count] = press_num;
            break;

        case 2:
            int value_typeint;
            scanf("%d", &value_typeint);
            calc[count] = &value_typeint;
            check_calc[count] = press_num;
            break;

        case 3:
            char value_typechr;
            scanf(" %c", &value_typechr);
            calc[count] = &value_typechr;      
            check_calc[count] = press_num;   
            break;    

        case 4:
            char value_typestr[10];
            scanf("%s", value_typestr);
            calc[count] = value_typestr;
            check_calc[count] = press_num;
            //printf("%s\n ",((char *)*(calc + count)));
            break;        

        default:
            break;
        }

        count++;
        if(count == 10) press_num = 0;
    } while (press_num);  

    *count_calc = count;
}

void show_calc(int count_calc)
{
    show_press_num(&count_calc);

    int sum_calc_int = 0;

    double sum_calc_double = 0;

    double show_sum_calc = 0;

    char chr_calc[20] = "";
    int count_chr = 0;

    char str_calc[10][10];
    int count_str = 0;

    //char string_calc[20];

    for(int count = 0; count < count_calc; count++)
    {
        if(check_calc[count] == 1)
        {
            sum_calc_double += *((double *)*(calc + count));
            //printf("%lf\n",*((double *)*(calc + count)));
        }

        else if(check_calc[count] == 2)
        {
            sum_calc_int += *((int *)*(calc + count));
            //printf("%d\n", *((int *)*(calc + count)));
        }

        else if(check_calc[count] == 3)
        {
            chr_calc[count_chr] = *((char *)*(calc + count));
            count_chr++;
        }

        else if(check_calc[count] == 4)
        {
            //*(str_calc + count_str) = ((char *)*(calc + count));
            //printf("string : %s\n", *(str_calc+count_str));
            
            int length_calc = strlen((char *)calc[count]);
            for(int count_str_calc = 0; count_str_calc < length_calc; count_str_calc++)
            {
                str_calc[count_str][count_str_calc] = *((char *)*(calc + count) + count_str_calc);
            }
            count_str++;
        }
    }
    
    printf("\n");
    show_sum_calc = sum_calc_double + (double)sum_calc_int;
    printf("Sum numbers of calc : %lf\n",show_sum_calc);

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

    //show_press_num(&calc_count);
    
    show_calc(calc_count);

    return 0;
}


