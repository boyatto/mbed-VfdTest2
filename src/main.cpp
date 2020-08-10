#include <mbed.h>
#include "vfd.h"
#include "keypad.h"

int main()
{

  // put your setup code here, to run once:
  int i;
  char key;
  char dispStr[7] = {0};
  char workBufStr[7] = {0};
  char lastKey[] = {0, 0, 0};
  int strLength;

  while (1)
  {
    // put your main code here, to run repeatedly:
    key = getKey();
    if (key != lastKey[0] && key != lastKey[1] && key != lastKey[2])
      thread_sleep_for(20);

    lastKey[2] = lastKey[1];
    lastKey[1] = lastKey[0];
    lastKey[0] = key;

    if (key != 0 && lastKey[1] != 0 && key != lastKey[2])
    {
      if (key == '#')
      {
        strcpy(dispStr, "");
      }
      else if (key == '*')
      {
        if (strlen(dispStr) == 6)
        {
          strcpy(workBufStr, dispStr);
          strcpy(dispStr, &workBufStr[1]);
        }
        strncat(dispStr, " ", 6);
      }
      else
      {
        if (strlen(dispStr) == 6)
        {
          strcpy(workBufStr, dispStr);
          strcpy(dispStr, &workBufStr[1]);
        }
        dispStr[strlen(dispStr) + 1] = 0;
        dispStr[strlen(dispStr)] = key;
      }
    }

    strLength = strlen(dispStr);
    for (i = 0; i <= strLength; i++)
    {
      SetNum(dispStr[i], (strLength - 1) - i);
    }
    off();
  }
}