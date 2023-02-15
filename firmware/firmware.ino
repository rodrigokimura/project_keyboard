#include "Wire.h"

#include "Utils.h"
#include "Keys.h"

const boolean IS_LEFT_SIDE = true;

const uint32_t L_DEBOUNCE_TIME = 50;
const uint32_t R_DEBOUNCE_TIME = 1;

// PIN MAPPINGS
const byte L_ROW_PINS[] = {5, 6, 7, 8, 9};
const byte L_COL_PINS[] = {19, 18, 15, 14, 16, 10};
const byte R_ROW_PINS[] = {18, 15, 14, 16, 10};
const byte R_COL_PINS[] = {9, 8, 7, 6, 5, 4};

const uint32_t L_COL_COUNT = sizeof(L_COL_PINS) / sizeof(L_COL_PINS[0]);
const uint32_t L_ROW_COUNT = sizeof(L_ROW_PINS) / sizeof(L_ROW_PINS[0]);
const uint32_t R_COL_COUNT = sizeof(R_COL_PINS) / sizeof(R_COL_PINS[0]);
const uint32_t R_ROW_COUNT = sizeof(R_ROW_PINS) / sizeof(R_ROW_PINS[0]);

const uint32_t BAUD_RATE = 115200;
const uint32_t I2C_CLOCK = 400000;

byte keysState[R_COL_COUNT];
unsigned long startTime = 0;

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

void setup()
{
    Serial.begin(BAUD_RATE);
    if (IS_LEFT_SIDE)
    {
        Wire.begin();
        Keyboard.begin();
    }
    else
    {
        Wire.begin(8);
        Wire.onRequest(requestEvent);
    }
    Wire.setClock(I2C_CLOCK);
}

void loop()
{
    if (IS_LEFT_SIDE)
    {
        if ((millis() - startTime) <= L_DEBOUNCE_TIME)
        {
            return;
        }
        startTime = millis();
        scanKeys({L_ROW_COUNT, L_COL_COUNT}, L_ROW_PINS, L_COL_PINS, lSendCommand);
        readKeysFromSecondaryArduino();
    }
    else
    {
        if ((millis() - startTime) <= R_DEBOUNCE_TIME)
        {
            return;
        }
        startTime = millis();
        scanKeys({R_ROW_COUNT, R_COL_COUNT}, R_ROW_PINS, R_COL_PINS, registerToBitMap);
    }
}

void requestEvent()
{
    for (int c = 0; c < R_COL_COUNT; c++)
    {
        Wire.write(keysState[c]);
    }
}

void scanKeys(Size size, const byte rows[], const byte columns[], void (*function)(Coords c, boolean pressed))
{
    for (byte c = 0; c < size.columns; c++)
    {
        pinMode(columns[c], INPUT_PULLUP);
    }

    for (byte r = 0; r < size.rows; r++)
    {
        pinMode(rows[r], OUTPUT);
        digitalWrite(rows[r], LOW);
        for (byte c = 0; c < size.columns; c++)
        {
            boolean pressed = !digitalRead(columns[c]);
            function({r, c}, pressed);
        }
        digitalWrite(rows[r], HIGH);
        pinMode(rows[r], INPUT);
    }
}

void lSendCommand(Coords c, boolean pressed)
{
    if (pressed)
    {
        lKeys[c.row][c.col].press();
    }
    else
    {
        lKeys[c.row][c.col].release();
    }
}

void rSendCommand(Coords c, boolean pressed)
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

void readKeysFromSecondaryArduino()
{
    Wire.requestFrom(8, 6, true);

    byte c = 0;
    while (Wire.available())
    {
        byte b = Wire.read();
        for (byte r = 0; r < R_COL_COUNT; r++)
        {
            boolean pressed = bitRead(b, r);
            rSendCommand({r, c}, pressed);
        }
        c++;
    }
}

void registerToBitMap(Coords c, boolean pressed)
{
    bitWrite(keysState[c.col], c.row, pressed);
}
