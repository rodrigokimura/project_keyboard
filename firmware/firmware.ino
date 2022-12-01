#include "HID-Project.h"

byte rows[] = {7, 8, 9};
byte cols[] = {10, 16};

const int ROW_COUNT = sizeof(rows) / sizeof(rows[0]);
const int COL_COUNT = sizeof(cols) / sizeof(cols[0]);
const int CMD_DELAY = 10;
const int BAUD_RATE = 115200;

byte keys[COL_COUNT][ROW_COUNT];
struct KeyData
{
    int key;
    bool media;
};
KeyData commands[COL_COUNT][ROW_COUNT];

const KeyData KEY_0_0 = {KEY_LEFT_CTRL, false};
const KeyData KEY_0_1 = {KEY_LEFT_SHIFT, false};
const KeyData KEY_0_2 = {KEY_C, false};
const KeyData KEY_1_0 = {KEY_Z, false};
const KeyData KEY_1_1 = {KEY_V, false};
const KeyData KEY_1_2 = {MEDIA_PLAY_PAUSE, true};
const KeyData KEY_ENC_CW = {MEDIA_VOLUME_UP, true};
const KeyData KEY_ENC_CCW = {MEDIA_VOLUME_DOWN, true};

const int ENC_PIN_1 = 3;
const int ENC_PIN_2 = 4;

void setup()
{
    Serial.begin(BAUD_RATE);
    Mouse.begin();
    Keyboard.begin();

    setInitialPinModes();
    initializeCommands();
}

long oldPosition = -999;

void loop()
{
    pinMode(ENC_PIN_1, INPUT_PULLUP);
    pinMode(ENC_PIN_2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENC_PIN_1), checkPosition, CHANGE);

    readKeysFromCurrentArduino();
    delay(CMD_DELAY);
}

void checkPosition()
{

    if (digitalRead(ENC_PIN_1) == LOW)
    {
        if (digitalRead(ENC_PIN_2) == LOW)
        {
            sendEncoderCommand(true);
        }
        else
        {
            sendEncoderCommand(false);
        }
    }
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
        if (commands[col][row].media == true)
        {
            Consumer.press(ConsumerKeycode(commands[col][row].key));
        }
        else
        {
            Keyboard.press(KeyboardKeycode(commands[col][row].key));
        }
    }
    else
    {
        if (commands[col][row].media == true)
        {
            Consumer.release(ConsumerKeycode(commands[col][row].key));
        }
        else
        {
            Keyboard.release(KeyboardKeycode(commands[col][row].key));
        }
    }
}

void sendEncoderCommand(bool isCW)
{
    if (isCW)
    {
        if (KEY_ENC_CW.media == true)
        {
            Consumer.write(ConsumerKeycode(KEY_ENC_CW.key));
        }
        else
        {
            Keyboard.write(KeyboardKeycode(KEY_ENC_CW.key));
        }
    }
    else
    {
        if (KEY_ENC_CCW.media == true)
        {
            Consumer.write(ConsumerKeycode(KEY_ENC_CCW.key));
        }
        else
        {
            Keyboard.write(KeyboardKeycode(KEY_ENC_CCW.key));
        }
    }
}