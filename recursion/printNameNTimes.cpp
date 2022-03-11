/*
Print name n times
*/
#include<iostream>
using namespace std;

void printNameNTimes(int i, int n){
    if(i==n)
        return;
    cout<<"Tina"<<endl;
    printNameNTimes(i+1,n);
}


int main(){
    int n;
    cin>>n;
    printNameNTimes(0,n);
    return 0;
}