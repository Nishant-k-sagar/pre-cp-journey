#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    if(n&1==1){
        cout<<-1<<endl;
    }
    else
    {
        for(int i=0; i<n; ++i){
            v[i] = i+1; 
        }

        for(int i=0; i<n-1; i=i+2){
            swap(v[i], v[i+1]);
        }

        for(int i=0; i<n; ++i){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}