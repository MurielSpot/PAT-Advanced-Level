# 目录：甲级51-100题

## A1051. Pop Sequence (25)##
https://www.patest.cn/contests/pat-a-practise/1051

类型：栈（栈的弹出序列是否合理）。队列。

注意事项：
1. q.pop()弹出队首元素。q.front()取队首元素。s.pop()弹出栈顶元素，s.top()取栈顶元素。
2. 判断一个序列是否满足栈弹出序列的要求时，一次判断的序列要读完，以免影响下一个序列的读取。
3. stl容器作为参数传递：
（网上说的http://blog.csdn.net/yishaxiaoyao/article/details/44344097）
STL容器类自带的拷贝构造函数和符号“=”对容器进行深拷贝：将STL容器当作参数传递给函数时，如果是值传递，则会自动调用STL容器的拷贝构造函数，如下面的程序片段。<br/>
vector的拷贝构造函数会根据传进来的vector开辟相同的空间，然后将传进来的vector的元素一个一个拷贝到新的vector中。在逐个拷贝元素的过程中，如果该元素不是int型，而是一个自定义的类，那么必须使用该自定义的类的拷贝构造函数。那么，此时是否为深拷贝，取决于该自定义的类是否重写了拷贝构造函数。<br/>
除了STL容器外，string类自带的拷贝构造函数也是深拷贝。

## A1053. Path of Equal Weight (30)###
https://www.patest.cn/contests/pat-a-practise/1053

类型：图的遍历（带权图）

注意事项：
1. “.”和“->”优先级和数组下标[]以及圆括号()的优先级一样高，而取址运算符&的优先级比它们低一级。
2. 第一次做的时候，在输入完孩子结点时没有立即按照它们的权值从大到小排序，而是获得结果后再比较各个结果序列的权值大小对结果进行排序，出现了段错误，目前还不不清楚为什么会出现段错误（最后一个测试点因为段错误未通过）。

## A1054. The Dominant Color (20)##
https://www.patest.cn/contests/pat-a-practise/1054

类型：计数（映射或哈希）。

## A1055. The World's Richest (25)#
https://www.patest.cn/contests/pat-a-practise/1055

类型：排序。

## A1056. Mice and Rice (25)####
https://www.patest.cn/contests/pat-a-practise/1056

类型：队列或数组（分组排名）。

注意事项：
1. 要理解题意：第二行输入中老鼠的重量是从0到np-1编号的选手对应的老鼠的重量，而第三行是选手的编号。针对第三行，把每ng个选手编为一组，然后选取优胜者进行下一轮比赛。
2. 其他思路：可以注意每次分为x组之后，被淘汰选手的排名为x+1，因为x组对应x个优胜者，所以剩下的就是并列的x+1名选手；最后别忘了处理第一名。

## A1063. Set Similarity (25)###
https://www.patest.cn/contests/pat-a-practise/1063

类型：集合。

注意事项：
1. 英语不好，题目没理解清楚，题目中的集合输出时是需要去重的，所以如果有两组数1，1，1，2，2和2，2，2，3输入，则两集合共有的数只有一个2，不能记为4个2（集合各有两个）或5个2（一共5个2）。
2. 了解set使用方法。
3. 百分号的输出方法：%%。

其他：可以自己考虑用哈希数组代替集合做做看。

## A1064. Complete Binary Search Tree (30)#####（没想到好的做法）
https://www.patest.cn/contests/pat-a-practise/1064

类型：二叉搜索树 + 完全二叉树。

思路：
1. 因为二叉搜索树的中序遍历正好是递增序列，所以可以对所有数据从小到大排序，在中序顺序建树时插入，再层序遍历。

注意事项：
1. memset在cstring头文件里。

## A1066. Root of AVL Tree (25)#####（！！AVL TREE！！）
https://www.patest.cn/contests/pat-a-practise/1066

类型：平衡二叉树

注意事项：
1. 平衡因子（balance factor）：一般用左子树高度减右子树高度。
设当前结点的平衡因子为n，n的左孩子的平衡因子为l，n的右孩子的平衡因子为r。
n=2,l=1;说明插入在左边孩子的左边。
n=2,l=-1;左边孩子的右边。
n=-2,l=1;右边孩子的左边。
n=-2,l=-1;右边孩子的右边。

