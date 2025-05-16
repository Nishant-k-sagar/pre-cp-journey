#include <bits/stdc++.h>
using namespace std;

void codewithlove() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = INT_MIN;

    int num = 1 << n;

    for (int i = 0; i < num; i++) {
        int m = 0;
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                m += a[j];
                if (j + 1 < n ) {
                    s += b[j + 1];
                }
            }
        }
        ans = max(ans, m - s);
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        codewithlove();
    }

    return 0;
}