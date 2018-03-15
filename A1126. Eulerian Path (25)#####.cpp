/*
https://www.patest.cn/contests/pat-a-practise/1126

類似:連通圖,頂點的度.(图论)

難度:5(題目好難懂)

注意事項:
1. 題沒看懂.題意是説题目说了欧拉路径没有奇度点，欧拉回路有且只有两个奇度点，其他非歐拉.
百度百科中關於歐拉圖的介紹中有這樣一句:图 G 称为偶图(even graph)，如果G 中每个顶点的度数为偶数。容易发现，连通的偶图即为欧拉图。
所以做題時:先确定连通性,不连通则为3;再判斷是欧拉图还是半欧拉图,点的度数全为偶数为欧拉图,恰好有两个点度数为奇数是半欧拉图，其余情况二者皆不是。

其他:
[Euler tour]
图的环游(tour)是指经过图的每条边至少一次的闭途位。欧拉环游是经过每条边恰好一次的环游。一个图若包含欧拉环游，则称为欧拉图(Euleriangraph)。
类似地，经过图的每条边的迹称为图的欧拉达(Enlertrail)。这些术语之所以以欧拉命名，是因为欧拉首先研究了图中欧拉迹的存在问题。1736 年欧拉解决了著名的哥尼斯堡七桥问题。把哥尼斯堡七桥问题一般化，欧拉证明了如下定理：一个非空连通图是欧拉图当且仅当它的每个顶点的度数都是偶数。
由此可得如下结论：一个连通图有欧拉迹当且仅当它的每个顶点的度数都是偶数，由此可得如下结论：一个连通图有欧拉迹当它至多有两个度数是奇数的顶点。
图 G 称为偶图(even graph)，如果G 中每个顶点的度数为偶数。容易发现，连通的偶图即为欧拉图。
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>//memset
#include<map>
using namespace std;

#define sc(a) scanf("%d",&a)
#define rep(i,n) for(int i=0;i<n;i++)

const int MAXN=505;

int n;//vertices.[1,n].
int m;//edges.

int degree[MAXN];
vector<int> g[MAXN];

bool vis[MAXN] = { false };
void dfs(int now) {
	vis[now] = true;
	rep(i, g[now].size()) {
		int v = g[now][i];
		if (vis[v] == false) {
			dfs(v);
		}
	}
}
bool judgeConnectedness() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {
			cnt++;
			if (cnt > 1)return false;
			dfs(i);
		}
	}
	return true;
}

int main() {
	sc(n); sc(m);
	rep(i, m) {//这里是m,不是n.经常犯这种错误,把循环边界写错,输入边,当然是用边的个数结束循环,怎么能用顶点呢!!!!!
		int v1, v2;
		sc(v1); sc(v2);
		degree[v1]++;
		degree[v2]++;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	//数度为奇数的顶点的个数.并输出顶点的度.
	int oddCnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i != 1)printf(" ");
		printf("%d", degree[i]);
		if (degree[i] % 2) {
			oddCnt++;
		}
	}
	printf("\n");
	//如果奇数度不为0或2,则为第三种情况,不是欧拉图或半欧拉图.
	if (oddCnt != 2 && oddCnt != 0) {
		printf("Non-Eulerian\n");
	}
	else {
		//判断是否连通.
		bool connected = judgeConnectedness();
		if (connected) {
			if (oddCnt == 0) {
				printf("Eulerian\n");
			}
			else if (oddCnt == 2) {
				printf("Semi-Eulerian\n");
			}
		}
		else {
			printf("Non-Eulerian\n");
		}
	}
	return 0;
}
