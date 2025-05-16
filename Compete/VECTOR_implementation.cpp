#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;
int main(){
    vector <int> v;
    for(int i=10; i<20; ++i){
        v.push_back(i);
    }

    for(auto it = v.begin(); it!=v.end(); ++it){
        cout<<*it<<" ";
    }
    
    
    return 0;
}