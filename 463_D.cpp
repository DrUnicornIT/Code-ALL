#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int n , k ;
int A[1010];
int DAG[1010][1010];
int memo[1010];
int solve(int u)
{
	if(memo[u] != -1)
	{
		return memo[u];
	}
	int Cur = 0;

	for(int i = 1 ; i <= n ; i ++)
	{
		if(DAG[u][i] == 1)
		{
			Cur = max(Cur , solve(i) + 1);
		}
	}
	return memo[u] = Cur ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("463_D.inp","r",stdin);
	freopen("463_D.out","w",stdout);

	cin >> n >> k ; 
	for(int i = 1 ; i <= k ; i ++)
	{
		for(int j = 1 ; j <= n ; j ++)
		{
			cin >> A[j];
		}
		for(int j = 1 ; j <= n ; j ++)
		{
			for(int o = j + 1 ; o <= n ; o ++)
			{
				if(DAG[A[j]][A[o]] == 0 && DAG[A[o]][A[j]] == 0)
				{
					DAG[A[j]][A[o]] = 1;
				}
				else
				{
					if(DAG[A[j]][A[o]] == 0)
					{
						DAG[A[j]][A[o]] = -1;
						DAG[A[o]][A[j]] = -1;
					}
				}
			}	
		}
	}

	// for(int i = 1 ;i <= n ; i ++)
	// {
	// 	for(int j =1 ; j <= n ; j ++)
	// 	{
	// 		cout << DAG[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int Anss = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		memset(memo , -1 , sizeof(memo));
		//cout << solve(i);
		Anss = max(Anss , solve(i));
	}
	cout << Anss + 1;

	return 0;
}