/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

bool isPalindrome(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int minPalindromicPartition(string s, int i, int j){
    if(i>=j || isPalindrome(s,i,j))
        return 0;
    int k;
    int min=INT_MAX;
    int count;
    for(k=i;k<j;k++){
        count=minPalindromicPartition(s,i,k)+minPalindromicPartition(s,k+1,j)+1;
        if(count<min)
            min=count;
    }
    return min;
}
vector<vector<int>> dp(101,vector<int>(101,-1));
int minPalindromicPartitionMemoized(string s,int i, int j){
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i>=j || isPalindrome(s,i,j))
        return 0;
    int min=INT_MAX;
    int count;
    for(int k=i;k<j;k++){
        count=minPalindromicPartitionMemoized(s,i,k)+minPalindromicPartitionMemoized(s,k+1,j)+1;
        if(count<min)
            min=count;
    }
    return dp[i][j]=min;
}
vector<vector<int>> t(101,vector<int>(101,-1));
int minPalindromicPartitionOptimized(string s,int i, int j){
    if(t[i][j]!=-1)
        return t[i][j];
    if(i>=j || isPalindrome(s,i,j))
        return 0;
    int min=INT_MAX;
    int count,left,right;
    for(int k=i;k<j;k++){
        for(k=i;k<j;k++){
        if(t[i][k]!=-1)
            left=t[i][k];
        else
            left=minPalindromicPartition(s,i,k);
        if(t[k+1][j]!=-1)
            right=t[k+1][j];
        else 
            right=minPalindromicPartition(s,k+1,j);
        count=left+right+1;
        if(count<min)
            min=count;
    }
        if(count<min)
            min=count;
    }
    return t[i][j]=min;
}

int main(){
    string s="abcde";
    int n=s.length();
    cout<<minPalindromicPartition(s,0,n-1);
    cout<<minPalindromicPartitionMemoized(s,0,n-1);
    cout<<minPalindromicPartitionOptimized(s,0,n-1);
    return 0;
}