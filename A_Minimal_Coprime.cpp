#include<bits/stdc++.h>
using namespace std;

void codewithlove() {
    long long l, r;
    cin >> l >> r;


    if(l==1 && r==1){
        cout<<1<<endl;
        return;
    }
    if (l == 1) {
        cout << (r - l ) << endl;
        return;
    }

    cout << (r - l) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        codewithlove();
    }

    return 0;
}
