GUI前端思路：

​	PageManager异步页面调度器 + U8G2图形库 +JuanEventButton按键事件库。

PageManager异步任务调度，先软件进行切换后进行实际调度。

每个页面单独是一个cpp文件，且需要具备四个固定静态函数

create:	创建页面，只在创建执行一次

loop:	会不间断执行

destory: 销毁页面，只会在切换其它页面时候执行一次

key_callback:按键回调，会向当前页面传递按键值和事件供当前页面处理

通过 PAGE_DECLARE 宏将当前cpp文件声明为一个页面，通过 PAGE_REGISTER宏在初始化函数中注册页面。

#TODO#
后端思路:
	设计一个 Class HAL接口类，供GUI对硬件进行数据读写以及控制。
	设计一个 Class Algorithm类，包括所需要的算法。
	设计一个 Class Net类，包括地理位置获取，ntp校时，udp，tcp，mqtt
	
后台调度思路：
	设计一个 Class Board 类。进行传感器数据读取，保存，上传，网络时间校准，睡眠调度。