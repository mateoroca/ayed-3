
nameFile = "8.1.txt"

file = open(nameFile, 'r')


state = file.closed

openMode = file.mode

name = file.name

codification = file.encoding

data = file.read()

print("File State:", "Close" if state else "Open")

print("Opening Mode:", openMode)

print("Name of File:", name)
print("character encoding:", codification)
print("Data of File:")
print(data)

# Cerrar el archivo
file.close()
