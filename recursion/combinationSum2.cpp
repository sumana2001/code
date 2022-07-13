/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<set>
using namespace std;

void combinationSum2(int idx, vector<int> &ds, int arr[],int n,int target, int sum, set<vector<int> > &s){
    if(idx>=n){
        if(target==sum){
            sort(ds.begin(),ds.end());
            s.insert(ds);
        }
        return;
    }
    ds.push_back(arr[idx]);
    sum+=arr[idx];
    combinationSum2(idx+1,ds,arr,n,target,sum,s);
    ds.pop_back();
    sum-=arr[idx];
    combinationSum2(idx+1,ds,arr,n,target,sum,s);
}

int main(){
    int n=7;
    int arr[]={10,1,2,7,6,1,5};
    int target=8;
    vector<int> ds;
    set<vector<int> > s; 
    combinationSum2(0,ds,arr,n,target,0,s);
    for(auto x:s){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}