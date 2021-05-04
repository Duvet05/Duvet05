section .text
    global  function_calculationBinASM

function_calculationBinASM:
	xorps       xmm0,   xmm0      
    xorps       xmm1,   xmm1
    xorps       xmm2,   xmm2
	xor         r9,     r9
    inc         r9
    cvtsi2sd    xmm0,   r9
    cvtsi2sd    xmm1,   r9   
	cvtsi2sd    xmm2,   rdi
    divsd       xmm1,   xmm2   	
	addsd       xmm1,   xmm0 
	mov         r9,     rdi
    xor         r8,     r8   
    log_loop:
        and         r8,     00000001 ;Me salio de chiripa :v
        jz          not_1
        mulsd       xmm0,   xmm1
        not_1:
            mulsd       xmm1,   xmm1
            shr         r9,     1 
            mov         r8,     r9
            cmp         r9,     0
		    jne         log_loop	
ret

