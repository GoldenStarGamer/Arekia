#pragma once
#include <efi.h>
#include <intrin>
static uint64_t ReadMSR(uint32_t msr);
static void WriteMSR(uint32_t msr, uint64_t value);

typedef enum {
    // IA-32 and x86_64 common MSRs
    MSR_IA32_APIC_BASE = 0x0000001B,
    MSR_IA32_SYSENTER_CS = 0x00000174,
    MSR_IA32_SYSENTER_ESP = 0x00000175,
    MSR_IA32_SYSENTER_EIP = 0x00000176,
    MSR_IA32_DEBUGCTL = 0x000001D9,
    MSR_IA32_FEATURE_CONTROL = 0x0000003A,
    MSR_IA32_PERF_STATUS = 0x00000198,
    MSR_IA32_PERF_CTL = 0x00000199,
    MSR_IA32_THERM_STATUS = 0x0000019C,
    MSR_IA32_MISC_ENABLE = 0x000001A0,
    MSR_IA32_PLATFORM_ID = 0x00000017,

    // MSRs related to SYSCALL/SYSRET (64-bit mode)
    MSR_IA32_EFER = 0xC0000080, // Extended Feature Enable Register
    MSR_IA32_STAR = 0xC0000081, // Segments for syscall/sysret
    MSR_IA32_LSTAR = 0xC0000082, // syscall target RIP
    MSR_IA32_CSTAR = 0xC0000083, // syscall target RIP (compat mode)
    MSR_IA32_FMASK = 0xC0000084, // RFLAGS mask on syscall
    MSR_IA32_FS_BASE = 0xC0000100, // FS segment base
    MSR_IA32_GS_BASE = 0xC0000101, // GS segment base
    MSR_IA32_KERNEL_GS_BASE = 0xC0000102, // Swap GS

    // TSC (Timestamp Counter) and timers
    MSR_IA32_TIME_STAMP_COUNTER = 0x00000010,
    MSR_IA32_TSC_DEADLINE = 0x000006E0,
    MSR_IA32_TSC_ADJUST = 0x00000003,

    // Virtualization-related MSRs
    MSR_IA32_VMX_BASIC = 0x00000480,
    MSR_IA32_VMX_PINBASED_CTLS = 0x00000481,
    MSR_IA32_VMX_PROCBASED_CTLS = 0x00000482,
    MSR_IA32_VMX_EXIT_CTLS = 0x00000483,
    MSR_IA32_VMX_ENTRY_CTLS = 0x00000484,


} IA32_MSR;

typedef enum {
    EFER_SCE = 1 << 0,   // SYSCALL/SYSRET Enable
    EFER_LME = 1 << 8,   // Long Mode Enable
    EFER_LMA = 1 << 10,  // Long Mode Active (read-only)
    EFER_NXE = 1 << 11,  // No-Execute Enable
    EFER_SVME = 1 << 12,  // Secure Virtual Machine Enable (AMD)
    EFER_LMSLE = 1 << 13,  // Long Mode Segment Limit Enable (AMD)
    EFER_FFXSR = 1 << 14   // Fast FXSAVE/FXRSTOR Enable
} EFER_FLAGS;