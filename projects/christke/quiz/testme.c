#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
// #include<math.h>

// inputChar parameters
#define CSPAN     128         // Only Standard ASCII characters
#define COFFSET   0

// inputString parameters
#define STRLEN    6
#define SSPAN1    26
#define SSPAN2    2
#define SOFFSET1  97
#define SOFFSET2  0

char inputChar()
{
    return (char)(rand()%(int)CSPAN+(int)COFFSET);
}

char *inputString()
{
    static char str[STRLEN];

    for(int i = 0; i < STRLEN-1; i++)
      str[i] = (char)(rand()%SSPAN1+SOFFSET1);      // Only lowercase letters
    str[STRLEN-1] = (char)(rand()%SSPAN2+SOFFSET2); // Only control characters
    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;

  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
