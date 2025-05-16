#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n;
    cin>>n;

    vector<pair<int, int>> vec;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        vec.push_back({x, 1});
    }

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        vec.push_back({x, 0});
    }

    sort(vec.begin(), vec.end());


    int ans=  0;
    int cnt = 0;
    
    for(int i=0; i<vec.size(); i++){
        if(vec[i].second == 1){
            cnt++;
        }
        else cnt--;
        ans = max(ans, cnt);
    }

    cout<<ans<<endl;
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