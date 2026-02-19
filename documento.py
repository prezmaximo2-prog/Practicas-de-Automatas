import re


lenguaje_curp = r'^[A-Z]{4}\d{6}[HM][A-Z]{5}[A-Z0-9]\d$'
lenguaje_rfc = r'^[A-Z&Ñ]{3,4}\d{6}[A-Z0-9]{3}$'
lenguaje_ine = r'^\d{10}$' 

resultados = []
seccion_actual = None
cantidad_esperada = 0
conteo_actual = 0

try:
    with open('LeerDocumento/documento.txt', 'r') as archivo:
        for linea in archivo:
            linea = linea.strip()
            if not linea: continue

            if linea.startswith('##'):
                seccion_actual = linea.replace('#', '')
                conteo_actual = 0
                resultados.append(f"--- Analizando {seccion_actual} ---\n")
                
            elif 'numero =' in linea:
                cantidad_esperada = int(linea.split('=')[1])
                
            elif seccion_actual and conteo_actual < cantidad_esperada:
                es_valido = False
                if seccion_actual == 'CURP':
                    es_valido = bool(re.match(lenguaje_curp, linea))
                elif seccion_actual == 'RFC':
                    es_valido = bool(re.match(lenguaje_rfc, linea))
                elif seccion_actual == 'INE':
                    es_valido = bool(re.match(lenguaje_ine, linea))
                
                status = "VÁLIDO" if es_valido else "INVÁLIDO"
                resultados.append(f"[{seccion_actual}] {linea}: {status}")
                conteo_actual += 1

    with open('LeerDocumento/MeEncantaPython(menosParaGUI).txt', 'w') as salida:
        salida.write("\n".join(resultados))
    
    print("Análisis completado. Revisa 'resultados_analisis.txt'")

except FileNotFoundError:
        print("Error: No se encontró el archivo 'documento.txt'")