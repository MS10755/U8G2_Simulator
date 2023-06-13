#include "common.h"

PAGE_DECLARE(menu)


static void* create(void * parms) {
	Serial.println("create menu page");
	keyBar.setText({ "Ok","Next","Last","Return"});
	menu.set_items({ 
		{"Settings",NULL},
		{"About",NULL}
		});
	return NULL;
}

static void* loop(void* parms) {
	menu.redraw();
	return NULL;
}


static void* destory(void* parms) {


	return NULL;
}

static void key_callback(uint8_t key, uint8_t event) {
	if (key == 4 && event == BUTTON_EVENT_PRESSED) {
		keyBar.mask(3);
		pagemanager.SwitchTo("main");
	}
	else if (key == 2 && event == BUTTON_EVENT_PRESSED) {
		menu.cursor_down();
		keyBar.mask(1);
	}
	else if (key == 3 && event == BUTTON_EVENT_PRESSED) {
		menu.cursor_up();
		keyBar.mask(2);
	}
	else if (key == 1 && event == BUTTON_EVENT_PRESSED) {
		switch (menu.cursor_pos())
		{
		case 1:
			pagemanager.SwitchTo("about");
			break;
		case 0:
			pagemanager.SwitchTo("settings");
			break;
		default:
			break;
		}
		keyBar.mask(0);
	}
}