#include <bits/stdc++.h>
#include <math.h>
using namespace std;
vector <int> arr;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//将十进制转化为任意进制 
//	int x, k;
//	cin >> x >> k;
//	while(x){
//		arr.push_back(x%k);
//		x /= k;
//	}
//	for(int i=arr.size()-1;i>=0;i--)
//	cout << arr[i];

//将任意进制转化为十进制 
	int x, k, n, i=0;
	cin >> x >> k;
	while(x){
		n += (x%10)*pow(k, i);
		x = x/10;
		i++;
	}
	cout << n; 
	return 0;
}
