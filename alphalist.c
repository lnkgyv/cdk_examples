#include "alphalist.h"

/* Alphalist List example using Ncurses/CDK  */

int show_alphalist() {
	CDKSCREEN *cdkscreen;
	CDKALPHALIST *CDKType;
	WINDOW *screen;
	char *type;
	char *types[4];
	char temp[256], *mesg[10];
	
	screen = initscr();
	cdkscreen = initCDKScreen(screen);
	initCDKColor();


	types[0] = "CD";
	types[1] = "DVD";
	types[2] = "Floppy";
	types[3] = "ZIP";

	CDKType = newCDKAlphalist(cdkscreen, 
		CENTER, CENTER, 
		8, 10,
		"", "", types, 4,
		'_', A_REVERSE,
		TRUE, FALSE);

	type = activateCDKAlphalist(CDKType, 0);
	
	if (CDKType->exitType == vNORMAL)
	{
	  sprintf (temp, "(%s)", type);
	  mesg[0] = temp;
	  popupLabel (cdkscreen, mesg, 1);
	}

	destroyCDKEntry(CDKType);
	destroyCDKScreen(cdkscreen);
	endCDK();
	
	return 0;
}

int main(int argc, char *argv[])
{
	show_alphalist();

	return 0;
}
