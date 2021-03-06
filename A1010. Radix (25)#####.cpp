/*
https://www.patest.cn/contests/pat-a-practise/1010

类型：进制转换。二分查找。

难度：5.（很難全過）

注意事项：
1. 题意及其不清楚，所以要注意：
基数radix的范围最大为INT_MAX，即2^31-1；
已知进制的数默认对应的10进制不超过long long，而未知进制的数转换成10进制后可能是溢出的；
2. 遍历进制数的方法会超时。所以可以通过二分查找来确定进制是多少。
3. 進制範圍：做題時進制的下界可設為未知數（沒有確定基數的那個數）的每個位數中的最大值+1，上界設爲已知的那個數+1.
4. 據説暴力遍历会在测试点7超时。 二分搜索后，如果不考虑溢出会在测试点10报错。
5. 題中說可能有解不唯一的情況，擧個例子：2 2 1 4，答案為3到∞進制都是可以的，取最小解就應該是3.
*/

//ac代碼。下面的代碼和這個幾乎一樣，衹是把所有的char數組換成了string，但不知道爲什麽出錯了，☹。（findLargestDigit略有改動，但我測試過了，僅替換這個函數是可以ac的。）
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char n1[20], n2[20];
int tag, radix;

inline int char2ll(char c) {
	if (isdigit(c)) {
		return c - '0';
	}
	else return c - 'a' + 10;
}

long long convertToTen(char a[], long long radix) {
	long long ans = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		ans = ans * radix + char2ll(a[i]);
	}
	return ans;
}

int cmp(char n2[], long long radix, long long t) {
	long long num = convertToTen(n2, radix);
	if (num < 0) return 1;
	if (num < t) return -1;
	return (t == num) ? 0 : 1;
}

long long binarySearch(char n2[], long long left, long long right, long long t) {
	long long mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int flag = cmp(n2, mid, t);
		if (flag == 0) return mid;
		else if (flag == -1) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

int findLargestDigit(char n2[]) {
	int ans = 2, len = strlen(n2);
	for (int i = 0; i < len; i++) {
		if (char2ll(n2[i]) >= ans) {
			ans = char2ll(n2[i]) + 1;
		}
	}
	return ans;
}

int main() {
	scanf("%s%s%d%d", &n1, &n2, &tag, &radix);
	if (tag == 2) {
		swap(n1, n2);
	}
	long long t = convertToTen(n1, radix);
	long long low = findLargestDigit(n2);
	long long ans = binarySearch(n2, low, t + 1, t);
	if (ans == -1) printf("Impossible");
	else printf("%lld", ans);
	return 0;
}

//0和6未過。
#include <iostream>
#include <cstring>
#include <algorithm>
#include<string>
using namespace std;
string n1,n2;
int tag, radix;

inline int char2ll(char c){
	if(isdigit(c)){
		return c-'0';
	}else return c-'a'+10;
}

long long convertToTen(string a, long long radix) {
    long long ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans = ans * radix + char2ll(a[i]);
    }
    return ans;
}

int cmp(string s, long long radix, long long t) {
    long long num = convertToTen(s, radix);
    if(num < 0) return 1;
    if(num < t) return -1;
    return (t == num) ? 0 : 1;
}

