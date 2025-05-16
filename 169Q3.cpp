#include <bits/stdc++.h>
using namespace std;

long long minTransformCost(string a, string B) {
    int n = a.size(), m = B.size();
    int j = 0; // Pointer for B
    long long cost = 0;
    
    vector<int> indices;  // Stores positions of B's characters in a
    for (int i = 0; i < n && j < m; i++) {
        if (a[i] == B[j]) {
            indices.push_back(i);
            j++;
        }
    }

    // If B is not a subsequence of a, return -1
    if (j < m) return -1;

    // Compute the minimum cost
    long long dynamicIndex = 0;
    j = 0; // Reset pointer for indices array
    for (int i = 0; i < n; i++) {
        if (j < (int)indices.size() && indices[j] == i) {
            j++;  // Keep the character, move forward
        } else {
            cost += (dynamicIndex + 1); // Deleting from the beginning minimizes cost
            dynamicIndex++;
        }
    }

    return cost-(a[0]-'a');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        string a, B;
        cin >> a >> B;
        cout << minTransformCost(a, B) << "\n";
    }

    return 0;
}
