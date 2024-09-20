/*---------------------------------------------------------------------
**
**  Fichero:
**    fun_asm.c  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 4
**
**-------------------------------------------------------------------*/
.text
.global eucl_dist
.global guardar
.extern int mul(int a, int b)
.extern int i_sqrt(int a)
.extern _stack



//int eucl_dist(int * w, int size);
eucl_dist:
	la sp, _stack
	add sp, sp, -4
	sw ra, 0(sp)
	li t0, 0	//Almacena acc
	mv t1, a0	//Almacena *w
	mv t2, a1	//Almacena size
	li t3, 0	//Almacena i
	for:
		bge t3, t2, efor
		lw a0, 0(t1)
		mv a1, a0
		call mul
		add t0, t0, a0
		add t3, t3, 1
		add t1, t1, 4
		j for
	efor:
		mv a0, t0
		call i_sqrt
		lw ra, 0(sp)
		add sp, sp, 4
		ret
//int guardar(char valor, char * ubicacion);
guardar:
	sb a0, 0(a1)
	ret
    //recibo el valor en a0, y la dirección destino en a1
    //asegurarse que sólo se guarda UN BYTE!!
