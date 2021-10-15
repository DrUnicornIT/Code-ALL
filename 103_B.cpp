#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int n , m ;
int Ans = 0;
int Ok[105];
vector<int> A[105];
int Tf[105];
void DFS(int u,int pa)
{
	//cout << u << "-" ;
	//cout << A[u].size()<<"pp"<< endl;
	for(int i = 0; i < A[u].size() ; i ++)
	{
		if(A[u][i] != pa && Ok[A[u][i]] != 2)
		{
			////cout << A[u][i] << "+";
			if(Ok[A[u][i]] == 0)
			{
				Ok[A[u][i]] = 1;
				DFS(A[u][i],u);
			}
			else
			{
				//Ok[A[u][i]] = 2;
				//cout << endl;
				//cout << pa <<"="<< u <<"="<< A[u][i]<<"/";
				Ans ++;
				//cout << endl;
			}
		}
		else
		{
			//cout << endl;
			//cout << A[u][i] <<"*" <<endl;
		}
	}
	Ok[u] = 2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("103_B.inp","r",stdin);
	freopen("103_B.out","w",stdout);

	cin >> n >> m;

	int u , v ;

	for(int i = 1 ; i <= m ; i ++)
	{		
		
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
		Tf[u] = 1;
		Tf[v] = 1;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		if(Tf[i] != 1)
		{
			cout <<"NO";
			exit(0);
		}
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		if(Ok[i] == 0)
		{
			//cout << i << endl;
			Ok[i] = 1;
			DFS(i,0);
		}
	}
	//cout << Ans;
	if(Ans == 1 )
	{
		cout << "FHTAGN!";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}