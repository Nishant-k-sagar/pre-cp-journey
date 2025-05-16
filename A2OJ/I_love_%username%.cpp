#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int count = 0;
    for(int i=1; i<n; i++){
        if(v[i]>*max_element(v.begin(), v.begin()+i) || v[i]<*min_element(v.begin(), v.begin()+i)){
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}