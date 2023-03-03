#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

/*this function will use putpixel() function to fill color between two parallel and equal straight lines.
 * Don't use in case of any polygon because function like floodfill() will help in that case in easy way.
 *
 * Args:
 * color - color to be filled.
 * line1X1 - starting x coordinate of first line
 * line1Y1 - starting y coordinate of first line
 * length - length of the line (both line is parallel and equal)
 * height - distance between both parallel lines.
 */
void fillColorBetWeenTwoLines(int color, int line1X1, int line1Y1, int length, int height)
{
    // setfillstyle(SOLID_FILL, MAGENTA);
    // floodfill(200, 300, 10);

    for (int row = line1Y1; row <= line1Y1 + height; row++)
    {
        /*outer for loop for filling y axis (vertical)
         * row will be y axis.
         */
        for (int column = line1X1; column <= line1X1 + length; column++)
        {
            /*inner for loop for filling x axis (horizontal)
             * column will be x axis.
             */
            putpixel(column, row, color);
        }
        delay(10);
    }
}

int main()
{
    int gDriver = DETECT;
    int gMode;
    initgraph(&gDriver, &gMode, NULL);

    int stripWidth = 150;
    int stripHeight = 30;
    int stickHeight = 300;
    int stickTopX = 50;
    int stickTopY = 50;

    /*drawing stick*/
    setlinestyle(SOLID_LINE, 1, 5);
    // line(stickTopX, stickTopY, stickTopX, stickTopY + stickHeight);
    /*-4 because of line style*/
    line(stickTopX - 4, stickTopY, stickTopX - 4, stickTopY + stickHeight);
    /*resetting line style*/
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);

    /*now drawing flag strip*/
    line(stickTopX, stickTopY, stickTopX + stripWidth, stickTopY);
    delay(50);
    line(stickTopX, stickTopY + stripHeight, stickTopX + stripWidth, stickTopY + stripHeight);
    delay(50);
    line(stickTopX, stickTopY + (2 * stripHeight), stickTopX + stripWidth, stickTopY + (2 * stripHeight));
    delay(50);
    line(stickTopX, stickTopY + (3 * stripHeight), stickTopX + stripWidth, stickTopY + (3 * stripHeight));
    delay(50);

    /*filling color*/
    delay(50);
    fillColorBetWeenTwoLines(COLOR(255, 153, 51), stickTopX, stickTopY, stripWidth, stripHeight);
    delay(50);
    fillColorBetWeenTwoLines(WHITE, stickTopX, stickTopY + stripHeight, stripWidth, stripHeight);
    delay(50);
    fillColorBetWeenTwoLines(COLOR(19, 136, 8), stickTopX, stickTopY + (2 * stripHeight), stripWidth, stripHeight);

    /*line right side of the strip*/
    line(stickTopX + stripWidth, stickTopY, stickTopX + stripWidth, stickTopY + (3 * stripHeight));

    setcolor(COLOR(0, 0, 128)); /*setting color to navy blue for ashok chakra*/
    /*circle*/
    delay(50);
    circle(stickTopX + stripWidth / 2, stickTopY + stripHeight * 1.5, stripHeight / 2);
    int centerX = stickTopX + stripWidth / 2;
    int centerY = stickTopY + stripHeight * 1.5;

    /*24 lines inside the circle (Ashok Chakra)*/
    int angle = 15;
    int radius = stripHeight / 2;
    for (int i = 0; i < 24; i++)
    {
        line(centerX, centerY, centerX + radius * cos(angle), centerY + radius * sin(angle));
        angle += 15;
        delay(50);
    }

    getch();
    closegraph();
}