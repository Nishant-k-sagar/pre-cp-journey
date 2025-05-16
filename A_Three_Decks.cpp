#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int a, b, c;
    cin>>a>>b>>c;

    int mini = min(a, min(b, c));

    a = a - mini;
    b = b-mini;
    c = c - mini;

    if((a+b+c)%3 == 0 && b<=(a+b+c)/3){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
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