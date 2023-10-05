//aNbNcN
#include<iostream.h>
#include<string.h>

using namespace std;
int main()
{
    char str[40],input[40];
    int f=0,i;
    cout<<"enter string to be checked:";
    cin>>str;
    for(i=0; i<strlen(str); i++)
        input[i]=str[i];

    while(i<40)
    {
        input[i]='\0';
        i++;
    }
    i=0;
    while(1)
    {
        switch(f)
        {
        case 0:
            if(input[i]=='a')
            {
                f=1;
                input[i]='x';
                i++;
            }
            else if(input[i]=='y')
            {
                f=4;
                i++;
            }
            else
                f= 10; //for invalid transition
            break;
        case 1:
            if(input[i]=='a'||input[i]=='y')
            {
                f=1;
                i++;
            }
            else if(input[i]=='b')
            {
                f=2;
                input[i]='y';
                i++;
            }
            else
                f=10; // for undefined transition
            break;
        case 2:
            if(input[i]=='b'||input[i]=='z')
            {
                f=2;
                i++;
            }
            else if(input[i]=='c')
            {
                f=3;
                input[i]='z';
                i--;
            }
            else
                f=10;
            break;
        case 3:

            if(input[i]=='z'||input[i]=='b'||input[i]=='y'||input[i]=='a')
            {
                f=3;
                i--;
            }
            else if(input[i]=='x')
            {
                f=0;
                i++;
            }
            else
                f=10;
            break;
        case 4:
            if(input[i]=='y'||input[i]=='z')
            {
                f=4;
                i++;
            }
            else if(input[i]=='\0')
            {
                f=5;
            }
            else
                f=10;
            break;
        }
        if(f==10 || f==5)
            break;
    }
    if(f==5)
        cout<<"string is accepted";
    else
        cout<<"string is not accepted";
    return 0;
}
