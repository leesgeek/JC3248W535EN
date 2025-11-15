#include "display_color_test.h"
#include <lvgl.h>
#include <esp_log.h>

static const char *TAG = "display_color_test";

void display_color_test_create(void)
{
    lv_disp_t *disp = lv_disp_get_default();
    lv_obj_t *scr = lv_disp_get_scr_act(disp);

    /* Clear existing content */
    lv_obj_clean(scr);

    /* Determine screen size (fallback to disp resolution if needed) */
    lv_coord_t w = lv_obj_get_width(scr);
    lv_coord_t h = lv_obj_get_height(scr);
    if (w == 0 || h == 0)
    {
        w = lv_disp_get_hor_res(disp);
        h = lv_disp_get_ver_res(disp);
    }

    /* Top: Red = Blue */
    lv_obj_t *top = lv_obj_create(scr);
    lv_obj_remove_style_all(top);
    lv_obj_set_size(top, w, h / 3);
    lv_obj_align(top, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_bg_color(top, lv_color_hex(0xFF0000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(top, LV_OPA_COVER, LV_PART_MAIN);

    /* Middle: Green - Red */
    lv_obj_t *mid = lv_obj_create(scr);
    lv_obj_remove_style_all(mid);
    lv_obj_set_size(mid, w, h / 3);
    lv_obj_align(mid, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_color(mid, lv_color_hex(0x00FF00), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(mid, LV_OPA_COVER, LV_PART_MAIN);

    /* Bottom: Blue - Green*/
    lv_obj_t *bot = lv_obj_create(scr);
    lv_obj_remove_style_all(bot);
    lv_obj_set_size(bot, w, h - (h / 3 * 2));
    lv_obj_align(bot, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_bg_color(bot, lv_color_hex(0x0000FF), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(bot, LV_OPA_COVER, LV_PART_MAIN);

    ESP_LOGI(TAG, "Created color test (w=%d h=%d)", w, h);
}
