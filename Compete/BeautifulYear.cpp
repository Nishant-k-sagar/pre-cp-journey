#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin>>num;

    int digits = log10(num)+1;

    int hash[10] = {0};

    for(int index = num+1; index< num+10; index++){
        int  temp_index = index;
        int a;
        for(int i=0; i<digits; i++){
            a = temp_index%10;
            hash[a]++;
            cout<<hash[a]<<" ";
            temp_index /= 10;
        }
    }

    for(int i = 0; i<10; i++){
        cout<<hash[i]<<" ";
    } 

    return 0;
}