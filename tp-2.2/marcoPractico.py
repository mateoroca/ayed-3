
""" punto 1 """
""" numeros = [i for i in range(1, 101)] """

""" punto 2  """
""" meses = ["Ene",
         "Feb",
         "Mar",
         "Abr",
         "May",
         "Jun",
         "Jul",
         "Ago",
         "Sep",
         "Oct",
         "Nov",
         "Dic"]

num = input("ingresa un numero: ")

if (int(num) > len(meses)):
    print("error , el numero exede el tamaño de la lista")
else:
    indice = int(num) - 1
    print(meses[indice]) """

""" punto 3  """
""" num = input("Ingresa un número: ")
lista = []

for i in range(1, 11):
    resultado = (i) * int(num)
    lista.append(resultado)
    print(lista[i-1]) """
""" 
punto 3 simplificado  """

""" num = input("Ingresa un número: ")
lista = [(i) * int(num) for i in range(1, 11)]

for elemento in lista:
    print(elemento) """


""" punto 4  """
""" 
contactos = {}

while True:
    nombre = input("Ingresa el nombre del contacto (o 'no' para terminar): ")

    if nombre == "no":
        break

    if nombre in contactos:
        print("El nombre ya existe. Ingresa un nombre diferente.")
        continue

    telefono = input("Ingresa el número de teléfono: ")
    contactos[nombre] = telefono

print("Contactos ingresados:")
for nombre, telefono in contactos.items():
    print(nombre + ": " + telefono) """


""" punto 5  """


""" num1 = input("ingrese el primer numero: ")
num2 = input("ingrese el segundo numero: ")

numeros = []

if num1 > num2:

    for i in range(int(num2)+1, int(num1)):
        numeros.append(i)
else:
    for i in range(int(num1)+1, int(num2)):
        numeros.append(i)


for items in numeros:
    if items % 2 == 0:
        print("Número Par:"+str(items))
    else:
        print("Numero Inpar:"+str(items))
 """
""" punto 6 """

""" 
while True:
    num = float(input("ingrese un numero positivo: "))
    if num < 0:
        print("El numero no es positivo intente de nuevo:")
        continue
    if num > 0:
        print("bien hecho")
        break
 """

"""  punto 7 """

""" while True:
    num1 = int(input("Ingrese el primer numero: "))
    num2 = int(input("Ingrese el segundo numero:"))
    if num2 < num1:
        print("El segundo numero debe ser mayor al primero, (intente de nuevo)")
        continue
    else:
        print("Bien hecho")
        print(num1, num2)
        break
 """
""" punto 8 """
""" 
num1 = int(input("ingrese un numero: "))
num2 = int(input("ingrese otro numero: "))
lista = []
if num1 < num2:
    for i in range(num1+1, num2):
        lista.append(i)


else:
    for i in range(num2+1, num1):
        lista.append(i)

for item in lista:
    print(item)
 """
