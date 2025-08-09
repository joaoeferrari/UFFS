# Programa que l� N valores positivos do teclado e imprime o maior valor, 
# o menor valor e a m�dia dos valores.

.data
    input_prompt:   .asciiz "Digite um valor (negativo para sair): "
    output_max:     .asciiz "Maior valor: "
    output_min:     .asciiz "Menor valor: "
    output_avg:     .asciiz "M�dia dos valores: "
    newline:        .asciiz "\n"

.text
    # Fun��o para imprimir uma string
    print_string:
        li  a7, 4               # C�digo do sistema para imprimir string
        ecall
        ret

    # Fun��o para imprimir um inteiro
    print_integer:
        li  a7, 1               # C�digo do sistema para imprimir inteiro
        ecall
        ret

    # Fun��o para ler um inteiro do teclado
    read_integer:
        li  a7, 5               # C�digo do sistema para ler inteiro
        ecall
        ret

    # Fun��o principal
    .globl _start
    _start:
        # Inicializar vari�veis
        li  t0, -1              # Valor para marcar o fim da entrada (n�mero negativo)
        li  t1, 0               # Contador de valores lidos
        li  t2, 0               # Soma dos valores lidos
        li  t3, 0               # Menor valor
        li  t4, 0               # Maior valor

    loop:
        # Solicitar entrada do usu�rio
        la  a0, input_prompt
        jal print_string

        # Ler valor do teclado
        jal read_integer

        # Verificar se o valor � negativo (fim da entrada)
        bge t0, a0, done

        # Atualizar estat�sticas
        addi t1, t1, 1           # Incrementar contador
        add t2, t2, a0          # Adicionar valor � soma

        # Verificar se o valor � o novo m�nimo
        blt a0, t3, update_min

        # Verificar se o valor � o novo m�ximo
        bgt a0, t4, update_max

        j   loop

    update_min:
        mv  t3, a0
        j   loop

    update_max:
        mv  t4, a0
        j   loop

    done:
        # Calcular m�dia
        beqz t1, print_results  # Evitar divis�o por zero
        divu    t2, t1
        mv  t5, t2              # Salvar o resultado da divis�o em t5 (m�dia)

    print_results:
        # Imprimir resultados
        la  a0, output_max
        jal print_string
        mv  a0, t4
        jal print_integer
        la  a0, newline
        jal print_string

        la  a0, output_min
        jal print_string
        mv  a0, t3
        jal print_integer
        la  a0, newline
        jal print_string

        la  a0, output_avg
        jal print_string
        mv  a0, t5
        jal print_integer
        la  a0, newline
        jal print_string

        # Sair do programa
        li  a7, 10              # C�digo do sistema para sair
        ecall
