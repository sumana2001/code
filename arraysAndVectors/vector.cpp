#include<iostream>
#include <vector>
using namespace std;

int main()
{
    //vector of size 0
    // vector<int> arr;

    //vector with values initialized
    // vector<int> arr = {1, 2, 3, 4, 5, 6};

    //fill constructor
    vector<int> arr(10,0);

    //pop_back O(1)
    arr.pop_back();

    //push_back O(1)
    arr.push_back(15);

    //print vector
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }

    //size of vector
    cout<<arr.size()<<endl;

    //capacity of vector
    cout<<arr.capacity()<<endl;

    return 0;
}