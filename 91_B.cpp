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
	int val , id;
};
bool cmp(Tnode x , Tnode y)
{
	return x.val < y.val;
} 

int n ;
Tnode A[GH] ;
int B[GH];
int Ans[GH];
int BIT[GH];
int BITmax[GH];

void update(int u)
{
	for(int i = u ; i <= n ; i += i & -i)
	{
		BIT[i] ++;
	}
}
void updatemax(int u , int val)
{
	for(int i = u ; i <= n ; i += i & -i)
	{
		BITmax[i] = max(BITmax[i] , val);
	}
}
int get(int u)
{
	int Res = 0;
	for(int i = u  ; i > 0; i -= i & -i)
	{
		Res += BIT[i];
	}
	return Res;
}
int getmax(int u)
{
	int Res = 0;
	for(int i = u ; i > 0 ; i -= i & -i)
	{
		Res = max(Res , BITmax[i]);
	}
	return Res;
}
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("91_B.inp","r",stdin);
	freopen("91_B.out","w",stdout);

	cin >> n ;

	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> A[i].val;
		A[i].id = i;
	}
	sort(A + 1 , A + 1 + n , cmp);
	
	int id = 0;
	int du = 0;
	for(int i = 1 ;i <= n ; i ++)
	{
		if(A[i].val > du)
		{
			id ++;
			du = A[i].val;
		}
		B[A[i].id] = id;
	}

	for(int i = 1 ; i <= n ; i ++)
	{
		//cout << B[i] << " ";
	}
	//cout << endl;
	for(int i = n ; i >= 1; i --)
	{
		// << i << "?";
		//cout << B[i] << "-";
		if(get(B[i]) == 0)
		{
			Ans[i] = -1 ;
		}
		else
		{
			//cout << getmax(B[i]-1);
			//cout << getmax(B[i]-1) << endl;
			if(getmax(B[i]-1) == 0)
			{
				Ans[i] = -1;
				continue;
			}

			Ans[i] = getmax(B[i]-1) - i - 1 ;
		}
		update(B[i]);
		updatemax(B[i],i);
		//cout << endl;
	}

	for(int i = 1 ; i <= n; i ++)
	{
		cout << Ans[i] <<" ";
	}
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
