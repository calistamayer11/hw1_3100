// Only this line of comment is provided
#include <stdio.h>

int main()
{

    double total = 0.0; // total of every number so far
    double count = 0.0; // stores count of all the numbers so far

    // printf("Enter number:\n");

    while (1)
    { // pay attention to %lf
        double number;

        if (scanf("%lf", &number) == 1)
        {
            total += number;
            count++;
            double avg = total / count;
            printf("Total=%.6lf Average=%.6lf\n", total, avg);
        }

        else
        {
            if (feof(stdin))
            {
                // printf("EOF detected. Program terminated.\n");
                break; // Exit the loop when EOF is detected
            }
            else
            {
                // fprintf(stderr, "Error reading input.\n");
                return 1;
            }
        }
    }

    return 0;
}