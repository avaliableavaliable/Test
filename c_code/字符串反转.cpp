#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int main(){
	//字符串转数字 
//	string str;
//	int n=0;
//	cin >> str;
//	for(auto i:str)
//		{
//			n = n*10 + i-'0';
//		}
//	
//	cout << n;

// 数字转字符串
	int n;
	string str,s;
	cin >> n;
	//这一步取得的是反转的字符串 
	while(n){
		str +=  n%10 + '0';
		n =n / 10;
	}
	//反转回去 
	for(int i=str.length()-1;i>=0;i--){
		s += str[i];
	}
//	for(int i=0;i<str.length();i++)
//	str += '0';
	cout << str << endl << s; 
	return 0;
}
