#include "scrollinglist.h"

/* Scrolling List example using Ncurses/CDK  */

int show_scrollinglist() {

	CDKSCREEN *cdkscreen;
	CDKSCROLL *CDKScroll;
	WINDOW *screen;
	int id_type;
	char *types[4];
	char temp[256], *mesg[10];
	
	screen = initscr();
	cdkscreen = initCDKScreen(screen);
	initCDKColor();

	types[0] = "CD";
	types[1] = "DVD";
	types[2] = "Floppy";
	types[3] = "ZIP";

	CDKScroll = newCDKScroll(cdkscreen, 
		CENTER, CENTER, RIGHT,
		8, 20,
		"Media:", types, 4,
		TRUE, A_REVERSE,
		TRUE, FALSE);
		
	setCDKScrollPosition(CDKScroll, 2);
	insertCDKScrollItem(CDKScroll, "Flash");
	
	id_type = activateCDKScroll(CDKScroll, 0);
	
	if (CDKScroll->exitType == vNORMAL)
	{
	    sprintf (temp, "(%s)", chtype2Char(CDKScroll->item[id_type]));
	mesg[0] = temp;
	    popupLabel (cdkscreen, mesg, 1);
	}

	destroyCDKScroll(CDKScroll);
	destroyCDKScreen(cdkscreen);
	endCDK();

	return 0;
}

int main(int argc, char *argv[])
{
	show_scrollinglist();

	return 0;
}
