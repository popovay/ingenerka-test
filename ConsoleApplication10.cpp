// ConsoleApplication10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "TXLib.h"
using namespace std;
struct menu_button
{
	
	HDC img;
	COLORREF color= TX_NULL;
	




};
bool Button(int x, int y, int w, int h, const char *str);
void PanelLoad(int nom, const char *PanelName);


int main()
{
	txCreateWindow(800, 600);
	
	while (!GetAsyncKeyState(VK_ESCAPE))
	{

		txBegin();
	//Button(100, 100, 0, 0, "Создать город");
	//Button(100, 170, 0, 0, "Загрузить город");
	//Button(100, 240, 0, 0, "Настройки");
		PanelLeft(1, "Дома");
	txEnd();
	}
}


bool Button(int x, int y, int w, int h, const char *str)
{

	
	menu_button button1;
	if (button1.color == TX_NULL)  button1.color = TX_RED;
	if (w== 0)  w = 120;
	if (h == 0)  h = 30;
	
	txSetFillColor(TX_YELLOW);

	txRectangle(x+3, y+8, x + w+8, y + h+8);
	txSetFillColor(button1.color);
	if (txMouseX() > x && txMouseY() > y && txMouseX() < x + w && txMouseY() < y + h) txSetFillColor(TX_GREEN);
	txRectangle(x, y, x + w, y + h);
	txSetColor(button1.color, 5);
	txRectangle(x, y, x+w, y+h);
	txSetColor(TX_WHITE, 5);
	txTextOut(x+5, y+5, str);

	return 0;

}
void PanelLeft(int nom, const char *PanelName)
{
	int n=250, imgX = 250, imgY = 250, imgRast = 250;;
	struct picter
{
	HDC img;
	int x;
	int y;
	int w;
	int h;
	const char *name;

};
	
   picter pic[4];
   
   pic[0].img = txLoadImage("img\\dom1.bmp");
   pic[1].img = txLoadImage("img\\dom2.bmp");
   pic[2].img = txLoadImage("img\\dom3.bmp");
   pic[3].img = txLoadImage("img\\dom4.bmp");
   for (int i=0;i<4;i++)
   {
	   pic[i].w = 200;
	   pic[i].h = 200;
   };
   
   txTransparentBlt(txDC(), imgX, imgY, 200, 200, pic[0].img);
   imgX = imgX + imgRast;
   txTransparentBlt(txDC(), imgX, imgY, 200, 200, pic[1].img);
   imgX = n;;
   imgY = imgY + imgRast;

   txTransparentBlt(txDC(), imgX, imgY, 200, 200, pic[2].img);
   imgX = imgX + imgRast;
   txTransparentBlt(txDC(), imgX, imgY, 200, 200, pic[3].img);
   imgX = n;;
   imgY = imgY + imgRast;
   
}
