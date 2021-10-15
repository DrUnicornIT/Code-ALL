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
    int r,g,b;
};

int a,b,c,n;
vector <int> Ok;
Tnode Cur;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	//freopen("777_C.inp","r",stdin);
	//freopen("777_C.out","w",stdout);

	cin>>a>>b>>c>>n;
    
    while(n >= 1)
    {
        Ok.push_back(n);
        if(n%3==2)
        {
            n/=3;
            n++;
            continue ;
        }
        n/=3;
    }

    reverse(Ok.begin(),Ok.end());

    Cur.r=a;
    Cur.g=b;
    Cur.b=c;
    for(int i=1;i<(int)Ok.size();i++)
    {
        int t=Ok[i-1]*3+1-Ok[i];
        Tnode Ok2=Cur;
        if(t==0)
        {
            Cur.r=Ok2.g;
            Cur.g=Ok2.r;
            Cur.b+=Ok2.r;
            continue ;
        }
        if(t==1)
        {
            Cur.r =Ok2.b;
            Cur.g +=Ok2.b;
            Cur.b = Ok2.r;
            continue ;
        }
        Cur.r += Ok2.g;
        Cur.g = Ok2.b;
        Cur.b = Ok2.g;
    }
    cout<<Cur.r<< " " << Cur.g << " " << Cur.b;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}