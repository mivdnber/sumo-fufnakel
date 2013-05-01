void YourHighPriorityISRCode();
void YourLowPriorityISRCode();

// vector remapping
// Bootloader occupies addresses 0x000-0x1FFF and thus cannot be used.
// Thus adresses 0x00, 0x08 and 0x18 (used for reset, high prior interrupt,
// and low prior interrupt) have to be remapped.
extern void _startup(void);
#pragma code REMAPPED_RESET_VECTOR = 0x2000
void _reset(void) {
    _asm goto _startup _endasm
}

#pragma code REMAPPED_HIGH_INTERRUPT_VECTOR = 0x2008

void Remapped_High_ISR(void) {
    _asm goto YourHighPriorityISRCode _endasm
}
#pragma code REMAPPED_LOW_INTERRUPT_VECTOR = 0x2018
void Remapped_Low_ISR(void) {
    _asm goto YourLowPriorityISRCode _endasm
}

#pragma code HIGH_INTERRUPT_VECTOR = 0x08
void High_ISR(void) {
    _asm goto 0x2008 _endasm
}

#pragma code LOW_INTERRUPT_VECTOR = 0x18
void Low_ISR(void) {
    _asm goto 0x2018 _endasm
}

#pragma code

// Interrupt handler routines
#pragma interrupt YourHighPriorityISRCode
void YourHighPriorityISRCode() {
    //Check which interrupt flag caused the interrupt
    //Service the interrupt
    //Clear the interrupt flag
}

#pragma interruptlow YourLowPriorityISRCode
void YourLowPriorityISRCode() {
    // Check which interrupt flag caused the interrupt
    // Service the interrupt
    // Clear the interrupt flag
}