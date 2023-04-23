/*
    Bài 4 : 
    Tạo một lớp động vật với các thuộc tính tên, tuổi và trọng lượng, và các
    phương thức để tính chỉ số BMI, so sánh tuổi và trọng lượng của các
    động vật khác nhau
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

/*
    Create a class for Animal
*/
class Animal{
    private :
        char Name[20];              // Create Name Animal
        int Age;                    // Create Age Animal
        double Height;              // Create Height Animal
        double Weight;              // Create Weight Animal

        double Index_BMI = 0;    

    public :
        Animal(char Name[] = "\0", int Age = 0, double Height = 0, double Weight = 0);      // Create a constructor to import inform for Animal

        char *Get_Name_Animal() { return Animal::Name; }                                    // Get name for animal
        int Get_Age_Animal() { return Animal::Age; }                                        // Get age for animal
        double Get_Height_Animal() { return Animal::Height; }                               // Get height for animal
        double Get_Weight_Animal() { return Animal::Weight; }                               // Get weight for animal

        double Calc_BMI();
};

/*
    Create constructor 
*/
Animal::Animal(char Name[], int Age, double Height, double Weight)
{
    strcpy(Animal::Name,Name);
    Animal::Age = Age;
    Animal::Height = Height;
    Animal::Weight = Weight;
}

/*
    Calculation value of BMI
*/
double Animal::Calc_BMI()
{
    Animal::Index_BMI = Weight/ (pow(Height,2));

    return Animal::Index_BMI;
}

/*
    Compare ages between two animals
*/
void Check_Age_Animal(Animal First_Animal, Animal Second_Animal)
{
    if(First_Animal.Get_Age_Animal() > Second_Animal.Get_Age_Animal())
    {
        printf("%s is older than %s\n",First_Animal.Get_Name_Animal(),Second_Animal.Get_Name_Animal());
    }
    else if(First_Animal.Get_Age_Animal() < Second_Animal.Get_Age_Animal())
    {
        printf("%s is younger than %s\n",First_Animal.Get_Name_Animal(),Second_Animal.Get_Name_Animal());
    }
    else
    {
        printf("%s is same age %s\n",First_Animal.Get_Name_Animal(),Second_Animal.Get_Name_Animal());
    }   
}

/*
    Compare weight between two animals
*/
void Check_Weight_Animal(Animal First_Animal, Animal Second_Animal)
{
    if(First_Animal.Get_Weight_Animal() > Second_Animal.Get_Weight_Animal())
    {
        printf("%s is heavier than %s\n",First_Animal.Get_Name_Animal(),Second_Animal.Get_Name_Animal());
    }
    else if(First_Animal.Get_Weight_Animal() < Second_Animal.Get_Weight_Animal())
    {
        printf("%s is lighter than %s\n",First_Animal.Get_Name_Animal(),Second_Animal.Get_Name_Animal());
    }
    else
    {
        printf("%s is same weight %s\n",First_Animal.Get_Name_Animal(),Second_Animal.Get_Name_Animal());
    }   
}

/*
    Compare height between two animals
*/
void Check_Height_Animal(Animal First_Animal, Animal Second_Animal)
{
    if(First_Animal.Get_Height_Animal() > Second_Animal.Get_Height_Animal())
    {
        printf("%s is taller than %s\n",First_Animal.Get_Name_Animal(),Second_Animal.Get_Name_Animal());
    }
    else if(First_Animal.Get_Height_Animal() < Second_Animal.Get_Height_Animal())
    {
        printf("%s is lower than %s\n",First_Animal.Get_Name_Animal(),Second_Animal.Get_Name_Animal());
    }
    else
    {
        printf("%s is same height %s\n",First_Animal.Get_Name_Animal(),Second_Animal.Get_Name_Animal());
    }   
}

/*
    Funcion main
*/
int main()
{
    Animal first("Elephant", 10, 3.5, 900);
    printf("Index BMI of %s : %lf\n", first.Get_Name_Animal(), first.Calc_BMI());

    Animal second("Tiger", 15, 1, 250);
    printf("Index BMI of %s : %lf\n", second.Get_Name_Animal(), second.Calc_BMI());

    Check_Age_Animal(first,second);
    Check_Height_Animal(first,second);
    Check_Weight_Animal(first,second);

    return 0;
}
