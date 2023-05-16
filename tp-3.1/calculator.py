class Calculator:
    def add(self, num1, num2):
        return num1+num2

    def sustract(self, num1, num2):
        return num1-num2

    def Multiply(self, num1, num2):
        return num1*num2

    def divide(self, num1, num2):
        return num1/num2


calcu = Calculator()

print(calcu.add(2, 2))
print(calcu.sustract(4, 5))
print(calcu.divide(50, 10))
print(calcu.Multiply(5, 2))
