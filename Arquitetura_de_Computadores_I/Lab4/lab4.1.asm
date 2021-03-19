.data
	Zero.s: .word 0x00000000
	PlusInf.s: .word 0x7F800000
	MinusInf.s: .word 0xFF800000
	PlusNaN.s: .word 0x7F800020
	MinusNaN.s: .word 0xFF800002
	
	Zero.d:     .word 0x00000000 0x00000000
	PlusInf.d:  .word 0x00000000 0x7FF00000
	MinusInf.d: .word 0x00000000 0xFFF00000
	PlusNaN.d:  .word 0x00000020 0x7FF00000
	MinusNaN.d: .word 0x00000002 0xFFF00000
	
	quebra: .ascii "\n"

.text
	# float results
	
	lwc1 $f0, Zero.s
	mov.s  $f12, $f0
	jal printfloat
	
	lwc1 $f1, PlusInf.s
	mov.s  $f12, $f1
	jal printfloat
	
	lwc1 $f2, MinusInf.s
	mov.s  $f12, $f2
	jal printfloat
	
	lwc1 $f3, PlusNaN.s
	mov.s  $f12, $f3
	jal printfloat
	
	lwc1 $f4, MinusNaN.s
	mov.s  $f12, $f4
	jal printfloat
	
	# double results

	lwc1 $f6, Zero.d
	lwc1 $f7, Zero.d+4
	mov.d $f12, $f6
	jal printdouble

	lwc1 $f8, PlusInf.d
	lwc1 $f9, PlusInf.d+4
	mov.d $f12, $f8
	jal printdouble

	lwc1 $f10, MinusInf.d
	lwc1 $f11, MinusInf.d+4
	mov.d $f12, $f10
	jal printdouble

	lwc1 $f14, PlusNaN.d
	lwc1 $f15, PlusNaN.d+4
	mov.d $f12, $f14
	jal printdouble

	lwc1 $f16, MinusNaN.d
	lwc1 $f17, MinusNaN.d+4
	mov.d $f12, $f16
	jal printdouble
	
	
	li $v0, 10 #finish
	syscall 


	printfloat:
		li $v0, 2
		syscall
		li $v0, 4 # system call for print_str
		la $a0, quebra # address of string to print
		syscall # print \n
		jr $ra # return
		
	printdouble:
		li $v0, 3
		syscall
		li $v0, 4 # system call for print_str
		la $a0, quebra # address of string to print
		syscall # print \n
		jr $ra # return