## A1067. Sort with Swap(0,*) (25)###
https://www.patest.cn/contests/pat-a-practise/1067

注意事项：
1. swap(0,*)并不是下标为0和*的元素交换，而是数值为0和*的两个元素交换。
2. 循环中找不再本位的元素时，如果每次都从头开始枚举，有两组数据会超时，因为复杂度是二次方级的。要注意到，每个元素移动到本位之后，就不会出现0占用它的位置的情况，也就是不会再移动。所以找到当前数组不在本位的第一个元素之后，下次寻找可以从这个元素开始找。

## A1068. Find More Coins (30)#####(不太理解)
https://www.patest.cn/contests/pat-a-practise/1068

類型:01背包,dp

## A1070. Mooncake (25)##（使用浮点类型时出了很多错）
https://www.patest.cn/contests/pat-a-practise/1070

注意事项：
1. 当数据是double型时，一定要用%lf来读入，如果用了%d会出现莫名其妙的结果。
2. double最好不要参加比较，用的使用最好用极小值来矫正。因为即使它有时不影响结果，但是如果代码本身有错，很可能让人以为可能是double比较时出错引起的，其实并不是。
3. 题目中库存量全用int表示的时候，会有一个测试点答案错误，要改成double。以后代码中可能会用到double或者参与double运算的变量类型一定要设置为double。但是要注意整型才能做数组的下标，而浮点转换成整型可能会丢失精度，所以变量要是为double就不能做下标了。

## A1071. Speech Patterns (25)##
https://www.patest.cn/contests/pat-a-practise/1071

类型：字符串处理，映射（map字典）。

1. 判断是否字母或数字：extern int isalnum(int c);判断字符变量c是否为字母或数字，若是则返回非零，否则返回零。
判断是否是十进制数字：int isdigit(char c);<ctype.h>(C)<cctype>(C++)。
判断是否是字母：int isalpha ( int c );A value different from zero (i.e., true) if indeed c is an alphabetic letter. Zero (i.e., false) otherwise.
2. 问答：map<string, int>中的 int 的初始值为什么是 0？
用在标准库里的类和算法里的内置类型我见过的都是value initial的，这也算是不成文的规定吧？我记得c++primer
第五版里好像把这写成了一段话当做小经验。
3. scanf通配符的使用:可以用来向数组里只读入指定内容。
<pre>#include&lt;cstdio>
#include&lt;iostream>
#include&lt;string>
using namespace std;
int main(){
	char s[100];
	char discard[100];
	scanf("%[^0-9,a-z,A-Z]s",discard);//读取除去0-9，a-z，A-Z以后的字符。
	scanf("%[0-9,a-z,A-Z]s",s);//读取0-9，a-z，A-Z，遇到其他字符停止。
	printf("%s\n",s);
	return 0;
}</pre>

## A1072. Gas Station (30)#####（還需再看）
https://www.patest.cn/contests/pat-a-practise/1072

類型：最短路徑。

注意事項：出現了很多變量用錯位，小於等於寫成小於，小於寫成大於，這類問題，思路一定要清晰！！！

其他：vs2017，運行測試樣例時和所給結果一致，而dev最後的3.3被它計算成3.2。

## A1074. Reversing Linked List (25)##
https://www.patest.cn/contests/pat-a-practise/1074

类型：静态链表

注意事项：
1. 逆序也可考虑用堆栈。
2. vector的reverse自行了解。

## A1075. PAT Judge (25)###
https://www.patest.cn/contests/pat-a-practise/1075

类型：排序。

注意事项：
1. 编译无法通过对应的分值是0，某一题没有提交过对应的才是“-”。
2. 英语阅读要加强，不用理解错题意。
3. 细心：不要写错变量，括号嵌套不要出错。

## A1078. Hashing (25)####
https://www.patest.cn/contests/pat-a-practise/1078

类型：哈希（插入、冲突处理）。

注意事项：
1. vector的迭代器用法不熟：如it是它的一个迭代器，可以通过*it访问对应元素。
2. 哈希函数是用求出的大于msize的最小质数小取模，不是用所给的msize。
3. 散列表长度为某个4k+3形式的素数时，平方探测法可以探测到整个数组，所以此时可以用数组是否已经满来判断是否可以停止探测。

