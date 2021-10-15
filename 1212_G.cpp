#include <bits/stdc++.h>
#define int long long 
#define ii pair<int, int>
#define jj pair<int, pair< int , int > >
#define f first
#define s second
using namespace std ;

int n, m;
vector<jj> A;
vector<ii> B;

int Ress = 0;
int Pa[200010];
int Val[200010];
int Ans[200010];
int root(int u)
{
	if(Pa[u] == u)
	{
		return u;
	}
	else
	{
		return root(Pa[u]);
	}
}
int Tinh(int a)
{
	return a * (a - 1) / 2;
}
void DSU(int x ,int y)
{
	x = root(x);
	y = root(y);
	if(x == y)
	{
		return ;
	}
	if(Val[x] < Val[y])
	{
		swap(x,y);
	}
	Ress -= (Tinh(Val[x]) + Tinh(Val[y]));
	Val[x] += Val[y];
	Pa[y] = x;
	Ress += Tinh(Val[x]);

}
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1212_G.inp","r",stdin);
	freopen("1212_G.out","w",stdout);

	cin >> n >> m;
	int u , v ,w;

	for(int i = 1 ; i <= n ; i ++)
	{
		Val[i] = 1;
		Pa[i] = i;
	}
	for(int i = 1 ; i <= n - 1 ; i ++)
	{
		cin >> u >> v >> w;
		A.push_back(jj(w ,ii(u , v)));
	}
	int p;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >>p;
		B.push_back(ii(p,i)); 
	}
	sort(A.begin(),A.end());
	sort(B.begin(), B.end());
	int id = 0;

	for(int i = 0 ; i < B.size() ; i ++)
	{
		while(id < A.size() && A[id].f <= B[i].f)
		{
			DSU(A[id].s.f , A[id].s.s);
			id ++;
		}
		Ans[B[i].s] = Ress; 
	}
	for(int i = 1 ; i <= m ; i ++)
	{
		cout << Ans[i] <<" ";
	}
	return 0;
}