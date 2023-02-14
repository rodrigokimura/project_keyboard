#include "Keypad.h"
#include "Wire.h"

#include "Utils.h"
#include "Keys.h"

const boolean IS_LEFT_SIDE = true;

unsigned long startTime = 0;
unsigned int debounceTime = 50;

// PIN MAPPINGS
byte lRows[] = {5, 6, 7, 8, 9};
byte lCols[] = {19, 18, 15, 14, 16, 10};

byte rRows[] = {18, 15, 14, 16, 10};
byte rCols[] = {9, 8, 7, 6, 5, 4};

const uint32_t BAUD_RATE = 115200;
const uint32_t I2C_CLOCK = 400000;

const int L_COL_COUNT = sizeof(lCols) / sizeof(lCols[0]);
const int L_ROW_COUNT = sizeof(lRows) / sizeof(lRows[0]);

const int R_COL_COUNT = sizeof(rCols) / sizeof(rCols[0]);
const int R_ROW_COUNT = sizeof(rRows) / sizeof(rRows[0]);

_Key lKeys[L_ROW_COUNT][L_COL_COUNT] = {
    {L_KEY_0_0, L_KEY_0_1, L_KEY_0_2, L_KEY_0_3, L_KEY_0_4, L_KEY_0_5},
    {L_KEY_1_0, L_KEY_1_1, L_KEY_1_2, L_KEY_1_3, L_KEY_1_4, L_KEY_1_5},
    {L_KEY_2_0, L_KEY_2_1, L_KEY_2_2, L_KEY_2_3, L_KEY_2_4, L_KEY_2_5},
    {L_KEY_3_0, L_KEY_3_1, L_KEY_3_2, L_KEY_3_3, L_KEY_3_4, L_KEY_3_5},
    {L_KEY_4_0, L_KEY_4_1, L_KEY_4_2, L_KEY_4_3, L_KEY_4_4, L_KEY_4_5},
};
_Key rKeys[R_ROW_COUNT][R_COL_COUNT] = {
    {R_KEY_0_0, R_KEY_0_1, R_KEY_0_2, R_KEY_0_3, R_KEY_0_4, R_KEY_0_5},
    {R_KEY_1_0, R_KEY_1_1, R_KEY_1_2, R_KEY_1_3, R_KEY_1_4, R_KEY_1_5},
    {R_KEY_2_0, R_KEY_2_1, R_KEY_2_2, R_KEY_2_3, R_KEY_2_4, R_KEY_2_5},
    {R_KEY_3_0, R_KEY_3_1, R_KEY_3_2, R_KEY_3_3, R_KEY_3_4, R_KEY_3_5},
    {R_KEY_4_0, R_KEY_4_1, R_KEY_4_2, R_KEY_4_3, R_KEY_4_4, R_KEY_4_5},
};

char _lKeypadKeyNames[L_COL_COUNT][L_ROW_COUNT] = {
    {'z', '1', '2', '3', '4'},
    {'5', '6', '7', '8', '9'},
    {'a', 'b', 'c', 'd', 'e'},
    {'f', 'g', 'h', 'i', 'j'},
    {'k', 'l', 'm', 'n', 'o'},
    {'p', 'q', 'r', 's', 't'},
};
char _rKeypadKeyNames[R_COL_COUNT][R_ROW_COUNT] = {
    {'z', '1', '2', '3', '4'},
    {'5', '6', '7', '8', '9'},
    {'a', 'b', 'c', 'd', 'e'},
    {'f', 'g', 'h', 'i', 'j'},
    {'k', 'l', 'm', 'n', 'o'},
    {'p', 'q', 'r', 's', 't'},
};

Keypad lKeypad = Keypad(makeKeymap(_lKeypadKeyNames), lCols, lRows, L_COL_COUNT, L_ROW_COUNT);
Keypad rKeypad = Keypad(makeKeymap(_rKeypadKeyNames), rCols, rRows, R_COL_COUNT, R_ROW_COUNT);

void setup()
{
    Serial.begin(BAUD_RATE);
    if (IS_LEFT_SIDE)
    {
        Wire.begin();
        Keyboard.begin();
        lKeypad.addEventListener(keypadEvent);
    }
    else
    {
        Wire.begin(8);
        rKeypad.setDebounceTime(1);
        Wire.onRequest(requestEvent);
    }
    Wire.setClock(I2C_CLOCK);
}

void requestEvent()
{
    for (int c = 0; c < R_COL_COUNT; c++)
    {
        Wire.write(rKeypad.bitMap[c]);
    }
}

void loop()
{
    if (IS_LEFT_SIDE)
    {
        lKeypad.getKeys();
        readKeysFromSecondaryArduino();
    }
    else
    {
        rKeypad.getKeys();
    }
}

void keypadEvent(KeypadEvent key)
{
    Coords coords = getCoords(key);
    _Key _key = lKeys[coords.row][coords.col];
    switch (lKeypad.getState())
    {
    case PRESSED:
        _key.press();
    case RELEASED:
        _key.release();
    case HOLD:
        Serial.println(key);
    case IDLE:
        Serial.println(key);
    }
}

Coords getCoords(char k)
{
    Coords coords;

    for (int c = 0; c < L_COL_COUNT; c++)
    {
        for (int r = 0; r < L_ROW_COUNT; r++)
        {
            if (_lKeypadKeyNames[c][r] == k)
            {
                coords.row = r;
                coords.col = c;
                return coords;
            }
        }
    }
}

void readKeysFromSecondaryArduino()
{
    if ((millis() - startTime) <= debounceTime)
    {
        return;
    }
    startTime = millis();
    Coords coords;

    Wire.requestFrom(8, 6, true);

    int c = 0;
    while (Wire.available())
    {
        coords.col = c;
        byte b = Wire.read();
        for (int r = 0; r < R_COL_COUNT; r++)
        {
            coords.row = r;
            boolean pressed = bitRead(b, r);
            sendCommand(coords, pressed);
        }
        c++;
    }
}

void sendCommand(Coords c, boolean pressed)
{
    if (pressed)
    {
        rKeys[c.row][c.col].press();
    }
    else
    {
        rKeys[c.row][c.col].release();
    }
}
