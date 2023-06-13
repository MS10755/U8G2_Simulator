#include "common.h"	//页面公共头文件

PAGE_DECLARE(template) //声明当前.cpp文件 为一个页面文件，页面名称为 "template"

/* 页面创建函数，创建该页面时自动调用 */
static void* create(void* parms) {

	return NULL;
}

/* 页面主循环，当处于当前页面时无限调用 */
static void* loop(void* parms) {
	return NULL;
}

/* 页面销毁函数，推出该页面时自动调用，释放当前页面使用的动态资源 */
static void* destory(void* parms) {

	return NULL;
}

/* 按键回调，切换到当前页面会自动连接该函数 */
static void key_callback(uint8_t key, uint8_t event) {

}