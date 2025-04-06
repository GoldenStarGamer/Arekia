    .globl read_msr      # Make the function global
    .globl write_msr     # Make the function global
    .type read_msr, @function
    .type write_msr, @function

# Read MSR function (returns the 64-bit value of MSR)
read_msr:
    # Input: MSR address in %rdi (64-bit MSR address)
    # Output: MSR value in %rax (low 32 bits), %rdx (high 32 bits)

    mov %rdi, %ecx        # Move MSR address (passed in %rdi) to %ecx
    rdmsr                 # Read MSR, result is stored in %rdx:%rax
    ret

# Write MSR function (writes a 64-bit value to MSR)
write_msr:
    # Input: MSR address in %rdi (64-bit MSR address)
    # Input: MSR value in %rsi (low 32 bits) and %rdx (high 32 bits)
    
    mov %rdi, %ecx        # Move MSR address to %ecx
    mov %rsi, %eax        # Move the lower 32 bits of the value to %eax
    mov %rdx, %edx        # Move the upper 32 bits of the value to %edx
    wrmsr                 # Write MSR from %rdx:%rax to the MSR at address in %ecx
    ret
