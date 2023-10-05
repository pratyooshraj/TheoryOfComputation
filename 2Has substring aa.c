#include<string.h>
#include <stdio.h>
#include<stdlib.h>
#define max 100

void printstate(int i)
{
    if(i==3)
        printf("State q%d(Final state)\n",i);
    else
        printf("State q%d\n",i);
}


int main()
{
    char str[max];
    int i=0, f = 1;

    printf("Enter the string to be checked: ");
    scanf("%s",str);
    printf("start:");
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]!='a' && str[i]!='b')
        {
            printf("Invalid string");
            exit(1);
        }
        printstate(f);
        switch(f)
        {

        case 1:

            if(str[i]=='a')
                f=2;
            else if(str[i]=='b')
                f=1;
            break;
        case 2:
            //printf("state q2\n");
            if(str[i]=='a')
                f=3;
            else if(str[i]=='b')
                f=1;
            break;
        case 3:
            //printf("state q3(Final)\n");
            if(str[i]=='a')
                f=3;
            else if(str[i]=='b')
                f=3;
            break;
        }

    }
    printstate(f);
    if(f==3)
        printf("String is accepted");
    else
        printf("String is not accepted");

    return 0;
}
