### 毕设系统——智慧工地监控管理系统

#### 项目简介

建筑施工场所环境复杂，工作条件艰苦，工人在施工过程中对安全规则的遵守程度普遍较低，由此产生的不安全行为在施工期间埋下潜在的安全隐患。本系统基于华为软件定义相机本生的智能业务，利用SDK接口实现人员身份识别、安全设备佩戴检测、危险区域入侵检测等不安全行为的检测，并在后台构建预警系统，对不安全行为数据进行记录。

#### 系统需求分析

* （1）基于SDK智能分析类接口，调用相机本身的人脸识别业务、行为识别功能
* （2）监管模块：调用相机第三方APP智能元数据，实现检测结果预览功能
* （3）预警模块：存储检测后的违规数据（视频、图像、用户信息等），并显示预警结果。

#### 系统架构









####   数据库表设计

![](https://image.easyblog.top/%E6%99%BA%E8%83%BD%E5%AE%89%E5%85%A8%E7%9B%91%E7%AE%A1%E5%B9%B3%E5%8F%B0E-R%E5%9B%BE.jpg)





####  开发日志

* 2021年3月15     讨论具体需求，讨论并设计数据库，设计E-R图，完成数据库表的建立
* 2021年3月16     在程序中实现Controller-->Service-->DAO-->Database 一套流程的基本代码的编写和测试运行；

