#include <iostream>
#include <vector>
using namespace std;

vector<int> findArray(int n, int k) {
    if (k == 1) {
        vector<int> a(n, 1);
        a[n-1] = 2; // Any number greater than 1 up to 10^9
        return a;
    } else if (k == n) {
        return vector<int>(n, 1); // All elements are 1
    } else {
        return vector<int>(); // Return an empty array to signify -1
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> result = findArray(n, k);
        if (result.empty()) {
            cout << "-1\n";
        } else {
            for (int num : result) {
                cout << num << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
