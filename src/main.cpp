import Log;
import Window;

int main() 
{
    LogInit();
    LogInfo("引擎启动中...");

    WindowInit(1280, 720, "Learn Engine");

    while(!WindowShouldClose())
    {
        WindowClear(0.60f, 0.20f, 0.20f);
        WindowUpdate();
    }

    WindowShutdown();
    LogInfo("引擎正常退出。");

    return 0;
}