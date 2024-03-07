#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int count = 0;
    long number = get_long("Number: \n");
    long original = number;
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;

    int mod = number % 10;

    do
    {
        if (count % 2 == 0)
        {
            sum1 = sum1 + number % 10;
        }
        else
        {
            int digit = 2 * (number % 10);
            sum2 = sum2 + digit % 10 + digit / 10;
        }
        number = number / 10;
        count++;
    }
    while (number >= 1);

    // printf("Sum1 is %i, sum2 is %i\n", sum1, sum2);

    int total = (sum2) + sum1;
    // printf("Count is %i", count);

    if (total % 10 == 0)
    {
        if (count == 13 || count == 16)
        {
            long z = pow(10, count - 1);
            // printf("Z is %li", z);
            int firstdigit = original / z;
            // printf("First digit is %i", firstdigit);

            if (firstdigit == 4)
            {
                printf("VISA\n");
                return 0;
            }
        }

        if (count == 15)
        {
            long z = pow(10, count - 2);
            // printf("Z is %li", z);
            int firstdigit = original / z;
            // printf("First digit is %i", firstdigit);

            if (firstdigit == 34 || firstdigit == 37)
            {
                printf("AMEX\n");
                return 0;
            }
        }

        if (count == 16)
        {
            long z = pow(10, count - 2);
            // printf("Z is %li", z);
            int firstdigit = original / z;
            // printf("First digit is %i", firstdigit);

            if (firstdigit >= 51 && firstdigit <= 55)
            {
                printf("MASTERCARD\n");
                return 0;
            }
        }
    }

    printf("INVALID\n");
}
