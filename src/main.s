; Minimal example of using ca65
;
; ca65 main.s
; ld65 -C lorom128.cfg -o my_game.smc main.o
;
.define ROM_NAME "MYGAME"
.include "src/include/init.inc"

reset:
  init_cpu
  ldx #$333 ; Clear PPU registers
@loop: stz $2100,x
  dex
  bpl @loop

  ; Set Background Color to $03E0
  lda #$E0
  sta $2122
  lda #$03
  sta $2122

  ; Maximum screen brightness
  lda #$0F
  sta $2100

forever:
  jmp forever
