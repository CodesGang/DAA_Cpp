//0-1 knapSack Problem using Dynamic Programming
#include <bits/stdc++.h>
using namespace std;


int max(int a, int b)
{
	return (a > b) ? a : b;
}


int knapSack(int W, int wt[], int p[], int n)
{
	int i, w;
	vector<vector<int>> K(n + 1, vector<int>(W + 1));

	
	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(p[i - 1] +
								K[i - 1][w - wt[i - 1]],
								K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}


int main()
{
	int p[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(p) / sizeof(p[0]);
	cout<< "0-1 Knapsack Problem :\n\n";
	cout<<"Max Profit : ";
	cout << knapSack(W, wt, p, n);
	
	return 0;
}


