#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll res,sum,mid,l,r,n,k;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n >> k;
	vector<ll>a(n);
	
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	
	l=0,r=2e14;
	while(l<r)
	{
		mid = (l+r+1)/2;
		
		sum = 0;
		for(int i=0;i<n;i++)
		{
			sum += min(a[i], mid);
		}
		res = sum/mid;
		
		if(res>=k)
		{
			l = mid;
			 
		 }
		 else{
		 	r = mid - 1;
		 } 
	}
	cout << r;
	
	return 0;
}
