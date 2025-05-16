#include <bits/stdc++.h>
using namespace std;
int MM(int A[][], int B[][], int n){
        if (n <= 2)
        {
            C[1][1] = a[1][1] * b[1][1] + a[1][2] * b[2][1];
            C[1][2] = a[1][1] * b[1][2] + a[1][2] * b[2][2];
            C[2][1] = a[2][1] * b[1][1] + a[2][2] * b[2][1];
            C[2][2] = a[2][1] * b[1][2] + a[2][2] * b[2][2];
        }

        else
        {
            mid = n / 2;

            P = MM(A[1][1] + A[1][2], B[1][1] + B[2][2], n / 2);
            Q = MM(A[2][1] + A[2][2], B[1][1], n / 2);
            R = MM(A[1][1], B[1][2] - B[2][2], n / 2);
            S = MM(A[2][2], B[2][1] - B[1][1], n / 2);
            T = MM(A[1][1] + A[1][2], B[2][2], n / 2);
            U = MM(A[2][1] - A[1][1], B[11] + B[12], n / 2);
            V = MM(A[1][2] - A[2][2], B[2][1] - B[2][2], n / 2);
        }
    }
int main()
{
    int n = 16;
    int A[n][n];
    int B[n][n];

    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 16; j++)
        {
            int b = i + j;
            cin >> A[i][j];
        }
    }

    for (int i = 16; i > 0; --i)
    {
        for (int j = 0; j < 16; j++)
        {
            int c = 2 * i + 3 * j;
            cin >> B[i][j];
        }
    }

    

    C[1][1] = P + S - T + V;
    C[1][2] = R + T;
    C[2][1] = Q + S;
    C[2][2] = P + R - Q + U;

    for(int i=0; i<16; ++i){
        for(int j=0; j<16; ++j){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}