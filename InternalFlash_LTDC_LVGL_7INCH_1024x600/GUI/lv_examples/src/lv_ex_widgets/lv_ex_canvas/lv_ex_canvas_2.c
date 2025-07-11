#include "../../../lv_examples.h"
#if LV_USE_CANVAS

#define CANVAS_WIDTH  1
#define CANVAS_HEIGHT  1

/**
 * Create a transparent canvas with Chroma keying and indexed color format (palette).
 */
void lv_ex_canvas_2(void)
{
    /*Create a button to better see the transparency*/
    lv_btn_create(lv_scr_act(), NULL);

    /*Create a buffer for the canvas*/
    static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];

    /*Create a canvas and initialize its the palette*/
    lv_obj_t * canvas = lv_canvas_create(lv_scr_act(), NULL);
    lv_canvas_set_buffer(canvas, cbuf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_align(canvas, NULL, LV_ALIGN_CENTER, 0, 0);
    // lv_canvas_set_palette(canvas, 0, LV_COLOR_TRANSP);
    // lv_canvas_set_palette(canvas, 1, LV_COLOR_RED);

    /*Create colors with the indices of the palette*/
    lv_color_t c0;
    lv_color_t c1;

    c0.full = 0xff00;
    c1.full = 0xfff0;

    /*Create hole on the canvas*/
    uint32_t x;
    uint32_t y;
    for( y = 0; y < 50; y++) {
        for( x = 0; x < 50; x++) {
            lv_canvas_set_px(canvas, x, y, c0);
        }
    }

}
#endif
