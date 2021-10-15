#include <bits/stdc++.h>
 
using namespace std;
 
const int maxN = 2e5 + 5;
 
int par[maxN], d[maxN], pr[maxN][18], w[maxN][18];
bool ch[maxN], tr[maxN];
long long res[maxN];
vector<int> p[maxN];
 
struct edge {int u, v, w, in;} e[maxN];
 
bool operator < (edge x, edge y) {return x.w < y.w;}
 
int rt(int k) {return par[k] == 0 ? k : (par[k] = rt(par[k]));}
 
bool mrg(int u, int v)
{
    if ((u = rt(u)) == (v = rt(v))) return false;
    par[v] = u;
    return true;
}
 
void dfs(int u, int dth)
{
    for (int i: p[u])
    {
        int v = e[i].u != u ? e[i].u : e[i].v;
        if (tr[v]) continue;
        tr[v] = true;
        d[v] = dth;
        pr[v][0] = u;
        w[v][0] = e[i].w;
        dfs(v, dth + 1);
    }
}
 
int lca(int u, int v)
{
    int cur = 0;
    if (d[u] < d[v]) swap(u, v);
    for (int i = 17; i >= 0; --i)
        if (d[pr[u][i]] >= d[v])
        {
            cur = max(cur, w[u][i]);
            u = pr[u][i];
        }
	cout << cur << "m" << endl;
    if (u == v) return cur;
    for (int i = 17; i >= 0; --i)
        if (pr[u][i] != pr[v][i])
        {
            cur = max(cur, max(w[u][i], w[v][i]));
            u = pr[u][i];
            v = pr[v][i];
        }
	cout << cur << "m" << endl;
    cur = max(cur, max(w[u][0], w[v][0]));
	cout << cur << "m" << endl;
    return cur;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].in = i;
    }
    sort(e, e + m);
    long long ans = 0;
    for (int i = 0; i < m; ++i)
        if (mrg(e[i].u, e[i].v))
        {
            ch[i] = true;
            ans += e[i].w;
            p[e[i].u].push_back(i);
            p[e[i].v].push_back(i);
        }
    tr[1] = true;
    dfs(1, 1);
    for (int j = 1; j < 18; ++j)
        for (int i = 1; i <= n; ++i)
        {
            pr[i][j] = pr[pr[i][j - 1]][j - 1];
            w[i][j] = max(w[i][j - 1], w[pr[i][j - 1]][j - 1]);
        }
    for (int i = 0; i < m; ++i)
    {
        if (ch[i])
        {
            res[e[i].in] = ans;
            continue;
        }
		cout << e[i].in << endl;
		cout << e[i].w << "-" << lca(e[i].v, e[i].u) << endl;
        res[e[i].in] = ans + e[i].w - lca(e[i].v, e[i].u);
    }
    for (int i = 0; i < m; ++i) cout << res[i] << '\n';
    return 0;
}