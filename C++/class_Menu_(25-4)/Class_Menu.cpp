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
    Manager::GetListFood();
    Manager::GetStatusTable();
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
    printf("*** This is a Food Management Program ***\n");
    printf("------------------------------------\n");
    do
    {
        printf("\n");
        printf("* Information of all funcions :\n");
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
    uint8_t qty = 0;

    // Print new food
    printf("* Add new Food\n");

    // Enter new name Food   
    printf("\t+ Enter new name Food : ");
    scanf(" %s", &name);

    // Enter quantity of new food
    // printf("\t+ Enter quantity of new Food : ");
    // scanf("%u", &qty);

    // Enter price of new food
    printf("\t+ Enter price of new Food : ");
    scanf("%ld", &price);

    // Create inform for new food
    Food new_food(name,price,qty);

    // Add new food in database
    DatabaseFood.push_back(new_food);

    printf("!! Select [1] if you want to continue add new Food\n"); 
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
    printf("* Fix Food\n");
    printf("\t+ Enter ID Food need fix : "); 
    scanf("%u",&ID_Food);
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
                printf("\t+ Fix inform for Food\n");
                printf("\t\t[0] End Fix\n");
                printf("\t\t[1] Fix name Food\n");
                printf("\t\t[2] Fix price Food\n");
                printf("------------------------------------\n");
                // Select inform need to fix
                scanf("%d", &select);
                printf("\tSelect funcion [%d] to fix inform : ",select);

                // Sellect inform
                switch (select)
                {
                case 1 :
                    printf("Food's Name\n");
                    scanf("%s",&name);
                    (DatabaseFood.at(ID_Food)).SetNameFood(name);
                    break;

                case 2 :
                    printf("Food's Price\n");
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

            printf("\t-> ID Food [%d] is fixed\n");
        }
    }

    // ID is not exist
    if(check_ID == false)
    {
        printf("\t-> ID Food [%d] is NOT exist, you can't fix\n");
    }

    printf("!! Select [2] if you want to continue fix Food\n");
    printf("\n");
}

/*  Delete Food */
void Manager::DeleteFood()
{
    uint8_t ID_Food;
    bool check_ID = false;

    /* Enter ID Food need to delete */
    printf("* Delete Food\n");
    printf("\t+ Enter ID Food need to delete : "); 
    scanf("%u",&ID_Food);
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
        printf("\t-> ID Food [%d] is NOT exist, you can't delete Food\n", ID_Food);
    }
    else if(check_ID == true)
    {
        printf("\t-> ID Food [%d] is deleted in the menu\n", ID_Food);
    }    

    printf("!! Select [3] if you want to continue delete Food in menu\n");
    printf("\n");
}

/*  Find Food   */
void Manager::FindFood()
{
    char name[20];
    bool check_name = false;

    /* Enter name Food need to find */
    printf("* Find Food in Menu\n");
    printf("\t+ Enter name Food need to find in the menu : "); 
    scanf("%s",&name);
    // Find name of Food in the menu
    for(int pos = 0; pos < DatabaseFood.size(); pos++)
    {
        if(strcmp((DatabaseFood.at(pos)).GetNameFood(), name) == 0)
        {
            printf("\t-> Food's name is [%s] exist in the menu\n",name);

            // Assign true to verify name of student is exist
            check_name = true;            
        }
    }

    // Food's name is NOT exist in the menu
    if(check_name == false)
    {
        printf("\t-> The Food's [%s] is NOT exist in list\n",name);       
    }

    printf("!! Select [4] if you want to continue to find other Food's name\n");
    printf("\n");
}

/*  List Foods  */
void Manager::ListFoods()
{
    char name[20];
    long long price;
    uint8_t ID_Food;
    int count = 1;

    printf("* List Food in the menu\n");
    printf("\n");
    // Print inform of all Foods in the menu
    printf("\tNo\t| ID\t| Food Name\t| Price\t\n");
    for(Food food : DatabaseFood)
    {
        ID_Food = food.GetIDFood();
        strcpy(name, food.GetNameFood());
        price = food.GetPriceFood();
        // Print inform of each Food in the menu
        printf("\t%d\t| %u\t| %s\t \t| %ld\t\n",count,ID_Food,name,price);
        count++;
    }
}

/*
    Class Employee-------------------------------------------------------
*/

typedef struct{
    vector<Food> ListDataFood;
    Table TABLE;
}Order;

/*  Class Employee  */
class Employee{
    private :
        vector<Table> DataTable;
        vector<Order> ListOrderFood;
    public :
        Employee();

        void GetDataManagerFood(Manager *manager);
        uint8_t GetQtyTable();
        
