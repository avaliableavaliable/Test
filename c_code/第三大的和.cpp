//#include <bits/stdc++.h>
//#include <algorithm>
//using namespace std;
//int n, l, r, num=0, a[200000];
//int main(){
//  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//  
//  cin >> n >> l >> r;
//  for(int i=1;i<=n;i++)
//  {
//  	cin >> a[i];
//  }
//  
//  sort(a, a+n);
//  
//  int i=1,j=i+1,re;
//  while(i<j){
//  	re = a[i]+a[j];
//  	if(re < l)
//	  {
//	  	i++;
//	  	continue;
//	  }
//  	if(re > r)
//  	{
//  		j--;
//  		continue;
//	}
//	num++;
//	i++;
//
//  }
//  
//  cout << num;
//  
//  return 0;
//}
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
set<int> sum;
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, arr[N+1], t;
  cin >> n;
  for(int i=0;i<n;i++)
  cin >> arr[i];
  
  sort(arr, arr+n);
  for(int i=n-1;i>=2;i--)
  {
  for(int j=i-1;j>=1;j--)
  {
  	for(int k=j-1;k>=0;k--)
  	{
  		t = arr[i]+arr[j]+arr[k];
  		sum.insert(t);
	  }
  }
  }
  set<int>::iterator it=sum.end();
  it--;
  it--;
  it--;
  cout << *it;

  return 0;
}
