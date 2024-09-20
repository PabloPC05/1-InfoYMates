
//En este archivo se encuentran aquellas funciones en las que se les pasa como argumentos
//tanto un array, como escalares (la dimension de la matriz y las columnas o filas que se quieran intercambiar)
.global intercambiarColsFunc
.global intercambiarFilasFunc

	intercambiarColsFunc:
		addi sp, sp , -16	//Inicio del prologo
		sw s0, 12(sp)
		sw s1, 8(sp)
		sw s2, 4(sp)
		sw s3, 0(sp) //Fin del prologo
		//LLegada de los argumentos
		mv t0, a0	//t0 = a0 = 1ºColumna a intercambiar
		mv t1, a1	//t1 = a1 = 2ºColumna a intercambiar
		add t0, t0, -1	//1ºcol--
		add t1, t1, -1	//2ºcol--
		mv s2, a2	//s2 = a2 = @FILA1
		mv s3, a3	//s3 = a3 = DIM
		//Comienzo de la funcion como tal
		li t4, 4
		mul t0, t0, t4	//t0 = col1*4
		mul t1, t1, t4	//t1 = col1*4
		add s1, t0, s2	//s1 = @col1
		add s2, t1, s2	//s2 = @col2
		mv t0, x0	//i = 0
		for_intercambiarCols:
			bge t0, s3, efor_intercambiarCols
			mul t3, t4, t0	//t3 = i * 4
			mul t3, t3, s3	//t3 = i*4*DIM
			add t1, t3, s1	//t1 = (i*4)+@col1 = @matriz.at(i).at(col1)
			add t2, t3, s2	//t2 = (i*4)+@col2 = @matriz.at(i).at(col2)
			lw t5, 0(t1)	//t5 = matriz.at(i).at(col1)
			lw t6, 0(t2)	//t6 = matriz.at(i).at(col2)
			sw t6, 0(t1)	//matriz.at(i).at(col1) = t6
			sw t5, 0(t2)	//matriz.at(i).at(col2) = t5
			add t0, t0, 1
			j for_intercambiarCols
		efor_intercambiarCols://Comienzo del epilogo
				lw s0, 12(sp)
				lw s1, 8(sp)
				lw s2, 4(sp)
				lw s3, 0(sp)//Fin del epilogo
				addi sp, sp, 16
				ret


	intercambiarFilasFunc:
		add sp, sp, -16	//Inicio del prologo
		sw s0, 12(sp)
		sw s1, 8(sp)
		sw s2, 4(sp)
		sw s3, 0(sp)	//Fin del prologo
		mv t0, a0	//t0 = a0 = 1ºFila a intercambiar
		mv t1, a1	//t1 = a1 = 2ºFila a intercambiar
		addi t0, t0, -1	//fila1--
		addi t1, t1, -1	//fila2--
		mv s2, a3	//s2 = a3 = DIM
		mv s3, a2	//s3 = a2 = @FILA1
		li t4, 4
		mul t0, t4, t0	//t0 = 4*1ºfila
		mul t1, t4, t1	//t1 = 4*2ºfila
		mul t0, t0, s2	//t0 = (4*1ºfila)*DIM
		mul t1, t1, s2	//t1 = (4*2ºfila)*DIM
		add s0, t0, s3	//s0 = @1ºFILA
		add s1, t1, s3	//s1 = @2ºFILA
		mv t0, x0	//t0 = 0
			for_intercambiarFilas:
				bge t0, s2, efor_intercambiarFilas
				mul t1, t4, t0	//t1 = 4*i
				add t2, t1, s0	//@matriz.at(fila1)
				add t3, t1, s1	//@matriz.at(fila2)
				lw t6, 0(t2)	//t6 = matriz.at(fila1)
				lw t5, 0(t3)	//t5 = matriz.at(fila2)
				sw t6, 0(t3)	//matriz.at(fila2) = matriz.at(fila1)
				sw t5, 0(t2)	//matriz.at(fila1) = matriz.at(fila2)
				add t0, t0, 1
				j for_intercambiarFilas
			efor_intercambiarFilas:
				lw s0, 12(sp)	//Inicio del epilogo
				lw s1, 8(sp)
				lw s2, 4(sp)
				lw s3, 0(sp)
				add sp, sp, 16	//Fin del epilogo
				ret
