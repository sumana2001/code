/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
using namespace std;

int solve(string s, string t){
    int i=0,j=0,mn=INT_MAX,n=s.length(),m=t.length();
    unordered_map<char,int> mp;
    for(int i=0;i<m;i++)
        mp[t[i]]++;
    int count=mp.size();
    while(j<n){
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0)
                count--;
        }
        if(count>0) 
            j++;
        else if(count==0){
            mn=min(mn,j-i+1);
            while(count==0){
                if(mp.find(s[i])==mp.end()){
                    i++;
                    mn=min(mn,j-i+1);
                } else {
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        i++;
                        count++;
                    } else {
                        i++;
                        mn=min(mn,j-i+1);
                    }
                }
            }
            j++;
        }
    }
    return mn;
}

int main(){
    string s = "ADOBECODEBANC", t = "ABC";
    cout<<solve(s,t);
    return 0;
}