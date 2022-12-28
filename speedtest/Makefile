CC = gcc
LD = gcc
CFLAGS = -Wall -c -O3 
LDFLAGS = -Wall -O3

all: speedtest.elf

speedtest.elf: main.o aes.o timer.o
	$(LD) $(LDFLAGS) -o $@ $^

main.o : main.c ../aes.h aes.o
	$(CC) $(CFLAGS) -o  $@ $<

aes.o : ../aes.c ../aes.h
	$(CC) $(CFLAGS) -o $@ $<

timer.o : ../timer/cycletimer.c ../timer/cycletimer.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -rf *.o *.elf