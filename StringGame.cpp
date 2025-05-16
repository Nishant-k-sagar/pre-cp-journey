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

    int cnt0 = 0;
    int cnt1 = 0;

    for(char ch: s){

        if(ch == '0')cnt0++;
        else cnt1++;
    }

    int mini = min(cnt1, cnt0);

    cout<<(mini%2==1?"Zlatan":"Ramos")<<endl;
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