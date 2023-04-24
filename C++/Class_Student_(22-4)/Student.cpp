#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

/*
    Create enum Rank
*/ 
typedef enum{
    EXCELLENT,
    VERY_GOOD,
    GOOD,
    AVERAGE,
    WEAK
}RANK;

/*
    Create enum Sex
*/
// typedef enum{
//     MALE = 0,
//     FEMALE
// }SEX;

/*
    Create class Student
*/
class Student{
    private :
        uint8_t ID;
        char Name[20];
        uint8_t Age;
        char Sex[10];
        float Math_Score;
        float Physics_Score;
        float Chemistry_Score;
        float Medium_Score;
        string Rank;

    public :
        Student(char Name[] = "\0", char Sex[] = "\0",  uint8_t Age = 0, float Math_Score = 0, float Physics_Score = 0, float Chemistry_Score = 0);

        // Set and get Name
        void SetName(char Name[]) { strcpy(this->Name, Name); }
        char *GetName()           { return this->Name;        }

        // Set and get Sex
        void SetSex(char Sex[])   { strcpy(this->Sex, Sex); }
        char *GetSex()            { return this->Sex;       }

        // Set and get Age
        void SetAge(uint8_t Age)  { this->Age = Age;  }
        uint8_t GetAge()          { return this->Age; }
        
        // Get ID
        uint8_t GetID()           { return this->ID; }

        // Set and get Math score
        void SetMathScore(float math)              { this->Math_Score = math; }
        float GetMathScore()                       { return this->Math_Score; }              
        
        // Set and get Physic score
        void SetPhysicsScore(float physic)         { this->Physics_Score = physic; }
        float GetPhysicsScore()                    { return this->Physics_Score;   }
        
        // Set and get Chemistry score
        void SetChemistryScore(float chemistry)    { this->Chemistry_Score = chemistry; }
        float GetChemistryScore()                  { return this->Chemistry_Score;      }
        
        // Set and get medium score
        void SetMdeiumScore()                      { this->Medium_Score = (GetMathScore() + GetPhysicsScore() + GetChemistryScore())/3; }
        float GetMediumScore()                     { return this->Medium_Score;                                                         }

        // Rank of student
        string GetRank();
}; 

/*
    Funcion : Get inform of student
*/
Student::Student(char Name[],char Sex[], uint8_t Age, float Math_Score, float Physics_Score, float Chemistry_Score)
{
    static uint8_t id = 100;
    this->ID = id;
    id++;

    strcpy(this->Sex, Sex);
    strcpy(this->Name, Name);
    this->Age = Age;
    this->Math_Score = Math_Score;
    this->Physics_Score = Physics_Score;
    this->Chemistry_Score = Chemistry_Score;

    this->SetMdeiumScore();
    this->GetRank();
}

/*
    Funcion : Get rank of student compare with medium score
*/
string Student::GetRank()
{
    float Score = GetMediumScore();
    if(Score >= 9.5)
    {
         this->Rank = "EXCELLENT";
    }
    else if (Score < 9.5 && Score >= 8)
    {
        this->Rank = "VERY GOOD";
    }
    else if (Score < 8 && Score >= 6.5)
    {
        this->Rank = "GOOD";
    }
    else if (Score < 6.5 && Score >= 5)
    {
        this->Rank = "AVERAGE";
    }   
    else
    {
        this->Rank = "WEAK";
    }

    return this->Rank;
}

/*
    A class Menu to create a request with many funcion
*/
class Menu{
    private :
        vector<Student> database;

    public : 
        Menu();
        void Run_program();
        void Add_Student();
        void Update_Student();
        void Delete_Sudent();
        void Find_Student();
        void Sort_ScoreStudent();
        void Sort_NameStudent();
        void Show_listStudent();
};

/*
*/
Menu::Menu()
{

}

/*
    Menu select all funcion of program
*/
void Menu::Run_program()
{
    int select = 0;

    printf("\n");
    printf("* This is a student management program\n");
    printf("------------------------------------\n");

    // Implement all funcion of program
    printf("[0] Exit program\n");
    printf("[1] Add student\n");
    printf("[2] Update student\n");
    printf("[3] Delete student\n");
    printf("[4] Find student\n"); 
    printf("[5] Sort score by student\n");
    printf("[6] Sort name by student\n");
    printf("[7] Show list student\n");      
    printf("------------------------------------\n"); 
    do
    {
        /* 
            all funcion of program 
        */    
        scanf(" %d", &select);
        printf("Select funcion [%d] : ", select); 
        /*
            select funcion
        */
        switch (select)
        {
        case 1 :
            printf("Add student\n");
            Add_Student();
            break;

        case 2 :
            printf("Update student\n");
            Update_Student();
            break;            

        case 3 :
            printf("Delete student\n");
            Delete_Sudent();
            break; 

        case 4 :
            printf("Find student\n");
            Add_Student();
            break;

        case 5 :
            printf("Sort score by student\n");
            Sort_ScoreStudent();
            break;            

        case 6 :
            printf("Sort name by student\n");
            Sort_NameStudent();
            break; 

        case 7 :
            printf("Show list student\n");
            Show_listStudent();
             break; 

        default:
            printf("Exit program\n");
            break;
        }
    } while (select); 
}

