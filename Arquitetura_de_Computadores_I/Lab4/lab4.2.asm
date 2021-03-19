.data
	Zero.s: .word 0x00000000
	PlusInf.s: .word 0x7F800000
	MinusInf.s: .word 0xFF800000
	PlusNaN.s: .word 0x7F800020
	MinusNaN.s: .word 0xFF800002
	
	MyNum: .word 0x41A00000
	

.text 
	lwc1 $f1, PlusInf.s
	lwc1 $f2, MyNum
	add.s $f3, $f1, $f2
	mov.s  $f12, $f3
	li $v0, 2
	syscall