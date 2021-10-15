#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int n , s, l;

int A[100010];
int M[100010][17];
int N[100010][17];

int RMQmax(int i , int j)
{
	int log = log2(j - i + 1);
	if(A[M[i][log]] < A[M[j-(1 << log)][log]])
	{
		return M[j-(1 << log) + 1][log];
	}
	else
	{
		return M[i][log];
	}
}

int RMQmin(int i , int j)
{
	int log = log2(j - i + 1);
	if(A[N[i][log]] >= A[N[j-(1 << log)][log]])
	{
		return N[j-(1 << log) + 1][log];
	}
	else
	{
		return N[i][log];
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("main.inp","r",stdin);
	freopen("main.out","w",stdout);

	cin >> n >> s >> l;
	for(int  i = 1 ; i <= n ; i ++)
	{
		cin >> A[i];
	}

	for(int i = 1 ; i <= n ; i ++)
	{
		M[i][0] = i;
		N[i][0] = i;
	}

	for(int i = 1 ; 1 << i <= n ; i ++)
	{
		for(int j = 1 ; j + (1 << i) -1 <= n ; j ++)
		{
			if(A[M[j][i-1]] > A[M[j + (1 << (i - 1)) ][i - 1]] )
			{
				M[j][i] = M[j][i-1];
			}
			else
			{
				M[j][i] = M[j + (1 << (i - 1)) ][i - 1];
			}

			if(A[N[j][i-1]] < A[N[j + (1 << (i - 1)) ][i - 1]] )
			{
				N[j][i] = N[j][i-1];
			}
			else
			{
				N[j][i] = N[j + (1 << (i - 1)) ][i - 1];
			}
		}
	}

	RMQmax(i,j);
	RMQmin(i,j);
	
	int l = 0 ,r = n / l ;
	int m = (l + r) / 2;
	while(r - l >= 1)
	{
		if(Check(m) == 0)
		{
			
		}
	}
	return 0;	
}