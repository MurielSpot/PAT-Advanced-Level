/*
https://www.patest.cn/contests/pat-a-practise/1131

类型：图。

难度:5.

注意事项：
1. 重点时怎么把站点连成一个网,且同时又线路信息。建图时稍微麻烦一点，另一个难点是如何记录换乘情况。
2. 注意到邻接矩阵在找邻接边的时候代价很大,用邻接表存储更好.不过有人用邻接矩阵做了，而且用的dfs，好像也过了。
3. 火车线路倒着也能走.........
4. 计算经过的总站点数时，经过的第一个站点不需要算。
5. 当起始地下一站就是目的地时，注意输出不要出错。对应测试点4.
6. 预编译输入的IN如果为1，会出现运行超时错误。
*/

/*
下面的代码第3个测试点出错,扣了5分.
不知道哪错了,也不想找哪错了.
我自己写的代码,自己都不太清楚思路是什么.
*/
#include<cstdio>
#include<iostream>

#include <string>
#include <cstring>

#include <algorithm>
#include<cmath> 

#include<vector>
#include<stack>
#include<queue>
#include<set>

#include<map>
using namespace std;

#define P 0
#define R 0
#define IN 0//忘了把它置为0，结果运行全部超时。

const int MAXN = 110;
const int MAXM = 110;
const int MAXID = 10010;
const int INF = 1000000000;

struct way {
	int line;
	int v1, v2;
	way() {
		line = v1 = v2 = -1;
	}
	way(int l, int from, int to) {
		line = l; v1 = from; v2 = to;
	}
};
vector<way> sub_way[MAXID];

int s, d;
vector<way> ans,tmp;
int preLine[MAXID];
int minSta=INF, minTrans=INF;
bool vis[MAXID];
void dfs(int now, int cntSta,int cntTrans) {//now是当前的站，cntSta表示到now有多少站，cntTrans表示到now换乘了多少站。
	if (now == d) {
		if (cntSta < minSta) {
			minSta = cntSta;
			ans = tmp;
			minTrans = cntTrans;
		}
		else if (cntSta == minSta && cntTrans < minTrans) {
			ans = tmp;
			minTrans = cntTrans;
		}
		return;
	}
	else if (cntSta > minSta || cntTrans > minTrans) {
		return;
	}
	for (int i = 0; i < sub_way[now].size(); i++) {
		int v2 = sub_way[now][i].v2;
		if (vis[v2] == false) {
			vis[v2] = true;
			preLine[v2] = sub_way[now][i].line;
			tmp.push_back(sub_way[now][i]);//经过当前一段线路。
			if (preLine[now] == preLine[v2] || now == s) {//不换乘。
				dfs(v2, cntSta + 1, cntTrans);
			}
			else {
				dfs(v2, cntSta + 1, cntTrans + 1);
			}
			tmp.pop_back();//递归完之后当前一段线路还要出栈。
			vis[v2] = false;
		}
	}
}

void outputAns(vector<way> &ans) {
	printf("%d\n", minSta);
	int former;
	way tmp;
	for (int i = 0; i < ans.size(); i++) {
		if (i == 0) {
			former = ans[0].line;
			tmp.line = former;
			tmp.v1 = s;
		}
		else {
			if (ans[i].line != former) {//换乘了。
				tmp.v2 = ans[i].v1;
				printf("Take Line#%d from %04d to %04d.\n",tmp.line,tmp.v1,tmp.v2);
				//更新former,tmp值。
				former = ans[i].line;
				tmp.line = former;
				tmp.v1 = ans[i].v1;
			}
		}
		//注意是由一个记录时，v2正好等于d，所以i==0时就该把路线给输出，所以这个if判断不能放到上面的else里。
		if (ans[i].v2 == d) {
			printf("Take Line#%d from %04d to %04d.\n", tmp.line, tmp.v1, d);
			break;
		}
	}
}

int main() {
	/*FILE *fp = fopen("C:\\Users\\oakpa\\Desktop\\test.txt", "r");*/
#if IN
	freopen("C:\\Users\\oakpa\\Desktop\\test.txt", "r", stdin);//重定向输入输出流.
#endif
	int n;
	scanf("%d", &n);
	for (int line = 1; line <= n; line++) {
		int m; scanf("%d", &m);
		int v1, v2;
		for (int i = 0; i < m; i++) {
			if (i == 0) {
				scanf("%d", &v2);
			}
			else {
				v1 = v2;
				scanf("%d", &v2);
				sub_way[v1].push_back(way(line, v1, v2));
				sub_way[v2].push_back(way(line, v2, v1));
			}
		}
	}
	int k; scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		//s,d放在全局了。
		scanf("%d%d", &s, &d);

		//初始化。
		memset(preLine, -1, sizeof(preLine));
		memset(vis, 0, sizeof(vis));
		minSta = INF, minTrans = INF;
		
		dfs(s, 0, 0);
		outputAns(ans);
	}
	return 0;
}
