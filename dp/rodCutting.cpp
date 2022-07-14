/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int rodCutting(vector<int> price, vector<int> length, int n, int lengthOfRod){
    vector<vector<int>> dp(n+1,vector<int>(lengthOfRod+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<lengthOfRod+1;j++){
            if(length[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-length[i-1]]);
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][lengthOfRod];
}

int main(){
    vector<int> price{1,5,8,9,10,17,17,20};
    int lengthOfRod=8;
    vector<int> length;
    for(int i=1;i<=lengthOfRod;i++){
        length.push_back(i);
    }
    int n=price.size();
    cout<<rodCutting(price,length,n,lengthOfRod);
    return 0;
}