#include <bits/stdc++.h>
using namespace std;

int calculateInitialConvenience(const vector<int> &arr) {
    int n = arr.size();
    int maxConvenience = INT_MIN;

    int maxVal = INT_MIN, minVal = INT_MAX;
    for (int i = 0; i < n; ++i) {
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
        int convenience = maxVal - minVal - i;
        maxConvenience = max(maxConvenience, convenience);
    }

    return maxConvenience;
}

int calculateConvenienceWithUpdate(const vector<int> &arr, int index) {
    int n = arr.size();
    int maxConvenience = INT_MIN;

    int maxVal = INT_MIN, minVal = INT_MAX;
    for (int i = index; i < n; ++i) {
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
        int convenience = maxVal - minVal - (i - index);
        maxConvenience = max(maxConvenience, convenience);
    }

    return maxConvenience;
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        // Calculate and print initial convenience
        int initialConvenience = calculateInitialConvenience(arr);
        cout << initialConvenience << endl;

        // Process updates and recalculate convenience
        while (q--) {
            int p, x;
            cin >> p >> x;
            --p; // Convert to 0-based indexing
            arr[p] = x; // Update the value

            // Update only the affected range
            cout << calculateConvenienceWithUpdate(arr, p) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
