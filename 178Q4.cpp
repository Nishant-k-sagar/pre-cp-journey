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
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;
    
    for (int i = 0; i < n; i++) {
        mp[arr[i]] = i;
    }
    vector<int> res(n);
    int i = 0;
    
    while (i < n) {
        int val = arr[i];
        int last = mp[val];
        
        for (int j = i; j <= last; j++) {
            res[j] = val;
        }
        
        i = last + 1;
    }

    set<int> st;

    for (int i = 0; i<res.size(); i++) {
        st.insert(res[i]);
    }
    cout << st.size()<<endl;
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