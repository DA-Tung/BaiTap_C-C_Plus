#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

class Date{
    private :
        uint16_t Day;
        uint16_t Month;
        uint16_t Years;
    
    public :
        Date(uint16_t Day = 0,uint16_t Month = 0,uint16_t Years = 0);

        uint16_t Get_Day() { return Date::Day; }
        uint16_t Get_Month() { return Date::Month; }
        uint16_t Get_Years() { return Date::Years; }

        void Calc_Age(uint16_t Cur_Year);
        void Check_Holiday(uint16_t Check_Day,uint16_t check_Month);
};

Date::Date(uint16_t Day,uint16_t Month,uint16_t Years)
{
    Date::Day = Day;
    Date::Month = Month;
    Date::Years = Years;
}

void Date::Check_Holiday(uint16_t Check_Day,uint16_t check_Month)
{
    if(Check_Day == 1 && check_Month == 1)
    {
        printf("It is holiday. It is New Day of Year\n");
    }
    else if(Check_Day == 30 && check_Month == 4)
    {
        printf("It is holiday. It is Victory Day\n");
    }
    else if(Check_Day == 1 && check_Month == 5)
    {
        printf("It is holiday. It is International Labor\n");
    }    
    else if(Check_Day == 1 && check_Month == 5)
    {
        printf("It is holiday. It is Country Establishment\n");
    }   
    else
    {
        printf("It is not holiday\n");
    }   
}

void Date::Calc_Age(uint16_t Cur_Year)
{
    uint16_t age = 0;

    age = Cur_Year - Get_Years();

    printf("Age is : %d\n",age);
}

int main()
{
    Date new_date(3,4,2000);

    new_date.Check_Holiday(1,1);

    new_date.Calc_Age(2023);

    return 0;
}

