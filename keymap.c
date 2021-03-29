/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
    EAT = SAFE_RANGE,
};



enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _SHIFT,
  _ADJUST,
  _GAMING,
  _GAMING2,
};


// Tap Dance declarations
enum {
    TD_ESC_CAPS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,TD(TD_ESC_CAPS),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       KC_LGUI, MO(_LOWER),  KC_SPC,    KC_ENT, MO(_RAISE), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,   KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGUP, XXXXXXX, KC_MINS,  KC_EQL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,                       KC_END, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRAVE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, XXXXXXX,  KC_SPC,   KC_PENT,MO(_ADJUST), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI, MO(_ADJUST), KC_SPC,   KC_ENT,  _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),


  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,TG(_GAMING),                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAMING] = LAYOUT_split_3x6_3(
  	 //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(_GAMING2, KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  	 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  	 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      	     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  	 //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	                                        KC_LCTRL, KC_LALT,  KC_SPC,    KC_ENT, TG(_GAMING), KC_EXLM
                                      	      //`--------------------------'  `--------------------------'
  ),

    [_GAMING2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_F1,    KC_F2,  KC_F3,   KC_F4,    KC_6,                        KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX, KC_RGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     EAT,                        KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       KC_LCTRL, KC_LALT,  KC_SPC,    KC_ENT, MO(_RAISE), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

};


uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:        {
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                delkey_registered = true;              
                set_mods(mod_state);
                return false;
            }
        } 
	else {             
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        return true;
    }
	break;

    case EAT:   {
        if (record->event.pressed) {
            SEND_STRING("678");
        } else {
        }
    }
    return true;
 }
    return true;

};



#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;
  return rotation;  
}


//void oled_render_logo1(void) {
//    static const char PROGMEM corne_logo[] = {

//    oled_write_raw_P(corne_logo, sizeof(corne_logo));
//};

//}
void oled_task_user(void) {
           switch (get_highest_layer(layer_state)) {
    case _QWERTY:          
	    oled_write(("     "), false);  
	    oled_write(("     "), false);  
	    oled_write(("     "), false);
	    break;
        case _LOWER:
            if (is_master) { 
		if (get_mods() & MOD_MASK_SHIFT) {
            oled_write(("!@#$%"), false);
	    oled_write(("     "), false);  
	    oled_write(("     "), false);  

	}
		else {
	    oled_write(("12345"), false);
	    oled_write(("     "), false);  
	    oled_write(("     "), false);  
//	    oled_render_logo2();
	    
	    
	}
    }
            else {
            	if (get_mods() & MOD_MASK_SHIFT) {
            oled_write(("^&*()"), false);
	}
		else {
		oled_write(("67890"), false);
	}
    }
            break;
        case _RAISE:          
            if (is_master) {
            oled_write(("F1-F6 "), false);
	}
            else {
            oled_write(("F7-12"), false);
	    oled_write(("-=[]/"), false);
	    oled_write(("_+{}|"), false);
	}
           break;

        case _ADJUST:
            if (is_master) {
           // void render_rgb_status(void) {
    	    oled_write_ln("RGB:", false);
     	    static char temp[20] = {0};
    	    snprintf(temp, sizeof(temp) + 1, "M:%3dS:%3d", rgb_matrix_config.mode, rgb_matrix_is_enabled());
    	    oled_write(temp, false);

	}      
	    else {
	    oled_write(("     "), false);
	    oled_write(("     "), false);  
	    oled_write(("     "), false);  
}
            break;
        case _GAMING:            
            oled_write((" GAMEMODE "), false);	
	    oled_write(("     "), false);  
	    oled_write(("     "), false);  
            oled_scroll_left();

            break;
}   
	led_t led_state = host_keyboard_led_state();
        oled_write_ln_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
  


};




#endif 
// OLED_DRIVER_ENABLE
