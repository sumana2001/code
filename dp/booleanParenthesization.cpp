/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solveRecursive(string s, int i, int j, bool isTrue){
    if(i>j)
        return true;
    if(i==j){
        if(isTrue==true){
            return s[i]=='T';
        } else {
            return s[i]=='F';
        }
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2){
        if(s[k]=='&'){
            if(isTrue==true){
                ans=ans+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,true));
            } else {
                ans=ans+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,true))+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,false))+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,false));
            }
        }
        if(s[k]=='|'){
            if(isTrue==true){
                ans=ans+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,true))+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,true))+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,false));
            } else {
                ans=ans+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,false));
            }
        }
        if(s[k]=='^'){
            if(isTrue==true){
                ans=ans+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,false))+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,true));
            } else {
                ans=ans+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,false))+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,true));
            }
        }
    }
    return ans;
}

unordered_map<string,int> mp;
int solveMemoization(string s, int i, int j, bool isTrue){
    if(i>j)
        return true;
    if(i==j){
        if(isTrue==true){
            return s[i]=='T';
        } else {
            return s[i]=='F';
        }
    }

    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }

    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2){
        if(s[k]=='&'){
            if(isTrue==true){
                ans=ans+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,true));
            } else {
                ans=ans+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,true))+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,false))+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,false));
            }
        }
        if(s[k]=='|'){
            if(isTrue==true){
                ans=ans+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,true))+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,true))+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,false));
            } else {
                ans=ans+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,false));
            }
        }
        if(s[k]=='^'){
            if(isTrue==true){
                ans=ans+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,false))+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,true));
            } else {
                ans=ans+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,false))+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,true));
            }
        }
    }
    return mp[temp]=ans;    

}

int main(){
    string s="T|T&F^T";
    int n=s.length();
    cout<<solveRecursive(s,0,n-1,true);
    mp.clear();
    cout<<solveMemoization(s,0,n-1,true);
    return 0;
}