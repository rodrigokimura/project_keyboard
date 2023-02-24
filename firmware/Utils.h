#include "HID-Project.h"

struct Coords
{
    const byte row;
    const byte col;
};

struct Size
{
    const byte rows;
    const byte columns;
};

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

struct MultiKey
{
    Key keys[2];
    byte modifier;

    MultiKey(ConsumerKeycode k) : keys{k, k}, modifier(0) {}
    MultiKey(KeyboardKeycode k) : keys{k, k}, modifier(0) {}
    MultiKey(KeyboardKeycode k1, KeyboardKeycode k2) : keys{k1, k2}, modifier(0) {}
    MultiKey(ConsumerKeycode k1, ConsumerKeycode k2) : keys{k1, k2}, modifier(0) {}
    MultiKey(KeyboardKeycode k1, ConsumerKeycode k2) : keys{k1, k2}, modifier(0) {}
    MultiKey(ConsumerKeycode k1, KeyboardKeycode k2) : keys{k1, k2}, modifier(0) {}

    MultiKey(Key k) : keys{k, k}, modifier(0) {}
    MultiKey(Key k1, Key k2) : keys{k1, k2}, modifier(0) {}
    MultiKey(byte mod) : keys{Key(), Key()}, modifier(mod) {}

    void press(byte &layer)
    {
        if (modifier == 1 || modifier == 2)
        {
            layer = modifier;
        }
        else
        {
            keys[layer > 0 ? 1 : 0].press();
        }
    }
    void release(byte &layer)
    {
        if (modifier > 0 && layer == modifier)
        {
            layer = 0;
        }
        else
        {
            keys[layer > 0 ? 1 : 0].release();
        }
    }
};
