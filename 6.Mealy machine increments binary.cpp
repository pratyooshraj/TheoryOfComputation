#include<string.h>
#include<iostream>
using namespace std;
#define max 50
int main()
{
    char str[max],inv[max];
    int outp[max];
    int i,j,k,f=0;
    cout<<"enter binary number: ";
    cin>>str;
    j=strlen(str);
    k=0;
    for(i=j-1; i>=0; i--)
    {
        inv[k++]=str[i];
    }
    for(i=0; i<j; i++)
    {
        if(inv[i]!='0' && inv[i]!='1')
        {
            cout<<"Invalid string";
            exit(1);
        }
        switch(f)
        {
        case 0:
            if(inv[i]=='0')
            {
                f=1;
                outp[i]=1;
            }
            else
            {
                f=2;
                outp[i]=0;
            }
            break;
        case 1:
            if(inv[i]=='0')
            {
                f=1;
                outp[i]=0;
            }
            else
            {
                f=1;
                outp[i]=1;
            }
            break;
        case 2:
            if(inv[i]=='0')
            {
                f=1;
                outp[i]=1;
            }
            else
            {
                f=2;
                outp[i]=0;
            }
            break;
        }
    }
    if(f==2)
    {
        outp[i]=1;
        i++;
    }
    cout<<"output= ";
    for(j=i-1; j>=0; j--)
    {
        cout<<outp[j];
    }
    return 0;
}
