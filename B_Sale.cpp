#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> a(n);
    for(int &e:a) {
        cin>>e;
    }

    auto comp = [&](int a,int b){
        return a<b;
    };

    sort(a.begin(), a.end(), comp);

    int sum = 0;
    for(int i=0; i<m; i++){
        if(a[i]<0){
        sum+=a[i];
        }
    }
    
    cout<<abs(sum)<<endl;
    return 0;
}