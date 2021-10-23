 if (txMouseButtons() == 2)
   {
	   
	   img_in_town[img_in_town_kol].img = pic[0].img;
		   img_in_town[img_in_town_kol].x = 400;
		   img_in_town[img_in_town_kol].y = 400;
		   img_in_town[img_in_town_kol].w = img_w*2;
		   img_in_town[img_in_town_kol].h = img_h * 2;
		   img_in_town[img_in_town_kol].Visible = TRUE;
		   int i=img_in_town_kol;
		   img_in_town_kol++;
		   
		   if (img_in_town[i].Visible) txTransparentBlt(txDC(), img_in_town[i].x, img_in_town[i].y, img_in_town[i].w, img_in_town[i].h, img_in_town[i].img);;

		  // txSleep(100);
   }
  // if (txMouseX() > imgX  &&  txMouseY() > imgY && txMouseX() < imgX + img_w && txMouseY() < imgY + img_h && txMouseButtons() == 2)
  // {
	//   img_in_town[img_in_town_kol].Visible = FALSE;
 //  }
