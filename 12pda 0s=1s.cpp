#include <bits/stdc++.h>
using namespace std;

stack<char> s;
int pda = 0;

void state0()
{
    cout << " At State 0\t";
    s.push('$');
    pda=1;
    cout << "Going state 1\n\n";
}

void state1(char c)
{
    cout<<c;
    cout << "At State 1\t";
    if (c == 'a' && (s.top()=='a' || s.top()=='$'))
    {
        s.push('a');
        cout << "Going state 1\n";
        pda = 1;
    }
    else if (c == 'b' && (s.top()=='b' || s.top()=='$'))
    {
        s.push('b');
        cout << "Going state 1\n";
        pda = 1;
    }
    else if (c == 'b' && s.top() == 'a')
    {
        s.pop();
        cout << "Going State 1\n";
        pda = 1;
    }
    else if (c == 'a' && s.top()== 'b')
    {
        s.pop();
        cout << "Going State 1\n";
        pda = 1;
    }
    else if(s.top()=='$')
    {
        s.pop();
        pda=2;
        cout << "Going state 2\n";
    }
}

void state2()
{
    pda=2;
    cout<<"\n";
    cout << "At State 2\n";
}

int isAccepted(char str[])
{
    int i, len = strlen(str);
    state0();

    for (i = 0; i <= len; i++)
    {
        if (pda == 0)
            state0();

        else if (pda == 1)
            state1(str[i]);

        else if (pda == 2)
            state2();

        else
            return 0;
    }
    if (pda == 2)
        return 1;
    else
        return 0;
}

int main()
{
    char str[] = "babbbaaa";
    if (isAccepted(str))
        printf("\nACCEPTED");
    else
        printf("\nNOT ACCEPTED");
    return 0;
}
