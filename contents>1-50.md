# 目录：甲级1~50题

## A1003. Emergency (25)###
https://www.patest.cn/contests/pat-a-practise/1003

类型：深搜，最短路径。

## A1007. Maximum Subsequence Sum (25)###
https://www.patest.cn/contests/pat-a-practise/1007

類型：動態規劃。

注意事項：
1. 是子序列兩頭的元素值，不是下標。樣例中元素的值和下表值正好是一樣的，所以沒有注意到錯誤。
儅序列全爲負數時，最大和認爲是0，然後輸出第一個和最後一個元素。

測試數據：
<pre>
//input
5
-1 -1 3 2 -2
//output
5 3 2
</pre>

## A1009. Product of Polynomials (25)####
https://www.patest.cn/contests/pat-a-practise/1009

题型：多项式乘法

注意事项：
1. 用到了double，%ld。注意浮点数在没有把握的情况下不要参加比较。
2. 注意输出的格式要求。
3. ！！！！！！可以只存储第一个数，第二个数在读入时和第一个数进行计算直接得出结果，这样可以节省空间。！！！！！！并且第一个数不用按照指数指示的位置存放，可以从0到k1-1依次存放，因为第二个数和和它相乘时从第一个数依次往后相乘，并不需要考虑找某个指数对应的系数，只有得到的结果才需要根据指数存储，因为可能还会有同样指数的值存入，如果此时要查找的话就太浪费时间。
4. 多项式乘法计算方法要会，该题中给的指数应该都是大于等于0的指数，当指数范围扩大且可能是小数时，考虑考虑怎么做！

## A1010. Radix (25)#####（自己做未ac）
https://www.patest.cn/contests/pat-a-practise/1010

类型：进制转换。二分查找。

注意事项：
1. 题意及其不清楚，所以要注意：
基数radix的范围最大为INT_MAX，即2^31-1；
已知进制的数默认对应的10进制不超过long long，而未知进制的数转换成10进制后可能是溢出的；
2. 遍历进制数的方法会超时。所以可以通过二分查找来确定进制是多少。
3. 進制範圍：做題時進制的下界可設為未知數（沒有確定基數的那個數）的每個位數中的最大值+1，上界設爲已知的那個數+1.
4. 據説暴力遍历会在测试点7超时。 二分搜索后，如果不考虑溢出会在测试点10报错。
5. 題中說可能有解不唯一的情況，擧個例子：2 2 1 4，答案為3到∞進制都是可以的，取最小解就應該是3.

## A1012. The Best Rank (25)###
https://www.patest.cn/contests/pat-a-practise/1012

类型：排序（stl（sort)，查找

注意事项：

1. 下面的代码比较啰嗦，前四个排序可以想办法合并成一个的。比如结构体里用一个数组SCORE[4]来表示三门分数即平均分，然后用一个全局变量i来依次表示0、1、2、3，则sort函数的cmp就可以根据score[i]来排名，用一个循环就可以代替四个排序代码块。
2. 学好英语。

## A1013. Battle Over Cities (25)##（嘗試用並查集再做一邊）
https://www.patest.cn/contests/pat-a-practise/1013

類型：連通圖（找不連通子圖的個數）。

注意事項：
1. 也可以用並查集來做。

## A1016. Phone Bills (25)#####（做得超级痛苦）
https://www.patest.cn/contests/pat-a-practise/1016

类型：排序，日期时间计算。

注意事项：
1. 一开始读错题，以为给的记录就是按时间顺序给的，所以没有排序，结果逻辑上非常复杂，还要用到字符串hash，但实际上记录未排序，需要人为排序，并且排序后再做就简单多了。
2. 其中处理时间差的部分比较麻烦。时间差可以用早一点的时间a反复加1分钟，当等于时间b的时候停止，这样做代码量小，但是计算次数感觉太多了。
3. 做题时建议把代码拆成一个一个函数，并且对一个一个函数单独测试正确性，因为写完了长长的代码之后出错时，再检查真的无从查起，肉眼看太累，有些地方比如stl调试又很难看出来对错。建议一定要养成良好的代码习惯。
4. 代码中接近末尾的地方有printf("Total amount: $%.2lf\n",sum);要注意是每个人的金额计算完才要输出，但并不是每个人都有有效通话记录，所以当名字改变开始计算另一个人的总费用时，并不是总是需要输出sum，所以之前的总费用是0的时候不要输出sum。这是个思维盲区，我自己根本没有注意到，所以要多积累做题经验，另外如果自己能想到所有可能出现的情况作为测试用例输入来测试代码正确性当然是坠吼的。

除了题目中给的，下面这个是《算法笔记》中给出的很好的测试样例：

