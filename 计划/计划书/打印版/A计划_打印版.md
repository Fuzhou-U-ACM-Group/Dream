[TOC]

### 【3】扩展欧几里得/费马小定理/欧拉定理/逆元/筛法/卢卡斯定理

一次同余方程$ax=b\pmod{p}$，有解条件：$gcd(a,p)|b$

设$a,b,p$约去$gcd(a,p)$为$a',b',p'$，则：$a'x=b'\pmod{p'},a'\perp p'$

故得到特解：$x_0=a'^{-1}b'\pmod{p'}$，显然通解$x\pmod{p}$有$gcd(a,p)$种

### 【8】群论基础与$Polya$计数法定理，$bunside$引理

- 群作用

  - 定义

    - **![[公式]](https://www.zhihu.com/equation?tex=G) 为一个群， ![[公式]](https://www.zhihu.com/equation?tex=X) 为一个集合，那么 ![[公式]](https://www.zhihu.com/equation?tex=G) 在 ![[公式]](https://www.zhihu.com/equation?tex=X) 上的作用定义为一个映射：**

      **![[公式]](https://www.zhihu.com/equation?tex=G%5Ctimes+X%5Crightarrow+X) ，其将一个有序对 ![[公式]](https://www.zhihu.com/equation?tex=%28g%2Cx%29) 映射到 ![[公式]](https://www.zhihu.com/equation?tex=g%5Bx%5D) ，其中 ![[公式]](https://www.zhihu.com/equation?tex=g%5Cin+G%2Cx%5Cin+X%2Cg%5Bx%5D%5Cin+X)**

  - 性质

    - **![[公式]](https://www.zhihu.com/equation?tex=e%5Bx%5D%3Dx)**
    - **![[公式]](https://www.zhihu.com/equation?tex=%5Cforall+g_1%2Cg_2%5Cin+G%2Cg_1%5Bg_2%5Bx%5D%5D%3D%28g_1g_2%29%5Bx%5D)**

  - Cayley定理推论

    - 任意一个群在集合上的作用的实质都是与其同构的一个变换群在集合上的作用

  - 群作用下可相互转化的等价关系：

    - **![[公式]](https://www.zhihu.com/equation?tex=%5Cforall+x%2Cy%5Cin+X%2Cx%5Csim+y) 当且仅当 ![[公式]](https://www.zhihu.com/equation?tex=%5Cexists+g%5Cin+G%2C%5C+s.t.%5C+g%5Bx%5D%3Dy)**

  - 轨道

    - 定义
      - **![[公式]](https://www.zhihu.com/equation?tex=O_x) 为元素 ![[公式]](https://www.zhihu.com/equation?tex=x) 所在的由关系 ![[公式]](https://www.zhihu.com/equation?tex=%5Csim) 导出的等价类，被称为 ![[公式]](https://www.zhihu.com/equation?tex=x+) 所在的轨道**
    - 性质
      - **![[公式]](https://www.zhihu.com/equation?tex=%5Cforall+x%2Cy%5Cin+X%2Cx%5Csim+y) 当且仅当 ![[公式]](https://www.zhihu.com/equation?tex=O_x%3DO_y)**
      - **任意两个轨道要么相同要么不交**
      - **所有不同轨道给出了集合 ![[公式]](https://www.zhihu.com/equation?tex=X) 的一个划分，即在 ![[公式]](https://www.zhihu.com/equation?tex=X) 每条不同轨道上选取一个元素组成集合 ![[公式]](https://www.zhihu.com/equation?tex=I) 的话，有 ![[公式]](https://www.zhihu.com/equation?tex=X%3D%5Cbigcup_%7Bx%5Cin+I%7DO_x)**
      - ![[公式]](https://www.zhihu.com/equation?tex=%5Csum_%7Bx%5Cin+X%7D+%5Cfrac%7B1%7D%7B%7CO_x%7C%7D%3Dn) 为不同轨道个数

  - 稳定化子

    - 定义
      - **对于 ![[公式]](https://www.zhihu.com/equation?tex=x%5Cin+X) ，![[公式]](https://www.zhihu.com/equation?tex=G_x%3D%5Cleft+%5C%7B+g%5Cin+G%7Cg%5Bx%5D%3Dx+%5Cright+%5C%7D) 被称为群作用下元素 ![[公式]](https://www.zhihu.com/equation?tex=x) 的稳定化子**
      - **稳定化子必定是作用群 ![[公式]](https://www.zhihu.com/equation?tex=G) 的子群**

  - Lagrange公式

    - ![[公式]](https://www.zhihu.com/equation?tex=x) **所在轨道元素个数等于 ![[公式]](https://www.zhihu.com/equation?tex=x) 的稳定化子的不同陪集数**
    - $|O_x|=|G/G_x|=\frac{|G|}{|G_x|}$

- $bunside$引理

  - 群作用应用：将**![[公式]](https://www.zhihu.com/equation?tex=X) 看作是所有染色方案组成的集合， ![[公式]](https://www.zhihu.com/equation?tex=G) 看作是给定对称意义下的所有变换构成的群**，**轨道 ![[公式]](https://www.zhihu.com/equation?tex=O_x) 包含的元素都是在对称意义下与 ![[公式]](https://www.zhihu.com/equation?tex=x) 相同的染色方案**，**![[公式]](https://www.zhihu.com/equation?tex=G_x) 中元素都是保持染色方案 ![[公式]](https://www.zhihu.com/equation?tex=x) 不变的变换**，所需要求的在对称意义下本质不同的非同构的染色方案数即**不同轨道的数量$n$**
  - 不动点集合：**![[公式]](https://www.zhihu.com/equation?tex=%5Cpsi%28g%29%3D%5Cleft+%5C%7B+x%5Cin+X%7C+g%5Bx%5D%3Dx%5Cright+%5C%7D) 为在 ![[公式]](https://www.zhihu.com/equation?tex=g) 作用下不变的元素的集合**
  - 算两次思想：考虑不动元祖$(g,x)$表示被作用元素$x$为变换$g$下的一个不动点，对其进行计数
    - ![[公式]](https://www.zhihu.com/equation?tex=%5Csum_%7Bg%5Cin+G%7D%7C%5Cpsi%28g%29%7C%3D%5Csum_%7Bx%5Cin+X%7D%7CG_x%7C)。
    - ![[公式]](https://www.zhihu.com/equation?tex=%5Csum_%7Bg%5Cin+G%7D%7C%5Cpsi%28g%29%7C%3D%5Csum_%7Bx%5Cin+X%7D%5Cfrac%7B%7CG%7C%7D%7B%7CO_x%7C%7D%3D%7CG%7C%5Csum_%7Bx%5Cin+X%7D+%5Cfrac%7B1%7D%7B%7CO_x%7C%7D)$=|G|n$
    - $n=$![[公式]](https://www.zhihu.com/equation?tex=%5Cfrac%7B1%7D%7B%7CG%7C%7D%5Csum_%7Bg%5Cin+G%7D%7C%5Cpsi%28g%29%7C)
    - **群中元素的不动点个数的平均值就是不同轨道的个数**
  - 简单的例题
    - ![[公式]](https://www.zhihu.com/equation?tex=6) 种颜色对立方体的六个面染色，每个面颜色必须不同，立方体可以在空间任意转动，求不同染色方案数。

- $Polya$计数法

  - 基础
    -  **![[公式]](https://www.zhihu.com/equation?tex=A) 为被染色块构成的集合， ![[公式]](https://www.zhihu.com/equation?tex=C) 为所有颜色构成的集合**， ![[公式]](https://www.zhihu.com/equation?tex=%7CA%7C%3Dn%2C%7CC%7C%3Dm) ，那么任意一个**映射 ![[公式]](https://www.zhihu.com/equation?tex=f%3AA%5Crightarrow+C)** 都代表了一个染色方案，被称为一个**染色函数**。 ![[公式]](https://www.zhihu.com/equation?tex=C%5EA) 即表示所有的染色函数 ![[公式]](https://www.zhihu.com/equation?tex=f) 构成的集合。 ![[公式]](https://www.zhihu.com/equation?tex=G) 为 ![[公式]](https://www.zhihu.com/equation?tex=A) **上的一个置换群**，包含了染色块之间“对称关系”的含义。**![[公式]](https://www.zhihu.com/equation?tex=X) 是所有染色函数组成的集合而不再是不同染色方案的集合**。
    -  定义![[公式]](https://www.zhihu.com/equation?tex=G) 作用在 ![[公式]](https://www.zhihu.com/equation?tex=C%5EA) 上的**群作用**： ![[公式]](https://www.zhihu.com/equation?tex=g%5Bf%5D%3Dfg%5E%7B-1%7D)
    -  **对称意义下的不同染色方案数仍旧等于这个群作用中的不同轨道的个数**
  - 核心
    - 考虑$g$为一个置换，考虑其包含的一个轮换，其中涉及到的元素，必须被染成相同的颜色
    - 因此在置换$g$作用下保持不变的方案有：$m^{k(g)}$，$k(g)$为其轮换个数
    - **不同轨道个数为** ![[公式]](https://www.zhihu.com/equation?tex=%5Cfrac%7B%5Csum_%7Bg%5Cin+G%7Dm%5E%7Bk%28g%29%7D%7D%7B%7CG%7C%7D)
    - 关键在于如何求置换群中轮换个数的分布，完整置换群的轮换分布可以与生成函数结合
  - 定理
    - **已知 ![[公式]](https://www.zhihu.com/equation?tex=%7CA%7C%3Dn%2C%7CC%7C%3Dm%2CG) 为 ![[公式]](https://www.zhihu.com/equation?tex=A) 上的置换群，则所有不同轨道个数为** ![[公式]](https://www.zhihu.com/equation?tex=%5Cfrac%7B%5Csum_%7Bg%5Cin+G%7Dm%5E%7Bk%28g%29%7D%7D%7B%7CG%7C%7D) 。

- 带权$bunside$引理

  - 权函数
    - 由于同一个轨道中的染色方案是等价的，因此应该有相同的权，令$\omega(x)$表示染色方案$x$的权，轨道的权等于其包含元素的权
    - 我们不再求不同轨道数，转而求不同轨道权之和![[公式]](https://www.zhihu.com/equation?tex=%5Csum_%7Bi%3D1%7D%5EN%5Comega%28O_i%29)，当权取$1$时被化归
  - 核心
    - ![[公式]](https://www.zhihu.com/equation?tex=%5Csum_%7Bi%3D1%7D%5EN%5Comega%28O_i%29%3D%5Csum_%7Bx%5Cin+X%7D%5Cfrac%7B%5Comega%28x%29%7D%7B%7CO_x%7C%7D)。
    - ![[公式]](https://www.zhihu.com/equation?tex=%5Csum_%7Bi%3D1%7D%5EN%5Comega%28O_i%29%3D%5Cfrac%7B1%7D%7B%7CG%7C%7D%5Csum_%7Bg%5Cin+G%7D%5Csum_%7Bx%5Cin+%5Cpsi%28g%29%7D%5Comega%28x%29)。
    - **所有轨道的权之和等同于群中每个元素对应的不动点的权的平均数**

- 带权$Polya$定理

  - 权函数

    - 考虑**![[公式]](https://www.zhihu.com/equation?tex=f%5Cin+C%5EA) 为染色函数，其中 ![[公式]](https://www.zhihu.com/equation?tex=A) 为被染色块集合， ![[公式]](https://www.zhihu.com/equation?tex=C) 为颜色的集合， ![[公式]](https://www.zhihu.com/equation?tex=%7CA%7C%3Dn%2C%7CC%7C%3Dm) ，权函数 ![[公式]](https://www.zhihu.com/equation?tex=%5Comega) 定义在集合 ![[公式]](https://www.zhihu.com/equation?tex=C) 上， ![[公式]](https://www.zhihu.com/equation?tex=G) 仍为 ![[公式]](https://www.zhihu.com/equation?tex=A) 上的一个置换群**
    - **![[公式]](https://www.zhihu.com/equation?tex=%5Comega%28f%29%3D%5Cprod_%7Ba%5Cin+A%7D%5Comega%28f%28a%29%29) 为染色函数 ![[公式]](https://www.zhihu.com/equation?tex=f) 的权**，**染色函数的权等同于其将所有染色块映射到的颜色所具有的权的积**

  - 定理

    - ![[公式]](https://www.zhihu.com/equation?tex=%5Comega%28f%29%3D%5Cprod_%7Ba%5Cin+A%7D%5Comega%28f%28a%29%29%3D%5Comega%28c_1%29%5E%7B%7CA_1%7C%7D...%5Comega%28c_%7Bk%28g%29%7D%29%5E%7B%7CA_%7Bk%28g%29%7D%7C%7D)。其中$k(g)$表示$g$的轮换个数，$A_{i}$表示第$i$个轮换的符号集合，即涉及到的被作用元素集合；$c_i$表示第$i$个轮换被染的颜色。

    - ![[公式]](https://www.zhihu.com/equation?tex=%5Csum_%7Bf%5Cin+%5Cpsi%28g%29%7D%5Comega%28f%29%3D%5Csum_%7Bc_1%2C...%2Cc_%7Bk%28g%29%7D%5Cin+C%7D%5Comega%28c_1%29%5E%7B%7CA_1%7C%7D...%5Comega%28c_%7Bk%28g%29%7D%29%5E%7B%7CA_%7Bk%28g%29%7D%7C%7D)。

      ![[公式]](https://www.zhihu.com/equation?tex=%3D%5Cprod_%7Bi%3D1%7D%5Ek%28%5Csum_%7Bc%5Cin+C%7D%5Comega%28c%29%5E%7Bi%7D%29%5E%7Bc_i%28g%29%7D)。其中$c_i(g)$表示$g$中长度为$i$的轮换个数。$k=|A|$，即最大轮换长度。

    - 由带权的Burnside定理， ![[公式]](https://www.zhihu.com/equation?tex=%5Csum_%7Bi%3D1%7D%5EN%5Comega%28O_i%29%3D%5Cfrac%7B1%7D%7B%7CG%7C%7D%5Csum_%7Bg%5Cin+G%7D%5Csum_%7Bf%5Cin+%5Cpsi%28g%29%7D%5Comega%28f%29%3D%5Cfrac%7B1%7D%7B%7CG%7C%7D%5Csum_%7Bg%5Cin+G%7D%5Cprod_%7Bi%3D1%7D%5Ek%28%5Csum_%7Bc%5Cin+C%7D%5Comega%28c%29%5E%7Bi%7D%29%5E%7Bc_i%28g%29%7D)

      若记 ![[公式]](https://www.zhihu.com/equation?tex=%5Comega_i%3D%5Csum_%7Bc%5Cin+C%7D%5B%5Comega%28c%29%5D%5Ei)，表示一个长度为$i$的轮换的染色权之和，若权为$1$，即退化为方案数。

      则得到： ![[公式]](https://www.zhihu.com/equation?tex=%5Csum_%7Bi%3D1%7D%5EN%5Comega%28O_i%29%3D%5Cfrac%7B1%7D%7B%7CG%7C%7D%5Csum_%7Bg%5Cin+G%7D%28%5Comega_1%5E%7Bc_1%28g%29%7D...%5Comega_n%5E%7Bc_n%28g%29%7D%29)

  - 生成函数表示与优化

    - 令$\omega(c)$表示颜色$c$对应的占位符$x_c$，而不是简单的数值权，带入$Polya$定理可以很容易得到非同构的一些方案数，其包含的细节更加丰富，很容易和生成函数结合起来：例如表示每种颜色各使用多少个的非同构方案数等。
    - 令$\omega_i=\sum_{c\in C}x_c^i$表示轮换占位符，$\prod_{i=1}^nx_i^{c_i}$表示种类占位符，排列的$Cycle \space Indicator/Index$即是关于种类占位符的，只需要带入$x_i=\omega_i$即得到关于颜色占位符$\prod_{c \in C}x_c^{cnt_c}$的生成函数，此项前面的系数即表示非同构的颜色$c$恰好使用了$cnt_c$次的方案数(当然要除以$|G|$)

  - 简单例题

    - 求$n$个点的**边非同构**无向图(点不带标号)，求出恰好包含$i$条边的答案$ret_i$

      - 染色对象集合为$A=E$即完全图边集，颜色集合$C=\{x,y\}$表示两种颜色，取或者不去($y$可令为$1$)，置换群为全变换群$G=S_{|A|}$，按照上面的思路即可得到$n$个点$i$条边的答案

      - $n=3$的情况：![[公式]](https://www.zhihu.com/equation?tex=%5Csum_%7Bi%3D1%7D%5EN%5Comega%28O_i%29%3D%5Cfrac%7B%28b%2Bw%29%5E3%2B3%28b%2Bw%29%28b%5E2%2Bw%5E2%29%2B2%28b%5E3%2Bw%5E3%29%7D%7B6%7D%3Db%5E3%2Bw%5E3%2Bb%5E2w%2Bbw%5E2)

        表示共有$4$种，每种情况各$1$种

      - 注意由于占位符个数太多，会产生维数爆炸的情况，不便于求大的数据规模，因此当$i \le k$时，我们没有必要考虑$\omega_i,i>k$，直接令其为$1$即可；比如说题目只要求$i \le 4$

      - 就此问题，每种必然答案为$1$，总方案答案为$|E|+1$

    - 求$n$个点的**边非同构**无向图(点不带标号)，$ans_n$

      - 由于不要求具体的颜色数量限制，因此令权值为$1$即可，即令轮换占位符中的$x_c=1$
      - 令$M=\binom{n}{2}$，由定理知，不同的轨道数$N=\frac{1}{|G|}\sum_{g \in G}2^{k(g)}=\frac{1}{M!}\sum_{i=1}^M2^iS(M,i)=M+1$，其中$S$表示第一类斯特林数
      - 最后一步用到了斯特林数的行生成函数，这是一个上升阶乘幂


### 【9】离散对数与原根

[在线求原根](http://www.bluetulip.org/2014/programs/primitive.html?inputbox=6&resultbox=3+has+1+primitive+roots%2C+and+they+are+and+2.) [维基百科：原根](https://en.wikipedia.org/wiki/Primitive_root_modulo_n)

- 关于原根存在的充要条件：

  - 原根存在，则$m=1,2,4,p^a,2p^a$，其中$p$为奇质数且$a \ge 1$
  - $m \ge 3$原根存在，$x^2=1\pmod{p}$存在两解(模$p$意义下)
  - $m \ge 3$，$[1,m]$中与$m$互质的数的乘积模$m$为$-1$有原根，为$1$则无原根

  $$
  \prod_{k=1 \atop \mathrm{ged}(k, m)=1}^{m} k 
  \equiv\left\{\begin{aligned}-1 &(\bmod m) \space ,m\in [1,2,4,p^e,2p^e],p为奇质数 \\ 1 &(\bmod m),否则 \end{aligned}\right.
  $$

  上述结论在模$m^2$意义下未必成立，若成立则$m$为$Wilson \space  numbers$

  上述结论可推广到***任意有限交换群***，群中所有元素的乘积等于单位元或者一个阶为$2$的元素[维基百科](https://en.wikipedia.org/wiki/Wilson%27s_theorem#Gauss.27s_generalization)

  关于[威尔逊商数](https://en.wikipedia.org/wiki/Wilson_quotient)，其同余递推式与伯努利数有关
  $$
  \begin{array}{l}{W(p) \equiv B_{2(p-1)}-B_{p-1}\pmod{p}} \\ {p-1+p t W(p) \equiv p B_{t(p-1)} \pmod{p^2}}\end{array}
  $$

- 求原根算法$O(glog^2p)$

- $BSGS$及其扩展求离散对数$a^x=b\pmod{p}$即$x=log_ab\pmod{\phi(b)}$,$p$未必与$a$互质

  其算法实质是分块思想，扩展时两边同时消因子，复杂度$O(\sqrt{p})$

- 解高次同余方程$x^a=b\pmod{p}$，$p$为质数
  $$
  log_g^x=log_{g^a}x^a=log_{g^a}b\pmod{\phi(p)} \\
  alog_g^x=log_g^b\pmod{\phi(p)}
  $$
  转化为第二种情形，即$(g^a)^x=b\pmod{p}$

  如果要求所有$[0,p)$中的解，最好转化后用$exgcd$解普通同余方程或者求逆元，得到一个最小特解$log_g^x=a'^{-1}(log_g^b)'=y_0\pmod{\phi(p)'}$，则通解显然为：$y_0+k\phi(p)',k\in[some \space range]$

  通解在$\pmod{\phi(p)}$意义下有$gcd(a,\phi(p))$种，这与原高次同余方程的解$\pmod{p}$显然一一对应

- 解高次同余方程$x^a=b\pmod{p}$，$p\in Z^+$

  - 特判$p=1$，特判$a=0$
  - 将$p$分解质因子，要求$2$的指数不超过$2$，否则将因为没有原根，而报无解
  - 对每个$p^k$单独考虑，化为模数为质数的幂次的情况，最后中国剩余定理$crt$合并
  - 将$b$规范化($b \in [0,p^k)$)，然后分解为$b=b'p^{cnt}$，其中$p^{cnt}||b$
    - $cnt \ge k$，即$p^k|b$，此时$b$必为$0$，特判之
    - $cnt>0$，即$gcd(b,p^k)>1$，方程化为：$x^a/p^{cnt}=\frac{b}{p^{cnt}}\pmod{p^{k-cnt}}$
      - 特判$a \not|cnt$，此种情况认为无解
      - 化为：$(\frac{x}{p^{cnt/a}})^a=\frac{b}{p^{cnt}}\pmod{p^{k-cnt}}$，转化为互质情形
    - $cnt=0$，即互质情形，与上一个知识点类似，即当$p$为质数时
  - 常常构造最小非负整数解($crt$直接合并)，求解$\in[0,p)$个数，求所有解等
  - 求解个数，可以根据$crt$证明解的一一对应，即简单的利用乘法原理即可
  - 模板支持：$a \ge 0,1\le p<10^{12}$，分解后每类均有原根

- 原根的性质：

  - 数量：$\phi(\phi(p))$
  - 可相互表示：若$g$为原根，则$g^k$亦为原根，其中$k\perp\phi(p)$
  - 若$g$是质数$p$的一个原根，则$p^k$原根为：
    - $g+p$，当$g^{p-1}=1\pmod{p^2}$
    - $g$，否则
  - 若$g$是$p^k$的一个原根，则$2p^k$原根为：
    - $g$和$g+p^k$其中任意一个奇数
  - 若质数$p!=3$，则其所有原根之积$ret=1\pmod{p}$
  - $\forall$质数$p$，其所有原根之和$ret=\mu(p-1)\pmod{p}$
- 注意点：

  - 不确定是否不同余$0$，就要讨论及特判
  - 注意在数学上$0^0=1$，故同余方程$a^x=b\pmod{p}$，当$a=b=0$时，注意最小非负整数解$x_0=[p==1]\oplus1$


### 【33】$Kummer$定理

- $Legendre's \space formula$
  - $\nu_{p}(n !)=\sum_{i=1}^{\infty}\left\lfloor\frac{n}{p^{i}}\right\rfloor=\frac{n-s_{p}(n)}{p-1}$
  - 其中$\nu_{p}(x)$表示$x$在$p$进制下末尾$0$个数
- $Multinomial \space coefficient \space  generalization \space for \space  Kummer$
  - $\nu_{p}\left(\left(\begin{array}{c}{n} \\ {m_{1}, \ldots, m_{k}}\end{array}\right)\right)=\frac{1}{p-1}\left(\sum_{i=1}^{k} S_{p}\left(m_{i}\right)-S_{p}(n)\right)$
  - 其中$S_p(x)$表示$x$在$p$进制下的数位之和


### 【58】代数：$(min,+)$卷积/最值反演/$min-max$容斥

注意为叙述方便，以下公式中，$\subset$类似符号常常表示非空包含；

对$\empty$不定义$min/max/gcd/lcm$等函数；

且$d|S$表示$\forall x\in S,d|x$，此处$S\ne\empty$.

- 基础公式


$$
\max(S)=\sum_{T \subseteq S}(-1)^{|T|+1}\min(T)
$$

$$
\min(S)=\sum_{T \subseteq S}(-1)^{|T|+1}\max(T)
$$

- $k$大值扩展

$$
kth\max(S)=\sum_{T \subseteq S} (-1)^{|T|-k} {|T|-1 \choose k-1} \min(T)
$$

主要用于一些求期望的题目，求一些随机变量的最大值可以转化为求这些随机变量最小值实现

$kthmax$容斥这个系数是可以关于$k$进行递推的，如洛谷$4707$



- $lcm$与$gcd$扩展



$$
lcm(S)=\prod_{T\subset S}gcd(T)^{(-1)^{|T|+1}}
$$
- 一个加速求值的应用

如果函数$f$已知，且满足$gcd$分配率，即：
$$
f(gcd(S))=gcd(f(S))
$$
我们要求：
$$
g(n)=\prod _{T\subset[n]}f(gcd(T))^{(-1)^{|T|+1}},[n]=\{1,\cdots,n\}
$$
若函数$f$是某个函数$h$的偏序前缀积：
$$
f(n)=\prod _{d|n}h(d)
$$
则有
$$
g(n)=\prod _{d=1}^{n}h(d)
$$

证明过程：

令$S=[n]$，令$p=\lfloor \frac{n}{d} \rfloor$.

将$f(n)$带入到$g(n)$表达式中得：
$$
g(n)=\prod _{T\subset S}\prod_{d|gcd(T)}h(d)^{(-1)^{|T|+1}}\\
=\prod _{T\subset S}\prod_{d|T}h(d)^{(-1)^{|T|+1}}\\
\large=\prod_{d=1}^nh(d)^{\sum_{T\subset S,d|T}(-1)^{|T|+1}}\\
其中\sum_{T\subset S,d|T}(-1)^{|T|+1}=\sum_{k=1}^p\binom{p}{k}(-1)^{k+1}=1,命题得证。
$$

- 应用扩展

  - 假设$S$为一般有穷正整数集合，则令$S_d\subset S$表示$\{x|x\in S,d|x\}$，$S_d\ne \empty$.令$G=\{x|x|y ,y \in S\}$为$S$的约数集$,G$显然满足一种偏序单调性.
    $$
    \sum_{T\subset S_d}(-1)^{|T|+1}=1\\
    g(S)=\prod _{T\subset S}f(gcd(T))^{(-1)^{|T|+1}}=\prod_{d\in G}h(d)^{\sum_{T\subset S_d}(-1)^{|T|+1}}=\prod_{d\in G}h(d)
    $$
    也就是说，我们推广了函数$g$在更一般的有限集$S$中与函数$h$的关系，简单的类比可以得到：
    $$
    f(n)=\sum_{d|n}h(d)\quad \Longrightarrow \quad g(S)=\sum_{d\in G}h(d) \\
    其中：g(S)=\sum_{T\subset S}{(-1)^{|T|+1}}f(gcd(T))
    $$

  - 令$f(S)$表示$\{f(x)|x\in S\}$，注意$g(S)$不是这样定义的，则
    $$
    lcm(f(S))=\prod_{T\subset f(S)}gcd(T)^{(-1)^{|T|+1}}=\prod_{T\subset S}gcd(f(T))^{(-1)^{|T|+1}}\\
    =\prod_{T\subset S}f(gcd(T))^{(-1)^{|T|+1}}=g(S)=\prod_{d\in G}h(d)
    $$
    推论：当$S=[n]$时，$lcm(f(S))=\prod_{d=1}^nh(d)$.

    仍然可以做简单的类比，得到$gcd(f(S))$.

  - 与类$lucas$数列结合，求$lcm(f(S))$，因为该数列$f$满足$gcd$分配率，处理出$f$之后，莫比乌斯反演得到$h$，利用集合$S$构造下标$bool$数组$S$，对其做莫比乌斯变换，得到约数偏序集$G$，求$G$中所有元素$h$函数值之积


### 【59】几何：$Szemerédi–Trotter \space theorem$

定理内容：

It asserts that given n points and m lines in the Euclidean plane, the number of incidences (i.e., the number of point-line pairs, such that the point lies on the line) is


$$
O(n^{2/3}*m^{2/3}+n+m)
$$

### 【60】几何：三维叉积的应用

求过两点的直线方程一般形式，判断两直线关系，并且求交点坐标

代码短，精度高，不容易出错

参考：https://blog.csdn.net/abcjennifer/article/details/7584628

摘要如下：

$$
一般方程法：\\

直线的一般方程为F(x) = ax + by + c = 0。既然我们已经知道直线的两个点，\\

假设为(x_0,y_0), (x_1, y_1)，那么可以得到a = y_0 – y_1, b = x_1 – x_0, c = x_0y_1 – x_1y_0。\\

因此我们可以将两条直线分别表示为\\

F_0(x) = a_0x + b_0y + c_0 = 0, F_1(x) = a_1x + b_1y + c_1 = 0\\

那么两条直线的交点应该满足\\

a_0x + b_0y +c_0 = a_1x + b_1y + c_1\\

由此可推出\\

x = (b_0c_1 – b_1c_0)/D\\

y = (a_1c_0 – a_0c_1)/D\\

D = a_0b_1 – a_1b_0， (D为0时，表示两直线平行)\\
$$

### 【66】组合：一个经典的组合问题转化结论

对于前$n$个正整数构成的集合，求所有$k$元子集元素乘积之和（$1..n$中$kk$乘积之和）

答案：$ans=S[n+1][n-k+1]$,$S$表示第一类斯特林数

### 【80】组合：$gcd$卷积与$lcm$卷积

卷积是一种比较耗费计算资源的基础数学运算，在数学上我们处理卷积的一般方法都是通过各种变换或者转化，使得问题转化为比较容易计算的计算类型(比如序列点积)，想方设法加速计算的效率，当然这需要卷积本身具有一定的数学性质。

***gcd*卷积**是说我们需要计算的卷积公式为：


$$
\Large
c_k=\sum_{(i,j)=k}a_i*b_j
$$



令$A,B,C$分别为$a,b,c$的类点值序列(闭区间$[1,n]$,下标超过$n$值为$0$)，

其中一个定义如下：


$$
\Large
A_k=\sum_{k|d}a_d
$$

那么即有：

$$
\Large
C_k=\sum_{k|d}c_d=\sum_{k|d}\sum_{(i,j)=d}a_i*b_j=\sum_{k|(i,j)}a_i*b_j \\

\Large
=\sum_{k|i}\sum_{k|j}a_i*b_j=(\sum_{k|i}a_i)*(\sum_{k|i}b_i)=A_k*B_k
$$

我们得到：

$$
\Large
C=A\bullet B
$$

序列反演公式： 

$$
\Large
a_k=\sum_{k|d}A_d*\mu_{\frac{d}{k}}
$$

***lcm*卷积**是说我们需要计算的卷积公式为：


$$
\Large
c_k=\sum_{[i,j]=k}a_i*b_j
$$

令$A,B,C$分别为$a,b,c$的类点值序列，其中一个定义如下：


$$
\Large
A_k=\sum_{d|k}a_d \Leftrightarrow A=a \circ I
$$

那么即有：


$$
\Large
C_k=\sum_{d|k}c_d=\sum_{d|k}\sum_{[i,j]=d}a_i*b_j=\sum_{[i,j]|k}a_i*b_j \\

\Large
=\sum_{i|k}\sum_{j|k}a_i*b_j=(\sum_{i|k}a_i)*(\sum_{i|k}b_i)=A_k*B_k
$$

我们得到：


$$
\Large
C=A\bullet B
$$

序列反演公式： 

$$
\Large
a_k=\sum_{d|k}A_d*\mu_{\frac{k}{d}}=\sum_{x*y=k}A_x*\mu_y \Leftrightarrow a=A \circ\mu
$$

更多信息可以参见模板和配套的$md$说明文件

### 【85】组合：k进制fwt/高维广义快速离散傅里叶变换fft

**本质**：有穷高维循环卷积$fft$，循环周期为$k$

http://www.cnblogs.com/TinyWong/p/10351109.html

https://www.cnblogs.com/reverymoon/p/10197711.html

需要变换的下标每个数都是$n$位的$k$进制数，那么下标空间为$[0,k^n)$

这相当于一种$n$维的($n=log_kN$)每维长度为$k$的$fft$循环异或卷积变换($k$进制不进位加法)，按照高维$fft$的思路，应该按照某种维度的排列顺序(比如从高位到低位)，逐维正变换，然后每个位置独立做点积，最后再逐维逆变换(对应一种递归或者迭代过程)

$2$进制宏观上正变换的实质：$\large c_i=\sum_{j=0}^{2^k-1}(-1)^{num(j\&k)}a_j,i\in[0,2^k-1]$

$k$进制微观上每维正变换的实质，与$fft$相似，是**向量左乘一个变换矩阵**$T$，满足$T(i,j)*T(i,k)=T(i,j \oplus k)$

我们采用$k$阶单位根的***范德蒙德矩阵***：
$$
T=\begin{bmatrix}
 1& 1 &  1& ... & 1\\ 
 1& w_k^1&  w_k^2& ... & w_k^{k - 1}\\ 
 1&  w_k^2 &  w_k^4&  ... & w_k^{2(k - 1)}\\ 
 ...&  ...&  ...&  ...& ...\\ 
 1&  w_k^{k - 1}& w_k^{2(k - 1)} & ... & w_k^{(k - 1)(k - 1)}
\end{bmatrix}
$$
其行列式为：
$$
det(T)=\prod \limits_{i < j} (x_i - x_j)，x_i\ne x_j \\
det(T)\ne 0 \leftrightarrow T可逆
$$
其逆矩阵为：
$$
T^{-1}=\frac{1}{k} \begin{bmatrix}
 1& 1 &  1& ... & 1\\ 
 1& w_k^{-1}&  w_k^{-2}& ... & w_k^{-(k - 1)}\\ 
 1&  w_k^{-2} &  w_k^{-4}&  ... & w_k^{-2(k - 1)}\\ 
 ...&  ...&  ...&  ...& ...\\ 
 1&  w_k^{-(k - 1)}& w_k^{-2(k - 1)} & ... & w_k^{-(k - 1)(k - 1)}
\end{bmatrix}
$$
证明用到结论：
$$
[n | t] = \sum \limits_{i = 0}^{n - 1} w_n^{ti}
$$
注：2进制下的特殊情形
$$
T=\begin{bmatrix} 1& 1\\  1& -1 \end{bmatrix} =  \begin{bmatrix} 
0.5& 0.5\\
0.5& -0.5\\
\end{bmatrix}^{-1}
$$
一种**实现思路**是：

采用递归，传入参数FWT(a,S,n,op)，表示的是将a数组中以S开头的长度为n的一段区间进行正/逆变换(op=1为正/op=-1为逆)，那么首先将这段区间平均分为k段，每段长度n/k，逐段递归FWT，然后回溯合并时扫描段长(穷举一个段中偏移为i的位置)，将这些位置取出来构成一个k维向量，将这个向量左乘单位根矩阵$T$或者$T^{-1}$，变换后按顺序放置回去，对每个偏移量i都这样操作即可



**数的表示技巧：单位根表示法**

注意到一个数$x$，需要与$k$阶单位根做乘积，正常的思路是用一个$pair<double,double>$保存其复数的实部和虚部，用复数的乘法规则运算，但是这样显然精度损失严重，最终不容易回到其整数形态

注意到数$x$一定具有形式：$x=\sum_{i=0}^{k-1}a_i\omega^i$，故可以使用$k$维向量$\overrightarrow{a}$表示数$x$

那么普通的加减就是模意义下逐位加减，普通的乘法变为$k$维向量的**循环卷积**即可

而与$\omega^t$相乘相等于，此向量循环右移$t$位

考虑最后如何由向量$\overrightarrow{a}$得到整数值$x$:
$$
令cnt=k\&-k，L=k/cnt \\
容易发现，[0,k)这些下标可以分成cnt组，每组L个元素，分组的依据是一个下标i\&cnt的值的不同 \\
比如k=20可以分为以下4组： \\
$$

| 组/元素 | /4=0 | /4=1 | /4=2 | /4=3 | /4=4 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 组0   | 0    | 4    | 8    | 12   | 16   |
| 组1   | 1    | 5    | 9    | 13   | 17   |
| 组2   | 2    | 6    | 10   | 14   | 18   |
| 组3   | 3    | 7    | 11   | 15   | 19   |

当$k$为偶数时，$0$和$k/2$这两个位置保存整数值；当$k$为奇数时，只有$0$这个唯一的位置保存整数值

我们每组独立考虑，首先$0$和$k/2$不会分到同一组，因为$k/2$存在，则必定$k$为偶数，$k$为偶数，则可以先按照每个下标的最后一位是$0$或者$1$暂时分成两组，若$0$和$k/2$同分在组$A$，则$x$轴上方和下方显然有一样多的元素属于组A，那么组$A$显然包含了偶数个元素，则组$A$，还可以继续拆分为两组，重复应用这个过程，由无穷递降法知矛盾

**基本事实**：每组单位根之和为$0$，这是因为：
$$
x^n-1=\prod_{i=0}^{n-1}(x-\omega^i)=(x-1)(x^{n-1}+x^{n-2}+\dots+1) \\
约去x-1得到：\\
x^{n-1}+x^{n-2}+\dots+1=\prod_{i=1}^{n-1}(x-\omega^i) \\
而\sum_{i=0}^{L-1}\omega_{k}^{cnt*i+t}=\omega^t(\sum_{i=0}^{L-1}\omega_{cnt*L}^{cnt*i})=\omega^t(\sum_{i=0}^{L-1}\omega_{L}^{i})=0
$$
若一个组不含$0$和$k/2$，那么这个组元素都相同，可消去为$0$；若含有其中一个，则其余元素全相同，可消除为除$0$下标之外元素为$0$；那么我们最多考虑两个组贡献，就是$a[t]-a[t+cnt],t \in \{0,k/2\}$

可以得到模板代码求整数值如下：

```c++
inline ll Value() {
	int cnt=K&-K,L=K/cnt; ll ret=a[0]-(L>1)*a[cnt];
	if (K&1^1) ret-=a[K>>1]-(L>1)*a[(K>>1)+cnt],ret%=_p;
	return ret;
}
```



**单位根表示法的优化**：

很显然，对于一个偶数进制k(k为奇数的两倍)，除了用k阶单位根表示一个数，还可以用k/2阶单位根，这主要是因为有类似于折半引理的复数性质，可以节约一些常数；如果这里可以找到一些更本质的性质，也许可以推广下去，或者针对具体的进制，具体的分析



**数的表示技巧：模域表示法**

这是一种可以让高进制卷积，加速好几倍同时没有精度误差的方法

- 适用条件：只适用于**特殊进制$k$**和**模数$p$**，要求$p$为质数且$k|p-1$.
  - 模$p$意义下循环群阶为$p-1$，元素阶以及循环子群的阶均为其约数
  - 主要思想是用模域中的数刻画有理数，实数，以及复数域中的数
  - $\sqrt[m]{t}$用$m$次剩余去刻画，虚数单位$i$使用$\sqrt{-1}$刻画，一定条件下，复数可以得到刻画
  - 令$g$为模$p$原根，$k$阶单位根，共$k$个，构成循环子群；原根$g$为其生成元，$w_k=g^{\frac{p-1}{k}}$
  - 模数为$10^9+9$或$998244353$最为适用，进制$k$为$2,3,4,7,8$最为得当
- 表示方法：根据前面的分析，一个数$x=\sum_{i=0}^{k-1}a_iw_k^i$，带入单位根即得到模域表示
- 基本运算
  - 乘法转化为循环卷积，这里即普通乘法，衍生出乘方
  - 左右移，通过乘除单位根的幂次得到
  - 实数求值，该值就是答案，因为虚部为$0$，在模域里也抵消了
  - 逆向分解，不大可能，因为相当于降维了，信息与高维比不充分
- 主要用途
  - 对卷积运算加速常数
  - 在复数域中扩展多项式操作，比如生成函数带入单位根，或者单位根反演，支持三角函数操作等
  - $ntt$本身就是一种特殊的$2^k$阶单位根处的多点求值






**求逆技巧**：

注意在$FWT$的逆变换中，最中间的赋值语句要除以一个进制数，或者最终结果每个元素要除以一个长度$N=k^p$

而$FWT$正变换中没有除法，所以最终结果每个元素只要除以$N^t$，其中$t$为逆变换的总次数



**模数变更**：

当模数不是一个质数的时候，考虑进制数$k$可能和模数不互质，那么将$k$分解为$k=k'*q$，其中$q$使用数学技巧转化掉(事实上要视情况而定，可能不能转化掉)，而$k'$是互质成分，存在逆元

当存在特殊模数的时候，比如$2^{58}$，可以不取模，常数可能会小很多



**公共性质：**

卷积定理表明：
$$
T(a\oplus b)=T(a)\cdot T(b) \\
T(a+b)=T(a)+T(b) \\
T(h(a,b))=h(T(a),T(b)) \\
T(h(\overrightarrow{a}))=h(\overrightarrow{T}(\overrightarrow{a})) \\
其中h(a,b,c)是关于多项式a,b,c之间的组合多项式函数
$$



### 【91】代数：暴力多项式取模$m^2logn$，用于特征多项式法解$k$阶常系数线性齐次递推数列(k>=1000)

蕴含着：Cayley–Hamilton theorem

https://en.wikipedia.org/wiki/Cayley%E2%80%93Hamilton_theorem

参考资料：

https://blog.csdn.net/joker_69/article/details/80869814

https://blog.csdn.net/hzj1054689699/article/details/85683342

有模板题和模板：***LinearRecursion***ZP版本$O(m^2logn)$

https://www.lydsy.com/JudgeOnline/problem.php?id=4161

**简要笔记**：

$O(m^2logn)$可以使用长除法，模拟多项式除法/取模(被除$deg=n \le 1e18$,除数$deg=m \le 1000$)，参见模板

令递推变换矩阵为$A_{m \times m}$，其特征多项式$G(\lambda)$为：
$$
G(\lambda)=|\lambda I-A|=\lambda^{m}-\sum_{i=0}^{m-1} a_{m-i} \lambda^{i}=[-a_m,-a_{m-1},-a_{m-2},\dots,-a_1,1]
$$
根据$Cayley–Hamilton$定理，有：$G(A)=0$

若$x^n=F(x)G(x)+C(x),deg(C)<m$，则有$A^n=C(A)$

更进一步地：$A^n \overrightarrow{x}=C(A)\overrightarrow{x}=(\sum_{i=0}^{m-1}c_iA^{i})\overrightarrow{x}=\sum_{i=0}^{m-1}c_i(A^{i}\overrightarrow{x})$

假设我们取具体而特定的：$\overrightarrow{x}^T=[x_{m-1},x_{m-2},x_{m-3},\dots,x_1,x_0]$

为了得到$x_n$，我们应该左乘$A^{n-m+1}$,取结果向量第一个元素$x_n=(A^{n-m+1}\overrightarrow{x})[1]$

我们得到：
$$
x_n=\sum_{i=0}^{m-1}c_ix_{m-1+i}
$$
上述差卷积需要已知：$X'=[x_{m-1},x_{m},x_{m+1},\dots,x_{2m-3},x_{2m-2}]=[x_i],i \in [m-1,2m-2]$

此种方法可能还需要我们多算$O(m)$项，如果我们左乘$A^{n}$取结果向量第m个元素(最后一个)，亦即：
$$
x_n=(A^n\overrightarrow{x})[m]=\sum_{i=0}^{m-1}c_i(A^{i}\overrightarrow{x})[m]=\sum_{i=0}^{m-1}c_i((A^{i}\overrightarrow{x})[m])=\sum_{i=0}^{m-1}c_ix_i=\overrightarrow{C}\cdot\overrightarrow{X} \\

其中：\overrightarrow{C}=[c_i],\overrightarrow{X}=[x_i], i \in [0,m-1],另\cdot表示向量点积
$$
可以看到，这种方法没有什么冗余计算，$\overrightarrow{C}$和$\overrightarrow{X}$均为已知的，只要直接做一次点积即可

而$\overrightarrow{C}$通过多项式$x^n$对$G(x)$取模得到，由于$n$巨大，所以不能用普通的多项式取模模板，考虑使用快速幂$Pow(x,n,G)$,令多项式$x^t$在模$G$意义下不断自乘即可，故我们需要写一个模板函数，$mul(A,B,G)$表示模$G$意义下多项式$A$和$B$乘积，其中如果多项式乘和取模用暴力$O(m^2)$，则此方法复杂度$O(m^2logn)$，而如果使用多项式模板($ntt$实现)，则复杂度为$O(mlogmlogn)$

如果我们只知道$\overrightarrow{a}=[a_i],i \in [1,m]$，和$x_0$，而不知道整个$\overrightarrow{X}$，现在要求$x_n$，就需要先求$\overrightarrow{X}$：

$O(m^2)$可以暴力线性递推，$O(mlog^2m)$可以使用分治$fft/ntt$，$O(mlogm)$可以使用以下生成函数方法：
$$
令\overrightarrow{H}=\sum_{i=0}^{+\infin}x_iz^i为普通型生成函数 \\

\overrightarrow{H}=\frac{\overrightarrow{H}(1-\overrightarrow{a})}{1-\overrightarrow{a}} \\
故：\overrightarrow{X}=\overrightarrow{H}\%x^m=\frac{\overrightarrow{H}(1-\overrightarrow{a}) \% x^m}{1-\overrightarrow{a}}=\frac{(\overrightarrow{H}\%x^m(1-\overrightarrow{a}) \% x^m)\%x^m}{(1-\overrightarrow{a})\%x^m} \\
注：上式分子实际上是个有穷多项式，特别当心\overrightarrow{a}下标是从1开始的，即[1,m]
$$

当然，上述方法适用于知道$x_0$，比较快速地求出$f[1..n],k \le n \le 10^6$

更本质地讲，如果我们把所有序列下标为负的部分，都看作$0$，那么其实$x_0$不再是序列$x$的首项

这样讲的意义在于，我们可以重构序列$\overrightarrow{X'}=[x_i],i \in [-(m-1),0]$

从而重构：$\overrightarrow{x'}^T=[x_{0},x_{-1},x_{-2},\dots,x_{-(m-2)},x_{-(m-1)}]$

我们仍然左乘$A^{n}$取结果向量第1个元素，亦即：
$$
x_n=(A^n\overrightarrow{x'})[1]=\sum_{i=0}^{m-1}c_i(A^{i}\overrightarrow{x'})[1]=\sum_{i=0}^{m-1}c_i((A^{i}\overrightarrow{x'})[1])=\sum_{i=0}^{m-1}c_ix_i=\overrightarrow{C}\cdot\overrightarrow{X} \\

其中：\overrightarrow{C}=[c_i],\overrightarrow{X}=[x_i], i \in [0,m-1],另\cdot表示向量点积
$$

发现最终需要的还是$\overrightarrow{X}$，而不是$\overrightarrow{X'}$；我们左乘$A^{n+m-1}$取结果向量第$m$个元素，亦即：

$$
x_n=(A^{n+m-1}\overrightarrow{x'})[m]=\sum_{i=0}^{m-1}c_i'(A^{i}\overrightarrow{x'})[m]=\sum_{i=0}^{m-1}c_i'((A^{i}\overrightarrow{x'})[m])=\sum_{i=0}^{m-1}c_i'x_{i-m+1}=\overrightarrow{C'}\cdot\overrightarrow{X'}=c'_{m-1}x_0 \\

其中：\overrightarrow{C'}=[c_i'],i \in [0,m-1],\overrightarrow{X'}=[x_i], i \in [-(m-1),0],另\cdot表示向量点积
$$
因此可以看到，我们不再需要计算多余的前$m$项内容，只要计算多项式快速幂模，亦即$\overrightarrow{C'}$即可

**推广：**

求递推序列$\{x_i\}$的前$n+1$项和$s_n$，沿用上述的方法：

令$C_i$表示多项式$x^i$对特征多项式$G$取模，令$C=\sum_{i=0}^nC_i=(\sum_{i=0}^nx^i)\%G$，类似于快速幂的递归算法可以求解$C$，结果仍然是$\overrightarrow{C}\cdot\overrightarrow{X}$

### 【93】概率论：全期望公式

$$
E(E(X|Y))=E(X) \\
注意：E(X|Y)是个随机变量，概率分布：以P(Y=y)概率取到E(X|Y=y)
$$
进一步分析可见维基百科或者2013年国家集训队论文《概率论应用》



### 【94】组合：超平面切平面的规律

经典问题：$n$个$k-1$维超平面最多可以将$k$维空间分割成多少个空间区域
$$
f(n,k)=\sum_{i=0}^{min(k,n)}\binom{n}{i}
$$

| $f(n,k)$ | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | $\dots$ |
| -------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ------- |
| 0        | 1    | 1    | 1    | 1    | 1    | 1    | 1    | 1    | 1    | $\dots$ |
| 1        | 1    | 2    | 2    | 2    | 2    | 2    | 2    | 2    | 2    | $\dots$ |
| 2        | 1    | 3    | 4    | 4    | 4    | 4    | 4    | 4    | 4    | $\dots$ |
| 3        | 1    | 4    | 7    | 8    | 8    | 8    | 8    | 8    | 8    | $\dots$ |
| 4        | 1    | 5    | 11   | 15   | 16   | 16   | 16   | 16   | 16   | $\dots$ |

递推公式：
$$
f(0,k)=1,k \ge 0 \\
f(n,k)=f(n-1,k-1)+f(n-1,k)
$$
显然将上表中，每一行都差分一下，记得到组合数表；可以这样理解，每个第$0$行的$1$都为下面区域带来一个组合数的贡献，那么$(n,k)$相当于得到了行总是$n$但是列$\in [0,k]$的组合数贡献之和

该序列可以通过莫队算法或者分治$fft$快速求得一组，线性时间可预处理一行或者一列

特别的，令$k=2$有：直线分割平面的区域数目：
$$
f(n,2)=\binom{n}{0}+\binom{n}{1}+\binom{n}{0}=n(n+1)/2+1
$$
一些其他问题，比如折线划分平面，或者闭曲线椭圆划分平面，这些都可以用类似的类比递推归纳的方法，得到递推式，但暂时不便于推广到高维情形



### 【95】代数/拓扑：全序关系、偏序关系与偏序集

全序关系$\le$满足：完全性，即$\forall x,y \in S,x \le y || y \le x$

偏序关系$\le$满足：自反性(反身性)，即$\forall x \in S,x \le x$

两者均满足：

反对称性，即$\forall x,y \in S,x\le y \&\& y \le x \leftrightarrow x=y$

传递性，即$\forall x,y,z\in S, x \le y \&\& y \le z \to x \le z$

由于完全性是反身性的特例，故全序关系是偏序关系的特例，即全序关系一定是偏序关系

二者直观的区别在于，偏序关系并不是两两可比(默认只知道自己和自己可比)，但是全序关系是两两可比的



全序集及其笛卡尔积偏序线性空间中的$min/max$函数的基本性质与推广

- 都满足交换律，结合律等基本性质
- 满足对称分配率，即$min$对$max$满足分配率，反之亦然

设全序集$(S,\le)$中运算$+$表示二元$min$函数，运算$*$表示二元$max$函数，该表示可以用多元多项式刻画复杂的$min/max$嵌套表达式

令$T_n=S^n,n\in[1,+\infin]$，注意$(T_n,\le)$一般不再是全序集，但是如果定义$T_n$上的$min$为各维$min$的笛卡尔积，可以发现仍然满足上述的分配率；当$S=\{0,1\}$时，$\&$为$S^n$上的$min$，$|$为$S^n$上的$max$；当$S=N$时，$gcd$为$S^n$上的$min$，$lcm$为其$max$，可以推广到$S=Z$，涉及到有理数的$gcd$；当$S^k$为全集$U$($|U|=n$)的$k$元子集簇时，$\cap$为其$min$，$\cup$为其$max$

与$gcd$有关的分配率的直接推论：

- $lcm(gcd(x,y),gcd(x,z),gcd(y,z))=gcd(lcm(x,y),lcm(x,z),lcm(y,z))$
- $n$元整数集$(k-k)gcd$的$lcm$等于$((n-k+1)-(n-k+1))lcm$的$gcd$


### 【100】数论/密码学：RSA公钥体系

公钥加密，私钥解密，$RSA$可靠性取决于大数因式分解的困难性

取两个大而不太接近的质数$p,q$，令$n=pq,t=\phi(n)=(p-1)(q-1)$

取一个随机数$e \in [2,t),gcd(e,t)=1$，令$d=e^{-1}\pmod{t}$

$(n,e)$为公钥，$(p,q,d)$为私钥，明文为$M$，密文为$C$

加密算法：$C=M^e \pmod{n}$

解密算法：$M=C^d \pmod{n}$

### 【101】数论/密码学：$ElGamal$密码

其可靠性取决于大数离散对数的困难程度

选择一个大质数$p$，且要求$p-1$含大质因子，选择一个$p$的生成元或原根$a$

随机选择一个$d \in [2,p-2]$，令$y=a^d \pmod{p}$

公开$p,a$，取$y$为公钥，$d$为私钥，明文为$M$，密文为$(C_1,C_2)$

加密算法：随机选取$k \in [2,p-2]$

$C_1=a^k \pmod{p}$

$C_2=My^k \pmod{p}$

解密算法：$M=C_2C_1^{-d} \pmod{p}$

### 【106】数论：$Vantieghems theorem$

$n$是质数当且仅当：
$$
\prod_{1 \leq k \leq n-1}\left(2^{k}-1\right)\equiv n\pmod{2^n-1}
$$
可以换成其他的公式：
$$
\prod_{1 \leq k \leq n-1}\left(X^{k}-1\right) \equiv n-\left(X^{n}-1\right) /(X-1)\pmod{X^n-1} \\

\prod_{1 \leq k \leq n-1}\left(X^{k}-1\right) \equiv n \pmod{\frac{X^{n}-1}{X-1}}
$$



### 【118】组合/代数：杨氏矩阵/杨表(Young tableaux) [维基百科：杨表](https://en.wikipedia.org/wiki/Young_tableau)

- 定义
  - **形状**：$N$的一个不严格降序拆分称为形状，$\lambda=(\lambda_1,\lambda_2,\lambda_3,...,\lambda_m)$，$\lambda_i \ge \lambda_{i+1}$，$\lambda \vdash N$
  - **杨图**：某种形状$\lambda$的未填数字的表格，共$m$行，第$i$行$\lambda_i$列
  - **杨表**：填满数字的杨图
    - **标准杨表**：从上向下严格増，从左往右严格増，$1..N$各出现一次
    - **半标准杨表**：从上向下严格増，从左往右不严格増
    - **杨表权重**：一个向量$(1,1,...,1)$表示各数字出现次数
  - **斜杨图/表**：$\lambda/\mu$，$\lambda_i \ge \mu_i$，第$i$行在$[\mu_i+1,\lambda_i]$列填数字
    - 标准/半标准：参见上面
  - **边角**：一个格子为边角，其下面和右边的格子不存在

- 杨表与排列
  - 行插入算法$S \gets x$

    - 所移动的格子看上去一定是向不严格的左下方移动

      ![杨表_行插入](\pic\数学\杨表_行插入.PNG)

  - 列插入算法$x \to S$

    - 与行插入对称

      ![杨表_列插入](\pic\数学\杨表_列插入.PNG)

  - 边角删除算法

    - 与行插入互为逆操作

      ![杨表_边角删除](\pic\数学\杨表_边角删除.PNG)

  - 记录表：一个排列$X$进行行插入得到杨表$P_X$，同时可以得到记录表$Q_X$，只需要每次在将元素$x_i$插入时，杨表增加新元素的位置，放入下标$i$；记录表$Q_X$与$P_X$同规模

    ![杨表_记录表](\pic\数学\杨表_记录表.PNG)

  - 一一对应：[Robinson–Schensted correspondence](https://en.wikipedia.org/wiki/Robinson%E2%80%93Schensted_correspondence)

    - 长度为$n$的排列与**一对形状相同的标准杨表**一一对应
    - 令$f_{\lambda}$表示形状为$\lambda$的标准杨表的数量，则$\sum_{\lambda \vdash n}f_{\lambda}^2=n!$

  - 排列插入算法的性质

    - 行列交换律：$(x \to S) \gets y=x \to (S \gets y)$，这表明相邻两个对行列的插入操作(一个对行，一个对列)是可交换的
    - 行列相对独立性：一个插入操作序列，可以调整为先完成行操作，再做列操作，每种相对顺序不变
    - 翻转特性：$X^R$表示排列的左右翻转，则$P_X=(P_{X^R})^T$，这表明排列行插入等价于倒序列插入，注意只对杨表成立，对记录表**不**成立
    - 相反数特性：排列倒序行插入得到的杨图(形状)等价于原排列***相反数序列***行插入得到的杨图，注意不是杨表相同

- 杨表与对称矩阵

  - 普通非负整数矩阵

    - 矩阵$A$拆成序列对$X$：其中$(i,j)$这个数对出现$A[i][j]$次，数对按照$pair$排序，即构成$(first,second)$序列对

    - $X^{-1}$：只要把每个数对两维交换，重新排序，得到新的序列对

    - $P_X$表示将$X$第二行(即第二维，或者$second$序列)插入构造的杨表，$Q_X$表示在$P_X$构造过程中，将$first$序列视为下标构造的记录表

    - 性质关系：$(P_X,Q_X)=(Q_{X^{-1}},P_{X^{-1}})$

      ![性质关系](\pic\数学\杨图1.PNG)

  - 对称矩阵

    - 一些定义：矩阵$M_{W \times H}$，行和$r_i$，列和$c_j$，$X_M$为其所构序列对，$P_M=P_{X_M}$，同理定义$Q_M$，$X_M^{-1}=X_{M^T}$
    - 一一对应：$M$和一对半标准杨表$P_M$和$Q_M$一一对应，$P_M$中$i$出现$c_i$次，$Q_M$中$i$出现$r_i$次；特别的，$M$为对称矩阵，与半标准杨表$P_M$一一对应，$P_M$中$i$出现$r_i$次，且$X_M^{-1}=X_M$，$P_M=Q_M$
    - 对称矩阵$M$的迹$tr(M)=\sum_{i=1}^nM_{ii}$等于$P_M$中长度为奇数的列数

  - 对合排列(*involution permutation*)

    - 定义：对合排列$X=X^{-1}$，即$X$的圈结构中，圈长非$1$即$2$；对应着每行每列只有一个$1$的$01$矩阵
    - 性质：其自环个数等于其所对应的标准杨表中奇数长度的列的个数
    - 对合数：$a_0=a_1=1,a_n=(n-1)a_{n-2}+a_{n-1}$

- 杨表与最长上升/下降子序列

  - 基本结论：$X$为一个排列

    - $P_X$第一行长度为$len(LIS_X)$，第一列长度为$len(LDS_X)$

  - 最长$k-LIS$子序列

    - 定义：长度不超过$k$的$LIS$子序列为$k-LIS$子序列
    - 结论：排列$X$的最长$k-LIS$子序列长度等于杨表$P_X$的前$k$列长度之和
    - 例题：$CTSC2017$最长上升子序列，询问$Q$次排列前缀的最长$k-LIS$子序列长度($k$变化)；只维护杨表前$\sqrt{n}$行和$\sqrt{n}$列，前$\sqrt{n}$行，通过插入相反数序列维护杨图；复杂度$O(n\sqrt{n}logn)$

  - $LIS$计数

    - 结论

      - 长度为$n$的$LIS$长度为$\alpha$，且$LDS$长度为$\beta$的排列个数为：
        $$
        \large num(n,\alpha,\beta)=\sum_{行数为\beta,列数为\alpha,\lambda \vdash n} f_{\lambda}^2
        $$

      - 权值范围为$[1,n]$，各权值数量分布为$\mu$，即：$\sum_{i=1}^n\mu[i]=n$；令$g_{\lambda/\mu}$表示形状为$\lambda$且权值分布为$\mu$的**半标准**杨表数量；则这样的长度为$n$的序列中，最长**非严格**上升子序列长度为$\alpha$且最长**严格**下降子序列长度为$\beta$的序列数量为：
        $$
        \large num(n,\alpha,\beta)=\sum_{行数为\beta,列数为\alpha,\lambda \vdash n,\mu}g_{\lambda/\mu}f_{\lambda}
        $$

    - 例题：$BJWC2018$最长上升子序列

      - 题目：长度为$n$的随机排列$X$，求$E(len(LIS_X)$
      - 分析：枚举$n$的所有降序拆分$\lambda$，用钩子公式$O(n^2)$计算$f_{\lambda}$，复杂度$O(n^2p(n))$，可轻松做到$n \le 63$

- 杨表与钩子公式

  - 钩子函数：$h_{\lambda}(i,j)$表示在形状为$\lambda$的杨图中$(i,j)$右侧和下侧以及自己所确定的一块钩子区域的格子数量

  - 标准杨表钩子公式：
    $$
    \large f_{\lambda}=\frac{n !}{\prod h_{\lambda}(i, j)} \\
    \large f_{\lambda}= n ! \frac{\prod_{1 \leq j<k \leq m}\left((\lambda_{j}-j)-(\lambda_{k}-k\right))}{\prod_{i=1}^{m}\left(\lambda_{i}+m-i\right) !}
    $$
    注：上面的公式更便于理解和记忆，下面的公式更便于计算和实现，时间复杂度为$O(m^2)$

- 杨图随机游走

  - 定义：从杨图上某个格子出发，随机向右边或下边走一格，直到走到边角停止

  - 等概率随机游走，$\lambda=(\lambda_1,\lambda_2,\cdots,\lambda_m)$
    $$
    \large p(\space(1,1) \to 边角(r,s)\space)=\frac{1}{n} \prod_{i=1}^{r-1} \frac{h_{\lambda}(i, s)}{h_{\lambda}(i, s)-1} \prod_{j=1}^{s-1} \frac{h_{\lambda}(r, j)}{h_{\lambda}(r, j)-1}
    $$

  - 带权随机游走，$\lambda_i'=|\{j|\lambda_j \ge i\}|$，$x_i,y_i$为每列/每行的权重
    $$
    \large p(\space(1,1) \to 边角(r,s)\space)= \\
    \frac{x_{r} y_{s}}{\sum_{(p, q) \epsilon[\lambda]}} \prod_{i=1}^{r-1}\left(1+\frac{x_{i}}{x_{i+1}+\cdots+x_{r}+y_{s+1}+\cdots+y_{\lambda_{i}}}\right) \\
    \times \prod_{j=1}^{s-1}\left(1+\frac{y_{j}}{x_{r+1}+\cdots+x_{\lambda_{j}'}+y_{j+1}+\cdots+y_{s}}\right)
    $$

- 杨表与网格图路径

  - 卡特兰数相关

    - $2 \times n$的标准杨表个数为卡特兰数：$C_n=\binom{2n}{n}/(n+1)$

    - 分析方法：对每一维坐标，记录为杨表的一行，$x_{ij}$表示$i$这一维坐标，第一次到达$j$的时刻；考虑一条合法的路径，每个时刻会且仅会使得一维坐标达到新的值，当走到终点$(a_1,a_2,\cdots,a_m)$时，每维均取到了终点坐标的上界，因此我们得到的是一个$m$行，$\lambda=\overrightarrow{a}$的标准杨表；考虑杨表的限制，每列递增，表示不同维到达同一个值的时刻偏序关系，对应到路径中任何时刻走到的点的坐标应该满足逐维递减；例如卡特兰数要求路径每点横坐标不小于纵坐标，即不穿过对角线

    - 例题：$LOJ6051$PATH

      - 题目：$m$维空间，从原点出发，到达$\overrightarrow{a}$，每次某一维坐标增加$1$，问随机路径中能够保持坐标逐维不升的概率，保证$\overrightarrow{a}$满足此性质；即求***高维卡特兰数***

      - 分析：令$r_i=\lambda_i+m-i$，$n=\sum_{i=1}^ma_i$，由钩子公式：
        $$
        \large ans=\frac{\frac{n !}{\prod_{i=1}^{m} r_{i} !} \prod_{1 \leq j<k \leq m}\left(r_{j}-r_{k}\right)}{\frac{n !}{\prod_{i=1}^{m} a_{i} !}}=\left(\prod_{i=1}^{m} \frac{a_{i} !}{r_{i} !}\right) \prod_{1 \leq j<k \leq m}\left(r_{j}-r_{k}\right)
        $$
        注：最右边的公式可以用$ntt$优化到$mlogm$，这是一个差卷积

  - 不交叉网格路径

    - [Lindström–Gessel–Viennot lemma](https://en.wikipedia.org/wiki/Robinson%E2%80%93Schensted_correspondence)($LGVL$)

      该定理是说：边带权$DAG$中有两个点集$A,B,|A|=|B|=n$，我们枚举$A \to B$的$n!$个对应关系，对每种对应关系(一个排列$\sigma$)，对每对对应点，枚举一条有向路径，且这$n$条路径不交，令$\omega(P)$表示路径边权之积，则累乘$n$条不交路径的权，最后叠加到答案中(正负取决于$\sigma$逆序对)，该答案等于下面矩阵的行列式的值
      $$
      M=\left(\begin{array}{cccc}{e\left(a_{1}, b_{1}\right)} & {e\left(a_{1}, b_{2}\right)} & {\cdots} & {e\left(a_{1}, b_{n}\right)} \\ {e\left(a_{2}, b_{1}\right)} & {e\left(a_{2}, b_{2}\right)} & {\cdots} & {e\left(a_{2}, b_{n}\right)} \\ {\vdots} & {\vdots} & {\ddots} & {\vdots} \\ {e\left(a_{n}, b_{1}\right)} & {e\left(a_{n}, b_{2}\right)} & {\cdots} & {e\left(a_{n}, b_{n}\right)}\end{array}\right)
      $$

      $$
      \operatorname{det}(M)=\sum_{\left(P_{1}, \ldots, P_{n}\right) : A \rightarrow B} \operatorname{sign}(\sigma(P)) \prod_{i=1}^{n} \omega\left(P_{i}\right)
      $$

      其中$e(a,b)=\sum_{P:a \to b}\omega(P)$，即所有$a\to b$的有向路径权值积的和

      特别的，若图的边权均为$1$，则该行列式的值即为$A \to B$的不交路径元祖计数

      注意上述的乘法，可以换成一些可重载的运算，如字符串的连接操作等

      参考阅读：[1](https://graphicallinearalgebra.net/2017/07/31/determinants-and-the-lindstrom-gessel-vienot-lemma/) [文献](https://kam.mff.cuni.cz/~ashutosh/lectures/Presentation_Diptapriyo.pdf)

    - $LGVL$用于网格图

      - 如果是网格图，只允许向右向上走，不过是特殊化的$DAG$，带入$E(x,y)$即可
      - 由于在此意义下，所枚举到的排列$\sigma$，只有一种是合法的，因此适当排序之后，上述行列式值直接等于$A_i \to B_i$所构成的$n$元组路径方案；形式化的，我们要求$A,B$中点横坐标不升，纵坐标不降

    - 一一对应

      - 权值$\in [1,n]$且$m$行($n=\sum_{i=1}^m\lambda_i$)的半标准杨表与$A=\{(-i,1)\},B=\{(\lambda_i-i,n)\},i \in [1,m]$的$m$条不交路径元组一一对应；构造方法：每条路径对应杨表一行，该路径每右行一步，记录其行号

        ![杨表_不交路径1](\pic\数学\杨表_不交路径1.PNG)

      - 权值$\in [1,n]$且$m$行($n=\sum_{i=1}^m\lambda_i$)的半标准斜杨表$\lambda/\mu$与$A=\{(\mu_i-i,1)\},B=\{(\lambda_i-i,n)\},i \in [1,m]$的$m$条不交路径元组一一对应(图表右移了两格)

        ![杨表_不交路径2](\pic\数学\杨表_不交路径2.PNG)

  - 行列式公式

    - 标准斜杨表数量公式
      $$
      f_{\lambda / \mu}=\left(\sum_{i} \lambda_{i}-\mu_{i}\right) !\left|\frac{1}{\left(\lambda_{i}-i-\mu_{j}+j\right) !}\right|_{i, j=1}^{|\lambda|}
      $$

      - 注：负数的阶乘倒数定义为$0$

    - 标准杨表数量公式
      $$
      f_{\lambda}=\left.\left(\sum_{i} \lambda_{i}\right) !\left|\frac{1}{\left(\lambda_{i}+j-i\right) !}\right|\right|_{i, j=1} ^{|\lambda|}
      $$

    - 欧拉数：长度为$2n$的波形排列计数
      $$
      (2 n) ! \operatorname{det}\left(\frac{1}{(2 j-2 i+2) !}\right)_{i, j=1}^{n}
      $$

      - 思路：构造一个斜杨表$(2n-i+2)/(2n-i),i \in [1,m]$，填好数之后从下而上，从左向右取数构造排列

  -  [Hankel 矩阵](https://en.wikipedia.org/wiki/Hankel_matrix)

    - 定义：$Hankel$矩阵每条副对角线值相等，由序列$a$生成的矩阵如下：
      $$
      A=\left[\begin{array}{ccccc}{a_{0}} & {a_{1}} & {a_{2}} & {\dots} & {\dots} & {a_{n-1}} \\ {a_{1}} & {a_{2}} & {} & {} & {} & {\vdots} \\ {a_{2}} & {} & {} & {} & {} & {\vdots} \\ {\vdots} & {} & {} & {} &  {} &{a_{2 n-4}} \\ 
      {\vdots} & {} & {} & {} & {a_{2 n-4}} & {a_{2 n-3}} \\ {a_{n-1}} & {\cdots} & {\cdots} & {a_{2 n-4}} & {a_{2 n-3}} & {a_{2 n-2}}\end{array}\right]
      $$

    - $Hankel$变换：由$b$序列变换为$h$序列
      $$
      h_{n}=\operatorname{det}\left(b_{i+j-2}\right)_{1 \leq i, j \leq n+1} \\
      令c_{n}=\sum_{k=0}^{n}\left(\begin{array}{l}{n} \\ {k}\end{array}\right) b_{k}\\
      则有：\operatorname{det}\left(b_{i+j-2}\right)_{1 \leq i, j \leq n+1}=\operatorname{det}\left(c_{i+j-2}\right)_{1 \leq i, j \leq n+1} \\
      即h在原序列二项式变换下，保持不变
      $$

    - 相关定理

      - $$
        \operatorname{det}\left(\left(X_{i}+A_{n-1}\right) \cdots\left(X_{i}+A_{j+1}\right)\left(X_{i}+B_{j}\right) \cdots\left(X_{i}+B_{1}\right)\right)_{i, j=0}^{n-1}\\
        =\prod_{0 \leq i<j \leq n-1}\left(X_{i}-X_{j}\right) \prod_{1 \leq i \leq j \leq n-1}\left(B_{i}-A_{j}\right)
        $$

      - $$
        \operatorname{det}\left(C_{\alpha_{i}+j}\right)_{i, j=0}^{n-1}=\prod_{0 \leq i<j \leq n-1}\left(\alpha_{j}-\alpha_{i}\right) \prod_{i=0}^{n-1} \frac{(i+n) !\left(2 \alpha_{i}\right) !}{(2 i) ! \alpha_{i} !\left(\alpha_{i}+n\right) !}
        $$

  - $k-Dyck \space Path$

    - $Dyck \space Path$是说一条从$(0,0)$到$(2n,0)$的一条路径，每次横坐标增加$1$，纵坐标增加$1$或$-1$，且不越过$x$轴

    - $k-Dyck \space Path$是说有$k$条这样的路径，第一条不越过$x$轴，第$i$条不越过即不低于第$i-1$条路径

    - 一一对应：列数不超过$2k$的，元素$\in [1,n]$内的且**每行长度为偶数**的**半标准杨表**和长度均为$2n+2$的$k-Dyck \space Path$构成一一对应；若将其旋转一下，可转化为从$(0,0)$到$(n+1,n+1)$的$k$条路径，每次只可以向右向上走一步，不能越过上一条路径，第一条不低于$y=x$

    - 计数公式
      $$
      \large b_{n,k}=\prod_{1 \le i \le j \le n} \frac{2k+i+j}{i+j}
      $$

    - 下三角矩阵的$LDS$

      - 下三角矩阵$M$的$LDS$定义为权值和最大的路径，可选一个起点，然后每次走向右上方的某个格子，或者同行的右侧的某个格子，注意不要求权值递增

      - $LDS(M) \le k$的下三角矩阵$M$与$k-Dyck \space Path$一一对应

      - 元素$\in[1,n]$，每行长度为偶数，半标准杨表和$n \times n$的对称矩阵$M'$一一对应，杨表列数$=LDS(M')$

      - 元素$\in[1,n]$，列数$\le k$半标准杨表与$n \times n$元素$\in[0,k]$满足每行每列均非严格递增的**对称矩阵**数量相等
        $$
        \large a_{n,k}=\prod_{1 \le i \le j \le n} \frac{k+i+j-1}{i+j-1}
        $$

- 半标准杨表计数

  - 元素$\in[1,n]$，半标准杨表$ \lambda = (\lambda_1,\cdots,\lambda_m),n=\sum_{i=1}^m\lambda_i$的计数公式
    $$
    \large \prod_{(i,j) \in \lambda} \frac{n+j-i}{h_\lambda(i,j)}=\prod_{1 \le i < j \le n} \frac{\lambda_i-\lambda_j+j-i}{j-i}
    $$

  - 例题：$CodeChef \space BillBoards(BB)$

- 形状带限制的杨表计数

  - 列数$\le k$，即$LIS \le k$的排列计数

    - 定义
      $$
      \begin{aligned} u_{k}(n) &=\sum_{\lambda \vdash n, \lambda_{1} \leq k} f_{\lambda}^{2} \\ U_{k}(x) &=\sum_{n \geq 0} u_{k}(n) \frac{x^{2 n}}{n !^{2}} \\ I_{i}(2 x) &=\sum_{n \geq 0} \frac{x^{2 n+i}}{n !(n+i) !} \end{aligned} \\
      其中I_k(2x)=I_{-k}(2x)表示第一类修正贝塞尔函数，有许多性质
      $$

    - 定理
      $$
      \large U_{k}(x)=\operatorname{det}\left(I_{i-j}(2 x)\right)_{i, j=1}^{K} \\
      \begin{aligned} U_{2}(x) &=\left|\begin{array}{cc}{I_{0}(2 x)} & {I_{1}(2 x)} \\ {I_{1}(2 x)} & {I_{0}(2 x)}\end{array}\right|=I_{0}(2 x)^{2}-I_{1}(2 x)^{2} \\ \Rightarrow u_{2}(n) &=\frac{1}{n+1}\left(\begin{array}{c}{2 n} \\ {n}\end{array}\right) \end{aligned} \\
      u_{3}(n)=\frac{1}{(n+1)^{2}(n+2)} \sum_{j=0}^{n}\left(\begin{array}{c}{2 j} \\ {j}\end{array}\right)\left(\begin{array}{l}{n+1} \\ {j+1}\end{array}\right)\left(\begin{array}{l}{n+2} \\ {j+2}\end{array}\right)
      $$

  - 行数$\le k$

    - 定义
      $$
      y_{k}(n)=\sum_{\lambda \vdash n, \lambda_{1} \leq k} f_{\lambda}
      $$

    - 定理
      $$
      \begin{aligned} y_{2}(n) &=\left(\begin{array}{c}{n} \\ {\lfloor n / 2\rfloor}\end{array}\right) \\ y_{3}(n) &=\sum_{i=0}^{\lfloor n / 2\rfloor}\left(\begin{array}{c}{n} \\ {2 i}\end{array}\right) C_{i} \\ y_{4}(n) &=C_{\lfloor(n+1) / 2 \rfloor} C_{\lceil(n+1) / 2\rceil} \\ y_{5}(n) &=6 \sum_{i=0}^{\lfloor n / 2\rfloor}\left(\begin{array}{c}{n} \\ {2 i}\end{array}\right) C_{i} \frac{(2 i+2) !}{(i+2) !(i+3) !} \end{aligned}
      $$







### 【122】博弈论：基础知识梳理

- $NP$状态定理

- $sg$函数理论

  - 适用组合游戏特点
    - 二人博弈，双方绝对聪明且利己
    - 游戏在有限步内终止，无法决策方输
    - 游戏状态不能重复抵达，游戏无平局；即游戏图为$DAG$
    - 决策空间只与游戏状态有关，与游戏者无关，即游戏决策是对称的，游戏是信息公开的
  - $sg$函数定义与递推
  - 游戏和与$nim$和

- 普通$Nim$游戏

  - 一步策略：若$n$堆依次为$x_1,x_2,...,x_n$，异或和不为$0$，先手存在必胜策略；下面构造一个方案，令$X=XOR_{i=1}^nx_i$，只需要将某个$x_i$变成$x_i \oplus X<x_i$即可；考虑寻找一个$i \in [1,n]$，满足$x_i$在与$X$对其的最高位为$1$，即满足前述要求

- $Anti-Nim$游戏与$SJ$定理

  - 定义：$nim$游戏中，拿走最后一个石子者输，即决策空间为空者赢
  - 结论：先手必胜当且仅当：
    - 游戏的$sg>0$，且存在单一游戏$sg>1$
    - 游戏的$sg=0$，且所有单一游戏$sg \le 1$

- $Multi-Nim$游戏

  - 定义：可以将一堆石子分成若干堆(可指定或者不指定堆数)，即一个单一游戏的后继可以为多个单一游戏的和
  - 结论：利用经典的$sg$递推即可，不同决策的后继之间用$mex$操作，游戏和用$nim$和

- $Every-Nim$游戏

  - 定义：每一轮游戏，选手必须将每个没有结束的单一游戏，推进一步；必胜则要求最长的步数使得到达胜利状态，必败则要求最短的步数使得到达必败态
  - 令$step[x]$表示状态$x$的步数，满足上述所求
    - 若$v$为终止状态，$step[v]=0$
    - 若$sg[v]>0$，$step[v]=max\{step[u]\}+1$，$sg[u]=0$，$v \to u$
    - 若$sg[v]=0$，$step[v]=min\{step[u]\}+1$，$v \to u$
  - 结论：先手必胜当且仅当单一游戏的最大$step$为奇数

- 阶梯博弈

  - 定义：有一组阶梯编号为$0,1,2,...$；每个阶梯上有一些石子，每次可以选择一个阶梯移动一部分到左边紧靠着的阶梯，不能移动者输；$0$为地面。
  - 结论：等价于只考虑奇数编号的阶梯的$nim$游戏，因为对方将奇数移动到偶数，看成某一堆石子减少，将偶数移动到奇数，则你可以立刻将同样多的石子从奇数移动到偶数，故操作抵消，奇数编号石子数不变。

- $nimk$游戏

  - 定义：$n$堆石子，双方轮流取，每次可以取最多$k$堆，每堆可以取任意个石子(至少$1$个)，无子取者败
  - 结论：将每堆石子数$a_i$转化为二进制数，统计每一位上的$1$个数之和，若每一位的和都是$k+1$的倍数，则先手必败，否则先手必胜

- $Bash$博弈及其扩展

  - 普通$Bash$博弈
    - 定义：每次选择一堆，取走数量$\in [1,m]$
    - 结论：$n$为$m+1$倍数为必败态，否则为必胜态
  - $Bash$博弈扩展
    - 定义：每次选择一堆，取走数量$\in [a,b]$
    - 结论：$n \in [1,a) \cup (b,a+b)$平局，除此之外$n\%(a+b)=0$先手必败，否则先手必胜

- 硬币游戏

  - 定义：按照规则翻一系列硬币，要求满足所翻动的下标最大的硬币必须从正面到反面
  - 基本结论：局面的$sg$值等于局面中正面朝上即$1$单独存在时的单一游戏$sg$值的$nim$和
  - 已知经典游戏：下标从$1$开始
    - 每次翻连续$k$个
      - $sg$值分布为：$00...001$周期为$k$，即$sg(x)=[k|x]$
    - 每次先翻动$x$，然后在$x-1,x-2,x-3$中选择一个翻动
      - $sg$值分布为：$1,2,3,0,1,2,3,0...$，周期是$4$
    - 每次翻动严格$2$个，下标差$\in \{1,2,3\}$，下标从$0$开始
      - $sg$值分布为：$0,1,2,3,0,1,2,3,...$，注意$sg(0)=0$，周期为$4$
    - 每次翻动个数不超过$3$个，下标从$0$开始
      - $sg$值分布为：$sg(x)=2x+!parity(x)$，$parity(x)$表示$x$二进制$1$的个数是否为奇数
    - 每次翻动连续任意多个，至少$1$个，下标从$1$开始(尺子游戏)
      - $sg$值分布为：$sg(x)=lowbit(x)=x\&-x$

- 删边游戏

  - 树上删边游戏

    - 定义：给定$n$个点的有根树，双方轮流删边，移走不与根连通的分支，无法操作者输
    - 结论：叶子节点$sg$值为$0$，非叶节点的$sg$值等于儿子的$sg+1$的异或和
    - 分析：某棵子树$x$可以等效的替换为长度(边数)为$sg(x)$的单一链分支，那么考虑很多儿子的子树，他们需要先生长一条边，然后并联时，直接作为游戏和异或合并；等价于转化为一堆石子数为$x$的单一游戏，$sg(x)=x$

  - 特殊图上删边游戏：$Christmas \space Game$

    - 定义：图可看成从基础树，添加一些环得到；每次选择树上一个点，在空中生长出一个环还要回到这个点，不能经过其他树上的点

      ![博弈1](\pic\博弈论\博弈1.JPG)

    - 结论：偶环直接去掉，奇环等效为长度为$1$的链

      ![博弈2](\pic\博弈论\博弈2.JPG)

    - 分析：长度为偶数的环，无论剪去哪条边，都只能分成一奇一偶两条链，其异或和为奇数，故$sg=0$，可消去；或者说，无论先手删哪一条边，对方可以对称的删对应边，先手必败，$sg=0$；长度为奇数的环，首先先手是必胜的，因为可以删正中间的边，然后对称操作即可，故$sg>0$，而删去一条边后得到奇偶性相同的两条链，其异或和为偶数，故$sg=1$

  - 图上删边游戏

    - 定义：无向连通图，有一个点为根，不能删边者输，其余规则一样
    - 结论：$Fusion \space Principle$
      - 偶环缩成新点，所有与环相连的边直接与新点相连；奇环缩成新点，延伸一条新边；这样转换$sg$值不变

- 有环$sg$博弈/有向图博弈

  - 使用$spfa$更新$NP$状态值或者$sg$函数值

- 三人$nim$游戏

- $K-L-nim$游戏

- $k$倍动态减法游戏

  - 定义：有一堆石子，含$m$个，双方轮流取，不能取输；第一个人可以取任意个，不能一次取完；以后每次取的石子数量不超过上一次的$k$倍(严格小于$m$个)

  - 结论：

    - 特殊情况：$k=1$，当且仅当$m$为$2$的幂次时，后者胜利，否则先手胜利；$k=2$游戏退化为斐波那契博弈

    - 一般情况：令$NP(x,y)$表示当前有$x$个石子，本次所取不超过$y$个，是否先手必胜；显然存在单调性，即若$NP(x,y_0)=1$，则$\forall y \ge y_0,NP(x,y)=1$；故令$f(x)$表示石子个数为$x$时，使得$NP(x,y_0)=1$的最小$y_0$；考虑画出$NP$表格图，值为$0$的一行中连成一堵墙，如图所示：

      <img src="\pic\博弈论\博弈3.JPG" alt="博弈3" style="zoom: 200%;" />

      考虑一行一行求解$f(i)$，$i$为行数；$f(i)$具有几何意义：从$(i,0)$这个格子，沿着直线$y=x$出发，撞到第一赌墙，所走的步数；注意墙有单调性，即若一堵墙不能挡住当前的射线，则再也不可能挡住以后产生的射线；考虑采用单调栈，从栈顶开始，挡不住的墙依次弹栈，直到撞到，计算步数即$f(i)$，然后产生长度为$f(i)-1$的新墙，压栈；时间复杂度$O(m)$，从几何角度不难实现；先手必败当且仅当$f(m)=m$，因为先手第一次只能取$[1,m-1]$内的石子个数，即$NP(m,m-1)$

- 斐波那契博弈

  - 定义：一堆石子，先手不能全取完，以后每次一方取的个数不超过另一个方上次的两倍，不能取输
  - 结论：斐波那契数处先手必败，否则先手必胜

- 威佐夫博奕

  - 定义：两堆石子，每次任选一堆取走任意个，或者两堆同时取走同样多个，不能取者输
  - 结论：令两堆石子个数为$a,b(a \le b)$，令$k=\frac{\sqrt{5}+1}{2}$，若$(int)k(b-a)=a$，则先手必败，否则先手必胜，即必败态$\{\lfloor k\cdot\frac{1+\sqrt{5}}{2}\rfloor, k+\lfloor k\cdot\frac{1+\sqrt{5}}{2}\rfloor\}(k = 0,1,2,\cdots)$
  - 扩展：两堆石子，个数分别为$n,m(n \le m)$ ，两人轮流从某一堆拿任意数量的物品或同时从两堆中取绝对值$\le k$的物品，每次至少一个，不能操作的人败；$d = k + 1, t^2 + (d - 2) * t - d = 0$，解出$t$，$(m - n) / d * t = n$则为必败态

- 不平等博弈

  - $surreal \space number$基础

    - 定义：是一个包含无穷小、无穷大和实数的域，用它可以十分方便地研究一些不平等博弈问题。$surreal \space number$定义为一个集合对 $\{L|R\}$，其中 $L$ 中的每个元素小于 $R$ 中的每个元素。我们称 $x≤y$ 当且仅当不存在 $x_L∈X_L$ 使得 $y≤x_L$，且不存在 $y_R∈Y_R$ 使得 $y_R≤x$。
    - 性质：
      - 若$x=\{L|R\}$，则$L<x<R$，表示$x$严格大于$L$中的任何一个元素，严格小于$R$中的任何一个元素
      - 令$L_{max}$表示$L$中最大值，则$x=\{L_{max}|R_{min}\}$；注意$L,R$可以为空，这时可以认为其最值为正负无穷大，不影响结论
      - 若$a<x<b$，且$x$是在$a$和$b$之间最早出现的(在树结构中层数最小)，则可证明$x$是唯一的，且$x=\{a|b\}$
    - 运算：
      - 加法法则：$x+y=\{X_{L}|X_{R}\}+\{Y_{L}|Y_{R}\}=\{X_{L}+y,x+Y_{L}|X_{R}+y,x+Y_{R}\}$
      - 取反法则：$-x=-\{X_{L}|X_{R}\}=\{-X_{R}|-X_{L}\}$
      - 乘法法则：$xy=\{X_{L}|X_{R}\}\{Y_{L}|Y_{R}\}=\{X_{L}y+xY_{L}-X_{L}Y_{L}，X_{R}y+xY_{R}-X_{R}Y_{R}|X_{L}y+xY_{R}-X_{L}Y_{R}，xY_{L}+X_{R}y-X_{R}Y_{L}\}$
      - 求逆法则：$\displaystyle{\frac{1}{y}=\{0,\frac{1+(y^{R}-y)(\frac{1}{y})^{L}}{y^{R}},\frac{1+(y^{L}-y)(\frac{1}{y})^{R}}{y^{L}}|\frac{1+(y^{L}-y)(\frac{1}{y})^{L}}{y^{L}},\frac{1+(y^{R}-y)(\frac{1}{y})^{R}}{y^{R}}\}}$

  - 判定结论

    - 用一个$surreal \space number$   $x=\{L|R\}$表示一个局面，$L$集合表示左边玩家的决策空间(子局面)，则可利用$x$的值分类判定游戏状态的胜负情况：
      - $x>0$，$L$玩家总是获胜，无论他是先手还是后手
      - $x<0$，$R$玩家总是获胜，无论他是先手还是后手
      - $x=0$，后手获胜
      - $x||0$，先手获胜；这种情况$x$超出了实数的表示范围是一类无穷类数，表示在$0$附近且和$0$不可比的实数外的数
    - 游戏和：直接求出每个子游戏的$surreal \space number$值$x_i$，则总游戏值为其和$\sum_i{x_i}$
    - 更多结论，请参阅参考文献

  - 一些常见的无穷类数的表示
    $$
    \begin{aligned}\\
    &\{0|1,\frac{1}{2},\frac{1}{4},\cdots\}=\epsilon(无穷小)\\
    &\{0,1,2,3,\cdots|\}=\omega(无穷大)\\
    &\{\epsilon|1,\frac{1}{2},\frac{1}{4},\cdots\}=2\epsilon\\
    &\{0|\epsilon\}=\frac{\epsilon}{2}\\
    &\{0,1,2,3,\cdots,\omega|\}=\omega+1\\
    &\{0,1,2,3,\cdots|\omega\}=\omega-1\\
    &\{\omega|\omega+1\}=\omega+\frac{1}{2}\\
    \end{aligned}\\
    $$

- 纳什均衡理论

  - 纯策略均衡：画出$payoff$矩阵，容易检查某个状态是否是纯策略均衡，第一维在行中取最值，第二维在列中取最值，意思是当处于这个组合状态时，任何一方不会轻易改变自己的策略，这个组合是占优的
  - 混合策略均衡：纳什均衡点指的是一组策略，表示某一方对决策空间有一个概率分布，有一个固定的概率选择某个决策，双方均有；在此纳什均衡点处，双方任何一方，不会率先改变自己的策略，因为这样只会使得自己受益减少；无论对方选择何种具体决策，在此点处我们的期望受益$\sum_{c \in S}P_c*V_c$是相等的
  - 纳什均衡点存在定理：在允许混合策略的情况下，任意一个有限个玩家的，每个玩家有有限个可选纯策略的游戏，必然有至少一个纳什均衡点
  - 典型例子
    - 智猪博弈

- $nim$积理论

  - 定义：$x \otimes y = \mathrm{mex}\{(a \otimes b) \oplus (a \otimes y) \oplus (x \otimes b), 0 \le a < x, 0 \le b < y\}$

  - 数表：

    |      |  0   |  1   |  2   |  3   |  4   |
    | :--: | :--: | :--: | :--: | :--: | :--: |
    |  0   |  0   |  0   |  0   |  0   |  0   |
    |  1   |  0   |  1   |  2   |  3   |  4   |
    |  2   |  0   |  2   |  3   |  1   |  8   |
    |  3   |  0   |  3   |  1   |  2   |  12  |
    |  4   |  0   |  4   |  8   |  12  |  6   |

  - 运算性质：

    - $$
      \begin{aligned}
      x \otimes 0 &= 0 \otimes x = 0\\ 
      x \otimes 1 &= 1 \otimes x = x\\
      x \otimes y &= y \otimes x
      \end{aligned}
      $$

    - $$
      \begin{aligned}
      x \otimes (y \otimes z) &= (x \otimes y) \otimes z\\
      x \otimes (y \oplus z) &= (o \otimes y) \oplus (x \otimes z)
      \end{aligned}
      $$

    - $\forall n \in N_+,[0,2^{2^{n}}-1]$中的数在$(\otimes,\oplus)$下构成一域

    - $\forall n \in N_+,2^{2^{n}}\otimes x=2^{2^{n}}\times x(0\le x<2^{2^{n}})$

    - $\forall n \in N_+,2^{2^{n}}\otimes 2^{2^{n}}=\frac{3}{2}\cdot2^{2^{n}}=2^{2^{n}}\oplus2^{2^{n}-1}$

  - 复杂度：模板计算一次大约复杂度$O(log^2)$

  - 应用：高维硬币游戏

    - 考虑二维网格平面，选择一个正方形(边长$\ge 2$)，取角落$4$个格子，同时翻转硬币，要求右上角(横纵坐标都大)的一个格子是从正面翻到反面的，不能翻者败，其$sg(x,y)=x \otimes y$
    - 可以扩展成三维或者更高维，$sg(x,y,z)=x \otimes y \otimes z$
    - 考虑另一个版本的硬币游戏，每次选择一个正方形(边长$\ge 2$)，取右上角和左下角翻转，则$sg(x,y)=x \oplus y$

- $shannon$开关游戏

- 广义地理游戏

- $k-knights$游戏

  - 定义：棋盘上有$k$只马，每次玩家对每只马都要操作，每只马只能向左下角四个方向走(日子)，当无法操作者输
  - 结论：由于是一种$Every$游戏，故单一游戏需要满足：能够胜利的尽可能慢的胜利，不能胜利尽可能快的输掉；令$round(x,y)$表示单一的马在$(x,y)$时最快的步数，结论为：$round(x,y)-\lfloor\frac{x}{2}\rfloor-\lfloor\frac{y}{2}\rfloor$有规律(除了左下角$4 \times 4$和最外围一圈，可以$dp$)。


### 【124】代数：奇数双阶乘对$2^p$分块模数列的性质

函数$f(n)=1\times 3 \times 5 \times \cdots \times n$，其中$n$为奇数，则令$b_n=f(2^n) \% 2^p$。则$b_{kn}=b_k^n$对$k \ge \frac{p+1}{3}$恒成立。若已知$b_k=B$，则$f(n)=B^{\lfloor n/2^k \rfloor}*\prod_{k \in [\lfloor n/2^k \rfloor\times 2^k +1,n] 且 odd(k)}k$，复杂度$O(2^k)$。

### 【125】代数：关于下降阶乘幂的多项式间的运算

- 两个下降阶乘幂多项式的乘法

  - 令$f(x)=\sum_{i=0}^{+\infin} a_ix^{\underline{i}},A(x)=\sum_{i=0}^{+\infin}a_ix^i$

  - $g(x)$与$f(x)$形式类似，要求$f(x)g(x)$一种思路是利用斯特林数将两个多项式本身的具体系数求出来，然后用$fft/ntt$做多项式乘法，但是那样没有利用好阶乘幂本身的性质

  - 不难发现：$\frac{k^{\underline{i}}}{k!}=\frac{1}{(k-i)!}$

  - 我们考虑绕过$f(x)$本身的具体系数，直接求其点值序列的指数型生成函数$F(x)$

  - $$
    F(x)=\sum_{k=0}^{+\infin}\frac{f(k)}{k!}x^k=\sum_{k=0}^{+\infin}\frac{x^k}{k!}\sum_{i=0}^{+\infin}a_ik^{\underline{i}}=\sum_{i=0}^{+\infin}a_i\sum_{k=0}^{+\infin}\frac{x^k}{(k-i)!}=e^x\sum_{i=0}^{+\infin}a_ix^i=e^xA(x)
    $$

  - 我们已知$A(x)$，即可从$F(x)$中取出点值序列，$G(x)$类似，点值序列直接点乘，构成指数型生成函数$F_{ret}(x)$，再利用上述公式逆向求得$A_{ret}(x)=e^{-x}F_{ret}(x)$，取出系数即可


### 【126】图论：图有关的定理

- $Petersen's$   $theorem$
  - $3-$正则无桥边的无向图，必存在完美匹配(此图不可能有奇数个点)
  - 推广：$d-$正则无向图，边连通度$\ge d-1$(至少删除$d-1$条边，图才可能不连通)，若点数为偶数，则必存在完美匹配；更进一步的，对每一条边，都存在一个包含此边的完美匹配
- $Tutte$   $theorem$
  - 无向图$G=(V,E)$，存在完美匹配，当且仅当$\forall U\subseteq V$，$G-U$至多含有$|U|$个奇数联通块
  - 即$G=(V,E),\forall U \subseteq V,odd(G-U) \le |U|$，其中$odd(G)$表示$G$中奇数连通块的个数
- $Tutte–Berge$   $formula$
  - $G=(V,E)$的最大匹配的个数$=\frac{1}{2}min_{U \subseteq V}(|U|-odd(G-U)+|V|)$
- $Matrix$  $Tree$  $theorem$
- $BEST$   $theorem$



