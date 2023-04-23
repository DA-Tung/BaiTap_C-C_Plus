/*
    Bài 6 :
    Tạo một lớp phân số với các thuộc tính tử số và mẫu số và các phương
    thức để tính toán các phép tính toán cơ bản như cộng, trừ, nhân và
    chia.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

/*
    Create class Fraction
*/
class Fraction{
    private :
        int Numerator;
        int Denominator;

    public :
        Fraction(int Numerator = 0, int Denominator = 1);
        int Get_Numerator() { return Fraction::Numerator; }
        int Get_Denominator() { return Fraction::Denominator; }
};

/*
    Import value of Numerator and Denominator
*/
Fraction::Fraction(int Numerator, int Denominator)
{
    Fraction::Numerator = Numerator;
    Fraction::Denominator = Denominator;
}

/*
    Find Greatest common divisor of two numbers
*/
int Greatest_Common_Divisor(int number1, int number2)
{
    int num1 = abs(number1);                    // Get absolute value of number1
    int num2 = abs(number2);                    // Get absolute value of number2

    if(num1 == 0 || num2 == 0)                  // Check num1 or num2 are equal 0 or not
    {
        if(num1 + num2 == 0) return -1;         // return -1 if num1 + num2 = 0
                    
        else return (num1 + num2);              // return sum of (num1+num2) if num1 or num2 is equal 0
    }

    while(num1 != num2)                         /* When num1 and num2 is not equal 0. Compare value of num1 and num2. */ 
    {                                           
        if(num1 > num2)                         /* Find Greatest common divisor by use substract for two numbers      */
        {                                       
            num1 = num1 - num2;                 
        }
        else
        {
            num2 = num2 - num1;
        }
    }
    return num1;                                /* Return value is num1 or num2 if num1 = num2, because least common divisor of them are num1 or num2  */
}

/*
    Create class calclation fraction
*/
class Math_Calculation{
    private :
        Fraction first;                 // Create first fraction
        Fraction second;                // Create second fraction

    public :
        Math_Calculation(Fraction first, Fraction second);          // Create a contructor for class
        void Calc_Sum_Fraction();                                   // Funcion calculation sum of two fractions
        void Calc_Sub_Fraction();                                   // Funcion calculation subtract of two fractions
        void Calc_Multi_Fraction();                                 // Funcion calculation multiply of two fractions
        void Calc_Div_Fraction();                                   // Funcion calculation divide of two fractions
};

/*
    Import value of two fractions
*/
Math_Calculation::Math_Calculation(Fraction first, Fraction second)
{
    Math_Calculation::first = first;
    Math_Calculation::second = second;
}

/*
    Calculation sum of two fractions
*/
void Math_Calculation::Calc_Sum_Fraction()
{
    // Check Denominator is diffirent 0 or not
    if(first.Get_Denominator() == 0 || second.Get_Denominator() == 0)                                                           
    {
        printf("Can not Calculation\n");
    }
    else
    {   
        // Calculation Denominator of two fractions
        int New_Denominator = first.Get_Denominator()*second.Get_Denominator();    

        // Calculation Numerator of two fractions
        int New_Numerator = first.Get_Numerator()*second.Get_Denominator() + first.Get_Denominator()*second.Get_Numerator(); 

        // Find Greatest common divisor of New_Numerator and New_Denominator. After reduced fraction     
        int Common_number = Greatest_Common_Divisor(New_Denominator,New_Numerator);                                                   
        New_Numerator = New_Numerator/Common_number;
        New_Denominator = New_Denominator/Common_number;

        // Printf sum of two fractions
        printf("Sum of two fractions : %d/%d\n", New_Numerator,New_Denominator);
    }
}

/*
    Calculation subtract of two fractions
*/
void Math_Calculation::Calc_Sub_Fraction()
{
    // Check Denominator is diffirent 0 or not
    if(first.Get_Denominator() == 0 || second.Get_Denominator() == 0)                                                           
    {
        printf("Can not Calculation\n");
    }
    else
    {   
        // Calculation Denominator of two fractions
        int New_Denominator = first.Get_Denominator()*second.Get_Denominator();    

        // Calculation Numerator of two fractions
        int New_Numerator = first.Get_Numerator()*second.Get_Denominator() - first.Get_Denominator()*second.Get_Numerator(); 

        // Find Greatest common divisor of New_Numerator and New_Denominator. After reduced fraction     
        int Common_number = Greatest_Common_Divisor(New_Denominator,New_Numerator);                                                   
        New_Numerator = New_Numerator/Common_number;
        New_Denominator = New_Denominator/Common_number;

        // Printf subtract of two fractions
        printf("Subtract of two fractions : %d/%d\n", New_Numerator,New_Denominator);
    }
}

/*
    Calculation multiply of two fractions
*/
void Math_Calculation::Calc_Multi_Fraction()
{
    // Check Denominator is diffirent 0 or not
    if(first.Get_Denominator() == 0 || second.Get_Denominator() == 0)                                                           
    {
        printf("Can not Calculation\n");
    }
    // Check Numerator of first or sencond fraction is equal 0 or not
    else if(first.Get_Numerator() == 0 || second.Get_Numerator() == 0)
    {
        printf("Multiply of two fractions : 0\n");
    }
    else
    {   
        // Calculation Denominator of two fractions
        int New_Denominator = first.Get_Denominator()*second.Get_Denominator();    

        // Calculation Numerator of two fractions
        int New_Numerator = first.Get_Numerator()*second.Get_Numerator(); 

        // Find Greatest common divisor of New_Numerator and New_Denominator. After reduced fraction     
        int Common_number = Greatest_Common_Divisor(New_Denominator,New_Numerator);                                                   
        New_Numerator = New_Numerator/Common_number;
        New_Denominator = New_Denominator/Common_number;

        // Printf multiply of two fractions
        printf("Multiply of two fractions : %d/%d\n", New_Numerator,New_Denominator);
    }
}

/*
    Calculation divide of two fractions
*/
void Math_Calculation::Calc_Div_Fraction()
{
    // Check Denominator is diffirent 0 or not
    if(first.Get_Denominator() == 0 || second.Get_Denominator() == 0)                                                           
    {
        printf("Can not Calculation\n");
    }
    // Check Numerator of sencond fraction is equal 0 or not
    else if(second.Get_Numerator() == 0)
    {
        printf("Can not Calculation\n");
    }
    // Check Numerator of frist fraction is equal 0 or not
    else if(first.Get_Numerator() == 0)
    {
        printf("Divide of two fractions : 0\n");
    }
    else
    {   
        // Calculation Denominator of two fractions
        int New_Denominator = first.Get_Denominator()*second.Get_Numerator();    

        // Calculation Numerator of two fractions
        int New_Numerator = first.Get_Numerator()*second.Get_Denominator(); 

        // Find Greatest common divisor of New_Numerator and New_Denominator. After reduced fraction     
        int Common_number = Greatest_Common_Divisor(New_Denominator,New_Numerator);                                                   
        New_Numerator = New_Numerator/Common_number;
        New_Denominator = New_Denominator/Common_number;

        // Printf divide of two fractions
        printf("Divide of two fractions : %d/%d\n", New_Numerator,New_Denominator);
    }
}

/*
    Funcion Main
*/
int main()
{
    Fraction new_first(0,4);
    Fraction new_second(10,9);

    Math_Calculation new_calc(new_first,new_second);
    new_calc.Calc_Sum_Fraction();
    new_calc.Calc_Sub_Fraction();
    new_calc.Calc_Multi_Fraction();
    new_calc.Calc_Div_Fraction();

    return 0;
}

