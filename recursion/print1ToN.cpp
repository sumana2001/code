/*
Print linearly 1 to n
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print1(int i,int n){
    if(n<i)
        return;
    cout<<i<<" ";
    print1(i+1,n);
}

//backtracking
void print2(int n){
    if(n<1)
        return;
    print2(n-1);
    cout<<n<<" ";
}

int main(){
    int n;
    cin>>n;
    print1(1,n);
    print2(n);
    return 0;
}