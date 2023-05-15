from functools import reduce

"""punto 1"""
""" 
list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
lista_to_squared = [pow(item, 2) for item in list]
print(lista_to_squared)
 """
""" punto 2 """

""" tupla = (1, 3, 4, 5, 6, 9, 2, 98, 55, 7, 10)

cantidad_mayores_a_5 = len([x for x in tupla if x > 5])
print(cantidad_mayores_a_5)
 """

"""punto 2"""
""" tupla = (1, 3, 4, 5, 6, 9, 2, 98, 55, 7, 10, 33, 22, 33, 22, 12)


def contar_mayores_a_5(acc, elemento):
    if elemento > 5:
        return acc + 1
    else:
        return acc


cantidad_mayores_a_5 = reduce(contar_mayores_a_5, tupla, 0)
print(cantidad_mayores_a_5) """


""" punto 7.1 """


""" def dividir(num1, num2):
    return num1 / num2


dividir(5, 0)
 """

"""punto 7.2"""

""" def add_10(num):
    return num + 10


add_10("cinco") """

"""punto 7.3"""

"""
lista = [1, 2, 3]

try:
    for i in range(len(lista)+1):
        print(lista[i])
except IndexError:
    print("Se generó un IndexError: índice fuera de rango")

"""
"""punto 7.4"""

""" agenda = {'name': 'pepe', 'city': 'mdq'}


print(agenda['name'])
print(agenda['surname'])
 """
