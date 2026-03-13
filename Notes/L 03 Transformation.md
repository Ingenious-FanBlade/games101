# Transformation 变换

## Scale Matrix

- 本质单位向量变换
  $$\begin{bmatrix} x'\\y'\end{bmatrix}=\begin{bmatrix} s_x&0\\0&s_y\end{bmatrix}\begin{bmatrix} x\\y\end{bmatrix}$$

> Reflection Matrix: $s_x or s_y=-1$

## Shear Matrix

- 本质单位向量变换
  $$\begin{bmatrix} x'\\y'\end{bmatrix}=\begin{bmatrix} 1&a\\0&1\end{bmatrix}\begin{bmatrix} x\\y\end{bmatrix}$$

> - $x$方向单位向量不变，$y$方向单位向量变为$\begin{bmatrix}a & 1 \end{bmatrix}^T$
> - 绕原点旋转

## Rotate Matrix

- 本质单位向量变换
  $$
  \begin{bmatrix}
      x'\\y'
  \end{bmatrix}=\begin{bmatrix}
      cos\theta&-sin\theta\\sin\theta&cos\theta
  \end{bmatrix}\begin{bmatrix}
    x\\y
  \end{bmatrix}
  $$

# Linear Transforms
$$x'=ax+by\\y'=cx+dy$$
$$\begin{bmatrix}
    x'\\y'
\end{bmatrix}=\begin{bmatrix}
    a&c\\b&d
\end{bmatrix}\begin{bmatrix}
    x\\y
\end{bmatrix}$$

# 齐次坐标下的变换

- 2D point: $\begin{bmatrix}
    x,y,1
\end{bmatrix}^T$
- 2D vector: $\begin{bmatrix}
    x,y,0
\end{bmatrix}^T$

- $\begin{bmatrix}
    x,y,w
\end{bmatrix}$ 即是2D点: $\begin{bmatrix}
    \frac{x}{w},\frac{y}{w},1
\end{bmatrix}(w\neq0)$

## Scale

$$S(s_x,s_y)=\begin{bmatrix}
    s_x&0&0\\0&s_y&0\\0&0&1
\end{bmatrix}$$

## Rotation

$$R(\alpha)=\begin{bmatrix}
    cos\theta&-sin\theta&0\\sin\theta&cos\theta&0\\0&0&1
\end{bmatrix}$$

## Translation
$$T(t_x,t_y)=\begin{bmatrix}
    1&0&t_x\\0&1&t_y\\0&0&1
\end{bmatrix}$$

## Composite Transform
- $R\cdot T\neq T\cdot R$
- 对于变换：$A_n(...A_2(A_1(x))) = A_n...A_2\cdot A_1\begin{bmatrix}
    x\\y\\1
\end{bmatrix}$，从右往左依次应用于向量

### 复杂变换的分解：以绕某点c为例
变换矩阵$M=T(-c)R(\alpha)T(c)$（先平移回原点，旋转，然后再平移回c点）

