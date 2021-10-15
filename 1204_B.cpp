#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int n ,l , r ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1204_B.inp","r",stdin);
	freopen("1204_B.out","w",stdout);

	cin >> n >> l >> r;
	int Cur = 0;
	int Res = 2;
	for(int i = 1 ; i <= l-1 ; i ++)
	{
		Cur += Res ;
		Res *= 2;
	}	
	int Cur1 = 0;
	int Res1 = 1;
	for(int i = 1 ; i <= r ; i ++)
	{
		Cur1 += Res1;
		Res1 *= 2; 
	}
	Res1 /= 2;
	cout << 1 * (n - l + 1) + Cur <<" "<< Cur1 + Res1 * (n - r);

	return 0;
}