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
    string s, t;

    cin>>s>>t;

    // int cnt1s = count(s.begin(), s.end(), '1');
    // int cnt1t = count(t.begin(), t.end(), '1');

    // // cout<<"cnt1s = " <<cnt1s<<" ";
    // // cout<<"cnt1t = " <<cnt1t<<" ";

    // if(cnt1s == 0){
    //     cout<<"No"<<endl;
    //     return;
    // }

    // if((cnt1s-cnt1t)%2 == 0){
    //     cout<<"Yes"<<endl;
    // }
    // else cout<<"No"<<endl;


    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] == '1' && s[i] != '1') {
            cout << "No"<<endl;
            return;
        }
        if (s[i] == '1' && t[i] == '0') {
            cnt++;
        }
    }

    if (cnt % 2 == 0) {
        cout << "Yes"<<endl;
    } else {
        cout << "No"<<endl;
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