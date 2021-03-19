.data
	msg: .asciiz  "Erro, deve ser um numero positivo"

.text 
	ReadInt:
		li $v0, 5
		syscall 
		move $t0 $v0
		move $t2, $t0
		slt $t1,$t0,$zero
		beq $t1, 1, PrintErro
	
	
	Fatorial:
		beq $t0, 0, PrintOne
		beq $t0, 1, PrintResult
		sub $t0, $t0, 1
		mul $t2, $t2, $t0
		jal Fatorial
		
	PrintOne:
		li  $v0, 1
		addi $t2, $zero, 1
        	mtc1 $t2, $f0
		cvt.s.w $f0, $f0
    		mov.s  $f12, $f0
        	li $v0, 2
		syscall
		jal Exit

	PrintResult: 
		mtc1 $t2, $f0
		cvt.s.w $f0, $f0
    		mov.s  $f12, $f0
        	li $v0, 2
		syscall
		jal Exit
		
	PrintErro:
		la $a0,msg
    		li $v0,4
    		syscall
		jal ReadInt
		
	Exit:
