#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll codewithlove() {
    int n, m;
    cin>>n>>m;
    if(n>m)cout<<n+1<<endl;
    else if(m>n){
    cout<<m+1<<endl;
    }
    else cout<<n+1<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        codewithlove();
    }

    return 0;
}
