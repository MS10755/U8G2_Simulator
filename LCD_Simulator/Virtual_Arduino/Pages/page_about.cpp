#include "common.h"

PAGE_DECLARE(about)


static void* create(void* parms) {

	return NULL;
}

static void* loop(void* parms) {
	u8g2.setFont(u8g2_font_5x7_tf);
	u8g2.clearBuffer();
	u8g2.setDrawColor(1);
	u8g2.setCursor(0, u8g2.getMaxCharHeight());
	u8g2.drawStr(0, u8g2.getMaxCharHeight(), "About:");
	u8g2.drawStr(0, 2 * u8g2.getMaxCharHeight(), "System_ver:1.0");
	u8g2.drawStr(0, 3 * u8g2.getMaxCharHeight(), "GUI by U8G2");
	u8g2.drawStr(0, 4 * u8g2.getMaxCharHeight(), "Open source list:");
	keyBar.setText({ "","Down","Up","Return" });
	keyBar.show();
	u8g2.sendBuffer();
	return NULL;
}

static void* destory(void* parms) {

	return NULL;
}

static void key_callback(uint8_t key, uint8_t event) {
	if (key == 4 && event == BUTTON_EVENT_PRESSED) {
		pagemanager.SwitchTo("menu");
		
	}
	if (event == BUTTON_EVENT_PRESSED && key != 1 ) {
		keyBar.mask(key-1);
	}
}