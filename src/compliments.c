#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0xDE, 0xB3, 0x4E, 0x49, 0xB2, 0x93, 0x45, 0xB7, 0xB7, 0xD4, 0x15, 0xD5, 0x98, 0xE7, 0x22, 0x75 }
PBL_APP_INFO(MY_UUID,
             "Complimenter", "Jatin Inc",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;

TextLayer hello_layer;

void handle_init(AppContextRef ctx) {
      window_init(&window, "Window Name");
      window_stack_push(&window, true /* Animated */);
        
      text_layer_init(&hello_layer, GRect(0, 65, 144, 30));
      text_layer_set_text_alignment(&hello_layer, GTextAlignmentCenter);
      text_layer_set_text(&hello_layer, "You're amazing");
      text_layer_set_font(&hello_layer, fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21));
      layer_add_child(&window.layer, &hello_layer.layer);
}

void pbl_main(void *params) {
    PebbleAppHandlers handlers = {
        .init_handler = &handle_init
    };
    app_event_loop(params, &handlers);
}
