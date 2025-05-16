#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int &e:a) {
        cin>>e;
    }

    int m;
    cin>>m;

    vector<int> b(m);
    for(int &e:b){
        cin>>e;
    }

    map<int,int> mp;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!(b[j]%a[i])){
                mp[b[j]/a[i]]++;
            }
        }
    }

    cout<<mp.rbegin()->second;

    return 0;
}