segment code

..start:
    MOV 	AX, dados
    MOV 	DS, AX
    MOV 	ES,AX
    MOV 	AX, stack
    MOV 	SS,AX

    MOV 	SP,stacktop 
    
Main:
    call PrintMenu
    call ReadValue
    cmp dl, '1'
    je Soma
    
    Operation2:
    cmp dl, '2'
    je Subtracao
    
    Operation3:
    cmp dl, '3'
    je Multiplicacao
    
    Operation4:
    cmp dl, '4'
    je Divisao

    call Quit  

Soma:
    mov dx, Msg10
    call Println

    mov dx, Msg6
    call Println
	
	call ReadValue
	call PrintNewLine	

	mov [num1], al
	mov dl,[num1]

	mov ah, 2h ; display subprogram
	int 21h ; display character in dl
	call PrintNewLine
	mov di, [num1]
	call ascii2bin
	mov [num1],di

	mov dx, Msg7 ;segunda entrada
    call Println
	
	call ReadValue
	call PrintNewLine

	mov [num2], al
	mov dl,[num2]

	mov ah, 2h ; display subprogram
	int 21h ; display character in dl
	call PrintNewLine
	mov di, [num2]
	call ascii2bin


	mov cx,[num2]
	add [num1],cx
	
	mov di, [num1]
	call bin2ascii

	mov dl,[num1]
	mov ah, 2h ; display subprogram
	int 21h ; display character in dl
	call PrintNewLine

    jmp Main

Subtracao:
    mov dx, Msg11
    call Println
    jmp Main
Multiplicacao:
    mov dx, Msg12
    call Println
    jmp Main
Divisao:
    mov dx, Msg13
    call Println
    jmp Main

Print:
    ;push ax
    mov ah,0x9
    int 0x21
	;pop ax
    ret             	; retorna

Println:
    push ax
    mov ah,0x9
    int 0x21
	pop ax
    mov dx,CRLF  
    call Print
    ret             	; retorna

PrintNewLine:
	mov dx,CRLF  
    call Print
    ret            

PrintMenu:
    mov dx, Msg1		; Mensagem 1
    call Println      	; Chama a funcao Print
    
    mov dx, Msg2		; Mensagem 2
    call Println      	; Chama a funcao 
    
    mov dx, Msg3		; Mensagem 3
    call Println      	; Chama a funcao 
    
    mov dx, Msg4		; Mensagem 4
    call Println      	; Chama a funcao 
    ret

ReadValue:
    mov ah, 1h ; keyboard input subprogram
    int 21h ; read character into al
    mov dl, al ; copy character to dl
	ret			;


bin2ascii:
		CMP		DX,10
		JB		Uni
		CMP		DX,100 
		JB		Des
		CMP		DX,1000
		JB		Cen
		CMP		DX,10000
		JB		Mil
		JMP		Dezmil
			
Uni:	
		ADD		DX,0x0030
		MOV 	byte [DI],DL
		RET
Des:
		MOV 	AX,DX
		MOV		BL,10
		div		BL
		ADD		AH,0x30
		ADD		AL,0x30
		MOV 	byte [DI],AL
		MOV 	byte [DI+1],AH
		RET
Cen:		
		MOV 	AX,DX
		MOV		BL,100
		DIV		BL
		ADD		AL,0x30
		MOV 	byte [DI],AL
		MOV 	AL,AH
		AND		AX,0x00FF
		MOV		BL,10
		DIV		BL
		ADD		AH,0x30
		ADD		AL,0x30
		MOV 	byte [DI+1],AL		
		MOV 	byte [DI+2],AH
		RET
Mil:		
		MOV 	AX,DX
		MOV     DX,0
		MOV		BX,1000
		DIV		BX
		ADD		AL,0x30
		MOV 	byte [DI],AL
		MOV 	AX,DX
		MOV		BL,100
		DIV		BL
		ADD		AL,0x30
		MOV 	byte [DI+1],AL		
		MOV 	AL,AH
	    AND     AX,0x00FF
		MOV		BL,10
		DIV		BL
		ADD		AH,0x30
		ADD		AL,0x30
		MOV 	byte [DI+2],AL		
		MOV 	byte [DI+3],AH
		RET
