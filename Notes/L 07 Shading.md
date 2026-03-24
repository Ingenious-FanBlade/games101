z-buffering
深度z永远整数=>z小意味着更靠近=>z-buffer灰度越小

目前流程：mvp矩阵确定二维正则空间中的位置->视口变换->三角形采样

着色：
高光、漫反射、环境光照=>材质

shading point：物体表面=>切平面
inputs: 观测方向、光照方向、法线（单位向量）、物体表面属性（颜色、材质、shininess）
只考虑这个点的着色情况，着色的局部性=>没有阴影，只有明暗变化
漫反射
bling-phong：
漫反射 光的能量接收
能量接收和法线与光线夹角余弦值成正比
点光源传播的光强能量：I/r1^2=I/r2^2，平方反比。
光传播到shading point并被吸收然后反射：$L_d=k_d(I/r^2)max(0,\boldsymbol{n}\cdot\boldsymbol{l})$
k_d漫反射系数，L_d反射后的光线
跟观察方向没有关系