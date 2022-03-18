#include <stdio.h>

static char a[] = {'H', 'e', 'l', 'l', 'o', '\0'};

void
print_strings (void) {
  char b[] = "Hello";

  a[1] = 'a'; /* Because the array is static, it's writable. */
  b[1] = 'a'; /* Because the array is auto, it's writable. */

  printf ("a = %s\n", a); /* Hallo */
  printf ("b = %s\n", b); /* Hallo */
}

int main(){
  printf("a = %s\n", a);
  print_strings();
  printf("a = %s\n", a);
  
  int i = 0;
  for (;i < 5; i++){
    char c = 65+i;
    printf ("%c", c);
  }
  printf ("%c", c);

  return 0;

}
