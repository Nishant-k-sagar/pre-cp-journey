#include<bits/stdc++.h>
using namespace std;


int main(){
    map<int,int> mp;
    long long int vasya = 0;
    long long int petya = 0;

    int n, m;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        mp[x] = i;
    }

    cin>>m;

    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        vasya += mp[x]+1;

        petya += n - mp[x];
    }

    cout<<vasya<<" "<<petya;
    return 0;
}