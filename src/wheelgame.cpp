#include "ybadge.h"

void wheelGame()
{
    //wait for button to release
    while(buttons_get(1) || buttons_get(2) || buttons_get(3) || switches_get(1) || switches_get(2))
    {
      delay(1);
      for (int i=0; i<=20; i++)
      {
        leds_set_color(i, 255, 0, 0);
      }
    }

    for (int i=0; i<=20; i++)
    {
      leds_set_color(i, 0, 0, 0);
    }

    //illuminate the winning pin
    leds_set_color(17, 0, 255, 255);

    //inital vars setup
    bool wheelSpinning = true;
    int wheelLed = 0;
    int wheelDelay = 50;

    //wait
    while (wheelSpinning)
    {
        leds_set_color(wheelLed, 0, 0, 0);
        wheelLed++;
        if (wheelLed > 20)
        {
            wheelLed = 0;
        }
        leds_set_color(wheelLed, 0, 191, 127);

        //illuminate the winning pin
        leds_set_color(17, 0, 255, 0);

        delay(wheelDelay);
        if (buttons_get(1) || buttons_get(2) || buttons_get(3))
        {
            wheelSpinning = false;
        }
    }

    //slow down the wheel
    for (int i=0; i<5; i++)
    {
        wheelDelay *= 2;
        leds_set_color(wheelLed, 0, 0, 0);
        wheelLed++;
        if (wheelLed > 20)
        {
            wheelLed = 0;
        }
        leds_set_color(wheelLed, 0, 191, 127);
        delay(wheelDelay);
    }
    
    if (wheelLed == 17)
    {
        //you won lol
        speaker_play_note(NOTE_F4, 200);
        delay(200);
        speaker_play_note(NOTE_F3, 400);
        delay(400);
        speaker_play_note(NOTE_F4, 200);
        delay(200);
        speaker_play_note(NOTE_F3, 400);
        delay(400);
        speaker_play_note(NOTE_F4, 200);
        delay(200);
        speaker_play_note(NOTE_F5, 200);
        delay(200);
        speaker_play_note(NOTE_F6, 400);
        delay(400);
    }
    else
    {
        //you lose you loser
        speaker_play_note(NOTE_F4, 200);
        delay(200);
        speaker_play_note(NOTE_F3, 300);
        delay(300);
        speaker_play_note(NOTE_F2, 400);
        delay(400);
        speaker_play_note(NOTE_B1, 500);
        delay(500);
    }

    //wait for button release (if we still need to)
    while(buttons_get(1) || buttons_get(2) || buttons_get(3))
    {
      delay(1);
    }

    for (int i=0; i<=20; i++)
    {
        leds_set_color(i, 0, 0, 0);
    }
}