<pre>10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line</pre>

## A1018. Public Bike Management (30)#####（看了答案，做了很多遍才對）
https://www.patest.cn/contests/pat-a-practise/1018

類型：最短路徑，圖的遍歷。

注意事項：
1. vector<int>的數組，被我用memset把所有位都置為1之後，運行出錯，但是置為0時，正常運行了，所以容器不要隨便用memset。
運行錯誤的代碼示例：
<pre>int main() {
	vector<int> a[3];
	memset(a, -1, sizeof(a));
	a[0].push_back(1);
	return 0;
}</pre>
2. 題目要理解清楚：<br/>
選擇距離最短的路徑；<br/>
然後選從PBMC出發到sp所需携帶車輛最小的路徑，此時已經把經過的路程上的所有借點調整成最佳；<br/>
上一步可能選出了多條路徑，所以從sp返回時，要看此時需要帶回去多少輛自行車，選最少的情況。（回去時就不用考慮也要找一條路將所有結點調整成最優狀態了）
3. dfs算法中，不能從sp倒著計算需要多少自行車、剩餘多少自行車，因爲後面多的自行車在前面是取不到的，衹有從0出發開始，在前面多的自行車，在後面才能用到，而前面缺少的自行車，衹能從0処管理中心補足。
4. dijkstra算法中，找最短距離的結點時，每次存儲暫時最短距離和結點下標的變量都要再找新的最短距離之前初始化，不要忘！

補充測試數據：
<pre>10 4 4 5
4 8 9 0
0 1 1
1 2 1
1 3 2
2 3 1
3 4 1</pre>

## A1020. Tree Traversals (25)##
https://www.patest.cn/contests/pat-a-practise/1020

类型：树的建立，树的遍历

## A1022. Digital Library (30)##
https://www.patest.cn/contests/pat-a-practise/1022

类型：映射（map容器）

注意事项：
1. getline结尾的\n不需要用getchar接收。用scanf时，希望后面的\n不影响下一次输入，可以用scanf("%d\n",&x);这种方式把后面的\n吃掉，其他多余字符同理。
2. id是7位数，所以需要%07d格式输出，否则会有错误，而且未必会提醒你是格式错误。
3. 函数传参时需用引用，否则会超时。
4. 下面的下面结构体以及结构体数组完全不需要，因为可以用临时变量读取一个书籍记录，存到相应map里，临时变量读取到的值不会再用，直接从map里找结果即可。
5. 一行字符串，获得由一个空格分隔的一个个单词时，由多种处理方法，下面仅是几个例子：
<pre>//第一种用getchar
char ch='0';string tmp;
while(ch!='\n'){
	tmp = "";
	while((ch=getchar())!=' '&&ch!='\n'){
		tmp+=ch;
	}
	mp[tmp].push_back(id);//把获得的一个单词tmp存入到map<string,vector<int> >的映射中。
}		
</pre>
<pre>//第二种主要用cin
while(cin&lt;&lt;tkey) {//好像只要还能获得输入数据就一直输入。
  map[key].push_back(id);//把获得的一个单词key存入到map<string,vector<int> >的映射中。
  char ch = getchar();//接收单词后面的空白字符，如果为\n需跳出循环。
  if(ch == '\n') break;
}
</pre>
## A1023. Have Fun with Numbers (20)###
https://www.patest.cn/contests/pat-a-practise/1023

类型：字符串处理（数字用字符串表示）。

注意事项：
1. 字符串最后的'\0'要谨慎处理。
2. string字符串是常量！

