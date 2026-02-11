import re

cadena = input("Cadena a analizar: ")

mayusculas = "[A-Z]"
minusculas = "[a-z]"
numero = "[0-9]"

print('En la cadena "' + cadena + '":')

auxMayus = len(re.findall(mayusculas,cadena))
auxMinus = len(re.findall(minusculas,cadena))
auxNum = len(re.findall(numero, cadena))

if auxMayus == 1:
    print(f"Hay {auxMayus} Letra mayuscula")
if auxMayus > 1:
    print(f"Hay {auxMayus} Letras mayusculas")
if auxMinus > 1:
    print(f"Hay {auxMinus} Letras minusculas")
if auxMayus & auxMinus < 1:
    print("No se encontraron letras")
    print(f"Hay {auxNum} Numeros")

print("La cadena es valida como identificador") if cadena.isidentifier() else print("No es valida como identificador")