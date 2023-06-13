#ifndef __COMMON_H__
#define __COMMON_H__
#include "manage.h"
#include <U8g2lib.h>
#include "Juan_EventButton.h"
#include "MillisTaskManager.h"
#include <initializer_list>
using namespace std;
extern MillisTaskManager TaskManager;
class U8G2_SDL_128X64 : public U8G2 {
public: U8G2_SDL_128X64(const u8g2_cb_t* rotation) : U8G2() {
    u8g2_SetupBuffer_SDL_128x64(&u8g2, rotation);
}
public:
    /* 这里重写下U8G2 setFont以提供getFont方法 */
    void setFont(const uint8_t* font) {
        U8G2::setFont(font);
        _font = font;
    }
    const uint8_t* getFont() {
        return _font;
    }
private:
    const uint8_t* _font;
};

extern U8G2_SDL_128X64 u8g2;


#define UNITY_KEYBAR_TEXT_NUM   4

class Unity_keybar {
    public:
        Unity_keybar() {
            setFont(u8g2_font_helvR08_tr);
        }
        void setText(uint8_t index,const char * text);
        void setText(initializer_list<const char *> text);
        void setFont(const uint8_t * font);
        void show();
        void mask(uint8_t index, uint16_t ms = 100);
        uint8_t getHeight();
    private: 
        char _buf[UNITY_KEYBAR_TEXT_NUM][5];
        const uint8_t *_font;
};
extern Unity_keybar keyBar;


#define UNITY_MENU_MAX_ITEM 32

typedef void (*callback_t)(void);
typedef struct {
    const char* title;
    callback_t callback;
}menu_item_t;

class Unity_menu{
    public:
        Unity_menu(uint8_t _item_pad_piexs = 2) {
            item_pad_piexs = _item_pad_piexs;
        }
        void set_items(initializer_list<menu_item_t> items);
        uint8_t size();
        void cursor_up();
        void cursor_down();
        uint8_t cursor_pos();
        virtual void redraw();
    private:
        menu_item_t item_list[UNITY_MENU_MAX_ITEM];
        uint8_t select_index;
        uint8_t item_pad_piexs;
};

extern Unity_menu menu;


#define PAGE_DECLARE(NAME)                                  \
    static void * create(void *parms);                      \
    static void * loop(void *parms);                        \
    static void * destory(void *parms);                     \
    static void   key_callback(uint8_t key,uint8_t event);  \
    void NAME##_register(void){                             \
        pagemanager.Register(#NAME, create, loop, destory, key_callback); \
    }



#define PAGE_REGISTER(NAME)                 \
    extern void NAME##_register(void);      \
    do                                      \
    {NAME##_register();} while (0);     


#endif
