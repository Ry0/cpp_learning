#include <stdio.h>

int str_char(const char str[], char c){
  int len = 0;
  while( str[len] != '\0' ){
    if ( str[len] == c ) {
      return (len);
    }
    len++;
  }
  return (-1);
}

int main(void){
  char str[] = "Japan";
  char str2[] = "Netherlands";
  char str3[100];
  char searchchar;

  printf("position of p in '%s' = %d\n", str,
                                  str_char(str, 'p') ); 

  printf("position of e in '%s' = %d\n", str2,
                                  str_char(str2, 'e') );

  printf("input searchchar\n");
  searchchar = getchar();
  printf("input str\n");
  scanf("%s", str3);
  printf("position of %c in '%s' = %d\n", searchchar, str3,
                      str_char(str3, searchchar) );

  return 0;

}