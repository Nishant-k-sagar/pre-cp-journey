#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin>>n>>m;

    //n for boys and m for girls

    string str1= "GB";
    string str2="BG";
    string str = "";

    int diff = abs(n-m);

    if(n>m){
        for(int i=0; i<m; i++){
            str.append(str2);
        }
    }
    for(int i=0; i<str2.length(); i++)
    cout<<str2;

    return 0;
}