;
; File generated by cc65 v 2.17 - Git 180bb082
;
	.fopt		compiler,"cc65 v 2.17 - Git 180bb082"
	.setcpu		"65SC02"
	.smart		on
	.autoimport	on
	.case		on
	.debuginfo	off
	.importzp	sp, sreg, regsave, regbank
	.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
	.macpack	longbranch
	.forceimport	__STARTUP__
	.import		_wait
	.import		_rs232_tx
	.export		_main

.segment	"RODATA"

L0012:
	.byte	$48,$65,$6C,$6C,$6F,$20,$57,$6F,$72,$6C,$64,$21,$00

; ---------------------------------------------------------------
; int __near__ main (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_main: near

.segment	"CODE"

L0002:	ldy     #$00
	jsr     _wait
	bra     L0017
L0016:	lda     $1000
	cmp     #$3F
	bne     L0017
	lda     #<(L0012)
	ldx     #>(L0012)
	jsr     _rs232_tx
L0017:	lda     $1001
	and     #$02
	beq     L0016
	bra     L0002

.endproc

