

ENTRY(Startup)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 256K
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

EndOfSRAM = ORIGIN(SRAM) + LENGTH(SRAM)

SECTIONS
{
    .isr_vector :
    {

    }

    .text :
    {
        *(.text)
    }>FLASH

    .rodata :
    {
        *(.rodata)
    }>FLASH

    .data :
    {
        *(.data)
    }>SRAM AT> FLASH

    .bss :
    {
        *(.bss)
    }>SRAM
}
