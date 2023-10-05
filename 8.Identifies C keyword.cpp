#include <iostream>
#include <string>
#include<cctype>
#include<algorithm>
using namespace std;

bool isValid(string s)
{
    //transform(s.begin(), s.end(), s.begin(), ::tolower);
    if(s=="auto"||s=="break"||s=="case"||s=="char"||s=="const"||s=="continue"||s=="default"||s=="do"
            ||s=="double"||s=="else"||s=="enum"||s=="extern"||s=="float"||s=="for"||s=="goto"||s=="if"
            ||s=="int"||s=="long"||s=="register"||s=="return"||s=="short"||s=="signed"||s=="sizeof"
            ||s=="static"||s=="struct"||s=="switch"||s=="typedef"||s=="union"||s=="unsigned"||s=="void"||s=="volatile"||s=="while")
    {
        return true;
    }

}

int main()
{
    string str;
    cout<<"enter string\t";
    cin>>str;

    if (isValid(str))
        cout << "Given string is C keyword";
    else
        cout << "Given string is not C keyword";

    return 0;
}
