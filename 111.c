#include <graphics.h>
#include <conio.h>

int main(void)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(YELLOW);
    circle(320, 240, 100);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    floodfill(320, 240, YELLOW);

    getch();
    closegraph();
    return 0;
}