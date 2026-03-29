材质和表面 
三角形内插值=>重心坐标
法线插值
Barycentric Coordinates
重心坐标$(\alpha , \beta, \gamma)$
$(x,y)=\alpha A+\beta B+\gamma C$
$\alpha + \beta + \gamma =1$，当三个值全都非负时点在三角形内部
三角形重心重心坐标：(1/3,1/3,1/3)
插值的属性也用重心坐标线形插值
重心坐标不能保证投影后坐标不变=>在3维坐标中插值

某个点的(u,v)=>设置像素的颜色为对应纹理坐标的颜色

纹理过小（低分辨率）
texel 纹理上的像素
纹理过小导致一个texel映射到了多个pixel
双线性插值法
线性插值：$lerp(x,v_0,v_1)=v_0+x(v_1-v_0)$
水平插值+竖直插值得到一个点的值

像素覆盖纹理过大
MipMap 近似的正方形范围查询
预生成不同分辨率图构成的金字塔
求MipMap Level D Mipmap级别：
$D = \log_{2}L$
$L = max(\sqrt{(\frac{du}{dx})^2+(\frac{dv}{dx})^2},\sqrt{(\frac{du}{dy})^2+(\frac{dv}{dy})^2})$
为了算出一个pixel映射到texel上对应的边长有多大
比如L=4，即对应的texel边长应该是4，此时对应的mipMap等于为2（该等级的mipMap像素粒度为4）
各向异性过滤
横竖分别压缩获得的mipmap 

通过找pixel对应的texel颜色确定pixel颜色