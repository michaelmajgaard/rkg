#include "arg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void print_help() {
  printf("usage:\n"
         "  rkg -k <key-length> [-n]\n\n"
         "options:\n"
         "  -k --key-length {>8} Key length in characters.\n"
         "  -n                   Omit trailing newline in output.\n");
}

char *genkey(int key_length) {
  int length = key_length;
  char *buffer = (char *)malloc((length + 1) * sizeof(char));
  for (int i = 0; i < length; ++i) {
    buffer[i] = 126 - rand() % 93;
  }
  buffer[length] = '\0';
  return buffer;
}

int main(int argc, char *argv[]) {
  char *k, *key;
  if (parse_optv(argc, argv, "-k", "--key-length", &k)) {
    int key_length = atoi(k);
    if (key_length > 7) {
      srand(time(0));
      key = genkey(key_length);
      printf("%s", key);
      if (!parse_opt(argc, argv, "-n", "")) {
        printf("\n");
      }
      free(key);
      return 0;
    }
  }
  print_help();
  return -1;
}
