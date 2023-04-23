/*
    Bài 5 :
    Tạo một lớp người với các thuộc tính tên, tuổi và địa chỉ, và các
    phương thức để in thông tin của người đó và tính tuổi của người đó.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

/*
    Class inform of People
*/
class Inform_People{
    private :
        char Name[20];                  // Create Name
        uint8_t Age;                    // Create Age
        char Address[20];               // Create Address

    public :
        Inform_People(char Name[] = "\0", uint8_t Age = 0, char Address[] = "\0");  // Create a contructor to import inform of people

        char *Get_Name_People() { return Inform_People::Name; }                     // Get name of people
        uint8_t Get_Age_People() { return Inform_People::Age; }                     // Get age of people
        char *Get_Address_People() { return Inform_People::Address; };              // Get address of people

        void Show_inform();                                                         // Show inform of people
        uint8_t Calc_Ages(uint8_t Birth_Year, uint8_t Current_Year);                // Calculation age of people
};

/*
    Import inform of people
*/
Inform_People::Inform_People(char Name[], uint8_t Age, char Address[])
{
    strcpy(Inform_People::Name,Name);
    Inform_People::Age = Age;
    strcpy(Inform_People::Address,Address);
}

/*
    Show inform of people
*/
void Inform_People::Show_inform()
{
    printf("Name : %s\n", Inform_People::Name);
    printf("Age : %d\n", Inform_People::Age);
    printf("Address : %s\n", Inform_People::Address);
}

/*
    Calculation of people
*/
uint8_t Inform_People::Calc_Ages(uint8_t Birth_Year, uint8_t Current_Year)
{
    return (Current_Year - Birth_Year);
}

/*
    Funcion Main
*/
int main()
{
    Inform_People people1("Nguyen A",20,"Ha Noi");
    people1.Show_inform();

    Inform_People people2("Tran B", 19, "Hai Phong");
    people2.Show_inform();

    return 0;
}

