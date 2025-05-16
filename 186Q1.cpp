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
    
    int mini = INT_MAX;
    
    for (int i = 0; i < n; ++i) {
        int rating, cost;
        cin >> rating >> cost;
        if (rating >= 7) {
            mini = min(mini, cost);
        }
    }
    
    if (mini == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << mini << endl;
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