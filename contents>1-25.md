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

## A1020. Tree Traversals (25)##
https://www.patest.cn/contests/pat-a-practise/1020

类型：树的建立，树的遍历

## A1025. PAT Ranking (25)####
https://www.patest.cn/contests/pat-a-practise/1025

注意：计算清数组元素有多少再申请！！
