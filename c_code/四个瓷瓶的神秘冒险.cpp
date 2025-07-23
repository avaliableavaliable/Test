#include<bits/stdc++.h>
using namespace std;

long long a[4],b[4];

int main(){
    for (int i = 0; i < 4; i ++) {
        cin >> a[i];
    }
    sort(a, a+4);
    long long ans, x;
    ans = a[3]+a[0]*2;
    
    for(int i=0; i<4; i++)
    {
    	for(int j=0; j<4; j++)
    	{
    		if(j!=i)
    		{
    			long long m1 = ans, m2 = ans;
    			for(int k=0; k<4; k++)
    			{
    				if(k!=i&&k!=j)
    				{
    					m1 = min(m1, a[k]);
					}
				}
				m2 = min(m1, a[j]);
				x = a[i] + m2*2;
				if(m1 >= m2)
				{
					m1 -= m2;// 0 m1 3-m1 a[i]+m2*2+m1
					x += m1/3*3;
					if(m1%3==2)
					{
						x += 1;
					}
				}
				ans = max(ans, x);
			}
		}
	}
    
    cout << ans << '\n';
    return 0;
}
