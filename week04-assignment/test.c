#pragma warning(disable:4996)
#pragma warning(disable:6031)

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int count;
    double score = 0;
    double average;
    char grade[3];

    printf("Input Subject Count: ");
    scanf("%d", &count);

    for (int i = 1; i <= count; i++) 
    {
        printf("Inpute Your Score: ");
        scanf("%s", grade);

        if (strcmp(grade, "A+") == 0) 
        {
            score += 4.5;
        }
        else if (strcmp(grade, "A") == 0)
        {
            score += 4.0;
        }
        else if (strcmp(grade, "B+") == 0)
        {
            score += 3.5;
        }
        else if (strcmp(grade, "B") == 0) 
        {
            score += 3.0;
        }
        else if (strcmp(grade, "C+") == 0) 
        {
            score += 2.5;
        }
        else if (strcmp(grade, "C") == 0) 
        {
            score += 2.0;
        }
        else if (strcmp(grade, "D+") == 0)
        {
            score += 1.5;
        }
        else if (strcmp(grade, "D") == 0)
        {
            score += 1.0;
        }
        else if (strcmp(grade, "F") == 0)
        {
            score += 0;
        }
        else {
            printf("Wrong Input! Order: %d.\n", i);
            i--;
        }
    }

    average = (float)score / count;
    printf("Your average grade is: %.2f\n", average);
    return 0;
}
