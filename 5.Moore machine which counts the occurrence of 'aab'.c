#include<string.h>
#include <stdio.h>
#include<stdlib.h>
#define max 100
#include<conio.h>

int printstate(int i)
{
    if(i==3)
    {
        printf("State q%d\t",i);
        printf("output=1\n");
        return 1;
    }

    else
    {
        printf("State q%d\t",i);
        printf("output=0\n");
    }
}

int main()
{
    char str[max];
    int i=0, f = 0;
    int count=0,out=0;
    printf("Enter the string to be checked: ");
    scanf("%s",str);
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

        case 0:
            if(str[i]=='a')
                f=1;
            else if(str[i]=='b')
                f=0;
            break;
        case 1:
            //printf("state q1\n");
            if(str[i]=='a')
                f=2;
            else if(str[i]=='b')
                f=0;
            break;
        case 2:
            //printf("state q2\n");
            if(str[i]=='a')
                f=2;
            else if(str[i]=='b')
                f=3;
            break;
        case 3:
            //count++;
            //printf("state q3(Final)\n");
            if(str[i]=='a')
                f=1;
            else if(str[i]=='b')
                f=0;
            break;
        }

    }
    count+=printstate(f);
    printf("occurrence=%d\n",count);

    return 0;
}

