#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

void str2spongebobcase(char *toConvert){
  srand(time(NULL));
  int counter = 0;
  for(int i = 0; i < strlen(toConvert); i++){
    if(rand() % 8 <= 5){
      if(counter == 2){
        counter = 0;
        continue;
      }
      counter++;
      char c = toConvert[i];
      toConvert[i] = c >= 97 && c <= 122 ? toupper(c) : (c >= 65 && c <= 90 ? tolower(c) : c);
    }
  }
}

int main(int argc, char ** const argv){
  if(argc < 2){
    fprintf(stderr, "Usage: %s [strin1] [string2] ...", argv[0]);
    exit(0);
  }

  for(int i = 1; i < argc; i++){
    printf("%s: ", argv[i]);
    str2spongebobcase(argv[i]);
    printf("%s\n", argv[i]);
  }
}
