# Security Simple Double Buffer
安全的双缓冲区简单实现

## 应用背景
* 如MCU串口中断函数中会读取一些传感器数据并保存起来，在MCU的主程序段中读取处理这些数据。
* 中断函数写入数据的时间间隔远远超过MCU中读取一次数据的时间。
* 若操作同一个数据的话极有可能造成数据的冲突。
* 通过设置双buffer，每次读取的均为上一次写入的数据则不会发生数据冲突。

## Usage
* MCU: call DB_BUF_INIT() to init data 
* ISR: call DB_BUF_SET() to write data 
* MCU: call DB_BUF_GET() to read data 
