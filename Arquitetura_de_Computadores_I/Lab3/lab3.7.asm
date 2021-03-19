.data 
a: .word 0
b: .word 0

.text 
li $v0, 5 # system call for read_int (a)
syscall 
move $t0 $v0
sw $t0 a

li $v0, 5 # system call for read_int (b)
syscall 
move $t1 $v0
sw $t1 b


divu $t2, $t0, $t1 # mult $t0 and $t1
li  $v0, 1           # service 1 is print integer
move $a0 $t2 # move number to print in $a0
syscall
