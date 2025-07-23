#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll b,p,k,tem,ans=1;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> b >> p >> k;
	tem = b;
	while(p)
	{
		if(p&1)ans=(ans*tem)%k;
		tem = (tem*tem)%k;
		p = p/2;
	}
	
	cout << ans;
	
	return 0;
}
