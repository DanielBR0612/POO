def iniciais(nome):
    name = nome.split()
    lista = []
    lista2 = []
    ini = []

    for i in range(len(name)):
        name1 = list(name[i])
        lista.append(name1)

    for i in range(len(lista)):
        lista2 = lista[i]
        ini += lista2[0]

    return ini


nome = input("digite seu nome: ")


print(iniciais(nome))

