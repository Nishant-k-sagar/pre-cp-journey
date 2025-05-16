#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, idx, min = INT_MAX, ele;

    cin>>n;
    int flag = 0;
    for(int i =1; i<=n; i++){
        cin>>ele;
        if(ele == min) flag = 1;
        if(ele<min) {
            min = ele;
            idx = i;
            flag=0;
    }}
    if(flag){
        cout<<"Still Rozdil"<<endl;
    }
    else
    cout<<idx<<endl;
}