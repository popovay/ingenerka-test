#include <iostream>
#include "TXLib.h"
using namespace std;


int main()
{
    int x=50,y=50;
    int w=50, h=200;
    txCreateWindow(600,600);
    int n=1;

    for (int i=1;i<7;i=i+1)
    {
    if(n<4){txFillColour(TX_YELLOW); n=n+1}
    else {txFillColour(TX_GREEN);n=1;}
    txRectangle(x,y,x+w,y+h);
    x=x+70;

    }
    cout<<"Hello world";
    return 0;
}
