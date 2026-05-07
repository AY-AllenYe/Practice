# 438. 找到字符串中所有字母异位词

## version 1

​	滑动窗口

​		窗口等于长度。每种字母数量相同时说明是异位词。



​	time: $O(m+(n-m)*\Sigma)$
​	space: $O(\Sigma)$
