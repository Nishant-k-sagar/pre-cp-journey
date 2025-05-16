#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void codewithlove()
{
    int n, a, b;
    cin >> n >> a >> b;
    if(abs(a-b)%2){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        codewithlove();
    }

    return 0;
}
