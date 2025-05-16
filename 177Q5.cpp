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
        
        string stra, strb;
        cin >> stra >> strb;
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            if (stra[i] != strb[i]) {
                int start = i;
                while (i < n && stra[i] != strb[i]) i++;
                ans.push_back({1, start + 1, i});
            }
        }
        
        cout << ans.size() << endl;
        for (int j = 0; j < ans.size(); j++) {
            cout << ans[j][0] << " " << ans[j][1] << " " << ans[j][2] << endl;
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