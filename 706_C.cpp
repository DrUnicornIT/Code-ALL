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
const int oo = 1e18;
void TIME();

int n;
string x[100002];
bool KhanhLoz[100002][6];
int C[100002];
int memo[100002][2];
int solve(int i, bool tt)
{
    if(i == n+1)
    {
        return 0;
    }
    if(memo[i][tt] != -1) return memo[i][tt];
    int Cur = oo;
    bool OP = 0;
    if(!tt)
    {
        if(KhanhLoz[i][1]) {Cur = min(Cur , solve(i+1,0)); OP = 1;}
        if(KhanhLoz[i][3]) {Cur = min(Cur , solve(i+1,1)+C[i]); OP = 1;}
        if(!OP)
        {
            return oo;
        }
    }
    else
    {
        if(KhanhLoz[i][2]) {Cur = min(Cur , solve(i+1,0)); OP = 1;}
        if(KhanhLoz[i][4]) {Cur = min(Cur , solve(i+1,1)+C[i]); OP = 1;}
        if(!OP)
        {
            return oo;
        }
    }
    return memo[i][tt] = Cur;
}
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("706_C.inp","r",stdin);
	// freopen("706_C.inp","w",stdout);
	freopen("706_C.out","w",stdout);

    cin >> n;
    int Res = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> C[i];
        Res += C[i];
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> x[i];
    }
    for(int i = 2 ; i <= n ; i ++)
    {
        int szR = x[i].size();
        int szL = x[i-1].size();


        bool tf1 = 0,tf2 = 0,tf3 = 0,tf4 = 0;
        for(int j = 0 ; j < min(szR,szL) ; j ++)
        {
            if(!tf1 && x[i][j] > x[i-1][j])
            {
                KhanhLoz[i][1] = 1;
                tf1=1;
                // break;
            }
            if(!tf1 && x[i][j] < x[i-1][j])
            {
                KhanhLoz[i][1] = 0;
                tf1 = 1;
                // break;
            }
            if(!tf2 && x[i][j] > x[i-1][szL-j-1])
            {
                KhanhLoz[i][2] = 1;
                tf2=1;
                // break;
            }
            if(!tf2 && x[i][j] < x[i-1][szL-j-1])
            {
                KhanhLoz[i][2] = 0;
                tf2 = 1;
                // break;
            }
            if(!tf3 && x[i][szR-j-1] > x[i-1][j])
            {
                KhanhLoz[i][3] = 1;
                tf3=1;
                // break;
            }
            if(!tf3 && x[i][szR-j-1] < x[i-1][j])
            {
                KhanhLoz[i][3] = 0;
                tf3 = 1;
                // break;
            }
            if(!tf4 && x[i][szR-j-1] > x[i-1][szL-j-1])
            {
                KhanhLoz[i][4] = 1;
                tf4=1;
                // break;Res
            }
            if(!tf4 && x[i][szR-j-1] < x[i-1][szL-j-1])
            {
                KhanhLoz[i][4] = 0;
                tf4 = 1;
                // break;
            }
            if(tf1 && tf2 && tf3 && tf4)
            {
                break;
            }
        }

        //cout<< i<<endl;
        bool KL = tf1 | tf2 | tf3 | tf4;
        if(!tf1) {if(szR < szL && !KL) {cout << -1; exit(0);} else {KhanhLoz[i][1] = 1; KL = 1;}}
        if(!tf2) {if(szR < szL && !KL) {cout << -1; exit(0);} else {KhanhLoz[i][2] = 1; KL = 1;}}
        if(!tf3) {if(szR < szL && !KL) {cout << -1; exit(0);} else {KhanhLoz[i][3] = 1; KL = 1;}}
        if(!tf4) {if(szR < szL && !KL) {cout << -1; exit(0);} else {KhanhLoz[i][4] = 1; KL = 1;}}
    }
//    for(int i = 2 ; i <= n ; i ++)
//    {
//        cout << KhanhLoz[i][1] <<" " <<KhanhLoz[i][2] <<" " <<KhanhLoz[i][3] <<" " <<KhanhLoz[i][4] << endl;
//    }

    memset(memo, -1, sizeof(memo));
    int OP;
    OP = min(solve(2,0) , solve(2,1) + C[1]);
    if(OP >= Res+1)
    {
        cout << -1;
    }
    else
    {
        cout << OP;
    }
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
