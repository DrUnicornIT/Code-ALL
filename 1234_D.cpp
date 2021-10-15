/*
 ──────────────────────────────────────
 ─▄▄▄───────────▄▄▄▄▄▄▄────────────────
 █▀░▀█──────▄▀▀▀░░░░░░░▀▀▄▄────────────
 █░░░░█───▄▀░░░░░░░░░░░░░░░▀▄───────▄▄▄
 █▄░░░▀▄▄▀░░██░░░░░░░░░░░░░░▀█────█▀▀░█
 ─█░░░░█▀░░░▀░░░░░░░░██░░░░░░▀█─▄█░░░░█
 ─▀█░░▄█░░░░░░░▄▄▄░░░░▀░░░░░░░███░░░░█▀
 ──█▄░█░░░░░▄███████▄░░░░░░░░░█▀░░░░▄▀─
 ──▀█░█░░░░▄██████████░░░░░░░▄█░░░░▄▀──
 ───███░░░░███████████░░░░░░▄█░░░░█▀───
 ────█░░░░░██████████▀░░░░░░█░░░░█▀────
 ────█░░░░░░▀███████▀░░░░░░░█▄▄▄▀──────
 ────█░░░░░░░░▀▀▀▀░░░░░░░░░░░▀█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ──────────────────────────────────────
 */
#include <bits/stdc++.h>
#define LL long long 
#define ii pair<int, int>
#define jj pair<int, pair< int , int > >
#define f first
#define s second
using namespace std ;

void TIME();

int n, m;
string x;
int A[27];
int B[100010][27];
void update(int u, int id, int val)
{
	for(int i = u ; i <= n ; i += (i & -i))
	{
		B[i][id] += val;
	}
}

int gett(int u, int id)
{
	int Res = 0;
	for(int i = u ; i > 0 ; i -= (i & -i))
	{
		Res += B[i][id];
	}
	return Res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1234.inp","r",stdin);
	freopen("1234.out","w",stdout);

	cin >> x;
	n = x.size();
	x = " " + x;	
	int id;
	for(int i = 1 ;i <= n ; i ++)
	{
		id = x[i] - 'a' + 1;
		update(i,id,1);
	}
	cin >> m;
	int a,l,r;
	char b;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> a;
		if(a == 1)
		{
			cin >> l;
			cin >> b;
			swap(x[l],b);
			//cout << b <<" " << x[l] << endl;
			update(l,b - 'a' + 1,-1);
			update(l,x[l] - 'a' + 1, 1);
		}
		else
		{
			cin >> l >> r;
			int Ans = 0;
			for(int j = 1 ; j <= 26 ; j ++)
			{
				if(gett(r,j) - gett(l-1,j) != 0)
				{
					Ans ++;
				}
			}
			cout << Ans << '\n' ;
		}
	}
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}