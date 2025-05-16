#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a[10];
        for(int i=0; i<10; ++i){
            cin>>a[i];
        }
        int sumodd=0;
        int sumeven=0;
        for(int i=0; i<10; ++i){
            if(i&1==1){
                sumeven += a[i];
            }

            else
            sumodd += a[i];
        }

        if(sumeven > sumodd){
            cout<<"2"<<endl;
        }
        else if
            (sumeven == sumodd){
                cout<<"0"<<endl;
            }

            else
            cout<<"1"<<endl;
        

    }
    return 0;
}