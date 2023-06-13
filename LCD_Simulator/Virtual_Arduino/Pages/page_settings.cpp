#include "common.h"	//ҳ�湫��ͷ�ļ�
#include "unit_setting.h"
PAGE_DECLARE(settings) //������ǰ.cpp�ļ� Ϊһ��ҳ���ļ���ҳ������Ϊ "template"

/* ҳ�洴��������������ҳ��ʱ�Զ����� */
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

/* ҳ����ѭ���������ڵ�ǰҳ��ʱ���޵��� */
static void* loop(void* parms) {
	menu.redraw();
	return NULL;
}

/* ҳ�����ٺ������Ƴ���ҳ��ʱ�Զ����ã��ͷŵ�ǰҳ��ʹ�õĶ�̬��Դ */
static void* destory(void* parms) {

	return NULL;
}

/* �����ص����л�����ǰҳ����Զ����Ӹú��� */
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