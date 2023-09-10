#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;

    printf("n = ");
    scanf("%d", &n);

    double pi = 0.;
    double sum = 0.0;

    // TODO
    // add code below
    for (i = 0; i <= n; i++)
    {

        double a, b, c, d;
        double left_side;
        double right_side = 1.0;

        a = 4.0 / (8 * i + 1);
        b = 2.0 / (8 * i + 4);
        c = 1.0 / (8 * i + 5);
        d = 1.0 / (8 * i + 6);
        left_side = a - b - c - d;

        for (int j = 0; j < i; j++)
        {
            right_side /= 16.0;
        }

        double term = left_side * right_side;
        sum += term;
    }
    pi = sum;

    printf("PI = %.10f\n", sum);
    return 0;
}