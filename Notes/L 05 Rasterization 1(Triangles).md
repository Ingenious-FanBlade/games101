# Rasterization 光栅化

## 像素

- 一个像素从左下角开始到右上角
- 范围：$[0,0]\quad to\quad [width-1,height-1]$
- 像素$(x,y)$的中心点为$(x+0.5,y+0.5)$

## 视口变换

- 将空间从 $[-1,1]^2$ 变换为屏幕空间 $[0,width] \times [0,height]$

$$
M_{viewport}=\begin{bmatrix}
    width/2&0&0&width/2\\ 0&height/2&0&height/2\\ 0&0&1&0\\0&0&0&1
\end{bmatrix}
$$

## 三角形

- 可以通过向量叉积判断一个点是否在三角形外

### 判断方法

设三角形 $ABC$ 三条边向量分别为 $\overrightarrow{AB},\overrightarrow{BC},\overrightarrow{CA}$ ，设顶点$P$到三个顶点的向量为$\overrightarrow{AP},\overrightarrow{BP},\overrightarrow{CP}$

$$
\overrightarrow{AB}\times\overrightarrow{AP}\quad\And\quad\overrightarrow{BC}\times \overrightarrow{BP}\quad\And\quad \overrightarrow{CA}\times \overrightarrow{CP} \begin{cases}
    >0, &inside\\=0,&edge\\<0,&outside
\end{cases}
$$

## 采样操作

- 判断像素点中心是否在三角形内（叉积）

```
for(int x=0;x<xmax;++x)
    for(int y=0;u<ymax;++y)
        image[x][y]=inside(tri,x+0.5,y+0.5);
```

可以使用包围盒来减少不必要的判断

会带来锯齿问题（走样）
