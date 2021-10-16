// ConsoleApplication10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


{
	
	HDC img;
	COLORREF color= TX_NULL;
	




};
bool Button(int x, int y, int w, int h, const char *str);

int main()
{
	txCreateWindow(800, 600);
	
	while (!GetAsyncKeyState(VK_ESCAPE))
	{

		txBegin();
	Button(100, 100, 0, 0, "Одиночная игра");
	Button(100, 170, 0, 0, "Чемпионат");
	Button(100, 240, 0, 0, "Настройки");
	Button(100, 310, 0, 0, "О программе");
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
