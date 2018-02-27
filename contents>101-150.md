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

## A1105. Spiral Matrix (25)###
https://www.patest.cn/contests/pat-a-practise/1105

類型:(不明,不好歸類)

## A1106. Lowest Price in Supply Chain (25)###
https://www.patest.cn/contests/pat-a-practise/1106

类型：图的遍历。

注意事项：
1. 题目保证价格最大不超过10^10，所以用int的最大值来表示INF范围还是小的，而且价格为浮点型，不应该用int型的最大值给它赋值。
2. r是百分号前面的值，实际上增加的比率为r/100，所以可以提前处理r=r/100，然后计算价格是用price*(1+r)即可，可以减少若干次除法运算。
3. 对每一级商家添加下一级商家时，下标要用前者的下标，不要用错了，比如不要把用来控制循环次数的变量当成商家的下标来用，所以变量名起好很重要，不然不经意间可能就出错了。

## A1107. Social Clusters (30)#####（！！並查集！！）
https://www.patest.cn/contests/pat-a-practise/1107

類型：並查集。（最初用圖的遍歷做，發現做不了，不過沒有細想是不是真的做不了）

注意事項：
1. 該題中將並查集的根結點的值設置為它本身的下標，比設置為0更方便、更容易處理。

## A1132. Cut Integer (20)#
https://www.patest.cn/contests/pat-a-practise/1132

类型:数字计算.

注意事項：
1. 不注意切分后的兩部分的乘積是否為0，會出現浮點錯誤，比如10，分成1和0，然後10/(1*0)就出現除0錯誤。

## A1133. Splitting A Linked List (25)##
https://www.patest.cn/contests/pat-a-practise/1133

类型:静态链表,排序.

注意事项:
1. 排序时的cmp函数不太好写.

## A1134. Vertex Cover (25)#
https://www.patest.cn/contests/pat-a-practise/1134

类型:图(边的遍历).

其他:水题连dfs,bfs都不需要用;英语稍微有点不容易懂.

## A1135. Is It A Red-Black Tree (30)###
https://www.patest.cn/contests/pat-a-practise/1135

類型：樹（先序遍歷結合二叉平衡搜索樹的性質建樹），dfs。

注意事項：
1. 不考慮平衡，按照二叉搜索樹的性質劃分左右子樹即可結合先序遍歷建成所給樹。
2. 建樹的時候，找先序序列中，第一個值是當前根結點的值，後面是左右子樹的值，找左右子樹里找第一個大於當前結點的值的位置時，不能直接用lower_bound函數，
因為關鍵字是正的，但為了表示紅黑，所以需要取絕對值再比較它們與根結點絕對值的大小。如果想用lower_bound函數，見下面介紹。
3. 進行深度搜索，判斷樹是否滿足條件，一開始沒用返回值來求當前結點到葉子結點路徑上black的數量，沒做出來，然後用返回值就很容易求得black數量。
可以自己思考，能不能不用返回值，求black到當前結點的數量，比如設置計數變量，每次到null就加一以與上次區分，結點里每次都判斷當前到根結點的值是否是舊的，是否滿足條件，
我現在只是想一想，具體可不可行還沒有試。
4. 注意題目中For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
說的是任何一個結點到它的葉子結點的簡單路徑上的黑色結點的值，不是根結點到葉子結點。

其他：
1. 平衡二叉樹的建立、插入等等還很不熟，幸好這道題沒考，但自己要多做做avl的題。
2. 紅黑樹也不了解。該題中是這樣介紹的：<pre>
There is a kind of balanced binary search tree named red-black tree in the data structure. It has the following 5 properties:
(1) Every node is either red or black.
(2) The root is black.
(3) Every leaf (NULL) is black.
(4) If a node is red, then both its children are black.
(5) For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.</pre>

3. lower_bound函数<br/>
注意:lower_bound(num,num+10,value)-num,要减num才能获得value在数组中的下标,不减num得到的是地址.

> 第一个版本：
> template<class ForwardIterator,class T>
> ForwardIterator lower_bound(ForwardIterator first,ForwardIterator last,const T &val);

> 第二个版本：
> template<class ForwardIterator,class T,class Compare>
> ForwardIterator lower_bound(ForwardIterator first,ForwardIterator last,const T &val,Compare comp);

<pre>
//第二个版本的比较函数的书写及对应对应例子:
int num[10]={0,3,6,6,-8,-8,8,9,10,12};
int main() {
	printf("%d",lower_bound(num,num+10,x,cmp)-num); 
	return 0;
}

//cmp里函数应该写的是小于运算的比较
//找第一个大于等于x的值.这个cmp函数和不加cmp函数lower_bound的效果时相同的.
bool cmp(int a,int b){
	return a&lt;b;
}
//x=8时
6

//找第一个大于x的值.相当于事项了upper_bound的效果.
bool cmp(int a,int b){
	return a&lt;=b;
}
//x=6时
6

//找第一个绝对值大于等于x的值.
bool cmp(int a,int b){
	return abs(a)&lt;abs(b);
}
//x=7时
4
</pre>
