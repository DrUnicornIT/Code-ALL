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
const int GH = 3 *(1e5) + 10;
void TIME();

int n; 
int A[GH];
std::map<int, ii > mp1;
int S[GH];
std::vector<int> Anss;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("331_A2.inp","r",stdin);
	freopen("331_A2.out","w",stdout);

	cin >> n ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> A[i];
		if(mp1[A[i]].f == 0)
		{
			mp1[A[i]].f = i;
		}
		mp1[A[i]].s = i;
		if(A[i] >= 0)
		{
			S[i] = S[i-1] + A[i];
		}
		else
		{
			S[i] = S[i-1];
		}
	}

	// for(int i = 1 ; i <= n ; i ++)
	// {
	// 	cout << mp1[A[i]].f  <<" " << mp1[A[i]].s << endl;
	// }
	int Ans = -1e18;
	int Ansl , Ansr;
	int l , r;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(mp1[A[i]].s == i)
		{
			continue;
		}
		l = mp1[A[i]].f;
		r = mp1[A[i]].s;
		//cout << S[r-1] - S[l] + A[r] + A[l] << endl;
		if(Ans < S[r-1] - S[l] + A[r] + A[l])
		{
			Ans = S[r-1] - S[l] + A[r] + A[l];
			Ansl = l; 
			Ansr = r;
		}
	}
	//cout << Ans;
	//cout << Ansl <<" "<< Ansr<<endl;
	for(int i = 1 ; i <= Ansl - 1 ; i ++)
	{
		Anss.push_back(i);
	}
	for(int i = Ansl+1 ; i <= Ansr-1; i ++)
	{
		if(A[i] < 0)
		{
			Anss.push_back(i);
		}
	}
	for(int i = Ansr + 1 ; i <= n ; i ++)
	{
		Anss.push_back(i);
	}
	//cout << endl;
	cout << Ans <<" "<< Anss.size() <<'\n';
	for(int i = 0 ; i < Anss.size() ; i ++)
	{
		cout << Anss[i] << " ";
	}
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}