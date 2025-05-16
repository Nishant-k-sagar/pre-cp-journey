#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void nottryingenouf() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string check = "RGB";
    int ans = n;

    for (int start = 0; start < 3; ++start) {
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] != check[(start + i) % 3]) {
                cnt++;
            }
        }

        ans = min(ans, cnt);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        nottryingenouf();
    }

    return 0;
}
