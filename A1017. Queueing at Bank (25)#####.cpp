/*
https://www.patest.cn/contests/pat-a-practise/1017

類型:日常模擬.

難度:5(題沒理解清楚,調試了很長時間)

注意事項:
1. 窗口不止一個!!!!!!!!!
2. 過了17點的人不被服務,是指這個人到達時間。來的早但等到17點還未被服務的人之後仍然可以服務。否則最後一個測試點過不了。
3. 求平均等待時間時,過了17點的人不算在内.另外不要以爲某個人一來就被服務了的這類人不算在等待的人裏,即等待時間為0但是被處理的人要儅分母.
4. 有時候struct裏的構造函數進行了一些操作,但是正文裏卻沒有用,注意這樣的錯誤!
5. 計算同一天的時間差時,可以將其轉換成秒s來做,會更方便!
6. 服務時間長於60分鐘的,按60分鐘算,還不知道測試數據裏會不會給長於60分鐘服務時間的數據.
*/
#include<cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include<map>
using namespace std;

const int MAXN = 10010;
const int MAXK=110;
const int INF = 1000000000;

int n;//customers.
int k;//windows.

struct info{
	//以秒計算
	int time;
	int start;
	int lasting;
	//info(){start=time;}//忘了用構造函數,結果start就一直為0.
	//info(int h,int m,int s){hour=h;minute=m;second=s;}
}customer[MAXN];
int window[MAXK];

bool cmp(info a,info b){
	return a.time < b.time;
}

vector<int> valid;
bool handle(int index){//找一個可以最早進行服務的窗口,在其后處理,然後更新它下一次可以處理的時間.
	sort(window,window+k);//窗口的編號有沒有都無所謂,所以可以隨意排序.
	//if(window[0]>61200||customer[index].start>61200)return false;//沒有窗口能在17點前完成服務.
	if(customer[index].time>61200)return false;//到來時間不合格。
	if(customer[index].start<window[0]){
		customer[index].start=window[0];
	}
	window[0]=customer[index].start+customer[index].lasting;
	valid.push_back(index);
	return true;
}

int getSumTime(){
	int sum=0;
	for(int i=0;i<valid.size();i++){
		int t=valid[i];
		sum+=customer[t].start-customer[t].time;
	}
	return sum;
}

int main() {
	fill(window,window+MAXK,28800);//所有窗口都是八點開始工作.
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int h,m,s,l;
		scanf("%d:%d:%d %d",&h,&m,&s,&l);
		customer[i].time=h*3600+m*60+s;
		if(l>60)l=60;//如果通過了,看看把這個去掉能不能通過. 
		customer[i].lasting=l*60;//持續時間也要換算成秒,不要忘了!!!!
		customer[i].start = customer[i].time;
	}
	sort(customer,customer+n,cmp);
	for(int index=0;index<n;index++){
			if(handle(index)==false)break;
	}
	int sum=getSumTime();
	if (valid.size()) {
		printf("%.1lf",(double)sum/60/valid.size());
	}else printf("0.0");
	return 0;
}
