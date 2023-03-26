/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// 
uint8_t *Date_Name[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

//
typedef enum
{
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAY = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVEMBER = 11,
    DECEMBER = 12
}MONTH;

//
typedef struct
{
    uint8_t Day;
    uint8_t Month;
    uint16_t Year;
}DayMonthYear;

// Funcion check month
uint8_t NumdayofMonth(MONTH month)
{
    switch(month)
    {
        case JANUARY :
        case MARCH :
        case MAY :
        case JULY :
        case AUGUST :
        case OCTOBER :
        case DECEMBER :
            return 31;
            break;
            
        case APRIL :
        case JUNE :
        case SEPTEMBER :
        case NOVEMBER :
            return 30;
            break;
            
        case FEBRUARY :
            return 28;
            break;
            
        default :
            printf("Invalid");
            break;
    }
}

// Funcion caculation number days
uint32_t Caculation_Date(DayMonthYear Date)
{
    uint32_t sum_dates = 0;
    uint8_t check_year = 0;
    
    // Caculation number days of all year
    sum_dates += 365*(Date.Year - 1);
    
    // Caculation leap Year
    for(uint16_t year = 1; year < Date.Year; year++)
    {
        if(year%4 == 0)
        {
            sum_dates++;
        }
        
        if(year%100 == 0)
        {
            if(year%400 != 0)   sum_dates--;
        }
    }  
    
    if(Date.Year%100 == 0)
    {
        if(Date.Year%400 == 0) check_year = 1;
        else check_year = 0;
    }
    
    // Caculation number days of all month
    for(uint8_t month = 1; month < Date.Month; month++)
    {
        sum_dates += NumdayofMonth(month);
    }
    
    if(Date.Month > 2)
    {
        if(check_year == 1) sum_dates += 1;
    }
    
    // Caculation day
    sum_dates += Date.Day;
    
    return sum_dates;
}

// Funcion show date
void Show_Date(DayMonthYear Date)
{
    uint32_t sum_dates = Caculation_Date(Date);
    
    uint32_t check_date = sum_dates%7;
    
    printf("%s", Date_Name[check_date]);
}

// Main
int main()
{
    DayMonthYear new_Date;
    
    new_Date.Day = 5;
    new_Date.Month = 5;
    new_Date.Year = 2022;
    
    Show_Date(new_Date);

    return 0;
}