## A1079. Total Sales of Supply Chain (25)##
https://www.patest.cn/contests/pat-a-practise/1079

类型：图的遍历（bfs、dfs都可以做这道题）。

注意事项：
1. 要注意题目是否可以用图的遍历来做，经常会忘了可以用图的遍历来很方便地解决问题。

## A1080. Graduate Admission (30)#####
https://www.patest.cn/contests/pat-a-practise/1080

类型：排序（排名）。

注意事项：
1. 注意申请者的id就是最开始输入的顺序号（从0开始到n-1），重新根据成绩排序后，申请者的排序和他们的id就被打乱不是一一对应的了，输出时需要根据id号重新排序。所以排序后不能通过id号访问相应记录，比如id为3，排序后再位置5，再通过id访问的是3号位置的记录，会出错，我最初测试时有两个测试点总是过不了，是因为把id号存入vector，然后用id访问记录出错了，改成把排序后的序号i存入vector就解决了问题，但是花费了一两个小时的时间。

测试数据参考：（题目中给的测试数据比较特殊，排序后与排序前申请人的先后顺序没有太大改变，有些错误可能用这个测试数据测不出来。）

一、
<pre>11 6 3
2 1 2 2 2 3
60 60 2 3 5
90 100 1 2 0
70 80 1 2 3
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
100 90 0 3 4
80 70 1 3 2
100 100 0 1 2
100 100 0 2 4</pre>

二、所有考生都无法录取的边界情况：
<pre>5 5 3
0 0 0 5 5
100 100 0 1 2
100 99 1 2 0
99 100 2 1 0
99 99 1 0 2
98 98 2 0 1</pre>

## A1081. Rational Sum (20)####
https://www.patest.cn/contests/pat-a-practise/1081

类型：分数加减，分数化简。最大公约数。

注意事项：
1. 分母一定不能为0。
2. gcd函数，分数的加减运算，这些基本的计算都不熟悉。

需要了解的知识：<br/>
分数存储的标准:
1. 分母为非负数。
2. 分数为0，则规定分子为0，分母为1。
3. 分子和分母没有除了1以外的公约数。<br/>
结构体表示：
<pre>struct fraction{
  int up,down;//其中up可为负数，且此时进行加法计算不会出错，等同于减法计算。
 };</pre>
分数化简。<br/>
分数加法、减法。<br/>
分数输出：有整数、假分数、真分数等情况。对于已化简的分数：整数有分母等于1，假分数分子大于分母，除此以外的情况就是真分数分子小于分母。

最大公约数：gcd函数。

## A1083. List Grades (25)
https://www.patest.cn/contests/pat-a-practise/1083

类型：排序。

注意事项；
1. 注意此题中数组从1开始记录，所以sort的区间要相应从1开始。 
2. 没给n的范围，所以用vector做可能更严谨，不过这道题假设n最大为一万就能通过了。

## A1084. Broken Keyboard (20)#
https://www.patest.cn/contests/pat-a-practise/1084

类型：哈希（字符->布尔），字符串处理（给出原字符串，找出另一条字符串与原字符串相比缺失的字符）。

注意：
1. 用if还是while不要混。

## A1085. Perfect Sequence (25)#####（自己没做出来）
https://www.patest.cn/contests/pat-a-practise/1085

注意事项：
1. n平方的复杂度会超时，可用二分查找来解决问题，或者双指针法来避免复杂度过高。
2. 注意数据的表示范围：一般来说int是32位，所以表示范围为-2^31~2^31-1，即-2147483648~2147483647，而题中所给数字不超过10^9,但是两个数相乘可能会溢出。
3. c语言溢出问题：long long m;int a;int b;m=a*b;虽然m为长整型，但是并不意味着a*b就按长整型计算，a和b仍然按int型计算，所以可能会溢出，只是最后把结果存到了更长的存储空间里。所以应该明确地类型转换乘数：m=(long long)a*b。
4. stl容器algorithm里也有二分查找相关地函数，所以二分查找不需要自己实现。

