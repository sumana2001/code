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
    vector<int> arr(5,0);

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

    //2D array
    vector<vector<int>> arr2={
        {1,2,3},
        {4,5,6},
        {7,8,9,10},
        {11,12}
    };

    //update value
    arr2[0][0]+=10;

    //print all values
    for(int i=0;i<arr2.size();i++){
        for(int num:arr2[i]){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}