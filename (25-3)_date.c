#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*INITIALIZE CONSTANT -------------------------------------------------*/ 

// Declare dates of week
const uint8_t *Date_Name[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

// Declare months of year
typedef enum
{
    JANUARY     = 1,
    FEBRUARY    = 2,
    MARCH       = 3,
    APRIL       = 4,
    MAY         = 5,
    JUNE        = 6,
    JULY        = 7,
    AUGUST      = 8,
    SEPTEMBER   = 9,
    OCTOBER     = 10,
    NOVEMBER    = 11,
    DECEMBER    = 12
}MONTH;

// Struct define timeline
typedef struct
{
    uint8_t Day;
    uint8_t Month;
    uint16_t Year;
}DAYMONTHYEAR;

/*INITIALIZE FUNCION --------------------------------------------------*/ 

uint8_t NUMDAYOFMONTH(MONTH DayofMonth);            // Check number days of Month
uint32_t CACULATION_DATE(DAYMONTHYEAR Date);        // Caculation total days
void SHOW_DATE(DAYMONTHYEAR Date);                  // Show dates

/*FUNCION CODE --------------------------------------------------------*/ 

// 
/*  This funcion is used to check number days of Month
    Month have 31 days : JANUARY, MARCH, MAY, JULY, AUGUST, OCTOBER, DECEMBER
    Month have 30 days : APRIL, JUNE, SEPTEMBER, NOVEMBER
    Month have 28 days : FEBRUARY
*/
uint8_t NUMDAYOFMONTH(MONTH DayofMonth)
{
    switch(DayofMonth)
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

/*  This Funcion is used to caculation total days of all months and years */

uint32_t CACULATION_DATE(DAYMONTHYEAR Date)
{
    uint32_t Total_Dates = 0;                                       // Total day
    uint8_t Check_LeapYear = 0;                                     // Check special Leap Year
    
    Total_Dates += 365*(Date.Year - 1);                             // Caculation number days of all year
    
    for(uint16_t year = 1; year < Date.Year; year++)                // Caculation Leap Year
    {
        if(year%4 == 0)
        {
            Total_Dates++;
        }
        
        if(year%100 == 0)
        {
            if(year%400 != 0)   Total_Dates--;
        }
    }  
    
    if(Date.Year%100 == 0)                                          // Special leap year                                        
    {
        if(Date.Year%400 == 0) Check_LeapYear = 1;
        else Check_LeapYear = 0;
    }
    else
    {
        if(Date.Year%4 == 0)    Check_LeapYear = 1;
        else Check_LeapYear = 0;
    }
    
    for(uint8_t month = 1; month < Date.Month; month++)             // Caculation number days of all month
    {
        Total_Dates += NumdayofMonth(month);
    }
    
    if(Date.Month > 2)
    {
        if(Check_LeapYear == 1) Total_Dates += 1;
    }
    
    Total_Dates += Date.Day;                                       // Caculation day
    
    return Total_Dates;
}

// Funcion show date
void SHOW_DATE(DAYMONTHYEAR Date)
{
    uint32_t Total_Dates = CACULATION_DATE(Date);
    
    uint32_t check_date = Total_Dates%7;
    
    printf("%s", Date_Name[check_date]);
}

/*MAIN CODE -----------------------------------------------------------*/

int main()
{
    DAYMONTHYEAR New_Date;
    
    New_Date.Day = 5;
    New_Date.Month = 5;
    New_Date.Year = 2022;
    
    SHOW_DATE(new_Date);

    return 0;
}