相关知识点：
string的相关用法：
erase函数：
1. string& erase (size_t pos = 0, size_t len = npos);
Erases the portion of the string value that begins at the character position pos and spans len characters (or until the end of the string, if either the content is too short or if len is string::npos.
Notice that the default argument erases all characters in the string (like member function clear).
2. iterator erase (const_iterator p);
Erases the character pointed by p.
3. iterator erase (const_iterator first, const_iterator last);
Erases the sequence of characters in the range \[first,last).

## A1024. Palindromic Number (25)###
https://www.patest.cn/contests/pat-a-practise/1024

类型：回文数，反转字符串，字符串所表示的数字的加减。

注意事项：
1. 手动处理数组时别忘了结尾的"\0"。

## A1025. PAT Ranking (25)####
https://www.patest.cn/contests/pat-a-practise/1025

注意：计算清数组元素有多少再申请！！

## A1028. List Sorting (25)
https://www.patest.cn/contests/pat-a-practise/1028

类型：排序。

## A1029. Median (25)###
https://www.patest.cn/contests/pat-a-practise/1029

类型：查找。中位数。

多种方法：
1. 轮流删除最大最小元素：由于数组a，b有序，所以最小元素一定在a和b数组的最右边的一个，最大在最左边。每次删除一对最大最小，当剩下两个元素时输出小的那个，剩下一个元素时直接输出。
2. 直接计算出中位数大小排第几，从最小数数到中位数所在位置：记录总共有多少个元素，数组a长n，b长m，mid=(n+m)/2,设置count记录已经计数多少数，分别指针i，j指向a和b的开头，那个数组指针指向位置较小就将哪个指针加1，且count加1，当count加到mid大小，即找到第mid大的值时，它即是整个数组的中位数。
3. 大概思路：取数组a和b的中位数ma和mb，如果ma>mb，则总的中位数mid在数组a中小于等于ma的部分，或数组b中大于等于mb的部分。因为如果mid在大于ma的部分的话，则a中至少有一半数都比mid小，且ma>mb,所以b中至少也有一半比mid小，所以总共至少有一半元素比该mid小，则此时mid不可能是中位数，与题矛盾。所以该算法每次都可以删除上一次操作剩下的元素的一半，复杂度平均为logn。
但需要注意的是，在去除一半元素的时候，如果确定去除的边界，这需要仔细讨论，要能把大于mid和小于mid的元素删除同样的数目。

不同方法的平均效率：方法3的效率最高，然后是2，然后是1。

## A1037. Magic Coupon (25)#
https://www.patest.cn/contests/pat-a-practise/1037

类型：贪心。

注意事项：
1. 使用贪心求得结果，前提是要能够证明使用贪心算法必定能取得最大结果。（注意到只有正数与正数相乘，以及负数与负数相乘才能取得正值，其他情况为0或为负都不需要考虑，因为加到结果里会让结果变小。所以可划分为正数和负数两个集合分别考虑。）

## A1038. Recover the Smallest Number (30)#####（自己没有做出来）
https://www.patest.cn/contests/pat-a-practise/1038

类型：贪心。

注意：
1. 得到字符串序列后需要去除前导零。如果字符串序列大小为0，输出0。
2. string的erase函数三种用法：
>（c++ 11）<br/>
>string& erase (size_t pos = 0, size_t len = npos);<br/>
>iterator erase (const_iterator p);<br/>
>iterator erase (const_iterator first, const_iterator last);

>（c++ 98）<br/>
>string& erase (size_t pos = 0, size_t len = npos);<br/>
>iterator erase (iterator p);<br/>
>iterator erase (iterator first, iterator last);

## A1039. Course List for Student (25)##
https://www.patest.cn/contests/pat-a-practise/1039

类型：哈希（查询），排序。

注意事项：
1. 根据学生名找相应记录时，用sort函数对学生名排序，再二分查找对应记录，会有一个记录超时。改用hash函数后，虽然没超时，但占用的内存空间太大。
同样也不可用map和string，会超时，cin和cout也不要用，注意到该题时间限制200ms，有些PAT20分的计算过程特别简单的题还给了400ms呢，所以这题时间要求算比较严的了，所以做题之前要先考虑时间，不要一拿来就做，然后发现通过不了。
2. 姓名处理技巧：比如定义vector<int> course[MAXC];char name[MAXN][5];其中int对应的是学生姓名所存储的位置,此时对学生姓名按字母序排序时，可以通过下标进行操作会更快。如下
<pre>sort(course[i].begin(),course[i].end(),cmp);
bool cmp(int a,int b){
  return strcmp(name[a],name[b])<0;
}</pre>

## A1040. Longest Symmetric String (25)###
https://www.patest.cn/contests/pat-a-practise/1040

類型：dp（回文串）

注意事項：
1. 衹要有字符串，則回文串長度至少為1.

## A1041. Be Unique (20)#
https://www.patest.cn/contests/pat-a-practise/1041

类型：计数。散列。

注意事项：

1.count用来统计各个数出现次数，但count里第一个unique的数字不一定就是所要找的数字，题目要求按bet顺序第一个独一无二的数字，而赌博中第一个独一无二的数字未必是count数组里从小到大第一个遇到计数为1的数字。

## A1044. Shopping in Mars (25)###
https://www.patest.cn/contests/pat-a-practise/1044

注意事项：
1. sum[i]存储第一个值到第i个值的和，所以某个钻石串[a,b]的长度可以用sum[b]-sum[a-1]直接计算，所以sum[0]应该不存储任何元素，且置为0，会便于计算。
另外用数组存放和的思路值得注意，不用数组存放单个钻石的值可以减少很多求和运算。并且数组的值表示某些项的和这种方法在动态规划的问题中经常能遇到。
2. 多学习各种算法吧，一些经典算法里的技巧和思想能让做题变得很快，而且有些算法本身就很精彩。
3. 用到upper_bound函数：ForwardIter lower_bound(ForwardIter first, ForwardIter last,const _Tp& val)算法返回一个非递减序列\[first, last)中的第一个大于等于值val的位置。

## A1045. Favorite Color Stripe (30)#####
https://www.patest.cn/contests/pat-a-practise/1045

類型：動態規劃，最長不下降子序列（LIS），最長公共子序列（LCS）

難度：5

注意事項：
1. 題意不清或容易忽視的地方：eva喜歡的序列裏的顔色都是不一樣的（如果序列裏有重複顔色就不好做了）；不一定所有喜歡的顔色都要出現。

測試數據：
<pre>
//如果用下面兩個測試數據無法做出正確結果，則pat中測試點4很可能也會出錯。
//input
6
5 2 3 1 5 6
14 3 3 3 2 2 2 2 1 5 2 2 2 2 6
//output
9
//input
6
5 2 3 1 5 6
6 2 3 6 2 2 1
//output
4

//下面兩個測試數據過不了，可能測試點2也過不了。
//input
6
5 2 3 1 5 6
6 2 3 5 1 1 1
//output
5
//input，主要需注意到5後面的兩個1出現時最大長度發生了變化，而兩個1後面的233出現之後最大程度又發生了變化。
6
5 2 3 1 5 6
6 2 3 5 1 1 2 3 3 1 1 1
//output
7
</pre>

## A1047. Student List for Course (25)#
https://www.patest.cn/contests/pat-a-practise/1047

类型：排序（统计每门课学习的人名再按字母序输出）。

## A1048. Find Coins (25)##
https://www.patest.cn/contests/pat-a-practise/1048

类型：类似于背包问题。

注意事项：
1. c用来记录某种面值的钱币有多少个，一般情况只要c对应值不等于0即可，但是当相同面值钱币相加时，需要c对应值不小于2。
2. 输出要求，如果有多对答案（v1，v2），输出v1最小的那对，而我并没有注意到这点，代码碰巧满足了这个条件，所以以后读题一定要仔细。

其他方法：
1. 哈希法：c数组用途不变，确定一个c[i]之后可以直接查询c[m-i]是否有值来得到结果，但此处c大小不能仅开到500，因为m-i可能会超过500。
2. 二分查找。

## A1049. Counting Ones (30)#####（太难了，我好抑郁）
https://www.patest.cn/contests/pat-a-practise/1049

类型：计数（计算1的个数）。

思路：
每次考虑某一位在1~n这些数内可能出现的次数。<br/>
令数为(left)x(right)，x为第k位（1代表个位），left表示k位左边若干位代表的数，right是右边。<br/>
* 当x==0，只有在左边取0\~left-1时第k位才会出现1，此时右边可以取遍0到(9...9)，即对应每个第k位的1右边都可取一共10^right个数。如123045百位为1的情况有：0001##-1221##，共123*(10^2)中取法。所以此时1的个数为：left*(10^(k-1))。
* 当x==1，如123145可把它看成[0,123099]中的1，和[123100,123145]中的1之和。前面一个区间的1的个数同上为123*(10^2),后面的区间第k位的1的个数为46个，即right+1。所以x==1时，第k为1的个数为：left*(10^(k-1))+right+1。
* 当x>=2，如123545中，0001##~1231##百位都为1，共有(123+1)*(10^3)个。所以当x>=2时，第k位1的总个数为(left+1)*(10^(k-1))。

难点：在于怎么划分数来统计1的个数。
如：有数abcd。
* 计算1的划分方法一：分别计算0-a000，a000-ab00，ab00-abc0,abc0-abcd中的1的个数再加在一起，虽然可以但是这种划分方法实现起来挺复杂的。（可以提前处理好x位数最多包含多少个1，也许可以帮助计算，如1位数最多1个1，2位数最多20个1，……。）
* 计算1的划分方法二：分别计算abc1，ab1d，a1bc，1bcd，即分别计算每一位为1时的数量，只需要讨论该位以外其它位有多少中组和情况即可。（这种方法容易让人糊涂的一点在于，当确定一位为1的时候，其他位可能也为1，反过来其他位为1的时候，这个数也可能为1，从而多次计算该数对应的1，容易让人误以为这种方法会重复计算1的个数，其实不会。比如计算1234的时候，在abc1的情况下，1231对应一个1，而1bcd的情况下，1231又对应一个1，注意此时它们对应的是不同位的1，所以虽然都是1231这个数，但是对于它计算两个1是正确的。我又要把自己绕晕了。）
