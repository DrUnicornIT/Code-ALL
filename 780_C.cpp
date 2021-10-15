#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int n ;
vector<int> A[200010];
int B[200010];
int Ok[200010];
int Ans = 0 ;
void DFS(int u ,int Res , int Pa)
{
	//cout << u << " " << Res <<" " << Pa << endl;
	Ok[u] = 1;
	B[u] = Res;
	Ans = max(Ans , Res );
	int Cur = 0;
	for(int i = 0 ; i < A[u].size() ; i ++)
	{
		if(Ok[A[u][i]] == 0)
		{
			//cout << A[u][i] <<endl;
			Cur ++;
			if(Cur == Res )
			{
				Cur ++;
				if(Cur == Pa)
				{
					Cur ++;
				}
			}
			if(Cur == Pa )
			{
				Cur ++;
				if(Cur == Res)
				{
					Cur ++;
				}
			}
			DFS(A[u][i], Cur ,Res );
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("780_C.inp","r",stdin);
	freopen("780_C.out","w",stdout);

	cin >> n ;
	int x, y; 
	for(int i = 1 ; i <= n - 1 ; i ++)
	{
		cin >> x >> y;
		A[x].push_back(y);
		A[y].push_back(x);
	}

	DFS(1 , 1 , 0);
	cout << Ans << endl;
	for(int i = 1 ; i <= n ; i ++)
	{
		cout << B[i] << " ";
	}
	return 0;
}