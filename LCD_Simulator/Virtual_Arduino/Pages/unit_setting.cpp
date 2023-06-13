#include "unit_setting.h"

void Unity_setting::set_items(initializer_list<setting_item_t> items) {
	const setting_item_t* item =  items.begin();
	for (uint8_t i = 0; i < UNITY_SETTING_MAX_ITEM && i< items.size(); i++) {
		memcpy(&item_list[i],item,sizeof(item_list[i]));
		item++;
	}
}

Unity_setting settings;