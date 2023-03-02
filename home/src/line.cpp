#include <graphics.h>
// #include <windows.h>

int main()
{
    int gDriver = DETECT;
    int gMode;
    initwindow(550, 500);
    initgraph(&gDriver, &gMode, NULL);
    line(200, 300, 600, 300);
    getch();
    closegraph();
}