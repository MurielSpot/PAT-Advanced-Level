/*
https://www.patest.cn/contests/pat-a-practise/1021

類型:树的深度,连通图(还需要一些数学知识,找两个结点之间的最长距离)(这道题我自己是没做出来)

難度：5

注意事項：
1. 輸入邊時，注意衹有n-1條。
2. 無向圖用dfs判斷是否有回路會出問題，因爲無向圖u訪問v后，進入到v的dfs后，肯定判斷u是否已訪問，若認爲u已訪問是有回路，則出錯。
判斷是否有回路的方法：該題中n個node，n-1條邊，若整個圖是一個連通圖，則肯定是樹；（拓撲排序，需要記錄node的入度出度，用於有向圖）；
3. 求set的并集,有现成的函数,不过使用到了inserter,需要包含iterator头文件.求并集的函数set_union(a.begin(),a.end(), b.begin(),b.end(),inserter(c,c.begin()));

其他：
1. connected components是連通分量的意思。
2. 关于查错,如果代码出错,最好自己手写几个测试数据,想各种可能性,才可能避免错误,
因为有的时候不是代码整体思路错,而是一些细节,如输出错误,变量类型错误,通过一次调试或用几个区别比较大的测试数据就能找出来.
3. 补充集合运算的函数:这个博客讲得挺详细,不总结了不想打字,但是之后看笔记的时候请不要懒,别不想打开链接...http://blog.csdn.net/kalilili/article/details/42177279

思路:
先判断是否连通,不连通则输出连通分量个数,可以用dfs做,其中第一次dfs的时候可以统计可能的根结点,大于1次说明不连通,不需要再算了.
如果连通,则先从一个顶点出发,找所有可以以它为根的最深结点,再从这些最深结点里选一个,找以新选出来的结点为根的最深结点,将两个最深结点的集合取并集则得到结果.
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<cstring>//memset

#include<iterator>//inserter需要用到它.set_union(a.begin(),a.end(), b.begin(),b.end(),inserter(c,c.begin()));
using namespace std;

#define sc(a) scanf("%d",&a)
#define rep(i,n) for(int i=0;i<n;i++)


const int MAXN=10005;

int n;//[1,n].
vector<int> g[MAXN];

set<int> a, b;

bool vis[MAXN];

int maxDepth = 1;
void dfs(int now,int depth,set<int> &s) {
	vis[now] = true;
	//if (g[now].size() == 0) {//因为是无向图,如果图连通,每个结点都会有出度....所以这个size等于0的判断条件永远不会成立!!所以还是每次都判断一次最大深度吧.
	if (depth > maxDepth) {
		maxDepth = depth;
		s.clear();
		s.insert(now);
	}
	else if (depth == maxDepth) {
		s.insert(now);
	}
	rep(i, g[now].size()) {
		int v = g[now][i];
		if (vis[v] == false) {
			dfs(v, depth + 1,s);
		}
	}
}

int dfsTrave() {//因为只有n-1条边,所以如果只有一个连通分量肯定是树,没有回路.如果有多个连通分量可能就有回路了.所以为一颗树时,一个结点不会被重复访问,所以vis并不影响结点的访问,不会有vis设置为true之后结点无法访问的情况.
	int cnt=0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {
			dfs(i, 1,a);
			cnt++;
		}
	}
	return cnt;
}

int main() {
	sc(n);
	rep(i, n - 1) {
		int v1, v2;
		sc(v1); sc(v2);
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	memset(vis, 0, sizeof(vis));
	maxDepth = 1;
	int components=dfsTrave();
	if (components!=1) {
		printf("Error: %d components", components);
	}
	else {//哎呀,我忽然发现忘了写这个else,在运行测试的时候,下面没写就对不连通的情况做了测试,对了,
		//然后写完下面的内容,就对连通的情况做了测试,但是else没写,不连通的时候既会打印出error,又会输出一些结点,从而出错!!
		//以后出了同样的错误,真不知道要怎么检查出来,代码看了几遍也每看出来什么问题.
		//可能需要自己手写几个测试数据,想各种可能性,才可能避免错误.
		memset(vis, 0, sizeof(vis));
		maxDepth = 1;
		if (a.size()) {
			dfs(*a.begin(), 1, b);
		}
		set<int> c;
		set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));//<iterator>
		for (set<int>::iterator it = c.begin(); it != c.end(); it++) {
			printf("%d\n", *it);
		}
	}
	
	return 0;
}
