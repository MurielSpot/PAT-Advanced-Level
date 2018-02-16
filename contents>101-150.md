# 目录：甲级101-150题
## A1101. Quick Sort (25)###（比较讲究技巧的题，容易超时。还要注意输出格式。）
https://www.patest.cn/contests/pat-a-practise/1101

类型：查找（快速排序里的pivot）。

注意事项：
1. 暴力判断会超时。不会超时的算法：第一遍遍历（即输入数据的时候），得到某个元素之前的最大值，如果当前元素没有之前的最大值大，说明不是pivot；可用同样的思路倒着遍历一遍得到后面的最小值，来判断当前是否是pivot。
注意第一遍遍历按上诉方法做，第二遍遍历根据当前元素是否可能是pivot，再暴力判断后面的元素是否有比当前元素小的，这种方法同样会超时。
2. 主元个数为0时，第二行虽然没有输出主元，但必须输出一个换行！

## A1103. Integer Factorization (30)###
https://www.patest.cn/contests/pat-a-practise/1103

类型：背包问题，数的分解（把一个数分解成若干次方项的和）。

## A1104. Sum of Number Segments (20)####
https://www.patest.cn/contests/pat-a-practise/1104

类型：人工推导/找规律题。

注意事项：
1. 如果用脑子想不清楚题目所给数据的规律，可以举几个例子类推。
该题中第i个数总出现次数为i*(n+1-i)。注意这里的i的范围为[1,n]，不能从0开始。
2. 隐式类型转换的注意事项：sum+=tmp*(n+1-i)*i;这一句中sum，tmp是double型，n，i是int型，代码中tmp放在(n+1-i)*i前面能测试通过，但是把tmp放在最后乘会有两个测试点不能通过。

因为n最大为10^5，所以tmp在后面的时候(n+1-i)*i还未转换成double类型，仍然按照int的存储大小进行运算，而tmp放在前面，(n+1-i)*i再参与运算就是double型的了。
<pre>//溢出测试
#include&lt;cstdio>
int main(){
	int n=100000;
	int i=50000;
	double tmp1=1.0*i*(n+1-i);//double类型放在前面乘。
	double tmp2=i*(n+1-i)*1.0;//double类型放在后面乘。
	printf("tmp1=%.2lf\ntmp2=%.2lf",tmp1,tmp2);
	return 0;
}
//output
tmp1=2500050000.00
tmp2=-1794917296.00
</pre>
