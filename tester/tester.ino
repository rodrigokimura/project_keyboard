const int BAUD_RATE = 115200;
const int COL = 8;
const int ROW = 9;
const int CMD_DELAY = 10;

void setup()
{
    Serial.begin(BAUD_RATE);

}

void loop()
{
    pinMode(COL, OUTPUT);
    digitalWrite(COL, LOW);

    pinMode(ROW, INPUT_PULLUP);
    Serial.println(digitalRead(ROW));
    delay(CMD_DELAY);
    pinMode(ROW, INPUT);
    pinMode(COL, INPUT); 
}