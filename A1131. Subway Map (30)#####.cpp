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
//网上的可ac代码，还没看，懒得看了。
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v(10000);
int line[10000][10000], visit[10000], minCnt, minTransfer, start, end1;
vector<int> path, tempPath;
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]][a[i]] != preLine) cnt++;
        preLine = line[a[i-1]][a[i]];
    }
    return cnt;
}
void dfs(int node, int cnt) {
    if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end1) return;
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], cnt + 1);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
}
int main() {
    int n, m, k, pre, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre][temp] = line[temp][pre] = i + 1;
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &start, &end1);
        minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        tempPath.push_back(start);
        visit[start] = 1;
        dfs(start, 0);
        visit[start] = 0;
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]][path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]][path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
    }
    return 0;
}
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
