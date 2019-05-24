; ----------------------------------------------------------------------------------------
;  A program that uses reverse-range-in-place.c to echo its command-line arguments, including 
;  the program name, but in reverse.
;  
;  To assemble and run:
;
;     nasm -felf64 reverse-echo.asm && gcc -no-pie reverse-echo.o reverse-range-in-place.c && ./a.out string_to_reverse
; ----------------------------------------------------------------------------------------

        global  main
        extern  puts
        extern  strlen
        extern  reverse_range_in_place

        section .text
main:
        push    r12                     ; save r12 that will be used for reading inputs from the command line
        push    rdi                     ; save registers that puts uses
        push    rsi                     ; on entry, rdi will contain argc and rsi will contain argv
        sub     rsp, 8                  ; must align stack before call

        mov     r12, rsi                ; move pointer of string into r12
        mov     rdi, [r12]              ; the argument string to reverse
        call    strlen                  ; length of argument is now in rax
                
        mov     rdi, [r12]              ; set char* string to current string
        mov     rsi, 0                  ; set the start_index for where to reverse to be 0
        mov     rdx, rax                ; set the end_index for where to reverse to be end of string (from strlen)
        call    reverse_range_in_place  ; call the reverse string function -> result in r12

        mov     rdi, [r12]              ; move the result of the reverse string function to rdi and print 
        call    puts


        add     rsp, 8                  ; restore %rsp to pre-aligned value
        pop     rsi                     ; restore registers puts used
        pop     rdi
        pop     r12                     ; restore r12 

        add     rsi, 8                  ; point to next argument
        dec     rdi                     ; count down
        jnz     main                    ; if not done counting keep going
        
        ret