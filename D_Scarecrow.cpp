#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void codewithlove()
{
   int n, k, l;
   cin >> n >> k >> l;


   vector<int> arr(n);
   for(int i=0; i<n; i++){
    cin >> arr[i];
   }

//     for(int i=0; i<n; i++){
//     cout<< arr[i]<<" ";
//    }

   int track = 0;
   int pos = 0;

   for(int i=0; i<n; i++){
    while(arr[i]-pos-track<k){
        track++;
    }
    pos = arr[i]+k;
   }
   cout << track << endl;
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
