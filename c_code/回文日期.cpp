#include <bits/stdc++.h>
#include <string.h>
#include <algorithm>
using namespace std;
int rev(int x){
	int y=0;
	while(x>0){
		y = y*10 + x%10;
		x = x/10;
	}
	return y;
}
//判断闰年 
bool isLeap(int n){
	if((n%4==0 && n%100!=0) || (n%400==0))
	return true;
	else return false;
}
//判断日期合法 
bool isDate(int n){//20210121
	int day, month;
	bool flag=false;
	string str;
	int year;
	year = n/10000;
	month = (n%10000)/100;
	day = n%100;
	
	if(month>12||month==0) return flag;
	if(day>32||day==0) return flag;
	
	if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day<=31){
		flag=true;
		return flag;
	}
	if((month==4||month==6||month==9||month==11)&&day<=30){
		flag=true;
		return flag;
	}
	if(month==2&&isLeap(year)&&day<=29){
		flag=true;
		return flag;
	}
	if(month==2&&isLeap(year)==false&&day<=28){
		flag=true;
		return flag;
	}
	return flag;
} 
//判断回文数 
bool isHuiwen(int s){
	if(s%10==0)return false;
	if(rev(s)==s&&isDate(rev(s)))
	{
		return true;
	}
	
	else return false;
}
//判断ABABBABA
bool isAB(int s){//20210112
	int revab;
	int a = s/10000000;
	int b = (s/1000000)%10;
	if(a==b)return false;
	revab = a*10000000+b*1000000+a*100000+b*10000+b*1000+a*100+b*10+a;
	if(s==revab&&isDate(revab))
	return true;
	else return false;
}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  bool hflag=false,Aflag=false;
  int n,tem,t;
  cin >> n;//20210121
  
  
  for(int i=n;i<=99999999;i++){
  	if(isDate(i)&&i!=n){
  		
  		if(isHuiwen(i)&&hflag==false)
  		{
  			cout << i << endl;
  			hflag=true;
  			tem = i;
  			if(Aflag==true)
  			break;
		  }
		  
  		if(isAB(i)&&Aflag==false&&i!=tem&&isHuiwen(i))
  		{		
  				if(hflag==false){
  					t = i;
  					Aflag = true;
				  }
				  else{
				  	t=i;
  					Aflag = true;
  					break;
				  }
  				
  		
		  }
  		
	  }
  }
  cout << t << endl;

  return 0;
}
