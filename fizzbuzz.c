#include <stdio.h>

int main(void)
{
    for (int num = 1; num <= 100; num++)
    {
        if(num % 3 == 0 && num % 5 == 0)
        {
            printf("fizzbuzz\n");
        }
        else if(num % 3 == 0)
        {
            printf("fizz\n");
        }
        else if(num % 5 == 0)
        {
            printf("buzz\n");
        }
        else
        {
            printf("%i\n", num);
        }
    }
}
