#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;

    int n = str.length();

    string nstr = "";

    for(int i=0; i<n; i = i+2){
        nstr += str[i];
    }

    sort(nstr.begin(), nstr.end());

    string newstr = " ";

    int m = nstr.size();
    for(int i=0; i<m-1; i++){
        newstr += nstr[i];
        newstr += '+';
    }
    newstr += nstr[m-1];
    cout<<newstr<<endl;

    return 0;
}