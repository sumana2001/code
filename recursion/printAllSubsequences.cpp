/*
Print all subsequences of an array
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print(int idx, vector<int> &ds, int arr[],int n){
    if(idx>=n){
        for(auto x:ds)
            cout<<x<<" ";
        if(ds.size()==0)
            cout<<"{}";
        cout<<endl;
        return;
    }
    ds.push_back(arr[idx]);
    print(idx+1,ds,arr,n);
    ds.pop_back();
    print(idx+1,ds,arr,n);
}

int main(){
    int arr[]={1,2,3};
    int n=3;
    vector<int> ds;
    print(0, ds, arr, n);
    return 0;
}