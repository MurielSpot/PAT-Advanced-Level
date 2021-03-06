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

## A1108. Finding Average (20)####
https://www.patest.cn/contests/pat-a-practise/1108

類型:判斷數字格式(判斷是否是一個數,這個數小數小於等於兩位;類似的問題還有,判斷一個表示法是否符合科學計數法,這類題做得總是不太好!!!)

注意事項:
1. 字符衹能是0-9,以及點和負號.
2. 負號衹能在第一位,但判斷符號是否在第一位,不能根據當前數字和是否是0,或者當前是否出現過數字,來判斷.可以用一個bool變量來標記第一個值.
3. 小數點可以在最後一位,逗號後面最多衹能有兩位小數.
4. 數的範圍需要在[-1000,1000]内.

5. -.9以及這樣的情況我并沒有把它看作無效,所以沒有考慮這種情況,測試點也全部通過了.另外網上說123.這樣的數據也算對的.

測試數據:
<pre>可以試試看下面這些數據能不能得到正確結果.
無效的數據:
--9
0-0
9..9
1001
1000.011</pre>

## A1109. Group Photo (25)###
https://www.patest.cn/contests/pat-a-practise/1109

類型:模擬(集體照站位),排序.

注意事項:
1. 題不好讀.
2. 劃分一行一行人數在數組中的位置,即確定左右邊界有點麻煩.

## A1110. Complete Binary Tree (25)###
https://www.patest.cn/contests/pat-a-practise/1110

類型:dfs/bfs.

注意事項:
1. 字符別忘了轉爲數字.注意'-'的情況.
2. 節點的下標可能是10,11,...,這種情況下用%c,衹能讀入第一個數字...否則導致答案錯誤和段錯誤!!!!!!!!!

思路:
1. dfs.<br/>
把結點錄入到[0,n-1]的數組裏,記錄它的子節點,同時記錄子節點的父節點為它;<br/>
由題意可知結果是一棵樹,然後找到父節點為-1的結點則為根節點;<br/>
對根節點進行dfs遍歷,記錄它們的節點編號,然後對它們按新的節點編號進行排序,如果排序的序號是從1到n的,説明是完全二叉樹,如果中間有哪個編號缺失説明不是完全二叉樹.
2. bfs.<br/>
代碼寫起來麻煩,但時間和空間用的都少.<br/>
層序遍歷,發現某個節點的某個孩子節點為空時,這個孩子節點後面的節點都應該不存在,所以如果當前或後面節點又有了不該存在的孩子節點,則不是完全二叉樹.

## A1111. Online Map (30)####
https://www.patest.cn/contests/pat-a-practise/1111

類型:最短路徑,dfs.

注意事項:
1. 數組名命名爲time會編譯錯誤,而且編譯錯誤時,點擊編譯錯誤幾個字,會給出具體錯誤,所以不用着急不知道錯了哪.<br/>
time在其它地方,不是我的代碼裏被使用了,所以不能用作數組名了.<br/>
編譯錯誤部分信息:<br/>
a.cpp:54:14: error: 'int time [510]' redeclared as different kind of symbol<br/>
 int time[MAXN];<br/>
/usr/include/time.h:192:15: note: previous declaration 'time_t time(time_t*)'<br/>
 extern time_t time (time_t *__timer) __THROW;<br/>
2. 題目沒理解清楚,一開始是fastest儅成了farthest,不知道怎么做直接放棄了這道題.<br/>
 然後又把one-way的意思當成是"有路徑",實際one-way是單向的意思.所以oneway為1,表示是單向的,否則是雙向的!!!!!!!!!!!!<br/>
 one-way is 1 if the street is one-way from V1 to V2, or 0 if not.<br/>
3. 輸出邊的時候用的是m變量,即邊的個數,不是n,n是頂點個數.
4. 找距離已訪問的節點的集合最近的結點時,不要忘了判斷結點是否是未訪問的!!!!!!!!1

## A1112. Stucked Keyboard (20)###
https://www.patest.cn/contests/pat-a-practise/1112

