#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

/*
    Class Foods-------------------------------------------------------
*/
class Food{
    private : 
        uint8_t id_Food;
        char NameFood[20];
        uint32_t PriceFood;
    public :
        Food(char NameFood[] = "\0", uint32_t PriceFood = 0);
        void SetNameFood(char NameFood[])     { strcpy(this->NameFood,NameFood); }
        char *GetNameFood()                   { return this->NameFood;           }
        
        void SetPriceFood(uint32_t PriceFood) { this->PriceFood = PriceFood; }
        uint32_t GetPriceFood()               { return this->PriceFood;      }

        uint8_t GetIDFood()                   { return this->id_Food; }
};

/*  Funcion : Get inform Foods  */
Food::Food(char NameFood[], uint32_t PriceFood)
{
    static uint8_t id = 100;
    this->id_Food = id;
    id++;

    strcpy(this->NameFood, NameFood);
    this->PriceFood = PriceFood;
}

/*
    Class Manager-------------------------------------------------------
*/

/*  Table   */
typedef struct{
    uint8_t PositionTable;
    bool StatusTable;
}Table;

/*  Class Manager   */
class Manager{
    private :
        vector<Food> DatabaseFood;
        vector<Table> DatabaseTable;

    public :
        Manager();
        void RunProgramManager();

        void AddFood();
        void FixFood();
        void DeleteFood();
        void FindFood();
        void ListFoods();

        void SetQtyTable();
        uint8_t GetQtyTable();

        vector<Food> GetListFood();
};

/*  Manager */
Manager::Manager()
{

}

/*  Get list Food*/
vector<Food> Manager::GetListFood()
{
    return Manager::DatabaseFood;
}

/*  Set quanlity table  */
void Manager::SetQtyTable()
{
    int qty_table;

    printf("Enter quanlity table of Restaurant : ");
    scanf("%d", qty_table);

    for(int pos = 0; pos < qty_table; pos++)
    {
        Table table;
        table.PositionTable = pos;
        table.StatusTable = false;
        DatabaseTable.push_back(table);
    }
}

/*  Get quanlity Table  */
uint8_t Manager::GetQtyTable()
{
    return DatabaseTable.size();
}

/* Run program Manager  */
void Manager::RunProgramManager()
{
    int select = 0;
    printf("\n");
    printf("* This is a Food Management Program\n");
    printf("------------------------------------\n");
    do
    {
        printf("\t[0] Exit program\n");
        printf("\t[1] Add Food\n");
        printf("\t[2] Fix Food\n");
        printf("\t[3] Delete Food\n");
        printf("\t[4] Find Food\n"); 
        printf("\t[5] List Foods\n");
        printf("\t[6] Set quanlity Table\n");
        printf("\n");
        scanf("%d", select);
        printf("- Select funcion [%d] : ", select);

        switch (select)
        {
            case 1 :
                printf("Add Food\n");
                AddFood();
                break;

            case 2 :
                printf("Fix Food\n");
                FixFood();
                break;            

            case 3 :
                printf("Delete Food\n");
                DeleteFood();
                break; 

            case 4 :
                printf("Find Food\n");
                FindFood();
                break;

            case 5 :
                printf("List Foods\n");
                ListFoods();
                break;            

            case 6 :
                printf("Set quanlity Table\n");
                SetQtyTable();
                break; 
            
            default:
                printf("Exit program\n");
                break;
        } 
    } while (select);    
}

/*  Add Food    */
void Manager::AddFood()
{
    char name[20];
    uint32_t price;

    // Print new food
    printf("- Add new Food\n");

    // Enter new name Food   
    printf("\t+ Enter new name Food : ");
    scanf("%s", &name);

    // Enter price of new food
    printf("\t+ Enter price of new Food : ");
    scanf("%u", &price);

    // Create inform for new food
    Food new_food(name,price);

    // Add new food in database
    DatabaseFood.push_back(new_food);

    printf("- Select [1] if you want to continue add new Food\n");    
}

