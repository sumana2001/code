/*

*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int solve(int e, int f){
    if(f==0 || f==1 || e==1)
        return f;
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int temp=1+max(solve(e-1,k-1),solve(e,f-k));
        mn=min(temp,mn);
    }
    return mn;
}

int main(){
    int f=10,e=2;
    cout<<solve(e,f);
    return 0;
}