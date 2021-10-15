#include <bits/stdc++.h>
#define int long long 
using namespace std ;

int q;
int n, r;
int a[100010];
int Ok[100010];
vector<int> b;
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1238_B.inp","r",stdin);
	freopen("1238_B.out","w",stdout);

	cin >> q;

	for(int o = 1 ; o <= q ; o ++)
	{
		b.clear();
		memset(Ok , 0 , sizeof(Ok));
		cin >> n >> r ;
		int Ress = 0;
		int Anss = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> a[i];
			if(Ok[a[i]] == 0)
			{
				b.push_back(a[i]);
				Ok[a[i]] = 1;
			}
		}
		sort(b.begin(), b.end());

		for(int i = b.size()-1 ; i >= 0 ; i --)
		{
			if(b[i] - Ress > 0)
			{
				Anss ++;
				Ress += r;
			}
		}
		cout << Anss << endl;
	}
	return 0;
}