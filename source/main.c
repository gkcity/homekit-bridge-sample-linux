#include <tiny_socket.h>
#include <tiny_snprintf.h>
#include <device/access/Access.h>
#include "device/definition/bridge/Bridge.h"
#include "device/initializer/InitializeConfiguration.h"
#include "HomeKitStack.h"
#include "DeviceMonitor.h"
#include "CommandReader.h"

//#define DID                 "1C:BE:EE:01:02:0A" // error
//#define DID                 "1C:BE:EE:01:02:0B"
#define DID                 "1C:BE:EE:01:02:0D"
#define NAME                "demo"
#define IP                  "10.0.1.29"
#define SETUP_CODE          "031-45-154"

int main(void)
{
    Product *product = NULL;
    uint16_t port = 60006;

    tiny_socket_initialize();

    /**
     * 1. 初始化设备
     */
    product = Bridge(DID, NAME, IP, SETUP_CODE);
    if (product == NULL)
    {
        return 0;
    }

    /**
     * 2. 线程1： 启动协议栈，连接到服务器，等待控制指令并执行。
     */
    StartHomeKit(product, &port);

    /**
     * 3. 线程2： 监控设备数据，如果发生变化，则通过ipc端口通知服务器。
     */
//    StartDeviceMonitor(device->did, port);

    /**
     * 4. 线程3: 主线程，阻塞在这里，等待用户输入命令
     */
    WaitingForUserCommand(port);

    /**
     * 5. 停止数据监控
     */
    StopDeviceMonitor();

    /**
     * 6. 停止协议栈
     */
    StopHomeKit();

    /**
     * 7. 删除设备，准备退出
     */
    Product_Delete(product);

    tiny_socket_finalize();

    return 0;
}
