/*
Given a string, write a function to find the largest substring with unique characters (no duplicates)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

string uniqueSubstring(string str)
{
    int i = 0, j = 0, windowLen = 0, maxLen = 0, startWindow = -1;
    unordered_map<char, int> m;
    while (j < str.length())
    {
        char ch = str[j];
        if (m.count(ch) and m[ch] >= i)
        {
            i = m[ch] + 1;
            windowLen = j - i;
        }
        m[ch] = j;
        windowLen++;
        j++;
        if (windowLen > maxLen)
        {
            maxLen = windowLen;
            startWindow = i;
        }
    }
    return str.substr(startWindow, maxLen);
}

int main()
{
    string input;
    cin >> input;
    cout << uniqueSubstring(input) << endl;
    return 0;
}