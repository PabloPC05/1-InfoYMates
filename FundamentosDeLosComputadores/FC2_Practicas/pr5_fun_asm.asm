
.extern _stack
.global main
.extern intercambiarColsFunc
.extern intercambiarFilasFunc
.extern esMatrizSilla

.equ DIM, 4
.equ dim, 3
.data
	FILA1: .word 0, 0, 0, 0
	FILA2: .word 0, 3, 0, 0
	FILA3: .word 0, 0, 0, 0
	FILA4: .word 0, 0, 0, 0
	opciones: .word 7

.text
	minimo:
		bge a0, a1, else //if(a0 < a1) goto e_minimo
		j minimo_end
		else:	// else <-> a0 >= a1
			mv a0, a1	//a0 = a1
		minimo_end:
			ret
	main:
		li s0, 1	//s0 = numOpciones
		li t1, 1	//Inicializar el primer indice de la primera opcion
		mv s2, x0	//s2 almacenará el indice i = 0
		la sp, _stack	//inicializar sp
		for_main:
			bge s2, s0, efor_main	//Si s2(i) > s0(numOps), salta a efor <-> si no se escogen opciones se va al final del main
			la s3, opciones	//s3 = @opciones
			li t4, 4	//t4 = 4
			mul t4, t4, s2	//t4 = i * 4
			add t0, t4, s3	//t0 = (i*4) + @opciones
			lw t0, 0(t0)	//t0 = opcion[i]
			if1:
				bne t1, t0, eif1
				call rotarFila
				j endOption	//Cuando termina cada proceso, para no seguir haciendo el resto se llama a
							//endOption para i++ y mirar si ya ha terminado el proceso
			eif1:
				li t1, 2
			if2:
				bne t1, t0, eif2
				call rotarCol
				j endOption
			eif2:
				li t1, 3
			if3:
				bne t1, t0, eif3
				call rellenarCruz
				j endOption
			eif3:
				li t1, 4
			if4:
				bne t1, t0, eif4
				call intercambiarFilas
				j endOption
			eif4:
				li t1, 5
			if5:
				bne t1, t0, eif5
				call intercambiarCols
				j endOption
			eif5:
				li t1, 6
			if6:
				bne t1, t0, eif6
				call sumarTraza
				j endOption
			eif6:
				li t1, 7
			if7:
				bne t1, t0, eif7
				la a0, FILA1
				li a1, DIM
				call esMatrizSilla
				j endOption
			eif7:
			endOption:
				add s2, s2, 1
				j for_main
		efor_main:
			j end
	end:
		j end
	//Dado la fila que se quiere rotar, si el numero dado es positivo se rota hacia la derecha
	//si es negativo se rota hacia la izquierda
	rotarFila:
		li t0, -2	//Se escoge la fila que queremos cambiar
		if_rotarFila: //Si es mayor que 0
			bltz t0, eif_rotarFila
			add t0, t0, -1	//fila--
			la t3, FILA1	//t3 = @FILA1
			li t6, 4	//t6 = 4
			mul t0, t0, t6	//t0 = t0 * 4
			li t6, DIM	//t6 = DIM
			mul t0, t0, t6	//t0 = t0 * DIM
			add t3, t3, t0	//t3 = @FILA a rotar
			li t4, DIM	// j(t4) = getCols
			addi t4, t4, -1	// j(t4) = getCols -1
			li t0, 4
			mul t5, t4, t0	//t5 = (DIM-1) * (4)
			add t5, t5, t3	//t5 = t3 + t5
			lw t5, 0(t5)	//t5 = fila[getCols-1]
			for_rotarFila_1:
				blez t4, efor_rotarFila_1
				li t6, 4	//t6 = 4
				mul t6, t6, t4	//t6 = j * 4
				add t6, t6, -4
				add t6, t6, t3
				lw t0, 0(t6)	//t0 = fila[j-1]
				add t6, t6, 4
				sw t0, 0(t6)	//@t6 <-> fila[j] = t0 <-> fila[j-1]
				add t4, t4, -1	//j--
				j for_rotarFila_1
			efor_rotarFila_1:
				sw t5, 0(t3)
				ret
		eif_rotarFila:
			li t1, -1	//t1 = -1
			mul t0, t0, t1	//t0 = (-1)*t0
			add t0, t0, -1	//fila--
			la t3, FILA1	//t3 = @FILA1
			li t6, 4	//t6 = 4
			mul t0, t0, t6	//t0 = t0 * 4
			li t6, DIM	//t6 = DIM
			mul t0, t0, t6	//t0 = t0 * DIM
			add t3, t3, t0	//t3 = @FILA a rotar
			lw t5, 0(t3)	//t5 = fila[0]
			li t4, 0	// j(t4) = 0
			li t1, DIM	// t1 = getCols
			add t1, t1, -1	// t1--
			for_rotarFila_2:
				ble t1, t4, efor_rotarFila_2
				li t6, 4	//t6 = 4
				mul t6, t6, t4	//t6 = j * 4
				//Como t0, almacenaba la fila a mover, ese dato ya no es relevante y se vuelve a usar el registro
				add t6, t6, 4	//t6 = (j*4)+4
				add t6, t6, t3	//t6 = @fila[j+1]
				lw t0, 0(t6)	//t0 = fila[j+1]
				add t6, t6, -4	//t6 = @fila[j]
				sw t0, 0(t6)	//@t6 <-> fila[j] = t0 <-> fila[j+1]
				add t4, t4, 1	//j++
				j for_rotarFila_2
			efor_rotarFila_2:
				li t0, 4
				mul t4, t4, t0	//t4 = (DIM-1)*4
				add t3, t3, t4	//t3 =	((DIM-1)*4) + @FILA1
				sw t5, 0(t3)
				ret
	rotarCol:
		li t0, -1	//t0 = nº de la columna a rotar
		if_rotarCol: //Si es mayor que 0
			bltz t0, eif_rotarCol
			add t0, t0, -1	//col--
			li t1, 4	// t1 = 4
			mul t1, t1, t0	//t1 = 4 * nºcol
			la t2, FILA1	//t2 = @FILA1
			add t2, t2, t1	//t2 = @COL a rotar <-> @matriz.at(0).at(col-1)
			li t3, DIM	//t3 = DIM
			mul t3, t3, t3	//t3 = DIM * DIM
			addi t3, t3, -DIM	//t3 = (DIM* DIM) - DIM
			li t0, 4	//t0 = 4
			mul t3, t3, t0	//t3 = [((DIM * DIM) - DIM)*4]
			add t3, t3, t2	//t3 = @matriz.at(getFilas()-1).at(col-1)
			lw t3, 0(t3)	// t3 = matriz.at(getFilas()-1).at(col-1)
			li t0, DIM	//i = getFilas
			addi t0, t0, -1	//getFilas--
				for_rotarCol_1:	//rotar columna hacia abajo
					blez t0, efor_rotarCol_1	//Si es menor que 0 que salte
					li t1, DIM	//t1 = DIM
					li t4, 4	//t4 = 4
					add t5, t0, -1	//t5 = j - 1
					mul t1, t1, t4	//t1 = 4 * DIM
					mul t4, t1, t5	//t4 = 4 * DIM * (j-1)
					mul t1, t1, t0	//t1 = 4 * DIM * j
					add t1, t1, t2	//t1 = @matriz.at(i).at(col-1)
					add t4, t4, t2	//t4 = @matriz.at(i-1).at(col-1)
					lw t4, 0(t4)	//t4 = matriz.at(i-1).at(col-1)
					sw t4, 0(t1)	//matriz.at(i).at(col-1) = matriz.at(i-1).at(col-1)
					addi t0, t0, -1	//i--
					j for_rotarCol_1
				efor_rotarCol_1:
					sw t3, 0(t2)
					ret
		eif_rotarCol:
			li t1, -1	//t1 = -1
			mul t0, t0, t1	//t0 = (-1)*t0
			add t0, t0, -1	//col--
			li t1, 4	// t1 = 4
			mul t1, t1, t0	//t1 = 4 * nºcol
			la t2, FILA1	//t2 = @FILA1
			add t2, t2, t1	//t2 = @COL a rotar <-> @matriz.at(0).at(col-1)
			lw t3, 0(t2)	//t3 = matriz.at(0).at(col-1) = aux
			li t0, DIM	//t0 = getFilas
			add t0, t0, -1	//getFilas--
			li t1, 0	//j = 0
			for_rotarCol_2:
				ble t0, t1, efor_rotarCol_2
				li t4, DIM	//t4 = DIM
				li t5, 4	//t5 = 4
				mul t4, t5, t4	//t4 = DIM * 4
				add t5, t1, 1	//t5 = j + 1
				mul t5, t5, t4	//t5 = DIM * 4 * (j + 1)
				mul t4, t4, t1	//t4 = DIM * 4 * j
				add t4, t4, t2	//t4 = @matriz.at(j).at(col-1)
				add t5, t5, t2	//t5 = @matriz.at(j+1).at(col-1)
				lw t5, 0(t5)	//t5 = matriz.at(j+1).at(col-1)
				sw t5, 0(t4)	//matriz.at(j).at(col-1) = matriz.at(j+1).at(col-1)
				addi t1, t1, 1
				j for_rotarCol_2
			efor_rotarCol_2:
				mul t4, t4, t1	//t4 = DIM * 4 * j
				add t4, t4, t2	//t4 = @matriz.at(j).at(col-1)
				sw t3, 0(t4)	//matriz.at(j).at(col-1) = aux
				ret
	rellenarCruz:
		addi sp, sp , -24	//Inicio del prologo
		sw ra, 20(sp)
		sw s0, 16(sp)
		sw s1, 12(sp)
		sw s2, 8(sp)
		sw s3, 4(sp)
		sw s4, 0(sp)	//Fin del prologo
		li s0, 3	//Selecciona la fila s0 = fila
		addi s0, s0, -1	//fila--
		li s1, 3	//Selecciona la columna	s1 = columna
		addi s1, s1, -1	//columna--
		li s2, 3	//Selecciona el digito	//s2 = digito a rellenar
		li s3, DIM	//s3 = DIM
			//Llegamos al limite superior de la matriz para realizar la parte de la cruz desde
			//la parte superior izquierda de la misma
				//Calculamos la posicion en memoria de la ficha que se ha escogido
				addi t0, s3, 1	//t0 = DIM+1
				mul t0, s0, s3	//t0 = fila*DIM
				add t0, t0, s1	//t0 = fila*DIM + col
				li t1, 4	//t1 = 4
				mul t0, t0, t1	//t0 = (fila*DIM + col)*4
				la t1, FILA1	//t1 = @FILA1
				add t0, t1, t0	//t0 = @matriz.at(fila).at(columna)
				mv s4, t0	//s4 = t0
				//Calculamos la posicion desde la que hay que empezar a sustituir
				//Lo hacemos multiplicando (DIM+1)*min{f, c} para obtener cuantas veces tenemos que cambiar de direccion de memoria
				mv a0, s0	//a0 = fila seleccionada (s0)
				mv a1, s1	//a1 = columna seleccionada (s1)
				call minimo
				mv t1, a0	//t1 = minimo(f, c)
				addi t0, s3, 1	//t0 = DIM+1
				mul t0, t1, t0	//t0 = (DIM+1)*minimo(f, c)
				li t2, 4	//t2 = 4
				mul t0, t0, t2	//t0 = [(DIM+1)*minimo(f, c)]*4
				sub t0, s4, t0	//t0 = @de la ficha desde la que empezar
				la t4, FILA1
				neg t4, t4
				add t1, t0, t4	//t1 = diferencia de las direcciones
				li t4, 4	//t4 = 4
				div t1, t1, t4	//t1 = t1/4(col de la ficha desde la que se empieza)
				neg t1, t1
				addi t1, t1, DIM	//t1 = DIM - col de la ficha desde la que se empieza
				mv t2, x0	//i(t2) = 0
			while_rellenarCruz_1:
				bge t2, t1, ewhile_rellenarCruz_1	//if((DIM - fila) <= i)
				addi t3, s3, 1	//t3 = DIM + 1
				mul t3, t4, t3	//t3 = (DIM + 1)*4
				mul t3, t3, t2	//t3 = [(DIM + 1)*4]*i
				add t3, t3, t0	//t3 = @matriz.at(i).at(j)
				sw s2, 0(t3)	//matriz.at(i).at(j) = dig
				add t2, t2, 1	//i++
				j while_rellenarCruz_1
			ewhile_rellenarCruz_1:
				//Calculamos la posicion desde la que hay que empezar a sustituir desde la esquina superior derecha
				//Para ello hacemos lo mismo que en el caso anterior pero tomando las columnas como su diferencia a la dimension de la matriz
				addi t1, s3, -1	//t1 = DIM-1
				sub a0, t1, s1	//a0 = DIM -1 -col
				mv a1, s0	//a1 = fila
				call minimo
				mv t0, a0
				mul t0, t1, t0	//t0 = (DIM-1)*minimo(f, (dim-1-c))
				mul t0, t0, t4	//t0 = [(DIM-1)*minimo(f, (dim-1-c))]*4
				sub t0, s4, t0	//t0 = @de la ficha desde la que empezar
				la t3, FILA1	//t3 = @FILA1
				sub t3, t3, t0	//t3 = @FILA1 - ficha desde la que empezar
				div t3, t3, t4	//t3 = t3/4
				mv t2, t3
				neg t2, t2
				mv t1, x0	//t1 = i = 0
				addi t2, s3, -1	//t2 = DIM - 1
			while_rellenarCruz_2:
				bge t1, t2, ewhile_rellenarCruz_2
				addi t3, s3, -1	//t3 = DIM - 1
				mul t3, t3, t4	//t3 = (DIM - 1)*4
				mul t3, t3, t1	//t3 = [(DIM - 1)*4]*i
				add t3, t0, t3	//@matriz.at(i).at(j)
				sw s2, 0(t3)	//matriz.at(i).at(j) = dig
				add t1, t1, 1
				j while_rellenarCruz_2
			ewhile_rellenarCruz_2:
				lw ra, 20(sp)	//Comienzo del epilogo
				lw s0, 16(sp)
				lw s1, 12(sp)
				lw s2, 8(sp)
				lw s3, 4(sp)
				lw s4, 0(sp)	//Fin del epilogo
				addi sp, sp, 24
				ret
	intercambiarFilas:
		add sp, sp, -8
		sw ra, 4(sp)
		li a0, 2	//a0 = 1ºfila a intercambiar
		li a1, 3	//a1 = 2ºfila a intercambiar
		la a2, FILA1
		li a3, DIM
		call intercambiarFilasFunc
		lw ra, 4(sp)
		addi sp, sp, 8
		ret

	intercambiarCols:
		add sp, sp, -8
		sw ra, 4(sp)
		li a0, 2	//a0 = 1ºcolumna a intercambiar
		li a1, 3	//a1 = 2ºcolumna a intercambiar
		la a2, FILA1
		li a3, DIM
		call intercambiarColsFunc
		lw ra, 4(sp)
		addi sp, sp, 8
		ret
	sumarTraza:
		addi sp, sp , -10	//Inicio del prologo
		sw s0, 8(sp)
		sw s1, 4(sp)
		sw s2, 0(sp)	//Fin del prologo
		la s0, FILA1	//s0 = @FILA1
		li s1, DIM	//s1 = DIM
		addi s2, s1, 1	//s2 = DIM+1
		mv t0, x0	//t0(i) = 0
		li t4, 4	//t4 = 4
			for_sumarTraza:
				bge t0, s1, efor_sumarTraza
				mul t1, t0, s2	//t1 = i*(DIM+1)
				mul t1, t1, t4	//t1 = [i*(DIM+1)]*4
				add t1, t1, s0	//t1 = @matriz.at(i).at(j)
				lw t1, 0(t1)	//t1 = matriz.at(i).at(j)
				add t2, t2, t1	//sumaTraza = matriz.at(i).at(j) + sumaTraza
				addi t0, t0, 1
				j for_sumarTraza
			efor_sumarTraza:
				mv a3, t2	//a0 = t2 = resultado de la suma de la traza
				//Lo devuelvo a un registro diferente al estipulado por el codigo RISC-V, debido a que en otras funciones
				//que tengo de tipo booleano, he utilizado ese registro de argumento para guardar el valor del retorno
				lw s0, 8(sp)	//Comienzo del epilogo
				lw s1, 4(sp)
				lw s2, 0(sp)	//Fin del epilogo
				addi sp, sp, 10
				ret









