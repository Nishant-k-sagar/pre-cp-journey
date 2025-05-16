#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder

    int x, y;
    cin>>x>>y;

    string str = "";

    int i=0;

    if(x<=y){

        while(x>0 && y>0){
            if(i%2!=0){
                str+='0';
                str+='1';
                x--;
            }
            else{
                str+='1';
                str+='0';
                y--;
            }
            i++;
        }

    }

    if(x>y){

        while(x>0 && y>0){
            if(i%2==0){
                str+='0';
                str+='1';
                x--;
            }
            else{
                str+='1';
                str+='0';
                y--;
            }
            i++;
        }
        
    }

    // while(x>0 && y>0 && x<=y){
    //     if(i%2!=0){
    //         str+='0';
    //         str+='1';
    //         x--;
    //     }
    //     else{
    //         str+='1';
    //         str+='0';
    //         y--;
    //     }
    //     i++;
    // }

    while(x>0){
        str+='0';
        str+='1';
        x--;
    }

    while(y>0){
        str+='1';
        str+='0';
        y--;
    }

    int cnt = 0;
    for(int i=0; i<str.size()-1; i++){
        if(str[i]!=str[i+1])cnt++;
    }

    cout<<cnt<<endl;
}

int main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        nottryingenouf();
    }
}
