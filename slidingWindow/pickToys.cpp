/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
using namespace std;

int solve(string s){
    unordered_map<char,int> mp;
    int i=0,j=0,mx=INT_MIN,n=s.length();
    while(j<n){
        mp[s[j]]++;
        if(mp.size()<2)
            j++;
        else if(mp.size()==2){
            mx=max(mx,j-i+1);
            j++;
        } else {
            while(mp.size()>2){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return mx;
}

int main(){
    string s="abaccab";
    cout<<solve(s);
    return 0;
}