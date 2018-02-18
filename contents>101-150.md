# 目录：甲级101-150题
## A1101. Quick Sort (25)###（比较讲究技巧的题，容易超时。还要注意输出格式。）
https://www.patest.cn/contests/pat-a-practise/1101

类型：查找（快速排序里的pivot）。

注意事项：
1. 暴力判断会超时。不会超时的算法：第一遍遍历（即输入数据的时候），得到某个元素之前的最大值，如果当前元素没有之前的最大值大，说明不是pivot；可用同样的思路倒着遍历一遍得到后面的最小值，来判断当前是否是pivot。
注意第一遍遍历按上诉方法做，第二遍遍历根据当前元素是否可能是pivot，再暴力判断后面的元素是否有比当前元素小的，这种方法同样会超时。
2. 主元个数为0时，第二行虽然没有输出主元，但必须输出一个换行！

## A1102. Invert a Binary Tree (25)##

https://www.patest.cn/contests/pat-a-practise/1102

类型：二叉树（层序、中序遍历），bfs

注意事项：
1. 尝试用scanf("%c\n",&ch);吃掉下次读取时多余的回车出现了问题，以后还是用getchar吧。scanf("%*c%s",ch);中%*c可以用来接收一个字符，所以可以用来处理之前遗留的\n。
2. 输出的层序遍历和中序遍历都是反转过的树，所以在一开始输入左右子树时，直接把原左子树的位置赋给父结点的右子树的指针，原右子树同理。
再按层序和中序遍历的写法直接输出得到正好时一棵反转的二叉树。

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

## A1106. Lowest Price in Supply Chain (25)###
https://www.patest.cn/contests/pat-a-practise/1106

类型：图的遍历。

注意事项：
1. 题目保证价格最大不超过10^10，所以用int的最大值来表示INF范围还是小的，而且价格为浮点型，不应该用int型的最大值给它赋值。
2. r是百分号前面的值，实际上增加的比率为r/100，所以可以提前处理r=r/100，然后计算价格是用price*(1+r)即可，可以减少若干次除法运算。
3. 对每一级商家添加下一级商家时，下标要用前者的下标，不要用错了，比如不要把用来控制循环次数的变量当成商家的下标来用，所以变量名起好很重要，不然不经意间可能就出错了。
