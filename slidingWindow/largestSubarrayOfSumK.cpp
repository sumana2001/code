/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solve(vector<int> arr, int k){
    int n=arr.size(),sum=0,mx=0,i=0,j=0;
    while(j<n){
        sum+=arr[j];
        if(sum<k)
            j++;
        else if(sum==k){
            mx=max(mx,j-i+1);
            j++;
        }
        else{
            while(sum>k){
                sum-=arr[i];
                i++;
            }
            j++;
        }
    }
    return mx;
}

int main(){
    vector<int> arr{4,1,1,1,2,3,5};
    int k=5;
    cout<<solve(arr,k);
    return 0;
}