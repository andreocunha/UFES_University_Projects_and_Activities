.data
teste: .word 0x04, 0x2000, 0x1000, 0x0800, 0x0400, 0x00, 0x00, 0x00, 0x00
msg: .asciiz "Entre com o ultimo digito do seu numero de matricula na Ufes: "

.text
li $v0, 4
la $a0, msg
syscall
li $v0, 5
syscall

move $t3, $v0
li $t0, 0x10010004
li $t1, 0x10010014
lui $at, 0x1001
lw $t2, 0($at)
loop:
beq $t2, $zero, exit
lw $t4, 0($t0)
#srlv $t4, $t4, $t3
sllv $t4, $t4, $t3
sw $t4, 0($t1)
addi $t2, $t2, -1
addi $t0, $t0, 4
addi $t1, $t1, 4
j loop

exit:
li $v0, 10
syscall