# Unreal4 术语

* 常见视图模式

  | 模式     | 效果                                         |
  | -------- | -------------------------------------------- |
  | 带光照   | 显示应用了材质和光照的场景的最终结果         |
  | 不带光照 | 从场景中移除所有光照，显示来自材质的基础颜色 |
  | 线框     | 显示场景中Actor的所有多边形的边              |
  | 细节光照 | 在整个场景中显示中性材质，使用法线贴图       |
  | 仅光照   | 显示无法线信息且仅被光照影响的中性材质       |




---



* UE4 模块

  [UE4 模块,PrivateDependencyModuleNames?](https://zhuanlan.zhihu.com/p/107270501)

  * Public / Private 文件夹
  * Build.cs 之 DependencyModuleNames / IncludePathModuleNames 依赖
  * 