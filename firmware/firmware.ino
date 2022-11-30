#include "Keyboard.h"
#include "Mouse.h"

byte rows[] = {2, 3};
const int rowCount = sizeof(rows) / sizeof(rows[0]);

byte cols[] = {8, 9};
const int colCount = sizeof(cols) / sizeof(cols[0]);
const int cmdDelay = 100;

byte keys[colCount][rowCount];

void setup()
{
    Serial.begin(115200);

    for (int x = 0; x < rowCount; x++)
    {
        pinMode(rows[x], INPUT);
    }

    for (int x = 0; x < colCount; x++)
    {
        pinMode(cols[x], INPUT_PULLUP);
    }

    Mouse.begin();
    Keyboard.begin();
}

void sendCommand()
{
    if (keys[0][0] == 0)
    {
        Keyboard.press(KEY_LEFT_CTRL);
    }
    else
    {
        Keyboard.release(KEY_LEFT_CTRL);
    }

    if (keys[1][0] == 0)
    {
        Keyboard.press(KEY_LEFT_SHIFT);
    }
    else
    {
        Keyboard.release(KEY_LEFT_SHIFT);
    }
    if (keys[0][1] == 0)
    {
        Keyboard.press('c');
    }
    else
    {
        Keyboard.release('c');
    }
    if (keys[1][1] == 0)
    {
        Keyboard.press('v');
    }
    else
    {
        Keyboard.release('v');
    }
}

void readMatrix()
{
    for (int colIndex = 0; colIndex < colCount; colIndex++)
    {
        byte curCol = cols[colIndex];
        pinMode(curCol, OUTPUT);
        digitalWrite(curCol, LOW);

        for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
        {
            byte rowCol = rows[rowIndex];
            pinMode(rowCol, INPUT_PULLUP);
            keys[colIndex][rowIndex] = digitalRead(rowCol);
            sendCommand();
            pinMode(rowCol, INPUT);
        }
        pinMode(curCol, INPUT);
    }
}

void loop()
{
    readMatrix();
    delay(cmdDelay);
}
