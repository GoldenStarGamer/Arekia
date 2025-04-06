#include <efi.h>
#include <efilib.h>
#include <libsmbios.h>
#include "MSR.h"

static uint64_t ReadMSR(uint32_t msr)
{
    unsigned long low, high;
    read_msr(msr, &low, &high);
    return ((uint64_t)high << 32) | low;
}

static void WriteMSR(uint32_t msr, uint64_t value)
{
    unsigned long low = (unsigned long)(value & 0xFFFFFFFF);
    unsigned long high = (unsigned long)(value >> 32);
    write_msr(msr, low, high);
}

extern void read_msr(unsigned long msr, unsigned long* low, unsigned long* high);
extern void write_msr(unsigned long msr, unsigned long low, unsigned long high);