#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

bool dfs(int pos, int val, vector<int> &brr, vector<bool> &marked, int y) {
    int m = brr.size();
    if (pos == m)
        {
            if(val == y){
                return true;
            }
            else return false;
        }

    for (int i = 0; i < m; i++) {


        // cout << "pos: " << pos << " val: " << val << " i: " << i << endl;
        if (!marked[i]) {
            marked[i] = true;
            if (dfs(pos + 1, val % brr[i], brr, marked, y))
                return true;
            marked[i] = false;
        }
    }
    return false;
}

bool chk(vector<int> &brr, int x, int y) {
    int m = brr.size();
    vector<bool> marked(m, false);
    return dfs(0, x, brr, marked, y);
}

void nottryingenouf() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> good, pref;

    for (int i = 0; i < n; i++) {
        pref.push_back(arr[i]);
        if (chk(pref, x, y)){
        // cout << "pref len " << (i + 1) << endl;
    
            good.push_back(i + 1);
        }
    }

    

    cout << good.size() << endl;
    for (auto it : good)
        cout << it << " ";
    cout << endl;
}

int main() {
    fast
    ll t;
    cin >> t;
    while (t--) {
        nottryingenouf();
    }
    return 0;
}
