#include<bits/stdc++.h>
using namespace std;


int main()
{
    int arr1[] = {2,3,1,3,2,4,6,7,9,2,19};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {2,1,4,3,9,6};
    int n1 = sizeof(arr2)/sizeof(arr2[0]);

    int hash[10000] = {0};

    for(int i = 0; i<n; i++)
    {
        hash[arr1[i]]++;
    }
    
    int index = 0;
    for (int i = 0; i < n1; ++i) {
        while (hash[arr2[i]] > 0) {
            arr1[index++] = arr2[i];
            hash[arr2[i]]--;
        }
    }

    for(int i = 0; i<10000; i++)
    {
        if(hash[i]>0)
        {
            arr1[index++] = i;
            hash[i]--;
        }
    }
    cout<<"The sorted array : ";
    for(int i = 0; i<n; i++) cout<<arr1[i]<<" ";
    cout<<endl;
}