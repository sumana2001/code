/*
Given two non-empty strings, write a function that determines whether the second string is subsequence of first one
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isSubset(string s1,string s2){
    int i=s1.length()-1;
    int j=s2.length()-1;

    while(i>=0 && j>=0){
        if(s2[j]==s1[i]){
            i--;
            j--;
        }
        else
            i--;
    }
    if(j==-1)
        return true;
    return false;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<isSubset(s1,s2)<<endl;
    return 0;
}