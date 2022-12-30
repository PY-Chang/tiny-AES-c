CC = clang
LD = clang
CFLAGS = -Wall -c -Ofast -fopenmp #-g
LDFLAGS = -Wall -Ofast -fopenmp #-g

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