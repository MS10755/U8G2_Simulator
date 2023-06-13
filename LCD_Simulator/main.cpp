/*

  HelloWorld.ino

  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list
    of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice, this
    list of conditions and the following disclaimer in the documentation and/or other
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include <Arduino.h>
#include "Juan_EventButton.h"
#include "MillisTaskManager.h"
#include "common.h"
#include "manage.h"
MillisTaskManager TaskManager;
static uint8_t now_page;

U8G2_SDL_128X64 u8g2(U8G2_R0);

#include "SDL.h"

Juan_EventButton_t* button1,* button2,* button3,* button4;
extern uint8_t select_index;
void button_callback(void * btn,ButtonEvent_t _event) {
    if (btn == button1 && _event == BUTTON_EVENT_PRESSED) {
        Serial.println("key1 clicked!");
        pagemanager.KeyCallback(1, BUTTON_EVENT_PRESSED);
    }
    if (btn == button2 && _event == BUTTON_EVENT_PRESSED) {
        Serial.println("key2 clicked!");
        pagemanager.KeyCallback(2, BUTTON_EVENT_PRESSED);
    }
    if (btn == button3 && _event == BUTTON_EVENT_PRESSED) {
        Serial.println("key3 clicked!");
        pagemanager.KeyCallback(3, BUTTON_EVENT_PRESSED);
    }
    if (btn == button4 && _event == BUTTON_EVENT_PRESSED) {
        Serial.println("key4 clicked!");
        pagemanager.KeyCallback(4, BUTTON_EVENT_PRESSED);
    }
}

void setup(void) {
    u8g2.begin();
    button1 = Juan_EventButtonCreate(0,300,1000,1000);
    button2 = Juan_EventButtonCreate(0, 300, 1000, 1000);
    button3 = Juan_EventButtonCreate(0, 300, 1000, 1000);
    button4 = Juan_EventButtonCreate(0, 300, 1000, 1000);
    Juan_AddEventHandler(button1, button_callback);
    Juan_AddEventHandler(button2, button_callback);
    Juan_AddEventHandler(button3, button_callback);
    Juan_AddEventHandler(button4, button_callback);
    PAGE_REGISTER(main);
    PAGE_REGISTER(menu);
    PAGE_REGISTER(about);
    PAGE_REGISTER(settings);
    pagemanager.SwitchTo("main");
}

void loop(void) {
    pagemanager.Loop();
    TaskManager.Running(millis());
    /* SDL 按键只能检测单次按下，无法检测持续性按下 */
    switch (u8g_sdl_get_key())
    {
    case 'a':
        Juan_EventMonitor(button1,1);
        break;
    case 's':
        Juan_EventMonitor(button2, 1);
        break;
    case 'd':
        Juan_EventMonitor(button3, 1);
        break;
    case 'f':
        Juan_EventMonitor(button4, 1);
        break;
    default:
        Juan_EventMonitor(button1, 0);
        Juan_EventMonitor(button2, 0);
        Juan_EventMonitor(button3, 0);
        Juan_EventMonitor(button4, 0);
        break;
    }
}
