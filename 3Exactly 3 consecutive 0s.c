//DFA over {0,1} having exactly three consecutive 0s
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100

void printstate(int i)
{
    if(i==4||i==6||i==7)
        printf("State q%d(Final state)\n",i);
        else if(i==5)
        printf("State q%d(dead state)\n",i);
    else
        printf("State q%d\n",i);
}

int main()
{
    char str[max];
    int i, f = 1;
    printf("Enter the string to be checked: ");
    scanf("%s",str);
    printf("start:");

    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]!='0' && str[i]!='1')
        {
            printf("Invalid string");
            exit(1);
        }
        printstate(f);
        switch(f)
        {
        case 1:
            //printf("state q1\n");
            if(str[i]=='0')
                f=2;
            else if(str[i]=='1')
                f=1;
            break;
        case 2:
            //printf("state q2\n");
            if(str[i]=='0')
                f=3;
            else if(str[i]=='1')
                f=1;
            break;
        case 3:
            // printf("state q3\n");
            if(str[i]=='0')
                f=4;
            else if(str[i]=='1')
                f=1;
            break;
        case 4:
            //printf("state q4(Final state)\n");
            if(str[i]=='0')
                f=5;
            else if(str[i]=='1')
                f=6;
            break;
        case 5:
            //printf("state q5\n");
            if(str[i]=='0')
                f=5;
            else if(str[i]=='1')
                f=5;
            //printf("dead state");
            exit(0);
            break;
        case 6:
            // printf("state q6(Final state)\n");
            if(str[i]=='0')
                f=7;
            else if(str[i]=='1')
                f=6;
            break;
        case 7:
            //printf("state q7(Final state)\n");
            if(str[i]=='0')
                f=4;
            else if(str[i]=='1')
                f=6;
            break;
        }
    }
    printstate(f);
    if(f==4 || f==6|| f==7)
        printf("\nString is accepted");
    else
        printf("\nString is not accepted");
    return 0;
}
