/*
https://www.patest.cn/contests/pat-a-practise/1095

类型:模拟.

难度:4.(一般想清楚再做,如果遇到了什么疏忽的地方,那这题就别得分了.)

注意事项:
1. 有一个巨大的坑点,一个车可能反复进入校园,所以它的值要不断累加.求最长停车时间不是指一次连续停车时间....

思路:
先按姓名排序，筛选出无效的记录，同时统计最长停车时间。
再按时间排序，进行查询的处理，因为查询是按时间递增的顺序，所以新的查询都从上一次查询开始。
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
#define P 0
#define R 0

const int MAXN=10005;
const int INF = 1000000000;

int n;//records.
int k;//queries.

int computeSecond(int hour, int minute, int second) {
  return hour * 3600 + minute * 60 + second;
}

struct info {
  char id[9];
  int time;
  bool in,out,valid;
  info() {
    in = out = false;
    valid = true;
  }
}record[MAXN];

//先按id字典序排序,再按记录时间递增排序.
bool cmpName(info a, info b) {
  int tmp = strcmp(a.id, b.id);
  if (tmp==0) {
    return a.time < b.time;
  }
  //else tmp < 0;//错误说明是无效的比较器....因为忘写return了.
  else return tmp < 0;
}
//先把有效数据放在前面,再完全按进出时间排序.
bool cmpValidTime(info a, info b) {
  if (a.valid == b.valid) {
    return a.time < b.time;
  }
  else return a.valid;//有效值放在前面.
}

//输入的lastIndex的时间点是没有被统计的.
void computeCar(int &lastCnt, int &lastIndex, int time) {
  //if (record[lastIndex].time >= time) {//如果上次查到的时间比现在还迟,则这次不需要计算.
  //  return;
  //}
  //注意下面对时间的判断,取小于等于,不是小于,不然与测试数据给的答案不一样.record[lastIndex].time < time改成<=.
  while (lastIndex < n && record[lastIndex].valid && record[lastIndex].time<=time) {//如果上次查询再这次查询的时间之前,且查询的序号有效,则可以继续查询.
    if (record[lastIndex].in) {
      lastCnt++;
    }
    else if (record[lastIndex].out) {
      lastCnt--;
    }
    lastIndex++;
  }
}

int main() {
  sc(n); sc(k);
  rep(i, n) {
    char id[9];
    int h, m, s;
    char inout[4];
    scanf("%s %d:%d:%d %s", id, &h, &m, &s, inout);
    strcpy(record[i].id, id);
    record[i].time = computeSecond(h, m, s);
    if (inout[0] == 'i') {
      record[i].in = true;
    }
    else if (inout[0] == 'o') {
      record[i].out = true;
    }
  }
  sort(record, record + n, cmpName);

  //同一个名字的情况下,判断是否和上一个进出情况相匹配.
  int maxTime = 0;//统计最长停车时间,
  map<string,int> id2time;//统计最长停车时间的车辆id.
  vector<string> ansId;
  for (int i = 1; i < n; i++) {
    int tmpTime;
    string tmpId;
    if (strcmp(record[i].id,record[i-1].id)==0) {
      //和上一个名字一样,则只有上一个in这一个out,或上一个out,这一个in是可能的有效数据.
      if (record[i - 1].out&&record[i].out) {
        record[i].valid = false;
      }
      else if (record[i - 1].in&&record[i].in) {
        record[i - 1].valid = false;
      }
      else if (record[i - 1].in&&record[i].out) {
        //用map记录每个车的停车总时长.
        tmpId = record[i].id;
        tmpTime = record[i].time - record[i - 1].time+ id2time[tmpId];
        id2time[tmpId] = tmpTime;
        //更新最大值.
        if (tmpTime > maxTime) {
          maxTime = tmpTime;
          ansId.clear();//一开始忘了清空,且忘了写下面的else,以至于把一些比较小的时长也打印出来了.
          ansId.push_back(tmpId);
        }
        else if (tmpTime == maxTime) {
          ansId.push_back(tmpId);
        }
      }
    }
    else {
      //两次名字不一样,则如果上一个是in,或当前为out,则肯定是无效的.
      if (record[i - 1].in) {
        record[i - 1].valid = false;
      }
      if (record[i].out) {
        record[i].valid = false;
      }
    }
  }
  //还要单独处理最后一个数据.因为保证至少有一对有效数据,所以不会有n==1的情况,所以不用对这种情况下唯一一个记录为out的情况进行讨论,仅看最后一个记录是否为in,如果是,则是无效数据.
  if (record[n - 1].in) {
    record[n - 1].valid = false;
  }

  //处理查询.
  sort(record, record + n, cmpValidTime);
  int lastCnt = 0;//上一次计算时有多少量车.
  int lastIndex = 0;//上一次计算时查询record数组数据的index号.
  rep(i, k) {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    int time = computeSecond(h, m, s);
    computeCar(lastCnt, lastIndex, time);
    printf("%d\n", lastCnt);
  }
  rep(i, ansId.size()) {
    cout << ansId[i];
    printf(" ");
  }
  printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime / 60 % 60, maxTime % 60);
  return 0;
}
