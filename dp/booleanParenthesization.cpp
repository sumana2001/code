/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool solveRecursive(string s, int i, int j, bool isTrue){
    if(i>j)
        return false;
    if(i==j){
        if(isTrue==true)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    int ans=0;
    for(int k=i+1;k<j;k+=2){
        if(s[k]=='&'){
            if(isTrue==true){
                ans=ans+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,true));
            } else {
                ans=ans+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,true))+(solveRecursive(s,i,k-1,true)*solveRecursive(s,k+1,j,true))+(solveRecursive(s,i,k-1,false)*solveRecursive(s,k+1,j,false));
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

int main(){
    string s="T^F|F";
    int n=s.length();
    cout<<solveRecursive(s,0,n-1,true);
    return 0;
}