#include "MultiKey.h"

MultiKey::MultiKey(byte mod) : keys{Key(), Key()}, modifier(mod) {}
MultiKey::MultiKey(ConsumerKeycode k) : keys{k, k}, modifier(0) {}
MultiKey::MultiKey(KeyboardKeycode k) : keys{k, k}, modifier(0) {}
MultiKey::MultiKey(KeyboardKeycode k1, KeyboardKeycode k2) : keys{k1, k2}, modifier(0) {}
MultiKey::MultiKey(ConsumerKeycode k1, ConsumerKeycode k2) : keys{k1, k2}, modifier(0) {}
MultiKey::MultiKey(KeyboardKeycode k1, ConsumerKeycode k2) : keys{k1, k2}, modifier(0) {}
MultiKey::MultiKey(ConsumerKeycode k1, KeyboardKeycode k2) : keys{k1, k2}, modifier(0) {}

void MultiKey::press(byte &layer)
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

void MultiKey::release(byte &layer)
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
