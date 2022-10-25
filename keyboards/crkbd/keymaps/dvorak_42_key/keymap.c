
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "dvorak_42_key.h"
#include "rgblight.h"

// to build: qmk compile -kb crkbd -km dvorak_42_key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   OSL(VSCODE), KC_QUOTE, KC_COMMA, KC_DOT,  KC_P,   KC_Y,                         KC_F,   KC_G,   KC_C,     KC_R,  KC_L,    KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
OSL(SHELL_NAV), KC_A,     KC_O,     KC_E,    KC_U,   KC_I,                         KC_D,   KC_H,   KC_T,     KC_N,  KC_S,   TD(TD_DEL_WORD_DEL),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
OSM(MOD_LSFT),KC_SCOLON, KC_Q,  KC_J,    KC_K,   KC_X,                             KC_B,   KC_M,   KC_W,     KC_V,  KC_Z,   CAPS_WORD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                      MO(BROWSER_CONTROL), MO(COMBINED),MO(KEYNAV),     KC_ENTER, KC_SPACE, OSL(SHORTCUTS)
                                      //`--------------------------'  `--------------------------'

  ),

  [BASE_IOS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LALT(KC_BSPC),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        MO(BROWSER_CONTROL_IOS),  KC_TRNS, MO(KEYNAV_IOS),     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [KEYNAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_ESC, RCTL(KC_ENTER), RCTL(KC_K), RCTL(KC_Z), RCTL(KC_S), RCTL(KC_N),          KC_TRNS, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_DELETE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
KC_TRNS, MO(KEYSEL), KC_TRNS, RSFT(KC_TAB), KC_TAB, RCTL(KC_F),         LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_RIGHT), KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
KC_TRNS, RCTL(KC_P), KC_TRNS,  RCTL(KC_A), RCTL(KC_B), NP_DUPE_LINE,               KC_TRNS, RCTL(KC_C), RCTL(KC_X), RCTL(KC_V), KC_PGDOWN, RCTL(KC_DELETE),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  // https://medium.com/macoclock/best-text-editing-keyboard-shortcuts-for-ipad-41e8234a4c42
  // alt == option
  // gui/win == command
  [KEYNAV_IOS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_ESC,   KC_TRNS, KC_TRNS, RGUI(KC_Z),RCTL(KC_S), KC_TRNS,                KC_TRNS, RGUI(KC_LEFT), KC_UP, RGUI(KC_RIGHT), KC_PGUP, KC_DELETE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,MO(KEYSEL_IOS), KC_TRNS, KC_TRNS, KC_TRNS, RGUI(KC_F),           LALT(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LALT(KC_RIGHT), LALT(KC_DELETE),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, RGUI(KC_C), RGUI(KC_X), RGUI(KC_V), KC_PGDOWN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),


  [KEYSEL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, RSFT(KC_HOME), RSFT(KC_UP), RSFT(KC_END), RSFT(KC_PGUP), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         RSFT(RCTL(KC_LEFT)), RSFT(KC_LEFT), RSFT(KC_DOWN), RSFT(KC_RIGHT), RSFT(RCTL(KC_RIGHT)), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, RCTL(KC_C), RCTL(KC_X), RCTL(KC_V), RSFT(KC_PGDN), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [KEYSEL_IOS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, RSFT(RGUI(KC_LEFT)), RSFT(KC_UP), RSFT(RGUI(KC_RIGHT)), RSFT(KC_PGUP), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         RSFT(LALT(KC_LEFT)), RSFT(KC_LEFT), RSFT(KC_DOWN), RSFT(KC_RIGHT), RSFT(LALT(KC_RIGHT)), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, RGUI(KC_C), RGUI(KC_X), RGUI(KC_V), RSFT(KC_PGDN), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [SHELL_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                              ,-----------------------------------------------------.
KC_TRNS,SHELL_GIT_DIFF, SHELL_PGREP, SHELL_PLESS, SHELL_LESS, KC_TRNS,              RCTL(KC_D), KC_HOME, KC_UP, KC_END, RCTL(KC_L), RCTL(KC_X),
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
OSL(SHELL_SCREEN),SHELL_GIT_STATUS,SHELL_CDPRE,SHELL_LSLTR,SHELL_LS, SHELL_LSLA,              LALT(KC_B), KC_LEFT, KC_DOWN, KC_RIGHT, LALT(KC_F), LALT(KC_BSPC),
  //|--------+--------+--------+--------+--------+--------|                           |--------+--------+--------+--------+--------+--------|
KC_TRNS,SHELL_SCREEN_LIST, SHELL_SCREENRD, SHELL_SCREEN_NEW, SHELL_TAILF, KC_TRNS,   RCTL(KC_U), LALT(KC_DOT), RCTL(KC_R), KC_BTN2, RCTL(KC_K), RCTL(KC_C),
  //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,              LCTL(LSFT(KC_V)), KC_TRNS, KC_TRNS
                                      //`--------------------------'            `--------------------------'
  ),

  [SHELL_SCREEN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                 ,-----------------------------------------------------.
KC_TRNS,KC_TRNS, SCREEN_READREG_3, SCREEN_READREG_2, SCREEN_READREG_1,KC_TRNS,          KC_TRNS,         SCREEN_7, SCREEN_8, SCREEN_9, SCREEN_RENAME, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                 |--------+--------+--------+--------+--------+--------|
TO(BASE),KC_TRNS,SCREEN_PASTEREG_3,SCREEN_PASTEREG_2,SCREEN_PASTEREG_1,SCREEN_DETACH,    SCREEN_TAB_LEFT, SCREEN_4, SCREEN_5, SCREEN_6, SCREEN_TAB_RIGHT, SCREEN_COPY_MODE,
  //|--------+--------+--------+--------+--------+--------|                                 |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS,         SCREEN_1, SCREEN_2, SCREEN_3, SCREEN_NUMBER, SCREEN_PASTE,
  //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,                     SCREEN_KILL, SCREEN_NEW_TAB, SCREEN_0
                                      //`--------------------------'                `--------------------------'
  ),

  [VSCODE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                             ,-----------------------------------------------------.
KC_TRNS, KC_TRNS, KC_TRNS, VS_CMT_BLOCK, VS_CMT_LINE, VS_BM_LISTALL,                     VS_COPYLINEDOWN, VS_REFERENCES, VS_DEFINITION, VS_IMPLEMENTATION, VS_LINE,   VS_BRACKET,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
KC_TRNS, KC_TRNS, VS_TOGGLE_TERMINAL, VS_FOCUS_TERMINAL, VS_FOCUS_EDITOR, VS_BM_LIST,    VS_CLOSETAB,     VS_TABLEFT,    VS_TABRIGHT,   VS_SYMBOLEDITOR,   VS_FILE,   VS_BACK,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, VS_BM_CLEARALL,                             VS_JUMPY,        VS_BM_PREV,    VS_BM_NEXT,    VS_GROUP_1,        VS_GROUP_2, VS_BM_TOGGLE,
//|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  VS_DEL_LEFT, VS_DEL_RIGHT,                VS_DEL_LINE, VS_JUMPY, VS_COMMANDS
                                      //`--------------------------'            `--------------------------'
  ),
  
  [COMBINED] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TILD,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                        KC_PLUS,   KC_7,  KC_8,   KC_9,  KC_ASTR,  KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 KC_GRAVE,  KC_LPRN, KC_RPRN, KC_LBRACKET, KC_RBRACKET, KC_UNDS,                  KC_MINS,   KC_4,  KC_5,   KC_6,  KC_SLSH,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 KC_CIRC,  KC_COLN,  KC_DQUO,   KC_LCBR,   KC_RCBR,     KC_AMPR,                  KC_EQUAL,  KC_1,  KC_2,   KC_3,  KC_QUES,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_0
                                      //`--------------------------'  `--------------------------'
  ),

  [BROWSER_CONTROL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                     ,-----------------------------------------------------.
KC_TRNS, KC_TRNS, KC_BTN3, KC_MS_U, KC_BTN1, KC_BTN2,                                       KC_UP, KC_PGUP, KC_PGDN, KC_MS_WH_UP, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                                       KC_DOWN, RCTL(KC_PGUP), RCTL(KC_PGDN), KC_MS_WH_DOWN, LALT(KC_LEFT), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
KC_TRNS, RCTL(LSFT(KC_TAB)), RCTL(KC_TAB), WINDOWS10_WORKSPACE_LEFT, WINDOWS10_WORKSPACE_RIGHT, WINDOWS10_TASK_VIEW, KC_TRNS, RCTL(KC_1),   RCTL(KC_9), KC_F6, KC_F5, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,                         RCTL(KC_W), RCTL(KC_T), KC_TRNS
                                      //`--------------------------'                   `--------------------------'
  ),

  [BROWSER_CONTROL_IOS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                             ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_BTN3, KC_MS_U, KC_BTN1, KC_BTN2,                               KC_UP, KC_PGUP, KC_PGDN, KC_MS_WH_UP, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                             KC_DOWN, RGUI(LALT(KC_LEFT)), RGUI(LALT(KC_RIGHT)), KC_MS_WH_DOWN, LALT(KC_LEFT), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
    KC_TRNS, KC_TRNS, IOS_SHOW_SLIDEOVER, IOS_APP_PREV, IOS_APP_NEXT, IOS_APP_LIST,     KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, RGUI(KC_L), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,             RGUI(KC_W), RGUI(KC_T), KC_TRNS
                                      //`--------------------------'          `--------------------------'
  ),

  [SHORTCUTS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                             ,-----------------------------------------------------.
    KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                                MEH(KC_I), MEH(KC_J), MEH(KC_K), MEH(KC_L), MEH(KC_M), MEH(KC_N),
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
    KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,                               MEH(KC_O), MEH(KC_P), MEH(KC_Q), MEH(KC_R), MEH(KC_S), MEH(KC_T),
  //|--------+--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------+--------|
TG(RGB_CONTROL), OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), KC_TRNS,            MEH(KC_U), MEH(KC_V), MEH(KC_W), MEH(KC_X), MEH(KC_Y), MEH(KC_Z),
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,                 TG(BASE_IOS), KC_TRNS, KC_TRNS
                                      //`--------------------------'             `--------------------------'
  ),

  [RGB_CONTROL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TRNS,   KC_TRNS, RGB_SAI, RGB_SAD, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
RGB_TOG, RGB_MODE_FORWARD, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    TG(RGB_CONTROL),   KC_TRNS, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  /*
  // empty layer
  [15] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
  */


};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  // return rotation;
  return OLED_ROTATION_180;
}
  

#define DISPLAY_LAYER_NAME(LAYER_NAME, LAYER_STRING) \
  if(biton32(layer_state) == LAYER_NAME) { \
      oled_write_ln_P(PSTR(LAYER_STRING), false); \
      return;\
  }\


void oled_render_layer_state(void) {
  DISPLAY_LAYER_NAME(RGB_CONTROL, "RGB_CONTROL");
  DISPLAY_LAYER_NAME(SHORTCUTS, "SHORTCUTS");
  DISPLAY_LAYER_NAME(VSCODE, "VSCODE");
  DISPLAY_LAYER_NAME(COMBINED, "SYMBOLS");
  DISPLAY_LAYER_NAME(BROWSER_CONTROL_IOS, "BROWSER IOS");
  DISPLAY_LAYER_NAME(BROWSER_CONTROL, "BROWSER");
  DISPLAY_LAYER_NAME(SHELL_SCREEN, "SHELL SCREEN");
  DISPLAY_LAYER_NAME(SHELL_NAV, "SHELL NAV");
  DISPLAY_LAYER_NAME(KEYSEL_IOS, "KEYSEL IOS");
  DISPLAY_LAYER_NAME(KEYSEL, "KEYSEL");
  DISPLAY_LAYER_NAME(KEYNAV_IOS, "KEYNAV IOS");
  DISPLAY_LAYER_NAME(KEYNAV, "KEYNAV");
  DISPLAY_LAYER_NAME(BASE_IOS, "BASE IOS");
  DISPLAY_LAYER_NAME(BASE, "BASE");

}

const rgblight_segment_t PROGMEM rgb_layer_off[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 0, 0}
);

const rgblight_segment_t PROGMEM rgb_layer_blue[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_layer_purple[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM rgb_layer_red[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_RED}
);

const rgblight_segment_t PROGMEM rgb_layer_orange[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_ORANGE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_off,
    rgb_layer_blue,
    rgb_layer_purple,
    rgb_layer_red,
    rgb_layer_orange
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {

    

    rgblight_set_layer_state(1, layer_state_cmp(state, KEYNAV));
    rgblight_set_layer_state(2, layer_state_cmp(state, KEYSEL));    

    
    rgblight_set_layer_state(3, layer_state_cmp(state, SHELL_NAV));    
    rgblight_set_layer_state(4, layer_state_cmp(state, SHELL_SCREEN));
    
    
    return state;
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master( )) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
     }
    return false;
}

#endif // OLED_ENABLE
