毕设系统——智慧工地监控管理系统
===

### 1、项目简介

建筑施工场所环境复杂，工作条件艰苦，工人在施工过程中对安全规则的遵守程度普遍较低，由此产生的不安全行为在施工期间埋下潜在的安全隐患。本系统基于华为软件定义相机本生的智能业务，利用SDK接口实现人员身份识别、安全设备佩戴检测、危险区域入侵检测等不安全行为的检测，并在后台构建预警系统，对不安全行为数据进行记录。

### 2、系统需求分析

#### 2.1 功能性需求

* （1）基于SDK智能分析类接口，调用相机本身的人脸识别业务、行为识别功能
* （2）监管模块：调用相机第三方APP智能元数据，实现检测结果预览功能
* （3）预警模块：存储检测后的违规数据（视频、图像、用户信息等），并显示预警结果。

#### 2.2 非功能性需求

1. 可靠性：该系统的可靠性主要是在系统是否能够长时间正常的运行，以及系统远程调用SDC的接口是否可以及时响应。
2. 安全性：该系统的使用者一般是建筑工地工程管理人员，系统旨在降低建筑工地工程管理人员的管理难度，提高施工人员的安全意识，而且这类系统一般只运行在内部网络，同时对于某些关键信息，比如管理员登陆密码都进行了AES加密处理，即使系统被攻破，攻击者也无法在短时间内获得管理员密码，因此安全性比较高；
3. 易用性：该系统基于Web开发，因此可以方便的使用浏览器在任意一台具有网络的个人电脑上进行访问。
4. 可扩展性：系统使用MVC模式的Web应用体系结构进行开发，层次分明，各司其职，系统中的模型层、控制器层和视图层可以独立变化。
5. 可维护性：该系统中最重要的模型层全部基于设计模式中的接口隔离原则开发，即所有的功能模块都是对应功能接口的实现类，维护人员可以轻松的基于功能接口重新定义新的实现。
   可测试性：系统集成了著名的Java测试框架JUtil，测试程序十分方便。


### 3、系统架构

<img src="https://camo.githubusercontent.com/1d6a6f31d4eec326ad11c2b7b5d0b39378e8e207515fe2a1abcf96ddc89b0b39/687474703a2f2f696d6167652e65617379626c6f672e746f702f3136313639333936343130333336643638363632652d333365662d343031652d396463392d6261636663313031326133302e6a7067" alt="" data-canonical-src="http://image.easyblog.top/16169396410336d68662e-33ef-401e-9dc9-bacfc1012a30.jpg" style="width: 60%;max-width: 60%;">


### 4、项目重难点技术栈

#### 4.1 流媒体技术

流媒体就是指采用流式传输技术在网络上连续实时播放的媒体格式，如音频、视频或多媒体文件。流媒体技术也称流式媒体技术.
所谓流媒体技术就是把连续的影像和声音信息经过压缩处理后放上网站服务器,由视频服务器向用户计算机顺序或实时地传送各个压缩包，
让用户一边下载一边观看、收听，而不要等整个压缩文件下载到自己的计算机上才可以观看的网络传输技术。该技术先在使用者端的
计算机上创建一个缓冲区，在播放前预先下一段数据作为缓冲，在网路实际连线速度小于播放所耗的速度时，播放程序就会取用一小段
缓冲区内的数据，这样可以避免播放的中断，也使得播放品质得以保证。

