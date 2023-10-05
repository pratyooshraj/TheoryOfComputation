#include <iostream>
#include <regex>
using namespace std;

bool isValidString(string str)
{
    // ab*b + aa*b
    const regex pattern("^a[b]*b|a[a]*b$");

    // is empty return false
    if (str.empty())
    {
        return false;
    }

    if (regex_match(str, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string prompt(bool a)
{
    if(a==true)
        return (" is valid string");
    else
        return (" is not valid string");
}

// Driver Code
int main()
{
    // ab*b + aa*b
    string str1;
    cout<<"Enter string";
    cin>>str1;
    cout << str1<<prompt(isValidString(str1)) << endl;
    return 0;
}
