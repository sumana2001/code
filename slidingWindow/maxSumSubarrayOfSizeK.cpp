/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int solve(vector<int> arr, int k){
    int n=arr.size();
    int sum=0,maxSum=INT_MIN,i=0,j=0;
    while(j<n){
        sum+=arr[j];
        if(j-i+1<k)
            j++;
        else if(j-i+1==k){
            maxSum=max(maxSum,sum);
            sum-=arr[i];
            i++;
            j++;
        }
    }
    return maxSum;
}

int main(){
    vector<int> arr{2,5,1,8,2,9,1};
    int k=3;
    cout<<solve(arr,k);
    return 0;
}