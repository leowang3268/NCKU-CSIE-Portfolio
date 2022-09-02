main:
    addi $a0, $zero, 19654 # a0= 19654
    addi $a1, $zero, 100654  # a1=100654
    addi $a2, $zero, 10065  # a2= 10065
    jal average     # call average
    j exit

average:
    addi $sp, $sp, -4
    sw $ra, 0x0($sp)    # Save $ra register into stack
    
    # a / 3 = a * (1 / 4 + 1 / 16 + 1 / 64 + ...) = a *¡a(1/4) / [1 - (1/4)]¡b
    #--------------------------------------#
    add $s0, $a0, $a1 
    add $s0, $s0, $a2 # Store the sum of three numbers into $s0
    srl $s1, $s0, 2 # a >>2
    srl $v0, $s0, 4 # a>>4
    add $v0, $v0, $s1 # a>>2 + a>>4
    srl $s1, $v0, 4 # a>>6 + a>>8
    add $v0, $v0, $s1 # a>>2 + a>>4 + a>>6 + a>>8
    srl $s1, $v0, 8 # a>>10 + a>>12 + a>>14 + a>>16
    add $v0, $v0, $s1 # a>>2 + a>>4 + a>>6 + a>>8 + a>>10 + a>>12 + a>>14 + a>>16
    srl $s1, $v0, 16 # ......
    add $v0, $v0, $s1 # a>>2 + ... + a>>30 + a>>32
    
    # check whether the answer is smaller than the correct one, since shiftting right may lose bits
    add $t0, $v0, $v0
    add $t0, $t0, $v0
    addi $t2, $s0, -2 # answer * 3 must at least be (a - 2)
 
   Loop:
    slt $t1, $t0, $t2
    beq $t1, $zero, L1
    addi $v0, $v0, 1
    addi $t0, $t0, 3
    j Loop
    #--------------------------------------#
    
    L1:    
    lw $ra, 0x0($sp)    # Load $ra register from stack
    addi $sp, $sp, 4
    jr $ra

exit:
