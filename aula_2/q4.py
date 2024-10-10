import math

a, b = map(int, input("Digite a base e a altura do retangulo: ").split())

area = a * b
perimetro = (a * 2) + (b * 2)
diagonal = math.sqrt((a*a) + (b*b))


print(f"Area = {area} - Perimetro = {perimetro} - Diagonal = {diagonal}")
