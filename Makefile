CFLAGS	= -std=c99 -Wall -Wextra -O3 -I/usr/include/librsvg-2.0/ $(shell pkg-config --cflags glib-2.0) $(shell pkg-config --cflags librsvg-2.0)
LDFLAGS	= 
LIBS	= $(shell pkg-config --libs glib-2.0) $(shell pkg-config --libs librsvg-2.0)

svgdim: svgdim.c
	gcc $(CFLAGS) $(LDFLAGS) -o $@ $< $(LIBS)
