#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

bool checker(deque<int> arr) {
    while (arr.size() > 1) {
        bool inc = true;
        for (ll i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] >= arr[i + 1]) {
                inc = false;
                break;
            }
        }
        if (!inc) return false;
        
        deque<int> d;
        for (ll i = 0; i < arr.size() - 1; ++i) {
            d.push_back(arr[i + 1] - arr[i]);
        }
        arr = move(d);
    }
    return true;
}

void nottryingenouf()
{
    // try it harder
    int n;
    cin >> n;
    deque<int> dq(n);
    for (int i = 0; i < n; ++i) {
        cin >> dq[i];
    }
    
    if (n > 1001) {
        cout << string(n, '0') << endl;
        return;
    }
    
    string res;
    for (int i = 0; i < n; ++i) {
        deque<int> m;
        for (int j = 0; j < n; ++j) {
            if (i != j) m.push_back(dq[j]);
        }
        res += (checker(m) ? '1' : '0');
    }
    
    cout << res << endl;
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