                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 28 2016) (Linux)
                                      4 ; This file was generated Mon Dec  3 17:37:04 2018
                                      5 ;--------------------------------------------------------
                                      6 	.module main
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _main
                                     13 	.globl _mdelay
                                     14 ;--------------------------------------------------------
                                     15 ; ram data
                                     16 ;--------------------------------------------------------
                                     17 	.area DATA
                                     18 ;--------------------------------------------------------
                                     19 ; ram data
                                     20 ;--------------------------------------------------------
                                     21 	.area INITIALIZED
                                     22 ;--------------------------------------------------------
                                     23 ; Stack segment in internal ram 
                                     24 ;--------------------------------------------------------
                                     25 	.area	SSEG
      000001                         26 __start__stack:
      000001                         27 	.ds	1
                                     28 
                                     29 ;--------------------------------------------------------
                                     30 ; absolute external ram data
                                     31 ;--------------------------------------------------------
                                     32 	.area DABS (ABS)
                                     33 ;--------------------------------------------------------
                                     34 ; interrupt vector 
                                     35 ;--------------------------------------------------------
                                     36 	.area HOME
      008000                         37 __interrupt_vect:
      008000 82 00 80 83             38 	int s_GSINIT ;reset
      008004 82 00 00 00             39 	int 0x0000 ;trap
      008008 82 00 00 00             40 	int 0x0000 ;int0
      00800C 82 00 00 00             41 	int 0x0000 ;int1
      008010 82 00 00 00             42 	int 0x0000 ;int2
      008014 82 00 00 00             43 	int 0x0000 ;int3
      008018 82 00 00 00             44 	int 0x0000 ;int4
      00801C 82 00 00 00             45 	int 0x0000 ;int5
      008020 82 00 00 00             46 	int 0x0000 ;int6
      008024 82 00 00 00             47 	int 0x0000 ;int7
      008028 82 00 00 00             48 	int 0x0000 ;int8
      00802C 82 00 00 00             49 	int 0x0000 ;int9
      008030 82 00 00 00             50 	int 0x0000 ;int10
      008034 82 00 00 00             51 	int 0x0000 ;int11
      008038 82 00 00 00             52 	int 0x0000 ;int12
      00803C 82 00 00 00             53 	int 0x0000 ;int13
      008040 82 00 00 00             54 	int 0x0000 ;int14
      008044 82 00 00 00             55 	int 0x0000 ;int15
      008048 82 00 00 00             56 	int 0x0000 ;int16
      00804C 82 00 00 00             57 	int 0x0000 ;int17
      008050 82 00 00 00             58 	int 0x0000 ;int18
      008054 82 00 00 00             59 	int 0x0000 ;int19
      008058 82 00 00 00             60 	int 0x0000 ;int20
      00805C 82 00 00 00             61 	int 0x0000 ;int21
      008060 82 00 00 00             62 	int 0x0000 ;int22
      008064 82 00 00 00             63 	int 0x0000 ;int23
      008068 82 00 00 00             64 	int 0x0000 ;int24
      00806C 82 00 00 00             65 	int 0x0000 ;int25
      008070 82 00 00 00             66 	int 0x0000 ;int26
      008074 82 00 00 00             67 	int 0x0000 ;int27
      008078 82 00 00 00             68 	int 0x0000 ;int28
      00807C 82 00 00 00             69 	int 0x0000 ;int29
                                     70 ;--------------------------------------------------------
                                     71 ; global & static initialisations
                                     72 ;--------------------------------------------------------
                                     73 	.area HOME
                                     74 	.area GSINIT
                                     75 	.area GSFINAL
                                     76 	.area GSINIT
      008083                         77 __sdcc_gs_init_startup:
      008083                         78 __sdcc_init_data:
                                     79 ; stm8_genXINIT() start
      008083 AE 00 00         [ 2]   80 	ldw x, #l_DATA
      008086 27 07            [ 1]   81 	jreq	00002$
      008088                         82 00001$:
      008088 72 4F 00 00      [ 1]   83 	clr (s_DATA - 1, x)
      00808C 5A               [ 2]   84 	decw x
      00808D 26 F9            [ 1]   85 	jrne	00001$
      00808F                         86 00002$:
      00808F AE 00 00         [ 2]   87 	ldw	x, #l_INITIALIZER
      008092 27 09            [ 1]   88 	jreq	00004$
      008094                         89 00003$:
      008094 D6 80 FB         [ 1]   90 	ld	a, (s_INITIALIZER - 1, x)
      008097 D7 00 00         [ 1]   91 	ld	(s_INITIALIZED - 1, x), a
      00809A 5A               [ 2]   92 	decw	x
      00809B 26 F7            [ 1]   93 	jrne	00003$
      00809D                         94 00004$:
                                     95 ; stm8_genXINIT() end
                                     96 	.area GSFINAL
      00809D CC 80 80         [ 2]   97 	jp	__sdcc_program_startup
                                     98 ;--------------------------------------------------------
                                     99 ; Home
                                    100 ;--------------------------------------------------------
                                    101 	.area HOME
                                    102 	.area HOME
      008080                        103 __sdcc_program_startup:
      008080 CC 80 C2         [ 2]  104 	jp	_main
                                    105 ;	return from main will return to caller
                                    106 ;--------------------------------------------------------
                                    107 ; code
                                    108 ;--------------------------------------------------------
                                    109 	.area CODE
                                    110 ;	main.c: 19: void mdelay(unsigned int ms)
                                    111 ;	-----------------------------------------
                                    112 ;	 function mdelay
                                    113 ;	-----------------------------------------
      0080A0                        114 _mdelay:
      0080A0 52 04            [ 2]  115 	sub	sp, #4
                                    116 ;	main.c: 22: for(i = 0; i < ms; i++) {
      0080A2 5F               [ 1]  117 	clrw	x
      0080A3 1F 01            [ 2]  118 	ldw	(0x01, sp), x
      0080A5                        119 00107$:
      0080A5 16 01            [ 2]  120 	ldw	y, (0x01, sp)
      0080A7 93               [ 1]  121 	ldw	x, y
      0080A8 13 07            [ 2]  122 	cpw	x, (0x07, sp)
      0080AA 24 13            [ 1]  123 	jrnc	00109$
                                    124 ;	main.c: 23: for(x = 0; x < 100; x++);
      0080AC AE 00 64         [ 2]  125 	ldw	x, #0x0064
      0080AF                        126 00105$:
      0080AF 5A               [ 2]  127 	decw	x
      0080B0 1F 03            [ 2]  128 	ldw	(0x03, sp), x
      0080B2 1E 03            [ 2]  129 	ldw	x, (0x03, sp)
      0080B4 16 03            [ 2]  130 	ldw	y, (0x03, sp)
      0080B6 26 F7            [ 1]  131 	jrne	00105$
                                    132 ;	main.c: 22: for(i = 0; i < ms; i++) {
      0080B8 1E 01            [ 2]  133 	ldw	x, (0x01, sp)
      0080BA 5C               [ 2]  134 	incw	x
      0080BB 1F 01            [ 2]  135 	ldw	(0x01, sp), x
      0080BD 20 E6            [ 2]  136 	jra	00107$
      0080BF                        137 00109$:
      0080BF 5B 04            [ 2]  138 	addw	sp, #4
      0080C1 81               [ 4]  139 	ret
                                    140 ;	main.c: 27: void main()
                                    141 ;	-----------------------------------------
                                    142 ;	 function main
                                    143 ;	-----------------------------------------
      0080C2                        144 _main:
                                    145 ;	main.c: 31: PB_DDR |= 0x20;
      0080C2 AE 50 07         [ 2]  146 	ldw	x, #0x5007
      0080C5 F6               [ 1]  147 	ld	a, (x)
      0080C6 AA 20            [ 1]  148 	or	a, #0x20
      0080C8 F7               [ 1]  149 	ld	(x), a
                                    150 ;	main.c: 32: PB_CR1 |= 0x20;
      0080C9 AE 50 08         [ 2]  151 	ldw	x, #0x5008
      0080CC F6               [ 1]  152 	ld	a, (x)
      0080CD AA 20            [ 1]  153 	or	a, #0x20
      0080CF F7               [ 1]  154 	ld	(x), a
                                    155 ;	main.c: 33: PB_CR2 |= 0x00;
      0080D0 AE 50 09         [ 2]  156 	ldw	x, #0x5009
      0080D3 F6               [ 1]  157 	ld	a, (x)
      0080D4 AE 50 09         [ 2]  158 	ldw	x, #0x5009
      0080D7 F7               [ 1]  159 	ld	(x), a
                                    160 ;	main.c: 35: while (1) {
      0080D8                        161 00102$:
                                    162 ;	main.c: 36: PB_ODR ^= 0x00;
      0080D8 AE 50 05         [ 2]  163 	ldw	x, #0x5005
      0080DB F6               [ 1]  164 	ld	a, (x)
      0080DC AE 50 05         [ 2]  165 	ldw	x, #0x5005
      0080DF F7               [ 1]  166 	ld	(x), a
                                    167 ;	main.c: 38: mdelay(1000);
      0080E0 4B E8            [ 1]  168 	push	#0xe8
      0080E2 4B 03            [ 1]  169 	push	#0x03
      0080E4 CD 80 A0         [ 4]  170 	call	_mdelay
      0080E7 5B 02            [ 2]  171 	addw	sp, #2
                                    172 ;	main.c: 40: PB_ODR ^= 0xf0;
      0080E9 AE 50 05         [ 2]  173 	ldw	x, #0x5005
      0080EC F6               [ 1]  174 	ld	a, (x)
      0080ED A8 F0            [ 1]  175 	xor	a, #0xf0
      0080EF F7               [ 1]  176 	ld	(x), a
                                    177 ;	main.c: 42: mdelay(1000);
      0080F0 4B E8            [ 1]  178 	push	#0xe8
      0080F2 4B 03            [ 1]  179 	push	#0x03
      0080F4 CD 80 A0         [ 4]  180 	call	_mdelay
      0080F7 5B 02            [ 2]  181 	addw	sp, #2
      0080F9 20 DD            [ 2]  182 	jra	00102$
      0080FB 81               [ 4]  183 	ret
                                    184 	.area CODE
                                    185 	.area INITIALIZER
                                    186 	.area CABS (ABS)
