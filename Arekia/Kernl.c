#include <efi.h>
#include <efilib.h>
#include <libsmbios.h>
#include "Kernl.h"
#include "MSR.h"

EFI_STATUS KernelMain()
{
	uint64_t efer = ReadMSR(MSR_IA32_EFER);
	efer |= EFER_LME | EFER_NXE;
	WriteMSR(MSR_IA32_EFER, efer);
	return EFI_SUCCESS;
}


