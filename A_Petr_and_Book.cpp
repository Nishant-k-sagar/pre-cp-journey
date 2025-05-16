#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    vector<int> v(7, 0);

    for(int i=0; i<7; i++){
        cin>>v[i];
    }
    
    for(int i=0; i<7; i++){
        if(n<=0){
            if(i!=0){
            cout<<i<<endl;
            break;}
            else
            cout<<7<<endl;
            break;
        }
        else if(n>=0 && i==6){
            n = n- v[i];
            i= -1;
        }
        else n = n - v[i];
    }
    
    return 0;
}