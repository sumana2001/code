/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solve(string s, string ptr){
    int k=ptr.length();
    int n=s.length();
    unordered_map<char,int> mp;
    for(int i=0;i<k;i++){
        mp[s[i]]++;
    }
    int count=mp.size();
    int ans=0,i=0,j=0;
    while(j<n){
        mp[s[j]]--;
        if(mp[s[j]]==0)
            count--;
        if(j-i+1<k)
            j++;
        else if(j-i+1==k){
            if(count==0)
                ans++;
            if(mp[s[i]]==0){
                count++;
            }
            mp[s[i]]++;
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    string s="forxxorfxdofr";
    string ptr="for";
    cout<<solve(s,ptr);
    return 0;
}