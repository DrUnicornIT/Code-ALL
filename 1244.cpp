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
#define int long long 
#define ii pair<int, int>
#define jj pair<int, pair< int , int > >
#define f first
#define s second
using namespace std ;

int n ,k;
int A[100010];
map<int , int> mp;
void TIME();

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1244_A.inp","r",stdin);
	freopen("1244_A.out","w",stdout);

	cin >> n >> k;

	int Min ; 
	int Max ; 
	for(int i = 1 ; i<= n ; i ++)
	{
		cin >> A[i];
		Max = max(Max , A[i]);
		Min = min(Min , A[i]);
		mp[A[i]] ++;
	}
	if(Max - Min == 0)
	{
		cout << 0 ;
		return 0;
	}
	sort(A + 1 , A + 1 + n);

	int l = 1 ; 
	int r = n;
	int Sl = 0;
	int Sll ,  Slr;
	int Anss = 1e9;

	while(Sl <= k && l <= n && r >= 1 && l <= r )
	{
		while(A[l + 1] == A[l])
		{
			l ++;
		}
		while(A[r-1] == A[r])
		{
			r --;
		}
		// cout << l << " " << r << endl;
		// cout << Sl << endl;
		//cout << l << " " << r << endl;

		Min = A[l];
		Max = A[r];
		Sll = mp[Min];
		Slr = mp[Max];
		
		//cout << Min <<"-"<<Max << endl;
		Anss = min(Anss,Max -Min); 
		if(Anss == 0)
		{
			cout << 0 ;
			return 0;
		}
		
		// cout <<Sll <<"+"<<Slr<<endl;
		// cout << endl;

		if(Sll < Slr)
		{
			if(Sl + Sll*(A[l+1] - A[l]) <= k)
			{
				Sl += Sll*(A[l+1] - A[l]);
				mp[A[l+1]] += mp[A[l]];
				Anss = min(Anss,Max - A[l + 1]); 
				l ++;
				while(A[l + 1] == A[l])
				{
					l ++;
				}
				continue;
			}
			else
			{
				cout << Max - (Min + (k - Sl) / Sll) ;
				return 0;
			}
		}
		else
		{
			if(Sl + Slr*(A[r] - A[r-1]) <= k)
			{
				Sl += Slr*(A[r] - A[r-1]);
				mp[A[r-1]] += mp[A[r]];
				Anss = min(Anss,A[r-1] - Min); 
				r --;
				while(A[r-1] == A[r])
				{
					r --;
				}
				continue;
			}
			else
			{
				cout << Max - ((k - Sl) / Slr) - Min ;
				return 0;
			}
		}
	}
	cout << Anss;
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}