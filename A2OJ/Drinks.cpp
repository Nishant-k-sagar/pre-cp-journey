#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    int a[n];

    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    
    
    double sum=0;

    for(int i=0; i<n; ++i){
        sum+= double(a[i])/100;
    }

    double num = ((sum)/n)*100;
    cout<<fixed<<setprecision(12)<<num<<endl;
    return 0;
}