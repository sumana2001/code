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
    int i=0,j=0,mx=INT_MIN,n=s.length();
    unordered_map<char,int> mp;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()==j-i+1){
            mx=max(mx,j-i+1);
            j++;
        } else if(mp.size()<j-i+1){
            while(mp.size()<j-i+1){
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
    string s="pwwkew";
    cout<<solve(s);
    return 0;
}