#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
        cin>>a[i];
        }
        int cnt = 0;
        int not0= 0;

        for(int i=0; i<n;  i++){
            if(a[i] != 0 && !not0)cnt++, not0 = 1;
            if(a[i] == 0)not0 = 0;
        }
        cout<<(cnt > 2 ? 2: cnt);
        cout<<endl;
    }
    return 0;
}
