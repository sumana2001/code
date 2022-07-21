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
int minPalindromicPartitionRecursive(string s,int i, int j){
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i>=j || isPalindrome(s,i,j))
        return 0;
    int min=INT_MAX;
    int count;
    for(int k=i;k<j;k++){
        count=minPalindromicPartitionRecursive(s,i,k)+minPalindromicPartitionRecursive(s,k+1,j)+1;
        if(count<min)
            min=count;
    }
    return dp[i][j]=min;
}

int main(){
    string s="aaaa";
    int n=s.length();
    cout<<minPalindromicPartition(s,0,n-1);
    cout<<minPalindromicPartitionRecursive(s,0,n-1);
    return 0;
}