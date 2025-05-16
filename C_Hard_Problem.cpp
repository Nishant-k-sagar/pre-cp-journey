#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 1; 
    cin >> t;

    while (t--) {
        long long m, a, b, c;
        cin >> m >> a >> b >> c;

        long long r1 = min(a, m);
        
        long long r2 = min(b, m);

        long long r1_rem = m - r1;
        long long r2_rem = m - r2;

        long long c_place = min(c, r1_rem + r2_rem);

        long long tot = r1 + r2 + c_place;

        cout << tot << endl;
    }

    return 0;
}
