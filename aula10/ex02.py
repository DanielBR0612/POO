import json
class Cliente:
    def __init__(self, id, nome):
        self.id = id
        self.nome = nome
    def __str__(self):
        return f"{self.id} - {self.nome}"


def salvar():
    a = Cliente(1, "Gilbert")
    b = Cliente(2, "Eduardo") 
    d = Cliente(3, "Daniel")
    print(a)
    print(b)
    print(d)
    print(a.__dict__)
    print(vars(b))
    print(vars(d))
    clientes = [a, b, d]
    with open("clientes.json", mode="w") as arquivo:
        json.dump(clientes, arquivo, default = vars)

def abrir():
    clientes = []
    with open("clientes.json", mode="r") as arquivo:
        clientes_json = json.load(arquivo)
        print(clientes_json)
        for obj in clientes_json:
            c = Cliente(obj["id"], obj["nome"])
            clientes.append(c)    
    for c in clientes: print(c)

salvar()

