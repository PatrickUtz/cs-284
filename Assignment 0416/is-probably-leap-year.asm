; ----------------------------------------------------------------------------------------
;  Takes a command line argument for an integer year and computes whether that year is 
;  divisible by four
;  
;  To assemble and run:
;
;     nasm -felf64 is-probably-leap-year.asm && gcc -no-pie is-probably-leap-year.o && ./a.out #year 
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

        mov     rdi, [r12+8]            ; argv[1] the year
        call    atoi                    ; year in eax
        mov     r13d, eax               ; year in r13d

        mov     r14d, 4                 ; 4 years in r14d

subfour:
        cmp     r13d, 0                 ; check if divisible by 4 years
        jz      isLeap                  ; is a leap year
        jl      notLeap                 ; is not a leap year
        sub     r13d, r14d              ; subtract 4 years
        jmp     subfour        

isLeap:                                 ; print that the year is a leap year
        mov     rdi, isLeapAns
	    movsxd  rsi, eax
        xor     rax, rax
        call    printf
        jmp     done

notLeap:                                ; print that the year is not a leap year
        mov     rdi, notLeapAns
	    movsxd  rsi, eax
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

isLeapAns:
        db      "%d is probably a leap year.", 10, 0
notLeapAns:
        db      "%d is probably not a leap year.", 10, 0
badArgumentCount:
        db      "This program requires exactly one command line argument specifying a year.", 10, 0
