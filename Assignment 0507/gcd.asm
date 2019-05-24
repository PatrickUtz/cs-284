; ----------------------------------------------------------------------------------------
;  Euclid’s algorithm for calculating the greatest common divisor (GCD) of two numbers as a 
;  function in assembly language
;  
;  To assemble and run:
;
;     nasm -felf64 gcd.asm && gcc -no-pie callgcd.c gcd.o && ./a.out x y
; ----------------------------------------------------------------------------------------
        
        global  gcd       ; uint64_t gcd(uint64_t x, uint64_t y)

        section .text
gcd:
        push    r9
        push    r10
        push    r11
        push    r12
        push    r13
        push    r14
        push    r15

        mov     r11, rdi        ; move the value of x into r11
        mov     r12, rsi        ; move the value of y into r12
        mov     r13, 1          ; move the base divisor, 1, into r13
        mov     r9, 1           ; move the base GCD, 1, into r9 -> this will store the gcd 

        cmp     r12, r11
        jl      switch          ; switch so that lower value is in r11 and higher value is in r12
back:
        cmp     r11, 0          ; check if either value is 0 and return the other value
        je      returnHigher
        cmp     r12, 0
        je      returnLower

        cmp     r11, r12        ; check if values are the same
        je      returnLower

        mov     rdx, 0
        mov     rax, r12
        div     r11        	; handle case where lower value is gcd
        cmp     rdx, 0
        je      returnLower  

check: 
        cmp     r11, r13        ; check if the divisor is the same as the lower value
        je      done            ; if they are the same then the loop is done

        mov     rdx, 0
        mov     rax, r11
        div     r13
        cmp     rdx, 0          ; check if the modulus is 0
        jne     next
        mov     r10, rax        ; modulus of lower division is 0 -> move into r10
        
        mov     rdx, 0
        mov     rax, r12
        div     r13
        cmp     rdx, 0          ; check if the modulus is 0
        jne     next    
        
        mov     r9, r13         ; both moduluses are equal to zero -> possible GCD and move to r9
        add     r13, 1
        jmp     check 

next:
        add     r13, 1
        jmp     check
        
switch:
        mov     r15, r12        ; take the lower value in r12 and swap it with the higher value in r12
        mov     r12, r11
        mov     r11, r15
        jmp     back        

returnLower:
        mov     r9, r11         ; move lower value to r9 which is the GCD
        jmp     done

returnHigher:
        mov     r9, r12         ; move higher value to r9 which is the GCD
        jmp     done

done:
        mov    rax, r9          ; move r9 into rax which will be returned and is the GCD

        pop    r15              ; free up space taken up by program
        pop    r14
        pop    r13
        pop    r12
        pop    r11
        pop    r10
        pop    r9            

        ret                     ; end program