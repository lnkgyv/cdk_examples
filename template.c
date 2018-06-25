#include "template.h"

int show_template() {
	CDKSCREEN *cdkscreen;
	CDKTEMPLATE *CDKDate;
	WINDOW *screen;
	char *mesg[10], temp[256];
	struct tm *tm;

	tm = malloc(sizeof(struct tm));
	memset(tm, 0, sizeof(struct tm));

	screen = initscr();
	cdkscreen = initCDKScreen(screen);
	initCDKColor();

	CDKDate = newCDKTemplate(cdkscreen,
			CENTER,
			CENTER,
			"Set Date:",
			"",
			"##.##.#### ##:##",
			"DD.MM.YYYY HH:MM",
			FALSE,
			FALSE
	);

	refreshCDKScreen(cdkscreen);

	activateCDKTemplate(CDKDate, 0);

	if (CDKDate->exitType == vNORMAL)
	{
		if (mixCDKTemplate(CDKDate) == NULL) {
			destroyCDKEntry(CDKDate);
			destroyCDKScreen(cdkscreen);
			endCDK();

			return 0;
		}

		if (strptime(mixCDKTemplate(CDKDate), "%d.%m.%Y %H:%M", tm) == NULL) {
			strcpy(temp, "Date is incorrect !!!");
		} else {
			strftime(temp, sizeof(temp), "%d.%m.%Y %H:%M", tm);
		}

		mesg[0] = temp;
		popupLabel (cdkscreen, mesg, 1);
	}

	destroyCDKEntry(CDKDate);
	destroyCDKScreen(cdkscreen);
	endCDK();

	return 0;
}

int main(int argc, char *argv[])
{
	show_template();

	return 0;
}
