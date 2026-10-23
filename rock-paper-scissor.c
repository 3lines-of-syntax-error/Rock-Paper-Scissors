#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int genrannum()
{
    srand(time(NULL));
    return rand() % 3;
}

int main()
{
    int p, k, a = 0, b = 0;
    char s[50];
    printf("\n");
    printf("~~~~~WELCOME TO ROCKS-PAPER-SCISSORS GAME~~~~~\n");
    printf("[[[it's a 3 round game. Whoever scores the highest score will win the game]]]\n");
    printf("Enjoy!!");
    printf("\n");
    printf("enter your name: ");
    scanf("%49[^\n]", s);
    printf("%s's choices:", s);
    printf("\n\t\t1.rock \n\t\t2.paper \n\t\t3.scissor\n");

label:
    for (int i = 0; i < 3; i++)
    {
        printf("play your turn: ");
        scanf("%d", &k);
        k--;

        if (k > 2 || k < 0)
        {
            printf("invalid choice!!! try again\n");
            goto label;
        }
        else
        {
            p = genrannum();
            if (p == 0)
            {
                printf("computer's choice: rock\n");
            }
            else if (p == 1)
            {
                printf("computer's choice: paper\n");
            }
            else
            {
                printf("computer's choice: scissors\n");
            }

            if (p == k)
            {
                printf("draw!\n");
                if(a>b)
                {
                printf("computer: %d\n", a);
                printf("%s: %d\n", s, b);
                }
                else if(b>a)
                {
                printf("%s: %d\n", s, b);
                printf("computer: %d\n", a);
                }
                else
                {
                    printf("%s: %d\n", s, b);
                    printf("computer: %d\n", a);
                    printf("\n");
                }
            }
            else if ((p == 0 && k == 1) || (p == 1 && k == 2) || (p == 2 && k == 0))
            {
                printf("%s got this point\n", s);
                b = b + 1;
                printf("%s: %d\n", s, b);
                printf("computer: %d\n", a);
                printf("\n");
            }
            else if ((p == 1 && k == 0) || (p == 2 && k == 1) || (p == 0 && k == 2))
            {
                printf("computer got this point\n");
                a = a + 1;
                printf("computer: %d\n", a);
                printf("%s: %d\n", s, b);
                printf("\n");
            }
        }
    }
    
    if (a > b)
    {
        printf("computer wins\n");
    }
    else if (b > a)
    {
        printf("%s wins\n", s);
    }
    else
    {
        printf("its a draw\n");
    }
    return 0;
}