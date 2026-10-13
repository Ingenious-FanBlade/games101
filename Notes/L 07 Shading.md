# Shading 1

## Z-Buffer 深度缓冲
- 用来描述像素在前后关系
- 每个像素存储对应的深度值
  > - frame buffer帧缓冲存储像素的颜色
  > - depth buffer深度缓冲存储像素的深度值

### Z-Buffer 要求
1. $z\in[0,1]$
2. z更小更近，更大更远

## Shading 着色

### Bling- Phone反射模型
- 高光：镜面反射
- 漫反射
- 环境光照

shading point 着色点：在物体表面
inputs 光线方向 $I$：指向光源
法线方向 $n$
viewer direction观测者方向 $v$：指向观测者

> 着色的局部性：只考虑这个点的着色情况 => 不产生阴影，只有明暗变化

### 漫反射

- 漫反射：$L_d=k_d(I/r^2)max(0,\boldsymbol{n}\cdot\boldsymbol{l})$
- $Color_{new} = k_d(Color_{old}/r^2)max(0,\boldsymbol{n}\cdot\boldsymbol{l})$

