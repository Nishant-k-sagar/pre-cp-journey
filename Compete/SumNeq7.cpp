#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int v[n];
        for(int i = 0;i<n;i++){
	        cin >> v[i];
	    }

        if(n==4){
            if(v[0]+v[1]!=v[2]+v[3]){
                cout<<"YES"<<endl;
            }
            else{
            cout<<"NO"<<endl;
            }
        }
        else{
            bool alleq = true;
            int temp=v[0];
            for(int i = 1;i<n;i++){
                if(v[i] != temp ){
                    alleq = false;
                    break;
                }
            }
            if(alleq){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}