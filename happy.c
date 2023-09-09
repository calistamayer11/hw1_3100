#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("n = ");
    scanf("%d", &n);

    int m = n;
    int sum_square = 0;
    // TODO
    // add code below
    while (n > 0)
    {
        int digit = n % 10;
        sum_square += digit * digit;
        digit /= 10;
    }

    if (n == 1)
        printf("%d is a happy number.\n", m);
    else
        printf("%d is NOT a happy number.\n", m);
    return 0;
}