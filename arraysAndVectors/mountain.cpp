/*
Given an array of distinct integers, return the highest mountain 
where a mountain is defined as adjacent integers that are strictly
increasing until they reach a peak, at which they become strictly
decreasing. At least 3 numbers are required to make a mountain
*/

#include<iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int n=v.size();
    int maximum=0;
    for(int i=1;i<n-1;){
        int count=1;
        if(v[i]>v[i-1] && v[i]>v[i+1]){
            int j=i;
            while(j>=1 && v[j]>v[j-1]){
                j--;
                count++;
            }
            while(i<=n-2 && v[i]>v[i+1]){
                i++;
                count++;
            }
            maximum=max(count,maximum);
        }
        else{
            i++;
        }
    }
    cout<<maximum<<endl;
    return 0;
}