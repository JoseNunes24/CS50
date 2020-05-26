#include <stdio.h>
#include <cs50.h>

void spaces(void);
void blocks(void);

int main(void) 
{
    //Ask user for input, loop until number is positive
    int height;
    int i;
    int j;
    int h;
    
    do
    {
        height = get_int("What's the height of the blocks: \n");
       
    }
    while (height < 1 || height > 8);

    
    for (h = 1; h <= height; h++) //rows of pyramid, the h is equivalent to number of #
    {
        //print spaces until the number of #, for example, row 2 will print spaces up to i=2
        for (i = height - h; i > 0; i--)
        {
            spaces();
        }
        
        //after i is finished, fill the rest with blocks
        for (j = 1; j <= h ; j++)
        {
            blocks();
        }
        
        // Print space between pyramid
        printf("  ");
        
        //Print other side of pyramid
        for (j = 1; j <= h ; j++)
        {
            blocks();
        }
        
        printf("\n");
    }
}

void spaces(void)
{
    printf(" ");
}

void blocks(void)
{
    printf("#");
}
    