

preg_num = int(input("Número: "))

cant_num = 0

suma =  0

cant_num_mult_prim_num = 0

cant_primos = 0

divisor = 2

cant_prom = 0

while preg_num != 0:

    cant_num += 1

    if (preg_num > 0 and preg_num % 6 == 0):
        suma += preg_num
        cant_prom += 1

    if cant_num == 1:

        for i in range(1, preg_num+1):

            if preg_num % i == 0:
                cant_num_mult_prim_num += 1


    while preg_num > 1 and preg_num % divisor != 0 and preg_num != divisor:
        divisor += 1

    if divisor == preg_num:
        cant_primos += 1

    
    preg_num = int(input("Número: "))


if cant_prom > 0:
    promedio = suma / cant_prom
else:
    promedio = ""


print(f"Promedio: {promedio}")
print(f"Cantidad de numeros multiplos de primer numero: {cant_num_mult_prim_num}")
print(f"Cantidad de numeros primos {cant_primos}")



            
    
    