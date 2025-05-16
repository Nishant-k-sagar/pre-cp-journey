#include <bits/stdc++.h>
using namespace std;

#define V 5
int parent[V];


int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}


void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}


void kruskalMST(int cost[][V])
{
	int mincost = 0; 

	
	for (int i = 0; i < V; i++)
		parent[i] = i;

	
	int edge_count = 0;
	while (edge_count < V - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (find(i) != find(j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		edge_count++;
		mincost += min;
	}
	printf("\n Minimum cost= %d \n", mincost);
}

int main()
{
		 
	int cost[][V] = {
		{ 1, 2, 6 },
		{ 2, 3, 5 },
		{ 2,4,2},
		{ 3,4,8 },
		{5,1,7 },
	};

	
	kruskalMST(cost);

	return 0;
}
