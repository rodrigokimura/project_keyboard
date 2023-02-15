#include "HID-Project.h"

struct Coords
{
    const byte row;
    const byte col;
};

struct Size
{
    const byte rows;
    const byte columns;
};

struct _Key
{
    const int key;
    const bool isMedia;
    _Key(int k, bool m) : key(k), isMedia(m) {}
    _Key() : key(KEY_RESERVED), isMedia(false) {}

    void press()
    {

        if (isMedia == true)
        {
            Consumer.press(ConsumerKeycode(key));
        }
        else
        {
            Keyboard.press(KeyboardKeycode(key));
        }
    }
    void release()
    {

        if (isMedia == true)
        {
            Consumer.release(ConsumerKeycode(key));
        }
        else
        {
            Keyboard.release(KeyboardKeycode(key));
        }
    }
};

struct MultiKey
{
    _Key keys[2];
    byte modifier;
    MultiKey(_Key k1, _Key k2) : keys{k1, k2}, modifier(0) {}
    MultiKey(byte mod) : keys{_Key(), _Key()}, modifier(mod) {}

    void press(byte &layer)
    {
        if (modifier == 1 || modifier == 2)
        {
            layer = modifier;
        }
        else
        {
            keys[layer > 0 ? 1 : 0].press();
        }
    }
    void release(byte &layer)
    {
        if (modifier > 0 && layer == modifier)
        {
            layer = 0;
        }
        else
        {
            keys[layer > 0 ? 1 : 0].release();
        }
    }
};

_Key K_RESERVED = {KEY_RESERVED, false};
_Key K_ERROR_ROLLOVER = {KEY_ERROR_ROLLOVER, false};
_Key K_POST_FAIL = {KEY_POST_FAIL, false};
_Key K_ERROR_UNDEFINED = {KEY_ERROR_UNDEFINED, false};
_Key K_A = {KEY_A, false};
_Key K_B = {KEY_B, false};
_Key K_C = {KEY_C, false};
_Key K_D = {KEY_D, false};
_Key K_E = {KEY_E, false};
_Key K_F = {KEY_F, false};
_Key K_G = {KEY_G, false};
_Key K_H = {KEY_H, false};
_Key K_I = {KEY_I, false};
_Key K_J = {KEY_J, false};
_Key K_K = {KEY_K, false};
_Key K_L = {KEY_L, false};
_Key K_M = {KEY_M, false};
_Key K_N = {KEY_N, false};
_Key K_O = {KEY_O, false};
_Key K_P = {KEY_P, false};
_Key K_Q = {KEY_Q, false};
_Key K_R = {KEY_R, false};
_Key K_S = {KEY_S, false};
_Key K_T = {KEY_T, false};
_Key K_U = {KEY_U, false};
_Key K_V = {KEY_V, false};
_Key K_W = {KEY_W, false};
_Key K_X = {KEY_X, false};
_Key K_Y = {KEY_Y, false};
_Key K_Z = {KEY_Z, false};
_Key K_1 = {KEY_1, false};
_Key K_2 = {KEY_2, false};
_Key K_3 = {KEY_3, false};
_Key K_4 = {KEY_4, false};
_Key K_5 = {KEY_5, false};
_Key K_6 = {KEY_6, false};
_Key K_7 = {KEY_7, false};
_Key K_8 = {KEY_8, false};
_Key K_9 = {KEY_9, false};
_Key K_0 = {KEY_0, false};
_Key K_ENTER = {KEY_ENTER, false};
_Key K_RETURN = {KEY_RETURN, false}; // Alias
_Key K_ESC = {KEY_ESC, false};
_Key K_BACKSPACE = {KEY_BACKSPACE, false};
_Key K_TAB = {KEY_TAB, false};
_Key K_SPACE = {KEY_SPACE, false};
_Key K_MINUS = {KEY_MINUS, false};
_Key K_EQUAL = {KEY_EQUAL, false};
_Key K_LEFT_BRACE = {KEY_LEFT_BRACE, false};
_Key K_RIGHT_BRACE = {KEY_RIGHT_BRACE, false};
_Key K_BACKSLASH = {KEY_BACKSLASH, false};
_Key K_NON_US_NUM = {KEY_NON_US_NUM, false};
_Key K_SEMICOLON = {KEY_SEMICOLON, false};
_Key K_QUOTE = {KEY_QUOTE, false};
_Key K_TILDE = {KEY_TILDE, false};
_Key K_COMMA = {KEY_COMMA, false};
_Key K_PERIOD = {KEY_PERIOD, false};
_Key K_SLASH = {KEY_SLASH, false};
_Key K_CAPS_LOCK = {KEY_CAPS_LOCK, false};
_Key K_F1 = {KEY_F1, false};
_Key K_F2 = {KEY_F2, false};
_Key K_F3 = {KEY_F3, false};
_Key K_F4 = {KEY_F4, false};
_Key K_F5 = {KEY_F5, false};
_Key K_F6 = {KEY_F6, false};
_Key K_F7 = {KEY_F7, false};
_Key K_F8 = {KEY_F8, false};
_Key K_F9 = {KEY_F9, false};
_Key K_F10 = {KEY_F10, false};
_Key K_F11 = {KEY_F11, false};
_Key K_F12 = {KEY_F12, false};
_Key K_PRINT = {KEY_PRINT, false};
_Key K_PRINTSCREEN = {KEY_PRINTSCREEN, false}; // Alias
_Key K_SCROLL_LOCK = {KEY_SCROLL_LOCK, false};
_Key K_PAUSE = {KEY_PAUSE, false};
_Key K_INSERT = {KEY_INSERT, false};
_Key K_HOME = {KEY_HOME, false};
_Key K_PAGE_UP = {KEY_PAGE_UP, false};
_Key K_DELETE = {KEY_DELETE, false};
_Key K_END = {KEY_END, false};
_Key K_PAGE_DOWN = {KEY_PAGE_DOWN, false};
_Key K_RIGHT_ARROW = {KEY_RIGHT_ARROW, false};
_Key K_LEFT_ARROW = {KEY_LEFT_ARROW, false};
_Key K_DOWN_ARROW = {KEY_DOWN_ARROW, false};
_Key K_UP_ARROW = {KEY_UP_ARROW, false};
_Key K_RIGHT = {KEY_RIGHT, false}; // Alias
_Key K_LEFT = {KEY_LEFT, false};   // Alias
_Key K_DOWN = {KEY_DOWN, false};   // Alias
_Key K_UP = {KEY_UP, false};       // Alias
_Key K_NUM_LOCK = {KEY_NUM_LOCK, false};
_Key KPAD_DIVIDE = {KEYPAD_DIVIDE, false};
_Key KPAD_MULTIPLY = {KEYPAD_MULTIPLY, false};
_Key KPAD_SUBTRACT = {KEYPAD_SUBTRACT, false};
_Key KPAD_ADD = {KEYPAD_ADD, false};
_Key KPAD_ENTER = {KEYPAD_ENTER, false};
_Key KPAD_1 = {KEYPAD_1, false};
_Key KPAD_2 = {KEYPAD_2, false};
_Key KPAD_3 = {KEYPAD_3, false};
_Key KPAD_4 = {KEYPAD_4, false};
_Key KPAD_5 = {KEYPAD_5, false};
_Key KPAD_6 = {KEYPAD_6, false};
_Key KPAD_7 = {KEYPAD_7, false};
_Key KPAD_8 = {KEYPAD_8, false};
_Key KPAD_9 = {KEYPAD_9, false};
_Key KPAD_0 = {KEYPAD_0, false};
_Key KPAD_DOT = {KEYPAD_DOT, false};
_Key K_NON_US = {KEY_NON_US, false};
_Key K_APPLICATION = {KEY_APPLICATION, false}; // Context menu/right click
_Key K_MENU = {KEY_MENU, false};               // Alias

// Most of the following keys will only work with Linux or not at all.
// F13+ keys are mostly used for laptop functions like ECO key.
_Key K_POWER = {KEY_POWER, false};           // PowerOff (Ubuntu)
_Key K_PAD_EQUALS = {KEY_PAD_EQUALS, false}; // Dont confuse with KEYPAD_EQUAL_SIGN
_Key K_F13 = {KEY_F13, false};               // Tools (Ubunutu)
_Key K_F14 = {KEY_F14, false};               // Launch5 (Ubuntu)
_Key K_F15 = {KEY_F15, false};               // Launch6 (Ubuntu)
_Key K_F16 = {KEY_F16, false};               // Launch7 (Ubuntu)
_Key K_F17 = {KEY_F17, false};               // Launch8 (Ubuntu)
_Key K_F18 = {KEY_F18, false};               // Launch9 (Ubuntu)
_Key K_F19 = {KEY_F19, false};               // Disabled (Ubuntu)
_Key K_F20 = {KEY_F20, false};               // AudioMicMute (Ubuntu)
_Key K_F21 = {KEY_F21, false};               // Touchpad toggle (Ubuntu)
_Key K_F22 = {KEY_F22, false};               // TouchpadOn (Ubuntu)
_Key K_F23 = {KEY_F23, false};               // TouchpadOff Ubuntu)
_Key K_F24 = {KEY_F24, false};               // Disabled (Ubuntu)
_Key K_EXECUTE = {KEY_EXECUTE, false};       // Open (Ubuntu)
_Key K_HELP = {KEY_HELP, false};             // Help (Ubuntu)
_Key K_MENU2 = {KEY_MENU2, false};           // Disabled (Ubuntu)
_Key K_SELECT = {KEY_SELECT, false};         // Disabled (Ubuntu)
_Key K_STOP = {KEY_STOP, false};             // Cancel (Ubuntu)
_Key K_AGAIN = {KEY_AGAIN, false};           // Redo (Ubuntu)
_Key K_UNDO = {KEY_UNDO, false};             // Undo (Ubuntu)
_Key K_CUT = {KEY_CUT, false};               // Cut (Ubuntu)
_Key K_COPY = {KEY_COPY, false};             // Copy (Ubuntu)
_Key K_PASTE = {KEY_PASTE, false};           // Paste (Ubuntu)
_Key K_FIND = {KEY_FIND, false};             // Find (Ubuntu)
_Key K_MUTE = {KEY_MUTE, false};
_Key K_VOLUME_MUTE = {KEY_VOLUME_MUTE, false}; // Alias
_Key K_VOLUME_UP = {KEY_VOLUME_UP, false};
_Key K_VOLUME_DOWN = {KEY_VOLUME_DOWN, false};
_Key K_LOCKING_CAPS_LOCK = {KEY_LOCKING_CAPS_LOCK, false};     // Disabled (Ubuntu)
_Key K_LOCKING_NUM_LOCK = {KEY_LOCKING_NUM_LOCK, false};       // Disabled (Ubuntu)
_Key K_LOCKING_SCROLL_LOCK = {KEY_LOCKING_SCROLL_LOCK, false}; // Disabled (Ubuntu)
_Key KPAD_COMMA = {KEYPAD_COMMA, false};                       // .
_Key KPAD_EQUAL_SIGN = {KEYPAD_EQUAL_SIGN, false};             // Disabled (Ubuntu), Dont confuse with KEYPAD_EQUAL
_Key K_INTERNATIONAL1 = {KEY_INTERNATIONAL1, false};           // Disabled (Ubuntu)
_Key K_INTERNATIONAL2 = {KEY_INTERNATIONAL2, false};           // Hiragana Katakana (Ubuntu)
_Key K_INTERNATIONAL3 = {KEY_INTERNATIONAL3, false};           // Disabled (Ubuntu)
_Key K_INTERNATIONAL4 = {KEY_INTERNATIONAL4, false};           // Henkan (Ubuntu)
_Key K_INTERNATIONAL5 = {KEY_INTERNATIONAL5, false};           // Muhenkan (Ubuntu)
_Key K_INTERNATIONAL6 = {KEY_INTERNATIONAL6, false};           // Disabled (Ubuntu)
_Key K_INTERNATIONAL7 = {KEY_INTERNATIONAL7, false};           // Disabled (Ubuntu)
_Key K_INTERNATIONAL8 = {KEY_INTERNATIONAL8, false};           // Disabled (Ubuntu)
_Key K_INTERNATIONAL9 = {KEY_INTERNATIONAL9, false};           // Disabled (Ubuntu)
_Key K_LANG1 = {KEY_LANG1, false};                             // Disabled (Ubuntu)
_Key K_LANG2 = {KEY_LANG2, false};                             // Disabled (Ubuntu)
_Key K_LANG3 = {KEY_LANG3, false};                             // Katakana (Ubuntu)
_Key K_LANG4 = {KEY_LANG4, false};                             // Hiragana (Ubuntu)
_Key K_LANG5 = {KEY_LANG5, false};                             // Disabled (Ubuntu)
_Key K_LANG6 = {KEY_LANG6, false};                             // Disabled (Ubuntu)
_Key K_LANG7 = {KEY_LANG7, false};                             // Disabled (Ubuntu)
_Key K_LANG8 = {KEY_LANG8, false};                             // Disabled (Ubuntu)
_Key K_LANG9 = {KEY_LANG9, false};                             // Disabled (Ubuntu)
_Key K_ALTERNATE_ERASE = {KEY_ALTERNATE_ERASE, false};         // Disabled (Ubuntu)
_Key K_SYSREQ_ATTENTION = {KEY_SYSREQ_ATTENTION, false};       // Disabled (Ubuntu)
_Key K_CANCEL = {KEY_CANCEL, false};                           // Disabled (Ubuntu)
_Key K_CLEAR = {KEY_CLEAR, false};                             // Delete (Ubuntu)
_Key K_PRIOR = {KEY_PRIOR, false};                             // Disabled (Ubuntu)
_Key K_RETURN2 = {KEY_RETURN2, false};                         // Disabled (Ubuntu), Do not confuse this with KEY_ENTER
_Key K_SEPARATOR = {KEY_SEPARATOR, false};                     // Disabled (Ubuntu)
_Key K_OUT = {KEY_OUT, false};                                 // Disabled (Ubuntu)
_Key K_OPER = {KEY_OPER, false};                               // Disabled (Ubuntu)
_Key K_CLEAR_AGAIN = {KEY_CLEAR_AGAIN, false};                 // Disabled (Ubuntu)
_Key K_CRSEL_PROPS = {KEY_CRSEL_PROPS, false};                 // Disabled (Ubuntu)
_Key K_EXSEL = {KEY_EXSEL, false};                             // Disabled (Ubuntu)

