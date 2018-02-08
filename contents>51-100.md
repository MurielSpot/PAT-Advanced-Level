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

类型：哈希（字符->布尔），字符串处理（给出原字符串，找出另一条字符串与原字符串相比缺失的字符。

注意：
1. 用if还是while不要混。

## A1085. Perfect Sequence (25)#####（自己没做出来）
https://www.patest.cn/contests/pat-a-practise/1085

注意事项：
1. n平方的复杂度会超时，可用二分查找来解决问题，或者双指针法来避免复杂度过高。
2. 注意数据的表示范围：一般来说int是32位，所以表示范围为-2^31~2^31-1，即-2147483648~2147483647，而题中所给数字不超过10^9,但是两个数相乘可能会溢出。
3. c语言溢出问题：long long m;int a;int b;m=a*b;虽然m为长整型，但是并不意味着a*b就按长整型计算，a和b仍然按int型计算，所以可能会溢出，只是最后把结果存到了更长的存储空间里。所以应该明确地类型转换乘数：m=(long long)a*b。
4. stl容器algorithm里也有二分查找相关地函数，所以二分查找不需要自己实现。



>Binary search (operating on partitioned/sorted ranges):
><a href="http://www.cplusplus.com/reference/algorithm/lower_bound/">lower_bound (Return iterator to lower bound (function template) )</a>

>[upper_bound (Return iterator to upper bound (function template) )](http://www.cplusplus.com/reference/algorithm/upper_bound/)

>[equal_range (Get subrange of equal elements (function template) )](http://www.cplusplus.com/reference/algorithm/equal_range/)

>[binary_search (Test if value exists in sorted sequence (function template) )]:http://www.cplusplus.com/reference/algorithm/binary_search/
[binary_search (Test if value exists in sorted sequence (function template) )]

algorithm头文件参考资料：http://www.cplusplus.com/reference/algorithm/

## A1092. To Buy or Not to Buy (20)#
https://www.patest.cn/contests/pat-a-practise/1092

类型：哈希。
