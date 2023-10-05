#include<iostream>
#include <regex>
using namespace std;

bool gmail(string str)
{
    const regex pattern("(^[a-zA-Z][a-zA-Z0-9]+(?:\\.[a-zA-Z0-9]+)*@$)");
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

string checkvalid(string str){
    if(gmail(str)){
        return "valid";
    }
    else {
        return "not valid";
    }
}
int main()
{

    string valid = "gmail.com";
    string str1;
    cout << "Enter an email address: ";
    cin >> str1;
    string email = str1.substr(0, str1.size() - valid.size());

    cout << "Extracted email address: " << email << std::endl;
    cout << str1<< " is " << checkvalid(email) << endl;N
    return 0;
}
