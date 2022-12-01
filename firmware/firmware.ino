#include "HID-Project.h"

byte rows[] = {7, 8, 9};
byte cols[] = {10, 16};

const int ROW_COUNT = sizeof(rows) / sizeof(rows[0]);
const int COL_COUNT = sizeof(cols) / sizeof(cols[0]);
const int CMD_DELAY = 100;
const int BAUD_RATE = 115200;

byte keys[COL_COUNT][ROW_COUNT];
int commands[COL_COUNT][ROW_COUNT];

const int KEY_0_0 = KEY_LEFT_CTRL;
const int KEY_0_1 = KEY_LEFT_SHIFT;
const int KEY_0_2 = KEY_C;
const int KEY_1_0 = KEY_Z;
const int KEY_1_1 = KEY_V;
const int KEY_1_2 = MEDIA_PLAY_PAUSE;

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
    commands[0][0] = KEY_0_0;
    commands[0][1] = KEY_0_1;
    commands[0][2] = KEY_0_2;
    commands[1][0] = KEY_1_0;
    commands[1][1] = KEY_1_1;
    commands[1][2] = KEY_1_2;
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
            keys[colIndex][rowIndex] = digitalRead(rowCol);
            sendCommand(colIndex, rowIndex);
            pinMode(rowCol, INPUT);
        }
        pinMode(curCol, INPUT);
    }
}

void sendCommand(int col, int row)
{
    if (keys[col][row] == 0)
    {
        Keyboard.press(KeyboardKeycode(commands[col][row]));
        Consumer.press(ConsumerKeycode(commands[col][row]));
    }
    else
    {
        Keyboard.release(KeyboardKeycode(commands[col][row]));
        Consumer.release(ConsumerKeycode(commands[col][row]));
    }
}
