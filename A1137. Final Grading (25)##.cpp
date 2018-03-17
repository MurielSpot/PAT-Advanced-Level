/*
https://www.patest.cn/contests/pat-a-practise/1137

类型：排序，string映射数组下标。

难度：2

注意事项：
1. 第一次做的时候因为担心string会超时，做了一种很啰嗦的方法。再做的时候就用了string，map，sort，结果也没超时，大概复杂度也就10的6,7次方吧。
*/

#include <cstdio>
#include<iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;


const int MAXN = 10005;

#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define sc(a) scanf("%d",&a)

int p;//program students.
int m;//mid students.
int n;//final students.

struct info {
	char id[22];
	int p, m, f, g;
	info() {
		p = m = f = g = -1;
	}
}record[MAXN];

int recordPos=1;//从1开始给考生分配下标，存到record相应位置里。
map<string, int> getPos;

bool cmp(info &a, info &b) {
	if (a.g == b.g) {
		return strcmp(a.id, b.id) < 0;
	}
	else return a.g > b.g;
}

int main(){
	cin >> p >> m >> n;
	string id;
	int tmp;
	rep(i, p) {
		cin >> id;
		sc(tmp);
		if (tmp >= 200) {//程序成绩合格才会被记录。
			getPos[id] = recordPos;
			strcpy(record[recordPos].id,id.c_str());
			record[recordPos].p = tmp;
			recordPos++;
		}
	}
	rep(i, m) {
		cin >> id;
		sc(tmp);
		if (getPos.find(id)!=getPos.end()) {//程序成绩有记录才会被记录。
			record[getPos[id]].m = tmp;
		}
	}
	rep(i, n) {
		cin >> id;
		sc(tmp);
		int pos;
		if (getPos.find(id) != getPos.end()) {//程序成绩有记录才会被记录。
			pos = getPos[id];
			record[pos].f = tmp;
			if (record[pos].m > tmp) {
				tmp = (int)(0.4f*record[pos].m + 0.6f*tmp+0.5);//此時tmp裏存的是最終成績
			}
			if (tmp >= 60) {//期末成績合格才會被記錄.所以g不为-1时，肯定是程序成绩和最终成绩都合格，其他情况g肯定为-1！
				record[pos].g =tmp;
			}
			
		}
	}
	sort(record + 1, record + recordPos, cmp);
	int i = 1;
	while (record[i].g != -1) {
		printf("%s %d %d %d %d\n",record[i].id,record[i].p,record[i].m,record[i].f,record[i].g);
		i++;
	}
	return 0;
}
