import tkinter as tk
from tkinter import messagebox


class LoginScreen:
    def __init__(self, root):
        self.root = root
        self.root.title("Login")

        self.usuario_var = tk.StringVar()
        self.clave_var = tk.StringVar()

        tk.Label(root, text="Usuario:").grid(row=0, column=0, padx=10, pady=5)
        self.usuario_entry = tk.Entry(root, textvariable=self.usuario_var)
        self.usuario_entry.grid(row=0, column=1, padx=10, pady=5)

        tk.Label(root, text="Clave:").grid(row=1, column=0, padx=10, pady=5)
        self.clave_entry = tk.Entry(
            root, textvariable=self.clave_var, show="*")
        self.clave_entry.grid(row=1, column=1, padx=10, pady=5)

        tk.Button(root, text="Ingresar", command=self.logIn).grid(
            row=2, column=0, columnspan=2, padx=10, pady=10)

    def logIn(self):
        usuario = self.usuario_var.get()
        clave = self.clave_var.get()

        if usuario == "admin" and clave == "1234":
            self.root.destroy()
            root = tk.Tk()
            app = RepairCenterApp(root)
            root.mainloop()
            messagebox.showerror("Error", "Usuario o clave incorrectos")


class RepairCenterApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Repair Center")

        self.cliente_var = tk.StringVar()
        self.direccion_var = tk.StringVar()
        self.inconveniente_var = tk.StringVar()
        self.tecnico_var = tk.StringVar()
        self.fecha_var = tk.StringVar()
        self.hora_var = tk.StringVar()

        tk.Label(root, text="Apellido y Nombre del Cliente:").grid(
            row=0, column=0, padx=10, pady=5)
        self.cliente_entry = tk.Entry(root, textvariable=self.cliente_var)
        self.cliente_entry.grid(row=0, column=1, padx=10, pady=5)

        tk.Label(root, text="Dirección (calle y altura):").grid(
            row=1, column=0, padx=10, pady=5)
        self.direccion_entry = tk.Entry(root, textvariable=self.direccion_var)
        self.direccion_entry.grid(row=1, column=1, padx=10, pady=5)

        tk.Label(root, text="Inconveniente:").grid(
            row=2, column=0, padx=10, pady=5)
        self.inconveniente_entry = tk.Entry(
            root, textvariable=self.inconveniente_var)
        self.inconveniente_entry.grid(row=2, column=1, padx=10, pady=5)

        tk.Label(root, text="Técnico Asignado:").grid(
            row=3, column=0, padx=10, pady=5)
        self.tecnico_entry = tk.Entry(root, textvariable=self.tecnico_var)
        self.tecnico_entry.grid(row=3, column=1, padx=10, pady=5)

        tk.Label(root, text="Fecha de Visita:").grid(
            row=4, column=0, padx=10, pady=5)
        self.fecha_entry = tk.Entry(root, textvariable=self.fecha_var)
        self.fecha_entry.grid(row=4, column=1, padx=10, pady=5)

        tk.Label(root, text="Hora de Visita:").grid(
            row=5, column=0, padx=10, pady=5)
        self.hora_entry = tk.Entry(root, textvariable=self.hora_var)
        self.hora_entry.grid(row=5, column=1, padx=10, pady=5)

        tk.Button(root, text="Guardar Pedido", command=self.scheduleOrder).grid(
            row=6, column=0, columnspan=2, padx=10, pady=10)

    def scheduleOrder(self):
        cliente = self.cliente_var.get()
        direccion = self.direccion_var.get()
        inconveniente = self.inconveniente_var.get()
        tecnico = self.tecnico_var.get()
        fecha = self.fecha_var.get()
        hora = self.hora_var.get()

        if cliente and direccion and inconveniente and tecnico and fecha and hora:

            messagebox.showinfo("Pedido guardado",
                                "El pedido se ha guardado correctamente")

            self.cliente_var.set("")
            self.direccion_var.set("")
            self.inconveniente_var.set("")
            self.tecnico_var.set("")
            self.fecha_var.set("")
            self.hora_var.set("")
        else:
            messagebox.showerror(
                "Error", "Por favor, complete todos los campos")


root = tk.Tk()


login_screen = LoginScreen(root)


root.mainloop()
