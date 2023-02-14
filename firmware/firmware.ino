#include "Keypad.h"

#include "Utils.h"
#include "Wire.h"

const boolean IS_LEFT_SIDE = true;

// KEY MAPPINGS
const _Key KEY_0_0 = K_QUOTE;
const _Key KEY_0_1 = K_1;
const _Key KEY_0_2 = K_2;
const _Key KEY_0_3 = K_3;
const _Key KEY_0_4 = K_4;
const _Key KEY_0_5 = K_5;

const _Key KEY_1_0 = K_TAB;
const _Key KEY_1_1 = K_Q;
const _Key KEY_1_2 = K_W;
const _Key KEY_1_3 = K_E;
const _Key KEY_1_4 = K_R;
const _Key KEY_1_5 = K_T;

const _Key KEY_2_0 = K_CAPS_LOCK;
const _Key KEY_2_1 = K_A;
const _Key KEY_2_2 = K_S;
const _Key KEY_2_3 = K_D;
const _Key KEY_2_4 = K_F;
const _Key KEY_2_5 = K_G;

const _Key KEY_3_0 = K_BACKSLASH;
const _Key KEY_3_1 = K_Z;
const _Key KEY_3_2 = K_X;
const _Key KEY_3_3 = K_C;
const _Key KEY_3_4 = K_V;
const _Key KEY_3_5 = K_B;

const _Key KEY_4_0 = K_LEFT_SHIFT;
const _Key KEY_4_1 = K_LEFT_CTRL;
const _Key KEY_4_2 = K_LEFT_ALT;
const _Key KEY_4_3 = K_LEFT_WINDOWS;
const _Key KEY_4_4 = K_ENTER;
const _Key KEY_4_5 = K_SPACE;

// PIN MAPPINGS
byte leftCols[] = {5, 6, 7, 8, 9};
byte leftRows[] = {19, 18, 15, 14, 16, 10};

char matrix[30];

const int CMD_DELAY = 10;
const uint32_t BAUD_RATE = 115200;

const int LEFT_ROW_COUNT = sizeof(leftRows) / sizeof(leftRows[0]);
const int LEFT_COL_COUNT = sizeof(leftCols) / sizeof(leftCols[0]);

byte state_matrix[LEFT_COL_COUNT][LEFT_ROW_COUNT];
_Key leftKeys[LEFT_COL_COUNT][LEFT_ROW_COUNT];

// SECONDARY
byte rows[] = {9, 8, 7, 6, 5, 4};
byte cols[] = {18, 15, 14, 16, 10};

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
    if (IS_LEFT_SIDE)
    {

        Serial.begin(BAUD_RATE);
        Wire.begin();
        Wire.setClock(400000);
        Keyboard.begin();

        setInitialPinModes();
        initializeCommands();
    }
    else
    {
        Serial.begin(BAUD_RATE);
        Wire.begin(8);
        Wire.setClock(400000);
        keypad.setDebounceTime(1);
        Wire.onRequest(requestEvent);
    }
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
    if (IS_LEFT_SIDE)
    {
        readKeysFromCurrentArduino();
        readKeysFromSecondaryArduino();
        delay(CMD_DELAY);
    }
    else
    {
        keypad.getKeys();
    }
}

void setInitialPinModes()
{
    for (int x = 0; x < LEFT_ROW_COUNT; x++)
    {
        pinMode(leftRows[x], INPUT);
    }

    for (int x = 0; x < LEFT_COL_COUNT; x++)
    {
        pinMode(leftCols[x], INPUT_PULLUP);
    }
}

void initializeCommands()
{
    leftKeys[0][0] = KEY_0_0;
    leftKeys[0][1] = KEY_0_1;
    leftKeys[0][2] = KEY_0_2;
    leftKeys[0][3] = KEY_0_3;
    leftKeys[0][4] = KEY_0_4;
    leftKeys[0][5] = KEY_0_5;

    leftKeys[1][0] = KEY_1_0;
    leftKeys[1][1] = KEY_1_1;
    leftKeys[1][2] = KEY_1_2;
    leftKeys[1][3] = KEY_1_3;
    leftKeys[1][4] = KEY_1_4;
    leftKeys[1][5] = KEY_1_5;

    leftKeys[2][0] = KEY_2_0;
    leftKeys[2][1] = KEY_2_1;
    leftKeys[2][2] = KEY_2_2;
    leftKeys[2][3] = KEY_2_3;
    leftKeys[2][4] = KEY_2_4;
    leftKeys[2][5] = KEY_2_5;

    leftKeys[3][0] = KEY_3_0;
    leftKeys[3][1] = KEY_3_1;
    leftKeys[3][2] = KEY_3_2;
    leftKeys[3][3] = KEY_3_3;
    leftKeys[3][4] = KEY_3_4;
    leftKeys[3][5] = KEY_3_5;

    leftKeys[4][0] = KEY_4_0;
    leftKeys[4][1] = KEY_4_1;
    leftKeys[4][2] = KEY_4_2;
    leftKeys[4][3] = KEY_4_3;
    leftKeys[4][4] = KEY_4_4;
    leftKeys[4][5] = KEY_4_5;
}

void readKeysFromCurrentArduino()
{
    for (int colIndex = 0; colIndex < LEFT_COL_COUNT; colIndex++)
    {
        byte curCol = leftCols[colIndex];
        pinMode(curCol, OUTPUT);
        digitalWrite(curCol, LOW);

        for (int rowIndex = 0; rowIndex < LEFT_ROW_COUNT; rowIndex++)
        {
            byte rowCol = leftRows[rowIndex];
            pinMode(rowCol, INPUT_PULLUP);
            state_matrix[colIndex][rowIndex] = digitalRead(rowCol);
            sendCommand(colIndex, rowIndex);
            pinMode(rowCol, INPUT);
        }
        pinMode(curCol, INPUT);
    }
}

void readKeysFromSecondaryArduino()
{
    Wire.requestFrom(8, 6, true);

    while (Wire.available())
    {
        byte b = Wire.read();
        Serial.print(b, HEX);
    }
    Serial.println();
}

void sendCommand(int col, int row)
{
    if (state_matrix[col][row] == 0)
    {
        leftKeys[col][row].press();
    }
    else
    {
        leftKeys[col][row].release();
    }
}
