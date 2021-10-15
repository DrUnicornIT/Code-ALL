#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int q;
string x , y;
int Ok[30];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("1223_B.inp","r",stdin);
	freopen("1223_B.out","w",stdout);

	cin >> q;
	for(int i = 1 ; i <= q ; i ++)
	{
		cin >> x >> y;
		bool tf = 0;
		memset(Ok , 0 , sizeof(Ok));
		for(int j = 0 ; j < x.size() ;j ++)
		{
			Ok[x[j] -'a'] = 1;
		}
		for(int j = 0 ; j < y.size() ; j ++)
		{
			if(Ok[y[j] -'a'] == 1)
			{
				tf = 1;
				break;
			}
		}
		if(tf == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO"<<endl;
		}
	}

	return 0;
}