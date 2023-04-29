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
        long long PriceFood;
        uint8_t Qty;

    public :
        Food(char NameFood[] = "\0", long long PriceFood = 0, uint8_t Qty = 0);
        void SetNameFood(char NameFood[])     { strcpy(this->NameFood,NameFood); }
        char *GetNameFood()                   { return this->NameFood;           }
        
        void SetPriceFood(long long PriceFood) { this->PriceFood = PriceFood; }
        long long GetPriceFood()               { return this->PriceFood;      }

        void SetQtyFood(uint8_t Qty)          { this->Qty = Qty;    }
        uint8_t GetQtyFood()                  { return this->Qty;   }

        uint8_t GetIDFood()                   { return this->id_Food; }
};

/*  Funcion : Get inform Foods  */
Food::Food(char NameFood[], long long PriceFood, uint8_t Qty)
{
    // Number of food in list
    static uint8_t id = 100;
    this->id_Food = id;
    id++;

    strcpy(this->NameFood, NameFood);
    this->PriceFood = PriceFood;
    this->Qty = Qty;
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
        vector<Table> GetStatusTable();
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

/*  Get Status Table    */
vector<Table> Manager::GetStatusTable()
{
    return Manager::DatabaseTable;
}

/*  Set quanlity table  */
void Manager::SetQtyTable()
{
    int qty_table;

    printf("Enter quanlity table of Restaurant : ");
    scanf("%d", &qty_table);

    for(int pos = 1; pos <= qty_table; pos++)
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
    printf("*** This is a Food Management Program\n");
    do
    {
        printf("------------------------------------\n");
        printf("Information of all funcions :\n");
        printf("\t[0] Exit program\n");
        printf("\t[1] Add Food\n");
        printf("\t[2] Fix Food\n");
        printf("\t[3] Delete Food\n");
        printf("\t[4] Find Food\n"); 
        printf("\t[5] List Foods\n");
        printf("\t[6] Set quanlity Table\n");
        //printf("\n");
        scanf("%d", &select);
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
    long long price;
    uint8_t qty;

    // Print new food
    printf("* Add new Food\n");

    // Enter new name Food   
    printf("\t+ Enter new name Food : ");
    scanf(" %s", &name);

    // Enter quantity of new food
    printf("\t+ Enter quantity of new Food : ");
    scanf("%u", &qty);

    // Enter price of new food
    printf("\t+ Enter price of new Food : ");
    scanf("%ld", &price);

    // Create inform for new food
    Food new_food(name,price,qty);

    // Add new food in database
    DatabaseFood.push_back(new_food);

    printf("Select [1] if you want to continue add new Food\n"); 
    printf("\n");   
}

/*  Fix Food    */
void Manager::FixFood()
{
    char name[20];
    long long price;

    uint8_t ID_Food;
    bool check_ID = false;
    int select;

    /* Enter ID Food need to fix */
    printf("* Enter ID Food need fix : "); 
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
                printf("+ Fix inform for Food\n");
                printf("\t[0] End Fix\n");
                printf("\t[1] Fix name Food\n");
                printf("\t[2] Fix price Food\n");
                printf("------------------------------------\n");
                // Select inform need to fix
                scanf("%d", &select);
                printf("\tFix inform [%d] : ",select);

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
                    scanf("%ld",&price);
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

            printf("\tID Food [%d] is fixed\n");
        }
    }

    // ID is not exist
    if(check_ID == false)
    {
        printf("\tID Food [%d] is NOT exist, you can't fix\n");
    }

    printf("Select [2] if you want to continue fix Food\n");
    printf("\n");
}

/*  Delete Food */
void Manager::DeleteFood()
{
    uint8_t ID_Food;
    bool check_ID = false;

    /* Enter ID Food need to delete */
    printf("* Enter ID Food need to delete : "); 
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
        printf("\tID Food [%d] is NOT exist, you can't delete Food\n", ID_Food);
    }
    else if(check_ID == true)
    {
        printf("\tID Food [%d] is deleted in the menu\n", ID_Food);
    }    

    printf("Select [3] if you want to continue delete Food in menu\n");
    printf("\n");
}

/*  Find Food   */
void Manager::FindFood()
{
    char name[20];
    bool check_name = false;

    /* Enter name Food need to find */
    printf("* Enter name Food need to find in the menu : "); 
    scanf("%s",&name);
    printf("\n");

    // Find name of Food in the menu
    for(int pos = 0; pos < DatabaseFood.size(); pos++)
    {
        if(strcmp((DatabaseFood.at(pos)).GetNameFood(), name) == 0)
        {
            printf("\tFood's name is [%s] exist in the menu\n",name);

            // Assign true to verify name of student is exist
            check_name = true;            
        }
    }

    // Food's name is NOT exist in the menu
    if(check_name == false)
    {
        printf("\tThe Food's [%s] is NOT exist in list\n",name);       
    }

    printf("Select [4] if you want to continue to find other Food's name\n");
    printf("\n");
}

