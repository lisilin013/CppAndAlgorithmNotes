# 1 social network connectivity
一个social network包含n个人成员和一个log文件，log文件里面包含m个时间戳，在每个时间点，会有一些成员形成friend pairs，请设计一个算法，判断，所有人都连接到一起的时候，最早是什么timestamp？

>使用union find算法，在原来的weighted quick union find with path compression的基础上，增加一个成员变量cnt_来记录component的数量，也就是记录tree的个数，所有人pair到一起的时候，tree的数量为1，也就是cnt_==1成立。
cnt_在合并分支的时候进行cnt_--进行更新

# 2 Union-find with specific canonical element
将方法𝚏𝚒𝚗𝚍(i)添加到union-find数据类型，以便𝚏𝚒𝚗𝚍(i)返回包含i的连接组件中的最大元素。 𝚞𝚗𝚒𝚘𝚗(),𝚌𝚘𝚗𝚗𝚎𝚌𝚝𝚎𝚍()和𝚏𝚒𝚗𝚍()都应该采用对数时间。

这个只需要将标准的weighted quick union算法的数据结构转换成使用优先级队列代替tree结构即可

# 3 
![](https://raw.githubusercontent.com/lisilin013/image_bed/master/markdown20190913154626.png)
