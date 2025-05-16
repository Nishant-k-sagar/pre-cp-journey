#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {-5,10,11,-19,20,1,2,6,7,8,-1};
    int n= sizeof(a)/sizeof(a[0]);
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<n-1; ++j){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }

    for(int i=0; i<n; ++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}