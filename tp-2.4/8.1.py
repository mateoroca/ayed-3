file = open("8.1.txt", "w+")

file.write("estoy aprendiendo python")

file.seek(0)

data = file.read()

print(data)

file.close()
