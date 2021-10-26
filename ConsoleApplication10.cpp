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

picter img_in_town[1000] = {0};
int img_in_town_kol = 0, nom_pic = -1;

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
	txDeleteDC(pic[0].img);
	txDeleteDC(pic[1].img);
	txDeleteDC(pic[2].img);
	txDeleteDC(pic[3].img);
	for (int i=0;i< img_in_town_kol; i++) txDeleteDC(img_in_town[i].img);
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
		while (GetAsyncKeyState(VK_LBUTTON))
		{
			;
		}
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

	// vyvod picter right
	for (int i = 0;i < img_in_town_kol;i++)
		{
		HDC save = txCreateCompatibleDC(200, 200);
		txTransparentBlt(save, 0, 0, 200,200, img_in_town[i].img, 0, 0, TX_WHITE);
		if (img_in_town[i].Visible)
			//txTransparentBlt(txDC(), img_in_town[i].x, img_in_town[i].y, img_in_town[i].w, img_in_town[i].h, img_in_town[i].img);
		Win32::StretchBlt(txDC(), img_in_town[i].x, img_in_town[i].y, img_in_town[i].w, img_in_town[i].h,  save, 0, 0,
		200,200, SRCCOPY);
			//Win32::TransparentBlt(txDC(), img_in_town[i].x, img_in_town[i].y, img_in_town[i].w, img_in_town[i].h, img_in_town[i].img, img_in_town[i].x, img_in_town[i].y, img_in_town[i].w, img_in_town[i].h, RGB(255, 255, 255));
		txDeleteDC(save);
		}

	// vyvod picter left
	for (int i=0;i<4;i++)
	{
		HDC save = txCreateCompatibleDC(200, 200);
		txBitBlt(save, 0, 0, 200, 200, pic[i].img);
		Win32::StretchBlt(txDC(), imgX, imgY, img_w, img_h, save, 0, 0,	200, 200, SRCCOPY);
		//Win32::TransparentBlt(txDC(), img_in_town[i].x, img_in_town[i].y, img_in_town[i].w, img_in_town[i].h, img_in_town[i].img, img_in_town[i].x, img_in_town[i].y, img_in_town[i].w, img_in_town[i].h, RGB(255, 255, 255));
		txDeleteDC(save);
	// txTransparentBlt(txDC(), imgX, imgY, img_w, img_h, pic[i].img);
	 // click on picter left
	 if (txMouseX() > imgX && txMouseY() > imgY && txMouseX() < imgX + img_w && txMouseY() < imgY + img_h && txMouseButtons() == 1)
		{
			 nom_pic = i;
	     
		}
     if (i%2==0)   imgX = imgX + img_w + imgRast;
     else {
		     imgX = n;;
		     imgY = imgY + img_h + imgRast;
		 }
	
	}
	// draw picter right
   if (txMouseX() > x + img_w + img_w + imgRast + 5 && txMouseButtons() == 1 && nom_pic != -1)
   {
	   int x_begin = txMouseX();
	   int y_begin = txMouseY();
	   int x_end = txMouseX();
	   int y_end = txMouseY();
	   while (GetAsyncKeyState(VK_LBUTTON))
	   {
		   x_end = txMouseX();
		   y_end = txMouseY();
		   txSetFillColor(TX_GRAY);
		   txSetColor(TX_GRAY, 1);

		   txRectangle(x_begin, y_begin, x_end, y_end);

		   txSleep(100);
	   }
	   // add new picter right
	   img_in_town[img_in_town_kol].img = pic[nom_pic].img;

	   img_in_town[img_in_town_kol].w = x_end - x_begin;
	   img_in_town[img_in_town_kol].h = y_end - y_begin;
	   img_in_town[img_in_town_kol].Visible = TRUE;
	   img_in_town[img_in_town_kol].x = x_begin;
	   img_in_town[img_in_town_kol].y = y_begin;
	   img_in_town_kol++;
	   nom_pic = -1;

	  

   }

   //  ОТМЕНА
   if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
   
	   //txMessageBox("Отмена");
	   if (img_in_town_kol>0)
	   {
	   img_in_town_kol--;
	   img_in_town[img_in_town_kol].Visible = FALSE;
	   txSleep(100);
	   }
	   else  txMessageBox("Действий нет");
   if (GetAsyncKeyState(VK_SHIFT))
   {
	   //txMessageBox("Отмена");
	   if (img_in_town[img_in_town_kol].w != 0) {
		   
		   img_in_town[img_in_town_kol].Visible = TRUE;
		   img_in_town_kol++;
		   txSleep(100);
	   }
	   else  txMessageBox("Действий нет");
   }
   
   txSelectFont("Arial", 16);
  

}
