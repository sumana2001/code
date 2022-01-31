/*
Given a string, print all subsequences sorted by length and lexicographic sorted order if length is same
*/
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void subsequence(string s, string o, vector<string> &v){
    if(s.size()==0){
        v.push_back(o);
        return;
    }
    char ch=s[0];
    string reduced_input=s.substr(1);
    subsequence(reduced_input,o+ch,v);
    subsequence(reduced_input,o,v);
}

bool compare(string s1,string s2){
    if(s1.length()==s2.length())
        return s1<s2;
    return s1.length()<s2.length();
}

int main(){
    string s;
    cin>>s;
    vector<string> subsequences;
    string output="";
    subsequence(s,output,subsequences);
    sort(subsequences.begin(),subsequences.end(),compare);
    for(int i=0;i<subsequences.size();i++)
        cout<<subsequences[i]<<",";
    return 0;
}