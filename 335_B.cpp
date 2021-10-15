#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int n;
string x;
int TS[28];
int memo[2610][2610];
string y = "";
string z = "";
int solve(int i , int j )
{
	if(i > j)
	{
		return 0;
	}
	if(memo[i][j] != -1)
	{
		return memo[i][j] ;
	}
	int Cur = -1;
	if(x[i] == x[j])
	{
		if(i != j)
		{
			Cur = max(Cur ,solve(i + 1 , j - 1) + 2);
		}
		else
		{
			Cur = max(Cur ,solve(i + 1 , j - 1) + 1);
		}
	}
	else
	{
		Cur = max(Cur ,solve(i + 1 , j));
		Cur = max(Cur ,solve(i , j - 1));
	}
	return memo[i][j] = Cur ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("335_B.inp","r",stdin);
	freopen("335_B.out","w",stdout);

	cin >> x;
	n = x.size();
	x = " " + x;
	for(int i = 1 ;  i <= n ; i ++)
	{
		TS[x[i] - 'a' + 1] ++;
		if(TS[x[i] - 'a' + 1] >= 100)
		{
			for(int j = 1 ; j <= 100 ; j ++) 
			{
				cout << x[i];
			}
			return 0;
		}
	}
	memset(memo , -1 , sizeof(memo));
	//cout << solve(1 , n) << endl; 

	int l = 1 , r = n;

	while(r >= l)
	{
		//cout << l <<" " << r << endl;
		if(x[l] == x[r])
		{
			if(l != r)
			{
				if(solve(l+1,r-1) + 2 == solve(l,r))
				{
					y = y + x[l];
					z = x[r] + z;
					l ++;
					r --;
				}
			}
			else
			{
				if(solve(l+1,r-1) + 1 == solve(l,r))
				{
					y = y + x[l];
					l ++;
					r --;
				}
			}
		}
		else
		{
			if(solve(l+1,r) == solve(l,r))
			{
				l ++;
			}
			else
			{
				if(solve(l,r-1) == solve(l,r))
				{
					r --;
				}
			}
		}
	}
	//cout << y <<" " << z;
	if(solve(1 , n) >= 100)
	{
		for(int i = 0 ; i < 50 ; i ++)
		{
			cout << y[i];
		}
		for(int i = z.size() - 50 ; i < z.size() ; i ++)
		{
			cout << z[i];
		}
	}
	else
	{
		cout << y << z;
	}
	return 0;
}