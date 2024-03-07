#include <cs50.h>
#include <stdio.h>

int collatz(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n % 2 == 0)
    {
        return 1 + collatz(n/2);
    }
    else
    {
        return 1 + collatz(3*n +1);
    }

}
