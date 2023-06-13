#include "manage.h"
#include <string.h>
int PageManager::getPageId(const char* name) {
	for (uint8_t i = 0; i < page_num;i++) {
		if (strcmp(name,page_list[i].name)==0) {
			return i;
		}
	}
	return ERROR_PAGENOTEXIST;
}

int PageManager::Register(const char * name, page_create_fun_t create, page_create_fun_t loop, page_create_fun_t destory, page_key_callback_t key_callback) {
	if (page_num > PAGEMAX) {
		return ERROR_PAGEFULL;
	}
	if (name == NULL) {
		return ERROR_NAMEISNULL;
	}
	if (create == NULL) {
		return ERROR_CREATEISNULL;
	}
	if (loop == NULL) {
		return ERROR_LOOPISNULL;
	}
	if (destory == NULL) {
		return ERROR_DESTORYISNULL;
	}
	if (getPageId(name) != ERROR_PAGENOTEXIST) {
		return ERROR_ALREADYREGISTED;
	}
	strcpy(page_list[page_num].name,name);
	page_list[page_num].create = create;
	page_list[page_num].loop = loop;
	page_list[page_num].destory = destory;
	page_list[page_num].key_callback = key_callback;
	page_num++;
	return ERROR_OK;
}

int PageManager::Register(Page_t* page) {
	if (page_num > PAGEMAX) {
		return ERROR_PAGEFULL;
	}
	return Register(page->name, page->create, page->loop, page->destory, page->key_callback);
}
Page_t* PageManager::getPage(char* name) {
	uint8_t id = getPageId(name);
	if (id == ERROR_PAGENOTEXIST) {
		return NULL;
	}else {
		return getPage(id);
	}
}
Page_t* PageManager::getPage(uint8_t id) {
	if (id < page_num) {
		Page_t* page = &page_list[id];
		return page;
	}
	else {
		return NULL;
	}
}
int PageManager::SwitchTo(uint8_t id) {
	if (id < page_num) {
		Page_t * page  = getPage(id);
		now_page = page;
	}
	else {
		return ERROR_PAGENOTEXIST;
	}
}

int PageManager::SwitchTo(const char* name) {
	uint8_t id = getPageId(name);
	if (id == ERROR_PAGENOTEXIST) {
		return ERROR_PAGENOTEXIST;
	}
	else {
		SwitchTo(id);
	}
}

void PageManager::Loop(void) {
	static Page_t* last_page;
	if (last_page != now_page) {
		void* parms = NULL;
		if (last_page) {
			parms = last_page->destory(NULL);
		}
		if (now_page) {
			now_page->create(parms);
		}
		last_page = now_page;
	}
	else {
		if (now_page) {
			now_page->loop(NULL);
		}
	}
}

void PageManager::KeyCallback(uint8_t key, uint8_t event) {
	if (now_page && now_page->key_callback) {
		now_page->key_callback(key, event);
	}
}

PageManager pagemanager;