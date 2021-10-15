#include <bits/stdc++.h>
#define int long long 
using namespace std ;
 
int n , m;
int a[100010];
int T[400010][22];
int ok[400010][22];
void build(int id, int l, int r)
{
	if(l == r)
	{
		//cout << a[l] <<"id" <<id<< endl; 
		for(int i = 0 ; i <= 20 ; i ++)
		{
			if((a[l] & (1 << i)) != 0)
			{
				////cout << i <<" ";
				T[id][i] ++;
			}
		}
		//cout << endl;
		return ;
	}
	int m = (l + r)/2;
	build(id * 2, l , m);
	build(id * 2 + 1 , m + 1 , r);
	 for(int i = 0 ; i <= 20 ; i ++)
	 {
	 	T[id][i] = T[id*2][i] + T[id*2+1][i];
	 }
}
void Lzzy(int id , int l  , int r,int x)
{

	if(!ok[id][x])
	{
		return ;
	}
	T[id][x] = (r -l + 1) - T[id][x];
	if(l != r)
	{
		ok[id*2][x] = !ok[id*2][x];
		ok[id*2+1][x] = !ok[id*2+1][x];
	}
	ok[id][x] = 0;
 
}
void Update(int id ,int l , int r, int u , int v ,int x,int val)
{
	Lzzy(id,l,r,x);
	if(r < u || v < l)
	{
		return ;
	}
	if(u <= l && r <= v)
	{
		if(val == 0) return;
		ok[id][x] = !ok[id][x];
		Lzzy(id,l,r,x);
		return;
	}
	int m = (l + r)/2;
	Update(id * 2 , l , m , u , v , x , val);
	Update(id * 2 + 1 , m + 1, r, u , v , x , val);
	for(int i = 0 ; i <= 20 ; i ++)
	{
		T[id][i] = T[id*2][i] + T[id*2+1][i];
	}
}
 
int get(int id,int l,int r,int u ,int v,int x)
{
	Lzzy(id,l,r,x);
	if(v < l || r < u)
	{
		return 0;
	}
	if(u <= l && r <= v)
	{
		return T[id][x];
	}
	int m = (l+r) / 2;
	return get(id * 2 , l , m , u , v ,x) + get(id * 2 + 1 , m + 1 , r , u , v , x);
}
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);
 
 	freopen("242_E.inp","r",stdin);
	freopen("242_E.out","w",stdout);
 
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
	}
	build(1,1,n);
	for(int i = 0 ; i <= 3 ; i ++)
	{
		for(int j = 1 ; j <= 9 ; j ++)
		{
			//cout << T[j][i] <<" ";
		}
		//cout << endl;
	}
	cin >> m;
	int tt, l, r, x;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> tt ;
		if(tt == 1)
		{
			cin >> l >> r;
			int Res = 0;
			for(int j = 0 ; j <= 20 ; j ++)
			{
				Res += get(1,1,n,l,r,j) * (1 << j);
			}
			cout << Res << endl;
		}
		if(tt == 2)
		{
			cin >> l >> r >> x;
			//cout << l <<' ' << r << ' ' << x << endl;
			for(int j = 0 ; j <= 20 ; j ++)
			{
				if((x & (1 << j)) != 0)
				{
					//cout << j << " ";
					Update(1,1,n,l,r,j,1);
				}
				else
				{
					Update(1,1,n,l,r,j,0);
				}

			}
			//cout << endl;
			for(int i = 0 ; i <= 3 ; i ++)
			{
				for(int j = 1 ; j <= 9 ; j ++)
				{
					//cout << T[j][i] <<" ";
				}
				//cout << endl;
			}		
		}
	}
	return 0;
}