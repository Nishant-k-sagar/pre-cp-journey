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

    if(n==0){
        cout<<-1<<endl;
        return;
    }

    // vector<int> arr(n);
    if(n%2==0){
        for(int i=0; i<n; i++){
            if(i%2){
                cout<<-1<<" ";
            }
            else cout<<1<<endl;
        }
    }

    else {
        for(int i=0; i<n; i++){
            if(i==1){
                cout<<2<<endl;
            }
            else{
                if(i%2==0){
                    cout<<-1<<" ";
                }
                else cout<<1<<endl;
            }
        }
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