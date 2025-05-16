#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // Read input
    int n, k;
    cin >> n >> k;
    
    if (n == 1 || (n == 2 && k == 2)) {
        cout << "-1" << endl;
        return;
    }
    
    vector<vector<int>> vec(k);
    for (int i = 1; i <= n; i++) {
        vec[i % k].push_back(i);
    }
    
    for (int i = 0; i < k; i++) {
        if (vec[i].size() == 1) {
            cout << "-1" << endl;
            return;
        }
    }
    
    vector<int> perm(n + 1);
    
    for (int i = 0; i < k; i++) {
        auto tempv = vec[i];
        int size = tempv.size();
        
        if (size > 0) {
            for (int j = 0; j < size; j++) {
                int idx = tempv[j];
                int nextIdx = tempv[(j + 1) % size];
                perm[idx] = nextIdx;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << perm[i] << (i == n ? "\n" : " ");
    }
}

int main()
{
    fast
    ll t;
    cin >> t;
    while (t--)
    {
        nottryingenouf();
    }
}