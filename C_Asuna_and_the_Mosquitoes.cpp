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
    ll sum = 0, cntodd = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
        cntodd += arr[i] & 1; 
    }

    if (cntodd == n || cntodd == 0) {
        cout << *max_element(arr.begin(), arr.end()) << '\n';
    } else {
        cout << sum - cntodd + 1 << '\n';
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