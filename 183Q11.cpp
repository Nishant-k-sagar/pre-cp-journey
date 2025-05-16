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

    if(n<=3){
        cout<<-1<<endl;
        return;
    }
    else {
        cout<<3*n-3<<endl;
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