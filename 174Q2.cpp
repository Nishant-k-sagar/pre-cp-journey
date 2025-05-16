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

    bool flag = true;
    for(int i=0; i<n; i++){
        if(s[i]!='z'){
            flag = false;
        }
    }

    if(flag){
        cout<<-1<<endl;
        return;
    }

    string str = "";
    for(int i = 0; i<n; i++){
        str += 'z';
    }

    cout<<str<<endl;
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