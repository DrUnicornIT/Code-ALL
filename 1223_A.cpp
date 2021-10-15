#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1223_A.inp","r",stdin);
	freopen("1223_A.out","w",stdout);

	cin >> q;
	int n ;

	for(int i = 1 ; i <= q ; i++)
	{
		cin >> n ;
		if(n == 2)
		{
			cout << 2 << endl;
			continue;
		}
		if(n % 2 == 0)
		{
			cout << 0 << endl;
		}
		if(n % 2 == 1)
		{
			cout << 1 <<endl;
		}
	}

	return 0;
}