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
#define int  long long 
#define ii pair<int, int>
#define jj pair<int, pair< int , int > >
#define f first
#define s second
using namespace std ;

void TIME();

struct Tnode
{
	int val, sl;
};

int n;
int T[100010];
int V[100010];
int S[100010];
Tnode last[100010];
void CNP(int i)
{
	//cout << i << "CNP" ;
	if(V[i] > S[n] - S[i-1])
	{
		return;
	}

	int l = i , r = n;
	int m ;
	while(r >= l)
	{	
		m = (l + r) / 2;
		if(S[m-1] - S[i-1] < V[i] && S[m] - S[i-1] >= V[i])
		{
			break;
		}
		if(S[m-1]-S[i-1] >= V[i])
		{
			r = m-1;
		}
		else
		{
			l = m+1;
		}
	}	
	//cout << m << "--";
	//cout << V[i] - (S[m-1] - S[i-1]) << endl;
	last[m].val +=  V[i] - (S[m-1] - S[i-1]);		
	last[m].sl ++;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("923_B.inp","r",stdin);
	freopen("923_B.out","w",stdout);

	cin >> n ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> V[i] ;
	} 
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> T[i];
		S[i] = S[i - 1] + T[i];
	}

	for(int i = 1 ; i <= n ; i ++)
	{
		CNP(i);
	}

	//cout << endl;
	for(int i = 1 ; i <= n ; i ++)
	{
		//cout << last[i].val <<" "<< last[i].sl << endl;
	}
	int xoa = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		xoa += last[i].sl;
		cout << (i - xoa)*T[i] + last[i].val << ' ';
	}
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
