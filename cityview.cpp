#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight * 0.75
int ldisp = 0;
void hut()
{
    // setcolor(WHITE);
    rectangle(0, 80, 90, 300); // 1st building
    // blocks
    rectangle(15, 90, 40, 110);
    rectangle(50, 90, 75, 110);
    rectangle(15, 120, 40, 140);
    rectangle(50, 120, 75, 140);
    rectangle(15, 150, 40, 170);
    rectangle(50, 150, 75, 170);
    rectangle(15, 180, 40, 200);
    rectangle(50, 180, 75, 200);

    rectangle(90, 50, 180, 300); // 2nd building
    // blocks
    rectangle(105, 70, 130, 90);
    rectangle(140, 70, 165, 90);
    rectangle(105, 100, 130, 120);
    rectangle(140, 100, 165, 120);
    rectangle(105, 130, 130, 150);
    rectangle(140, 130, 165, 150);
    rectangle(105, 160, 130, 180);
    rectangle(140, 160, 165, 180);

    // bulletin board
    line(380, 240, 380, 300);
    line(440, 240, 440, 300);
    rectangle(340, 160, 480, 240);
    outtextxy(360, 190, (char *)"Coaching Center");

    // cloud1
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    ellipse(220, 20, 0, 180, 35, 25);
    ellipse(240, 25, 285, 90, 40, 20);
    ellipse(230, 35, 210, 10, 25, 25);
    ellipse(210, 35, 150, 340, 25, 30);
    ellipse(199, 25, 105, 250, 35, 20);

    floodfill(220, 50, WHITE);

    // cloud2
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    ellipse(450, 30, 0, 170, 35, 25);
    ellipse(500, 40, 340, 160, 29, 25);
    ellipse(502, 60, 240, 50, 40, 20);
    ellipse(450, 70, 165, 355, 45, 20);
    ellipse(410, 45, 70, 270, 20, 20);

    floodfill(450, 70, WHITE);

    rectangle(510, 90, 620, 300); // 3rd building
    // blocks
    rectangle(530, 123, 555, 160);
    rectangle(574, 123, 599, 160);
    line(510, 190, 620, 190);
    line(510, 200, 620, 200);
    rectangle(530, 231, 555, 268);
    rectangle(574, 231, 599, 268);

    // road
    line(0, 300, ScreenWidth, 300);
    line(0, 410, ScreenWidth, 410);

    // THICK_WIDTH(3px);
    // setlinestyle(0,0,10);
    line(50, 348, 100, 348);

    // roadlight upper
    line(220, 230, 220, 300);
    circle(220, 220, 13);
    // roadlights
    line(135, 340, 135, 410);
    circle(135, 327, 13);
    line(340, 340, 340, 410);
    circle(340, 327, 13);
    line(545, 340, 545, 410);
    circle(545, 327, 13);

    setfillstyle(SOLID_FILL, BLUE); // 1st building
    floodfill(2, 82, WHITE);
    setfillstyle(SOLID_FILL, CYAN); // 2nd building
    floodfill(92, 52, WHITE);
    setfillstyle(SOLID_FILL, RED); // 3rd building
    floodfill(512, 92, WHITE);
    floodfill(512, 298, WHITE);
    setfillstyle(WIDE_DOT_FILL, WHITE); // 3rd building window
    floodfill(532, 125, WHITE);
    floodfill(576, 125, WHITE);
    floodfill(532, 233, WHITE);
    floodfill(576, 233, WHITE);
    setfillstyle(SOLID_FILL, DARKGRAY); // 3rd building division
    floodfill(512, 192, WHITE);
    setfillstyle(SOLID_FILL, LIGHTBLUE); // bulletin board
    floodfill(342, 162, WHITE);

    setfillstyle(SOLID_FILL, YELLOW); // road lights
    floodfill(220, 220, WHITE);
    floodfill(135, 327, WHITE);
    floodfill(340, 327, WHITE);
    floodfill(545, 327, WHITE);

    // setfillstyle(SOLID_FILL, BLACK); // road
    // floodfill(2, 302, WHITE);

    setfillstyle(SOLID_FILL, LIGHTGREEN); // below road
    floodfill(2, 412, WHITE);

    setfillstyle(SOLID_FILL, 0); // sky
    floodfill(0, 0, WHITE);

    // floodfill(252, 182, WHITE);
    // setfillstyle(SLASH_FILL, WHITE);
    // floodfill(17, 92, WHITE);
    // setfillstyle(WIDE_DOT_FILL, GREEN);
    // floodfill(532, 125, WHITE);
    // floodfill(210, 105, WHITE);
}
void DrawManAndUmbrella(int x, int ldisp)
{
    circle(x, GroundY - 90, 10);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(x + 2, GroundY - 88, WHITE);
    line(x, GroundY - 80, x, GroundY - 30);
    line(x, GroundY - 70, x + 10, GroundY - 60);
    line(x, GroundY - 65, x + 10, GroundY - 55);
    line(x + 10, GroundY - 60, x + 20, GroundY - 70);
    line(x + 10, GroundY - 55, x + 20, GroundY - 70);
    line(x, GroundY - 30, x + ldisp, GroundY);
    line(x, GroundY - 30, x - ldisp, GroundY);

    setfillstyle(CLOSE_DOT_FILL, YELLOW);
    pieslice(x + 20, GroundY - 120, 0, 180, 40);
    line(x + 20, GroundY - 120, x + 20, GroundY - 70);
}
void Rain(int x)
{
    int i, rx, ry;
    for (i = 0; i < 300; i++)
    {
        rx = rand() % ScreenWidth;
        ry = rand() % ScreenHeight;
        if (ry < GroundY - 4)
        {
            if (ry < GroundY - 120 || (ry > GroundY + 120 && (rx < x - 20 || rx > x + 60)))
                line(rx, ry, rx -0.5, ry + 10);
        }
    }
}
// void cloud()
// {
//     setcolor(WHITE);
//     setfillstyle(SOLID_FILL,BLUE);
//     ellipse(320,105,0,180,30,25);
//     ellipse(350,130,285,90,40,30);
//     ellipse(335,160,210,360,25,30);
//     ellipse(300,150,80,300,30,30);
//     ellipse(290,130,85,235,30,25);

