#include <eadk.h>
const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "Notes";
const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;
int main(int argc, char * argv[]) {
  const char * note = "Ma Note: EADK est genial!";
  while (true) {
    eadk_keyboard_state_t state = eadk_keyboard_scan();
    if (eadk_keyboard_key_down(state, eadk_key_back)) break;
    eadk_display_push_rect_uniform((eadk_rect_t){0, 0, EADK_SCREEN_WIDTH, EADK_SCREEN_HEIGHT}, eadk_color_white);
    eadk_display_draw_string("Bloc Notes", (eadk_point_t){10, 10}, true, eadk_color_black, eadk_color_white);
    eadk_display_draw_string(note, (eadk_point_t){10, 60}, false, eadk_color_black, eadk_color_white);
    eadk_display_draw_string("Appuyez sur Back pour quitter", (eadk_point_t){10, 200}, false, eadk_color_black, eadk_color_white);
    eadk_timing_msleep(33);
  }
  return 0;
}