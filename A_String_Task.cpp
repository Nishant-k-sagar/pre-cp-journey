#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    string snew = "";

    for(char c : s){
        if (c=='Y'||c=='y'||c =='e' || c =='i' || c =='o' || c =='u'|| c == 'a' || c =='E' || c =='I' || c =='O' || c =='U'|| c == 'A'){
            continue;
        }
        if(c < 95){
            c += 32;
        }
        snew += '.';
        snew += c;
    }

    cout << snew << endl;
    return 0;
}
