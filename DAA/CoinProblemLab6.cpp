#include<bits/stdc++.h>
using namespace std;

//Greedy approach
//time complexity nlogn + n

int coinChange(vector<int>coins, int amount) {
    sort(coins.rbegin(), coins.rend()); 
    int count = 0;

    for (int i = 0; i < coins.size(); ++i) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }

    if(amount == 0) return count;
    else return -1;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount) << endl; 

    coins = {2};
    amount = 3;
    cout << coinChange(coins, amount) << endl; 

    coins = {1};
    amount = 0;
    cout << coinChange(coins, amount) << endl;  

    return 0;
}