#include <iostream>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    if (2 * K > N) {
        cout << "-1 -1\n";
        return;
    }

    int a = K, b = 3 * K;
    
    if (b > N) {
        cout << "-1 -1\n";
        return;
    }

    cout << a << " " << b << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
