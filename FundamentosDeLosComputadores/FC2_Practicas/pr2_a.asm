/*---------------------------------------------------------------------
**
**  Fichero:
**    pr2_a.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 2a
**
**  Notas de diseño:
**
** 	# define N 8
** 	# define INT_MAX 65536
**	int V [ N ] = { -7 ,3 , -9 ,8 ,15 , -16 ,0 ,3};
**	int min = INT_MAX ;
**	for ( i = 0; i < N ; i ++) {
**		if ( V [ i ] < min )
**			min = V [ i ];
**	}
**
**-------------------------------------------------------------------*/

.global main
.equ N, 8
.equ INT_MAX, 65536
.data
V:   .word -7,3,-9,8,15,-16,0,3

.bss
min: .space 4

.text
main:
    la s1, min	//s1 <- @min
    li t0, INT_MAX	//t0 <- intMAX
    sw t0, 0(s1)	//@s1 <- t0 <-> intMAX
    li t1, N	//t1 <- N(8)
    mv t2, x0 //t2 <- i
    la s0, V	//s0 <- @(V[])
    for:
    	bge t2, t1, efor
    	sll t3, t2, 2	//t3 <- i*4
    	add t3, s0, t3 //V[i]
    	lw t4, 0(t3)	//t4 <- V[i]
    	if:
    	    bge t4, t0, eif	// if(V [ i ] >= min) --> eif
    		mv t0, t4	//t0 <- V[i]
    	eif:
    		add t2, t2, 1	//i++
    		j for	//Vuelve a empezar el for
    	efor:
    		sw t0, 0(s1)	//@s1 <- t0 <-> min
    		j end	//Salta al final del for
    	end:
    		j end

