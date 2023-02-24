#include "Device.h"

static bool SendControl(u8 d)
{
    return USB_SendControl(0, &d, 1) == 1;
}

static bool USB_SendStringDescriptor(const char *string_P)
{
    const u8 strL = strlen(string_P);
    SendControl(2 + strL * 2);
    SendControl(3);
    for (u8 i = 0; i < strL; i++)
    {
        bool r = SendControl(string_P[i]);
        r &= SendControl(0); // high byte
        if (!r)
            return false;
    }
    return true;
}

Device::Device(
    const char *product,
    const char *manufacturer,
    const char *serial) : manufacturer(manufacturer),
                          product(product),
                          serial(serial),
                          PluggableUSBModule(1, 1, epType)
{
    PluggableUSB().plug(this);
}

int Device::getInterface(uint8_t *interfaceCount)
{
    return 0;
}

int Device::getDescriptor(USBSetup &setup)
{
    if (setup.wValueH != USB_STRING_DESCRIPTOR_TYPE)
        return 0;

    switch (setup.wValueL)
    {
    case IMANUFACTURER:
        return USB_SendStringDescriptor(manufacturer);
    case IPRODUCT:
        return USB_SendStringDescriptor(product);
    case ISERIAL:
        return USB_SendStringDescriptor(serial);

    default:
        return 0;
    }
}

bool Device::setup(USBSetup &setup)
{
    return false;
}