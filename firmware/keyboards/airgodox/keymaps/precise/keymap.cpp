/*
Copyright 2018 <Pierre Constantineau, Julian Komaromy>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "keymap.h"

#if KEYBOARD_MODE == SINGLE
/*
 * everything that concerns the layout of the keyboard
 * should go into this function
 */
matrix_t setupKeymap() 
{ 
    //two commonly used activation methods
    //TODO move out into defaults
    Keypress hold { {{ {false, 100} }} };
    Keypress toggle { {{ {false, 1}, {false, 1} }}, 1 };

    VKey TG_SHIFT {toggle, TG(KC_LSHIFT)};

    //all of these keys share the same toggling keypress
    //so that they work seamlessly across layers
    VKey TG_L1 {toggle, TG(LAYER_1)};

    VKey OS_SHIFT {OS(KC_LSHIFT)};
    VKey HOLD_W {hold, KC_W};

    /*
     * initiialize the default layer (QWERTY/PRESS) with the following
     * keymap
     */
    layer_t layer0 
    {{
         {KC_ESC,    OS_SHIFT,          HOLD_W,  KC_E,    KC_R,     KC_T},
             {KC_TAB,    KC_NO,    KC_S,  KC_CAP_D, KC_F,     KC_G},
             {KC_LSHIFT, TG_SHIFT, KC_X,  KC_C,     KC_V,     KC_B},
             {KC_NO,     KC_NO,    KC_NO, TG_L1,     KC_E,  KC_LGUI}
     }};

    layer_t layer1 
    {{
         {KC_GRV,    KC_1,    KC_2,     KC_3,    KC_4,     KC_5},
             {KC_CAPS,   KC_F1,   KC_F2,    KC_F3,   KC_F4,    KC_F5}, 
             {KC_LSHIFT, KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10}, 
             {KC_NO,     KC_NO,   KC_NO,    TG_L1,   KC_E,     KC_LGUI}
     }};

    //return an array of the two layers
    return {{ layer0, layer1 }};
}

#else
/*
 * TODO Configure right side
 */

error

#endif /* KEYBOARD_SIDE */