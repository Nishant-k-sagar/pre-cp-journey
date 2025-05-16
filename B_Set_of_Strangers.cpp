#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n, m;
    cin >> n >> m;
    int total = n * m;
    
    vector<int> arr(total);
    for (int i = 0; i < total; i++) {
        cin >> arr[i];
    }
    
    unordered_map<int, int> cost;
    unordered_map<int, bool> cur;
    
    for (int i = 0; i < total; i++) {
        int c = arr[i];
        if (!cur[c]) {
            cur[c] = true;
            cost[c] = 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int idx = i * m + j;
            int c = arr[idx];
            if (j + 1 < m && arr[idx + 1] == c) {
                cost[c] = 2;
            }
            if (i + 1 < n && arr[(i + 1) * m + j] == c) {
                cost[c] = 2;
            }
        }
    }
    
    long long Sum = 0;
    int best = 0;
    for (auto it = cost.begin(); it != cost.end(); ++it) {
        Sum += it->second;
        best = max(best, it->second);
    }
    
    cout << (Sum - best) << endl;
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