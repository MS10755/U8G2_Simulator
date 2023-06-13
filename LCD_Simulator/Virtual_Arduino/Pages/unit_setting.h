#ifndef __UNIT_SETTING_H__
#define __UNIT_SETTING_H__

#include <initializer_list>
#include <stdint.h>
#include <string.h>
using namespace std;
typedef enum {
	SETTING_ITEM_TYPE_INT,
	SETTING_ITEM_TYPE_FLOAT,
	SETTING_ITEM_TYPE_ENUM,
}setting_item_type_t;

typedef struct {
	const char* text;
	int val;
	int min;
	int max;
	int step;
}setting_item_int_t;

typedef struct {
	const char* text;
	float val;
	float min;
	float max;
	float step;
}setting_item_float_t;

typedef struct {
	const char* text;
	struct
	{
		const char* val_text;//显示在UI上的文本
		int val;//程序中采用的值
	}val_map;
}setting_item_enum_t;

typedef struct {
	setting_item_type_t type;
	void* item;
}setting_item_t;

#define UNITY_SETTING_MAX_ITEM	32

class Unity_setting {
public:
	void set_items(initializer_list<setting_item_t> items);
private:
	setting_item_t item_list[UNITY_SETTING_MAX_ITEM];
	uint8_t select_index;
};


extern Unity_setting settings;

#endif
