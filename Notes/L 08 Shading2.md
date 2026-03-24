高光：
观察方向和反射方向接近
半程向量h和n接近=>镜面反射法线是角平分线=>$\mathbf{h}=\frac{\mathbf{v}+\mathbf{l}}{\|\mathbf{v}+\mathbf{l}\|}$
镜面反射：$L_s=k_s(I/r^2)max(0,\mathbf{n}\cdot\mathbf{h})^p$，镜面反射，p指数用于控制高光在夹角稍大时能量迅速衰减（p>=100）
环境光照：$L_a=k_aI_a$，I_a为环境光强度
总光能量：环境光+漫反射+高光反射
着色频率
gouraud shading：顶点法线，顶点做一次着色，然后顶点内的三角形做一次插值算出来着色
phong shading：逐像素着色
顶点法线：相邻面法线向量根据面积求加权平均

重心坐标

实时渲染管线：
输入：点
vertex processing：点投影到屏幕上=>顶点mvp变换，shading
triangle processing：确定三角形
rasterization：逐像素化=>光栅化
fragment processing：着色=>z buffer深度缓存，shading，phong shading 
framebuffer operations获得输出图像