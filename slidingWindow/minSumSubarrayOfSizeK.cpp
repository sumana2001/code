/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int solve(vector<int> arr, int k){
    int i=0,j=0,sum=0,minSum=INT_MAX,n=arr.size();
    while(j<n){
        sum+=arr[j];
        if(j-i+1<k)
            j++;
        else if(j-i+1==k){
            minSum=min(minSum,sum);
            sum-=arr[i];
            i++;
            j++;
        }
    }
    return minSum;
}

int main(){
    vector<int> arr{2,5,1,8,2,9,1};
    int k=3;
    cout<<solve(arr,k);
    return 0;
}