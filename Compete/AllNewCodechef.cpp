#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    if(x>y){
        cout<<"New"<<"\n";
    }
    else if(x<y){
    cout<<"Old"<<"\n";
    }
    else
    cout<<"Same"<<"\n";
    return 0;
}