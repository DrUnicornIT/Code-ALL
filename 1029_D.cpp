#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int n , k ;
int a[200010];
std::map<int , int > M;
std::map<int , int > TT;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("main.inp","r",stdin);
	freopen("main.out","w",stdout);

	cin >> n ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
		M[a[i]] = a[i] % k;
	}
	int Ress = 1;
	TT[0] = 1 % k;
	for(int i = 1 ; i <= 9 ; i ++)
	{
		Res *= 10;
		TT[i] = T[i-1] * (10 % k);
	}
	
	return 0;
}-