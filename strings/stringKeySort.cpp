/*
Given a list of n string each consisting digits and spaces.
The program has to support the required parameters:
1. key: interger denoting the column to be used as key for comparisons.
2. reversed: boolean variable indicating whether to reverse the result of comparisons.
3. comparison-type: either numeric(122>13) or lexicographic(122<13).
*/
#include<iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string extractStringAtKey(string str, int key){
    char *s=strtok((char*)str.c_str()," ");
    while(key>1){
        s=strtok(NULL," ");
        key--;
    }
    return (string)s;
}

int convertToInt(string s){
    int ans=0;
    int p=1;
    for(int i=s.length()-1;i>=0;i--){
        ans+=((s[i]-'0')*p);
        p=p*10;
    }
    return ans;
}

bool lexiCompare(pair<string,string> s1, pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return key1<key2;
}

bool numericCompare(pair<string,string> s1, pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return convertToInt(key1)<convertToInt(key2);
}

int main(){
    int n;
    cin>>n;
    cin.get();  //consume extra \n
    string temp;
    vector<string> v;
    for(int i=0;i<n;i++){
        getline(cin,temp);  //include all white spaces
        v.push_back(temp);
    }
    int key;
    string reversal,ordering;
    cin>>key>>reversal>>ordering;   

    //1.Key
    vector<pair<string,string>> vp;
    for(int i=0;i<n;i++)
        vp.push_back({v[i],extractStringAtKey(v[i],key)});

    // 2.Sort
    if(ordering=="numeric")
        sort(vp.begin(),vp.end(),numericCompare);
    else    
        sort(vp.begin(),vp.end(),lexiCompare);

    //3.Reverse
    if(reversal=="true")
        reverse(vp.begin(),vp.end());

    //4.Output
    for(int i=0;i<n;i++){
        cout<<vp[i].first<<endl;
    }
    return 0;
}