_Key K_PAD_00 = {KEY_PAD_00, false};                             // Disabled (Ubuntu)
_Key K_PAD_000 = {KEY_PAD_000, false};                           // Disabled (Ubuntu)
_Key K_THOUSANDS_SEPARATOR = {KEY_THOUSANDS_SEPARATOR, false};   // Disabled (Ubuntu)
_Key K_DECIMAL_SEPARATOR = {KEY_DECIMAL_SEPARATOR, false};       // Disabled (Ubuntu)
_Key K_CURRENCY_UNIT = {KEY_CURRENCY_UNIT, false};               // Disabled (Ubuntu)
_Key K_CURRENCY_SUB_UNIT = {KEY_CURRENCY_SUB_UNIT, false};       // Disabled (Ubuntu)
_Key KPAD_LEFT_BRACE = {KEYPAD_LEFT_BRACE, false};               // (
_Key KPAD_RIGHT_BRACE = {KEYPAD_RIGHT_BRACE, false};             // )
_Key KPAD_LEFT_CURLY_BRACE = {KEYPAD_LEFT_CURLY_BRACE, false};   // Disabled (Ubuntu)
_Key KPAD_RIGHT_CURLY_BRACE = {KEYPAD_RIGHT_CURLY_BRACE, false}; // Disabled (Ubuntu)
_Key KPAD_TAB = {KEYPAD_TAB, false};                             // Disabled (Ubuntu)
_Key KPAD_BACKSPACE = {KEYPAD_BACKSPACE, false};                 // Disabled (Ubuntu)
_Key KPAD_A = {KEYPAD_A, false};                                 // Disabled (Ubuntu)
_Key KPAD_B = {KEYPAD_B, false};                                 // Disabled (Ubuntu)
_Key KPAD_C = {KEYPAD_C, false};                                 // Disabled (Ubuntu)
_Key KPAD_D = {KEYPAD_D, false};                                 // Disabled (Ubuntu)
_Key KPAD_E = {KEYPAD_E, false};                                 // Disabled (Ubuntu)
_Key KPAD_F = {KEYPAD_F, false};                                 // Disabled (Ubuntu)
_Key KPAD_XOR = {KEYPAD_XOR, false};                             // Disabled (Ubuntu)
_Key KPAD_CARET = {KEYPAD_CARET, false};                         // Disabled (Ubuntu)
_Key KPAD_PERCENT = {KEYPAD_PERCENT, false};                     // Disabled (Ubuntu)
_Key KPAD_LESS_THAN = {KEYPAD_LESS_THAN, false};                 // Disabled (Ubuntu)
_Key KPAD_GREATER_THAN = {KEYPAD_GREATER_THAN, false};           // Disabled (Ubuntu)
_Key KPAD_AMPERSAND = {KEYPAD_AMPERSAND, false};                 // Disabled (Ubuntu)
_Key KPAD_DOUBLEAMPERSAND = {KEYPAD_DOUBLEAMPERSAND, false};     // Disabled (Ubuntu)
_Key KPAD_PIPE = {KEYPAD_PIPE, false};                           // Disabled (Ubuntu)
_Key KPAD_DOUBLEPIPE = {KEYPAD_DOUBLEPIPE, false};               // Disabled (Ubuntu)
_Key KPAD_COLON = {KEYPAD_COLON, false};                         // Disabled (Ubuntu)
_Key KPAD_POUND_SIGN = {KEYPAD_POUND_SIGN, false};               // Disabled (Ubuntu)
_Key KPAD_SPACE = {KEYPAD_SPACE, false};                         // Disabled (Ubuntu)
_Key KPAD_AT_SIGN = {KEYPAD_AT_SIGN, false};                     // Disabled (Ubuntu)
_Key KPAD_EXCLAMATION_POINT = {KEYPAD_EXCLAMATION_POINT, false}; // Disabled (Ubuntu)
_Key KPAD_MEMORY_STORE = {KEYPAD_MEMORY_STORE, false};           // Disabled (Ubuntu)
_Key KPAD_MEMORY_RECALL = {KEYPAD_MEMORY_RECALL, false};         // Disabled (Ubuntu)
_Key KPAD_MEMORY_CLEAR = {KEYPAD_MEMORY_CLEAR, false};           // Disabled (Ubuntu)
_Key KPAD_MEMORY_ADD = {KEYPAD_MEMORY_ADD, false};               // Disabled (Ubuntu)
_Key KPAD_MEMORY_SUBTRACT = {KEYPAD_MEMORY_SUBTRACT, false};     // Disabled (Ubuntu)
_Key KPAD_MEMORY_MULTIPLY = {KEYPAD_MEMORY_MULTIPLY, false};     // Disabled (Ubuntu)
_Key KPAD_MEMORY_DIVIDE = {KEYPAD_MEMORY_DIVIDE, false};         // Disabled (Ubuntu)
_Key KPAD_PLUS_MINUS = {KEYPAD_PLUS_MINUS, false};               // Disabled (Ubuntu)
_Key KPAD_CLEAR = {KEYPAD_CLEAR, false};                         // Delete (Ubuntu)
_Key KPAD_CLEAR_ENTRY = {KEYPAD_CLEAR_ENTRY, false};             // Disabled (Ubuntu)
_Key KPAD_BINARY = {KEYPAD_BINARY, false};                       // Disabled (Ubuntu)
_Key KPAD_OCTAL = {KEYPAD_OCTAL, false};                         // Disabled (Ubuntu)
_Key KPAD_DECIMAL = {KEYPAD_DECIMAL, false};                     // Disabled (Ubuntu)
_Key KPAD_HEXADECIMAL = {KEYPAD_HEXADECIMAL, false};             // Disabled (Ubuntu)

_Key K_LEFT_CTRL = {KEY_LEFT_CTRL, false};
_Key K_LEFT_SHIFT = {KEY_LEFT_SHIFT, false};
_Key K_LEFT_ALT = {KEY_LEFT_ALT, false};
_Key K_LEFT_GUI = {KEY_LEFT_GUI, false};
_Key K_LEFT_WINDOWS = {KEY_LEFT_WINDOWS, false}; // Alias
_Key K_RIGHT_CTRL = {KEY_RIGHT_CTRL, false};
_Key K_RIGHT_SHIFT = {KEY_RIGHT_SHIFT, false};
_Key K_RIGHT_ALT = {KEY_RIGHT_ALT, false};
_Key K_RIGHT_GUI = {KEY_RIGHT_GUI, false};
_Key K_RIGHT_WINDOWS = {KEY_RIGHT_WINDOWS, false}; // Alias

// Keyboard HID mappings

