#include <bits/stdc++.h>
#define int long long 
using namespace std ;

int t;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1238_A.inp","r",stdin);
	freopen("1238_A.out","w",stdout);

	cin >> t;
	int  x, y;
	for(int i =1 ; i <= t ; i ++)
	{
		cin >> x >> y;
		//cout << x - y << endl;
		if(x - y == 1)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" <<endl;
		}
	}
	return 0;
}
