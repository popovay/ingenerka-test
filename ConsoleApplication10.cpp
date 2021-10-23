// ConsoleApplication10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "TXLib.h"
using namespace std;

struct picter
{
	HDC img;
	int x;
	int y;
	int w;
	int h;
	const char *name;
	bool Visible = FALSE;

};

picter img_in_town[1000];
int img_in_town_kol = 0;

struct menu_button
{
	
	HDC img;
	COLORREF color= TX_NULL;
	




};
bool Button(int x, int y, int w, int h, const char *str);

void PanelLeft(int nom, const char *PanelName, picter pic[], int x, int y);
//int MovePicter(int x, int y, HDC img );


int main()
{
	int sprite = 1;
	txCreateWindow(800, 600);
	picter pic[4];

	pic[0].img = txLoadImage("img\\dom1.bmp");
	pic[1].img = txLoadImage("img\\dom2.bmp");
	pic[2].img = txLoadImage("img\\dom3.bmp");
	pic[3].img = txLoadImage("img\\dom4.bmp");

	for (int i = 0;i < 4;i++)
	{
		pic[i].w = 200;
		pic[i].h = 200;
	};
	
	while (!GetAsyncKeyState(VK_ESCAPE))
	{

		txBegin();
		if (sprite == 1) {
			txSetFillColor(TX_BLACK);
			txClear();

			bool nomMenu = Button(100, 100, 0, 0, "Создать город");

			if (nomMenu) { sprite = 2; }

			nomMenu = Button(100, 170, 0, 0, "Загрузить город");
			if (nomMenu) { sprite = 3; }
			nomMenu = Button(100, 240, 0, 0, "Настройки");
			if (nomMenu) { sprite = 4; }
		}

		if (sprite == 2) {
			txSetFillColor(TX_BLACK);
			txClear();
			
			PanelLeft(1, "Дома", pic, 5, 100);
			bool nomMenu = Button(10, 10, 80, 20, "Заводы");
			if (nomMenu) { sprite = 5; }
			nomMenu = Button(100, 10, 80, 20, "Культура");
			if (nomMenu) { sprite = 6; }
			nomMenu = Button(190, 10, 80, 20, "Гл.меню");
			if (nomMenu) { sprite = 1; }

		}
		if (sprite == 1) {}
		//
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

	if (txMouseX() > x && txMouseY() > y && txMouseX() < x + w && txMouseY() < y + h && txMouseButtons() == 1)
	{
		txSleep(100);
		return 1;
	}
		

	return 0;

}
void PanelLeft(int nom, const char *PanelName, picter pic[], int x, int y)
{ 
	int img_w = 80, img_h = 80;

	int n=x, imgX = x, imgY = y, imgRast = 30;
	
	txSetFillColor(TX_RED);
	txRectangle(x, y, x + img_w+ img_w+ imgRast+5, y + img_h + img_h + imgRast + 100);
	txSetFillColor(TX_WHITE);
	txSelectFont("Comic Sans MS", 40);
	txTextOut(x +50 , y , PanelName);
	imgX = x + 5, imgY = y + 50;
   txTransparentBlt(txDC(), imgX, imgY, img_w, img_h, pic[0].img);
  
   imgX = imgX  +img_w+imgRast;
   txTransparentBlt(txDC(), imgX, imgY, img_w, img_h, pic[1].img);
   imgX = n;;
   imgY = imgY + img_h + imgRast;

   txTransparentBlt(txDC(), imgX, imgY, img_w, img_h, pic[2].img);
   imgX = imgX + img_w + imgRast;
   txTransparentBlt(txDC(), imgX, imgY, img_w, img_h, pic[3].img);
   imgX = n;;
   imgY = imgY + img_h + imgRast;
   

  
	txSelectFont("Arial", 16);	 

}
