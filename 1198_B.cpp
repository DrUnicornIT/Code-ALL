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
const int GH = 2 * (1e5 + 10);
void TIME();

int n ;
int A[GH];
int ID[GH];
int Maxx[GH];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1198_B.inp","r",stdin);
	freopen("1198_B.out","w",stdout);

	cin >> n ;
	for(int i = 1; i <= n ; i ++)
	{
		cin >> A[i]; 
	}
	int m;
	cin >> m;
	int tl;
	int x , y;
	for(int i = 1 ; i <= m ; i ++)
	{
		cin >> tl;
		if(tl == 1)
		{
			cin >> x >> y;
			A[x] = y;
			ID[x] = i;
		}
		else
		{
			cin >> x ;
			Maxx[i] = x;
		}
	}

	
	for(int i = m + 1 ; i >= 0 ;i --)
	{
		Maxx[i] = max(Maxx[i],Maxx[i+1]);
	}

	for(int i = 1 ; i <= n; i ++)
	{
		//cout << A[i]<< " " << ID[i] << " " << Maxx[ID[i]] <<endl;
		cout << max(A[i] , Maxx[ID[i]]) <<" " ;
	}

	//TIME();
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}