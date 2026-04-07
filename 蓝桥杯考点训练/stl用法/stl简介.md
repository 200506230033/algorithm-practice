# __简介STL__

# 1. __线性容器(Vector & String)__
## __vector__
### 核心操作：
1. push_back()尾部追加
2. pop_back()尾部删除
3. size()获取元素个数
### 注意：
尽量不要头插，会时间复杂度超标

## __String__
### 核心操作:
1. s.substr(pos,len):截取从pos开始长度为len的子串
2. s.find("abc"):在字符串中查找子串
### 注意:
支持直接用+拼接字符串，支持使用< ,> ,=进行字典序比较

# 2. __搜索算法(Stack & Queue)__
|容器名称|物理性质|核心底层方法|运用场景|
|----------|----------|----------|----------|
|stack|后进先出|push(),pop(),top()|括号匹配问题，表达式求值，单调栈找最近的极值|
|queue|先进先出|push(),pop(),front()|bfs,迷宫找最短路径|

# 3.__去重与映射(Set & Map)__
## __自动去重排序机(Set)__
按key自动升序排序
## __键值对映射(Map)__
可以将任何类型映射到任何类型，例如map<string,int>可以直接记录每个string出现的次数——map["zhangsan"]++

# 4.__进阶神器(Priority_queue & Pair)__
## __自动排序队列(Priority_queue)(优先队列)__
每次存入数据，会自动把最大或者最小元素浮到顶端
默认形态(大根堆)：priority_queue<int> q 每次q.top()取的是最大值
## __pair__
同时绑定两个变量(x与y)
pair<int,int> p = {1,2},取值用p.first和p.second