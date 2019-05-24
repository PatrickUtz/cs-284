; ----------------------------------------------------------------------------------------
;  Takes a command line argument for a text file name and creates an empty text file in the 
;  same driectory as create_file.asm.
;
;  To assemble and run:
;
;     nasm -felf64 create_file.asm && gcc -no-pie create_file.o && ./a.out filename.txt
;
;           ^^where "filename" should be replaced with your desired filename^^
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

        cmp     rdi, 2                  ; must have 1 argument
        jne     error1

        mov     rax, 85                 ; move the system call for sys_create into rax
        
        mov     r12, rsi                ; read input of filename from command line (argv)
        mov     rdi, [r12+8]            ; argv[1] is the filename
        
        mov     rsi, 2                  ; set the flag to create a read and write file
       
        syscall                         ; create the file

        mov     rdi, answer             ; print if the operation was successful 
        mov     rsi, rax
        xor     rax, rax
        call    printf
        jmp     done
error1:                                 ; print error message if have wrong input
        mov     edi, badArgumentCount
        call    puts
        jmp     done

done:                                   ; restore saved registers
        pop     r14
        pop     r13
        pop     r12
        ret

answer:
        db      "Congrats! Your file has been created. %d is the file descriptor of your new file. ", 10, 0
badArgumentCount:
        db      "This program requires only one argument, the desired filename.", 10, 0
