#include "ybadge.h"
#include <stdlib.h>
void playMusic();
void wheelGame();
void rickBomb();

int main() {
  int defaultG = rand() % 100;
  int defaultB = rand() % 100;
  while (true)
  {
    //wait for input
    while(!(buttons_get(1) || buttons_get(2) || buttons_get(3)))
    {
      for (int i=0; i<=200; i++)
      {
        delay(1);
        if ((buttons_get(1) || buttons_get(2) || buttons_get(3)))
        {
          //override the for loop
          i = 1020;
        }
      }
      
      //lights
      for (int i=0; i<=20; i++)
      {
        defaultG++;
        defaultB++;

        if (defaultG > 100)
        {
          defaultG = 0;
        }
        if (defaultB > 100)
        {
          defaultB = 0;
        }

        leds_set_color(i, 0, defaultG, defaultB);
      }
    }

    //options menu yay
    if (switches_get(1) && switches_get(2))
    {
      playMusic();
    }
    else if (switches_get(1) && !switches_get(2))
    {
      rickBomb();
    }
    else if (!switches_get(1) && switches_get(2))
    {
      wheelGame();
    }
    else if (!switches_get(1) && !switches_get(2))
    {
      //do nothing
    }
  }
}
