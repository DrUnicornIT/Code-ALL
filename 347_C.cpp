#include <bits/stdc++.h>
#define int long long 
#define ii pair < int , int >
using namespace std ;
const int oo = 1e18;

int n , m ;
vector<ii> D;
char a[1010][1010];
int memo[1010][1010] ;
string X = "IMAD";

int solve(int i, int j,int tt)
{
	//cout << i <<" "  << j << " " <<tt << endl;
	if(memo[i][j] != -1)
	{
		return memo[i][j];
	}
	memo[i][j] = oo; // danh dau nho tam 
	int Cur = 0;
	if(i > 1 && a[i-1][j] == X[tt])
	{
		Cur = max(Cur , solve(i - 1, j, (tt + 1) % 4 ));
	}
	if(i < n  && a[i+1][j] == X[tt])
	{
		Cur = max(Cur , solve(i + 1, j, (tt + 1) % 4 ));
	}
	if(j > 1 && a[i][j-1] == X[tt])
	{
		Cur = max(Cur , solve(i, j - 1, (tt + 1) % 4 ));
	}
	if(j < m && a[i][j+1] == X[tt])
	{
		//cout << "." << endl;
		Cur = max(Cur , solve(i , j + 1, (tt + 1) % 4 ));
	}
	memo[i][j] = min(oo , Cur + 1); // gan gia tri khi giat ve 

	return memo[i][j];
}
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("347_C.inp","r",stdin);
	freopen("347_C.out","w",stdout);

	cin >> n >> m ;

	memset(memo , -1 , sizeof(memo));
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			cin >> a[i][j];
			if(a[i][j] == 'D')
			{
				D.push_back(ii(i,j));
			}
		}
	}
	int u , v;
	int Maxx = 0;
	for(int i = 0 ; i < D.size() ; i ++)
	{
		u = D[i].first;
		v = D[i].second;
		//cout << u <<"-" << v << endl; 
		Maxx = max(Maxx , solve(u,v,0) );
	}
	//cout << Maxx << endl;
	if(Maxx >= oo)
	{
		cout << "Poor Inna!";
		exit(0);
	}
	Maxx /= 4;
	if(Maxx == 0)
	{
		cout << "Poor Dima!" ;
		exit(0);
	}
	cout << Maxx;
	
	return 0;
}