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
    
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll mini = *min_element(arr.begin(), arr.end());
    
    int miniCnt = count(arr.begin(), arr.end(), mini);
    
    if (miniCnt >= 2) {
        cout << "Yes"<<endl;
        return;
    }
    
    vector<ll> div; // divisible numbers by minimum value
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != mini && arr[i] % mini == 0) {
            div.push_back(arr[i]);
        }
    }
    
    
    if (div.empty()) {
        cout << "No"<<endl;
        return;
    }
    
    ll gcd = div[0];
    for (int i = 1; i < div.size(); i++) {
        gcd = __gcd(gcd, div[i]);
    }
    
    if (gcd == mini) {
        cout << "Yes"<<endl;
    } else {
        cout << "No" <<endl;
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