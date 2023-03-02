#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;

bool isTrueTriangle(int b, int p, int h)
{
    if((h*h) == ((b*b)+(p*p)))
    {
        cout<<"Triangle is valid"<<endl;
        return true;
    }
    return false;
}

void drawTriangle(int b, int p, int h)
{
    int gDriver=DETECT;
    int gMode;
    initgraph(&gDriver, &gMode, NULL);

    /*for base*/
    int bx1 = 200;
    int by1 = 200;
    int bx2 = bx1 + b;
    int by2 = by1;

    /*for perpendicular*/
    int px2 = bx1;
    int py2 = by1-p;

    line(bx1, by1, bx2, by2); /*base*/
    line(bx1, by1, px2, py2); /*perpendicular*/
    line(px2, py2, bx2, by2); /*hypotenuse*/

    getch();
    closegraph();
}

int main()
{
    char* b = (char*)calloc(1, 20);
    char* h = (char*)calloc(1, 20);
    char* p = (char*)calloc(1, 20);
    int base, height, hypotenuse;
    cout<<"Write base (press enter if N/A): ";
    cin.getline(b, 20);
    cout<<"Write height (press enter if N/A): ";
    cin.getline(p, 20);
    cout<<"Write hypotenuse (press enter if N/A): ";
    cin.getline(h, 20);


    int na=0;/*not available*/
    try{
        if (strcmp(b, "\0")==0)
        {
            na++;
            base = -1;
        }
        else
        {
            base = atoi(b);
            if(base==0)
                throw 1;
        }

        if(strcmp(p, "\0")==0)
        {
            na++;
            height = -1;
        }
        else
        {
            height = atoi(p);
            if(height==0)
                throw 1;

        }
    
        if(strcmp(h, "\0")==0)
        {
            na++;
            hypotenuse = -1;
        }
        else
        {
            hypotenuse = atoi(h);
            if(base==0)
                throw 1;
        }

    }
    catch(int a)
    {
            cout<<"Something went wrong while conversion."<<endl;
            exit(-1);
    }

    if(na >1 )
    {
        cout<<"You must need to pass at least two of 3"<<endl;
        exit(-1);
    }

    /* Now we have taken all desired values.*/
    if( hypotenuse == -1) /*means hypotenuse not given */
    {
        hypotenuse = sqrt(base*base + height*height);
    }
    else if (base == -1) /*if base is not given.*/
    {
        base = sqrt(hypotenuse*hypotenuse - height*height);
    }
    else if (height == -1) /*if height is not given*/
    {
        height = sqrt (hypotenuse*hypotenuse - base*base);
    }
    else /*if already all of 3 are given*/
    {
        if(!isTrueTriangle(base, height, hypotenuse))
        {
            cout<<"Triangle is not valid......"<<endl;
            exit(-1);
        }
    }

    /*everything is alright*/
    drawTriangle(base, height, hypotenuse);
}