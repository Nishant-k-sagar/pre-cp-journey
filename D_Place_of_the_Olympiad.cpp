#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    ll n, m, k;
    cin>>n>>m>>k;

    ll left = 0;
    ll right = m;


    while(left + 1 < right){
        ll x = left + (right-left)/2;

        if((m/(x+1)*x + (m % (x+1)))*n >=k ){
            right = x;
        }
        else {
            left = x;
        }
    }
    cout<<right<<endl;
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