/*  List Foods  */
void Manager::ListFoods()
{
    char name[20];
    long long price;
    uint8_t ID_Food;
    int count = 1;

    printf("List Food in the menu\n");
    printf("\n");
    // Print inform of all Foods in the menu
    for(Food food : DatabaseFood)
    {
        ID_Food = food.GetIDFood();
        strcpy(name, food.GetNameFood());
        price = food.GetPriceFood();

        // Print inform of each Food in the menu
        printf("\tFood number [%d] : \n",count);
        printf("\tName : %s |\tPrice : %ld VND | \tID_Food : %u\n",name,price,ID_Food);
        count++;
    }
}

/*
    Class Employee-------------------------------------------------------
*/

/*  Class Employee  */
class Employee{
    private :
        vector<Table> DataTable;

        typedef struct{
            vector<Food> ListDataFood;
            Table TABLE;
        }Order;
        
        vector<Order> ListOrderFood;
    public :
        Employee();

        void GetDataManagerFood(Manager manager);
        uint8_t GetQtyTable();

        void RunProgramOrder();

        void OrderFoods();
        void CancelFoods();
        void ShowOrderFood();
        void Payment();
};

/*  Employee    */
Employee::Employee()
{

}

void Employee::RunProgramOrder()
{
    int select = 0;
    printf("\n");
    printf("* This is a Food Management Program\n");
    printf("------------------------------------\n");
    do
    {
        // Information for all funcion
        printf("\t[0] Exit program\n");
        printf("\t[1] Order Food\n");
        printf("\t[2] Cancel Food\n");
        printf("\t[3] Show list order Food\n");
        printf("\t[4] Payment\n"); 
        //printf("\n");

        // Enter selection for funcion
        scanf("%d", &select);
        printf("- Select funcion [%d] : ", select);

        // Select funcion
        switch (select)
        {
        case 1:
            printf("Order Food\n");
            OrderFoods();
            break;
        
        case 2:
            printf("Cancel Food\n");
            CancelFoods();
            break;

        case 3:
            printf("Show list order Food\n");
            ShowOrderFood();
            break;

        case 4:
            printf("Payment\n");
            Payment();
            break;

        default:
            printf("Exit program\n");
            break;
        }
    } while (select); 
}

/*  Get data for list inform food in the menu */
void Employee::GetDataManagerFood(Manager manager)
{
    // Get inform all table
    DataTable.clear();
    for(auto new_list : manager.GetStatusTable())
    {
        DataTable.push_back(new_list);
    }

    // Get inform Food in menu and save status of all table
    for(int num = 1; num <= DataTable.size(); num++)
    {
        Order New_Inform;

        // Get status table
        New_Inform.TABLE.PositionTable = (DataTable.at(num)).PositionTable;
        New_Inform.TABLE.StatusTable = (DataTable.at(num)).StatusTable;

        // Get inform Food 
        (ListOrderFood.at(num)).ListDataFood.clear();
        for(auto new_list : manager.GetListFood())
        {
            New_Inform.ListDataFood.push_back(new_list);
        }

        // Push all inform in StatusOrderFood
        ListOrderFood.push_back(New_Inform);
    }
}

// Get number Table in restaurant
uint8_t Employee::GetQtyTable()
{
    return DataTable.size();
}

/* Order Food */
void Employee::OrderFoods()
{
    char Food[20];
    uint8_t Qty = 0;
    uint8_t Pos;
    bool check_food = false;

    // Import position table need to order
    printf("Table order : ");
    scanf("%u", &Pos);

    // Check position table of restaurant
    if(Pos > 0 && Pos <= GetQtyTable())
    {
        (ListOrderFood.at(Pos)).TABLE.StatusTable = true;

        // Enter the Food's Name you want to order
        printf("\tEnter the Food you want to order : ");
        scanf("%s", &Food);

        // Get quantity Foods in the Menu
        int QtyFood = (ListOrderFood.at(Pos)).ListDataFood.size();

        // Check if Food exsit or not in the List
        for(int Num_Food = 0; Num_Food < QtyFood; Num_Food++)
        {
            if(strcpy((ListOrderFood.at(Pos)).ListDataFood.at(Num_Food).GetNameFood(), Food) == 0)
            {
                // Food is exsit in the List
                check_food = true;

                // Enter the Food Order quantity
                printf("\tEnter the Food Order quantity : ");
                scanf("%u",&Qty);

                // Add quantity Food
                Qty += (ListOrderFood.at(Pos)).ListDataFood.at(Num_Food).GetQtyFood();

                // Set new quantity Food
                (ListOrderFood.at(Pos)).ListDataFood.at(Num_Food).SetQtyFood(Qty);

                // Show inform order
                printf("The Food [%s] at number table [%u] have quality : %u\n", Food,Pos,Qty);

                // Break loop for
                Num_Food = QtyFood;
            }
        }
        // Print if food does not exsit in the List
        if(check_food == false)
        {
            printf("The Food [%s] does not exist in the Menu\n",Food);
        }
    }
    // Printf if number table does not exist
    else
    {
        printf("The number table [%u] does not exist\n", Pos);
    }
}

