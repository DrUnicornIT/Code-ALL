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

int T, n;
char x[200010];
char y[200010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1234.inp","r",stdin);
	freopen("1234.out","w",stdout);

	cin >> T;
	while(T)
	{
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> x[i];
		}
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> y[i];
		}
		bool ud = 0, tf = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			if(x[i] - '0' <= 2 && ud == 0)
			{
				continue;
			}
			if(y[i] - '0' <=2 && ud == 1)
			{
				continue;
			}
			if(x[i] - '0' >= 3 && y[i] - '0' >= 3)
			{
				ud = !ud;
				continue;
			}
			tf = 1;
			break;
		}
		if(tf == 1)
		{
			cout << "NO" << '\n';
			T --;
			continue;
		}
		if(ud == 1)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}

		T --;
	}

	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}