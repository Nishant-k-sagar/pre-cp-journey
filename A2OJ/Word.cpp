#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    getline(cin, str);

    int count1 = 0;
    int count2 = 0;

    for(char it : str){
        if(int(it)<=90){
            count1++;
        }
        else if(int(it)>=97){
            count2++;
        }
    }
    if(count1 <= count2){
    transform(str.begin(), str.end(), str.begin(), :: tolower);
    }
    else
    {
        transform(str.begin(), str.end(), str.begin(), :: toupper);
    }

    cout<<str;
    return 0;
}