/*  Fix Food    */
void Manager::FixFood()
{
    char name[20];
    uint32_t price;

    uint8_t ID_Food;
    bool check_ID = false;
    int select;

    /* Enter ID Food need to fix */
    printf("- Enter ID Food need fix : "); 
    printf("------------------------------------\n");
    scanf("%u",&ID_Food);
    printf("\n");
    /* Find ID Food in list */
    for(int num_ID = 0; num_ID < DatabaseFood.size(); num_ID++)
    {
        // Check ID Food is exist or not
        if((DatabaseFood.at(num_ID)).GetIDFood() == ID_Food)
        {
            // ID Food is exist
            check_ID = true;

            // Implement fix Food
            do
            {
                printf("- Fix inform for Food\n");
                printf("\t[0] End Fix\n");
                printf("\t[1] Fix name Food\n");
                printf("\t[2] Fix price Food\n");
                printf("------------------------------------\n");
                // Select inform need to fix
                scanf("%d", &select);
                printf("\t - Fix inform [%d] : ",select);

                // Sellect inform
                switch (select)
                {
                case 1 :
                    printf("Name of Food\n");
                    scanf("%s",&name);
                    (DatabaseFood.at(ID_Food)).SetNameFood(name);
                    break;

                case 2 :
                    printf("Price of Food\n");
                    scanf("%u",&price);
                    (DatabaseFood.at(ID_Food)).SetPriceFood(price);
                    break;

                default:
                    printf("End fix\n");
                    break;
                }
            } while (select);  
        }
        // if ID Food is exist, after change inform of Food, we will break loop for because there is only ID number
        if(check_ID == true)
        {
            // Assign num_ID to illegal value of condition loop for
            num_ID = DatabaseFood.size();

            printf("- ID Food [%d] is fixed\n");
        }
    }

    // ID is not exist
    if(check_ID == false)
    {
        printf("- ID Food [%d] is NOT exist, you can't fix\n");
    }

    printf("- Select [2] if you want to continue fix Food\n");
}

/*  Delete Food */
void Manager::DeleteFood()
{
    uint8_t ID_Food;
    bool check_ID = false;

    printf("------------------------------------\n");
    /* Enter ID Food need to delete */
    printf("- Enter ID Food need to delete : "); 
    scanf("%u",&ID_Food);
    printf("\n");
    /* Find ID Food in menu */
    for(int num_ID = 0; num_ID < DatabaseFood.size(); num_ID++)
    {
        if((DatabaseFood.at(num_ID)).GetIDFood() == ID_Food)
        {
            // ID number is exist
            check_ID = true;

            // Delete inform of student by ID number
            DatabaseFood.erase(DatabaseFood.begin()+num_ID);

            // Because there is only a ID number, therefore we need to exit loop for after find ID number in list
            // Assign num_ID to illegal value of condition loop for
            num_ID = DatabaseFood.size();            
        }
    }

    // ID number is exist or not
    if(check_ID == false)
    {
        printf("\t+ ID Food [%d] is NOT exist, you can't delete Food\n", ID_Food);
    }
    else if(check_ID == true)
    {
        printf("\t+ ID Food [%d] is deleted in the menu\n", ID_Food);
    }    

    printf("- Select [3] if you want to continue delete Food in menu\n");
}

/*  Find Food   */
void Manager::FindFood()
{
    char name[20];
    bool check_name = false;

    printf("------------------------------------\n");
    /* Enter name Food need to find */
    printf("- Enter name Food need to find in the menu : "); 
    scanf("%s",&name);
    printf("\n");

    // Find name of Food in the menu
    for(int pos = 0; pos < DatabaseFood.size(); pos++)
    {
        if(strcmp((DatabaseFood.at(pos)).GetNameFood(), name) == 0)
        {
            printf("\t+ Food's name is [%s] exist in the menu\n",name);

            // Assign true to verify name of student is exist
            check_name = true;            
        }
    }

    // Food's name is NOT exist in the menu
    if(check_name == false)
    {
        printf("\t+ The Food's [%s] is NOT exist in list\n",name);       
    }

    printf("- Select [4] if you want to continue to find other Food's name\n");
}

/*  List Foods  */
void Manager::ListFoods()
{
    char name[20];
    uint32_t price;
    uint8_t ID_Food;
    int count = 1;

    printf("\n");
    printf("------------------------------------\n");
    printf("- List Food in the menu\n");
    // Print inform of all Foods in the menu
    for(Food food : DatabaseFood)
    {
        ID_Food = food.GetIDFood();
        strcpy(name, food.GetNameFood());
        price = food.GetPriceFood();

        // Print inform of each Food in the menu
        printf("\t+ Food number [%d] : \n",count);
        printf("\t  Name : %s |\tPrice : %u VND | \tID_Food : %u\n",name,price,ID_Food);
        count++;
    }
}

/*
    Class Employee-------------------------------------------------------
*/
class Employee{
    private :
    
};

/*
    Funcion Main
*/
int main()
{
    return 0;
}