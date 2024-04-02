section .data
ZERO dq 0.0

section .text
bits 64
default rel

global asmSolveStencil
extern printf

asmSolveStencil:
    LEA RBX, [RDX]              ; RBX = Address of Y
    MOV R11, 0                  ; counter
    MOV R12, 0                  ;
    MOV R13, R8                 ; R9 = n
    MOV R14, 0                  ; R10 = loop counter
    MOV R15, 0

INITIALIZE:
    LEA RSI, [RCX]              ; RSI = Address of X
    MOVSD XMM2, [ZERO]
    IMUL R12, R11, 8
    ADD RSI, R12                ; Offset RSI by R8 (current) multiplied by 8 (size of double)
    JMP ADDING

ADDING:
    ADDSD XMM2, [RSI]           ; Add the double at address pointed by RSI to XMM2
    INC R14                     ; Increment loop counter
    CMP R14, 7                  ; Compare loop counter to 7
    JE TRANSFER                 ; If equal, transfer control to TRANSFER

    ADD RSI, 8                  ; Move to next double in X
    JMP ADDING                  ; Repeat loop

TRANSFER:
    MOVSD [RDX + R12], XMM2     ; Move the result from XMM2 to Y
    CMP R15, R13                ; Compare current with n
    JE END                      ; If equal, end

    INC R11                     ; Increment current
    INC R15
    MOV R14, 0
    JMP INITIALIZE              ; Repeat loop

END:
    ret                       ; Return