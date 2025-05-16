#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> ans(2 * n + 1, 0);
    set<int> used;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int idx = i + j;
            if (ans[idx] == 0) {
                ans[idx] = arr[i][j];
                used.insert(arr[i][j]);
            }
        }
    }

    int missing = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (used.find(i) == used.end()) {
            missing = i;
            break;
        }
    }

    cout<<missing<<" ";
    
    for (int i = 2; i <= 2 * n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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