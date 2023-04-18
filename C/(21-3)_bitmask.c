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
}INDIVIDUAL_ITEMS;

char *CART_ITEMS[] = {"SHIRT","SHORT","SKIRT","DRESS","RING","BRACELET","SHOES","BAG"};

void ADD_CART(uint8_t *cart, INDIVIDUAL_ITEMS items)
{
    *cart |= items;
}

void DELETE_CART(uint8_t *cart, INDIVIDUAL_ITEMS items)
{
    *cart &= ~items;
}

void CHECK_ITEMS(uint8_t cart, INDIVIDUAL_ITEMS items)
{
    for(int i = 0; i < 8; i++)
    {
        if(items & (1 << i))
        {
            if(cart & (1 << i))
            {
                printf("THE CART HAVE : %s\n", CART_ITEMS[i]);
            }
            else
            {
                printf("THE CART DON'T HAVE : %s\n", CART_ITEMS[i]);  
            }              
        }
    }
}

void SHOW_CART(uint8_t cart)
{
    printf("SHOW THE CART : ");
    
    for(int i = 0; i < 8; i++)
    {
        if(cart & (1 << i))
        {
            printf("%s ", CART_ITEMS[i]);
        }
    }
    
    printf("\n");
}

void HIen_Thi(INDIVIDUAL_ITEMS items)
{

}

int main(int argc, char const *argv[])
{
    uint8_t cart;
    
    ADD_CART(&cart, SHIRT|SHORT|SKIRT|DRESS|RING);
    
    SHOW_CART(cart);
    
    DELETE_CART(&cart, SHIRT|SKIRT);

    CHECK_ITEMS(cart, SHIRT|RING|SHOES);
 
    SHOW_CART(cart);    

    return 0;
}



