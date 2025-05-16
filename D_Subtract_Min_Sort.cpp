#include <bits/stdc++.h>
using namespace std;

bool codewithlove() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int mini = min(arr[i], arr[i + 1]);
        arr[i] -= mini;
        arr[i + 1] -= mini;

        if (arr[i + 1] < arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << (codewithlove() ? "YES\n" : "NO\n");
    }
    return 0;
}
