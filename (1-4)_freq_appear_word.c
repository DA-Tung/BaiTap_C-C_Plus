#include <stdio.h>
#include <string.h>
#include <stdint.h>

char test_arr[] = "MOT NGOI NHA, HAI NGOI NHA, TONG CO HAI NHA, MOT CON DUONG";

char conv_new_arr[50][10];

// void delete_arr(char de_arr[], int length)
// {
//     for(int i = 0; i <= length; i++)
//     {
//         de_arr[i] = '\0';
//     }
// } 

int comp_arr(const char *arr1, const char *arr2)
{
    int check_arr = 1;

    int length_1 = strlen(arr1);
    int length_2 = strlen(arr2);

    if(length_1 != length_2)
    {
        check_arr = 0;
    }
    else
    {
        for(int count = 0; count < length_1; count++)
        {
            if(arr1[count] != arr2[count])
            {
                check_arr = 0;
                break;
            }
        }
    }

    return check_arr;
} 

void conv_to_new_arr(const char old_arr[],char new_arr[][10], int *length_arr)
{
    int length_new_arr = 0;

    int num_chr_new_arr = 0;

    int length_old_arr = strlen(old_arr);

    int count_old_arr = 0;

    // int count_temp_arr = 0;

    // char temp_arr[20] = "";

    //char last_pos_temp_arr = 0;

    while(count_old_arr <= length_old_arr)
    {
        if(old_arr[count_old_arr] == ' ' || count_old_arr == length_old_arr)
        {
            length_new_arr++;
            num_chr_new_arr = 0;
        }
        else
        {
            if(old_arr[count_old_arr] != ',')
            {
                new_arr[length_new_arr][num_chr_new_arr] = old_arr[count_old_arr];
                num_chr_new_arr++;
            }
        }

        count_old_arr++;
    }

    *length_arr = length_new_arr;

    for(int count = 0; count < length_new_arr; count++)
    {
        printf("%s\n", new_arr[count]);
    }
}

void show_freq_appearance_word(char arr[][10], int length_arr)
{          
    int check_word[length_arr];

    for(int count = 0; count < length_arr; count++)
    {
        check_word[count] = 1;
    }

    int freq_appear = 1;

    for(int count_1 = 0; count_1 < length_arr - 1; count_1++)
    {
        {                                
            for(int count_2 = count_1 + 1; count_2 < length_arr; count_2++)
            {             
                if(check_word[count_1] == 1 && check_word[count_2] == 1)
                {

                    int value_comp = comp_arr(arr[count_1],arr[count_2]);
                    if(value_comp == 1)
                    {
                        freq_appear++;
                        check_word[count_2] = 0;
                    }
                }
            }
        }

        if(freq_appear > 1)
        {
            printf("Freq appearance of word %s : %d times\n", arr[count_1], freq_appear);
            freq_appear = 1;
        }
    }
}

int main()
{
    int length_conv_arr;

    conv_to_new_arr(test_arr,conv_new_arr, &length_conv_arr); 

    show_freq_appearance_word(conv_new_arr, length_conv_arr);

   return 0;

}


