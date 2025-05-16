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

    vector<ll> arr(n), brr(n);
    ll suma = 0, sumb = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        suma += arr[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> brr[i];
        sumb += brr[i];
    }

    if (suma < sumb) {
        cout << "-1"<<endl;
        return;
    }

    ll diff = suma - sumb;

    if (diff == 0) {
        unordered_map<ll, int> cnta, cntb;
        for (auto val : arr) cnta[val]++;
        for (auto val : brr) cntb[val]++;
        
        if (cnta == cntb) {
            cout << *max_element(arr.begin(), arr.end()) + 1 << endl;
        } else {
            cout << "-1"<<endl;
        }
        return;
    }

    ll maxa = *max_element(arr.begin(), arr.end());
    ll maxb = *max_element(brr.begin(), brr.end());

    for (ll k = 1; k * k <= diff; ++k) {
        if (diff % k == 0) {
            ll div[2] = {k, diff / k};
            for (int i = 0; i < 2; ++i) { 
                ll it = div[i];
                if (it > maxb && it <= maxa) {
                    unordered_map<ll, int> modmpA;
                    for (int i = 0; i < n; i++) {
                        modmpA[arr[i] % it]++;
                    }
    
                    unordered_map<ll, int> cntbmp;
                    for (auto val : brr) cntbmp[val]++;
                    if (modmpA == cntbmp) {
                        cout << it << "\n";
                        return;
                    }
                }
            }
        }
    }
    

    cout << "-1"<<endl;
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