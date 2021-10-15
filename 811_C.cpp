	#include <bits/stdc++.h>
	#define LL long long 
	using namespace std ;

	int n ;
	int a[5010];
	int L[5010];
	int R[5010];
	int Ok[5010];
	int D[5010];
	int M[5010];
	int RDp[5010][5010];
	int LDp[5010][5010];
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0) ; //cout.tie(0);

		freopen("811_C.inp","r",stdin);
		freopen("811_C.out","w",stdout);

		cin >> n ;
		for(int i = 1; i <= n ; i ++)
		{
			cin >> a[i];
			if(Ok[a[i]] == 0)
			{
				L[a[i]] = i;
				Ok[a[i]] = 1;
			}
		}
		
		memset(Ok , 0 , sizeof(Ok));
		for(int i = n ; i >= 1; i --)
		{
			if(Ok[a[i]] == 0)
			{
				////cout << i << ' ';
				M[i] = 1;
				R[a[i]] = i;
				Ok[a[i]] = 1;
	 		}
		}
		////cout << endl;
		for(int i = 1 ; i <= n ; i ++)
		{
			////cout << i << "*" << endl;
			if(M[i] == 1)
			{
				////cout << i <<"="<< a[i] << " " << endl;
				memset(Ok , 0 , sizeof(Ok));
				int l , r;
				l = L[a[i]] ; 
				r = R[a[i]] ;
				int Cur = 0;
				bool tf = 0;
				//cout << i << endl;
				//cout << l <<"+"<< r << endl;
				int st = l;
				int ed = r;
				int new_st = 1e9;
				while(st <= ed)
				{
					if(R[a[st]] > r)
					{
						tf = 1;
						break;
					}
					new_st = min(L[a[st]] , new_st);
					if(st == ed)
					{
						if(new_st < L[a[st]])
						{
							ed = st - 1;
							st = new_st;
						}
					}
					st ++;
				}
				if(tf == 1)
				{
					D[i] = D[i-1];
					continue;
				}
				else
				{
					l = new_st;
					
					//cout << l << "-" << r << endl;
					for(int j = l ; j <= r ; j ++)
					{ 
						if(Ok[a[j]] == 0)
						{
							//if(L[a[j]] >= l && R[a[j]] <= r)
							{
								Cur ^= a[j];
								Ok[a[j]] = 1;
							}  	
						}
					}
					////cout << Cur <<"()"<< endl;
					D[r] = max(D[r-1] , Cur + D[l-1]); 
				}
			}
			else
			{
				D[i] = D[i-1];
			}
			////cout << D[i] <<"-"<< endl;
		}
		////cout << endl;
		cout << D[n];
		return 0;
	}