#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void merge(int arr[], int n, int low, int mid, int high)
{
    int temp[n];
    int left = low, right = mid + 1;
    int i = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[i++] = arr[left++];
        }
        else
        {
            temp[i++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        temp[i++] = arr[left++];
    }

    while (right <= high)
    {
        temp[i++] = arr[right++];
    }

    for (int j = low; j <= high; j++)
    {
        arr[j] = temp[j - low];
    }
}

void mergeSort(int arr[], int n, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, n, low, mid);
    mergeSort(arr, n, mid + 1, high);
    merge(arr, n, low, mid, high);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    mergeSort(arr, n, 0, n - 1);
    cout << k << "\t smallest elements in the given array: \n";
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << k << "th smallest element in the given array: " << arr[k - 1] << endl;
    int res[k];
    for (int i = 0; i < k; i++)
        res[i] = arr[i];
    cout << "Resultant array: " << endl;
    for (auto &val : res)
        cout << val << " ";
    cout << endl;
}