>Binary search (operating on partitioned/sorted ranges):<br/>
><a href="http://www.cplusplus.com/reference/algorithm/lower_bound/">lower_bound (Return iterator to lower bound (function template) )</a><br/>
>[upper_bound (Return iterator to upper bound (function template) )](http://www.cplusplus.com/reference/algorithm/upper_bound/)<br/>
>[equal_range (Get subrange of equal elements (function template) )](http://www.cplusplus.com/reference/algorithm/equal_range/)<br/>
>[binary_search (Test if value exists in sorted sequence (function template) )](http://www.cplusplus.com/reference/algorithm/binary_search/)

algorithm头文件参考资料：http://www.cplusplus.com/reference/algorithm/

## A1086. Tree Traversals Again (25)#####（自己没做对）
https://www.patest.cn/contests/pat-a-practise/1086

类型：二叉树建树、遍历（根据中序序列获得后序序列；遍历非递归写法，根据栈的变化情况（先序中序的关系）判断树的结构）

思路：push则new一个结点并赋值，将其指针返回给父结点相应儿子，pop则返回NULL给父结点对应儿子。<br/>
讨论：<br/>
因为叶子结点n0的个数等于有两个孩子的结点的个数n2加1，即n0=n2+1。<br/>
而n0对应2个空结点，n1对应1个，n2为0个。<br/>
所以空结点数为2n0+n1=n0+n1+n2+1,即等于树中结点总数加1。<br/>
由此可知对某个树push和pop时，pop可以看作是对其左或右子树一个个空结点进行操作，每次pop让空结点返回NULL，push则让非空结点返回自己的位置。<br/>

其他思路：<br/>
已知中序序列堆栈压入弹出状况（入栈顺序其实就是先序遍历的顺序），可知根结点的位置，从而划分出左右子树，对于左右子树同理。根据中序序列LNR和先序序列NLR的关系来获得整个树，然后进行后序遍历。

注意事项：
1. 把应该为char的数组写成int arr[6],然后用%s输入数据，没有报错，但出现了莫名其妙的错误。

## A1087. All Roads Lead to Rome (30)###
https://www.patest.cn/contests/pat-a-practise/1087

類型：最短路徑，dfs。

注意事項：
1. 算平均快樂值得時候，是用整個路徑上的快樂值之和除以有快樂值得城市數，不包括起點城市，因爲起點沒有給快樂值，所以不算在内。

## A1088. Rational Arithmetic (20)##
https://www.patest.cn/contests/pat-a-practise/1088

类型：分数的四则运算，分数化简（会用到最大公约数）。

注意事项：
1. 虽然输入的数据能用int存，但是进行四则运算得到的结果可能大于int的范围，所以应该用long long型存储分子分母。否则会有两个测试点不通过。
2. 输入的数据可能是没有化简的，需要先化简再计算。

## A1089. Insert or Merge (25)###（各类基本排序算法不熟，应该要都能快速写出来。）
https://www.patest.cn/contests/pat-a-practise/1089

类型：排序（插入排序，归并排序）。

注意事项：
1. 用while时要注意是否需要改变指针。for(int i=0;i<n;i++)中i的改变已经在括号里实现了，而while中如果用i控制循环的跳出，需要手动改变i，不要忘了写，否则很容易死循环。
2. 循环语句中如果有条件已经满足答案结果，别忘了要及时跳出循环，不要浪费资源。
3. merge里对每个小区间span的排序，并没有用专门的归并算法的合并函数，而是用sort函数代替，因为本题数据量较小，这样做没问题。
4. 该题中归并函数用非递归算法容易一些。可以尝试用递归算法也做一遍，我还没有试。
5. 注意此题中初始序列不参与与目标序列相同的比较，否则可能导致某个数据产生双解。

测试数据：
<pre>//input
4
3 4 2 1
3 4 2 1</pre>

## A1090. Highest Price in Supply Chain (25)##
https://www.patest.cn/contests/pat-a-practise/1090

类型：图的遍历。

## A1091. Acute Stroke (30)###
https://www.patest.cn/contests/pat-a-practise/1091

类型：广度优先搜索（获得某连续区域），三维数组。

注意事项：
1. 访问某个像素相邻的点时，也可以用增量矩阵：
<pre>int x[6]={0,0,0,0,1,-1};
int y[6]={0,0,1,-1,0,0};
int z[6]={1,-1,0,0,0,0};
for(int i=0;i&lt;6;i++){
	newX=nowX+x[i];
	newY=nowY+y[i];
	newZ=nowZ+z[i];
}</pre>
2. 三维01矩阵不可以设为bool型。
3. dfs容易出现段错误，因为可能遍历深度较深，出现爆栈错误。
4. 该题中的三维矩阵：第一层为一片slice，然后第二、三维时一片中的行和列。

## A1092. To Buy or Not to Buy (20)#
https://www.patest.cn/contests/pat-a-practise/1092

类型：哈希。

## A1093. Count PAT's (25)##
https://www.patest.cn/contests/pat-a-practise/1093

类型：字符串子串。

注意事项：
1. 可以了解一些模运算的知识（摘自百度百科）：<br/>
>取模运算（“Modulo Operation”）和取余运算（“Complementation ”）两个概念有重叠的部分但又不完全一致。主要的区别在于对负整数进行除法运算时操作不同。
>
>对于整型数a，b来说，取模运算或者求余运算的方法都是：<br/>
1.求整数商：c=a/b;<br/>
2.计算模或者余数：r=a-c*b.<br/>
求模运算和求余运算在第一步不同: 取余运算在取c的值时，向0方向舍入(fix()函数)；而取模运算在计算c的值时，向负无穷方向舍入(floor()函数)。<br/>
例如：计算-7 Mod 4<br/>
那么：a = -7；b = 4；<br/>
第一步：求整数商c，如进行求模运算c = -2（向负无穷方向舍入），求余c = -1（向0方向舍入）；<br/>
第二步：计算模和余数的公式相同，但因c的值不同，求模时r = 1，求余时r = -3。<br/>
归纳：当a和b符号一致时，求模运算和求余运算所得的c的值一致，因此结果一致。<br/>
当符号不一致时，结果不一样。求模运算结果的符号和b一致，求余运算结果的符号和a一致。<br/>
另外各个环境下%运算符的含义不同，比如c/c++，java 为取余，而python则为取模。<br/>

>取模运算基本性质：
>1. 若p|(a-b)，则a≡b (% p)。例如 11 ≡ 4 (% 7)， 18 ≡ 4(% 7)
>2. (a % p)=(b % p)意味a≡b (% p)
>3. 对称性：a≡b (% p)等价于b≡a (% p)
>4. 传递性：若a≡b (% p)且b≡c (% p) ，则a≡c (% p)

>取模运算运算规则：<br/>
模运算与基本四则运算有些相似，但是除法例外。其规则如下：
>1. (a + b) % p = (a % p + b % p) % p
>2. (a - b) % p = (a % p - b % p) % p
>3. (a * b) % p = (a % p * b % p) % p
>4. a ^ b % p = ((a % p)^b) % p

## A1094. The Largest Generation (25)##
https://www.patest.cn/contests/pat-a-practise/1094

类型：图的遍历。

## A1095. Cars on Campus (30)####
https://www.patest.cn/contests/pat-a-practise/1095

类型:模拟.

难度:4.(一般想清楚再做,如果遇到了什么疏忽的地方,那这题就别得分了.)

注意事项:
1. 有一个巨大的坑点,一个车可能反复进入校园,所以它的值要不断累加.求最长停车时间不是指一次连续停车时间....

思路:<br/>
先按姓名排序，筛选出无效的记录，同时统计最长停车时间。<br/>
再按时间排序，进行查询的处理，因为查询是按时间递增的顺序，所以新的查询都从上一次查询开始。

## A1096. Consecutive Factors (20)#####（需要自己重做一遍，未全部通过测试点，看了别人的代码才通过）
/*
https://www.patest.cn/contests/pat-a-practise/1096

类型：数的因数。

注意事项；
1. 所有情况下1都不作为因数，比如质数只有1和它本身两个因数，应该输出这个数，而不是1。
2. 连乘数需要用long long型。

## A1097. Deduplication on a Linked List (25)###
https://www.patest.cn/contests/pat-a-practise/1097

类型：静态链表。

注意事项：
1. 取绝对值：#include<math.h>
<pre>int abs(int x);
long labs(int x);
double fabs(double x);</pre>
2. 做题过程中，有一段代码出现段错误，自己看代码，切记不要再犯这种错误！！！在从容器或类似结构中取数据时，要想一想这个数据能不能取到，比如容器大小是否为0，是否一个指针是空指针，堆栈是否有上限即堆栈是否已经满，等等。

## A1098. Insertion or Heap Sort (25)####（！！堆排序！！）
https://www.patest.cn/contests/pat-a-practise/1098

類型：插入排序，堆排序。

難度：4（堆排序太費事了，很不熟練）

注意事项：
1. 插入排序将无序区元素加入有序区时，用while不是if，不要疏忽。
2. 初始序列不参与比较！
<pre>//测试数据：
4
3 4 2 1
3 4 2 1
//輸出,如果初始序列參與比較,則第一次調整就會發現相同,進行第二次調整之後輸出的就是3 4 2 1,但題目雖然沒説清楚,但是實際比較的是第二次發現相同,輸出的是第三次調整的結果.
Insertion Sort
2 3 4 1
</pre>

## A1099. Build A Binary Search Tree (30)###
https://www.patest.cn/contests/pat-a-practise/1099

类型：二叉搜索树，层序遍历。

注意事项：
1. 注意结构体的构造函数的一种写法：node(int left_,int right_):left(left_),right(right_){}。

## A1100. Mars Numbers (20)###
https://www.patest.cn/contests/pat-a-practise/1100

类型：字符串处理（数字和字符串的转换）

注意事项：
1. 大于12的数并不是都是由两个字符串组成，如13、26、39等13的倍数，直接用tam、hel、maa表示即可，不是tam tret。同样，只有一个字符串的数并不一定是小于12的数。
2. (ch=getchar())!=" "出错，因为双引号对应字符串，单引号对应字符。要谨慎。

其他：
1. 字符串转整数：对于string，可以用stoi函数，注意c++11才能用该函数：
<pre>int stoi (const string&  str, size_t* idx = 0, int base = 10);
int stoi (const wstring& str, size_t* idx = 0, int base = 10);</pre>
* 第一个参数：需要转换的字符串。
* 第二个参数：<br/>
Pointer to an object of type size_t, whose value is set by the function to position of the next character in str after the numerical value.<br/>
This parameter can also be a null pointer, in which case it is not used.<br/>
大概意思就是说，如果idx不为空指针，则将字符串中数字后面的第一个字符的位置赋给这个指针。<br/>
* 第三个参数：需要转换成的数字的基数，默认10进制。
<pre>//第二个函数使用示例
//#include"stdafx.h"
#include&lt;iostream>
#include&lt;string>
using namespace std;
int main() {
	string a = "abcdef123";
	string b = "123cba";
	int pos;
	std::string::size_type sz;
	int num = stoi(b, &sz);
	cout &lt;&lt; "num=" &lt;&lt; num &lt;&lt; ",sz=" &lt;&lt; sz &lt;&lt; endl;
	//num = stoi(a, &sz);//这一句会让程序崩溃。
	return 0;
}
//output
num=123,sz=3
</pre>
网上说：stoi函数默认要求输入的参数字符串是符合int范围的[-2147483648, 2147483647]，否则会runtime error。atoi函数则不做范围检查，若超过int范围，则显示-2147483648（溢出下界）或者2147483647（溢出上界）。

2. 读取带空格的一行：
gets已经被新标准删了，用fgets获者gets_s代替。但是fgets好像会把\n也读入数组。fgets(num,10,stdin)。
或者用getline，遇到\n结束读取，getline(std::cin,num)。
3. string::npos的含义：Maximum value for size_t. npos is a static member constant value with the greatest possible value for an element of type size_t.
4. string的用法不熟。
<pre>//string用法简单的例子
#include&lt;cstdio>
#include&lt;iostream>
#include&lt;string>
using namespace std;
int main(){
	string a="abcdef abd";
	string b="cccc";
	int pos;
	printf("posBlank=%d\n",pos=a.find(' '));
	cout&lt;&lt;a.substr(0,pos)t&lt;&lt;"\n"t&lt;&lt;a.substr(pos+1)t&lt;&lt;"\n";
	printf("posBlank=%d\n",pos=b.find(' ')); 
	if(pos!=string::npos)
		coutt&lt;&lt;b.substr(0,pos)t&lt;&lt;"\n"&lt;&lt;b.substr(pos);
	return 0;
}
//output
posBlank=6
abcdef
abd
posBlank=-1
</pre>
