# 目录：甲级51-100题
## A1055. The World's Richest (25)#
https://www.patest.cn/contests/pat-a-practise/1055

类型：排序。

## A1067. Sort with Swap(0,*) (25)###
https://www.patest.cn/contests/pat-a-practise/1067

注意事项：
1. swap(0,*)并不是下标为0和*的元素交换，而是数值为0和*的两个元素交换。
2. 循环中找不再本位的元素时，如果每次都从头开始枚举，有两组数据会超时，因为复杂度是二次方级的。要注意到，每个元素移动到本位之后，就不会出现0占用它的位置的情况，也就是不会再移动。所以找到当前数组不在本位的第一个元素之后，下次寻找可以从这个元素开始找。

## A1070. Mooncake (25)##（使用浮点类型时出了很多错）
https://www.patest.cn/contests/pat-a-practise/1070

注意事项：
1. 当数据是double型时，一定要用%lf来读入，如果用了%d会出现莫名其妙的结果。
2. double最好不要参加比较，用的使用最好用极小值来矫正。因为即使它有时不影响结果，但是如果代码本身有错，很可能让人以为可能是double比较时出错引起的，其实并不是。
3. 题目中库存量全用int表示的时候，会有一个测试点答案错误，要改成double。以后代码中可能会用到double或者参与double运算的变量类型一定要设置为double。但是要注意整型才能做数组的下标，而浮点转换成整型可能会丢失精度，所以变量要是为double就不能做下标了。

## A1075. PAT Judge (25)###
https://www.patest.cn/contests/pat-a-practise/1075

类型：排序。

注意事项：
1. 编译无法通过对应的分值是0，某一题没有提交过对应的才是“-”。
2. 英语阅读要加强，不用理解错题意。
3. 细心：不要写错变量，括号嵌套不要出错。

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

## A1083. List Grades (25)
https://www.patest.cn/contests/pat-a-practise/1083

类型：排序。

注意事项；
1. 注意此题中数组从1开始记录，所以sort的区间要相应从1开始。 

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

## A1092. To Buy or Not to Buy (20)#
https://www.patest.cn/contests/pat-a-practise/1092

类型：哈希。

## A1093. Count PAT's (25)##
https://www.patest.cn/contests/pat-a-practise/1093

注意事项：
1. 可以了解一些模运算的知识（摘自百度百科）：<br/>
>取模运算（“Modulo Operation”）和取余运算（“Complementation ”）两个概念有重叠的部分但又不完全一致。主要的区别在于对负整数进行除法运算时操作不同。

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
1. 若p|(a-b)，则a≡b (% p)。例如 11 ≡ 4 (% 7)， 18 ≡ 4(% 7)
2. (a % p)=(b % p)意味a≡b (% p)
3. 对称性：a≡b (% p)等价于b≡a (% p)
4. 传递性：若a≡b (% p)且b≡c (% p) ，则a≡c (% p)

>取模运算运算规则：<br/>
模运算与基本四则运算有些相似，但是除法例外。其规则如下：
1. (a + b) % p = (a % p + b % p) % p
2. (a - b) % p = (a % p - b % p) % p
3. (a * b) % p = (a % p * b % p) % p
4. a ^ b % p = ((a % p)^b) % p

