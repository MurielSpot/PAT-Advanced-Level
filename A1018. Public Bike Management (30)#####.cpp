/*
https://www.patest.cn/contests/pat-a-practise/1018

類型：最短路徑，圖的遍歷。

難度：5（難度大，這類題要多做。我看了答案，再按著答案思路做，結果還是改了半天。）

注意事項：
1. vector<int>的數組，被我用memset把所有位都置為1之後，運行出錯，但是置為0時，正常運行了，所以容器不要隨便用memset。
錯誤代碼示例：
int main() {
	vector<int> a[3];
	memset(a, -1, sizeof(a));
	a[0].push_back(1);
	return 0;
}
運行出錯。
2. 題目要理解清楚：
選擇距離最短的路徑；
然後選從PBMC出發到sp所需携帶車輛最小的路徑，此時已經把經過的路程上的所有借點調整成最佳；
上一步可能選出了多條路徑，所以從sp返回時，要看此時需要帶回去多少輛自行車，選最少的情況。（回去時就不用考慮也要找一條路將所有結點調整成最優狀態了）
3. dfs算法中，不能從sp倒著計算需要多少自行車、剩餘多少自行車，因爲後面多的自行車在前面是取不到的，衹有從0出發開始，在前面多的自行車，在後面才能用到，而前面缺少的自行車，衹能從0処管理中心補足。
4. dijkstra算法中，找最短距離的結點時，每次存儲暫時最短距離和結點下標的變量都要再找新的最短距離之前初始化，不要忘！

補充測試數據：
10 4 4 5
4 8 9 0
0 1 1
1 2 1
1 3 2
2 3 1
3 4 1
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include<vector>
using namespace std;

#define P 0

const int MAXN=510;
const int INF=1000000000;

int cmax,n,sp,m;//capacity; total stations; problem station; roads.
int g[MAXN][MAXN]={0},weight[MAXN];
int d[MAXN],minNeed=INF,minRemain=INF;
bool vis[MAXN];
vector<int> pre[MAXN];
vector<int> tempPath,path;

void dijkstra(int s){
	memset(vis,0,sizeof(vis));
	fill(d,d+MAXN,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int minIndex=-1,minDist=INF;
		for(int i=0;i<=n;i++){//結點編號是[1,n]，另外加一個0表示管理中心！！！！！所以要i<=n。
			//minIndex=-1,minDist=INF;//不是在這個地方初始化，是在for循環外面！！！！！
			if(d[i]<minDist&&vis[i]==false){
				minDist=d[i];
				minIndex=i;
			}
		}
		if(minIndex==-1)break;
		vis[minIndex]=true;
		for(int i=0;i<=n;i++){//i<=n!!!!!!
			if(vis[i]==false&&g[minIndex][i]!=0){//某個鄰接結點未訪問且連通。
				if(d[i]>d[minIndex]+g[minIndex][i]){
					d[i]=d[minIndex]+g[minIndex][i];
					pre[i].clear();
					pre[i].push_back(minIndex);
				}else if(d[i]==d[minIndex]+g[minIndex][i]){
					pre[i].push_back(minIndex);
				}
			}
		}
	}
}
void dfs(int v){
#if P
	printf("\n*****\nv=%d\n*****\n",v);
#endif
	tempPath.push_back(v);
	if(v==0){//到達0時，由於0不需要調整成完美狀態，所以不需要再改變need和remain。
		int need=0,remain=0;
		for(int i=tempPath.size()-2;i>=0;i--){//0號結點不應該參與需要調整成完美狀態的運算，所以從size-2開始。
			int id=tempPath[i];//把i當成id來用了，導致檢查錯誤很長時間，包括下面for循環裏的的dfs！！！！！！！！！！！！！！！！！！！！！！！！！
#if P
	printf("\nid=%d\n",id);
#endif
			if(weight[id]-cmax/2>=0)remain+=weight[id]-cmax/2;
			else if(cmax/2-weight[id]>=remain){//手裏有的車不足以補足某結點所需的車量。
				need+=cmax/2-weight[id]-remain;
				remain=0;//先計算need，後面才能把remain置爲0!!!!!
			}else{
				remain-=cmax/2-weight[id];
			}
		}
#if P
	printf("\nminNeed=%d,need=%d,    minRemain=%d,remain=%d\n------------------------------\n",minNeed,need,minRemain,remain);
#endif
		if(need<minNeed){
			minNeed=need;
			minRemain=remain;
			path=tempPath;
		}else if(need==minNeed&&remain<minRemain){
			minRemain=remain;
			path=tempPath;
		}
		tempPath.pop_back();
		return;
	}
	for(int i=0;i<pre[v].size();i++){//除了sp和0以外，圖中無環路，所以不需要判斷某個頂點有沒有訪問過。
		//dfs(i);//錯的！！！！
		dfs(pre[v][i]);
	}
	tempPath.pop_back();
}

int main() {
	cin>>cmax>>n>>sp>>m;
	for(int i=1;i<=n;i++){//[1,n]!!!
		cin>>weight[i];
	}
	for(int i=0;i<m;i++){
		int vi,vj;
		cin>>vi>>vj;
		cin>>g[vi][vj];
		g[vj][vi]=g[vi][vj];
	}
	dijkstra(0);
	dfs(sp);
	cout<<minNeed<<" ";
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i];
		if(i>0)printf("->");
	}
	cout<<" "<<minRemain;
	return 0;
}
