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

int n;
int A[200010];
vector <ii> Canh[200010];
int rmq[200010][20];
int pa[200010];
int d[200010];
int Ans[200010];

void DFS(int u, int rt, int sum )
{
    //cout << u << " " << sum << endl;
    d[u] = sum;
    int m = u;
    //cout <<u <<"_"<< d[u] << " " << A[u] <<endl;
    for(int i = 18 ; i >= 0 ; i --)
    {
        //cout <<i <<" " << d[rmq[m][i]] <<" "<<rmq[m][i] << "(" << endl;
        if(d[u] - d[rmq[m][i]] <= A[u])
        {
            //cout << ",,";
            m = rmq[m][i];
        }
    }

    int l, r;
    l = pa[u];
    r = pa[m];
    //cout << u <<"*" << l <<"*" << r << endl;
    Ans[l] ++;
    Ans[r] --;
    //cout <<"." << endl;
    for(int i = 0, v ; i < Canh[u].size() ; i ++)
    {
        v = Canh[u][i].s;
        //cout << u << endl;
        //cout << sum << "_" << endl;
        DFS(v,u,sum + Canh[u][i].f);
        Ans[u] += Ans[v];
    }
}
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("793_C.inp","r",stdin);
	// freopen("793_C.inp","w",stdout);
	freopen("793_C.out","w",stdout);

    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> A[i];
    }
    for(int i = 2, u, p ; i <= n ; i ++)
    {
        cin >> u >> p;
        pa[i] = u;
        Canh[u].push_back(ii(p,i));
    }

    for(int i = 1 ; i <= n ; i ++)
    {
        rmq[i][0] = pa[i];
    }
    for(int i = 1 ; 1 << i <= n ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
        {
            rmq[j][i] = rmq[rmq[j][i-1]][i-1];
        }
    }
    DFS(1,1,0);

    //cout << rmq[4][1] << "*" << endl;
//    for(int i = 1 ; i <= n ; i ++)
//    {
//        cout <<i <<" "<< d[i] << endl;
//    }
    for(int i = 1 ; i <= n ; i ++)
    {
        cout << Ans[i] <<" ";
    }
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
