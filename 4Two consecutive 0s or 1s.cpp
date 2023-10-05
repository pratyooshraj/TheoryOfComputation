#include<iostream>
#include<stdlib.h>
#include<string>
#define max 5
#define max1 15

using namespace std;
typedef struct state
{
    string label;
//	int flag_input_state;
    int flag_end_state;
    state* next_state_if_0[max];
    state* next_state_if_1[max];
} state;

state *current_state,*q0,*q1,*q2,*q3;
state* currentstates[max1];
state* finalstates[max1];

void setstates()
{
    q0=new state();
    q0->label="q0";
    q2=new state();
    q2->label="q2";
    q1=new state();
    q1->label="q1";
    q3=new state();
    q3->label="q3";

    current_state=q0;
    q3->flag_end_state=1;
}

void printfinal()
{
    int l=0;
    cout<<"\nFinal states: ";
    while(finalstates[l])
    {
        cout<<" "<<finalstates[l]->label;
        l++;
    }
    cout<<"\n";
}

void setnfa()
{
    q0->next_state_if_0[0]=q0;
    q0->next_state_if_0[1]=q1;


    q0->next_state_if_1[0]=q0;
    q0->next_state_if_1[1]=q2;

    q1->next_state_if_0[0]=q3;

    q2->next_state_if_1[0]=q3;

    q3->next_state_if_0[0]=q3;
    q3->next_state_if_1[0]=q3;
}

int cindex=0;
int findex=0;

int main()
{
    setstates();
    setnfa();
    string s;
    cout<<"\nEnter a number: ";
    cin>>s;
    int i=0;
    while(s[i])
    {
        if(s[i]!='0' && s[i]!='1')
        {
            cout<<"\nInvalid Characters!\n\n";
            exit(1);
        }
        i++;
    }

    i=0;
    currentstates[cindex]=current_state;
    finalstates[findex]=current_state;

    while(s[i])
    {
        cindex=0,findex=0;
        if(s[i]=='0')
        {
            while(currentstates[cindex])
            {
                int zeroindex=0;
                while(currentstates[cindex]->next_state_if_0[zeroindex])
                {
                    finalstates[findex++]=currentstates[cindex]->next_state_if_0[zeroindex];
                    zeroindex++;
                }
                cindex++;
            }
            cindex=0;
            int tindex=0;
            while(finalstates[tindex])
            {
                currentstates[cindex++]=finalstates[tindex++];
            }
            i++;
        }
        if(s[i]=='1')
        {
            cindex=0,findex=0;
            while(currentstates[cindex])
            {
                int oneindex=0;
                while(currentstates[cindex]->next_state_if_1[oneindex])
                {
                    finalstates[findex++]=currentstates[cindex]->next_state_if_1[oneindex];
                    oneindex++;
                }
                cindex++;
            }
            cindex=0;
            int tindex=0;
            while(finalstates[tindex])
            {
                currentstates[cindex++]=finalstates[tindex++];
            }
            i++;
        }
    }

    printfinal();
    findex=0;
    while(finalstates[findex])
    {
        if (finalstates[findex]->flag_end_state)
        {
            cout<<"\nIt is a valid string!\n";
            exit(2);
        }
        findex++;
    }
    cout<<"\nIt is an invalid string!\n";
    return 0;
}
