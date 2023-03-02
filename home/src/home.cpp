#include <graphics.h>
int main()
{
    int graphDriver = DETECT;
    int graphMode;
    initgraph(&graphDriver, &graphMode, NULL);
    rectangle(200, 200, 300, 300);
    getch();
    closegraph();
}