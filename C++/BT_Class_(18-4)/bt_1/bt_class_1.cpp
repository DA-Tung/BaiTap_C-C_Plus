/*
    Bài 1 : 
    Tạo một lớp điểm trong hệ tọa độ 2D và viết các phương thức để tính
    khoảng cách giữa hai điểm, tính diện tích của tam giác được tạo bởi ba
    điểm
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

/*
    Create a class to save value X-axis and Y-axis
*/
class Point_XY{
    private :
        int X_Point;
        int Y_Point;

    public :
        Point_XY(int X_Point = 0, int Y_Point = 0);         // Create 1 contructor            
        int get_X_Point() { return Point_XY::X_Point; }     // Get value of X-axis
        int get_Y_Point() { return Point_XY::Y_Point; }     // Get value of Y-axis
};

/*
    Import new value of X-axis and Y-axis 
*/
Point_XY::Point_XY(int X_Point, int Y_Point)                
{
    Point_XY::X_Point = X_Point;
    Point_XY::Y_Point = Y_Point;
}

/*
    Create a class to calculation maths in coordinates Oxy
*/
class Math_Calculation{
    private :
        Point_XY Point_1;                       // Create three point in coordinates Oxy                                 
        Point_XY Point_2;                       // *                                          
        Point_XY Point_3;                       // *                                          

        double Distance_TwoPoint = 0;           // Create a variable to save distance two points
        double Area_Triangle = 0;               // Create a variable to save area of triangle
    
    public :
        /*
            Use polymorphism to calculation maths
        */
        Math_Calculation(Point_XY Point_1, Point_XY Point_2);                       // Inilatize a contructor to import value of two points                      
        Math_Calculation(Point_XY Point_1, Point_XY Point_2, Point_XY Point_3);     // Inilatize a contructor to import value of three points

        double Calculation_distance();                                              // Funcion to calculation distance
        double Calculation_area();                                                  // Funcion to calculation area
};

/*
    Import coordinate for two points
*/
Math_Calculation::Math_Calculation(Point_XY Point_1, Point_XY Point_2)
{
    Math_Calculation::Point_1 = Point_1;
    Math_Calculation::Point_2 = Point_2;
}

/*
    Import coordinate for three points
*/
Math_Calculation::Math_Calculation(Point_XY Point_1, Point_XY Point_2, Point_XY Point_3)
{
    Math_Calculation::Point_1 = Point_1;
    Math_Calculation::Point_2 = Point_2;
    Math_Calculation::Point_3 = Point_3;
}

/*
    Calculation distance for two points
*/
double Math_Calculation::Calculation_distance()
{
    Math_Calculation::Distance_TwoPoint = sqrt(pow((Point_1.get_X_Point() - Point_2.get_X_Point()),2) + pow((Point_1.get_Y_Point() - Point_2.get_Y_Point()),2));

    return Math_Calculation::Distance_TwoPoint;
}

/*
    Check and calculation area for three points
*/
double Math_Calculation::Calculation_area()
{
    double Point_12 = sqrt(pow((Point_1.get_X_Point() - Point_2.get_X_Point()),2) + pow((Point_1.get_Y_Point() - Point_2.get_Y_Point()),2));

    double Point_23 = sqrt(pow((Point_3.get_X_Point() - Point_2.get_X_Point()),2) + pow((Point_3.get_Y_Point() - Point_2.get_Y_Point()),2));

    double Point_31 = sqrt(pow((Point_1.get_X_Point() - Point_3.get_X_Point()),2) + pow((Point_1.get_Y_Point() - Point_3.get_Y_Point()),2));      

    double half_perimeter = (Point_12 + Point_23 + Point_31)/2;
    
    Math_Calculation::Area_Triangle = sqrt(half_perimeter*(half_perimeter - Point_12)*(half_perimeter - Point_23)*(half_perimeter - Point_31));

    if(Math_Calculation::Area_Triangle == 0)        // Check three points is triangle or not
    {
        printf("Not a triangle\n");                 // return 0 if it is not triangle
        return 0;
    }
    else
    {
        return Math_Calculation::Area_Triangle;     // Return value area is calculated
    }
}

/*
    Funcion main
*/
int main()
{
    Point_XY first_point(0,0);              // Import coordinate first point
    Point_XY seconde_point(0,3);            // Import coordinate second point
    Point_XY third_point(4,0);              // Import coordinate third point

    Math_Calculation distance_point(first_point,seconde_point);
    printf("Distance : %lf\n", distance_point.Calculation_distance());
    
    Math_Calculation distance_point2(third_point,seconde_point);
    printf("Distance : %lf\n", distance_point2.Calculation_distance());
    
    Math_Calculation distance_point3(first_point,third_point);
    printf("Distance : %lf\n", distance_point3.Calculation_distance());

    Math_Calculation area_3Point(first_point,seconde_point,third_point);
    printf("Area : %lf\n", area_3Point.Calculation_area());

    return 0;
}