long long binarySearch(string s, long long left, long long right, long long t) {
    long long mid;
    while(left <= right) {
        mid = (left + right) / 2;
        int flag = cmp(s, mid, t);
        if(flag == 0) return mid;
        else if(flag == -1) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int findLargestDigit(string s) {
    int ans = -1;
    for(int i = 0; i < s.size(); i++) {
        if(char2ll(n2[i]) > ans) {
            ans = char2ll(n2[i]);
        }
    }
    return ans + 1;
}

int main() {
    cin>>n1>>n2>>tag>>radix;
	string a,b;
    if(tag == 2) {
        a=n2;
		b=n1;
    }else{
		a=n1;
		b=n2;
	}
    long long t = convertToTen(a, radix);
    long long low = findLargestDigit(b);
    long long ans = binarySearch(b, low, t+1, t);
    if(ans == -1) printf("Impossible");
    else printf("%lld", ans);
    return 0;
}


//下面代碼有測試點0和6未過.
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

#define P 0

const long long MAXRADIX=1<<31-1;

string n1,n2;
long long radix;
int tag;

long long determined,toDetermined;

inline long long char2ll(char c){
	if(isdigit(c)){
		return c-'0';
	}else return c-'a'+10;
}

long long r2ten(string num,long long r){//r進制轉10進制。
	long long ans=0,power=1;
	for(int i=num.size()-1;i>=0;i--){
		ans+=char2ll(num[i])*power;
		power*=r;
	}
	return ans;
}

long long lowestRadix(string num){
	long long low=2;
	for(int i=num.size()-1;i>=0;i--){
		if(char2ll(num[i])>=low)low=char2ll(num[i])+1;//大於等於，不是大於。
	}
#if P
	printf("\n-----------\nlowestRadix=%lld\n-----------\n",low);
#endif
	return low;
}

void binarySort(string s,long long leftR,long long rightR){//左右不要寫反了。
	long long ans,power,midR;
	int size=s.size()-1;
	while(leftR<=rightR){
		ans=0;
		power=1;
		midR = (leftR + rightR) / 2;
#if P
	printf("\n-----------\nleftR=%lld, rightR=%lld, midR=%lld\n-----------\n",rightR,leftR,midR);
#endif
		for(int i=size;i>=0;i--){
			ans+=char2ll(s[i])*power;
#if P
	printf("ans=%lld, power=%lld\n",ans,power);
#endif
			power*=midR;
			if(i==0&&power<0){//當前不是最後一次計算，下一步的power小於0，説明下一步也要溢出。
				ans=determined+1;//將ans置為比已確定的那個數大的數。此時可能determined+1可能又溢出了，但是下面那個if裏對這種情況進行了判斷。
			}
			if(ans>determined||ans<0){//還沒算完發現結果已經比另一個數大，説明這個基數不是所需的。ans小于0表示溢出了。
				break;
			}
		}
		if(ans>determined||ans<0)rightR=midR-1;
		else if(ans<determined)leftR=midR+1;
		else{
			printf("%lld",midR);
			break;
		}
	}
	if(leftR>rightR){
		printf("Impossible");//沒找到。
	}
}

int main() {
	cin>>n1>>n2>>tag>>radix;
	if(n1==n2){
		if(n1.size()==1){//衹有一位數時，已經確定進制的那個數的進制數并不會影響另一個數，也就是説，比如兩個數都是a，其中一個已經確定進制為35，另一個并不一定為35，取11也是正確的。
			printf("%lld",lowestRadix(n1));
		}else{
			printf("%lld",radix);
		}
	}else{
		if(tag==1){
			determined=r2ten(n1,radix);
			binarySort(n2,lowestRadix(n2),determined+1);//把最後一個參數中的MAXRADIX，改寫成determined+1。
		}else if(tag==2){
			determined=r2ten(n2,radix);
			binarySort(n1,lowestRadix(n2),determined+1);
		}
	}
	return 0;
}

//下面測試點0和7未過。把下面的MAXRADIX改成determined+1，就衹有0未過了。網上好像有人説，如果有段錯誤測試點7會錯。
//但是把lowestRadix函數裏的(char2ll(num[i])>low改成>=第6個測試點又會錯！！
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

#define P 0

const long long MAXRADIX=1<<31-1;

string n1,n2;
long long radix;
int tag;

long long determined,toDetermined;

inline long long char2ll(char c){
	if(isdigit(c)){
		return c-'0';
	}else return c-'a'+10;
}

long long r2ten(string num,long long r){//r進制轉10進制。
	long long ans=0,power=1;
	for(int i=num.size()-1;i>=0;i--){
		ans+=char2ll(num[i])*power;
		power*=r;
	}
	return ans;
}

long long lowestRadix(string num){
	long long low=2;
	for(int i=num.size()-1;i>=0;i--){
		if(char2ll(num[i])>low)low=char2ll(num[i])+1;
	}
#if P
	printf("\n-----------\nlowestRadix=%lld\n-----------\n",low);
#endif
	return low;
}

void binarySort(string s,long long leftR,long long rightR){//左右不要寫反了。
	long long ans,power,midR;
	int size=s.size()-1;
	while(leftR<=rightR){
		ans=0;
		power=1;
		midR = (leftR + rightR) / 2;
#if P
	printf("\n-----------\nleftR=%lld, rightR=%lld, midR=%lld\n-----------\n",rightR,leftR,midR);
#endif
		for(int i=size;i>=0;i--){
			ans+=char2ll(s[i])*power;
#if P
	printf("ans=%lld, power=%lld\n",ans,power);
#endif
			if(ans>determined){//還沒算完發現結果已經比另一個數大，説明這個基數不是所需的。
				break;
			}
			power*=midR;
		}
		if(ans>determined)rightR=midR-1;
		else if(ans<determined)leftR=midR+1;
		else{
			printf("%lld",midR);
			break;
		}
	}
	if(leftR>rightR){
		printf("Impossible");//沒找到。
	}
}

int main() {
	cin>>n1>>n2>>tag>>radix;
	if(n1==n2){
		printf("%lld",radix);
	}else{
		if(tag==1){
			determined=r2ten(n1,radix);
			binarySort(n2,lowestRadix(n2),MAXRADIX);
		}else if(tag==2){
			determined=r2ten(n2,radix);
			binarySort(n1,lowestRadix(n2),MAXRADIX);
		}
	}
	return 0;
}
