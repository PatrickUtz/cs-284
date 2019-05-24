; ----------------------------------------------------------------------------------------
;  Takes a command line argument for a total number of cents and computes the number 
;  of quarters that can be changed for that amount
;  
;  To assemble and run:
;
;     nasm -felf64 make-quarter-change.asm && gcc -no-pie make-quarter-change.o && ./a.out 142 #cents
; ----------------------------------------------------------------------------------------

global  main
        extern  printf
        extern  puts
        extern  atoi

        section .text
main:
        push    r12                     ; save callee-save registers
        push    r13
        push    r14                     ; 3 registers pushed so stack aligned for calls

        cmp     rdi, 2                  ; must have exactly one argument
        jne     error1

        mov     r12, rsi                ; read input from command line (argv)

        mov     rdi, [r12+8]            ; argv[1] the total cents
        call    atoi                    ; total cents now in eax
        mov     r13d, eax               ; total cents in r13d
        mov     r12d, eax               ; total cents in r12d used for printing later

        mov     r14d, 25                ; 25 cents in r14d
	    mov 	eax, 0

subquart:
        cmp     r13d, 25                ; check how many quarters left
        jl      gotit                   ; done
        sub     r13d, r14d              ; subtract 25 cents
        inc     eax
        jmp     subquart

gotit:                                  ; print how many quarters are needed
        mov     rdi, answer
	    movsxd  rsi, eax
        movsxd  rdx, r12d
        xor     rax, rax
        call    printf
        jmp     done
error1:                                 ; print error message about wrong input
        mov     edi, badArgumentCount
        call    puts
        jmp     done

done:                                   ; restore saved registers
        pop     r14
        pop     r13
        pop     r12
        ret

answer:
        db      "%d quarters make partial change for %d cents.", 10, 0
badArgumentCount:
        db      "This program requires exactly one integer command line argument.", 10, 0
