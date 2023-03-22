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
    if(items & (1 << 0))
    {
        if(cart & (1 << 0))
        {
            printf("THE CART HAVE :  : SHIRT\n");
        }
        else
        {
            printf("THE CART DON'T HAVE :  : SHIRT\n");  
        }
    }
    
    if(items & (1 << 1))
    {
        if(cart & (1 << 1))
        {
            printf("THE CART HAVE :  : SHORT\n");
        }
        else
        {
            printf("THE CART DON'T HAVE :  : SHORT\n");  
        }        
    }   

    if(items & (1 << 2))
    {
        if(cart & (1 << 2))
        {
            printf("THE CART HAVE :  : SKIRT\n");
        }
        else
        {
            printf("THE CART DON'T HAVE :  : SKIRT\n");  
        }        
    }
    
    if(items & (1 << 3))
    {
        if(cart & (1 << 3))
        {
            printf("THE CART HAVE :  : DRESS\n");
        }
        else
        {
            printf("THE CART DON'T HAVE :  : DRESS\n");  
        }        
    }
    
    if(items & (1 << 4))
    {
        if(cart & (1 << 4))
        {
            printf("THE CART HAVE :  : RING\n");
        }
        else
        {
            printf("THE CART DON'T HAVE :  : RING\n");  
        }        
    }
    
    if(items & (1 << 5))
    {
        if(cart & (1 << 5))
        {
            printf("THE CART HAVE :  : BRACELET\n");
        }
        else
        {
            printf("THE CART DON'T HAVE :  : BRACELET\n");  
        }        
    }
    
    if(items & (1 << 6))
    {
        if(cart & (1 << 6))
        {
            printf("THE CART HAVE :  : SHOES\n");
        }
        else
        {
            printf("THE CART DON'T HAVE :  : SHOES\n");  
        }        
    }
    
    if(items & (1 << 7))
    {
        if(cart & (1 << 7))
        {
            printf("THE CART HAVE :  : BAG\n");
        }        
        else
        {
            printf("THE CART DON'T HAVE :  : BAG\n");  
        }        
    }    
}

void Show_cart(uint8_t cart)
{
    //individual_items do_dung;
    
    printf("SHOW THE CART : ");
    
    if(cart & (1 << 0))
    {
        printf("SHIRT ");
    }
    
    if(cart & (1 << 1))
    {
        printf("SHORT ");
    }  
    
    if(cart & (1 << 2))
    {
        printf("SKIRT ");
    }
    
    if(cart & (1 << 3))
    {
        printf("DRESS ");
    } 
    
    if(cart & (1 << 4))
    {
        printf("RING ");
    }
    
    if(cart & (1 << 5))
    {
        printf("BRACELET ");
    }
    
    if(cart & (1 << 6))
    {
        printf("SHOES ");
    }
    
    if(cart & (1 << 7))
    {
        printf("BAG ");
    }  
    
    printf("\n");
}

void HIen_Thi(individual_items items)
{

}

int main(int argc, char const *argv[])
{
    uint8_t cart;
    
    Add_cart(&cart, SHIRT|SHORT|SKIRT|DRESS|RING);
    
    Show_cart(cart);
    
    Delete_cart(&cart, SHIRT|SKIRT);

    Check_items(cart, SHIRT|RING|SKIRT);
 
    Show_cart(cart);    

    return 0;
}





