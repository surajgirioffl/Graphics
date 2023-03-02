#include <graphics.h>
int main()
{
    int gDriver = DETECT;
    int gMode;
    initgraph(&gDriver, &gMode, NULL);
    line(200, 300, 300, 150);
    line(200, 300, 400, 300);
    line(400, 300, 300, 150);
    getch();
    closegraph();
}