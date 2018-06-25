#include "calendar.h"

/* Calendar example using Ncurses/CDK  */

int show_calendar() {
	CDKSCREEN *cdkscreen;
	CDKCALENDAR *calendar;
	WINDOW   *screen;
	time_t date;
	char *month[13];
	char  temp[256], *mesg[4];
	time_t current_time;
	struct tm *current_date;

	screen = initscr();
	cdkscreen = initCDKScreen(screen);
	initCDKColor();

	current_time = time(NULL);
	if (current_time == -1) {
		fprintf(stderr, "Can't get the current time.\n");

		return -1;
	}
	//printf("Current timestamp: %lu\n", current_time);
	current_date = malloc(sizeof(struct tm));
	current_date = localtime(&current_time);
	//printf("Current year: %d\n", current_date->tm_year);

	calendar = newCDKCalendar(cdkscreen, CENTER, CENTER, "Select date: ", 
	current_date->tm_mday,
	current_date->tm_mon + 1,
	current_date->tm_year + 1900,
	COLOR_PAIR(16)|A_BOLD, COLOR_PAIR(16)|A_BOLD, COLOR_PAIR(16)|A_BOLD,
	A_REVERSE, TRUE, FALSE);

	drawCDKCalendar(calendar, TRUE);
	
	date = activateCDKCalendar(calendar, 0);

	if (calendar->exitType == vNORMAL)
	{
	    sprintf (temp, "Selected date: %02d.%02d.%d", 
		calendar->day, calendar->month, calendar->year);
	mesg[0] = temp;
	    popupLabel (cdkscreen, mesg, 1);
	}

	destroyCDKCalendar(calendar);
	destroyCDKScreen(cdkscreen);
	endCDK();

	return 0;
}

int main(int argc, char *argv[])
{
	return show_calendar();	
}
