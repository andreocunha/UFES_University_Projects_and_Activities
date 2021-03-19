.data
	dim: .word 2
	a: .float 0.756 -1.567
	c: .float -2.675, 3.657
	r: .float 0 0

.text
	li $t0, 0
	li $t2, 4
	lw $t4, dim
	
	loop:
    		mul $t1, $t0, $t2
    		l.s  $f2, a($t1)
    		l.s  $f3, c($t1)
    		add.s  $f1, $f2, $f3
    		s.s $f1, r($t1)
    		addi $t0, $t0, 1
    		blt $t0, $t4, loop