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

    string s;
    cin>>s;

    map<char, int> mp;

    for(int i=0; i<n; i++){
        mp[s[i]]++;
    }

    if(n == 1){
        cout<<"YES"<<endl;
        return;
    }
    int flag = false;
    for(auto it : mp){
        if(it.second >=2){
            flag = true;
        }
    }

    if(flag){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}

int main()
{
    fast
        ll t =1 ;
    // cin >> t;
    while (t--)
    {
        nottryingenouf();
    }
}