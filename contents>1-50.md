# 目录：甲级1~50题

## A1003. Emergency (25)###
https://www.patest.cn/contests/pat-a-practise/1003

类型：深搜，最短路径。

## A1009. Product of Polynomials (25)####
https://www.patest.cn/contests/pat-a-practise/1009

题型：多项式乘法

注意事项：

1. 用到了double，%ld。注意浮点数在没有把握的情况下不要参加比较。
2. 注意输出的格式要求。
3. ！！！！！！可以只存储第一个数，第二个数在读入时和第一个数进行计算直接得出结果，这样可以节省空间。！！！！！！并且第一个数不用按照指数指示的位置存放，可以从0到k1-1依次存放，因为第二个数和和它相乘时从第一个数依次往后相乘，并不需要考虑找某个指数对应的系数，只有得到的结果才需要根据指数存储，因为可能还会有同样指数的值存入，如果此时要查找的话就太浪费时间。
4. 多项式乘法计算方法要会，该题中给的指数应该都是大于等于0的指数，当指数范围扩大且可能是小数时，考虑考虑怎么做！

## A1012. The Best Rank (25)###
https://www.patest.cn/contests/pat-a-practise/1012

类型：排序（stl（sort)，查找

注意事项：

1. 下面的代码比较啰嗦，前四个排序可以想办法合并成一个的。比如结构体里用一个数组SCORE[4]来表示三门分数即平均分，然后用一个全局变量i来依次表示0、1、2、3，则sort函数的cmp就可以根据score[i]来排名，用一个循环就可以代替四个排序代码块。
2. 学好英语。

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

## A1020. Tree Traversals (25)##
https://www.patest.cn/contests/pat-a-practise/1020

类型：树的建立，树的遍历

## A1025. PAT Ranking (25)####
https://www.patest.cn/contests/pat-a-practise/1025

注意：计算清数组元素有多少再申请！！

## A1028. List Sorting (25)
https://www.patest.cn/contests/pat-a-practise/1028

类型：排序。

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

## A1048. Find Coins (25)##
https://www.patest.cn/contests/pat-a-practise/1048

类型：类似于背包问题。

注意事项：
1. c用来记录某种面值的钱币有多少个，一般情况只要c对应值不等于0即可，但是当相同面值钱币相加时，需要c对应值不小于2。
2. 输出要求，如果有多对答案（v1，v2），输出v1最小的那对，而我并没有注意到这点，代码碰巧满足了这个条件，所以以后读题一定要仔细。

其他方法：
1. 哈希法：c数组用途不变，确定一个c[i]之后可以直接查询c[m-i]是否有值来得到结果，但此处c大小不能仅开到500，因为m-i可能会超过500。
2. 二分查找。
