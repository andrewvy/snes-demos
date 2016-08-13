.p816 ; 65816 processor
.i16  ; X/Y are 16 bits
.a8   ; A is 8 bits

.segment "HEADER" ; At +$7FE0
  .byte ROM_NAME  ; ROM name

.segment "ROMINFO"  ; At +$7FD5
  .byte $30         ; LoROM, fast-capable
  .byte 0
  .byte $87
  .byte 0,0,0,0
  .word $AAAA,$5555 ; Dummy checksum and Complement

.segment "VECTORS"
  .word 0, 0, 0, 0, 0, 0, 0, 0
  .word 0, 0, 0, 0, 0, 0, reset, 0

.code

.macro init_cpu
  clc ; enable native mode
  xce
  rep #$10 ; X/Y is 16-bit
  sep #$20 ; A is 8-bit
.endmacro
