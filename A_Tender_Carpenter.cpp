#include <bits/stdc++.h>
using namespace std;

void codewithlove()
{
    int n;
    cin >> n;
    vector<int> arr(n);
   
   for (int i = 0; i < n; i++) {
    cin >> arr[i];
   }

    int cnt = 0;
   for(int i = 0; i<n-1; i++){
    int a = arr[i];
    int b = arr[i+1];
    if((a<b && 2*a>b)||(b<a &&2*b>a)||(a==b)){
        cnt++;
    }
   }

   if(cnt){
    cout << "YES" << endl;
   }
   else{
    cout << "NO" << endl;
    }
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