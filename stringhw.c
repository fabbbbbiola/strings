#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "my_headers.h"

int mystrlen(char *c){
  int len = 0;
  while(*c){
    len++;
    c++;
  }
  return len;
}


char * mystrncat(char *dest, char *source, int c){
  char *destEnd = dest + mystrlen(dest);
  while(c--){
    *destEnd = *source;
    destEnd++;
    source++;
  }
  return dest;
}

char * mystrchr(char *s, char c){
  while(*s++){
    if(*s == c)
      return s;
  }
  return NULL;
}


int main(){

  char s[15] = "hello";
  char d[30];
  char r[] = "life";
  printf("testing strlen\n");
  printf("[mine] length of \"%s\": %d\n", s, mystrlen(s));
  printf("[standard] length of \"%s\": %lu\n\n", s, strlen(s));
  printf("[mine] length of \"%s\": %d\n", d, mystrlen(d));
  printf("[standard] length of \"%s\": %lu\n\n", d, strlen(d));
  printf("[mine] length of \"%s\": %d\n", r, mystrlen(r));
  printf("[standard] length of \"%s\": %lu\n\n", r, strlen(r));

  char str1[] = "hello";
  char str2[40];
  notstrcpy(str2, str1);
  printf("testing strcpy:\n");
  printf("source: %s\n",str1);
  printf("copied dest: %s\n\n", str2);

  printf("testing strncat\n");
  char mysrc[50], mydest[50];
  strcpy(mysrc,  "This is source");
  strcpy(mydest, "This is destination");
  mystrncat(mydest, mysrc, 15);
  printf("[Mine] Final destination string : |%s|\n", mydest);
  
  char src[50], dest[50];
  strcpy(src,  "This is source");
  strcpy(dest, "This is destination");
  strncat(dest, src, 15);
  printf("[Standard] Final destination string : |%s|\n\n", dest);

  char bob[] = "hair";
  char steve[] = "HAiR";
  printf("testing strcmp:\n");
  printf("strcmp |%s| & |%s|: ", bob, steve);
  notstrcmp(bob, steve);
  char alex[] = "string cheese";
  char harry[] = "cheese";
  printf("strcmp |%s| & |%s|: ", alex, harry);
  notstrcmp(alex, harry);
  char gilbert[] = "ostrich";
  char gunther[] = "an emu is an emo ostrich";
  printf("strcmp |%s| & |%s|: ", gilbert, gunther);
  notstrcmp(gilbert, gunther);
  
  char str[] = "http://www.tutorialspoint.com";
  char ch = '.';

  printf("\ntesting strchr\n");
  printf("[mine] String after |%c| is - |%s|\n", ch, mystrchr(str, ch));
  printf("[standard] String after |%c| is - |%s|\n", ch, strchr(str, ch));

  return 0;
}
