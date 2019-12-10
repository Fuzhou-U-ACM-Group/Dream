$$
我们考虑扩展这个积分的计算：\\
令变上限积分F(X_1,X_2,\cdots,X_n)=\int_0^{X_1} \cdots \int_0^{X_n} f\left(\left\lfloor x_1 + \cdots + x_n\right\rfloor\right) dx_1 \cdots dx_n,X_i \in N_+\\
令S=\sum_{i=1}^nX_i,s=\sum_{i=1}^nx_i,注意总是上下文符号表示\\
令p(k)=\int_0^{X_1} \cdots \int_0^{X_n} [\lfloor s \rfloor ==k] dx_1 \cdots dx_n\\
p(k)=\sum_{p_1=0}^{X_1-1}\sum_{p_2=0}^{X_2-1}\cdots\sum_{p_n=0}^{X_n-1}\int_{0}^1\int _0^1\cdots \int_0^1[\lfloor \sum_{i=1}^np_i+s \rfloor ==k  ]dx_1dx_2\cdots dx_n \\
=\sum_{r+s=k\\r \ge 0,s\in [0,n]} \\
F=\sum_{k=0}^Sf(k)p(k)\\
$$

