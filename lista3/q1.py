def maior(x, y):
    if (x > y):
        return True
    else:
        return False
    
x = int(input("DIgite um valor: "))
y = int(input("Digite outro valor"))

if maior(x,y):
    print("X é maior que Y")
else:
    print("Y é maior que X")