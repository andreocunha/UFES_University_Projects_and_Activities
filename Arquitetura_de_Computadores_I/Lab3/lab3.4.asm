.data 
a: .word 0
b: .word 0
quebra: .ascii "\n"

.text 
li $v0, 5 # system call for read_int (a)
syscall 
move $t0 $v0
sw $t0 a

li $v0, 5 # system call for read_int (b)
syscall 
move $t1 $v0
sw $t1 b

addu $t2, $t0, $t1 # add $t0 and $t1
li  $v0, 1           # service 1 is print integer
move $a0 $t2 # move number to print in $a0
syscall

# print \n
li $v0, 4 # system call for print_str
la $a0, quebra # address of string to print
syscall

subu $t3, $t0, $t1 # sub $t0 and $t1
li  $v0, 1           # service 1 is print integer
move $a0 $t3 # move number to print in $a0
syscall
