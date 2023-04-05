#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*INITIALIZE ----------------------------------------------------------*/
char test_arr[] = "MOT NGOI NHA, HAI NGOI NHA, TONG CO HAI NHA, MOT CON DUONG";

char conv_two_dim_arr[50][10];

/*INITIALIZE FUNCION --------------------------------------------------*/ 
int len_arr(const char *arr);                                                               // read length of array
int comp_arr(const char *arr1, const char *arr2);                                           // check if two arrays are equal or not
void conv_to_two_dim_arr(const char one_dim_arr[],char two_dim_arr[][10], int *length_arr); // convert a array to two dimensional array
void show_freq_appearance_word(char arr[][10], int length_arr);                             // show word in array

/*FUNCION CODE --------------------------------------------------------*/ 

/*
    This funcion is used to read length of array
*/ 
int len_arr(const char *arr)
{
    int length = 0;
    
    while(1)
    {
        if(arr[length] == '\0')     // check if character equal or not with character empty
        {
            break;
        }
        else
        {
            length++;               // increase value of length
        }
    }
    
    return length;
} 

/*
    This funcion is used to compare two arrays equal or not
*/ 
int comp_arr(const char *arr1, const char *arr2)
{
    int check_arr = 1;

    int length_1 = len_arr(arr1);   // read length of array 1
    int length_2 = len_arr(arr2);   // read length of array 2

    if(length_1 != length_2)        // check value of length each array is equal or not 
    {
        check_arr = 0;
    }
    else
    {
        // check each character of array at together position is equal or not
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

/*
    This funcion is used to convert a array to two dimensional array
*/ 
void conv_to_new_arr(const char one_dim_arr[],char two_dim_arr[][10], int *length_arr)
{
    /*
        initialize local variables  
    */ 
    int length_two_dim_arr = 0;                     // save length of two dimensional array
        
    int num_chr_two_dim_arr = 0;                    // save position of character in word of two dimensional array

    int length_one_dim_arr = len_arr(one_dim_arr);  // length of one dimensional array 

    int count_one_dim_arr = 0;                      // position of character of one dimensional array   

    /*
        convert a array to two dimensional array  
        action : save each character of one dimensional array in two dimensional array
    */ 
    while(count_one_dim_arr <= length_one_dim_arr)
    {
        
        if(one_dim_arr[count_one_dim_arr] == ' ' || count_one_dim_arr == length_one_dim_arr)            // check character ' ' or end of character
        {
            length_two_dim_arr++;                       // increase size of two dimensional array
            num_chr_two_dim_arr = 0;                    // reset value first position of character in two dimensional array
        }   
        else
        {
            if(one_dim_arr[count_one_dim_arr] != ',')   // ignore character ',' when it appear
            {
                two_dim_arr[length_two_dim_arr][num_chr_two_dim_arr] = one_dim_arr[count_one_dim_arr];  // assign each character of one dimensional array in two dimensional array   
                num_chr_two_dim_arr++;                                                                  // increase position of character in word
            }
        }

        count_one_dim_arr++;                            // increase value position of one dimensional array
    }

    *length_arr = length_two_dim_arr;                   

    for(int count = 0; count < length_two_dim_arr; count++)
    {
        printf("%s\n", two_dim_arr[count]);
    }
}

/*
    This funcion is used to show frequent apprearance of word in one dimensional array
*/ 
void show_freq_appearance_word(char arr[][10], int length_arr)
{          
    /*
        create one array to marking position of word in one dimensional array
        action : save all value of array is equal 1
                 if it is 1, this word has not been checked
                 else if is 0, this word has been checked
    */ 
    int check_word[length_arr];

    for(int count = 0; count < length_arr; count++)
    {
        check_word[count] = 1;
    }

    /*
        check and show frequent apprearance of word
        action : compare each word with all the words that come after it
                 start by count_1 and all the words that come after it will be start from count_2
    */ 
    int freq_appear = 1;
    
    for(int count_1 = 0; count_1 < length_arr - 1; count_1++)                   
    {
        for(int count_2 = count_1 + 1; count_2 < length_arr; count_2++)
        {             
            if(check_word[count_1] == 1 && check_word[count_2] == 1)            // word is checked or not?
            {
                int value_comp = comp_arr(arr[count_1],arr[count_2]);           // compare between two word
                if(value_comp == 1)             
                {
                    freq_appear++;                                              // increase frequent appearance of word
                    check_word[count_2] = 0;                                    // marking word check 
                }
            }
        }

        /*
            show frequent appearance of word in array
        */ 
        if(freq_appear > 1)
        {
            printf("Freq appearance of word %s : %d times\n", arr[count_1], freq_appear);
            freq_appear = 1;
        }
    }
}

/*MAIN CODE -----------------------------------------------------------*/
int main()
{
    int length_conv_arr;

    conv_to_new_arr(test_arr,conv_two_dim_arr, &length_conv_arr); 

    show_freq_appearance_word(conv_two_dim_arr, length_conv_arr);

   return 0;

}


