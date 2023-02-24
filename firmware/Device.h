
#include "PluggableUSB.h"

class Device : public PluggableUSBModule
{
public:
    Device(
        const char *product = NULL,
        const char *manufacturer = NULL,
        const char *serial = NULL);
    int getInterface(uint8_t *interfaceCount);
    int getDescriptor(USBSetup &setup);
    bool setup(USBSetup &setup);

private:
    const char *manufacturer;
    const char *product;
    const char *serial;
    uint8_t epType[0];
};