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

struct Tnode 
{
	int t1, t2, t3;	
} C[100010];

std::vector<int> A[100010];
int n;
int tree[100010];
int Ok[100010];

void Tre(int u , int id)
{
	//cout << u << endl;
	tree[id] = u;
	Ok[u] = 1;
	for(int i = 0 ; i < A[u].size() ; i ++)
	{
		if(Ok[A[u][i]] == 0)
		{
			Tre(A[u][i] , id + 1);
		}
	}
}
int Anss[100010];
vector<int> Mau;
std::vector<int> Cur;
void Tomau()
{
	int Ans = 1e18;
	int Res = 0;

	for(int i = 1; i <= n ; i ++)
	{
		if(i % 3 == 1)
		{
			Res += C[tree[i]].t1;
			Cur.push_back(1);
			continue;
		}	

		if(i % 3 == 2)
		{
			Res += C[tree[i]].t2;
			Cur.push_back(2);
			continue;
		}
		Res += C[tree[i]].t3;
		Cur.push_back(3);
	}

	if(Ans > Res)
	{
		Ans = Res;
		Mau.clear();
		Mau = Cur;
	}
	Cur.clear();
//	cout << Mau.size() << endl;
	Res = 0;

	for(int i = 1; i <= n ; i ++)
	{
		if(i % 3 == 1)
		{
			Res += C[tree[i]].t1;
			Cur.push_back(1);
			continue;
		}	

		if(i % 3 == 2)
		{
			Res += C[tree[i]].t3;
			Cur.push_back(3);
			continue;
		}
		Res += C[tree[i]].t2;
		Cur.push_back(2);
	}
//	cout << Mau.size() << endl;

	if(Ans > Res)
	{
		Ans = Res;
		Mau.clear();
		Mau = Cur;
	}
		Cur.clear();

	Res = 0;

	for(int i = 1; i <= n ; i ++)
	{
		if(i % 3 == 1)
		{
			Res += C[tree[i]].t2;
			Cur.push_back(2);
			continue;
		}	

		if(i % 3 == 2)
		{
			Res += C[tree[i]].t1;
			Cur.push_back(1);
			continue;
		}
		Res += C[tree[i]].t3;
		Cur.push_back(3);
	}
	//cout << Mau.size() << endl;

	if(Ans > Res)
	{
		Ans = Res;
		Mau.clear();
		Mau = Cur;
		
	}
	Cur.clear();
	Res = 0;

	for(int i = 1; i <= n ; i ++)
	{
		if(i % 3 == 1)
		{
			Res += C[tree[i]].t2;
			Cur.push_back(2);
			continue;
		}	

		if(i % 3 == 2)
		{
			Res += C[tree[i]].t3;
			Cur.push_back(3);
			continue;
		}
		Res += C[tree[i]].t1;
		Cur.push_back(1);
	}
	//cout << Mau.size() << endl;

	if(Ans > Res)
	{
		Ans = Res;
		Mau.clear();
		Mau = Cur;
	}
		Cur.clear();

	//cout << Mau.size() << endl;

	Res = 0;

	for(int i = 1; i <= n ; i ++)
	{
		if(i % 3 == 1)
		{
			Res += C[tree[i]].t3;
			Cur.push_back(3);
			continue;
		}	

		if(i % 3 == 2)
		{
			Res += C[tree[i]].t1;
			Cur.push_back(1);
			continue;
		}
		Res += C[tree[i]].t2;
		Cur.push_back(2);
	}
	//cout << Mau.size() << endl;

	if(Ans > Res)
	{
		Ans = Res;
		Mau.clear();
		Mau = Cur;
	}
		Cur.clear();

	Res = 0;

	for(int i = 1; i <= n ; i ++)
	{
		if(i % 3 == 1)
		{
			Res += C[tree[i]].t3;
			Cur.push_back(3);
			continue;
		}	

		if(i % 3 == 2)
		{
			Res += C[tree[i]].t2;
			Cur.push_back(2);
			continue;
		}
		Res += C[tree[i]].t1;
		Cur.push_back(1);
	}

	if(Ans > Res)
	{
		Ans = Res;
		Mau.clear();
		Mau = Cur;
	}
		Cur.clear();

	//cout << endl;
	cout << Ans << endl;
	//cout << Mau.size();
	for(int i = 1 ; i <= Mau.size() ; i ++)
	{
		Anss[tree[i]] = Mau[i-1];
	}
	for(int i = 1 ; i <= Mau.size() ; i ++)
	{
		cout << Anss[i] << " ";
	}
}
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1244.inp","r",stdin);
	freopen("1244.out","w",stdout);

	cin >> n ;
	for(int i = 1 ; i <= n; i ++)
	{
		cin >> C[i].t1;
	}
	for(int i = 1; i <= n ; i++)
	{
		cin >> C[i].t2;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> C[i].t3;
	}

	int u , v ;
	for(int i = 1; i <= n - 1; i ++)
	{
		cin >> u >> v ;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	int Maxx = 0;
	int ID;
	bool tf = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		Maxx = max(Maxx , (int)(A[i].size()));
		if(A[i].size() == 1 && tf == 0)
		{
			ID = i;
			tf = 1;
		}
	}
	if(Maxx + 1 > 3)
	{
		cout << -1 ;
		return 0;
	}
	else
	{
		////cout << ID;
		Tre(ID,1);
		Tomau();
	}

	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}