#include "Utils.h"

// KEY MAPPINGS
const Key KEY_0_0 = K_6;
const Key KEY_0_1 = K_7;
const Key KEY_0_2 = K_8;
const Key KEY_0_3 = K_9;
const Key KEY_0_4 = K_0;
const Key KEY_0_5 = K_MINUS;

const Key KEY_1_0 = K_Y;
const Key KEY_1_1 = K_U;
const Key KEY_1_2 = K_I;
const Key KEY_1_3 = K_O;
const Key KEY_1_4 = K_P;
const Key KEY_1_5 = K_CANCEL;

const Key KEY_2_0 = K_H;
const Key KEY_2_1 = K_J;
const Key KEY_2_2 = K_K;
const Key KEY_2_3 = K_L;
const Key KEY_2_4 = K_C;
const Key KEY_2_5 = K_TILDE;

const Key KEY_3_0 = K_N;
const Key KEY_3_1 = K_M;
const Key KEY_3_2 = K_COMMA;
const Key KEY_3_3 = K_PERIOD;
const Key KEY_3_4 = K_SEMICOLON;
const Key KEY_3_5 = K_SLASH;

const Key KEY_4_0 = K_ESC;
const Key KEY_4_1 = K_BACKSPACE;
const Key KEY_4_2 = K_LEFT_ALT;
const Key KEY_4_3 = K_LEFT_WINDOWS;
const Key KEY_4_4 = K_ENTER;
const Key KEY_4_5 = K_SPACE;

// PIN MAPPINGS
byte rows[] = {9, 8, 7, 6, 5, 4};
byte cols[] = {18, 15, 14, 16, 10};

const int CMD_DELAY = 10;
const int BAUD_RATE = 115200;

const int ROW_COUNT = sizeof(rows) / sizeof(rows[0]);
const int COL_COUNT = sizeof(cols) / sizeof(cols[0]);

byte state_matrix[COL_COUNT][ROW_COUNT];
Key keys[COL_COUNT][ROW_COUNT];

void setup()
{
    Serial.begin(BAUD_RATE);
    Mouse.begin();
    Keyboard.begin();

    setInitialPinModes();
    initializeCommands();
}

void loop()
{
    readKeysFromCurrentArduino();
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
