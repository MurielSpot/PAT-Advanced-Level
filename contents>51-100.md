# 目录：甲级51-100题

## A1055. The World's Richest (25)#

https://www.patest.cn/contests/pat-a-practise/1055

类型：排序。

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

难度：5

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

## A1092. To Buy or Not to Buy (20)#

https://www.patest.cn/contests/pat-a-practise/1092

类型：哈希。
