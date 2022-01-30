/*
Creating my own custom tokeniser
*/
#include<iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char *mystrtok(char *str,char delim){
    //static variable to store string variable left to tokenise
    static char *input=NULL;

    //first case (first time goes through tokeniser)
    if(str!=NULL)
        input=str;

    //last case (string tokenised and input at the last char i.e NULL)
    if(input==NULL)
        return NULL;

    //creating dynamic array to return current token
    char *token=new char[strlen(input)+1];
    int i=0;
    for(;input[i]!='\0';i++){
        if(input[i]!=delim)
            token[i]=input[i];
        else{
            token[i]='\0';
            input=input+i+1;
            return token;
        }
    }

    //reached end of string
    token[i]='\0';
    input=NULL;
    return token;
}

int main(){
    char s[1000];
    cin.getline(s,1000);
    char *token=mystrtok(s,' ');
    while(token!=NULL){
        cout<<token<<endl;
        token=mystrtok(NULL,' ');
    }
    return 0;
}