/*
    Funcion : add new student
*/
void Menu::Add_Student()
{
    char name[20];
    uint8_t age;
    char sex[20];
    float math;
    float physic;
    float chemistry;

    printf("\n");
    //printf("------------------------------------\n");
    printf("- Add new inform student\n");

    // Import age of student    
    printf("+ Enter your age : ");
    scanf("%u", &age);

    // Import name of student
    printf("+ Enter your name : ");
    scanf(" %[^\n]s", &name);

    // Import sex of student
    printf("+ Enter your sex : ");
    scanf("%s", &sex);
    
    // Import math score of student  
    printf("+ Enter your math score : ");
    scanf("%f", &math);

    // Import physic score of student  
    printf("+ Enter your physic score : ");
    scanf("%f", &physic);

    // Import chemistry score of student  
    printf("+ Enter your chemistry score : ");
    scanf("%f", &chemistry);    

    // Create inform for new student
    Student New_student(name,sex,age,math,physic,chemistry);

    // Add new student in database
    database.push_back(New_student);

    printf("- Select [1] to continue add new student\n");
}

/*
    Funcion update inform student by ID
*/
void Menu::Update_Student()
{
    char name[20];
    uint8_t age;
    char sex[20];
    float math;
    float physic;
    float chemistry;
    uint8_t id_student;
    int select = 0;
    bool check_ID = false;

    printf("\n");
    /* Import ID student need to change */
    printf("------------------------------------\n");
    printf("- Import ID Student need update : "); 
    scanf("%u",&id_student);
    printf("\n");

    /* Find ID student in list */
    for(int num_ID = 0; num_ID < database.size(); num_ID++)
    {
        // Check ID student is exist or not
        if((database.at(num_ID)).GetID() == id_student)
        {
            // ID number is exist
            check_ID = true;
            // Inform for update
            printf("Update new inform for student\n");
            printf("[0] End update\n");
            printf("[1] Update new name\n");
            printf("[2] Update new age\n");
            printf("[3] Update new sex\n");
            printf("[4] Update new math score\n"); 
            printf("[5] Update new physic score\n");
            printf("[6] Update new chemistry score\n");    
            printf("\n");
            do
            {
                // selcect inform need to update
                scanf("%d", &select);
                printf("+ Update inform : [%d] ", select);

                // Selet inform to change
                switch (select)
                {
                // Change name
                case 1 :
                    printf("Update new name\n");
                    scanf(" %s", &name);
                    //printf("\n");
                    database.at(num_ID).SetName(name);
                    break;

                // Change age
                case 2 :
                    printf("Update new age\n");
                    scanf(" %d", &age);
                    //printf("\n");
                    database.at(num_ID).SetAge(age);
                    break;            

                // Change sex
                case 3 :
                    printf("Update new sex\n");
                    scanf(" %s", &sex);
                    //printf("\n");
                    database.at(num_ID).SetSex(sex);
                    break; 

                // Change math score
                case 4 :
                    printf("Update new math score\n");
                    scanf(" %f", &math);
                    //printf("\n");
                    database.at(num_ID).SetMathScore(math);
                    break;

                // Change physic score
                case 5 :
                    printf("Update new physic score\n");
                    scanf(" %f", &physic);
                    //printf("\n");
                    database.at(num_ID).SetPhysicsScore(physic);
                    break;            

                // Change chemistry score
                case 6 :
                    printf("Update new chemistry score\n");
                    scanf(" %f", &chemistry);
                    //printf("\n");
                    database.at(num_ID).SetChemistryScore(chemistry);
                    break; 
            
                // break            
                default:
                    printf("End update\n");
                    break;
                } 
            } while(select); 
        }
        // if ID number is exist, after change inform of student, we will break loop for because there is only ID number
        if(check_ID == true)
        {
            // Assign num_ID to illegal value of condition loop for
            num_ID = database.size();
        }
    }

    if(check_ID == false)
    {
        // ID is not exist
        {
            printf("+ ID number [%d] is not exist, you can't change inform of student\n", id_student);
        }
    }

    printf("- Select [2] to continue update inform student\n");
}

/*
    Delete student by ID
*/
void Menu::Delete_Sudent()
{
    uint8_t id_student;
    bool check_ID = false;

    printf("\n");
    printf("------------------------------------\n");
    /* Import ID student need to delete */
    printf("- Import ID Student need delete : "); 
    scanf("%d",&id_student);
    printf("\n");

    /* Find ID student in list */
    for(int num_ID = 0; num_ID < database.size(); num_ID++)
    {
        // Check ID student is exist or not
        if((database.at(num_ID)).GetID() == id_student)
        {
            // ID number is exist
            check_ID = true;

            // Delete inform of student by ID number
            database.erase(database.begin()+num_ID);

            // Because there is only a ID number, therefore we need to exit loop for after find ID number in list
            // Assign num_ID to illegal value of condition loop for
            num_ID = database.size();
        }
    }

    // ID number is not exist
    if(check_ID == false)
    {
        printf("+ ID number [%d] is NOT exist, you can't delete inform of student\n", id_student);
    }
    else if(check_ID == true)
    {
        
        printf("+ ID number [%d] is deleted in the list\n", id_student);
    }

    // If you want to delete student, select number [3]
    printf("- Select [3] to continue delete student\n");
}

