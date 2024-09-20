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
**	int mul(int a, int b) {
**	    int res = 0;
**	    while (b > 0) {
**	        res += a;
**	        b--;
**	    }
**	    return res;
**	}
**
**	int dotprod(int V[], int W[], int n) {
**	    int acc = 0;
**	    for (int i = 0; i < n; i++) {
**	        acc += mul(V[i], W[i]);
**	    }
**	    return acc;
**	}
**
**	#define N 4
**	int A[] = {3, 5, 1, 9}
**	int B[] = {1, 6, 2, 3}
**
**	int res;
**
**	void main() {
**	    int normA = dotprod(A, A, N);
**	    int normB = dotprod(B, B, N);
**	    if (normA > normB)
**	        res = 0xa;
**	    else
**	        res = 0xb;
**	}
**
**-------------------------------------------------------------------*/
.extern _stack
.global main
.equ N, 4

.data
	A: .word 3, 5, 1, 9
	B: .word 1, 6, 2, 3
.bss
	res: .space 4
.text
	main:
		la t2, res	//t2<- @res
		la sp, _stack	//inicializar sp
		li a2, 4	//a2<- N

		la a0, A	//a0 <- @A[]
		la a1, A	//a1<- @A[]
		call dotprod
		mv t0, a0 //t0(normA)<-dotprod(A, A, N)

		la a0, B	//a0 <- @B[]
		la a1, B	//a1<- @B[]
		call dotprod
		mv t1, a0 //t1(normB)<-dotprod(B, B, N)
		if:
			bge t1, t0, else
			li t0, 10
			sw t0, 0(t2)
			//res = 0xa
			j end
		else:
			li t0, 11
			sw t0, 0(t2)
			//res = 0xb
			j end
	end:
		j end
	dotprod:
		add sp, sp, -24	//Inicio del prologo
		sw ra, 20(sp)
		sw s0, 16(sp)
		sw s1, 12(sp)
		sw s2, 8(sp)
		sw s3, 4(sp)
		sw s4, 0(sp)	//Fin del prologo
		li s0, 0	//acc = 0
		li t3, 0 	//i = 0
		mv s2, a0	//s2<-@V[]
		mv s3, a1	//s3<- @W[]

		for:
			bge t3, a2, efor
			sll t1, t3, 2	//t1 = i*4

			add s11, s2, t1
			lw s1, 0(s11)	//s1<-V[i]
			mv a0, s1

			add s10, s3, t1
			lw s4, 0(s10)	//s4<-W[i]
			mv a1, s4

			call mul

			add s0, s0, a0
			add t3, t3, 1
			j for

		efor:
			mv a0, s0	//devolver el valor de s0
			lw ra, 20(sp)	//Inicio del epilogo
			lw s0, 16(sp)
			lw s1, 12(sp)
			lw s2, 8(sp)
			lw s3, 4(sp)
			lw s4, 0(sp)
			add sp, sp, 24	//Fin del epilogo
			ret
	mul:
		li t4, 0	//res = 0
		mv t6, a0
		mv t5, a1
		while:
			bge x0, t5, ewhile	//condicional
			add t4, t4, t6	//s0(res) = s0(res) + s1(a0)
			add t5, t5, -1	//b--
			j while
		ewhile:
			mv a0, t4	//Pone s0(res) como el valor de vuelta
			ret


