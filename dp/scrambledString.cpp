/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isScrambled(string s1, string s2){
    if(s1.length()!=s2.length())
        return false;
    int n=s1.length();
    if(n==0)
        return true;
    if(s1==s2)
        return true;
    string copys1=s1,copys2=s2;
    sort(copys1.begin(),copys1.end());
    sort(copys2.begin(),copys2.end());
    if(copys1!=copys2)
        return false;
    for(int i=1;i<n;i++){
        if(isScrambled(s1.substr(0,i),s2.substr(0,i)) && isScrambled(s1.substr(i,n-i),s2.substr(i,n-i)))
            return true;
        if(isScrambled(s1.substr(0,i),s2.substr(n-i,i)) && isScrambled(s1.substr(i,n-i),s2.substr(0,n-i)))
            return true;
    }
    return false;
}

int main(){
    string s1="coder",s2="ocred";
    cout<<isScrambled(s1,s2);
    return 0;
}