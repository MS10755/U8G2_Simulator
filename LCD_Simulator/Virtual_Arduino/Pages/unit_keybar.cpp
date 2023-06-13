#include "common.h"

#define UNITY_KEYBAR_TEXT_INTERVAL	30
#define UNITY_KEYBAR_TEXT_PAD		2

void Unity_keybar::setText(uint8_t index, const char* text) {
	if (index >= UNITY_KEYBAR_TEXT_NUM) return;
	strcpy(_buf[index],text);
}

void Unity_keybar::setText(initializer_list<const char *> text) {
	const char* const * p_t;
	p_t = text.begin();
	for (uint8_t i = 0; i < UNITY_KEYBAR_TEXT_NUM && i< text.size(); i++) {
		strcpy(_buf[i], *p_t);
		p_t++;
	}
}

void Unity_keybar::setFont(const uint8_t* font) {
	_font = font;
}

uint8_t Unity_keybar::getHeight() {
	const uint8_t* last_font;
	last_font = u8g2.getFont();
	u8g2.setFont(_font);
	uint8_t h = (2 * UNITY_KEYBAR_TEXT_PAD + u8g2.getMaxCharHeight());
	u8g2.setFont(last_font);//获取完KeyBar 字体高度，要重新设置为之前的字体
	return h;
}


void Unity_keybar::show() {
	const uint8_t* last_font;
	last_font = u8g2.getFont();
	u8g2.setFont(_font);
	u8g2.setDrawColor(1);
	for (uint8_t i = 0; i < UNITY_KEYBAR_TEXT_NUM; i++) {
		u8g2.drawButtonUTF8(i * UNITY_KEYBAR_TEXT_INTERVAL, u8g2.getHeight()- 4, U8G2_BTN_BW0, 0, UNITY_KEYBAR_TEXT_PAD, UNITY_KEYBAR_TEXT_PAD, _buf[i]);
	}
	u8g2.setFont(last_font);
}

void Unity_keybar::mask(uint8_t index, uint16_t ms) {
	const uint8_t* last_font;
	last_font = u8g2.getFont();
	u8g2.setFont(_font);
	u8g2.setDrawColor(1);
	for (uint8_t i = 0; i < UNITY_KEYBAR_TEXT_NUM; i++) {
		uint8_t flags;
		if (i == index) {
			flags = U8G2_BTN_INV;
		}
		else {
			flags = U8G2_BTN_BW0;
		}
		u8g2.drawButtonUTF8(i * UNITY_KEYBAR_TEXT_INTERVAL, u8g2.getHeight() - 4, flags, 0, 2, 2, _buf[i]);
	}
	u8g2.setFont(last_font);
	u8g2.sendBuffer();
	delay(ms);
}

Unity_keybar keyBar;