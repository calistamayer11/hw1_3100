#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("n = ");
    scanf("%d", &n);

    int m = n;

    // // keep track of repeating numbers
    int seen[1000] = {0};

    // TODO
    // add code below
    while (1)
    {
        int sum_square = 0;

        // sum of squares of all digits
        while (n > 0)
        {
            int digit = n % 10;
            sum_square += digit * digit;
            n /= 10;
        }
        printf("%d\n", sum_square);

        if (sum_square == 1)
        {
            printf("%d is a happy number.\n", m);
            break;
        }
        else if (sum_square == 4)
        {
            printf("%d is NOT a happy number.\n", m);
            break;
        }
        else
        {
            seen[sum_square] = 1;
            n = sum_square;
        }
    }
    return 0;
}