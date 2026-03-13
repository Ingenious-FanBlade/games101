# Transformation Cont. 视图变换

## 三维齐次坐标下变换的矩阵

### Scale

$$S(s_x,s_y,s_z)=\begin{bmatrix}
    s_x&0&0&0\\0&s_y&0&0\\0&0&s_z&0\\0&0&0&1
\end{bmatrix}$$

### Translation

$$T(t_x,t_y,t_z)=\begin{bmatrix}
    1&0&0&t_x\\0&1&0&t_y\\0&0&1&t_z\\0&0&0&1
\end{bmatrix}$$

### Rotation

$$R_x(\alpha) = \begin{bmatrix}
    1&0&0&0\\0&cos\alpha&-sin\alpha&0\\0&sin\alpha&cos\alpha&0\\0&0&0&1
\end{bmatrix}$$

$$R_y(\alpha) = \begin{bmatrix}
    cos\alpha&0&sin\alpha&0\\0&1&0&0\\-sin\alpha&0&cos\alpha&0\\0&0&0&1
\end{bmatrix}$$
> 由于指定了z轴方向为$z=x\times y$，因此$x\times z=-y$

$$R_z(\alpha) = \begin{bmatrix}
    cos\alpha&-sin\alpha&0&0\\ sin\alpha&cos\alpha&0&0\\0&0&1&0\\0&0&0&1
\end{bmatrix}$$

- 任意的3D旋转：$R_{xyz}(\alpha,\beta,\gamma)=R_x(\alpha)R_y(\beta)R_z(\gamma)$
- 罗德里格斯旋转公式：
$$R(\bm{n},\alpha)=cos(\alpha)\bm{I}+(1-cos(\alpha))\bm{n}\otimes\bm{n^T}+sin(\alpha)\begin{bmatrix}
    0&-n_z&n_y\\n_z&0&-n_x\\-n_y&n_x&0
\end{bmatrix}$$

