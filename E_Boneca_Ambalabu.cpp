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
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    

    vector<int> bitcnt(30, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 30; ++j) {
            if (arr[i] & (1 << j)) {
                bitcnt[j]++;
            }
        }
    }
    
    ll maxsum = 0;
    
    for (int k = 0; k < n; ++k) {
        ll cursum = 0;
        for (int j = 0; j < 30; ++j) {
            if (arr[k] & (1 << j)) {
                cursum += (1LL << j) * (n - bitcnt[j]);
            } else {
                cursum += (1LL << j) * bitcnt[j];
            }
        }
        maxsum = max(maxsum, cursum);
    }
    
    cout << maxsum << endl;
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