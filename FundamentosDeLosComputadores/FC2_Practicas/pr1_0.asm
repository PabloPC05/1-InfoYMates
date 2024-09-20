.data
    N: .word 10
.bss
    res: .zero 4
.text
    lw a0, 0(t0) //almacena en el registro a0 el valor de N
    la t2, res //almcaena en el registro t2 la direccion de res
    lw a1, 0(t0) //almacena en el registro a1 el valor de res
    mv t0, x0   //almacena i
    for:
        bge  t0, a0, efor
        add a1, a1, t0
        add t0, t0, 1
        j for
    efor:
        sw a1, 0(t2) //almacena en res el valor de a1
    end:
        j end