类型:字符串处理.

注意事项:
1. 注意什么时候用for,什么时候用while.

## A1113. Integer Set Partition (25)
https://www.patest.cn/contests/pat-a-practise?page=2

类型:集合

## A1114. Family Property (25)####
https://www.patest.cn/contests/pat-a-practise/1114

类型:连通图.

注意事项:
1. 数组范围要注意!比如是否入队的数组inq,一开始设置的大小为一千,但是注意到它对应的下标是每个人的id,而id范围是不大于一万,所以inq大小至少要为一万.
2. 为了孩子父母相互联系,构成完整的无向的连通图,则再输入孩子结点时,要把孩子结点的父母同时记录,输入父母时,父母的孩子也要相应添加上.
(这种做法可能会有重复记录父母或孩子的情况,可以添加去重的代码,但是重复记录也就是再父母那记录一次,孩子那再记录一次,所以重复次数二三次,而总结点数不大于1000,所以重复记录空间也够用,所以就没有判断是否重复记录.)
3. 最后排序时,按平均值排序,按为取平均值的总值排序会出错,因为每个家族的人数都是不同的.

## A1115. Counting Nodes in a BST (30)##
https://www.patest.cn/submissions/4351707/source

类型:二叉搜索树(建立,层数)

注意事项:
1. 求的是最后两层,不是深度为2和1的结点.所以需要先找到最大层数,再把最后两层的结点统计出来,用层序遍历比较简洁,可以再处理一层的时候直接记录该层的结点数.
2. 二叉树建树时,如果函数用的时引用,则传入一个空指针即可,如果传入的不是空指针,则第一个元素就不会插入到当前的根结点,因为它非空,而是插入到它的左子树或右子树.


## A1116. Come on! Let's C (20)##
https://www.patest.cn/contests/pat-a-practise/1116

類型:素數,映射.

注意事項:
1. 審題要仔細,比如某人有效的詢問過一次,再次詢問給出回答應該是checked.
2. id輸出不足4位要補0.

## A1117. Eddington Number(25)#####
https://www.patest.cn/contests/pat-a-practise/1117

類型:排序.

注意事項:
1. 題目晦澀難懂,大意是n個數裏,有e個比e大(相等不行)的值,找出滿足這個條件的e的最大值.<br/>
例子:<br/>
6 6 6 6 6 6 6<br/>
有7個比4大的值,所以如果說有4個比4大的值是可以的;<br/>
有7個比5大的值,所以如果說有5個比5大的值是可以的;<br/>
有0個比6大的值,有0個比7大的值...<br/>
所以最大的e為5.<br/><br/>
我之前的理解是正好有e個比e大的值,這道題中,比5大的值不正好是5個,比6大的值為0個,所以是無解.這種思路是錯的.<br/>

## A1118. Birds in Forest (25)###
https://www.patest.cn/contests/pat-a-practise/1118

類型:並查集

注意事項:
1. 並查集使用不熟練.

## A1119. Pre- and Post-order Traversals (30)###
https://www.patest.cn/contests/pat-a-practise/1119

類型:前序後序件數(不唯一),中序遍歷.

注意事項:
1. 樹不唯一的情況,pre數組根節點後面的那個節點肯定是左子樹或右子樹的根,在post裏面找這個節點的位置,如果在post根節點前面那個位置,則該節點是左子樹還是右子樹的根節點無法判斷.
唯一的情況:上面所説的節點如果不在post根節點前面那個位置,而是和根節點之間還隔有節點,説明中間多出來的節點肯定是右子樹的,所以上面所説的子樹的根節點肯定是屬於左子樹,此時可以唯一判斷一棵樹.

## A1120. Friend Numbers (20)#
https://www.patest.cn/contests/pat-a-practise/1120

类型:哈希(映射)

## A1121. Damn Single (25)##
https://www.patest.cn/contests/pat-a-practise/1121

类型:映射

注意事项:
1. 非单身,但是另一位没有来也算单独的.

