#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 1; 
    cin >> t;

    while (t--) {
        string s;
        cin>>s;

        int n = s.length();
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i] == 'q')ans += 'p';
            else if(s[i] == 'p')ans+= 'q';
            else ans+='w';
        }
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;;
    }

    return 0;
}
