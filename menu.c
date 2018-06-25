#include "menu.h"

/* Item List example using Ncurses/CDK  */

int show_menu() {
	CDKSCREEN *cdkscreen;
	CDKITEMLIST *itemlist;
	WINDOW *screen;
	int val;
	char *types[4];
	char temp[256], *mesg[10];
	
	screen = initscr();
	cdkscreen = initCDKScreen(screen);
	initCDKColor();

	types[0] = "CD";
	types[1] = "DVD";
	types[2] = "Floppy";
	types[3] = "ZIP";

	itemlist = newCDKItemlist(cdkscreen, 
		CENTER, CENTER, 
		"", "Media: ", types, 4, 0,
		TRUE, FALSE);

	val = activateCDKItemlist(itemlist, 0);

	if (itemlist->exitType == vNORMAL)
	{
	  sprintf (temp, "(%s)", types[val]);
	  mesg[0] = temp;
	  popupLabel (cdkscreen, mesg, 1);
	}
	
	destroyCDKItemlist(itemlist);
	destroyCDKScreen(cdkscreen);
	endCDK();
	
	return 0;
}

int main(int argc, char *argv[])
{
	show_menu();

	return 0;
}
