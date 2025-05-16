#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin >> n;

    string str;
    str.resize(n);
    for(int i = 0; i < n; i++){
        cin >> str[i]; 
    }

    int ct1 = count(str.begin(), str.end(), '5');
    int ct2 = count(str.begin(), str.end(), '0'); 

    ct1 = ct1 - ct1 % 9; 

    string strnew = "";
    for(int i = 0; i < ct1 + ct2; i++){
        if(i < ct1){
            strnew += '5'; 
        }
        else{
            strnew += '0'; 
        }
    }

    if(ct2==0){
        strnew = "-1";
    }
    else if(ct1 == 0 && ct2 > 0){ 
        strnew = "0"; 
    }
    else if(ct1 == 0 && ct2 == 0){
        strnew = "-1";
    }

    cout << strnew << endl; 
    return 0;
}
