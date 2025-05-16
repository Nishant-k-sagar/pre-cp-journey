#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;

        string s;
        cin>>s;

        bool ifzero = false;

        for (i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i == n - 1) {
                    cout << "YES" << endl;
                } else {
                    cout << "IDK" << endl;
                }
            } else {
                ifzero = true;
                break;
            }
        }

        if (ifzero) {
            for (i; i < n; i++) {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}