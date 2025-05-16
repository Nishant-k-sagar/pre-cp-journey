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

    if(n == 3){
        cout<< "1 2 3"<<endl;
    }

    cout<<n <<" "<< n-2<<endl;

    for(int i=0; i<n-4; i++){
        cout<<i<<endl;
    }

    cout<<n-4<<" "<<n-3 << endl;
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