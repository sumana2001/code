/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> 
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

unordered_map<string,int> mp;
bool isScrambledDP(string s1, string s2){
    if(s1.length()!=s2.length())
        return false;
    int n=s1.length();
    if(n==0)
        return true;
    if(s1==s2)
        return true;

    string temp=s1;
    temp.push_back(' ');
    temp.append(s2);
    if(mp.find(temp)!=mp.end())
        return mp[temp];
    
    string copys1=s1, copys2=s2;
    sort(copys1.begin(),copys1.end());
    sort(copys2.begin(),copys2.end());
    if(copys1!=copys2)
        return mp[temp]=false;
    
    for(int i=1;i<n;i++){
        if(isScrambledDP(s1.substr(0,i),s2.substr(0,i)) && isScrambledDP(s1.substr(i,n-i),s2.substr(i,n-i)))
            return mp[temp]=true;
        if(isScrambledDP(s1.substr(0,i),s2.substr(n-i,i)) && isScrambledDP(s1.substr(i,n-i),s2.substr(0,n-i)))
            return mp[temp]=true;
    }
    return mp[temp]=false;
}

int main(){
    string s1="coder",s2="ocred";
    cout<<isScrambled(s1,s2);
    cout<<isScrambledDP(s1,s2);
    return 0;
}