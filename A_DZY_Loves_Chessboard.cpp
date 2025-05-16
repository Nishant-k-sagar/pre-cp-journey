#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin>>n>>m;

    char arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='.'){
            if((i+j)%2) arr[i][j] = 'W';
            else arr[i][j] = 'B';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}