//  Reserved (no_event_indicated)
_Key _HID_KEYBOARD_ERROR_ROLLOVER = {HID_KEYBOARD_ERROR_ROLLOVER, false};
_Key _HID_KEYBOARD_POST_FAIL = {HID_KEYBOARD_POST_FAIL, false};
_Key _HID_KEYBOARD_ERROR_UNDEFINED = {HID_KEYBOARD_ERROR_UNDEFINED, false};
_Key _HID_KEYBOARD_A_AND_A = {HID_KEYBOARD_A_AND_A, false};
_Key _HID_KEYBOARD_B_AND_B = {HID_KEYBOARD_B_AND_B, false};
_Key _HID_KEYBOARD_C_AND_C = {HID_KEYBOARD_C_AND_C, false};
_Key _HID_KEYBOARD_D_AND_D = {HID_KEYBOARD_D_AND_D, false};
_Key _HID_KEYBOARD_E_AND_E = {HID_KEYBOARD_E_AND_E, false};
_Key _HID_KEYBOARD_F_AND_F = {HID_KEYBOARD_F_AND_F, false};
_Key _HID_KEYBOARD_G_AND_G = {HID_KEYBOARD_G_AND_G, false};
_Key _HID_KEYBOARD_H_AND_H = {HID_KEYBOARD_H_AND_H, false};
_Key _HID_KEYBOARD_I_AND_I = {HID_KEYBOARD_I_AND_I, false};
_Key _HID_KEYBOARD_J_AND_J = {HID_KEYBOARD_J_AND_J, false};
_Key _HID_KEYBOARD_K_AND_K = {HID_KEYBOARD_K_AND_K, false};
_Key _HID_KEYBOARD_L_AND_L = {HID_KEYBOARD_L_AND_L, false};
_Key _HID_KEYBOARD_M_AND_M = {HID_KEYBOARD_M_AND_M, false};
_Key _HID_KEYBOARD_N_AND_N = {HID_KEYBOARD_N_AND_N, false};
_Key _HID_KEYBOARD_O_AND_O = {HID_KEYBOARD_O_AND_O, false};
_Key _HID_KEYBOARD_P_AND_P = {HID_KEYBOARD_P_AND_P, false};
_Key _HID_KEYBOARD_Q_AND_Q = {HID_KEYBOARD_Q_AND_Q, false};
_Key _HID_KEYBOARD_R_AND_R = {HID_KEYBOARD_R_AND_R, false};
_Key _HID_KEYBOARD_S_AND_S = {HID_KEYBOARD_S_AND_S, false};
_Key _HID_KEYBOARD_T_AND_T = {HID_KEYBOARD_T_AND_T, false};
_Key _HID_KEYBOARD_U_AND_U = {HID_KEYBOARD_U_AND_U, false};
_Key _HID_KEYBOARD_V_AND_V = {HID_KEYBOARD_V_AND_V, false};
_Key _HID_KEYBOARD_W_AND_W = {HID_KEYBOARD_W_AND_W, false};
_Key _HID_KEYBOARD_X_AND_X = {HID_KEYBOARD_X_AND_X, false};
_Key _HID_KEYBOARD_Y_AND_Y = {HID_KEYBOARD_Y_AND_Y, false};
_Key _HID_KEYBOARD_Z_AND_Z = {HID_KEYBOARD_Z_AND_Z, false};
_Key _HID_KEYBOARD_1_AND_EXCLAMATION_POINT = {HID_KEYBOARD_1_AND_EXCLAMATION_POINT, false};
_Key _HID_KEYBOARD_2_AND_AT = {HID_KEYBOARD_2_AND_AT, false};
_Key _HID_KEYBOARD_3_AND_POUND = {HID_KEYBOARD_3_AND_POUND, false};
_Key _HID_KEYBOARD_4_AND_DOLLAR = {HID_KEYBOARD_4_AND_DOLLAR, false};
_Key _HID_KEYBOARD_5_AND_PERCENT = {HID_KEYBOARD_5_AND_PERCENT, false};
_Key _HID_KEYBOARD_6_AND_CARAT = {HID_KEYBOARD_6_AND_CARAT, false};
_Key _HID_KEYBOARD_7_AND_AMPERSAND = {HID_KEYBOARD_7_AND_AMPERSAND, false};
_Key _HID_KEYBOARD_8_AND_ASTERISK = {HID_KEYBOARD_8_AND_ASTERISK, false};
_Key _HID_KEYBOARD_9_AND_LEFT_PAREN = {HID_KEYBOARD_9_AND_LEFT_PAREN, false};
_Key _HID_KEYBOARD_0_AND_RIGHT_PAREN = {HID_KEYBOARD_0_AND_RIGHT_PAREN, false};
_Key _HID_KEYBOARD_ENTER = {HID_KEYBOARD_ENTER, false}; // (MARKED AS ENTER_SLASH_RETURN)
_Key _HID_KEYBOARD_ESCAPE = {HID_KEYBOARD_ESCAPE, false};
_Key _HID_KEYBOARD_DELETE = {HID_KEYBOARD_DELETE, false}; // (BACKSPACE)
_Key _HID_KEYBOARD_TAB = {HID_KEYBOARD_TAB, false};
_Key _HID_KEYBOARD_SPACEBAR = {HID_KEYBOARD_SPACEBAR, false};
_Key _HID_KEYBOARD_MINUS_AND_UNDERSCORE = {HID_KEYBOARD_MINUS_AND_UNDERSCORE, false}; // (UNDERSCORE)
_Key _HID_KEYBOARD_EQUALS_AND_PLUS = {HID_KEYBOARD_EQUALS_AND_PLUS, false};
_Key _HID_KEYBOARD_LEFT_BRACKET_AND_LEFT_CURLY_BRACE = {HID_KEYBOARD_LEFT_BRACKET_AND_LEFT_CURLY_BRACE, false};
_Key _HID_KEYBOARD_RIGHT_BRACKET_AND_RIGHT_CURLY_BRACE = {HID_KEYBOARD_RIGHT_BRACKET_AND_RIGHT_CURLY_BRACE, false};
_Key _HID_KEYBOARD_BACKSLASH_AND_PIPE = {HID_KEYBOARD_BACKSLASH_AND_PIPE, false};
_Key _HID_KEYBOARD_NON_US_POUND_AND_TILDE = {HID_KEYBOARD_NON_US_POUND_AND_TILDE, false};
_Key _HID_KEYBOARD_SEMICOLON_AND_COLON = {HID_KEYBOARD_SEMICOLON_AND_COLON, false};
_Key _HID_KEYBOARD_QUOTE_AND_DOUBLEQUOTE = {HID_KEYBOARD_QUOTE_AND_DOUBLEQUOTE, false};
_Key _HID_KEYBOARD_GRAVE_ACCENT_AND_TILDE = {HID_KEYBOARD_GRAVE_ACCENT_AND_TILDE, false};
_Key _HID_KEYBOARD_COMMA_AND_LESS_THAN = {HID_KEYBOARD_COMMA_AND_LESS_THAN, false};
_Key _HID_KEYBOARD_PERIOD_AND_GREATER_THAN = {HID_KEYBOARD_PERIOD_AND_GREATER_THAN, false};
_Key _HID_KEYBOARD_SLASH_AND_QUESTION_MARK = {HID_KEYBOARD_SLASH_AND_QUESTION_MARK, false};
_Key _HID_KEYBOARD_CAPS_LOCK = {HID_KEYBOARD_CAPS_LOCK, false};
_Key _HID_KEYBOARD_F1 = {HID_KEYBOARD_F1, false};
_Key _HID_KEYBOARD_F2 = {HID_KEYBOARD_F2, false};
_Key _HID_KEYBOARD_F3 = {HID_KEYBOARD_F3, false};
_Key _HID_KEYBOARD_F4 = {HID_KEYBOARD_F4, false};
_Key _HID_KEYBOARD_F5 = {HID_KEYBOARD_F5, false};
_Key _HID_KEYBOARD_F6 = {HID_KEYBOARD_F6, false};
_Key _HID_KEYBOARD_F7 = {HID_KEYBOARD_F7, false};
_Key _HID_KEYBOARD_F8 = {HID_KEYBOARD_F8, false};
_Key _HID_KEYBOARD_F9 = {HID_KEYBOARD_F9, false};
_Key _HID_KEYBOARD_F10 = {HID_KEYBOARD_F10, false};
_Key _HID_KEYBOARD_F11 = {HID_KEYBOARD_F11, false};
_Key _HID_KEYBOARD_F12 = {HID_KEYBOARD_F12, false};
_Key _HID_KEYBOARD_PRINTSCREEN = {HID_KEYBOARD_PRINTSCREEN, false};
_Key _HID_KEYBOARD_SCROLL_LOCK = {HID_KEYBOARD_SCROLL_LOCK, false};
_Key _HID_KEYBOARD_PAUSE = {HID_KEYBOARD_PAUSE, false};
_Key _HID_KEYBOARD_INSERT = {HID_KEYBOARD_INSERT, false};
_Key _HID_KEYBOARD_HOME = {HID_KEYBOARD_HOME, false};
_Key _HID_KEYBOARD_PAGE_UP = {HID_KEYBOARD_PAGE_UP, false};
_Key _HID_KEYBOARD_DELETE_FORWARD = {HID_KEYBOARD_DELETE_FORWARD, false};
_Key _HID_KEYBOARD_END = {HID_KEYBOARD_END, false};
_Key _HID_KEYBOARD_PAGE_DOWN = {HID_KEYBOARD_PAGE_DOWN, false};
_Key _HID_KEYBOARD_RIGHTARROW = {HID_KEYBOARD_RIGHTARROW, false};
_Key _HID_KEYBOARD_LEFTARROW = {HID_KEYBOARD_LEFTARROW, false};
_Key _HID_KEYBOARD_DOWNARROW = {HID_KEYBOARD_DOWNARROW, false};
_Key _HID_KEYBOARD_UPARROW = {HID_KEYBOARD_UPARROW, false};
_Key _HID_KEYPAD_NUM_LOCK_AND_CLEAR = {HID_KEYPAD_NUM_LOCK_AND_CLEAR, false};
_Key _HID_KEYPAD_DIVIDE = {HID_KEYPAD_DIVIDE, false};
_Key _HID_KEYPAD_MULTIPLY = {HID_KEYPAD_MULTIPLY, false};
_Key _HID_KEYPAD_SUBTRACT = {HID_KEYPAD_SUBTRACT, false};
_Key _HID_KEYPAD_ADD = {HID_KEYPAD_ADD, false};
_Key _HID_KEYPAD_ENTER = {HID_KEYPAD_ENTER, false};
_Key _HID_KEYPAD_1_AND_END = {HID_KEYPAD_1_AND_END, false};
_Key _HID_KEYPAD_2_AND_DOWN_ARROW = {HID_KEYPAD_2_AND_DOWN_ARROW, false};
_Key _HID_KEYPAD_3_AND_PAGE_DOWN = {HID_KEYPAD_3_AND_PAGE_DOWN, false};
_Key _HID_KEYPAD_4_AND_LEFT_ARROW = {HID_KEYPAD_4_AND_LEFT_ARROW, false};
_Key _HID_KEYPAD_5 = {HID_KEYPAD_5, false};
_Key _HID_KEYPAD_6_AND_RIGHT_ARROW = {HID_KEYPAD_6_AND_RIGHT_ARROW, false};
_Key _HID_KEYPAD_7_AND_HOME = {HID_KEYPAD_7_AND_HOME, false};
_Key _HID_KEYPAD_8_AND_UP_ARROW = {HID_KEYPAD_8_AND_UP_ARROW, false};
_Key _HID_KEYPAD_9_AND_PAGE_UP = {HID_KEYPAD_9_AND_PAGE_UP, false};
_Key _HID_KEYPAD_0_AND_INSERT = {HID_KEYPAD_0_AND_INSERT, false};
_Key _HID_KEYPAD_PERIOD_AND_DELETE = {HID_KEYPAD_PERIOD_AND_DELETE, false};
_Key _HID_KEYBOARD_NON_US_BACKSLASH_AND_PIPE = {HID_KEYBOARD_NON_US_BACKSLASH_AND_PIPE, false};
_Key _HID_KEYBOARD_APPLICATION = {HID_KEYBOARD_APPLICATION, false};
_Key _HID_KEYBOARD_POWER = {HID_KEYBOARD_POWER, false};
_Key _HID_KEYPAD_EQUALS = {HID_KEYPAD_EQUALS, false};
_Key _HID_KEYBOARD_F13 = {HID_KEYBOARD_F13, false};
_Key _HID_KEYBOARD_F14 = {HID_KEYBOARD_F14, false};
_Key _HID_KEYBOARD_F15 = {HID_KEYBOARD_F15, false};
_Key _HID_KEYBOARD_F16 = {HID_KEYBOARD_F16, false};
_Key _HID_KEYBOARD_F17 = {HID_KEYBOARD_F17, false};
_Key _HID_KEYBOARD_F18 = {HID_KEYBOARD_F18, false};
_Key _HID_KEYBOARD_F19 = {HID_KEYBOARD_F19, false};
_Key _HID_KEYBOARD_F20 = {HID_KEYBOARD_F20, false};
_Key _HID_KEYBOARD_F21 = {HID_KEYBOARD_F21, false};
_Key _HID_KEYBOARD_F22 = {HID_KEYBOARD_F22, false};
_Key _HID_KEYBOARD_F23 = {HID_KEYBOARD_F23, false};
_Key _HID_KEYBOARD_F24 = {HID_KEYBOARD_F24, false};
_Key _HID_KEYBOARD_EXECUTE = {HID_KEYBOARD_EXECUTE, false};
_Key _HID_KEYBOARD_HELP = {HID_KEYBOARD_HELP, false};
_Key _HID_KEYBOARD_MENU = {HID_KEYBOARD_MENU, false};
_Key _HID_KEYBOARD_SELECT = {HID_KEYBOARD_SELECT, false};
_Key _HID_KEYBOARD_STOP = {HID_KEYBOARD_STOP, false};
_Key _HID_KEYBOARD_AGAIN = {HID_KEYBOARD_AGAIN, false};
_Key _HID_KEYBOARD_UNDO = {HID_KEYBOARD_UNDO, false};
_Key _HID_KEYBOARD_CUT = {HID_KEYBOARD_CUT, false};
_Key _HID_KEYBOARD_COPY = {HID_KEYBOARD_COPY, false};
_Key _HID_KEYBOARD_PASTE = {HID_KEYBOARD_PASTE, false};
_Key _HID_KEYBOARD_FIND = {HID_KEYBOARD_FIND, false};
_Key _HID_KEYBOARD_MUTE = {HID_KEYBOARD_MUTE, false};
_Key _HID_KEYBOARD_VOLUME_UP = {HID_KEYBOARD_VOLUME_UP, false};
_Key _HID_KEYBOARD_VOLUME_DOWN = {HID_KEYBOARD_VOLUME_DOWN, false};
_Key _HID_KEYBOARD_LOCKING_CAPS_LOCK = {HID_KEYBOARD_LOCKING_CAPS_LOCK, false};
_Key _HID_KEYBOARD_LOCKING_NUM_LOCK = {HID_KEYBOARD_LOCKING_NUM_LOCK, false};
_Key _HID_KEYBOARD_LOCKING_SCROLL_LOCK = {HID_KEYBOARD_LOCKING_SCROLL_LOCK, false};
_Key _HID_KEYPAD_COMMA = {HID_KEYPAD_COMMA, false};
_Key _HID_KEYPAD_EQUAL_SIGN = {HID_KEYPAD_EQUAL_SIGN, false};
_Key _HID_KEYBOARD_INTERNATIONAL1 = {HID_KEYBOARD_INTERNATIONAL1, false};
_Key _HID_KEYBOARD_INTERNATIONAL2 = {HID_KEYBOARD_INTERNATIONAL2, false};
_Key _HID_KEYBOARD_INTERNATIONAL3 = {HID_KEYBOARD_INTERNATIONAL3, false};
_Key _HID_KEYBOARD_INTERNATIONAL4 = {HID_KEYBOARD_INTERNATIONAL4, false};
_Key _HID_KEYBOARD_INTERNATIONAL5 = {HID_KEYBOARD_INTERNATIONAL5, false};
_Key _HID_KEYBOARD_INTERNATIONAL6 = {HID_KEYBOARD_INTERNATIONAL6, false};
_Key _HID_KEYBOARD_INTERNATIONAL7 = {HID_KEYBOARD_INTERNATIONAL7, false};
_Key _HID_KEYBOARD_INTERNATIONAL8 = {HID_KEYBOARD_INTERNATIONAL8, false};
_Key _HID_KEYBOARD_INTERNATIONAL9 = {HID_KEYBOARD_INTERNATIONAL9, false};
_Key _HID_KEYBOARD_LANG1 = {HID_KEYBOARD_LANG1, false};
_Key _HID_KEYBOARD_LANG2 = {HID_KEYBOARD_LANG2, false};
_Key _HID_KEYBOARD_LANG3 = {HID_KEYBOARD_LANG3, false};
_Key _HID_KEYBOARD_LANG4 = {HID_KEYBOARD_LANG4, false};
_Key _HID_KEYBOARD_LANG5 = {HID_KEYBOARD_LANG5, false};
_Key _HID_KEYBOARD_LANG6 = {HID_KEYBOARD_LANG6, false};
_Key _HID_KEYBOARD_LANG7 = {HID_KEYBOARD_LANG7, false};
_Key _HID_KEYBOARD_LANG8 = {HID_KEYBOARD_LANG8, false};
_Key _HID_KEYBOARD_LANG9 = {HID_KEYBOARD_LANG9, false};
_Key _HID_KEYBOARD_ALTERNATE_ERASE = {HID_KEYBOARD_ALTERNATE_ERASE, false};
_Key _HID_KEYBOARD_SYSREQ_SLASH_ATTENTION = {HID_KEYBOARD_SYSREQ_SLASH_ATTENTION, false};
_Key _HID_KEYBOARD_CANCEL = {HID_KEYBOARD_CANCEL, false};
_Key _HID_KEYBOARD_CLEAR = {HID_KEYBOARD_CLEAR, false};
_Key _HID_KEYBOARD_PRIOR = {HID_KEYBOARD_PRIOR, false};
_Key _HID_KEYBOARD_RETURN = {HID_KEYBOARD_RETURN, false};
_Key _HID_KEYBOARD_SEPARATOR = {HID_KEYBOARD_SEPARATOR, false};
_Key _HID_KEYBOARD_OUT = {HID_KEYBOARD_OUT, false};
_Key _HID_KEYBOARD_OPER = {HID_KEYBOARD_OPER, false};
_Key _HID_KEYBOARD_CLEAR_SLASH_AGAIN = {HID_KEYBOARD_CLEAR_SLASH_AGAIN, false};
_Key _HID_KEYBOARD_CRSEL_SLASH_PROPS = {HID_KEYBOARD_CRSEL_SLASH_PROPS, false};
_Key _HID_KEYBOARD_EXSEL = {HID_KEYBOARD_EXSEL, false};
// Reserved 0xA5-AF
_Key _HID_KEYPAD_00 = {HID_KEYPAD_00, false};
_Key _HID_KEYPAD_000 = {HID_KEYPAD_000, false};
_Key _HID_THOUSANDS_SEPARATOR = {HID_THOUSANDS_SEPARATOR, false};
_Key _HID_DECIMAL_SEPARATOR = {HID_DECIMAL_SEPARATOR, false};
_Key _HID_CURRENCY_UNIT = {HID_CURRENCY_UNIT, false};
_Key _HID_CURRENCY_SUBUNIT = {HID_CURRENCY_SUBUNIT, false};
_Key _HID_KEYPAD_LEFT_PAREN = {HID_KEYPAD_LEFT_PAREN, false};
_Key _HID_KEYPAD_RIGHT_PAREN = {HID_KEYPAD_RIGHT_PAREN, false};
_Key _HID_KEYPAD_LEFT_CURLY_BRACE = {HID_KEYPAD_LEFT_CURLY_BRACE, false};
_Key _HID_KEYPAD_RIGHT_CURLY_BRACE = {HID_KEYPAD_RIGHT_CURLY_BRACE, false};
_Key _HID_KEYPAD_TAB = {HID_KEYPAD_TAB, false};
_Key _HID_KEYPAD_BACKSPACE = {HID_KEYPAD_BACKSPACE, false};
_Key _HID_KEYPAD_A = {HID_KEYPAD_A, false};
_Key _HID_KEYPAD_B = {HID_KEYPAD_B, false};
_Key _HID_KEYPAD_C = {HID_KEYPAD_C, false};
_Key _HID_KEYPAD_D = {HID_KEYPAD_D, false};
_Key _HID_KEYPAD_E = {HID_KEYPAD_E, false};
_Key _HID_KEYPAD_F = {HID_KEYPAD_F, false};
_Key _HID_KEYPAD_XOR = {HID_KEYPAD_XOR, false};
_Key _HID_KEYPAD_CARAT = {HID_KEYPAD_CARAT, false};
_Key _HID_KEYPAD_PERCENT = {HID_KEYPAD_PERCENT, false};
_Key _HID_KEYPAD_LESS_THAN = {HID_KEYPAD_LESS_THAN, false};
_Key _HID_KEYPAD_GREATER_THAN = {HID_KEYPAD_GREATER_THAN, false};
_Key _HID_KEYPAD_AMPERSAND = {HID_KEYPAD_AMPERSAND, false};
_Key _HID_KEYPAD_DOUBLEAMPERSAND = {HID_KEYPAD_DOUBLEAMPERSAND, false};
_Key _HID_KEYPAD_PIPE = {HID_KEYPAD_PIPE, false};
_Key _HID_KEYPAD_DOUBLEPIPE = {HID_KEYPAD_DOUBLEPIPE, false};
_Key _HID_KEYPAD_COLON = {HID_KEYPAD_COLON, false};
_Key _HID_KEYPAD_POUND_SIGN = {HID_KEYPAD_POUND_SIGN, false};
_Key _HID_KEYPAD_SPACE = {HID_KEYPAD_SPACE, false};
_Key _HID_KEYPAD_AT_SIGN = {HID_KEYPAD_AT_SIGN, false};
_Key _HID_KEYPAD_EXCLAMATION_POINT = {HID_KEYPAD_EXCLAMATION_POINT, false};
_Key _HID_KEYPAD_MEMORY_STORE = {HID_KEYPAD_MEMORY_STORE, false};
_Key _HID_KEYPAD_MEMORY_RECALL = {HID_KEYPAD_MEMORY_RECALL, false};
_Key _HID_KEYPAD_MEMORY_CLEAR = {HID_KEYPAD_MEMORY_CLEAR, false};
_Key _HID_KEYPAD_MEMORY_ADD = {HID_KEYPAD_MEMORY_ADD, false};
_Key _HID_KEYPAD_MEMORY_SUBTRACT = {HID_KEYPAD_MEMORY_SUBTRACT, false};
_Key _HID_KEYPAD_MEMORY_MULTIPLY = {HID_KEYPAD_MEMORY_MULTIPLY, false};
_Key _HID_KEYPAD_MEMORY_DIVIDE = {HID_KEYPAD_MEMORY_DIVIDE, false};
_Key _HID_KEYPAD_PLUS_SLASH_MINUS = {HID_KEYPAD_PLUS_SLASH_MINUS, false};
_Key _HID_KEYPAD_CLEAR = {HID_KEYPAD_CLEAR, false};
_Key _HID_KEYPAD_CLEAR_ENTRY = {HID_KEYPAD_CLEAR_ENTRY, false};
_Key _HID_KEYPAD_BINARY = {HID_KEYPAD_BINARY, false};
_Key _HID_KEYPAD_OCTAL = {HID_KEYPAD_OCTAL, false};
_Key _HID_KEYPAD_DECIMAL = {HID_KEYPAD_DECIMAL, false};
_Key _HID_KEYPAD_HEXADECIMAL = {HID_KEYPAD_HEXADECIMAL, false};

