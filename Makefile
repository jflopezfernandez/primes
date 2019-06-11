
vpath %.c src
vpath %.h include

CP       = cp -f -u
RM       = rm -f

OBJS     = main.o

CC       = gcc
CFLAGS   = -std=c17 -Wall -Wextra -Wpedantic -O3 -mtune=intel -march=skylake
CPPFLAGS = -D_POSIX_C_SOURCE -D_GNU_SOURCE
LDFLAGS  = -lm -lgmp -lmpfr

TARGET   = primes

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I include -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I include -c -o $@ $^

.PHONY: clean
clean:
	$(RM) ./*.{o,asm,lst} $(TARGET)

.PHONY: install
install: $(TARGET)
	$(CP) ./$(TARGET) /usr/bin/$(TARGET)

.PHONY: uninstall
uninstall:
	$(RM) /usr/bin/$(TARGET)

