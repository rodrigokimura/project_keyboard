#include "HID-Project.h"

struct Key
{
    const int key;
    const bool isMedia;
    bool pressed;

    Key(ConsumerKeycode k) : key(k), isMedia(true), pressed(false) {}
    Key(KeyboardKeycode k) : key(k), isMedia(false), pressed(false) {}
    Key() : key(KEY_RESERVED), isMedia(false), pressed(false) {}

    void press()
    {
        if (pressed)
            return;
        if (isMedia == true)
        {
            Keyboard.press(ConsumerKeycode(key));
        }
        else
        {
            Keyboard.press(KeyboardKeycode(key));
        }
        pressed = true;
    }

    void release()
    {
        if (!pressed)
            return;
        if (isMedia == true)
        {
            Keyboard.release(ConsumerKeycode(key));
        }
        else
        {
            Keyboard.release(KeyboardKeycode(key));
        }
        pressed = false;
    }
};

class MultiKey
{
public:
    MultiKey(byte mod);
    MultiKey(ConsumerKeycode k);
    MultiKey(KeyboardKeycode k);
    MultiKey(KeyboardKeycode k1, KeyboardKeycode k2);
    MultiKey(ConsumerKeycode k1, ConsumerKeycode k2);
    MultiKey(KeyboardKeycode k1, ConsumerKeycode k2);
    MultiKey(ConsumerKeycode k1, KeyboardKeycode k2);

    void press(byte &layer);
    void MultiKey::release(byte &layer);

private:
    Key keys[2];
    byte modifier;
};