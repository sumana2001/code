/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
using namespace std;

int solve(string s,int k){
    int i=0,j=0,n=s.length(),mx=INT_MIN,count=0;
    unordered_map<char,int> mp;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()<k)
            j++;
        else if(mp.size()==k){
            mx=max(mx,j-i+1);
            j++;
        }
        else {
            while(mp.size()>k){
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
    string s="aabacbebebe";
    int k=3;
    cout<<solve(s,k);
    return 0;
}