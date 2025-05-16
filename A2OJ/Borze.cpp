#include<bits/stdc++.h>
using namespace std;

int main(){
    char a[200];
    cin.getline(a,200);

    vector<int> v;
    for(int i=0; i<200; ++i){
        if(a[i] == '.'){
            v.push_back(0);
        }

        else if(a[i] == '-'){
            if(a[i+1]=='-'){
                v.push_back(2);
                ++i;
                continue;
            }
        else if(a[i+1] = '.')
            {
                v.push_back(1);
                ++i;
                continue;
            }
        }
    }
    for(auto it :v){
        cout<<it;
    }
    cout<<endl;

    return 0;
}