## A1122. Hamiltonian Cycle (25)##
https://www.patest.cn/contests/pat-a-practise/1122

类型:图(简单环路).

注意事项:
1. 当序列最后一个元素不等于第一个元素时,肯定不是哈密顿回路,直接输出no;
当序列元素不等于图的顶点数加1,则不满足经过图中所有顶点这一条件,直接输出no;
当序列中有元素重复出现(除了开头和结尾这两个顶点元素),或者两个元素之间没有路径,都要输出no;
其它情况可输出yes.

其它:
1. 哈密顿图（哈密尔顿图）（英语：Hamiltonian path，或Traceable path）是一个无向图，由天文学家哈密顿提出，由指定的起点前往指定的终点，途中经过所有其他节点且只经过一次。在图论中是指含有哈密顿回路的图，闭合的哈密顿路径称作哈密顿回路（Hamiltonian cycle），含有图中所有顶点的路径称作哈密顿路径。
2. 简单回路:图的顶点序列中，除了第一个顶点和最后一个顶点相同外，其余顶点不重复出现的回路叫简单回路。或者说，若通路或回路不重复地包含相同的边，则它是简单的。

## A1123. Is It a Complete AVL Tree (30)###
https://www.patest.cn/contests/pat-a-practise/1123

类型:avl平衡二叉查找树,cbt完全二叉树.

注意事项:
1. avl的建立,调整等还需要更加熟悉.
2. 判断完全二叉树时,发现某个结点无孩子,则当前结点或之后结点都不能再出现孩子.

## A1124. Raffle for Weibo Followers (20)##
https://www.patest.cn/contests/pat-a-practise/1124

類型:映射.

注意事項:
1. 序號範圍是[1,m],所以處理循環退出邊界時不要出錯!!
2. 代碼不簡潔,輸入數據是就可以處理,不用把人名存到數組裏,另外不需要把結果再存到數組裏(因爲一開始看錯題,以爲第一行要輸出序號,之後多行輸出名字,所以用了ans數組,後來就懶得刪了).
末尾有很簡潔的別人寫的代碼.

## A1125. Chain the Ropes (25)##
https://www.patest.cn/contests/pat-a-practise/1125

類型:哈夫曼樹.

注意事項:
1. 題意不清:結果取不大於最大長度的最大整數,并不是最後一次取,而是每次得到新的繩子都要取整!!!!!!!!!所以第一次做用double型最後%.0lf輸出,最后一個測試點過不去!
另外,由於每次結果都要取整,先把繩子截成兩段再接在一起,和把繩子接在一起再截成兩段,得到的結果是不一樣的,應該取后一種!!!!!!!

思路:
哈夫曼樹的思想.(具體證明還沒想好)

## A1126. Eulerian Path (25)#####
https://www.patest.cn/contests/pat-a-practise/1126

類似:連通圖,頂點的度.(图论)

難度:5(題目好難懂)

注意事項:
1. 題沒看懂.題意是説题目说了欧拉路径没有奇度点，欧拉回路有且只有两个奇度点，其他非歐拉.<bt/>
百度百科中關於歐拉圖的介紹中有這樣一句:图 G 称为偶图(even graph)，如果G 中每个顶点的度数为偶数。容易发现，连通的偶图即为欧拉图。<bt/>
所以做題時:先确定连通性,不连通则为3;再判斷是欧拉图还是半欧拉图,点的度数全为偶数为欧拉图,恰好有两个点度数为奇数是半欧拉图，其余情况二者皆不是。

其他:<bt/>
[Euler tour]<bt/>
图的环游(tour)是指经过图的每条边至少一次的闭途位。欧拉环游是经过每条边恰好一次的环游。一个图若包含欧拉环游，则称为欧拉图(Euleriangraph)。<bt/>
类似地，经过图的每条边的迹称为图的欧拉达(Enlertrail)。这些术语之所以以欧拉命名，是因为欧拉首先研究了图中欧拉迹的存在问题。1736 年欧拉解决了著名的哥尼斯堡七桥问题。把哥尼斯堡七桥问题一般化，欧拉证明了如下定理：一个非空连通图是欧拉图当且仅当它的每个顶点的度数都是偶数。<bt/>
由此可得如下结论：一个连通图有欧拉迹当且仅当它的每个顶点的度数都是偶数，由此可得如下结论：一个连通图有欧拉迹当它至多有两个度数是奇数的顶点。<bt/>
图 G 称为偶图(even graph)，如果G 中每个顶点的度数为偶数。容易发现，连通的偶图即为欧拉图。<bt/>

