/*---------------------------------------------------------------------
**
**  Fichero:
**    pr2_b.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 2b
**
**  Notas de diseño:
**
**	# define N 8
**	# define INT_MAX 65536
**	int V [ N ] = { -7 ,3 , -9 ,8 ,15 , -16 ,0 ,3};
**	int W [ N ];
**	int min , index ;
**	for ( j = 0; j < N ; j ++) {
**		min = INT_MAX ;
**		for ( i = 0; i < N ; i ++) {
**			if ( V [ i ] < min ) {
**				min = V [ i ];
**				index = i ;
**			}
**		}
**		W [ j ] = V [ index ];
**		V [ index ] = INT_MAX ;
**	}
**
**-------------------------------------------------------------------*/

.global main
.equ N , 8	//#define N 8
.equ INT_MAX , 65536	//# define INT_MAX 65536

.data
V: 	 .word -7 ,3 , -9 ,8 ,15 , -16 ,0 ,3 //int V [ N ] = { -7 ,3 , -9 ,8 ,15 , -16 ,0 ,3}
.bss
W: 	 .space N *4//int W [ N ]
min: .space 4	//int min
ind: .space 4	//int index

.text
main :
	li t0, N	//t0<-N
	li t1, INT_MAX	//t1<-INT_MAX
	la t2, V	//t2 <- @V[]
	la t3, W	//t3 <- @W[]
	mv t6, x0	//t6<- j
	for1:
		bge t6, t0, efor1	//condicional contrario
		mv s3, t1	//Cargar en s3, el registro que va a almacenar min, el valor de intmax
		mv s0, x0	//s0 <- i
		for2:
			bge s0, t0, efor2	//condicional contrario
			sll s1, s0, 2	//calcula el desplazamiento i*4
			add s1, t2, s1	//suma base y desplazamiento
			lw s2, 0(s1)	//s2 <- V[i]
			if:
				bge s2, s3, eif	//condicional contrari
				mv s3, s2	//Cargar en s3(registro que contiene el min), el valor de V[i]
				mv s4, s0	//Cargar en s4(registro que almacena index), el valor de la i
			eif:
				add s0, s0 , 1	//i++
				j for2
		efor2:
			sll s8, s4, 2	//s8 <- index(s4)*4
			add s8, s8, t2	//suma s8, que es el valor de index*4 y la direccion de memoria de V[] y lo almacena en s8
			sll s5, t6, 2	//s5<-j(t6)*4
			add s5, s5, t3	//suma la direccion de W[](t3) y j*4(s5) y lo almacena en s5
			lw s10, 0(s8)	//almacena en s10 el contenido de la direccion de s8, es decir, V[index]
			sw s10, 0(s5)	//almacena s10 (V[index]) en la direccion de memoria de s5, es decir, la direccion de W[j]
			sw t1, 0(s8)	//almacena t1(INTMAX) en la direccion de memoria de s8(direccion de V[index])
			add t6, t6, 1	//j++
			j for1
	efor1:
		j end
	end:
		j end

	//Se puede cambiar s8, por s4, en todo lugar para hacer menor uso del nº de registros









