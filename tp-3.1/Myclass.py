### punto 7 , 8 ###

class Myclass:
    atributo_de_clase = "i'm a class atribute"

    @classmethod
    def class_method(cls):
        print("i'm a class method")

    @staticmethod
    def staticmethod():
        print("i'm a static method")

    def __init__(self) -> None:
        self.atributo_instancia = "i'm a instance atribute"

    def instance_method(self):
        print("i'm a instance method")


obj = Myclass()

print(obj.atributo_instancia)
print(Myclass.atributo_de_clase)

obj.instance_method()
Myclass.class_method()


obj.staticmethod()

Myclass.staticmethod()
