#include <iostream>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        bool found = false;
        
        for (int y = 1; y < x; ++y) {
            int z = x ^ y;
            if (y + x > z && y + z > x && x + z > y && z > 0) {
                cout << y << "\n";
                found = true;
                break;
            }
        }
        
        if (!found) cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}