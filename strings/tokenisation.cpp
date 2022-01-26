/*
Tokenizing a string denotes splitting a string with respect to some delimiter(s)
Example: "today is a sunny day" becomes "today","is","a","sunny","day"
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;

//String stream class
void token1()
{
    string s;
    getline(cin, s);

    //creating stringstream object
    stringstream ss(s);
    string token;
    vector<string> tokens;
    while (getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }

    for (auto token : tokens)
    {
        cout << token << ",";
    }
}

//Strtok() function
void token2()
{
    char input[1000];
    cin.getline(input, 1000);

    char *token = strtok(input, " ");
    //creates static variable and last state of string is stored
    while (token != NULL)
    {
        cout << token << endl;
        token = strtok(NULL, " ");
    }
}

int main()
{
    token1();
    token2();
    return 0;
}