main:
    addi $a0, $zero, 10 # n = 10
    addi $a1, $zero, 5  # m = 5
    jal pascal          # call pascal(10, 5)
    j exit

pascal:
    add $v0, $v0, $zero
    addi $sp, $sp, -12
    sw $ra, 0x0($sp)    # Save $ra register into stack
    # Save arguments and used variables into stack
    sw $a0, 0x4($sp)
    sw $a1, 0x8($sp)
    #sw $s0, 0xc($sp) 
    #--------------------------------------#
    # function pascal(n, m)
    # 	if (m == n || m == 0) 
    # 	    return 1
    # 	else
    # 	    return pascal(n - 1, m - 1) + pascal(n - 1, m)
    
    # if (m == n || m == 0)  return 1
    beq $a1, $a0, L1 
    beq $a1, $zero, L1
    
    # pascal(n - 1, m - 1)
    addi $a0, $a0, -1
    jal pascal
      
    # pascal(n - 1, m)
    addi $a1, $a1, -1
    jal pascal
    #--------------------------------------#
    
    #lw $s0, 0xc($sp)
    lw $a1, 0x8($sp) 
    lw $a0, 0x4($sp)
    lw $ra, 0x0($sp)    # Load $ra register from stack
    addi $sp, $sp, 12
    jr $ra
    
L1:
    # return value += 1
    addi $v0, $v0, 1    
    addi $sp, $sp, 12
    jr $ra
    
exit:
