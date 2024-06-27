import random

def calcular_probabilidad_ganar(EV1, EV2, AT, D,total_simulaciones = 10):
    victorias_vampiro1 = 0

    for _ in range(total_simulaciones):
        energia_vampiro1 = EV1
        energia_vampiro2 = EV2

        while ((energia_vampiro1 > 0) and (energia_vampiro2) > 0):
            dado = random.randint(1, 6)
            if dado >= AT:
                energia_vampiro2 -= D
                energia_vampiro1 += D
            else:
                energia_vampiro1 -= D
                energia_vampiro2 += D
        if energia_vampiro1 > 0:
            victorias_vampiro1 += 1
            
    probabilidad = (victorias_vampiro1 / total_simulaciones) * 100
    return probabilidad


testCasesList = []
stop = False
probabilidad = 1

while stop  == False:
    testCases = input("")
    
    if testCases == "0 0 0 0":
        stop = True
    
    try:
        EV1, EV2, AT, D = map(int, testCases.split())
    except ValueError:
        continue
    
    if EV1 >= 1 and EV2 <= 10 and (AT >= 1 and AT <= 5) and (D >= 1 and D <= 10):
        probabilidad = calcular_probabilidad_ganar(EV1, EV2, AT, D)
        testCasesList.append((EV1, EV2, AT, D, probabilidad))
        
for resultado in testCasesList:
    ultimo_numero = resultado[-1]
    print(ultimo_numero)