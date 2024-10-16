def maior(x, y, z):
    vasco = x

    if(y > vasco):
        vasco = y
    if (z > vasco):
        vasco = z
    
    return vasco

x = int(input("Digite X: "))
y = int(input("DIgite Y: "))
z = int(input("Digite Z: "))

print(maior(x,y,z))


