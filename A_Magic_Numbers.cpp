#include<bits/stdc++.h>
using namespace std;

int main() {   
    string n;
    cin >> n;

    bool flag = true;
    int count4 = 0;
    
    for(char digit : n){
        if(n[0]=='4'){
            flag=false;
            break;
        }
        else if(digit == '4'){
            count4++;
           
            if(count4 > 2){
                flag = false;
                break;
            }
        } else if(digit == '1'){
            count4 = 0;
        } else {

            flag = false;
            break;
        }
    }

    if(flag){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
