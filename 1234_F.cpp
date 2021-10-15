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

void TIME();

string x;
int Dp[(1 << 20) + 5];
int Ok[22];

int slbit(int mask)
{
	return __builtin_popcount(mask);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1234.inp","r",stdin);
	freopen("1234.out","w",stdout);

	cin >> x;
	//cout << (1 << 20) + 5 ;
	for(int i = 0 ; i < x.size() ; i ++)
	{
		memset(Ok, 0 , sizeof(Ok));
		int mask = 0;
		for(int j = i ; j < x.size() ; j ++)
		{
			if(!Ok[x[j] - 'a'])
			{
				Ok[x[j] - 'a'] = 1;
			}
			else
			{
				//cout << j << "++" << endl;
				break;
			}
			mask |= (1 << (x[j] - 'a'));
			Dp[mask] = slbit(mask);
		}
	}


	// for(int i = 1 ; i < (1 << 4) ; i ++)
	// {
	// 	cout << i << " " << Dp[i] << endl;
	// }
	for(int i = 0 ; i < (1 << 20) ; i ++)
	{
		for(int j = 0 ; j < 20 ; j ++)
		{
			if(i & (1 << j))
			{
				Dp[i] = max(Dp[i], Dp[i ^ (1 << j)]);
			}
		}
	}
	int Ans = 0;
	for(int i = 0 ; i < (1 << 20) ; i ++)
	{
		if(Dp[i] == slbit(i))
		{
			int re_mask = 0;
			for(int j = 0 ; j < 20 ; j ++)
			{
				if(i & (1 << j))
				{
					re_mask = re_mask;
				}
				else
				{
					re_mask |= (1 << j);
				}
			}
			//cout << i << " " << re_mask << endl;
			Ans = max(Ans, Dp[i] + Dp[re_mask]);
		}
	}
	cout << Ans;	
	TIME();
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}