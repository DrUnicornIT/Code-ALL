#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int q , n;
int Dp[300010];
int Ok[300010];
int a[300010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; //cout.tie(0);

	freopen("1223_D.inp","r",stdin);
	freopen("1223_D.out","w",stdout);

	cin >> q;
	for(int i = 1 ; i <= q ; i ++)
	{
		memset(Ok,0,sizeof(Ok));
		memset(Dp,0,sizeof(Dp));
		cin >> n ;
		int Ress = 0;
		for(int j = 1 ; j <= n ; j ++)
		{
			cin >> a[j];
			if(Ok[a[j]] == 0)
			{
				Ress ++;
				Ok[a[j]] ++;
			}
		}
		//cout << Ress <<"__";
		for(int j = 1 ; j <= n ; j ++)
		{
			if(a[j] > a[j-1] && Ok[a[j]] == 1)
			{
				Dp[j] = max(Dp[j] , Dp[j - 1] + 1);
				Ok[a[j]] --;
			}
			else
			{
				Dp[j] = max(Dp[j-1] , Dp[j] );
			}	
		}
		//cout << endl;
		for(int j = 1 ; j <= n ; j ++)
		{
			//cout << Dp[j] << " ";
		}
		//cout << endl;
		//cout << Ress <<" "<<Dp[n] << endl;
		cout << Ress - Dp[n] << endl;
	}
	return 0;
}