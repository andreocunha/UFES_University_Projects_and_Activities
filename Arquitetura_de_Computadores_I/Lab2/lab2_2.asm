.data	
var1: .word 'a'
var2: .word 'b'
var3: .word 'c'
var4: .word 'd'

primeiro: .byte 'A'
ultimo: .byte 'C'

.text
lw $t1, var1
lw $t2, var4
sw $t2, var1
sw $t1, var4

lw $t1, var2
lw $t2, var3
sw $t2, var2
sw $t1, var3