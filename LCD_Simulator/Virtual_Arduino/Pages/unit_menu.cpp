#include "common.h"
void Unity_menu::set_items(initializer_list<menu_item_t> items) {
	memset(item_list,0,sizeof(item_list));
	const menu_item_t* item = items.begin();
	for (uint8_t i = 0; i < UNITY_MENU_MAX_ITEM && i < items.size();i++) {
		memcpy(&item_list[i],item,sizeof(item_list[i]));
		item++;
	}
}

uint8_t Unity_menu::size() {
	uint8_t _size = 0;
	for (uint8_t i = 0; i < UNITY_MENU_MAX_ITEM; i++) {
		if (item_list[i].title!=NULL) {
			_size++;
		}
	}
	return _size;
}

void Unity_menu::cursor_up() {
	if (select_index > 0) {
		select_index--;
	}
	else {
		select_index = size() - 1;
	}
}
void Unity_menu::cursor_down() {
	if (select_index < size() - 1) {
		select_index++;
	}
	else {
		select_index = 0;
	}
}
uint8_t Unity_menu::cursor_pos() {
	return select_index;
}

void Unity_menu::redraw() {
	if (size() == 0) return;
	u8g2.clearBuffer();
	keyBar.show();
	u8g2.setFont(u8g2_font_5x7_tf);
	uint8_t box_height = 2 * item_pad_piexs + u8g2.getMaxCharHeight();
	uint8_t maxItemNumOneScreen = (u8g2.getHeight() - keyBar.getHeight()) / box_height;
	static uint8_t first_item = 0;
	static uint8_t end_item = min(size() - 1, maxItemNumOneScreen - 1);
	if (select_index > end_item) {
		first_item++;
		end_item++;
	}
	else if (select_index < first_item) {
		first_item--;
		end_item--;
	}
	for (uint8_t i = first_item; i <= end_item; i++) {
		uint8_t j = i - first_item;
		if (i == select_index) {
			u8g2.setDrawColor(1);
			u8g2.drawBox(0, j * box_height, u8g2.getWidth(), box_height);
			u8g2.setDrawColor(0);
		}
		else {
			u8g2.setDrawColor(1);
		}
		if (item_list[i].title) {
			u8g2.drawStr(0, (2 * j + 1) * item_pad_piexs + (j + 1) * u8g2.getMaxCharHeight(), item_list[i].title);
		}
	}
	u8g2.sendBuffer();
}

Unity_menu menu;