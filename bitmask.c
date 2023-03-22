/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>

typedef enum{
    SHIRT          = 1 << 0,   //0b00000001
    SHORT          = 1 << 1,   //0b00000010
    SKIRT          = 1 << 2,   //0b00000100
    DRESS          = 1 << 3,   //0b00001000
    RING           = 1 << 4,   //0b00010000
    BRACELET       = 1 << 5,   //0b00100000
    SHOES          = 1 << 6,   //0b01000000
    BAG            = 1 << 7    //0b10000000
}individual_items;

char *cart_items[] = {"SHIRT","SHORT","SKIRT","DRESS","RING","BRACELET","SHOES","BAG"};

void Add_cart(uint8_t *cart, individual_items items)
{
    *cart |= items;
}

void Delete_cart(uint8_t *cart, individual_items items)
{
    *cart &= ~items;
}

void Check_items(uint8_t cart, individual_items items)
{
    for(int i = 0; i < 8; i++)
    {
        if(items & (1 << i))
        {
            if(cart & (1 << i))
            {
                printf("THE CART HAVE : %s\n", cart_items[i]);
            }
            else
            {
                printf("THE CART DON'T HAVE : %s\n", cart_items[i]);  
            }              
        }
    }
}

void Show_cart(uint8_t cart)
{
    printf("SHOW THE CART : ");
    
    for(int i = 0; i < 8; i++)
    {
        if(cart & (1 << i))
        {
            printf("%s ", cart_items[i]);
        }
    }
    
    printf("\n");
}

void Show(individual_items items)
{

}

int main(int argc, char const *argv[])
{
    uint8_t cart;
    
    Add_cart(&cart, SHIRT|SHORT|SKIRT|DRESS|RING);
    
    Show_cart(cart);
    
    Delete_cart(&cart, SHIRT|SKIRT);

    Check_items(cart, SHIRT|RING|SHOES);
 
    Show_cart(cart);    

    return 0;
}





