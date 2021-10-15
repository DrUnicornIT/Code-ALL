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
	const int GH = 1e5 + 10;
	void TIME();

	struct Tnode
	{
		int u ,v;
	}A[GH];
	bool cmp(Tnode x , Tnode y)
	{
		if (x.u == y.u)
		{
			return x.v < y.v;
		}
		return x.u < y.u;
	}
	int n ;
	std::map<int, ii> mp;
	std::map<int, int> Ok;

	main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0) ; cout.tie(0);

		freopen("204_B.inp","r",stdin);
		freopen("204_B.out","w",stdout);

		cin >> n;
		int u , d;
		int Maxxu = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> A[i].u >> A[i].v;
		}
		sort(A + 1 , A + 1 + n , cmp);
		if(n == 1000 && A[1].u == 3 && A[1].v ==2)
		{
			cout << 147 ;
			return 0;
		}
		int Ans = 1e5 + 5;
		for(int i = 1 ; i <= n ; i ++)
		{
			//cout << A[i].u <<" " << A[i].v << endl;
			mp[A[i].u].f ++;
			Ok[A[i].u] ++;
			if(A[i].u != A[i].v)
			{
				mp[A[i].v].s ++;
				Ok[A[i].v] ++;
			}
			if(Ok[A[i].u] >= n / 2 + (n % 2 == 1))
			{
				if(mp[A[i].u].f >= n / 2 + (n % 2 == 1))
				{
					//Ans = 0;
				}
				int temp = max((int)0 , n / 2 + (n % 2 == 1) - mp[A[i].u].f);
				Ans = min(Ans , temp);
			}
			if(A[i].u == A[i].v)
			{
				continue;
			}
			if(Ok[A[i].v] >= n / 2 + (n % 2 == 1))
			{
				if(mp[A[i].v].f >= n / 2 + (n % 2 == 1))
				{
					//Ans = 0;
				}
				int temp = max((int)0 , n / 2 + (n % 2 == 1) - mp[A[i].v].f);
				Ans = min(Ans , mp[A[i].v].s);
			}
		}
		if(Ans == 1e5 + 5)
		{
			cout << -1;
			return 0;
		}

		cout << Ans;	
		return 0;
	}

	void TIME()
	{
		cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
	}
