/*
Check if string is palindrome
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s,int i, int n){
    if(i>=n/2)
        return true;
    if(s[i]!=s[n-i-1])
        return false;
    return isPalindrome(s,i+1,n);
}

int main(){
    string s;
    cin>>s;
    cout<<isPalindrome(s,0,s.length());
    return 0;
}