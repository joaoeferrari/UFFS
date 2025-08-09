# Programa que lê N valores positivos do teclado e imprime o maior valor, 
# o menor valor e a média dos valores.

.data
    input_prompt:   .asciiz "Digite um valor (negativo para sair): "
    output_max:     .asciiz "Maior valor: "
    output_min:     .asciiz "Menor valor: "
    output_avg:     .asciiz "Média dos valores: "
    newline:        .asciiz "\n"

.text
    # Função para imprimir uma string
    print_string:
        li  a7, 4               # Código do sistema para imprimir string
        ecall
        ret

    # Função para imprimir um inteiro
    print_integer:
        li  a7, 1               # Código do sistema para imprimir inteiro
        ecall
        ret

    # Função para ler um inteiro do teclado
    read_integer:
        li  a7, 5               # Código do sistema para ler inteiro
        ecall
        ret

    # Função principal
    .globl _start
    _start:
        # Inicializar variáveis
        li  t0, -1              # Valor para marcar o fim da entrada (número negativo)
        li  t1, 0               # Contador de valores lidos
        li  t2, 0               # Soma dos valores lidos
        li  t3, 0               # Menor valor
        li  t4, 0               # Maior valor

    loop:
        # Solicitar entrada do usuário
        la  a0, input_prompt
        jal print_string

        # Ler valor do teclado
        jal read_integer

        # Verificar se o valor é negativo (fim da entrada)
        bge t0, a0, done

        # Atualizar estatísticas
        addi t1, t1, 1           # Incrementar contador
        add t2, t2, a0          # Adicionar valor à soma

        # Verificar se o valor é o novo mínimo
        blt a0, t3, update_min

        # Verificar se o valor é o novo máximo
        bgt a0, t4, update_max

        j   loop

    update_min:
        mv  t3, a0
        j   loop

    update_max:
        mv  t4, a0
        j   loop

    done:
        # Calcular média
        beqz t1, print_results  # Evitar divisão por zero
        divu    t2, t1
        mv  t5, t2              # Salvar o resultado da divisão em t5 (média)

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
        li  a7, 10              # Código do sistema para sair
        ecall
