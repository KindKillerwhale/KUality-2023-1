#include<stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)

int checkgrade(char c) {
    if (c == 'A' || c == 'a')
        return 4;
    else if (c == 'B' || c == 'b')
        return 3;
    else if (c == 'C' || c == 'c')
        return 2;
    else if (c == 'D' || c == 'd')
        return 1;
    else if (c == 'F' || c == 'f')
        return 0;
    else
        return -1;
}

int main(int argc, char* argv[]) {
    int count = 0;
    double score = 0;

    printf("how many score you will input? >> ");
    scanf(" %d", &count);

    if (count <= 0) {
        printf("WRONG INPUT!!!!!!!");
        return 0;
    }

    for (int i = 0; i < count; i++) {
        char grade[3] = {' '};
        char* gradep = grade;
        printf("input grade >> ");
        scanf(" %s", &grade[0]);

        if (checkgrade(grade[0]) < 0) {
            i--;
            printf("wrong input!\n");
        }

        else {
            score += checkgrade(grade[0]);
            if (*(gradep + 1) == '+') 
                score += 0.5;
        }
    }

    double avg = score / (double)count;
    printf("grade avg : %0.2lf", avg);

    return 0;
}