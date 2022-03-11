/*
Sum of N Numbers
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void sum1(int n, int total){
    if(n<1){
        cout<<total<<endl;
        return;
    }
    sum1(n-1,total+n);
}

int sum2(int n){
    if(n<1)
        return 0;
    return n+sum2(n-1);
}

int main(){
    int n;
    cin>>n;
    sum1(n,0);
    cout<<sum2(n);
    return 0;
}