//     floodfill(320,140,WHITE);
// }
void rainbow()
{
    int x, y, i;
    circle(ScreenWidth - 100, 50, 30);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(ScreenWidth - 100, 50, WHITE);
    hut();
    ldisp = (ldisp + 2) % 20;
    DrawManAndUmbrella(x, ldisp);
    // hut();
    x = getmaxx() / 10;
    y = getmaxy() / 10;
    for (i = 30; i < 100; i++)
    {
        delay(100);
        setcolor(i / 10);
        arc(x, y, 0, 180, i - 10);
    }
    getch();
}
int main()
{
    int gd = DETECT, gm, x = 0;
    initgraph(&gd, &gm, (char *)"");
    // initwindow(ScreenWidth, ScreenHeight, "Rainbow Scene");
    while (!kbhit())
    {
        hut();
        // circle(ScreenWidth - 100, 50, 30);
        // setfillstyle(SOLID_FILL, YELLOW);
        // floodfill(ScreenWidth - 100, 50, WHITE);
        // line(0, GroundY+50, ScreenWidth, GroundY+50);
        // setfillstyle(SOLID_FILL, BLACK);
        // floodfill(2, GroundY+48, WHITE);
        Rain(x);
        // hut();
        ldisp = (ldisp + 2) % 20;
        DrawManAndUmbrella(x, ldisp);
        delay(20);
        cleardevice();
        x = (x + 2) % ScreenWidth;
    }
    ldisp = (ldisp + 2) % 20;
    DrawManAndUmbrella(x, ldisp);
    
    // cloud();
    rainbow();
    getch();
    closegraph();
    return 0;
}