#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n;
    int a[n],b[n],c[n];
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    int x=0,y=0,z=0;
    for(int i=0; i<n; i++){
        x += a[i];
        y += b[i];
        z += c[i];
    }

    if(x == 0 & y== 0 & z==0){
        cout<<"YES"<<endl;
    }
    else
    cout<<"NO"<<endl;
    return 0;
}