#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;

    int n = s.size();
    int hash[27];
    for(int i=0; i<n; i++){
        hash[s[i] - 'a']++;
    }

    int count = 0;

    for(int i=0; i<n; i++){
        bool flag = true;
        if((hash[s[i] - 'a']%2 == 1) ){
            count++;
            // flag = false;
            }
    }

    if(count %2 == 1)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}
