#include <Arduino.h>
#include "common.h"
#include <time.h>


PAGE_DECLARE(main)


static int a;
static void ui_loop() {
    u8g2.clearBuffer();					// clear the internal memory
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_5x7_tf);	// choose a suitable font
    u8g2.drawFrame(u8g2.getWidth() - 20, 0, 15, 10);
    u8g2.drawBox(u8g2.getWidth() - 5, 3, 2, 4);
    u8g2.drawBox(u8g2.getWidth() - 18, 2, 7, 6);
    u8g2.setFont(u8g2_font_5x7_tf);
    //u8g2.drawStr(u8g2.getWidth()-38,8,"64%");

    //SYSTEMTIME stCurTime;		// 当前时间
    //GetLocalTime(&stCurTime); // 获取当前时间
    time_t now;
    time(&now);
    struct tm* t = localtime(&now);
    char buf[20];
    snprintf(buf, sizeof(buf), "%d/%d/%d %02d:%02d:%02d", t->tm_year - 100, t->tm_mon, t->tm_wday, t->tm_hour, t->tm_min, t->tm_sec);
    u8g2.drawStr(20, 8, buf);
    u8g2.drawHLine(0, 12, u8g2.getWidth());
    u8g2.setFont(u8g2_font_10x20_mf);

    snprintf(buf, sizeof(buf), "T: %.2f", 20 + (rand() % 100) / 100.0f);
    u8g2.drawStr(20, 30, buf);
    snprintf(buf, sizeof(buf), "H: %d %%", 50 + rand() % 10);
    u8g2.drawStr(20, 50, buf);

    snprintf(buf, sizeof(buf), "D:%08d", a++);
    if (a % 2 == 0) {
        u8g2.drawStr(120, 50, "R");
    }
    keyBar.show();
    u8g2.sendBuffer();					// transfer internal memory to the display
    Serial.println("main ui_loop");
}
static void* create(void *parms) {
    TaskManager.Register(ui_loop,1000);
    Serial.println("create main page");
    keyBar.setText({"Menu","New","","Shut"});
    return NULL;
}

static void* loop(void* parms) {
    return NULL;
}

static void* destory(void* parms) {
    TaskManager.Logout(ui_loop);
    Serial.println("destory main page");
    return NULL;
}

static void key_callback(uint8_t key,uint8_t event) {
    if (key == 1 && event == BUTTON_EVENT_PRESSED) {
        pagemanager.SwitchTo("menu");
        keyBar.mask(0);
    }
    else if (key == 2 && event == BUTTON_EVENT_PRESSED) {
        keyBar.mask(1);
    }
    else if (key == 4 && event == BUTTON_EVENT_PRESSED) {
        keyBar.mask(3,1000);
        //exit(0);//关机
    }
}