//  0xDE-0xDF    - RESERVED
_Key _HID_KEYBOARD_LEFT_CONTROL = {HID_KEYBOARD_LEFT_CONTROL, false};
_Key _HID_KEYBOARD_LEFT_SHIFT = {HID_KEYBOARD_LEFT_SHIFT, false};
_Key _HID_KEYBOARD_LEFT_ALT = {HID_KEYBOARD_LEFT_ALT, false};
_Key _HID_KEYBOARD_LEFT_GUI = {HID_KEYBOARD_LEFT_GUI, false};
_Key _HID_KEYBOARD_RIGHT_CONTROL = {HID_KEYBOARD_RIGHT_CONTROL, false};
_Key _HID_KEYBOARD_RIGHT_SHIFT = {HID_KEYBOARD_RIGHT_SHIFT, false};
_Key _HID_KEYBOARD_RIGHT_ALT = {HID_KEYBOARD_RIGHT_ALT, false};
_Key _HID_KEYBOARD_RIGHT_GUI = {HID_KEYBOARD_RIGHT_GUI, false};

// MEDIA KEYS

_Key M_CONSUMER_POWER = {CONSUMER_POWER, true};
_Key M_CONSUMER_SLEEP = {CONSUMER_SLEEP, true};

_Key M_RECORD = {MEDIA_RECORD, true};
_Key M_FAST_FORWARD = {MEDIA_FAST_FORWARD, true};
_Key M_REWIND = {MEDIA_REWIND, true};
_Key M_NEXT = {MEDIA_NEXT, true};
_Key M_PREVIOUS = {MEDIA_PREVIOUS, true};
_Key M_PREV = {MEDIA_PREV, true}; // Alias
_Key M_STOP = {MEDIA_STOP, true};
_Key M_PLAY_PAUSE = {MEDIA_PLAY_PAUSE, true};
_Key M_PAUSE = {MEDIA_PAUSE, true};

_Key M_VOLUME_MUTE = {MEDIA_VOLUME_MUTE, true};
_Key M_VOL_MUTE = {MEDIA_VOL_MUTE, true}; // Alias
_Key M_VOLUME_UP = {MEDIA_VOLUME_UP, true};
_Key M_VOL_UP = {MEDIA_VOL_UP, true}; // Alias
_Key M_VOLUME_DOWN = {MEDIA_VOLUME_DOWN, true};
_Key M_VOL_DOWN = {MEDIA_VOL_DOWN, true}; // Alias

_Key M_CONSUMER_BRIGHTNESS_UP = {CONSUMER_BRIGHTNESS_UP, true};
_Key M_CONSUMER_BRIGHTNESS_DOWN = {CONSUMER_BRIGHTNESS_DOWN, true};

_Key M_CONSUMER_SCREENSAVER = {CONSUMER_SCREENSAVER, true};

_Key M_CONSUMER_PROGRAMMABLE_BUTTON_CONFIGURATION = {CONSUMER_PROGRAMMABLE_BUTTON_CONFIGURATION, true};
_Key M_CONSUMER_CONTROL_CONFIGURATION = {CONSUMER_CONTROL_CONFIGURATION, true};
_Key M_CONSUMER_EMAIL_READER = {CONSUMER_EMAIL_READER, true};
_Key M_CONSUMER_CALCULATOR = {CONSUMER_CALCULATOR, true};
_Key M_CONSUMER_EXPLORER = {CONSUMER_EXPLORER, true};

_Key M_CONSUMER_BROWSER_HOME = {CONSUMER_BROWSER_HOME, true};
_Key M_CONSUMER_BROWSER_BACK = {CONSUMER_BROWSER_BACK, true};
_Key M_CONSUMER_BROWSER_FORWARD = {CONSUMER_BROWSER_FORWARD, true};
_Key M_CONSUMER_BROWSER_REFRESH = {CONSUMER_BROWSER_REFRESH, true};
_Key M_CONSUMER_BROWSER_BOOKMARKS = {CONSUMER_BROWSER_BOOKMARKS, true};

