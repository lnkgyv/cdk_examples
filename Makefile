CC = gcc

LIBNCURSES = -lncurses
LIBCDK = -lcdk

LIBRARIES = $(LIBNCURSES) $(LIBCDK)

all: calendar menu alphalist scrollinglist

calendar: calendar.c
	$(CC) -o calendar $< $(LIBRARIES)

menu: menu.c
	$(CC) -o menu $< $(LIBRARIES)

alphalist: alphalist.c
	$(CC) -o alphalist $< $(LIBRARIES)

scrollinglist: scrollinglist.c
	$(CC) -o scrollinglist $< $(LIBRARIES)

clean:
	rm -f calendar
	rm -f menu
	rm -f alphalist
	rm -f scrollinglist

.PHONY: clean calendar menu alphalist scrollinglist
