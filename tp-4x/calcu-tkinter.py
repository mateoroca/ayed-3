import tkinter as tk


def calcular():
    try:
        resultado = eval(entry.get())
        entry.delete(0, tk.END)
        entry.insert(tk.END, str(resultado))
    except:
        entry.delete(0, tk.END)
        entry.insert(tk.END, "Error")


def agregar_caracter(caracter):
    entry.insert(tk.END, caracter)


def borrar():
    entry.delete(0, tk.END)


# Crear la ventana principal
ventana = tk.Tk()
ventana.title("Calculadora")

# Crear el campo de entrada
entry = tk.Entry(ventana, width=30)
entry.grid(row=0, column=0, columnspan=4)

# Definir los colores de los botones
color_fondo = "#E0E0E0"  # Color de fondo de los botones
color_texto = "#000000"  # Color del texto de los botones

# Crear los botones de la calculadora con los colores personalizados
botones = [
    ("7", 1, 0),
    ("8", 1, 1),
    ("9", 1, 2),
    ("/", 1, 3),
    ("4", 2, 0),
    ("5", 2, 1),
    ("6", 2, 2),
    ("*", 2, 3),
    ("1", 3, 0),
    ("2", 3, 1),
    ("3", 3, 2),
    ("-", 3, 3),
    ("0", 4, 0),
    (".", 4, 1),
    ("=", 4, 2),
    ("+", 4, 3),
    ("C", 5, 0),
]

for boton in botones:
    texto, fila, columna = boton
    tk.Button(ventana, text=texto, width=7, bg=color_fondo, fg=color_texto,
              command=lambda t=texto: agregar_caracter(t)).grid(row=fila, column=columna, sticky="nsew")

# Configurar el botón "=" para realizar el cálculo
tk.Button(ventana, text="=", width=7, bg="#FF9800", fg=color_texto,
          command=calcular).grid(row=4, column=2, sticky="nsew")

# Configurar el botón "C" para borrar la entrada
tk.Button(ventana, text="C", width=7, bg="#FF9800", fg=color_texto,
          command=borrar).grid(row=5, column=0, sticky="nsew")

# Configurar el comportamiento de redimensionamiento de las filas y columnas
for i in range(5):
    ventana.grid_rowconfigure(i, weight=1)
for i in range(4):
    ventana.grid_columnconfigure(i, weight=1)

# Ejecutar la ventana principal
ventana.mainloop()
