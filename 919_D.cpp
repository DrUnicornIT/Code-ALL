#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int n , m;
string x;
int Ok[300010];
int Dp[300010][27];
std::vector<int> A[300010];
stack <int> Topo;

void TOPOsort(int u);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; //cout.tie(0);

	freopen("919_D.inp","r",stdin);
	freopen("919_D.out","w",stdout);

	cin >> n >> m ;
	cin >> x;
	x = " " + x;
	int u, v;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> u >> v;
		A[u].push_back(v);
	}

	for(int i = 1 ; i <= n ; i ++)
	{
		if(Ok[i] != 1)
		{
			TOPOsort(i);
		}
	}

	// for(int i = 0 ; i < Topo.size() ; i ++)
	// {
	// 	//cout << Topo[i] <<" ";
	// }
	// //cout << Topo.size() << endl;
	// //cout << endl;

	// for(int i = 1 ; i < x.size() ; i ++)
	// {
	// 	Dp[i][x[i] - 'a' + 1] = 1;
	// }
	////cout << Topo.size() << endl;
	//cout << endl;
	int id , op , new_id , new_op;
	while(!Topo.empty())
	{
		id = Topo.top();
		//cout << id << endl;
		// op = x[id] - 'a' + 1;
		Dp[id][x[id] -'a' + 1] = max(Dp[id][x[id] -'a' + 1] , 1);
		//cout << Dp[id][x[id] - 'a' + 1] << endl;
		// //cout << id <<" "<< op <<" "<< Dp[id][op] << endl;
		for(int i = 0 ; i < A[id].size() ; i ++)
		{
			for(int j = 1 ; j <= 26 ; j ++)
			{
				//cout << x[A[id][i]] << "-"<<endl;
				Dp[A[id][i]][j] = max(Dp[A[id][i]][j] , Dp[id][j] + (x[A[id][i]] - 'a' + 1 == j));
			}
		}
		Topo.pop();
	}

	for(int i = 1 ;i <= 26 ; i ++)
	{
		for(int j = 1; j <= n ; j ++)
		{
			//cout << Dp[j][i] << " ";
		}
		//cout << endl;
	}
	int Ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1; j <= 26 ; j ++)
		{
			Ans = max(Ans , Dp[i][j]);
		}
	}
	if(Ans == 0)
	{
		cout << -1;
	}
	else
	{
		cout << Ans;
	}
	return 0;
}
void TOPOsort(int u)
{
	int v;
	Ok[u] = 1;
	//cout << u << "-";
	for(int i = 0 ; i < A[u].size() ; i ++)
	{
		v = A[u][i];
		if(Ok[v] == 1)
		{
			cout << - 1;
			exit(0);
		}
		if(Ok[v] == 2)
		{
			continue;
		}
		TOPOsort(v);
	}
	Ok[u] = 2;
	Topo.push(u);
}	