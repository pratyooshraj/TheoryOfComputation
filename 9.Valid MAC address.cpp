#include <iostream>
#include <regex>
using namespace std;

// Function to validate the MAC address
bool isValidMACAddress(string str)
{

    // Regex to check valid MAC address
    const regex pattern(
    "^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})|"
	"(([0-9a-fA-F]{4}\\.){2}[0-9a-fA-F]{4})$");

    // If the MAC address
    // is empty return false
    if (str.empty())
    {
        return false;
    }

    // Return true if the MAC address
    // matched the ReGex
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
        return (" is valid MAC address");
    else
        return (" is not valid MAC address");
}

int main()
{
    string str1 = "01-23-45-67-89-AB";
    cout << str1<<prompt(isValidMACAddress(str1)) << endl;

    string str2 = "01:23:45:67:89:AB";
    cout << str2<<prompt(isValidMACAddress(str2)) << endl;

    string str3 = "0123.4567.89AB";
    cout << str3<<prompt(isValidMACAddress(str3)) << endl;

    string str4 = "01-23-45-67-89-AH";
    cout << str4<<prompt(isValidMACAddress(str4)) << endl;

    string str5 = "01-23-45-67-AH";
    cout << str5<<prompt(isValidMACAddress(str5))  << endl;

    return 0;
}
