#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define f first
#define s second
using namespace std;
const int maxn = 1e6+5;
const int oo = 1e18;
struct Tnode
{
    int u, v, w;
};
int n, m, s;

vector <ii> Canh[maxn];
Tnode Canh_[maxn];

int dfs_st = 0;
int num[maxn], low[maxn];
stack <int> st;
int TPLT;
int ID[maxn];

int val[maxn];
vector <ii> nw_Canh[maxn];
int su[2000005];

int dfs(int u)
{
    dfs_st ++;
    num[u] = low[u] = dfs_st;
    st.push(u);
    for(int i = 0; i < Canh[u].size(); i ++) {
        int v = Canh[u][i].s;
        if(!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }
    if(low[u] == num[u])
    {
        TPLT ++;
        int v;
        do {
            v = st.top(); st.pop();
            ID[v] = TPLT;
            num[v] = low[v] = oo;
        }
        while(u != v);
    }
}
bool vis[maxn];
int Dp[maxn];
void DFS_DP(int u)
{
    // cout << u <<"_" << endl;
    vis[u] = 1;
    Dp[u] = 0;
    for(int i = 0; i < nw_Canh[u].size(); i ++) {
        int v = nw_Canh[u][i].s;
        int w = nw_Canh[u][i].f;
        if(!vis[v]) {
            // cout << v <<"+";
            DFS_DP(v);
        }
        Dp[u] = max(Dp[u], w + Dp[v]);
    }
    Dp[u] += val[u];
    // cout << Dp[u] << endl;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("894_E.inp", "r", stdin);
    freopen("894_E.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Canh_[i].u = u;
        Canh_[i].v = v;
        Canh_[i].w = w;

        Canh[u].push_back({w,v});
    }
    cin >> s;
    for(int i=1;i<2000000;++i)
		su[i]=su[i-1]+i*(i+1)/2;
    for(int i = 1;i <= n; i ++)
    {
        if(!num[i]) dfs(i);
    }
    // cout << TPLT << endl;
    for(int i = 1; i <= m; i ++)
    {
        int u, v, w;
        u = Canh_[i].u;
        v = Canh_[i].v;
        w = Canh_[i].w;
        if(ID[u] != ID[v]) {
            nw_Canh[ID[u]] .push_back({w, ID[v]});
            // cout << ID[u] << " " << ID[v] << " " << w << endl;
            // cout << w << endl;
        }
        else {
            int l=0,r=w;
			while(l<r)
			{
				int g=(l+r+1)>>1;
				if(g*(g+1)/2<=w) l=g; else r=g-1;
			}
			int rr=w*(l+1)-su[l];
			val[ID[u]]+=rr;
			// cout << val[ID[u]] << endl;
        }
    }
    // cout << endl;
    // cout << ID[1] <<" " << ID[2] <<" " << ID[3] << endl;
    DFS_DP(ID[s]);
    cout << Dp[ID[s]];
    return 0;
}
