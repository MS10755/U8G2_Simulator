#include "common.h"	//页面公共头文件
#include "unit_setting.h"
PAGE_DECLARE(settings) //声明当前.cpp文件 为一个页面文件，页面名称为 "template"

/* 页面创建函数，创建该页面时自动调用 */
static void* create(void* parms) {
	u8g2.clear();
	menu.set_items({ {"time",NULL},{"upload",NULL}});
	setting_item_t item1;
	setting_item_int_t _item1;
	item1.type = SETTING_ITEM_TYPE_INT;
	item1.item = &_item1;
	_item1.val = 1970;
	_item1.text = "Year";
	settings.set_items({ item1 });
	return NULL;
}

/* 页面主循环，当处于当前页面时无限调用 */
static void* loop(void* parms) {
	menu.redraw();
	return NULL;
}

/* 页面销毁函数，推出该页面时自动调用，释放当前页面使用的动态资源 */
static void* destory(void* parms) {

	return NULL;
}

/* 按键回调，切换到当前页面会自动连接该函数 */
static void key_callback(uint8_t key, uint8_t event) {
	if (key == 2 && event == BUTTON_EVENT_PRESSED) {
		menu.cursor_down();
	keyBar.mask(1);
	}else if (key == 3 && event == BUTTON_EVENT_PRESSED) {
		menu.cursor_up();
		keyBar.mask(2);
	}else if (key == 4 && event == BUTTON_EVENT_PRESSED) {
		keyBar.mask(3);
		pagemanager.SwitchTo("menu");
	}
	else if (key == 1 && event == BUTTON_EVENT_PRESSED) {
		switch (menu.cursor_pos())
		{
		case 0:
			pagemanager.SwitchTo("page_settings_time");
			break;
		case 1:
			break;
		default:
			break;
		}
		keyBar.mask(0);
	}
}