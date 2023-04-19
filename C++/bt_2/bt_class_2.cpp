/*
    Bài 2 :
    Tạo một lớp hình chữ nhật với các thuộc tính chiều dài, chiều rộng và
    các phương thức để tính chu vi, diện tích, đường chéo và kiểm tra xem
    nó có phải là hình vuông hay không.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

/*
    Create a class to calculation perimeter and area of Rectangle
*/
class Rectangle{
    private :   
        double width;                           // Create width of Rectangle
        double length;                          // Create length of Rectangle

        double perimeter_rectangle = 0;         // Create a variable to save value of perimeter Rectangle
        double area_rectangle = 0;              // Create a variable to save value of area Rectangle
        double diagonal_line = 0;               // Create a variable to save diagonal line of Rectangle

    public :
        Rectangle(double width = 0, double length = 0);             // Create a contructor import value width and length of Rectangle
        //double get_value_width() { return Rectangle::width; }
        //double get_value_lenghth() { return Rectangle::length; }

        double Calc_Area_Rec();                                     // Funcion to calculation area of Rectangle
        double Calc_Perimeter_Rec();                                // Funcion to calculation perimeter of Rectangle
        double Calc_Diagonal_Line();                                // Funcion to calculation diagonal line of Rectangle
        void Check_Square();                                        // Funcion to check Rectangle is square or not
};

/*
    Import value for width and length
*/
Rectangle::Rectangle(double width, double length)
{
    Rectangle::width = width;
    Rectangle::length = length;
}

/*
    Calculation area rectangle
*/
double Rectangle::Calc_Area_Rec()
{
    Rectangle::area_rectangle = width*length;

    return Rectangle::area_rectangle;
}

/*
    Calculation perimeter rectangle
*/
double Rectangle::Calc_Perimeter_Rec()
{
    Rectangle::perimeter_rectangle = (width + length)*2;

    return Rectangle::perimeter_rectangle;
}

/*
    Calculation diagonal line
*/ 
double Rectangle::Calc_Diagonal_Line()
{
    Rectangle::diagonal_line = sqrt(pow(width,2) + pow(length,2));

    return Rectangle::diagonal_line;
}

/*
    Check Rectangle is square or not
*/ 
void Rectangle::Check_Square()
{
    if(width == length)
    {
        printf("IT IS SQUARE\n");
    }
    else
    {
        printf("IT IS NOT SQUARE\n");
    }
}

/*
    Funcion main
*/
int main()
{
    /*
        Import and calculation inform of Rectangle
    */
    Rectangle rec1(1,2);
    printf("Area : %lf\n", rec1.Calc_Area_Rec());
    printf("Perimeter : %lf\n", rec1.Calc_Perimeter_Rec());
    printf("Diangonal line : %lf\n", rec1.Calc_Diagonal_Line());
    rec1.Check_Square();

    /*
        Import and calculation inform of Rectangle
    */
    Rectangle rec2(1.1,2.9);
    printf("Area : %lf\n", rec2.Calc_Area_Rec());
    printf("Perimeter : %lf\n", rec2.Calc_Perimeter_Rec());
    printf("Diangonal line : %lf\n", rec2.Calc_Diagonal_Line());
    rec2.Check_Square();    

    /*
        Import and calculation inform of Rectangle
    */
    Rectangle rec3(3,3);
    printf("Area : %lf\n", rec3.Calc_Area_Rec());
    printf("Perimeter : %lf\n", rec3.Calc_Perimeter_Rec());
    printf("Diangonal line : %lf\n", rec3.Calc_Diagonal_Line());
    rec3.Check_Square();

    return 0;
}

