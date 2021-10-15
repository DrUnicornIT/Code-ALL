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

		freopen("1234.inp","r",stdin);
		freopen("1234.out","w",stdout);

		cin >> n >> m;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> A[i];
		}	
		deque<int> Q;
		set<int> P;

		for(int i = 1 ; i <= n ; i ++)
		{
			if(Q.size() >= m)
			{
				if(!P.count(A[i]))
				{
					P.erase(Q.front());
					Q.pop_front();
					Q.push_back(A[i]);
					P.insert(A[i]);
					//cout << Q.front() <<"-"<< Q.back() << endl;
				}
			}
			else
			{
				if(!P.count(A[i]))
				{
					Q.push_back(A[i]);
					P.insert(A[i]);
				}
			}
		}
		
		cout << Q.size() << '\n';
		while(!Q.empty())
		{
			cout << Q.back() << " ";
			Q.pop_back();
		}
		return 0;	
	}

	void TIME()
	{
		cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
	}