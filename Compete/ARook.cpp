#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        char a, n;
        a= str[0];
        n=str[1];
        int i=0;
           
        for (int i=1; i<=8; ++i){
            cout<< a <<i<<endl;
            if (a+to_string(i) == str){
                continue;
            }
            }
            for (char ch ='a'; ch<='h'; ++ch){
            cout<< ch << n <<endl;
            if (ch + to_string(n) == str){
                continue;
            }
            }
    }
    return 0;
}