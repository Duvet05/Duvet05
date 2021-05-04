
set logging file output.txt
set logging on
set print pretty on
set disassembly-flavor intel
set pagination off
set args 10
file CalculationLimitBin
b function_calculationBin
r
define hook-echo
echo <<<------------
end
define hookpost-echo    
echo ------------>>>\n
end
echo Valores de los registros C
delete 1
b 36
c
printf "Base: %f X: %f\n", (double)base, (int)x
delete 2

b function_calculationBinASM
b 16
c
delete 3
info r r8 r9 rdi
p $xmm0
p $xmm1
p $xmm2
b 27
echo Respuesta en ASM (v4_float[1])
p $xmm0
c