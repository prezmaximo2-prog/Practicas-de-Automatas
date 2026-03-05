# Semestre 6 Grupo 3 
# Maximo P.
## Practica 2 "Automatas finitos deterministas"

# Ejercicio 1
L = {0x | x ∈ {0,1}*}
## Tupla
AFD = (Σ,Q,δ,q0,F)  
Σ = {0,1}  
Q = {q0,q1,q2,q3}  
q0 = inicial  
F = {q1}

## Tabla de transición

| Estado | 0   | 1   |
| ------ | --- | --- |
| q0     | q1  | q2  |
| q1     | q1  | q1  |
| q2     | q2  | q3  |
| q3     | q2  |q1   |

## Palabras aceptadas 

0
01
000
00101 
01001 

## Palabras rechazadas

palabra vacia
1
10
111
1000


# Ejercicio 2
L = {x1 | x ∈ {0,1}*}

## Tupla
AFD = (Σ,Q,δ,q0,F)  
Σ = {0,1}  
Q = {q0,q1,q2}  
q0 = inicial  
F = {q1}

## Tabla de transición

| Estado | 0 | 1 |
|----|------|------|
| q0 | q0 | q1 |
| q1 | q0 | q2 |

## Palabras aceptadas

00001 
01011 
10101 
11111 
00111 

## Palabras rechazadas

00000 
11110 
10110 
01010 
11000



# Ejercicio 3
L = {x01y}

## Tupla
AFD = (Σ,Q,δ,q0,F)  
Σ = {0,1}  
Q = {q0,q1,q2}  
q0 = inicial  
F = {q2}

## Tabla de transición

| Estado | 0 | 1 |
|------|------|------|
| q0 | q1 | q0 |
| q1 | q1 | q2 |
| q2 | q2 | q2 |

## Palabras aceptadas
00111 
10110 
01010 
11010 
00011 

## Palabras rechazadas

11111 
00000 
11110 
10000 
11000



# Ejercicio 4
L = {x110y}

## Tupla
AFD = (Σ,Q,δ,q0,F)  
Σ = {0,1}  
Q = {q0,q1,q2,q3}  
q0 = inicial  
F = {q3}

## Tabla de transición

| Estado | 0 | 1 |
|------|------|------|
| q0 | q0 | q1 |
| q1 | q0 | q2 |
| q2 | q3 | q2 |
| q3 | q3 | q3 |

## Palabras aceptadas

11101 
01101 
11011 
11100 
01110 

## Palabras rechazadas

00000 
10101 
01010 
00111 
10001



# Ejercicio 5
L = {acxab}

## Tupla
AFD = (Σ,Q,δ,q0,F)  
Σ = {a,b,c}  
Q = {q0,q1,q2,q3,q4}  
q0 = inicial  
F = {q4}

## Tabla de transición

| Estado | a | b | c |
|------|------|------|------|
| q0 | q1 | - | - |
| q1 | - | - | q2 |
| q2 | q3 | q2 | q2 |
| q3 | - | q4 | - |
| q4 | q4 | q4 | q4 |

## Palabras aceptadas

acaab 
acbab 
accab 
acabb 
acacb 

## Palabras rechazadas

abcab 
cabaa 
aacbb 
bcaba 
ccbab



# Ejercicio 6
L = {acxz | z ≠ ab}

## Tupla
AFD = (Σ,Q,δ,q0,F)  
Σ = {a,b,c}  
Q = {q0,q1,q2,q3}  
q0 = inicial  
F = {q2}

## Tabla de transición

| Estado | a | b | c |
|------|------|------|------|
| q0 | q1 | - | - |
| q1 | - | - | q2 |
| q2 | q2 | q2 | q2 |
| q3 | q3 | q3 | q3 |

## Palabras aceptadas

acaaa 
acbca 
acccc 
acbcb 
accaa 

## Palabras rechazadas
acaab 
acbab 
accab 
acabb 
acacb



# Ejercicio 7
L = {acbxz | z ≠ bd}

## Tupla
AFD = (Σ,Q,δ,q0,F)  
Σ = {a,b,c,d}  
Q = {q0,q1,q2,q3}  
q0 = inicial  
F = {q3}

## Tabla de transición

| Estado | a | b | c | d |
|------|------|------|------|------|
| q0 | q1 | - | - | - |
| q1 | - | - | q2 | - |
| q2 | - | q3 | - | - |
| q3 | q3 | q3 | q3 | q3 |

## Palabras aceptadas

acbaa 
acbcc 
acbda 
acbbb 
acbca 

## Palabras rechazadas

acbbd 
acabd 
acdbd 
acabd 
acbbd



# Ejercicio 8
L = {cabaxz | z ≠ ab}

## Tupla
AFD = (Σ,Q,δ,q0,F)  
Σ = {a,b,c,d}  
Q = {q0,q1,q2,q3,q4}  
q0 = inicial  
F = {q4}

## Tabla de transición

| Estado | a | b | c | d |
|------|------|------|------|------|
| q0 | - | - | q1 | - |
| q1 | q2 | - | - | - |
| q2 | - | q3 | - | - |
| q3 | q4 | - | - | - |
| q4 | q4 | q4 | q4 | q4 |

## Palabras aceptadas

cabaa 
cabac 
cabda 
cabbb 
cabca 

## Palabras rechazadas

cabab 
cabdab 
cababb 
cabacb 
cababb



# Ejercicio 9
L = {aⁿcbᵐ | n>0 , m>0}

## Tupla
AFD = (Σ,Q,δ,q0,F)  
Σ = {a,b,c}  
Q = {q0,q1,q2,q3}  
q0 = inicial  
F = {q3}

## Tabla de transición

| Estado | a | b | c |
|------|------|------|------|
| q0 | q1 | - | - |
| q1 | q1 | - | q2 |
| q2 | - | q3 | - |
| q3 | - | q3 | - |

## Palabras aceptadas

aacbb 
acbbb 
aaacb 
aaabb 
aacbb 

## Palabras rechazadas

aaaaa 
ccccc 
bbbba 
acaaa 
bbbbb



# Ejercicio 10
L = {x cᵐ | x ∈ {a,b}* y número de b es par}

## Tupla
AFD = (Σ,Q,δ,q0,F)  
Σ = {a,b,c}  
Q = {q0,q1,q2}  
q0 = inicial  
F = {q0,q2}

## Tabla de transición

| Estado | a | b | c |
|------|------|------|------|
| q0 | q0 | q1 | q2 |
| q1 | q1 | q0 | q2 |
| q2 | q2 | q2 | q2 |

## Palabras aceptadas

aabcc 
abbcc 
aaacc 
bbccc 
aabbc 

## Palabras rechazadas

abccc 
bcccc 
abbca 
bbcab 
abcac
