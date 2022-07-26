/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

vector<int> solve(vector<int> arr, int k){
    int n=arr.size();
    int i=0,j=0;
    vector<int> result;
    list<int> l;
    while(j<n){
        while(arr[j]>l.back() && !l.empty()){
            l.pop_back();
        }
        l.push_back(arr[j]);
        if(j-i+1<k){
            j++;
        } else if(j-i+1==k){
            result.push_back(l.front());
            if(l.front()==arr[i])
                l.pop_front();
            i++;
            j++;
        }
    }
    return result;
}

int main(){
    vector<int> arr{1, 3, -1, -3, 5, 3, 6, 7};
    int k=3;
    vector<int> result=solve(arr,k);
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}