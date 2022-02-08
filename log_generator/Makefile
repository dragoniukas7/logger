OBJS := log_writer.o
PREFIX := /usr
BIN := log_writer
CFLAGS := -Wall
CPPFLAGS := -I$(shell pwd)/../logger/lib -L$(shell pwd)/../logger/lib -llogger -lsqlite3

.PHONY: clean all install uninstall

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(CPPFLAGS)
	
install:
	install -d $(DESTDIR)/$(PREFIX)/bin
	install -m 555 $(BIN) $(DESTDIR)/$(PREFIX)/bin

uninstall:
	$(RM) $(DESTDIR)/$(PREFIX)/bin/$(BIN)

clean:
	$(RM) $(BIN) $(OBJS)
