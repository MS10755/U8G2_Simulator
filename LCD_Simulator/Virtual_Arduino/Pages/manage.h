#ifndef __MANAGE_H__
#define __MANAGE_H__
#include <stdint.h>
#include <string.h>

#define PAGEMAX	32

typedef void* (*page_create_fun_t)(void* parms);
typedef void* (*page_loop_fun_t)(void* parms);
typedef void* (*page_destory_fun_t)(void* parms);
typedef void  (*page_key_callback_t)(uint8_t key,uint8_t event);
enum
{
	ERROR_OK = 0,
	ERROR_PAGENOTEXIST = -100,
	ERROR_NAMEISNULL,
	ERROR_CREATEISNULL,
	ERROR_LOOPISNULL,
	ERROR_DESTORYISNULL,
	ERROR_PAGEFULL,
	ERROR_ALREADYREGISTED,
};

typedef struct {
	char name[16];
	page_create_fun_t create;
	page_create_fun_t loop;
	page_create_fun_t destory;
	page_key_callback_t	key_callback;
}Page_t;

class PageManager
{
public:
	PageManager() {
		memset(page_list,0,sizeof(page_list));
		now_page = NULL;
		page_num = 0;
	};
	~PageManager() {};
	int Register(Page_t * page);
	int Register(
		const char* name,
		page_create_fun_t create, 
		page_create_fun_t loop, 
		page_create_fun_t destory,
		page_key_callback_t	key_callback
	);
	int SwitchTo(uint8_t id);
	int SwitchTo(const char* name);
	void Loop(void);
	void KeyCallback(uint8_t key,uint8_t event);
private:
	int getPageId(const char * name);
	Page_t* getPage(char* name);
	Page_t* getPage(uint8_t id);
	Page_t *now_page;
	uint8_t page_num;
	Page_t page_list[PAGEMAX];
};




extern PageManager pagemanager;

#endif