        void RunProgramOrder();
        void ShowStatusTable();

        void OrderFoods();
        void CancelFoods();
        void ShowOrderFood();
        void Payment();
        void ClearTable(uint8_t pos_table);
};

/*  Employee    */
Employee::Employee()
{

}

void Employee::RunProgramOrder()
{
    int select = 0;
    printf("\n");
    printf("*** This is a Food Management Program ***\n");
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
void Employee::GetDataManagerFood(Manager *manager)
{
    // Get inform all table
    DataTable.clear();
    for(auto new_list : manager->GetStatusTable())
    {
        DataTable.push_back(new_list);
    }

    // Get inform Food in menu and save status of all table
    for(int num = 0; num < DataTable.size(); num++)
    {
        Order New_Inform;

        // Get status table
        New_Inform.TABLE.PositionTable = (DataTable.at(num)).PositionTable;
        New_Inform.TABLE.StatusTable = (DataTable.at(num)).StatusTable;

        // Get inform Food 
        //(ListOrderFood.at(num)).ListDataFood.clear();
        for(auto new_list : manager->GetListFood())
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

/*  Show status Table   */
void Employee::ShowStatusTable()
{
    printf(" Table  \t |");
    for(int pos_table = 1; pos_table <= Employee::GetQtyTable(); pos_table++)
    {
        printf(" %d\t| ",pos_table);
    }
    printf("\n Status \t |");
    for(int pos_table = 0; pos_table < Employee::GetQtyTable(); pos_table++)
    {
        if((ListOrderFood.at(pos_table)).TABLE.StatusTable == true)
        {
            printf(" x\t| ");
        }
        else
        {
            printf("  \t| ");
        }
    }
    printf("\n");
}

/* Order Food */
void Employee::OrderFoods()
{
    char Food[20];
    uint8_t Qty = 0;
    uint8_t Pos;
    bool check_food = false;

    //Show status table
    Employee::ShowStatusTable();

    // Import position table need to order
    printf("* Order Food\n");
    printf("\t+ Table order : ");
    scanf("%u", &Pos);

    // Check position table of restaurant
    if(Pos > 0 && Pos <= GetQtyTable())
    {
        (ListOrderFood.at(Pos-1)).TABLE.StatusTable = true;

        // Enter the Food's Name you want to order
        printf("\t+ Enter the Food you want to order : ");
        scanf("%s", &Food);

        // Get quantity Foods in the Menu
        int QtyFood = (ListOrderFood.at(Pos-1)).ListDataFood.size();

        // Check if Food exsit or not in the List
        for(int Num_Food = 0; Num_Food < QtyFood; Num_Food++)
        {
            if(strcmp((ListOrderFood.at(Pos-1)).ListDataFood.at(Num_Food).GetNameFood(), Food) == 0)
            {
                // Food is exsit in the List
                check_food = true;

                // Enter the Food Order quantity
                printf("\t+ Enter the Food Order quantity : ");
                scanf("%u",&Qty);

                // Add quantity Food
                Qty += (ListOrderFood.at(Pos-1)).ListDataFood.at(Num_Food).GetQtyFood();

                // Set new quantity Food
                (ListOrderFood.at(Pos-1)).ListDataFood.at(Num_Food).SetQtyFood(Qty);

                // Show inform order
                printf("\t-> The Food [%s] at number table [%u] have quality : %u\n", Food,Pos,Qty);

                // Break loop for
                Num_Food = QtyFood;
            }
        }
        // Print if food does not exsit in the List
        if(check_food == false)
        {
            printf("\t-> The Food [%s] does not exist in the Menu\n",Food);
        }
    }
    // Printf if number table does not exist
    else
    {
        printf("\t-> The number table [%u] does not exist\n", Pos);
    }
    printf("\n");
}

/*  Cancel order food  */
void Employee::CancelFoods()
{
    char Food[20];
    uint8_t Qty;
    uint8_t Pos;
    bool check_food = false;

    //Show status table
    Employee::ShowStatusTable();

    // Import position table need to order
    printf("* Cancel Food\n");
    printf("\t+ Table order : ");
    scanf("%u", &Pos);    

    // Check position table of restaurant
    if(Pos > 0 && Pos <= GetQtyTable())
    {
        // Check status table before change food
        if((ListOrderFood.at(Pos-1)).TABLE.StatusTable == false)
        {
            printf("\t-> There is no Food on this postion table\n");
        }
        else
        {
            // Enter the Food's Name you want to order
            printf("\t+ Enter the Food you want to cancel : ");
            scanf("%s", &Food);

            // Get quantity Foods in the Menu
            int QtyFood = (ListOrderFood.at(Pos-1)).ListDataFood.size();

            // Check if Food exsit or not in the List
            for(int Num_Food = 0; Num_Food < QtyFood; Num_Food++)
            {
                if(strcmp((ListOrderFood.at(Pos-1)).ListDataFood.at(Num_Food).GetNameFood(), Food) == 0)
                {     
                    if((ListOrderFood.at(Pos-1)).ListDataFood.at(Num_Food).GetQtyFood() > 0)
                    {
                        // Food is exsit in the List
                        check_food = true;

                        Qty = 0;
                        // Set quantity Food is 0, delete Food
                        (ListOrderFood.at(Pos-1)).ListDataFood.at(Num_Food).SetQtyFood(Qty);       

                        // Break loop for
                        Num_Food = QtyFood; 
                    }            
                }
            }
            // Print if food does not exsit in the List
            if(check_food == false)
            {
                printf("\t-> The Food [%s] does not exist therefore or before order, can not cancel Food\n",Food);
            }
        }
    }
    // Printf if number table does not exist
    else
    {
        printf("\t-> The number table [%u] does not exist, can not implement\n", Pos);
    }
    printf("\n");    
}

// Show list foods are ordered
void Employee::ShowOrderFood()
{
    uint8_t Pos;
    int count = 1;
    //Show status table
    Employee::ShowStatusTable();

    // Import position table need to order
    printf("* Show Order Food\n");
    printf("\t+ Table order : ");
    scanf("%u", &Pos);    

    // Check position table of restaurant
    if(Pos > 0 && Pos <= GetQtyTable())
    {
        // Check status table before change food
        if((ListOrderFood.at(Pos-1)).TABLE.StatusTable == false)
        {
            printf("\t-> There is no Food on this postion table\n");
        }
        else
        {    
            printf("\t+ The list Foods are ordered : \n");
            printf("\tNo\t | Name_Food\t | Qty\t\n");
            // Print list food 
            for(auto item : (ListOrderFood.at(Pos-1)).ListDataFood)
            {
                // Check quantity Food > 0, the Food is odered
                if(item.GetQtyFood() > 0)
                {
                    // Show name and quantity Food
                    printf("\t%d\t | %s\t\t | %u\t\n",count,item.GetNameFood(),item.GetQtyFood());
                    count++;
                }
            }
        }
    }
    // Printf if number table does not exist
    else
    {
        printf("\t-> The number table [%u] does not exist, can not show list\n", Pos);
    }
    printf("\n");    
}

/*  Clear Table */
void Employee::ClearTable(uint8_t pos_table)
{

}

/*  Payment for order food  */
void Employee::Payment()
{
    uint8_t Pos;
    int count = 1;
    long long price_each_food = 0;
    long long sum_price = 0;

    //Show status table
    Employee::ShowStatusTable();

    // Import position table need to order
    printf("* Payment\n");
    printf("\t+ Table order : ");
    scanf("%u", &Pos);    

    // Check position table of restaurant
    if(Pos > 0 && Pos <= GetQtyTable())
    {
        // Check status table before change food
        if((ListOrderFood.at(Pos-1)).TABLE.StatusTable == false)
        {
            printf("\t-> There is no Food on this postion table\n");
        }
        else
        {    
            printf("\t No\t | NameFood\t | Qty\t | Price\t\n");
            // Print list food 
            for(auto item : (ListOrderFood.at(Pos-1)).ListDataFood)
            {
                // Check quantity Food > 0, the Food is odered
                if(item.GetQtyFood() > 0)
                {
                    // Calculation total price for all Food
                    price_each_food = (long long)item.GetQtyFood()*(long long)item.GetPriceFood();
                    printf("\t %d\t | %s\t\t | %u\t | %ld VND\t\n",count,item.GetNameFood(),item.GetQtyFood(),price_each_food);
                    sum_price += price_each_food;
                    count++;

                    // Clear qty food after payment
                    item.SetQtyFood(0);
                }
            }

            // Show total price for all food
            printf("\t-> Total price for bill : %ld VND\n",sum_price);
        
            // Clear status table after payment
            (ListOrderFood.at(Pos-1)).TABLE.StatusTable = false;
        }
    }
    // Printf if number table does not exist
    else
    {
        printf("\t-> The number table [%u] does not exist, can not show list\n", Pos);
    }
    printf("\n");        
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
        printf("*** Program inform food and manager order of restaurant ***\n");
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
            printf("Inform of Food in menu\n");
            manager.RunProgramManager();
            printf("\n");
            employee.GetDataManagerFood(&manager);
            break;

        // Implement all funcion for a restaurant
        case 2:
            printf("Book Table or Order Food\n");
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