/*  Cancel order food  */
void Employee::CancelFoods()
{
    char Food[20];
    uint8_t Qty;
    uint8_t Pos;
    bool check_food = false;

    // Import position table need to order
    printf("Table order : ");
    scanf("%u", &Pos);    

    // Check position table of restaurant
    if(Pos > 0 && Pos <= GetQtyTable())
    {
        // Check status table before change food
        if((ListOrderFood.at(Pos)).TABLE.StatusTable == false)
        {
            printf("There is no Food on this postion table\n");
        }
        else
        {
            // Enter the Food's Name you want to order
            printf("\tEnter the Food you want to cancel : ");
            scanf("%s", &Food);

            // Get quantity Foods in the Menu
            int QtyFood = (ListOrderFood.at(Pos)).ListDataFood.size();

            // Check if Food exsit or not in the List
            for(int Num_Food = 0; Num_Food < QtyFood; Num_Food++)
            {
                if(strcpy((ListOrderFood.at(Pos)).ListDataFood.at(Num_Food).GetNameFood(), Food) == 0)
                {     
                    // Food is exsit in the List
                    check_food = true;

                    Qty = 0;
                    // Set quantity Food is 0, delete Food
                    (ListOrderFood.at(Pos)).ListDataFood.at(Num_Food).SetQtyFood(Qty);       

                    // Break loop for
                    Num_Food = QtyFood;             
                }
            }
            // Print if food does not exsit in the List
            if(check_food == false)
            {
                printf("The Food [%s] does not exist therefore can not cancel Food\n",Food);
            }
        }
    }
    // Printf if number table does not exist
    else
    {
        printf("The number table [%u] does not exist, can not implement\n", Pos);
    }
}

// Show list foods are ordered
void Employee::ShowOrderFood()
{
    uint8_t Pos;

    // Import position table need to order
    printf("Table order : ");
    scanf("%u", &Pos);    

    // Check position table of restaurant
    if(Pos > 0 && Pos <= GetQtyTable())
    {
        // Check status table before change food
        if((ListOrderFood.at(Pos)).TABLE.StatusTable == false)
        {
            printf("There is no Food on this postion table\n");
        }
        else
        {    
            printf("The list Foods are ordered : \n");
            // Print list food 
            for(auto item : (ListOrderFood.at(Pos)).ListDataFood)
            {
                // Check quantity Food > 0, the Food is odered
                if(item.GetQtyFood() > 0)
                {
                    // Show name and quantity Food
                    printf("\tFood : %s |\t Qty : %u\n",item.GetNameFood(),item.GetQtyFood());
                }
            }
        }
    }
    // Printf if number table does not exist
    else
    {
        printf("The number table [%u] does not exist, can not show list\n", Pos);
    }
}

/*  Payment for order food  */
void Employee::Payment()
{
    uint8_t Pos;
    long long sum_price = 0;
    // Import position table need to order
    printf("Table order : ");
    scanf("%u", &Pos);    

    // Check position table of restaurant
    if(Pos > 0 && Pos <= GetQtyTable())
    {
        // Check status table before change food
        if((ListOrderFood.at(Pos)).TABLE.StatusTable == false)
        {
            printf("There is no Food on this postion table\n");
        }
        else
        {    
            // Print list food 
            for(auto item : (ListOrderFood.at(Pos)).ListDataFood)
            {
                // Check quantity Food > 0, the Food is odered
                if(item.GetQtyFood() > 0)
                {
                    // Calculation total price for all Food
                    sum_price += (long long)item.GetQtyFood()*(long long)item.GetPriceFood();
                }
            }

            // Show total price for all food
            printf("Total price for all Foods : %ld\n",sum_price);
        }
    }
    // Printf if number table does not exist
    else
    {
        printf("The number table [%u] does not exist, can not show list\n", Pos);
    }    
}

/*  Run main program    */
void RunMainProgram()
{
    int select;
    Manager manager;
    Employee employee;

    do
    {
        // Show inform for Run main program
        printf("Program inform food and manager order of restaurant\n");
        printf("------------------------------------\n");
        printf("\t+ Select [0] if you want to exit program\n");
        printf("\t+ Select [1] if you want to check inform Food in menu\n");
        printf("\t+ Select [2] if you book table or order food\n");
        scanf("%d",&select);
        printf("- Select funcion [%d] : ",select);

        // Select inform Food or manager
        switch (select)
        {
        // Import inform Food or check Food
        case 1:
            printf(" Inform of Food in menu\n");
            manager.RunProgramManager();
            employee.GetDataManagerFood(manager);
            break;

        // Implement all funcion for a restaurant
        case 2:
            printf(" Book Table or Order Food\n");
            employee.RunProgramOrder();
            break;   

        default:
            printf("Exit Program\n");
            break;
        }
    } while (select);
}

/*
    Funcion Main
*/
int main()
{
    RunMainProgram();

    return 0;
}