// Consumer_Page_(0x0C)	0x15
_Key M_HID_CONSUMER_UNASSIGNED = {HID_CONSUMER_UNASSIGNED, true};
_Key M_HID_CONSUMER_NUMERIC_KEY_PAD = {HID_CONSUMER_NUMERIC_KEY_PAD, true};           // HID type NARY
_Key M_HID_CONSUMER_PROGRAMMABLE_BUTTONS = {HID_CONSUMER_PROGRAMMABLE_BUTTONS, true}; // HID type NARY
_Key M_HID_CONSUMER_MICROPHONE_CA = {HID_CONSUMER_MICROPHONE_CA, true};
_Key M_HID_CONSUMER_HEADPHONE_CA = {HID_CONSUMER_HEADPHONE_CA, true};
_Key M_HID_CONSUMER_GRAPHIC_EQUALIZER_CA = {HID_CONSUMER_GRAPHIC_EQUALIZER_CA, true};
// Reserved	= 0x07-1F
_Key M_HID_CONSUMER_PLUS_10 = {HID_CONSUMER_PLUS_10, true};         // HID type OSC
_Key M_HID_CONSUMER_PLUS_100 = {HID_CONSUMER_PLUS_100, true};       // HID type OSC
_Key M_HID_CONSUMER_AM_SLASH_PM = {HID_CONSUMER_AM_SLASH_PM, true}; // HID type OSC
// Reserved	= 0x23-3F
_Key M_HID_CONSUMER_POWER = {HID_CONSUMER_POWER, true};                       // HID type OOC
_Key M_HID_CONSUMER_RESET = {HID_CONSUMER_RESET, true};                       // HID type OSC
_Key M_HID_CONSUMER_SLEEP = {HID_CONSUMER_SLEEP, true};                       // HID type OSC
_Key M_HID_CONSUMER_SLEEP_AFTER = {HID_CONSUMER_SLEEP_AFTER, true};           // HID type OSC
_Key M_HID_CONSUMER_SLEEP_MODE = {HID_CONSUMER_SLEEP_MODE, true};             // HID type RTC
_Key M_HID_CONSUMER_ILLUMINATION = {HID_CONSUMER_ILLUMINATION, true};         // HID type OOC
_Key M_HID_CONSUMER_FUNCTION_BUTTONS = {HID_CONSUMER_FUNCTION_BUTTONS, true}; // HID type NARY
// Reserved	= 0x37-3F
_Key M_HID_CONSUMER_MENU = {HID_CONSUMER_MENU, true};                               // HID type OOC
_Key M_HID_CONSUMER_MENU_PICK = {HID_CONSUMER_MENU_PICK, true};                     // HID type OSC
_Key M_HID_CONSUMER_MENU_UP = {HID_CONSUMER_MENU_UP, true};                         // HID type OSC
_Key M_HID_CONSUMER_MENU_DOWN = {HID_CONSUMER_MENU_DOWN, true};                     // HID type OSC
_Key M_HID_CONSUMER_MENU_LEFT = {HID_CONSUMER_MENU_LEFT, true};                     // HID type OSC
_Key M_HID_CONSUMER_MENU_RIGHT = {HID_CONSUMER_MENU_RIGHT, true};                   // HID type OSC
_Key M_HID_CONSUMER_MENU_ESCAPE = {HID_CONSUMER_MENU_ESCAPE, true};                 // HID type OSC
_Key M_HID_CONSUMER_MENU_VALUE_INCREASE = {HID_CONSUMER_MENU_VALUE_INCREASE, true}; // HID type OSC
_Key M_HID_CONSUMER_MENU_VALUE_DECREASE = {HID_CONSUMER_MENU_VALUE_DECREASE, true}; // HID type OSC
// Reserved 0x49-5F
_Key M_HID_CONSUMER_DATA_ON_SCREEN = {HID_CONSUMER_DATA_ON_SCREEN, true};               // HID type OOC
_Key M_HID_CONSUMER_CLOSED_CAPTION = {HID_CONSUMER_CLOSED_CAPTION, true};               // HID type OOC
_Key M_HID_CONSUMER_CLOSED_CAPTION_SELECT = {HID_CONSUMER_CLOSED_CAPTION_SELECT, true}; // HID type OSC
_Key M_HID_CONSUMER_VCR_SLASH_TV = {HID_CONSUMER_VCR_SLASH_TV, true};                   // HID type OOC
_Key M_HID_CONSUMER_BROADCAST_MODE = {HID_CONSUMER_BROADCAST_MODE, true};               // HID type OSC
_Key M_HID_CONSUMER_SNAPSHOT = {HID_CONSUMER_SNAPSHOT, true};                           // HID type OSC
_Key M_HID_CONSUMER_STILL = {HID_CONSUMER_STILL, true};                                 // HID type OSC
// Reserved 0x67-7F
_Key M_HID_CONSUMER_SELECTION = {HID_CONSUMER_SELECTION, true};                                   // HID type NARY
_Key M_HID_CONSUMER_ASSIGN_SELECTION = {HID_CONSUMER_ASSIGN_SELECTION, true};                     // HID type OSC
_Key M_HID_CONSUMER_MODE_STEP = {HID_CONSUMER_MODE_STEP, true};                                   // HID type OSC
_Key M_HID_CONSUMER_RECALL_LAST = {HID_CONSUMER_RECALL_LAST, true};                               // HID type OSC
_Key M_HID_CONSUMER_ENTER_CHANNEL = {HID_CONSUMER_ENTER_CHANNEL, true};                           // HID type OSC
_Key M_HID_CONSUMER_ORDER_MOVIE = {HID_CONSUMER_ORDER_MOVIE, true};                               // HID type OSC
_Key M_HID_CONSUMER_CHANNEL = {HID_CONSUMER_CHANNEL, true};                                       // HID type LC
_Key M_HID_CONSUMER_MEDIA_SELECTION = {HID_CONSUMER_MEDIA_SELECTION, true};                       // HID type NARY
_Key M_HID_CONSUMER_MEDIA_SELECT_COMPUTER = {HID_CONSUMER_MEDIA_SELECT_COMPUTER, true};           // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_TV = {HID_CONSUMER_MEDIA_SELECT_TV, true};                       // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_WWW = {HID_CONSUMER_MEDIA_SELECT_WWW, true};                     // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_DVD = {HID_CONSUMER_MEDIA_SELECT_DVD, true};                     // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_TELEPHONE = {HID_CONSUMER_MEDIA_SELECT_TELEPHONE, true};         // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_PROGRAM_GUIDE = {HID_CONSUMER_MEDIA_SELECT_PROGRAM_GUIDE, true}; // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_VIDEO_PHONE = {HID_CONSUMER_MEDIA_SELECT_VIDEO_PHONE, true};     // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_GAMES = {HID_CONSUMER_MEDIA_SELECT_GAMES, true};                 // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_MESSAGES = {HID_CONSUMER_MEDIA_SELECT_MESSAGES, true};           // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_CD = {HID_CONSUMER_MEDIA_SELECT_CD, true};                       // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_VCR = {HID_CONSUMER_MEDIA_SELECT_VCR, true};                     // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_TUNER = {HID_CONSUMER_MEDIA_SELECT_TUNER, true};                 // HID type SEL
_Key M_HID_CONSUMER_QUIT = {HID_CONSUMER_QUIT, true};                                             // HID type OSC
_Key M_HID_CONSUMER_HELP = {HID_CONSUMER_HELP, true};                                             // HID type OOC
_Key M_HID_CONSUMER_MEDIA_SELECT_TAPE = {HID_CONSUMER_MEDIA_SELECT_TAPE, true};                   // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_CABLE = {HID_CONSUMER_MEDIA_SELECT_CABLE, true};                 // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_SATELLITE = {HID_CONSUMER_MEDIA_SELECT_SATELLITE, true};         // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_SECURITY = {HID_CONSUMER_MEDIA_SELECT_SECURITY, true};           // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_HOME = {HID_CONSUMER_MEDIA_SELECT_HOME, true};                   // HID type SEL
_Key M_HID_CONSUMER_MEDIA_SELECT_CALL = {HID_CONSUMER_MEDIA_SELECT_CALL, true};                   // HID type SEL
_Key M_HID_CONSUMER_CHANNEL_INCREMENT = {HID_CONSUMER_CHANNEL_INCREMENT, true};                   // HID type OSC
_Key M_HID_CONSUMER_CHANNEL_DECREMENT = {HID_CONSUMER_CHANNEL_DECREMENT, true};                   // HID type OSC
_Key M_HID_CONSUMER_MEDIA_SELECT_SAP = {HID_CONSUMER_MEDIA_SELECT_SAP, true};                     // HID type SEL
// Reserved 0x9F
_Key M_HID_CONSUMER_VCR_PLUS = {HID_CONSUMER_VCR_PLUS, true}; // HID type OSC
_Key M_HID_CONSUMER_ONCE = {HID_CONSUMER_ONCE, true};         // HID type OSC
_Key M_HID_CONSUMER_DAILY = {HID_CONSUMER_DAILY, true};       // HID type OSC
_Key M_HID_CONSUMER_WEEKLY = {HID_CONSUMER_WEEKLY, true};     // HID type OSC
_Key M_HID_CONSUMER_MONTHLY = {HID_CONSUMER_MONTHLY, true};   // HID type OSC
// Reserved 0xA5-AF
_Key M_HID_CONSUMER_PLAY = {HID_CONSUMER_PLAY, true};                               // HID type OOC
_Key M_HID_CONSUMER_PAUSE = {HID_CONSUMER_PAUSE, true};                             // HID type OOC
_Key M_HID_CONSUMER_RECORD = {HID_CONSUMER_RECORD, true};                           // HID type OOC
_Key M_HID_CONSUMER_FAST_FORWARD = {HID_CONSUMER_FAST_FORWARD, true};               // HID type OOC
_Key M_HID_CONSUMER_REWIND = {HID_CONSUMER_REWIND, true};                           // HID type OOC
_Key M_HID_CONSUMER_SCAN_NEXT_TRACK = {HID_CONSUMER_SCAN_NEXT_TRACK, true};         // HID type OSC
_Key M_HID_CONSUMER_SCAN_PREVIOUS_TRACK = {HID_CONSUMER_SCAN_PREVIOUS_TRACK, true}; // HID type OSC
_Key M_HID_CONSUMER_STOP = {HID_CONSUMER_STOP, true};                               // HID type OSC
_Key M_HID_CONSUMER_EJECT = {HID_CONSUMER_EJECT, true};                             // HID type OSC
_Key M_HID_CONSUMER_RANDOM_PLAY = {HID_CONSUMER_RANDOM_PLAY, true};                 // HID type OOC
_Key M_HID_CONSUMER_SELECT_DISC = {HID_CONSUMER_SELECT_DISC, true};                 // HID type NARY
_Key M_HID_CONSUMER_ENTER_DISC_MC = {HID_CONSUMER_ENTER_DISC_MC, true};
_Key M_HID_CONSUMER_REPEAT = {HID_CONSUMER_REPEAT, true};                               // HID type OSC
_Key M_HID_CONSUMER_TRACKING = {HID_CONSUMER_TRACKING, true};                           // HID type LC
_Key M_HID_CONSUMER_TRACK_NORMAL = {HID_CONSUMER_TRACK_NORMAL, true};                   // HID type OSC
_Key M_HID_CONSUMER_SLOW_TRACKING = {HID_CONSUMER_SLOW_TRACKING, true};                 // HID type LC
_Key M_HID_CONSUMER_FRAME_FORWARD = {HID_CONSUMER_FRAME_FORWARD, true};                 // HID type RTC
_Key M_HID_CONSUMER_FRAME_BACK = {HID_CONSUMER_FRAME_BACK, true};                       // HID type RTC
_Key M_HID_CONSUMER_MARK = {HID_CONSUMER_MARK, true};                                   // HID type OSC
_Key M_HID_CONSUMER_CLEAR_MARK = {HID_CONSUMER_CLEAR_MARK, true};                       // HID type OSC
_Key M_HID_CONSUMER_REPEAT_FROM_MARK = {HID_CONSUMER_REPEAT_FROM_MARK, true};           // HID type OOC
_Key M_HID_CONSUMER_RETURN_TO_MARK = {HID_CONSUMER_RETURN_TO_MARK, true};               // HID type OSC
_Key M_HID_CONSUMER_SEARCH_MARK_FORWARD = {HID_CONSUMER_SEARCH_MARK_FORWARD, true};     // HID type OSC
_Key M_HID_CONSUMER_SEARCH_MARK_BACKWARDS = {HID_CONSUMER_SEARCH_MARK_BACKWARDS, true}; // HID type OSC
_Key M_HID_CONSUMER_COUNTER_RESET = {HID_CONSUMER_COUNTER_RESET, true};                 // HID type OSC
_Key M_HID_CONSUMER_SHOW_COUNTER = {HID_CONSUMER_SHOW_COUNTER, true};                   // HID type OSC
_Key M_HID_CONSUMER_TRACKING_INCREMENT = {HID_CONSUMER_TRACKING_INCREMENT, true};       // HID type RTC
_Key M_HID_CONSUMER_TRACKING_DECREMENT = {HID_CONSUMER_TRACKING_DECREMENT, true};       // HID type RTC
_Key M_HID_CONSUMER_STOP_SLASH_EJECT = {HID_CONSUMER_STOP_SLASH_EJECT, true};           // HID type OSC
_Key M_HID_CONSUMER_PLAY_SLASH_PAUSE = {HID_CONSUMER_PLAY_SLASH_PAUSE, true};           // HID type OSC
_Key M_HID_CONSUMER_PLAY_SLASH_SKIP = {HID_CONSUMER_PLAY_SLASH_SKIP, true};             // HID type OSC
// Reserved 0xCF-DF
_Key M_HID_CONSUMER_VOLUME = {HID_CONSUMER_VOLUME, true};                     // HID type LC
_Key M_HID_CONSUMER_BALANCE = {HID_CONSUMER_BALANCE, true};                   // HID type LC
_Key M_HID_CONSUMER_MUTE = {HID_CONSUMER_MUTE, true};                         // HID type OOC
_Key M_HID_CONSUMER_BASS = {HID_CONSUMER_BASS, true};                         // HID type LC
_Key M_HID_CONSUMER_TREBLE = {HID_CONSUMER_TREBLE, true};                     // HID type LC
_Key M_HID_CONSUMER_BASS_BOOST = {HID_CONSUMER_BASS_BOOST, true};             // HID type OOC
_Key M_HID_CONSUMER_SURROUND_MODE = {HID_CONSUMER_SURROUND_MODE, true};       // HID type OSC
_Key M_HID_CONSUMER_LOUDNESS = {HID_CONSUMER_LOUDNESS, true};                 // HID type OOC
_Key M_HID_CONSUMER_MPX = {HID_CONSUMER_MPX, true};                           // HID type OOC
_Key M_HID_CONSUMER_VOLUME_INCREMENT = {HID_CONSUMER_VOLUME_INCREMENT, true}; // HID type RTC
_Key M_HID_CONSUMER_VOLUME_DECREMENT = {HID_CONSUMER_VOLUME_DECREMENT, true}; // HID type RTC
// Reserved 0xEB-EF
_Key M_HID_CONSUMER_SPEED_SELECT = {HID_CONSUMER_SPEED_SELECT, true};     // HID type OSC
_Key M_HID_CONSUMER_PLAYBACK_SPEED = {HID_CONSUMER_PLAYBACK_SPEED, true}; // HID type NARY
_Key M_HID_CONSUMER_STANDARD_PLAY = {HID_CONSUMER_STANDARD_PLAY, true};   // HID type SEL
_Key M_HID_CONSUMER_LONG_PLAY = {HID_CONSUMER_LONG_PLAY, true};           // HID type SEL
_Key M_HID_CONSUMER_EXTENDED_PLAY = {HID_CONSUMER_EXTENDED_PLAY, true};   // HID type SEL
_Key M_HID_CONSUMER_SLOW = {HID_CONSUMER_SLOW, true};                     // HID type OSC
// Reserved 0xF6-FF
_Key M_HID_CONSUMER_FAN_ENABLE = {HID_CONSUMER_FAN_ENABLE, true};                             // HID type OOC
_Key M_HID_CONSUMER_FAN_SPEED = {HID_CONSUMER_FAN_SPEED, true};                               // HID type LC
_Key M_HID_CONSUMER_LIGHT_ENABLE = {HID_CONSUMER_LIGHT_ENABLE, true};                         // HID type OOC
_Key M_HID_CONSUMER_LIGHT_ILLUMINATION_LEVEL = {HID_CONSUMER_LIGHT_ILLUMINATION_LEVEL, true}; // HID type LC
_Key M_HID_CONSUMER_CLIMATE_CONTROL_ENABLE = {HID_CONSUMER_CLIMATE_CONTROL_ENABLE, true};     // HID type OOC
_Key M_HID_CONSUMER_ROOM_TEMPERATURE = {HID_CONSUMER_ROOM_TEMPERATURE, true};                 // HID type LC
_Key M_HID_CONSUMER_SECURITY_ENABLE = {HID_CONSUMER_SECURITY_ENABLE, true};                   // HID type OOC
_Key M_HID_CONSUMER_FIRE_ALARM = {HID_CONSUMER_FIRE_ALARM, true};                             // HID type OSC
_Key M_HID_CONSUMER_POLICE_ALARM = {HID_CONSUMER_POLICE_ALARM, true};                         // HID type OSC
_Key M_HID_CONSUMER_PROXIMITY = {HID_CONSUMER_PROXIMITY, true};                               // HID type LC
_Key M_HID_CONSUMER_MOTION = {HID_CONSUMER_MOTION, true};                                     // HID type OSC
_Key M_HID_CONSUMER_DURESS_ALARM = {HID_CONSUMER_DURESS_ALARM, true};                         // HID type OSC
_Key M_HID_CONSUMER_HOLDUP_ALARM = {HID_CONSUMER_HOLDUP_ALARM, true};                         // HID type OSC
_Key M_HID_CONSUMER_MEDICAL_ALARM = {HID_CONSUMER_MEDICAL_ALARM, true};                       // HID type OSC
// Reserved 0x10E-14F
_Key M_HID_CONSUMER_BALANCE_RIGHT = {HID_CONSUMER_BALANCE_RIGHT, true};       // HID type RTC
_Key M_HID_CONSUMER_BALANCE_LEFT = {HID_CONSUMER_BALANCE_LEFT, true};         // HID type RTC
_Key M_HID_CONSUMER_BASS_INCREMENT = {HID_CONSUMER_BASS_INCREMENT, true};     // HID type RTC
_Key M_HID_CONSUMER_BASS_DECREMENT = {HID_CONSUMER_BASS_DECREMENT, true};     // HID type RTC
_Key M_HID_CONSUMER_TREBLE_INCREMENT = {HID_CONSUMER_TREBLE_INCREMENT, true}; // HID type RTC
_Key M_HID_CONSUMER_TREBLE_DECREMENT = {HID_CONSUMER_TREBLE_DECREMENT, true}; // HID type RTC
// Reserved 0x156-15F
_Key M_HID_CONSUMER_SPEAKER_SYSTEM = {HID_CONSUMER_SPEAKER_SYSTEM, true};                                       // HID type CL
_Key M_HID_CONSUMER_CHANNEL_LEFT = {HID_CONSUMER_CHANNEL_LEFT, true};                                           // HID type CL
_Key M_HID_CONSUMER_CHANNEL_RIGHT = {HID_CONSUMER_CHANNEL_RIGHT, true};                                         // HID type CL
_Key M_HID_CONSUMER_CHANNEL_CENTER = {HID_CONSUMER_CHANNEL_CENTER, true};                                       // HID type CL
_Key M_HID_CONSUMER_CHANNEL_FRONT = {HID_CONSUMER_CHANNEL_FRONT, true};                                         // HID type CL
_Key M_HID_CONSUMER_CHANNEL_CENTER_FRONT = {HID_CONSUMER_CHANNEL_CENTER_FRONT, true};                           // HID type CL
_Key M_HID_CONSUMER_CHANNEL_SIDE = {HID_CONSUMER_CHANNEL_SIDE, true};                                           // HID type CL
_Key M_HID_CONSUMER_CHANNEL_SURROUND = {HID_CONSUMER_CHANNEL_SURROUND, true};                                   // HID type CL
_Key M_HID_CONSUMER_CHANNEL_LOW_FREQUENCY_ENHANCEMENT = {HID_CONSUMER_CHANNEL_LOW_FREQUENCY_ENHANCEMENT, true}; // HID type CL
_Key M_HID_CONSUMER_CHANNEL_TOP = {HID_CONSUMER_CHANNEL_TOP, true};                                             // HID type CL
_Key M_HID_CONSUMER_CHANNEL_UNKNOWN = {HID_CONSUMER_CHANNEL_UNKNOWN, true};                                     // HID type CL
// Reserved 0x16B-16F
_Key M_HID_CONSUMER_SUB_CHANNEL = {HID_CONSUMER_SUB_CHANNEL, true};                             // HID type LC
_Key M_HID_CONSUMER_SUB_CHANNEL_INCREMENT = {HID_CONSUMER_SUB_CHANNEL_INCREMENT, true};         // HID type OSC
_Key M_HID_CONSUMER_SUB_CHANNEL_DECREMENT = {HID_CONSUMER_SUB_CHANNEL_DECREMENT, true};         // HID type OSC
_Key M_HID_CONSUMER_ALTERNATE_AUDIO_INCREMENT = {HID_CONSUMER_ALTERNATE_AUDIO_INCREMENT, true}; // HID type OSC
_Key M_HID_CONSUMER_ALTERNATE_AUDIO_DECREMENT = {HID_CONSUMER_ALTERNATE_AUDIO_DECREMENT, true}; // HID type OSC
// Reserved 0x175-17F
_Key M_HID_CONSUMER_APPLICATION_LAUNCH_BUTTONS = {HID_CONSUMER_APPLICATION_LAUNCH_BUTTONS, true};                               // HID type NARY
_Key M_HID_CONSUMER_AL_LAUNCH_BUTTON_CONFIGURATION_TOOL = {HID_CONSUMER_AL_LAUNCH_BUTTON_CONFIGURATION_TOOL, true};             // HID type SEL
_Key M_HID_CONSUMER_AL_PROGRAMMABLE_BUTTON_CONFIGURATION = {HID_CONSUMER_AL_PROGRAMMABLE_BUTTON_CONFIGURATION, true};           // HID type SEL
_Key M_HID_CONSUMER_AL_CONSUMER_CONTROL_CONFIGURATION = {HID_CONSUMER_AL_CONSUMER_CONTROL_CONFIGURATION, true};                 // HID type SEL
_Key M_HID_CONSUMER_AL_WORD_PROCESSOR = {HID_CONSUMER_AL_WORD_PROCESSOR, true};                                                 // HID type SEL
_Key M_HID_CONSUMER_AL_TEXT_EDITOR = {HID_CONSUMER_AL_TEXT_EDITOR, true};                                                       // HID type SEL
_Key M_HID_CONSUMER_AL_SPREADSHEET = {HID_CONSUMER_AL_SPREADSHEET, true};                                                       // HID type SEL
_Key M_HID_CONSUMER_AL_GRAPHICS_EDITOR = {HID_CONSUMER_AL_GRAPHICS_EDITOR, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AL_PRESENTATION_APP = {HID_CONSUMER_AL_PRESENTATION_APP, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AL_DATABASE_APP = {HID_CONSUMER_AL_DATABASE_APP, true};                                                     // HID type SEL
_Key M_HID_CONSUMER_AL_EMAIL_READER = {HID_CONSUMER_AL_EMAIL_READER, true};                                                     // HID type SEL
_Key M_HID_CONSUMER_AL_NEWSREADER = {HID_CONSUMER_AL_NEWSREADER, true};                                                         // HID type SEL
_Key M_HID_CONSUMER_AL_VOICEMAIL = {HID_CONSUMER_AL_VOICEMAIL, true};                                                           // HID type SEL
_Key M_HID_CONSUMER_AL_CONTACTS_SLASH_ADDRESS_BOOK = {HID_CONSUMER_AL_CONTACTS_SLASH_ADDRESS_BOOK, true};                       // HID type SEL
_Key M_HID_CONSUMER_AL_CALENDAR_SLASH_SCHEDULE = {HID_CONSUMER_AL_CALENDAR_SLASH_SCHEDULE, true};                               // HID type SEL
_Key M_HID_CONSUMER_AL_TASK_SLASH_PROJECT_MANAGER = {HID_CONSUMER_AL_TASK_SLASH_PROJECT_MANAGER, true};                         // HID type SEL
_Key M_HID_CONSUMER_AL_LOG_SLASH_JOURNAL_SLASH_TIMECARD = {HID_CONSUMER_AL_LOG_SLASH_JOURNAL_SLASH_TIMECARD, true};             // HID type SEL
_Key M_HID_CONSUMER_AL_CHECKBOOK_SLASH_FINANCE = {HID_CONSUMER_AL_CHECKBOOK_SLASH_FINANCE, true};                               // HID type SEL
_Key M_HID_CONSUMER_AL_CALCULATOR = {HID_CONSUMER_AL_CALCULATOR, true};                                                         // HID type SEL
_Key M_HID_CONSUMER_AL_A_SLASH_V_CAPTURE_SLASH_PLAYBACK = {HID_CONSUMER_AL_A_SLASH_V_CAPTURE_SLASH_PLAYBACK, true};             // HID type SEL
_Key M_HID_CONSUMER_AL_LOCAL_MACHINE_BROWSER = {HID_CONSUMER_AL_LOCAL_MACHINE_BROWSER, true};                                   // HID type SEL
_Key M_HID_CONSUMER_AL_LAN_SLASH_WAN_BROWSER = {HID_CONSUMER_AL_LAN_SLASH_WAN_BROWSER, true};                                   // HID type SEL
_Key M_HID_CONSUMER_AL_INTERNET_BROWSER = {HID_CONSUMER_AL_INTERNET_BROWSER, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AL_REMOTE_NETWORKING_SLASH_ISP_CONNECT = {HID_CONSUMER_AL_REMOTE_NETWORKING_SLASH_ISP_CONNECT, true};       // HID type SEL
_Key M_HID_CONSUMER_AL_NETWORK_CONFERENCE = {HID_CONSUMER_AL_NETWORK_CONFERENCE, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AL_NETWORK_CHAT = {HID_CONSUMER_AL_NETWORK_CHAT, true};                                                     // HID type SEL
_Key M_HID_CONSUMER_AL_TELEPHONY_SLASH_DIALER = {HID_CONSUMER_AL_TELEPHONY_SLASH_DIALER, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AL_LOGON = {HID_CONSUMER_AL_LOGON, true};                                                                   // HID type SEL
_Key M_HID_CONSUMER_AL_LOGOFF = {HID_CONSUMER_AL_LOGOFF, true};                                                                 // HID type SEL
_Key M_HID_CONSUMER_AL_LOGON_SLASH_LOGOFF = {HID_CONSUMER_AL_LOGON_SLASH_LOGOFF, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AL_TERMINAL_LOCK_SLASH_SCREENSAVER = {HID_CONSUMER_AL_TERMINAL_LOCK_SLASH_SCREENSAVER, true};               // HID type SEL
_Key M_HID_CONSUMER_AL_CONTROL_PANEL = {HID_CONSUMER_AL_CONTROL_PANEL, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AL_COMMAND_LINE_PROCESSOR_SLASH_RUN = {HID_CONSUMER_AL_COMMAND_LINE_PROCESSOR_SLASH_RUN, true};             // HID type SEL
_Key M_HID_CONSUMER_AL_PROCESS_SLASH_TASK_MANAGER = {HID_CONSUMER_AL_PROCESS_SLASH_TASK_MANAGER, true};                         // HID type SEL
_Key M_HID_CONSUMER_AL_SELECT_TASK_SLASH_APPLICATION = {HID_CONSUMER_AL_SELECT_TASK_SLASH_APPLICATION, true};                   // HID type SEL
_Key M_HID_CONSUMER_AL_NEXT_TASK_SLASH_APPLICATION = {HID_CONSUMER_AL_NEXT_TASK_SLASH_APPLICATION, true};                       // HID type SEL
_Key M_HID_CONSUMER_AL_PREVIOUS_TASK_SLASH_APPLICATION = {HID_CONSUMER_AL_PREVIOUS_TASK_SLASH_APPLICATION, true};               // HID type SEL
_Key M_HID_CONSUMER_AL_PREEMPTIVE_HALT_TASK_SLASH_APPLICATION = {HID_CONSUMER_AL_PREEMPTIVE_HALT_TASK_SLASH_APPLICATION, true}; // HID type SEL
_Key M_HID_CONSUMER_AL_INTEGRATED_HELP_CENTER = {HID_CONSUMER_AL_INTEGRATED_HELP_CENTER, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AL_DOCUMENTS = {HID_CONSUMER_AL_DOCUMENTS, true};                                                           // HID type SEL
_Key M_HID_CONSUMER_AL_THESAURUS = {HID_CONSUMER_AL_THESAURUS, true};                                                           // HID type SEL
_Key M_HID_CONSUMER_AL_DICTIONARY = {HID_CONSUMER_AL_DICTIONARY, true};                                                         // HID type SEL
_Key M_HID_CONSUMER_AL_DESKTOP = {HID_CONSUMER_AL_DESKTOP, true};                                                               // HID type SEL
_Key M_HID_CONSUMER_AL_SPELL_CHECK = {HID_CONSUMER_AL_SPELL_CHECK, true};                                                       // HID type SEL
_Key M_HID_CONSUMER_AL_GRAMMAR_CHECK = {HID_CONSUMER_AL_GRAMMAR_CHECK, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AL_WIRELESS_STATUS = {HID_CONSUMER_AL_WIRELESS_STATUS, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AL_KEYBOARD_LAYOUT = {HID_CONSUMER_AL_KEYBOARD_LAYOUT, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AL_VIRUS_PROTECTION = {HID_CONSUMER_AL_VIRUS_PROTECTION, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AL_ENCRYPTION = {HID_CONSUMER_AL_ENCRYPTION, true};                                                         // HID type SEL
_Key M_HID_CONSUMER_AL_SCREEN_SAVER = {HID_CONSUMER_AL_SCREEN_SAVER, true};                                                     // HID type SEL
_Key M_HID_CONSUMER_AL_ALARMS = {HID_CONSUMER_AL_ALARMS, true};                                                                 // HID type SEL
_Key M_HID_CONSUMER_AL_CLOCK = {HID_CONSUMER_AL_CLOCK, true};                                                                   // HID type SEL
_Key M_HID_CONSUMER_AL_FILE_BROWSER = {HID_CONSUMER_AL_FILE_BROWSER, true};                                                     // HID type SEL
_Key M_HID_CONSUMER_AL_POWER_STATUS = {HID_CONSUMER_AL_POWER_STATUS, true};                                                     // HID type SEL
_Key M_HID_CONSUMER_AL_IMAGE_BROWSER = {HID_CONSUMER_AL_IMAGE_BROWSER, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AL_AUDIO_BROWSER = {HID_CONSUMER_AL_AUDIO_BROWSER, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AL_MOVIE_BROWSER = {HID_CONSUMER_AL_MOVIE_BROWSER, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AL_DIGITAL_RIGHTS_MANAGER = {HID_CONSUMER_AL_DIGITAL_RIGHTS_MANAGER, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AL_DIGITAL_WALLET = {HID_CONSUMER_AL_DIGITAL_WALLET, true};                                                 // HID type SEL
// _Reserved 0x1BB
_Key M_HID_CONSUMER_AL_INSTANT_MESSAGING = {HID_CONSUMER_AL_INSTANT_MESSAGING, true};                                                             // HID type SEL
_Key M_HID_CONSUMER_AL_OEM_FEATURES_SLASH__TIPS_SLASH_TUTORIAL_BROWSER = {HID_CONSUMER_AL_OEM_FEATURES_SLASH__TIPS_SLASH_TUTORIAL_BROWSER, true}; // HID type SEL
_Key M_HID_CONSUMER_AL_OEM_HELP = {HID_CONSUMER_AL_OEM_HELP, true};                                                                               // HID type SEL
_Key M_HID_CONSUMER_AL_ONLINE_COMMUNITY = {HID_CONSUMER_AL_ONLINE_COMMUNITY, true};                                                               // HID type SEL
_Key M_HID_CONSUMER_AL_ENTERTAINMENT_CONTENT_BROWSER = {HID_CONSUMER_AL_ENTERTAINMENT_CONTENT_BROWSER, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AL_ONLINE_SHOPPING_BROWSER = {HID_CONSUMER_AL_ONLINE_SHOPPING_BROWSER, true};                                                 // HID type SEL
_Key M_HID_CONSUMER_AL_SMARTCARD_INFORMATION_SLASH_HELP = {HID_CONSUMER_AL_SMARTCARD_INFORMATION_SLASH_HELP, true};                               // HID type SEL
_Key M_HID_CONSUMER_AL_MARKET_MONITOR_SLASH_FINANCE_BROWSER = {HID_CONSUMER_AL_MARKET_MONITOR_SLASH_FINANCE_BROWSER, true};                       // HID type SEL
_Key M_HID_CONSUMER_AL_CUSTOMIZED_CORPORATE_NEWS_BROWSER = {HID_CONSUMER_AL_CUSTOMIZED_CORPORATE_NEWS_BROWSER, true};                             // HID type SEL
_Key M_HID_CONSUMER_AL_ONLINE_ACTIVITY_BROWSER = {HID_CONSUMER_AL_ONLINE_ACTIVITY_BROWSER, true};                                                 // HID type SEL
_Key M_HID_CONSUMER_AL_RESEARCH_SLASH_SEARCH_BROWSER = {HID_CONSUMER_AL_RESEARCH_SLASH_SEARCH_BROWSER, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AL_AUDIO_PLAYER = {HID_CONSUMER_AL_AUDIO_PLAYER, true};                                                                       // HID type SEL
// Reserved 0x1C8-1FF
_Key M_HID_CONSUMER_GENERIC_GUI_APPLICATION_CONTROLS = {HID_CONSUMER_GENERIC_GUI_APPLICATION_CONTROLS, true}; // HID type NARY
_Key M_HID_CONSUMER_AC_NEW = {HID_CONSUMER_AC_NEW, true};                                                     // HID type SEL
_Key M_HID_CONSUMER_AC_OPEN = {HID_CONSUMER_AC_OPEN, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_CLOSE = {HID_CONSUMER_AC_CLOSE, true};                                                 // HID type SEL
_Key M_HID_CONSUMER_AC_EXIT = {HID_CONSUMER_AC_EXIT, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_MAXIMIZE = {HID_CONSUMER_AC_MAXIMIZE, true};                                           // HID type SEL
_Key M_HID_CONSUMER_AC_MINIMIZE = {HID_CONSUMER_AC_MINIMIZE, true};                                           // HID type SEL
_Key M_HID_CONSUMER_AC_SAVE = {HID_CONSUMER_AC_SAVE, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_PRINT = {HID_CONSUMER_AC_PRINT, true};                                                 // HID type SEL
_Key M_HID_CONSUMER_AC_PROPERTIES = {HID_CONSUMER_AC_PROPERTIES, true};                                       // HID type SEL
_Key M_HID_CONSUMER_AC_UNDO = {HID_CONSUMER_AC_UNDO, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_COPY = {HID_CONSUMER_AC_COPY, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_CUT = {HID_CONSUMER_AC_CUT, true};                                                     // HID type SEL
_Key M_HID_CONSUMER_AC_PASTE = {HID_CONSUMER_AC_PASTE, true};                                                 // HID type SEL
_Key M_HID_CONSUMER_AC_SELECT_ALL = {HID_CONSUMER_AC_SELECT_ALL, true};                                       // HID type SEL
_Key M_HID_CONSUMER_AC_FIND = {HID_CONSUMER_AC_FIND, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_FIND_AND_REPLACE = {HID_CONSUMER_AC_FIND_AND_REPLACE, true};                           // HID type SEL
_Key M_HID_CONSUMER_AC_SEARCH = {HID_CONSUMER_AC_SEARCH, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_GO_TO = {HID_CONSUMER_AC_GO_TO, true};                                                 // HID type SEL
_Key M_HID_CONSUMER_AC_HOME = {HID_CONSUMER_AC_HOME, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_BACK = {HID_CONSUMER_AC_BACK, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_FORWARD = {HID_CONSUMER_AC_FORWARD, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AC_STOP = {HID_CONSUMER_AC_STOP, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_REFRESH = {HID_CONSUMER_AC_REFRESH, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AC_PREVIOUS_LINK = {HID_CONSUMER_AC_PREVIOUS_LINK, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_NEXT_LINK = {HID_CONSUMER_AC_NEXT_LINK, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AC_BOOKMARKS = {HID_CONSUMER_AC_BOOKMARKS, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AC_HISTORY = {HID_CONSUMER_AC_HISTORY, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AC_SUBSCRIPTIONS = {HID_CONSUMER_AC_SUBSCRIPTIONS, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_ZOOM_IN = {HID_CONSUMER_AC_ZOOM_IN, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AC_ZOOM_OUT = {HID_CONSUMER_AC_ZOOM_OUT, true};                                           // HID type SEL
_Key M_HID_CONSUMER_AC_ZOOM = {HID_CONSUMER_AC_ZOOM, true};                                                   // HID type LC
_Key M_HID_CONSUMER_AC_FULL_SCREEN_VIEW = {HID_CONSUMER_AC_FULL_SCREEN_VIEW, true};                           // HID type SEL
_Key M_HID_CONSUMER_AC_NORMAL_VIEW = {HID_CONSUMER_AC_NORMAL_VIEW, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_VIEW_TOGGLE = {HID_CONSUMER_AC_VIEW_TOGGLE, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_SCROLL_UP = {HID_CONSUMER_AC_SCROLL_UP, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AC_SCROLL_DOWN = {HID_CONSUMER_AC_SCROLL_DOWN, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_SCROLL = {HID_CONSUMER_AC_SCROLL, true};                                               // HID type LC
_Key M_HID_CONSUMER_AC_PAN_LEFT = {HID_CONSUMER_AC_PAN_LEFT, true};                                           // HID type SEL
_Key M_HID_CONSUMER_AC_PAN_RIGHT = {HID_CONSUMER_AC_PAN_RIGHT, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AC_PAN = {HID_CONSUMER_AC_PAN, true};                                                     // HID type LC
_Key M_HID_CONSUMER_AC_NEW_WINDOW = {HID_CONSUMER_AC_NEW_WINDOW, true};                                       // HID type SEL
_Key M_HID_CONSUMER_AC_TILE_HORIZONTALLY = {HID_CONSUMER_AC_TILE_HORIZONTALLY, true};                         // HID type SEL
_Key M_HID_CONSUMER_AC_TILE_VERTICALLY = {HID_CONSUMER_AC_TILE_VERTICALLY, true};                             // HID type SEL
_Key M_HID_CONSUMER_AC_FORMAT = {HID_CONSUMER_AC_FORMAT, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_EDIT = {HID_CONSUMER_AC_EDIT, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_BOLD = {HID_CONSUMER_AC_BOLD, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_ITALICS = {HID_CONSUMER_AC_ITALICS, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AC_UNDERLINE = {HID_CONSUMER_AC_UNDERLINE, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AC_STRIKETHROUGH = {HID_CONSUMER_AC_STRIKETHROUGH, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_SUBSCRIPT = {HID_CONSUMER_AC_SUBSCRIPT, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AC_SUPERSCRIPT = {HID_CONSUMER_AC_SUPERSCRIPT, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_ALL_CAPS = {HID_CONSUMER_AC_ALL_CAPS, true};                                           // HID type SEL
_Key M_HID_CONSUMER_AC_ROTATE = {HID_CONSUMER_AC_ROTATE, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_RESIZE = {HID_CONSUMER_AC_RESIZE, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_FLIP_HORIZONTAL = {HID_CONSUMER_AC_FLIP_HORIZONTAL, true};                             // HID type SEL
_Key M_HID_CONSUMER_AC_FLIP_VERTICAL = {HID_CONSUMER_AC_FLIP_VERTICAL, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_MIRROR_HORIZONTAL = {HID_CONSUMER_AC_MIRROR_HORIZONTAL, true};                         // HID type SEL
_Key M_HID_CONSUMER_AC_MIRROR_VERTICAL = {HID_CONSUMER_AC_MIRROR_VERTICAL, true};                             // HID type SEL
_Key M_HID_CONSUMER_AC_FONT_SELECT = {HID_CONSUMER_AC_FONT_SELECT, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_FONT_COLOR = {HID_CONSUMER_AC_FONT_COLOR, true};                                       // HID type SEL
_Key M_HID_CONSUMER_AC_FONT_SIZE = {HID_CONSUMER_AC_FONT_SIZE, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AC_JUSTIFY_LEFT = {HID_CONSUMER_AC_JUSTIFY_LEFT, true};                                   // HID type SEL
_Key M_HID_CONSUMER_AC_JUSTIFY_CENTER_H = {HID_CONSUMER_AC_JUSTIFY_CENTER_H, true};                           // HID type SEL
_Key M_HID_CONSUMER_AC_JUSTIFY_RIGHT = {HID_CONSUMER_AC_JUSTIFY_RIGHT, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_JUSTIFY_BLOCK_H = {HID_CONSUMER_AC_JUSTIFY_BLOCK_H, true};                             // HID type SEL
_Key M_HID_CONSUMER_AC_JUSTIFY_TOP = {HID_CONSUMER_AC_JUSTIFY_TOP, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_JUSTIFY_CENTER_V = {HID_CONSUMER_AC_JUSTIFY_CENTER_V, true};                           // HID type SEL
_Key M_HID_CONSUMER_AC_JUSTIFY_BOTTOM = {HID_CONSUMER_AC_JUSTIFY_BOTTOM, true};                               // HID type SEL
_Key M_HID_CONSUMER_AC_JUSTIFY_BLOCK_V = {HID_CONSUMER_AC_JUSTIFY_BLOCK_V, true};                             // HID type SEL
_Key M_HID_CONSUMER_AC_INDENT_DECREASE = {HID_CONSUMER_AC_INDENT_DECREASE, true};                             // HID type SEL
_Key M_HID_CONSUMER_AC_INDENT_INCREASE = {HID_CONSUMER_AC_INDENT_INCREASE, true};                             // HID type SEL
_Key M_HID_CONSUMER_AC_NUMBERED_LIST = {HID_CONSUMER_AC_NUMBERED_LIST, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_RESTART_NUMBERING = {HID_CONSUMER_AC_RESTART_NUMBERING, true};                         // HID type SEL
_Key M_HID_CONSUMER_AC_BULLETED_LIST = {HID_CONSUMER_AC_BULLETED_LIST, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_PROMOTE = {HID_CONSUMER_AC_PROMOTE, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AC_DEMOTE = {HID_CONSUMER_AC_DEMOTE, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_YES = {HID_CONSUMER_AC_YES, true};                                                     // HID type SEL
_Key M_HID_CONSUMER_AC_NO = {HID_CONSUMER_AC_NO, true};                                                       // HID type SEL
_Key M_HID_CONSUMER_AC_CANCEL = {HID_CONSUMER_AC_CANCEL, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_CATALOG = {HID_CONSUMER_AC_CATALOG, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AC_BUY_SLASH_CHECKOUT = {HID_CONSUMER_AC_BUY_SLASH_CHECKOUT, true};                       // HID type SEL
_Key M_HID_CONSUMER_AC_ADD_TO_CART = {HID_CONSUMER_AC_ADD_TO_CART, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_EXPAND = {HID_CONSUMER_AC_EXPAND, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_EXPAND_ALL = {HID_CONSUMER_AC_EXPAND_ALL, true};                                       // HID type SEL
_Key M_HID_CONSUMER_AC_COLLAPSE = {HID_CONSUMER_AC_COLLAPSE, true};                                           // HID type SEL
_Key M_HID_CONSUMER_AC_COLLAPSE_ALL = {HID_CONSUMER_AC_COLLAPSE_ALL, true};                                   // HID type SEL
_Key M_HID_CONSUMER_AC_PRINT_PREVIEW = {HID_CONSUMER_AC_PRINT_PREVIEW, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_PASTE_SPECIAL = {HID_CONSUMER_AC_PASTE_SPECIAL, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_INSERT_MODE = {HID_CONSUMER_AC_INSERT_MODE, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_DELETE = {HID_CONSUMER_AC_DELETE, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_LOCK = {HID_CONSUMER_AC_LOCK, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_UNLOCK = {HID_CONSUMER_AC_UNLOCK, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_PROTECT = {HID_CONSUMER_AC_PROTECT, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AC_UNPROTECT = {HID_CONSUMER_AC_UNPROTECT, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AC_ATTACH_COMMENT = {HID_CONSUMER_AC_ATTACH_COMMENT, true};                               // HID type SEL
_Key M_HID_CONSUMER_AC_DELETE_COMMENT = {HID_CONSUMER_AC_DELETE_COMMENT, true};                               // HID type SEL
_Key M_HID_CONSUMER_AC_VIEW_COMMENT = {HID_CONSUMER_AC_VIEW_COMMENT, true};                                   // HID type SEL
_Key M_HID_CONSUMER_AC_SELECT_WORD = {HID_CONSUMER_AC_SELECT_WORD, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_SELECT_SENTENCE = {HID_CONSUMER_AC_SELECT_SENTENCE, true};                             // HID type SEL
_Key M_HID_CONSUMER_AC_SELECT_PARAGRAPH = {HID_CONSUMER_AC_SELECT_PARAGRAPH, true};                           // HID type SEL
_Key M_HID_CONSUMER_AC_SELECT_COLUMN = {HID_CONSUMER_AC_SELECT_COLUMN, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_SELECT_ROW = {HID_CONSUMER_AC_SELECT_ROW, true};                                       // HID type SEL
_Key M_HID_CONSUMER_AC_SELECT_TABLE = {HID_CONSUMER_AC_SELECT_TABLE, true};                                   // HID type SEL
_Key M_HID_CONSUMER_AC_SELECT_OBJECT = {HID_CONSUMER_AC_SELECT_OBJECT, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_REDO_SLASH_REPEAT = {HID_CONSUMER_AC_REDO_SLASH_REPEAT, true};                         // HID type SEL
_Key M_HID_CONSUMER_AC_SORT = {HID_CONSUMER_AC_SORT, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_SORT_ASCENDING = {HID_CONSUMER_AC_SORT_ASCENDING, true};                               // HID type SEL
_Key M_HID_CONSUMER_AC_SORT_DESCENDING = {HID_CONSUMER_AC_SORT_DESCENDING, true};                             // HID type SEL
_Key M_HID_CONSUMER_AC_FILTER = {HID_CONSUMER_AC_FILTER, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_SET_CLOCK = {HID_CONSUMER_AC_SET_CLOCK, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AC_VIEW_CLOCK = {HID_CONSUMER_AC_VIEW_CLOCK, true};                                       // HID type SEL
_Key M_HID_CONSUMER_AC_SELECT_TIME_ZONE = {HID_CONSUMER_AC_SELECT_TIME_ZONE, true};                           // HID type SEL
_Key M_HID_CONSUMER_AC_EDIT_TIME_ZONES = {HID_CONSUMER_AC_EDIT_TIME_ZONES, true};                             // HID type SEL
_Key M_HID_CONSUMER_AC_SET_ALARM = {HID_CONSUMER_AC_SET_ALARM, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AC_CLEAR_ALARM = {HID_CONSUMER_AC_CLEAR_ALARM, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_SNOOZE_ALARM = {HID_CONSUMER_AC_SNOOZE_ALARM, true};                                   // HID type SEL
_Key M_HID_CONSUMER_AC_RESET_ALARM = {HID_CONSUMER_AC_RESET_ALARM, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_SYNCHRONIZE = {HID_CONSUMER_AC_SYNCHRONIZE, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_SEND_SLASH_RECEIVE = {HID_CONSUMER_AC_SEND_SLASH_RECEIVE, true};                       // HID type SEL
_Key M_HID_CONSUMER_AC_SEND_TO = {HID_CONSUMER_AC_SEND_TO, true};                                             // HID type SEL
_Key M_HID_CONSUMER_AC_REPLY = {HID_CONSUMER_AC_REPLY, true};                                                 // HID type SEL
_Key M_HID_CONSUMER_AC_REPLY_ALL = {HID_CONSUMER_AC_REPLY_ALL, true};                                         // HID type SEL
_Key M_HID_CONSUMER_AC_FORWARD_MSG = {HID_CONSUMER_AC_FORWARD_MSG, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_SEND = {HID_CONSUMER_AC_SEND, true};                                                   // HID type SEL
_Key M_HID_CONSUMER_AC_ATTACH_FILE = {HID_CONSUMER_AC_ATTACH_FILE, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_UPLOAD = {HID_CONSUMER_AC_UPLOAD, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_DOWNLOAD_SAVE_TARGET_AS = {HID_CONSUMER_AC_DOWNLOAD_SAVE_TARGET_AS, true};             // HID type SEL
_Key M_HID_CONSUMER_AC_SET_BORDERS = {HID_CONSUMER_AC_SET_BORDERS, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_INSERT_ROW = {HID_CONSUMER_AC_INSERT_ROW, true};                                       // HID type SEL
_Key M_HID_CONSUMER_AC_INSERT_COLUMN = {HID_CONSUMER_AC_INSERT_COLUMN, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_INSERT_FILE = {HID_CONSUMER_AC_INSERT_FILE, true};                                     // HID type SEL
_Key M_HID_CONSUMER_AC_INSERT_PICTURE = {HID_CONSUMER_AC_INSERT_PICTURE, true};                               // HID type SEL
_Key M_HID_CONSUMER_AC_INSERT_OBJECT = {HID_CONSUMER_AC_INSERT_OBJECT, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_INSERT_SYMBOL = {HID_CONSUMER_AC_INSERT_SYMBOL, true};                                 // HID type SEL
_Key M_HID_CONSUMER_AC_SAVE_AND_CLOSE = {HID_CONSUMER_AC_SAVE_AND_CLOSE, true};                               // HID type SEL
_Key M_HID_CONSUMER_AC_RENAME = {HID_CONSUMER_AC_RENAME, true};                                               // HID type SEL
_Key M_HID_CONSUMER_AC_MERGE = {HID_CONSUMER_AC_MERGE, true};                                                 // HID type SEL
_Key M_HID_CONSUMER_AC_SPLIT = {HID_CONSUMER_AC_SPLIT, true};                                                 // HID type SEL
_Key M_HID_CONSUMER_AC_DISRIBUTE_HORIZONTALLY = {HID_CONSUMER_AC_DISRIBUTE_HORIZONTALLY, true};               // HID type SEL
_Key M_HID_CONSUMER_AC_DISTRIBUTE_VERTICALLY = {HID_CONSUMER_AC_DISTRIBUTE_VERTICALLY, true};                 // HID type SEL
