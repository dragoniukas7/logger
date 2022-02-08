CFLAGS:=-Wall -fpic -shared
LIB := liblogger.so
OBJS := logger.o
PREFIX := /usr
CPPFLAGS := -I$(shell pwd)/../lib -L$(shell pwd)/../lib -llogger -lsqlite3

.PHONY: clean all install uninstall

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(CFLAGS) -o $(LIB) $^ $(CPPFLAGS)

install:
	install -d $(DESTDIR)/$(PREFIX)/lib $(DESTDIR)/$(PREFIX)/include
	install -m 644 logger.h $(DESTDIR)/$(PREFIX)/include
	install -m 644 $(LIB) $(DESTDIR)/$(PREFIX)/lib

uninstall:
	$(RM) $(DESTDIR)/$(PREFIX)/lib/$(LIB)
	$(RM) $(DESTDIR)/$(PREFIX)/include/logger.h

clean:
	$(RM) $(LIB) $(OBJS)
