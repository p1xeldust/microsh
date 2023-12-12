CC          = gcc
CFLAGS      = -Ofast -DDEBUG -static
LDFLAGS     = -Ofast

ifeq ($(CC),)
CC          = gcc
endif

CSOURCES    = main.c execute.c parse_input.c
BIN         = microsh

COBJ        = $(CSOURCES:.c=.o)
all: $(COBJ)
	@echo "  CCLD  $(BIN)"
	@$(LD) $(LDFLAGS) -o $(BIN) $^ 
	
%.o: %.c
	@echo "  CC    $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	@rm -f $(COBJ) $(BIN)

install: all
	install -d ${DESTDIR}/usr/bin
	install -m 755 $(BIN) ${DESTDIR}/usr/bin
	install -m 755 scripts/pako-builder ${DESTDIR}/usr/bin