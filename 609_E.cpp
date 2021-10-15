#include <bits/stdc++.h>
#define int long long 
using namespace std ;
struct Tnode
{
	int u ,v ,w; 
	int id;
};
 
bool cmp(Tnode a , Tnode b)
{
	return a.w < b.w;
}
 
int n , m ;
 
Tnode A[200010];
int Ok[200010];
int Pa[200010];
int Val[200010];
int Anss[200010];
int DFS_save[200010];
int Ans = 0 ;
 
vector<int> MST[200010];
int Pa_MST[200010][20];
int W_MST[200010][20];
int h[200010];
 
int root(int u);
bool DSU(int x , int y);
void DFS(int u, int len);
int LCA(int x ,int y);
 
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);
 
 freopen("609_E.inp","r",stdin);
	freopen("609_E.out","w",stdout);
 
	cin >> n >> m ;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> A[i].u >> A[i].v >> A[i].w;
		A[i].id = i;
  	}
 	sort(A + 1 , A + 1 + m , cmp);
 	
 	for(int i = 1 ; i <= n ; i ++)
 	{
 		Pa[i] = i;
 		Val[i] = 1;
 	}
 	for(int i = 1 ; i <= m ; i ++)
 	{
 		if(DSU(A[i].u , A[i].v))
 		{
 			Ans += A[i].w;
 			MST[A[i].u].push_back(i);
 			MST[A[i].v].push_back(i);
 			Ok[i] = 1;
 		}
 	}
 	DFS_save[1] = 1;
 	DFS(1,1);
 
 	for(int j = 1 ; j <= 17 ; j ++)
 	{
 		for(int i = 1 ; i <= n ; i ++)
 		{
 			Pa_MST[i][j] = Pa_MST[Pa_MST[i][(j - 1)]][(j - 1)];
 			W_MST[i][j] = max(W_MST[i][j-1], W_MST[Pa_MST[i][j-1]][j-1]);
 		}
 	}
 	//cout << Ans << "+" << endl;
 	for(int i = 1; i <= m ; i ++)
 	{
 		if(Ok[i])
 		{
 			Anss[A[i].id] = Ans;
 		}	
 		else
 		{
 			Anss[A[i].id] = Ans + A[i].w - LCA(A[i].u, A[i].v);
 		}
 	}
 
 	for(int i = 1 ; i <= m ; i ++)
 	{
 		cout << Anss[i] << endl;
 	}
	return 0;
	
}
int root (int u)
{
	if(Pa[u] == u )
	{
		return u;
	}
	else
	{
		return  Pa[u] = root(Pa[k]);
	}
}
 
bool DSU(int x ,int y )
{
	x = root(x);
	y = root(y);
	if(x == y)
	{
		return 0;
	}
	if(Val[x] < Val[y])
	{
		swap(x,y);
	}
	Val[x] += Val[y];
	Pa[y] = x;
	return 1;
} 
void DFS(int u, int len)
{
	int v , w ,id;
 
	for(int i = 0 ; i < MST[u].size() ; i ++)
	{
 
		id = MST[u][i];
		if(A[id].u == u)
		{
			v = A[id].v;
		}
		else
		{
			v = A[id].u;
		}
		w = A[id].w;
 
		if(!DFS_save[v])
		{
			h[v] = len;
			Pa_MST[v][0] = u;
			W_MST[v][0] = w;
			DFS_save[v] = 1;
			DFS(v,len + 1);

		}
	}
}
int LCA(int x , int y)
{
	int Ress = 0;
	
	if(h[x] < h[y])
	{
		swap(x, y);
	}
	int u = x , v = y;
	for(int i = 17 ; i >= 0 ; i --)
	{
		if(h[Pa_MST[u][i]] >= h[v])
		{
			Ress = max(Ress , W_MST[u][i]);
			u = Pa_MST[u][i];
		}
	}	
	if(u == v)
	{
		return Ress ;
	}
	for(int i = 17 ; i >= 0 ; i --)
	{
		if(Pa_MST[u][i] != Pa_MST[v][i])
		{
			Ress = max(Ress , max(W_MST[u][i] , W_MST[v][i]));
			u = Pa_MST[u][i];
			v = Pa_MST[v][i];
		}
	}
	Ress = max(Ress, max(W_MST[u][0] , W_MST[v][0]) );	
	return Ress;
}