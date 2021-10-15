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
const int GH = 3 * (1e5) + 10;
void TIME();
struct Tnode
{
	int t , b;
};
bool cmp(Tnode x ,Tnode y)
{
	if(x . b == y .b)
	{
		return x.t < y. t;
	}
	return x . b < y . b;
}

int n , k ;
Tnode A[GH];
priority_queue <int ,vector<int>, greater<int> > pq;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1140_C.inp","r",stdin);
	freopen("1140_C.out","w",stdout);

	cin >> n >> k;

	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> A[i].t >> A[i].b;
	}
	sort(A + 1 , A + 1 + n , cmp);

	int Ans = 0;
	int Summax = 0;
	for(int i = n ; i >= 1 ; i --)
	{
		//cout << A[i].t <<" "<<A[i].b << endl;
		if(pq.size() < k)
		{
			//cout << "." << endl;
			pq.push(A[i].t);
			Summax += A[i].t;
			Ans = max(Ans , Summax * A[i].b);
			continue;
		}
		if(pq.size() == k)
		{
			if(A[i].t > pq.top())
			{
				Summax -= pq.top();
				Summax += A[i].t;
				pq.pop();
				pq.push(A[i].t);
				Ans = max(Ans , Summax * A[i].b);
			}
		}
	}
	cout << Ans;
	//TIME();
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
