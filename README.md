# UE4_LearnAnimation
本工程包含以下功能：
### 1、脚部IK，包含斜坡和台阶
![在这里插入图片描述](https://img-blog.csdnimg.cn/628b92beffbf48ab8f24df314423bfe7.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA5rC05puc5pel6bih,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/3af34f19d243430390d5cf0830e42264.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA5rC05puc5pel6bih,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
***
## 脚部IK  
### 学习资料
- [[UE4蓝图]虚幻4中完整实现脚部IK（一）](https://zhuanlan.zhihu.com/p/84399021)  
- [[UE4蓝图]虚幻4中完整实现脚部IK（二）（完结）](https://zhuanlan.zhihu.com/p/85949418)  
-  [Unreal Engine 4 Tutorial - IK Part 1 - Understanding IK](https://www.youtube.com/watch?v=dpteQzWMbfQ&list=RDCMUCsS5i15vvUbwfr_1JdRKCAA&start_radio=1&t=3s&ab_channel=RyanLaley)  
- [Unreal Engine 4 Tutorial - IK Part 2 - Foot Placement Tracing](https://www.youtube.com/watch?v=M-6CP8c3qfw&ab_channel=RyanLaley)  
- [Unreal Engine 4 Tutorial - IK Part 3 - Foot Positioning](https://www.youtube.com/watch?v=cqI1nKnyzdg&ab_channel=RyanLaley)  
- [Unreal Engine 4 Tutorial - IK Part 4 - Final Touches and Fixes](https://www.youtube.com/watch?v=VRaOwDqbvIY&ab_channel=RyanLaley)  

### 实现原理
脚部IK的实现原理是发射射线检测判断脚底的地面情况，射线起点是脚底位置加上胶囊体半高（也可以是其他高度，设这个值为h），射线终点是脚底位置减去设定的判定距离（设这个值为d）。

脚底位置 = （脚底骨骼的xy值（GetSocketLocation），角色Mesh的Location的z值）。

射线检测结果可以拿到击中距离（hitDistance）。h - hitDistance = 脚部要抬高多少距离。

拿到距离后使用TwoBoneIk节点设置EffectorLocation。
### 遇到的问题和注意事项记录
- **注意点：左脚和右脚的骨骼空间x轴方向是相反的，左脚向上，右脚向下**。
- **问题：在台阶时，其中一只脚不会贴合地面。** 产生原因：角色的腿部是有固定长度的，不能无限伸长，所以需要对整体骨骼进行向下的位移。
- **问题：判定距离太小导致跨两级台阶时检测不到地面**。（图中是50）解决方法：调高判定距离（最长不能超过整条腿的长度，工程里判定距离为90）。
![在这里插入图片描述](https://img-blog.csdnimg.cn/41a7bbd5da6248b09dd83d659d879967.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA5rC05puc5pel6bih,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
- **问题：经过台阶时疯狂抖动。解决方法：使用lerp过渡**。（蓝图是FInerrpTo节点，InerpSpeed建议为10到20，太高了依然会有抖动，太低了会产生慢慢把脚放到地面的动画表现很不自然）
![在这里插入图片描述](https://img-blog.csdnimg.cn/a281e129136d46dca7eac5a0ea6d60fd.gif#pic_center)
- **问题：脚掌没有贴合斜坡。解决方法：根据法向量计算出脚部骨骼需要旋转的角度。RotationX=arctan（法向量y/法向量z）RotationY= -arc tan（法向量x/法向量z）**。（在上面列的[[UE4蓝图]虚幻4中完整实现脚部IK（二）（完结）](https://zhuanlan.zhihu.com/p/85949418)  文章里计算Y轴旋转角度时没有乘以-1，是错误的）。
![在这里插入图片描述](https://img-blog.csdnimg.cn/905f35838e414d5ea52c0429d5592cc6.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA5rC05puc5pel6bih,size_18,color_FFFFFF,t_70,g_se,x_16#pic_center)
