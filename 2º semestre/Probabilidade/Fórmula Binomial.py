from math import factorial

def titulo(nome):
    print("-"*(len(nome)+13))
    print(f'BEM-VINDO {nome}!')
    print("-"*(len(nome)+13))


#FUNÇÃO PARA A COMBINAÇÃO
def combinação(n,x):
    c = factorial(n)
    c1 = n - x
    c2 = factorial(c1)
    c3 = factorial(x)
    comb = c/(c2*c3)
    return comb


print('-'*27)
print('TRABALHO DE PROBABILIDADE')
print('-'*27)


nome = input('QUAL O SEU NOME? ').upper()
titulo(nome)
print("INFORME OS VALORES SOLICITADOS PELO PROBLEMA")
print()
print("LEMBRE-SE DE DIGITAR O VALOR DE 'p' EM DECIMAL (EX: 0.80)")
print()

n = int(input("INFORME O VALOR DE 'n': "))
p = float(input("INFORME O VALOR DE 'p': "))
x = int(input("INFORME O VALOR DE 'x': "))
q = 1 - p

#FORMULA PROBABILIDADE
P = combinação(n, x)*(p**x)*(q**(n-x))
porcentagem = P*100
print()
print(f"A PROBABILIDADE DO EVENTO SOLICITADO OCORRER É DE {round(porcentagem,2)}%")
print()
acumulador = 0
for i in range(x, -1, -1):
    P = combinação(n, i) * (p ** i) * (q ** (n - i))
    acumulador = acumulador + P

print(f"O SOMATÓRIO DE 0 ATÉ 'x' É: {acumulador*100:.2f}%")