## A1127. ZigZagging on a Tree (30)####
https://www.patest.cn/contests/pat-a-practise/1127

類型:中序後序建樹,層序遍歷按s路綫遍歷.

注意事項:
1. 寫循環時,要判斷邊界,變量別忘了加減.

## A1128. N Queens Puzzle (20)###
https://www.patest.cn/contests/pat-a-practise/1131

类型：模拟。

注意事项：
1. 我设的标记的数组标记的是某一行，某一左对角线和右对角线是否已经被占，已经被占后面那个元素再占则不满足要求。
2. 不知道设二维数组，只标记某个位置，而非一行或一条对角线，是否会超时。

## A1129. Recommendation System (25)###
https://www.patest.cn/contests/pat-a-practise/1129

类型：模拟。

注意事项：
1. while循环别忘了自加或自减,且要确定是加还是减!
2. 推荐仅仅是根据之前获取货物的情况，不需要把所有获取货物的情况遍历完。且第一次取货，由于之前没有人取过货，所以什么都不推荐。
3. 题一开始没看明白，建议以后看过题，根据自己思路对照答案演算一遍，判断自己思路对不对！

## A1130. Infix Expression (25)###
https://www.patest.cn/contests/pat-a-practise/1130

类型：中缀表达式，树的遍历。

注意事项：
1. data不一定只有一个字符，所以不要用char输入。
2. 最外层括号不需要输出，但只有一个元素时，它的两边也不需要输出括号。

## A1131. Subway Map (30)#####(做了很长时间)
https://www.patest.cn/contests/pat-a-practise/1131

类型：图(信息在邊上)。

难度:5.(比較複雜)

注意事项：
1. 重点时怎么把站点连成一个网,且同时又线路信息。建图时稍微麻烦一点，另一个难点是如何记录换乘情况。這類題要所需的信息都在邊上,所以要對邊進行操作!
2. 注意到邻接矩阵在找邻接边的时候代价很大,用邻接表存储更好.不过有人用邻接矩阵做了，而且用的dfs，好像也过了。
3. 火车线路倒着也能走.........
4. 计算经过的总站点数时，经过的第一个站点不需要算。也就是說經過的縂的小段綫路數.
5. 当起始地下一站就是目的地时，注意输出不要出错。对应测试点4.也就是說輸出的時候,對開頭和結尾都要單獨考慮,比如要考慮兩者之間是否有換乘,兩者之間是否有其他站點.
6. 预编译输入的IN如果为1，会出现运行超时错误。

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

## A1137. Final Grading (25)##
https://www.patest.cn/contests/pat-a-practise/1137

类型：排序，string映射数组下标。

难度：2

注意事项：
1. 第一次做的时候因为担心string会超时，做了一种很啰嗦的方法。再做的时候就用了string，map，sort，结果也没超时，大概复杂度也就10的6,7次方吧。

## A1139. First Contact (30)###
https://www.patest.cn/contests/pat-a-practise/1139

类型:图.

注意事项:
1. 注意数组要开到一万那么大,因为id为四位数.
2. id不足四位要补0.不然测试点1会错.
3. 会出现-0000，0000和-0000在数值上相同，所以需要输入字符串，根据字符串长度判断正负，然后再转成数字.这一点可能会卡住测试点2和5.
4. 注意有同性恋,题目并没有要求couple的两个朋友之间为异性.

其它做法:
1. 其实根本不需要用dfs.找一个v1的同性朋友,找一个v2的同性朋友,判断他们是否相识即可.
