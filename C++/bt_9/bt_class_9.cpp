/*
    Bài 9 :
    . Tạo một lớp xe hơi với các thuộc tính màu sắc, kiểu động cơ và số km
    đã đi, và các phương thức để tính toán chi phí bảo trì, kiểm tra số km
    đã đi và in thông tin về xe
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

/*
    Class Car
*/
class Car{
    private :
        char Color[20];                     // Color of car
        char Motor[20];                     // Motor of car
        uint32_t Distance_km;               // the number of kilometers traveled

        // typedef enum {
        //     level_0 = 0,
        //     level_1,
        //     level_2,
        //     level_3,
        //     level_4,
        // } Maintenance;

        // Maintenance maintenance;

    public :
        Car(char Color[] = "\0", char Motor[] = "\0", uint32_t Distance_km = 0);
        char *Get_Color_Car() { return Car::Color; }
        char *Get_Motor_Car() { return Car::Motor; }
        uint16_t Get_Distance_Car() { return Car::Distance_km; }

        void Calc_ChargeMaintenance();
        void ShowInform_Car();
};

/*
    Import inform of Car
*/
Car::Car(char Color[], char Motor[], uint32_t Distance_km)
{
    strcpy(Car::Color, Color);
    strcpy(Car::Motor, Motor);
    Car::Distance_km = Distance_km;
}

/*
    Calculation charge maintenance of car with the number of kilometers traveled
*/
void Car::Calc_ChargeMaintenance()
{
    uint32_t distance_car = Get_Distance_Car();

    if(distance_car < 5000)
    {
        printf("Level of Charge maintenance : 0\n");
        printf("Charge maintenance of car : 1,000,000 VND\n");
    }
    else if(distance_car > 5000 && distance_car < 15000)
    {
        printf("Level of Charge maintenance : 1\n");
        printf("Charge maintenance of car : 1,500,000 VND\n");
    }
    else if(distance_car > 15000 && distance_car < 30000)
    {
        printf("Level of Charge maintenance : 2\n");
        printf("Charge maintenance of car : 3,000,000 VND\n");
    }
    else if(distance_car > 30000 && distance_car < 40000)
    {
        printf("Level of Charge maintenance : 3\n");
        printf("Charge maintenance of car : 5,000,000 VND\n");
    }  
    else if(distance_car > 40000 && distance_car < 100000)
    {
        printf("Level of Charge maintenance : 4\n");
        printf("Charge maintenance of car : 10,000,000 VND\n");
    } 
    else if(distance_car > 100000)
    {
        printf("Level of Charge maintenance : 5\n");
        printf("Charge maintenance of car : 20,000,000 VND\n");
    }   
}

/*
    Get inform of Car
*/
void Car::ShowInform_Car()
{
    printf("Color of Car : %s\n", Get_Color_Car());
    printf("Motr of Car : %s\n", Get_Motor_Car());
    printf("The number of kilometers traveled : %d\n", Get_Distance_Car());
}

int main()
{
    Car first_car("Red","Electric", 12000);
    first_car.ShowInform_Car();
    first_car.Calc_ChargeMaintenance();

    printf("\n");

    Car second_car("Blue","Diesel", 35000);
    second_car.ShowInform_Car();
    second_car.Calc_ChargeMaintenance();

    return 0;
}