/*
    find student by name
*/
void Menu::Find_Student()
{
    char name[20];
    bool check_name = false;

    printf("\n");
    printf("------------------------------------\n");
    /* Import name student need to find */
    printf("- Import name Student need to find : "); 
    scanf("%s",&name);
    printf("\n");

    // Find name of student in list
    for(int num_name = 0; num_name < database.size(); num_name++)
    {
        if(strcmp((database.at(num_name)).GetName(), name) == 0)
        {
            printf("+ Student's name is [%s] exist in list\n",name);
            // Assign true to verify name of student is exist
            check_name = true;
        }
    }

    // Printf inform if name of student is not exist in list
    if(check_name == false)
    {
        printf("+ Name Student is [%s] NOT exist in list\n",name);       
    }

    // If you want to find other student's name, select number [4]
    printf("- Select [4] to continue to find other student's name\n");
}

/*
    Show all inform of student in the list
*/
void Menu::Show_listStudent()
{
    char name[20];
    uint8_t id;
    uint8_t age;
    char sex[10];
    float math;
    float physic;
    float chemistry;
    float medium_score;
    string rank;   
    int count = 1;
    printf("\n");
    printf("------------------------------------\n");
    printf("- List students in system\n");
    // Print inform of all student in the list
    for(Student student : database)
    {
        // Copy inform of each student
        strcpy(name, student.GetName());
        id = student.GetID();
        strcpy(sex, student.GetSex());
        age = student.GetAge();
        math = student.GetMathScore();
        physic = student.GetPhysicsScore();
        chemistry = student.GetChemistryScore();
        medium_score = student.GetMediumScore();
        //strcpy(student.GetRank(), rank);
        rank = student.GetRank();

        // Print inform of each student
        printf("+ Student number [%d] : \n",count);
        printf("\tID : %d |\tName : %s |\tSex : %s |\tAge : %d |\tRank : %s\n", id,name,sex,age,rank.c_str());
        printf("\tMath score : %.2f |\tPhysic score : %.2f |\tChemistry score : %.2f |\tMedium score : %.2f",math,physic,chemistry,medium_score);
        printf("\n");
        count++;
    }
}

/*
    Funcion : Swap between two students
*/
void Swap_Student(Student *student1, Student *student2)
{
    Student student = *student1;
    *student1 = *student2;
    *student2 = student;
}

/*
    Funcion compare two string
*/
int cmp_str(char *str1, char *str2)
{
    int count = 0;
    do
    {
        if(str1[count] > str2[count])
        {
            return 1;
        }
        else if(str1[count] < str2[count])
        {
            return -1;
        }
        count++;
    }while(str1[count] != '\0' || str2[count] != '\0');

    return 0;
}

/*
    Sort by student's name in the list
*/
void Menu::Sort_NameStudent()
{
    int value_cmp;
    // Number of students have in the list
    int num_students = database.size(); 

    if(num_students == 0)
    {
        printf("- There is no student in the list\n");
    }
    else
    {
        for(int index1 = 0; index1 < num_students - 1; index1++)
        {
            for(int index2 = index1 + 1; index2 < num_students; index2++)
            {
                value_cmp = cmp_str((database.at(index1)).GetName(),(database.at(index2)).GetName());
                if(value_cmp == -1)
                {
                    swap(database[index1], database[index2]);
                }
            }
        }
        printf("- List of students which sorting by name\n");
    }    
}

/*
    Sort by score of student in the list
*/
void Menu::Sort_ScoreStudent()
{
    // Number of students have in the list
    int num_students = database.size();  

    if(num_students == 0)
    {
        printf("- There is no student in the list\n");
    }
    else
    {
        for(int index1 = 0; index1 < num_students - 1; index1++)
        {
            for(int index2 = index1 + 1; index2 < num_students; index2++)
            {
                if((database.at(index1)).GetMediumScore() > (database.at(index2)).GetMediumScore())
                {
                    swap(database[index1], database[index2]);
                }
            }
        }
        printf("- List of students which sorting by score\n");
    }
}

/*
    Funcion main
*/
int main()
{
    // Student student1("Nguyen Van A","NAM",19,9.2,7.1,7.5);
    // Student student2("Nguyen Thi B","NU",20,8.2,8.1,9.5);
    // Student student3("Tran Van C","NAM",20,5.2,6.1,4.5);
    // Student student4("Lai Thi D","NU",18,7.2,8.1,7.7);

    Menu list_student;

    list_student.Run_program();
    
    return 0;
}


