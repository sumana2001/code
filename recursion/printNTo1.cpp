/*
Print linearly n to 1
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print1(int n){
    if(n==0)
        return;
    cout<<n<<" ";
    print1(n-1);
}

//backtracking
void print2(int i,int n){
    if(n<i)
        return;
    print2(i+1,n);
    cout<<i<<" ";
}

int main(){
    int n;
    cin>>n;
    print1(n);
    print2(1,n);
    return 0;
}