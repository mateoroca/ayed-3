with open("8.1.txt", 'w+') as file:

    state = file.closed
    openMode = file.mode
    name = file.name
    codification = file.encoding

    file.write("i'm learning python")
    file.seek(0)

    data = file.read()

    print("File State:", "Close" if state else "Open")
    print("Opening Mode:", openMode)
    print("Name of File:", name)
    print("character encoding:", codification)
    print("Data of File:")
    print(data)
