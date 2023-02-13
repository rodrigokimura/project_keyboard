#include "Wire.h"
#include "Keypad.h"

// KEY MAPPINGS
// const Key KEY_0_0 = K_6;
// const Key KEY_0_1 = K_7;
// const Key KEY_0_2 = K_8;
// const Key KEY_0_3 = K_9;
// const Key KEY_0_4 = K_0;
// const Key KEY_0_5 = K_MINUS;

// const Key KEY_1_0 = K_Y;
// const Key KEY_1_1 = K_U;
// const Key KEY_1_2 = K_I;
// const Key KEY_1_3 = K_O;
// const Key KEY_1_4 = K_P;
// const Key KEY_1_5 = K_CANCEL;

// const Key KEY_2_0 = K_H;
// const Key KEY_2_1 = K_J;
// const Key KEY_2_2 = K_K;
// const Key KEY_2_3 = K_L;
// const Key KEY_2_4 = K_C;
// const Key KEY_2_5 = K_TILDE;

// const Key KEY_3_0 = K_N;
// const Key KEY_3_1 = K_M;
// const Key KEY_3_2 = K_COMMA;
// const Key KEY_3_3 = K_PERIOD;
// const Key KEY_3_4 = K_SEMICOLON;
// const Key KEY_3_5 = K_SLASH;

// const Key KEY_4_0 = K_ESC;
// const Key KEY_4_1 = K_BACKSPACE;
// const Key KEY_4_2 = K_LEFT_ALT;
// const Key KEY_4_3 = K_LEFT_WINDOWS;
// const Key KEY_4_4 = K_ENTER;
// const Key KEY_4_5 = K_SPACE;

// PIN MAPPINGS
byte rows[] = {9, 8, 7, 6, 5, 4};
byte cols[] = {18, 15, 14, 16, 10};

const int CMD_DELAY = 10;
const uint32_t BAUD_RATE = 115200;

const int ROW_COUNT = sizeof(rows) / sizeof(rows[0]);
const int COL_COUNT = sizeof(cols) / sizeof(cols[0]);

char keys[ROW_COUNT][COL_COUNT] = {
    {'0', '1', '2', '3', '4'},
    {'5', '6', '7', '8', '9'},
    {'a', 'b', 'c', 'd', 'e'},
    {'f', 'g', 'h', 'i', 'j'},
    {'k', 'l', 'm', 'n', 'o'},
    {'p', 'q', 'r', 's', 't'},
};

Keypad keypad = Keypad(makeKeymap(keys), rows, cols, ROW_COUNT, COL_COUNT);

void setup()
{
    Serial.begin(BAUD_RATE);
    Wire.begin(8);
    Wire.setClock(400000);
    Wire.onRequest(requestEvent);
}

void requestEvent()
{
    for (int i = 0; i < ROW_COUNT; i++)
    {
        Wire.write(keypad.bitMap[i]);
    }
}

void loop()
{
    keypad.getKeys();
    // readKeysFromCurrentArduino();
}

void readKeysFromCurrentArduino()
{
    for (int i = 0; i < ROW_COUNT; i++)
    {
        Serial.print(keypad.bitMap[i], HEX);
    }
    Serial.println();
}
