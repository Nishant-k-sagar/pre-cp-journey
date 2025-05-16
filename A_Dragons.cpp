#include<bits/stdc++.h>
using namespace std;

int main(){
    int s,n;
    cin>>s>>n;

    vector<pair<int,int>> v(n);

    for(int i=0;i<n; i++){
        int a, b;
        cin>>a>>b;
        v[i] = make_pair(a,b);
    }

    sort(v.begin(), v.end());

    bool flag = true;
    for(int i=0; i<n; i++){
        if(s<=v[i].first){
            flag = false;
            break;
        }


        //just try again to not be in queue
        s=s+v[i].second;
    }

    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}