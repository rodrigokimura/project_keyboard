#include "Utils.h"
#include "Wire.h"

// KEY MAPPINGS
const Key KEY_0_0 = K_QUOTE;
const Key KEY_0_1 = K_1;
const Key KEY_0_2 = K_2;
const Key KEY_0_3 = K_3;
const Key KEY_0_4 = K_4;
const Key KEY_0_5 = K_5;

const Key KEY_1_0 = K_TAB;
const Key KEY_1_1 = K_Q;
const Key KEY_1_2 = K_W;
const Key KEY_1_3 = K_E;
const Key KEY_1_4 = K_R;
const Key KEY_1_5 = K_T;

const Key KEY_2_0 = K_CAPS_LOCK;
const Key KEY_2_1 = K_A;
const Key KEY_2_2 = K_S;
const Key KEY_2_3 = K_D;
const Key KEY_2_4 = K_F;
const Key KEY_2_5 = K_G;

const Key KEY_3_0 = K_BACKSLASH;
const Key KEY_3_1 = K_Z;
const Key KEY_3_2 = K_X;
const Key KEY_3_3 = K_C;
const Key KEY_3_4 = K_V;
const Key KEY_3_5 = K_B;

const Key KEY_4_0 = K_LEFT_SHIFT;
const Key KEY_4_1 = K_LEFT_CTRL;
const Key KEY_4_2 = K_LEFT_ALT;
const Key KEY_4_3 = K_LEFT_WINDOWS;
const Key KEY_4_4 = K_ENTER;
const Key KEY_4_5 = K_SPACE;

// PIN MAPPINGS
byte cols[] = {5, 6, 7, 8, 9};
byte rows[] = {19, 18, 15, 14, 16, 10};

char matrix[30];

const int CMD_DELAY = 10;
const uint32_t BAUD_RATE = 115200;

const int ROW_COUNT = sizeof(rows) / sizeof(rows[0]);
const int COL_COUNT = sizeof(cols) / sizeof(cols[0]);

byte state_matrix[COL_COUNT][ROW_COUNT];
Key keys[COL_COUNT][ROW_COUNT];

void setup()
{
    Serial.begin(BAUD_RATE);
    Wire.begin();
    Wire.setClock(400000);
    Keyboard.begin();

    setInitialPinModes();
    initializeCommands();
}

void loop()
{
    readKeysFromCurrentArduino();
    readKeysFromSecondaryArduino();
    delay(CMD_DELAY);
}

void setInitialPinModes()
{
    for (int x = 0; x < ROW_COUNT; x++)
    {
        pinMode(rows[x], INPUT);
    }

    for (int x = 0; x < COL_COUNT; x++)
    {
        pinMode(cols[x], INPUT_PULLUP);
    }
}

void initializeCommands()
{
    keys[0][0] = KEY_0_0;
    keys[0][1] = KEY_0_1;
    keys[0][2] = KEY_0_2;
    keys[0][3] = KEY_0_3;
    keys[0][4] = KEY_0_4;
    keys[0][5] = KEY_0_5;

    keys[1][0] = KEY_1_0;
    keys[1][1] = KEY_1_1;
    keys[1][2] = KEY_1_2;
    keys[1][3] = KEY_1_3;
    keys[1][4] = KEY_1_4;
    keys[1][5] = KEY_1_5;

    keys[2][0] = KEY_2_0;
    keys[2][1] = KEY_2_1;
    keys[2][2] = KEY_2_2;
    keys[2][3] = KEY_2_3;
    keys[2][4] = KEY_2_4;
    keys[2][5] = KEY_2_5;

    keys[3][0] = KEY_3_0;
    keys[3][1] = KEY_3_1;
    keys[3][2] = KEY_3_2;
    keys[3][3] = KEY_3_3;
    keys[3][4] = KEY_3_4;
    keys[3][5] = KEY_3_5;

    keys[4][0] = KEY_4_0;
    keys[4][1] = KEY_4_1;
    keys[4][2] = KEY_4_2;
    keys[4][3] = KEY_4_3;
    keys[4][4] = KEY_4_4;
    keys[4][5] = KEY_4_5;
}

void readKeysFromCurrentArduino()
{
    for (int colIndex = 0; colIndex < COL_COUNT; colIndex++)
    {
        byte curCol = cols[colIndex];
        pinMode(curCol, OUTPUT);
        digitalWrite(curCol, LOW);

        for (int rowIndex = 0; rowIndex < ROW_COUNT; rowIndex++)
        {
            byte rowCol = rows[rowIndex];
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
        keys[col][row].press();
    }
    else
    {
        keys[col][row].release();
    }
}
