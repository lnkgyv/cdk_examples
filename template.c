#include "template.h"

int show_template() {
	CDKSCREEN *cdkscreen;
	CDKTEMPLATE *CDKPhone;
	WINDOW *screen;
	char *phone;

	screen = initscr();
	cdkscreen = initCDKScreen(screen);
	initCDKColor();

	CDKPhone = newCDKTemplate(cdkscreen, CENTER, CENTER,
		"", "Date: ", "##.##.#### ##:##","DD.MM.YYYY HH:MM",
		FALSE, FALSE);

	refreshCDKScreen(cdkscreen);

	phone = activateCDKTemplate(CDKPhone, 0);

	destroyCDKEntry(CDKPhone);
	destroyCDKScreen(cdkscreen);
	endCDK();

	return 0;
}

int main(int argc, char *argv[])
{
	show_template();

	return 0;
}
