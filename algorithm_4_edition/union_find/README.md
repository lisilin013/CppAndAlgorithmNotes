# Union Find Algorithm

## 1 并查集算法实现

## 2 union find算法应用
- **Percolation**
- Games (Go, Hex).
- Dynamic connectivity.
- Least common ancestor.
- Equivalence of finite state automata.
- Hoshen-Kopelman algorithm in physics.
- Hinley-Milner polymorphic type inference.
- Kruskal's minimum spanning tree algorithm.
- Compiling equivalence statements in Fortran.
- Morphological attribute openings and closings.
- Matlab's bwlabel() function in image processing

### Percolation
![](https://raw.githubusercontent.com/lisilin013/image_bed/master/markdown20190913140455.png)
物理模型描述：

- N by N grid
- 每一个site open的概率为$p$
- top和bottom是通过opensite联通的称之为percolation，这是一个很常见的物理模型，也叫过滤器

这个物理模型很难用数学公式去描述求解，但是可以利用我们的union find算法在计算机上进行仿真，不同的概率值，会得到系统是否可以达到percolate状态。如下图所示
![](https://raw.githubusercontent.com/lisilin013/image_bed/master/markdown20190913141002.png)
通过仿真我们会得到一个site open的概率值和system是percolation状态的函数关系图如下，这样虽然不能用数学计算，但是可以仿真出可靠的结果，只要仿真的数量足够多。
![](https://raw.githubusercontent.com/lisilin013/image_bed/master/markdown20190913141138.png)

### Monte Carlo simulation
- Initialize N-by-N whole grid to be blocked.
- Declare random sites open until top connected to bottom.
- Vacancy percentage estimates p*

![](https://raw.githubusercontent.com/lisilin013/image_bed/master/markdown20190913141404.png)
解决这个问题需要在我们原有的union find算法上做一点点改动，在top和bottom分别增加一个virtual site。然后建立我们的union，进行connected判断就可以了。
![](https://raw.githubusercontent.com/lisilin013/image_bed/master/markdown20190913141635.png)
