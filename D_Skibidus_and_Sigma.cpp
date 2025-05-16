#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Function to calculate score of concatenated array
ll calculateScore(vector<vector<ll>>& arrays, vector<ll>& perm, ll n, ll m) {
    // Create concatenated array based on permutation
    vector<ll> concatenated;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            concatenated.push_back(arrays[perm[i]][j]);
        }
    }
    
    // Calculate score
    ll score = 0;
    ll len = concatenated.size();
    for (ll i = 0; i < len; i++) {
        ll sum = 0;
        for (ll j = 0; j <= i; j++) {
            sum += concatenated[j];
        }
        score += sum;
    }
    return score;
}

void solveTestCase() {
    ll n, m;
    cin >> n >> m;
    
    // Read arrays
    vector<vector<ll>> arrays(n, vector<ll>(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> arrays[i][j];
        }
    }
    
    // Create permutation array
    vector<ll> perm(n);
    for (ll i = 0; i < n; i++) {
        perm[i] = i;
    }
    
    // Try all permutations to find maximum score
    ll maxScore = 0;
    do {
        ll currentScore = calculateScore(arrays, perm, n, m);
        maxScore = max(maxScore, currentScore);
    } while (next_permutation(perm.begin(), perm.end()));
    
    cout << maxScore << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;
    while (t--) {
        solveTestCase();
    }
    return 0;
}