Dezmil:
		MOV 	AX,DX
		MOV     DX,0
		MOV		BX,10000
		DIV		BX
		ADD		AL,0x30
		MOV 	byte [DI],AL
		MOV		AX,DX		
		MOV     DX,0
		MOV		BX,1000
		DIV		BX
		ADD		AL,0x30
		MOV 	byte [DI+1],AL
		MOV 	AX,DX
		MOV		BL,100
		DIV		BL
		ADD		AL,0x30
		MOV 	byte [DI+2],AL		
		MOV 	AL,AH
	    AND     AX,0x00FF
		MOV		BL,10
		DIV		BL
		ADD		AH,0x30
		ADD		AL,0x30
		MOV 	byte [DI+3],AL		
		MOV 	byte [DI+4],AH
		RET


ascii2bin:
		CMP		DL,0x30
		JB		Uni2
		CMP		DL,0x37
		JB		Des2
		CMP		DL,0x3B
		JB		Cen2
		CMP		DL,0x40
		JB		Mil2
		JMP		Dezmil2
			
Uni2:	
		SUB		DL,0x30
		MOV 	byte [DI],DL
		RET
Des2:
		SUB		DL,0x30
		MOV		BL,10
		MUL		BL
		MOV 	byte [DI],AL
		MOV 	byte [DI+1],AH
		RET
Cen2:
		SUB		DL,0x30
		MOV		BL,100
		MUL		BL
		MOV 	byte [DI],AL
		MOV 	byte [DI+1],AH
		MOV		BL,10
		MUL		BL
		MOV 	byte [DI+2],AL
		MOV 	byte [DI+3],AH
		RET
Mil2:
		SUB		DL,0x30
		MOV		BX,1000
		MUL		BX
		MOV 	byte [DI],AL
		MOV 	byte [DI+1],AH
		MOV		BL,100
		MUL		BL
		MOV 	byte [DI+2],AL
		MOV 	byte [DI+3],AH
		MOV		BL,10
		MUL		BL
		MOV 	byte [DI+4],AL
		MOV 	byte [DI+5],AH
		RET
Dezmil2:
		SUB		DL,0x30
		MOV		BX,10000
		MUL		BX
		MOV 	byte [DI],AL
		MOV 	byte [DI+1],AH
		MOV		BX,1000
		MUL		BX
		MOV 	byte [DI+2],AL
		MOV 	byte [DI+3],AH
		MOV		BL,100
		MUL		BL
		MOV 	byte [DI+4],AL
		MOV 	byte [DI+5],AH
		MOV		BL,10
		MUL		BL
		MOV 	byte [DI+6],AL
		MOV 	byte [DI+7],AH
		RET



Quit:
    MOV AH,4CH ; retorna para o DOS com código 0
    INT 21h  


SEGMENT dados  ; Segment containing initialized data

	Zero128Bits DW  0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	DosA31	DW  	0x0000,0x8000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	;num1    DW 	    0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	;num2	DW	    0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	prd 	DW	    0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	tmp     DW	    0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

  	Msg1   DB "1 - SOMA $"
	Msg2   DB "2 - SUBTRACAO $"
	Msg3   DB "3 - MULTIPLICACAO $"
	Msg4   DB "4 - DIVISAO $"
	Msg9   DB "(ESC) - SAIR $"
	
	Msg5   DB "Qual o numero da operacao? $"

	Msg6   DB "Primeiro operando: $"
	Msg7   DB "Segundo operando: $"

	Msg8   DB "RESULTADO = $"

	Msg10   DB "Sua escolha -> SOMA $" 
	Msg11   DB "Sua escolha -> SUBTRACAO $" 
	Msg12   DB "Sua escolha -> MULTIPLICACAO $" 
	Msg13   DB "Sua escolha -> DIVISAO $" 
	
	Msg14	DB "#### Error nao pode dividir por 0 ####$"

	Buff   DB "000000000000000000000000000000$"

	Res    DB "000000000000000000000$"	

	OperA  DB "0000000000000000000000000$"
	
	num1 db 2000h
	num2 db 3000h

	CRLF   DB   0DH,0AH,'$'

	strCero DB '0'



SEGMENT stack stack                          	
resb 1024      		
stacktop:         