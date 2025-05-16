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

    if(s[0] == 'B'){
        cout<<1<<endl;
        return;
    }

    int cntb = 0;
    int cntg = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'G'){
            cntg++;
        }
        else {
            cntb++;
        }

        if(cntb>2*cntg){
            cout<<cntg+cntb<<endl;
            return;
        }
    }
    cout<<cntg+cntb<<endl;
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