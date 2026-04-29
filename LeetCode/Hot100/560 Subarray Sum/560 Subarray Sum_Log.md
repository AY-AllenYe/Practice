# 560. 和为 K 的子数组

## version 1

​	循环遍历。

​	先找到 start_index，再计算start_index +1, start_index +2,.....,找到和为k后计数并重新计算start_index++。



​	time: $O(n^2)$
​	space: $O(1)$

## version 2

​	前缀和+哈希表

​	“$[start\_index,end\_index]$ 的和为 k”可以转换为
$$
pre[start\_index - 1] == pre[end\_index] - k
$$
​	通过递归思想，定义 $pre[0]$ 为 0 并记入哈希表，则能找到 第一串满足”和为k“的子串及位置下标，同理可以获得之后所有前缀和与“前缀和的差”，随即得到每个满足“和为k”的子串。统计个数。



​	time: $O(n)$
​	space: $O(n)$
