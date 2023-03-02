#include <graphics.h>
int main()
{
    int gDriver = DETECT;
    int gMode;
    initgraph(&gDriver, &gMode, NULL);
    arc(400, 400, 90, 0, 100);
    getch();
    closegraph();
}