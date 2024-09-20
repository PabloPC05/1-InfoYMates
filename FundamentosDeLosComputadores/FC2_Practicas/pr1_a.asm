/*---------------------------------------------------------------------
**
**  Fichero:
**    pr1_a.asm  19/10/2022
**
**    (c) Pablo Pardo Cotos
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 1a
**
**  Notas de diseño:
**
**	# define N 10
**	int res = 0;
**	for (int i = 0; i < N ; i ++) {
**		res += i ;
**	}
**
**-------------------------------------------------------------------*/

//defino la constante N
.equ N, 10
//reservo espacio para el resultado
.bss
	res: 	.space 4
//programa
.text
.global main
main:
    la t1, N //almacena en t1 la direccion de N
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
