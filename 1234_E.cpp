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
int A[200010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("main.inp","r",stdin);
	freopen("main.out","w",stdout);

	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> A[i];
	}
	int u, v;
	for(int i = 1 ; i <= m ; i ++)
	{
		u = A[i];
		v = A[i+1];
		
	}

	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}