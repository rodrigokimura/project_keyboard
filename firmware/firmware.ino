#define MASTER

#include "Wire.h"

#include "Device.h"
#include "Utils.h"
#include "Keys.h"

Device dev = Device("Kovu Keyboard", "Mono", "1");

// PIN MAPPINGS
const byte L_ROW_PINS[] = {5, 6, 7, 8, 9};
const byte L_COL_PINS[] = {19, 18, 15, 14, 16, 10};
const byte R_ROW_PINS[] = {18, 15, 14, 16, 10};
const byte R_COL_PINS[] = {9, 8, 7, 6, 5, 4};

const uint32_t ROW_COUNT = sizeof(L_ROW_PINS) / sizeof(L_ROW_PINS[0]);
const uint32_t COL_COUNT = sizeof(L_COL_PINS) / sizeof(L_COL_PINS[0]);

typedef MultiKey Keys[ROW_COUNT][COL_COUNT];

const uint32_t BAUD_RATE = 115200;
const uint32_t I2C_CLOCK = 400000;

byte keysStateBuffer[COL_COUNT];
unsigned long startTime = 0;
byte layer = 0;

#ifdef MASTER

const uint32_t DEBOUNCE_TIME = 10;

Keys lKeys = {
    {L_KEY_0_0, L_KEY_0_1, L_KEY_0_2, L_KEY_0_3, L_KEY_0_4, L_KEY_0_5},
    {L_KEY_1_0, L_KEY_1_1, L_KEY_1_2, L_KEY_1_3, L_KEY_1_4, L_KEY_1_5},
    {L_KEY_2_0, L_KEY_2_1, L_KEY_2_2, L_KEY_2_3, L_KEY_2_4, L_KEY_2_5},
    {L_KEY_3_0, L_KEY_3_1, L_KEY_3_2, L_KEY_3_3, L_KEY_3_4, L_KEY_3_5},
    {L_KEY_4_0, L_KEY_4_1, L_KEY_4_2, L_KEY_4_3, L_KEY_4_4, L_KEY_4_5},
};

Keys rKeys = {
    {R_KEY_0_0, R_KEY_0_1, R_KEY_0_2, R_KEY_0_3, R_KEY_0_4, R_KEY_0_5},
    {R_KEY_1_0, R_KEY_1_1, R_KEY_1_2, R_KEY_1_3, R_KEY_1_4, R_KEY_1_5},
    {R_KEY_2_0, R_KEY_2_1, R_KEY_2_2, R_KEY_2_3, R_KEY_2_4, R_KEY_2_5},
    {R_KEY_3_0, R_KEY_3_1, R_KEY_3_2, R_KEY_3_3, R_KEY_3_4, R_KEY_3_5},
    {R_KEY_4_0, R_KEY_4_1, R_KEY_4_2, R_KEY_4_3, R_KEY_4_4, R_KEY_4_5},
};

#else

const uint32_t DEBOUNCE_TIME = 1;

#endif

void setup()
{
    Serial.begin(BAUD_RATE);

#ifdef MASTER
    Wire.begin();
    Keyboard.begin();
#else
    Wire.begin(8);
    Wire.onRequest(sendKeysStateToMaster);
#endif

    Wire.setClock(I2C_CLOCK);
}

void loop()
{
    if ((millis() - startTime) <= DEBOUNCE_TIME)
        return;
    startTime = millis();

#ifdef MASTER
    scanKeys({ROW_COUNT, COL_COUNT}, L_ROW_PINS, L_COL_PINS, lSendCommand);
    readKeysStateFromSlave(rSendCommand);
#else
    scanKeys({ROW_COUNT, COL_COUNT}, R_ROW_PINS, R_COL_PINS, sendToBuffer);
#endif
}

void sendKeysStateToMaster()
{
    for (int c = 0; c < COL_COUNT; c++)
        Wire.write(keysStateBuffer[c]);
}

void scanKeys(Size size, const byte rows[], const byte cols[], void (*cb)(Coords c, boolean pressed))
{
    for (byte c = 0; c < size.columns; c++)
        pinMode(cols[c], INPUT_PULLUP);

    for (byte r = 0; r < size.rows; r++)
    {
        pinMode(rows[r], OUTPUT);
        digitalWrite(rows[r], LOW);
        for (byte c = 0; c < size.columns; c++)
            cb({r, c}, !digitalRead(cols[c]));
        digitalWrite(rows[r], HIGH);
        pinMode(rows[r], INPUT);
    }
}

#ifdef MASTER

void sendCommand(Coords c, boolean pressed, boolean isLeft)
{
    Keys &keys = isLeft ? lKeys : rKeys;
    if (pressed)
    {
        keys[c.row][c.col].press(layer);
    }
    else
    {
        keys[c.row][c.col].release(layer);
    }
}

void lSendCommand(Coords c, boolean pressed)
{
    sendCommand(c, pressed, true);
}

void rSendCommand(Coords c, boolean pressed)
{
    sendCommand(c, pressed, false);
}

void readKeysStateFromSlave(void (*cb)(Coords c, boolean pressed))
{
    Wire.requestFrom(8, ROW_COUNT, true);

    for (byte r = 0; r < ROW_COUNT; r++)
    {
        byte b = Wire.read();
        for (byte c = 0; c < COL_COUNT; c++)
        {
            cb({r, c}, bitRead(b, c));
        }
    }
}

#else

void sendToBuffer(Coords c, boolean pressed)
{
    bitWrite(keysStateBuffer[c.row], c.col, pressed);
}

#endif