![](https://img-blog.csdnimg.cn/2020090814504028.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM4NTk5ODQw,size_16,color_FFFFFF,t_70#pic_center)

**三种常见的视频流协议介绍（RTMP、RTSP、HLS）**

<img src="https://camo.githubusercontent.com/3efce8227bee2324785e92ba8c19a49744a6e1e515d1a4cd308a1a694e3d9648/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303230303632383136313333383338382e706e673f782d6f73732d70726f636573733d696d6167652f77617465726d61726b2c747970655f5a6d46755a33706f5a57356e6147567064476b2c736861646f775f31302c746578745f6148523063484d364c7939696247396e4c6d4e7a5a473475626d56304c32566e64576c6b587a453d2c73697a655f31362c636f6c6f725f4646464646462c745f3730" alt="" data-canonical-src="https://img-blog.csdnimg.cn/20200628161338388.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2VndWlkXzE=,size_16,color_FFFFFF,t_70" style="width: 48%;">


**（1）RTMP（Real Time Messaging Protocol）实时消息传输协议**

RTMP是由Adobe公司提出的，是一种设计用来进行实时数据通信的网络协议，属于TCP/IP五层中的应用层，基于TCP协议，默认使用端口1935。RTMP中的基本数据单元称为消息（Message），传输的过程中消息会被拆分为更小的消息块（Chunk）单元，再将分割后的消息块通过 TCP 协议传输，接收端再将接收到的消息块恢复成流媒体数据。RTMP协议一般传输的是 flv，f4v 格式流（注意：RTMP 是协议，flv、f4v 是视频封装格式）。

RTMP 的特点：

* RTMP 是专为流媒体开发的协议，对底层的优化比其它协议更加优秀，同时它 Adobe Flash 支持好，基本上所有的编码器（摄像头之类）都支持 RTMP 输出。支持 Flash 的浏览器都能播放 RTMP 协议传输的流。

* RTMP 的延迟相对较低，一般延时在 1-3s 之间，一般的视频会议，互动式直播，是完全是够用的。

* 基于 TCP 传输，使用非公共端口，可能会被防火墙阻拦。

* RTMP 为 Adobe 私有协议，很多设备无法播放，特别是在 iOS 端，需要使用第三方解码器才能播放；

* 直接播放 RTMP 流需要浏览器支持 Flash。

**（2）RTSP（Real Time Streaming Protocol）实时流传输协议**

rtp是实时传输协议，并不一定传输的是视频，也可用于传输其他数据，补充一下rtp也可以传输h264/hevc裸流，至于它传什么数据，这个要取决于源头提供什么数据。一般而言，rtp协议用于监控设备较多，但是传输什么格式的视频数据还是要看具体设备传输而定。

rtsp是rtp的扩展协议，rtp只负责传输ps/ts封装流，rtsp在rtp基础上增加了传输控制和控制指令以支持视频回放，回放控制和设备指令控制等功能。RTSP是TCP/IP协议体系中的一个应用层协议，该协议定义了一对多应用程序如何有效通过IP网络传送多媒体数据。RTSP在体系结构上位于RTP和RTCP之上，它使用TCP或RTP完成数据传输。HTTP与RTSP相比，HTTP传送HTML，而RTP传送的是多媒体数据。HTTP请求由客户机发出，服务器做出响应；RTSP可以是双向的，即客户机和服务器都可以发出请求。

RTSP与RTP最大的区别在于：RTSP是一种双向实时数据传输协议，它允许客户端向服务器端发送请求，如回放、快进、倒退等操作。当然RTSP可基于RTP来传送数据，还可以选择TCP、UDP、组播UDP等通道来发送数据，具有很好的扩展性。它是一种类似于HTTP协议的网络应用协议。

**（3）HLS（HTTP Live Streaming）**

HLS是由苹果公司提出的基于Http协议的的流媒体网络传输协议。其工作原理是把整个流分成一个个ts文件来下载，每次只下载一个ts文件。在开始一个流媒体会话时，客户端会下载一个包含元数据的m3u8文件，用于寻找可用的媒体流。

![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly91cGxvYWQtaW1hZ2VzLmppYW5zaHUuaW8vdXBsb2FkX2ltYWdlcy83MTE0NDI5LTBhZDc5ZjkyNDEwNDk5MDUucG5n?x-oss-process=image/format,png)

HLS 协议特点：

* 跨平台性：支持iOS/Android/浏览器，通过http请求即可，通用性强。
* 穿墙能力强：由于HLS是基于HTTP协议的，基本不会遇到被防火墙屏蔽的情况。
* 切换码率快（清晰度）：自带多码率自适应，客户端可以选择从许多不同的备用源中以不同的速率下载同样的资源，允许流媒体会话适应不同的数据速率。客户端可以很快的选择和切换码率，以适应不同带宽条件下的播放。
* 负载均衡：HLS基于无状态协议（HTTP），客户端只是按照顺序使用下载存储在服务器的普通TS文件，做负责均衡如同普通的HTTP文件服务器的负载均衡一样简单。
* 实时性差：苹果官方建议是请求到3个ts切片文件之后才开始播放。所以一般很少用HLS做为互联网直播的传输协议。假设列表里面的包含5个ts文件，每个ts文件包含5秒的视频内容，那么整体的延迟就是25秒。苹果官方推荐的ts时长时10s，所以这样就会大概有（3 x 10）秒的延迟。
* 文件碎片化严重：对于点播服务来说, 由于ts切片文件通常较小, 海量碎片在文件分发, 一致性缓存, 存储等方面都有较大挑战。


本项目使用流媒体技术实现从摄像机获取实时的RTSP协议格式的流数据，然后经过流媒体服务器处理之后形成可以在浏览器中直接显示的RTMP
格式的流数据（需要FLASH支持），从而实现实时监控的目的


**（4）多媒体音视频处理工具FFmpeg**

FFmpeg官方地址：http://www.ffmpeg.org/ffmpeg.html

FFmpeg是一套可以用来记录、转换数字音频、视频，并能将其转化为流的开源计算机程序。采用LGPL或GPL许可证。它提供了录制、转换以及流化音视频的完整解决方案。它包含了非常先进的音频/视频编解码库libavcodec，为了保证高可移植性和编解码质量，libavcodec里很多code都是从头开发的。
FFmpeg在Linux平台下开发，但它同样也可以在其它操作系统环境中编译运行，包括Windows、Mac OS X等。这个项目最早由Fabrice Bellard发起，2004年至2015年间由Michael Niedermayer主要负责维护。许多FFmpeg的开发人员都来自MPlayer项目，而且当前FFmpeg也是放在MPlayer项目组的服务器上。项目的名称来自MPEG视频编码标准，前面的"FF"代表"Fast Forward"。 [1]  FFmpeg编码库可以使用GPU加速

转码过程ffmpeg对于每个输出可以用下图来描述：

![](https://image.easyblog.top/image-20210616162725989.png)

ffmpeg调用libavFormat库(包含演示程序)来读取输入文件，并从其中获取包含编码数据的数据包。当有多个输入文件时，ffmpeg试图通过跟踪任何活动输入流上的最低时间戳来保持它们的同步。

然后将编码的数据包传递给解码器(除非为流选择了流拷贝，请参阅进一步的描述)。解码器产生未压缩帧(原始视频/PCM音频/.)可以通过过滤进一步处理(请参阅下一节)。过滤后，帧被传递给编码器，编码器对它们进行编码并输出编码的数据包。最后，这些文件被传递给muxer，它将编码的数据包写入输出文件。


#### 4.2 Nginx 和 nginx-rtmp-module

**Nginx**

Nginx(engine x)是一个高性能的HTTP和反向代理web服务器，同时也提供了IMAP/POP3/SMTP服务。其特点是占有内存少，并发能力强，事实上nginx的并发能力在同类型的网页服务器中表现较好，中国大陆使用nginx网站用户有：百度、京东、新浪、网易、腾讯、淘宝等。
Nginx专为性能优化而开发，性能是器最重要的考量，实现上非常注重效率，能经受高负载的考验，据报告能支持高达50,000个并发连接数。
Nginx不仅能做反向代理，实现负载均衡；还能可以作正向代理来进行上网等功能。


**nginx-rtmp-module**

nginx-rtmp-module是一款NGINX的流媒体插件，除了直播发布音视频流之外具备流媒体服务器的常见功能

* 比如推拉流媒体资源
* 基于HTTP的FLV/MP4 VOD点播
* HLS (HTTP Live Streaming) M3U8的支持
* 基于http的操作（发布、播放、录制）
* 可以很好的协同现有的流媒体服务器以及播放器一起工作
* 在线调用ffmpeg对流媒体进行转码
* H264/AAC音视频编码格式的支持
* linux/BSD/MAC系统的支持



#### 4.3 JNA(Java Native Access)框架


Java开发过程中，有时候会需要和C，C++等交互，这时候我们就想起了经典技术JNI，但是JNI的使用过程十分繁琐，而且容易出现各种问题，还得封装而且问题不好定位。假如我们有一个.so文件，如果使用JNI去调用，我们需要另外用C语音写一个.so的共享文件，并且得使用SUN规定的数据结构去替代C语言的数据结构，至此才能调用so文件里面公布的函数。作为JAVA的程序员这个过程是令人头疼的。

相比之下，使用JNA就简单多了，只需要依赖一个jar包，就像调用一个java方法一样简单。JNA全称Java Native Access，是一个建立在JNI技术之上的Java开源框架。JNA提供一组Java工具类用于在运行期动态访问系统本地库（native library：如Window的dll，Linux的so）而不需要编写任何Native/JNI代码。开发人员只要在一个java接口中描述目标native library的函数与结构，JNA将自动实现Java接口到native function的映射。

dll和so是C函数的集合和容器，这与Java中的接口概念吻合，所以JNA把dll文件和so文件看成一个个接口。在JNA中定义一个接口就是相当于了定义一个DLL/SO文件的描述文件，该接口代表了动态链接库中发布的所有函数。而且，对于程序不需要的函数，可以不在接口中声明。

在该系统中，Java应用程序需要和软件定义摄像机（SDC）北向接口交互，但是华为提供的SDC北向接口是C语言开发的，Java语言无法直接调用，因此本系统使用JNA来实现对SDC北向接口的调用。原理如下图所示，
我们需要在Java层面引入JNA框架，然后自定义接口`HWPuSDK`并继承JNA提供的`com.sun.jna.Library`接口，并在HWPuSDK接口中描述北向接口中的函数和结构

![](https://image.easyblog.top/image-20210616163105939.png)

在Windows的IDEA开发工具中配置本地lib环境：

（1）设置项目使用的JDK版本

该项目由于华为北向接口的限制，在Windows平台上只有jdk8 32位可以正常运行

![](http://image.easyblog.top/16169416847050f93ff8a-c692-478a-ad6f-161f23125a2b.png)


（2） 点击Libraries ,添加动态链接库的依赖

项目中由于使用了华为软件定义摄像机官方提供的动态链接库，这些库文件位于resources目录下的libs目录中，并且我使用JNA框架来加载这些dll，但是JNA在加载的时候只会从系统或项目定义的类路径下加载dll，libs默认不在JNA扫描的范围内，因此我们需要配置将libs目录添
加到库路径中，好让JNA来加载dll：

（3）点击Project Struct.... --->  Libraries  点击图中所示的“+”号

![](http://image.easyblog.top/16169418403029dc9b0dd-1ed6-4569-a2ed-bd20305608f4.png)

（4）选择Java库，并且选中项目下的libs目录

<img src="https://camo.githubusercontent.com/1c8408ed6df2712106c586091d8c61f2d66a060519c3a0fb9f392dd0f4fcab16/687474703a2f2f696d6167652e65617379626c6f672e746f702f3136313639343138363633303662343332613864652d303863352d343233622d623530332d6231313032316161653961632e706e67" alt="" data-canonical-src="http://image.easyblog.top/1616941866306b432a8de-08c5-423b-b503-b11021aae9ac.png" style="width: 50%;">

（5）检查Modules中是否选中依赖

<img src="https://camo.githubusercontent.com/d8e6e2f10f7a56eef21c557dc6662e28b5c2c9fb072a35e693b850f8c203bd23/687474703a2f2f696d6167652e65617379626c6f672e746f702f3136313639343139303132373136316132386531382d316633632d343564332d613464632d3235326565623534643739382e706e67" alt="" data-canonical-src="http://image.easyblog.top/161694190127161a28e18-1f3c-45d3-a4dc-252eeb54d798.png" style="width: 80%;">

做完这些步骤后你的代码中应该就可以正常加载dll库并获取dll的实例对象了

###   5、数据库表设计

![](https://image.easyblog.top/image-20210616162426271.png)

数据库表结构定义在工程目录中的sql文件下



### 6、项目效果展示

<iframe 
    height=450 
    width=800 
    src="http://player.youku.com/embed/XMzMxMjE0MjY4NA==" 
    frameborder=0 
    allowfullscreen>
</iframe>




####  开发日志

* 2021年3月15      讨论具体需求，讨论并设计数据库，设计E-R图，完成数据库表的建立；
* 2021年3月16      实现Controller-->Service-->DAO-->Database 一套流程的基本代码的编写和测试运行；
* 2021年3月17      引入七牛云作为图床保存图片，完成七牛云自动配置以及图片上传接口的开发；
* 2021年3月25      调用相机SDK接口实现初始化SDK、清理SDK初始化、登陆相机、退出相机功能
* 2021年3月28      将工程开发平台迁移到IDEA上（不得不说，用了IDEA后真的回不去eclipse了，eclipse用起来真的非常不顺手）
* 2021年3月31      构建并调试FFmpeg+Nginx-RTMP流媒体服务器将网络摄像头的RTSP视频流数据推送成可以直接在浏览器上直接播放的RTMP格式视频流数据
* 2021年4月07      引入JavaCV，使用JavaCV FFMPEG推流摄像机RTSP视频流到nginx-rtmp
* 2021年4月11      JavaCV推流效果太差，转变思路直接使用Java调用本地FFmpeg执行有关命令来进行推流，显示效果大大提高，但视频播放有3秒左右的延迟，后续有待优化
* 2021年4月13      增加后台管理系统；实现了管理员用户的注册和登陆（分布式Session登陆）
* 2021年4月16      后台管理系统——完成人员管理模块的前后端代码的编写以及调试
* 2021年4月17      后台管理系统——引入PageHelper分页插件，实现完成人员管理模块的分页功能
* 2021年4月18      整合并完善之前`BusinessRealPlayServiceImpl`和`BusinessUserServiceImpl`两个服务中的逻辑代码，将其统一到IHWPuSDKService接口中，并在新接口中新增获取相机信息的方法：`getDeviceInfo()`
* 2021年4月20      后端管理系统——完成管理员权限管理模块的前后端代码的编写和调试，取消了管理员注册功能
* 2021年4月21      后台管理系统——修复后端管理系统中若干已知BUG
* 2021年5月1日     实现基于人脸识别的考勤打卡功能
* 2021年5月3日     实现人脸考勤动态数据分析API接口的开发
* 2021年5月6日     实现区域人流量统计功能
* 2021年5月10日    实现对人流量数据进行实时动态分析的API接口的开发
* 2021年5月12日    开始前后端联调：调试了人员管理大数据看板的内容
* 2021年5月16日    加载第三放人员危险行为识别以及告警算法App，固化模型
* 2021年5月17日    第三方算法App调用失败，原因是做算法的团队提供的算法App不对，着手从人员危险预警模块开始做起，通过添加实验数据写好预警模块的API接口
* 2021年5月20日    前后端联调：完成人员管理页面的调试，并调试了首页监控大屏部分内容
* 2021年5月21日    前后端联调：完成首页以及实时监控大屏的调试
* 2021年5月22日    前后端联调：完成了人员危险行为实时告警页面的调试
* 2021年5月23日    前后端联调：完成了人员危险行为抓拍页面的调试
