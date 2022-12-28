#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdint.h>
#include <string.h>

#define ECB 1

#include "../aes.h"
#include "../timer/cycletimer.h"

uint8_t * getRandomPlain(uint32_t length)
{
  uint8_t *plain = (uint8_t*)malloc(length * sizeof(uint8_t));
  for (uint32_t i = 0; i < length; i++) {
    plain[i] = rand() % 256;
  }

  return plain;
}

int main()
{
  const uint32_t MEGABYTE = 1024 * 1024 * sizeof(uint8_t);

  uint32_t megabytesCount = 100;
  uint32_t plainLength = megabytesCount * MEGABYTE;
  // uint8_t key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
  uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
  uint8_t in[]  = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a };
  uint8_t out[] = { 0x3a, 0xd7, 0x7b, 0xb4, 0x0d, 0x7a, 0x36, 0x60, 0xa8, 0x9e, 0xca, 0xf3, 0x24, 0x66, 0xef, 0x97 };

  printf("Start speedtest\n");
  srand(time(NULL));

  uint8_t *plain = getRandomPlain(plainLength);

  struct AES_ctx ctx;
  AES_init_ctx(&ctx, key);

  double startTime = currentSeconds();
  AES_ECB_encrypt(&ctx, in);
  double endTime = currentSeconds();

  double delta = endTime - startTime;
  printf("AES_ECB_encrypt: %f ms\n", delta * 1000);

  double speed = (double)megabytesCount / (delta * 1000) * 1000;
  // double speed = (double)16 / delta * MICROSECONDS;

  printf("%.2f Mb/s\n", speed);

  if (0 == memcmp((char*) out, (char*) in, 16)) {
    printf("SUCCESS!\n");
  } else {
    printf("FAILURE!\n");
  }

  free(plain);
  // delete[] plain;
//   delete[] out;

  return 0;
}