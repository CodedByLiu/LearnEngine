import Log;

int main() 
{
    LogInit();

    LogInfo("引擎日志系统启动成功！");
    LogWarn("这是一个警告信息！");
    LogError("这是一个错误信息！");

    return 0;
}