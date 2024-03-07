#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user for height
    int height;

    do
    {
        height = get_int("What is the height?\n");
    }
    while (height < 1 || height > 8);

    // Print pyramid
    for (int row = 0; row < height; row++)

    {
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }

        printf("  ");

        for (int space = 0; space < row + 1; space++)
        {
            printf("#");
        }
        printf("\n");
    }
}
