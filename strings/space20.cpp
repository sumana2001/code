/*
Given a string, write a function to replace all spaces with'%20'
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

void replace_space(char *s)
{
    int spaces = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
            spaces++;
    }
    int idx = spaces * 2 + strlen(s);
    s[idx] = '\0';
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            s[idx - 1] = '0';
            s[idx - 2] = '2';
            s[idx - 3] = '%';
            idx -= 3;
        }
        else
        {
            s[idx - 1] = s[i];
            idx--;
        }
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 1000);
    replace_space(input);
    cout << input << endl;
    return 0;
}