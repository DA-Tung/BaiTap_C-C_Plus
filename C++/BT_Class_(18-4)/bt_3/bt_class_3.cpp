/*
    Bài 3 :
    Tạo một lớp hình tròn với bán kính và các phương thức để tính chu vi
    và diện tích của hình tròn.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

// Create marco to save value of number PI
#define PI 3.14

/*
    Create a class for Circle and maths
*/
class Circle{
    private :
        double radius;                      // Create radius of Circle

        double Perimeter_Circle = 0;        // Create a variable to save value of perimeter Circle
        double Area_Circle = 0;             // Create a variable to save value of area Circle

    public :
        Circle(double radius = 0);                              // Create a contructor import value radius of Circle
        double Get_Value_Radius() { return Circle::radius; }    // Get value of radius

        void Calc_Circle();                                     // Funcion calculation inform of Circle
};

/*
    Import value radius of Circle
*/
Circle::Circle(double radius)
{
    Circle::radius = radius;
}

/*
    Calculation value which relate to Circle
*/
void Circle::Calc_Circle()
{
    // Calculation perimeter of Circle
    Circle::Perimeter_Circle = 2*PI*radius;
    printf("Perimeter Circle : %lf\n", Circle::Perimeter_Circle);

    // Calculation area of Circle
    Circle::Area_Circle = PI*pow(radius,2);
    printf("Area Circle : %lf\n", Circle::Area_Circle);
}

/*
    Funcion main
*/
int main()
{
    Circle cir1(1);
    cir1.Calc_Circle();

    Circle cir2(2.5);
    cir2.Calc_Circle();

    return 0;
}

