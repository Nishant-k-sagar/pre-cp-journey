#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n, k;

    cin>>n>>k;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> brr(n);
    for(int i=0; i<n; i++){
        cin>>brr[i];
    }

    ll moves = 0;
    int mincost = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        int diff = abs(arr[i] - brr[i]);
        int minMoves = min(diff, 9 - diff);
        moves += minMoves;
        mincost = min(mincost, abs(9 - 2 * minMoves));
    }
    
    ll rem = k - moves;
    if (rem < 0) {
        cout << "No" << endl;
        return;
    }
    if (rem % 2 == 0 || rem % 9 == 0 || mincost <= rem) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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
