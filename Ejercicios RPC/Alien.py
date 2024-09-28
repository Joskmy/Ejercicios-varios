import heapq

# Función principal del ataque alienígena
def alien_attack(n, m, calles):
    # Construir grafo usando listas de adyacencia
    grafo = [[] for _ in range(n + 1)]
    numero_calles = [0] * (n + 1)  # Cantidad de calles conectadas por ciudad

    # Añadir las calles entre ciudades al grafo
    for u, v in calles:
        grafo[u].append(v)
        grafo[v].append(u)
        numero_calles[u] += 1
        numero_calles[v] += 1

    # Cola de prioridad para destruir ciudades más conectadas
    heap = []
    for i in range(2, n + 1):  
        heapq.heappush(heap, (-numero_calles[i], i))  

    dias = 0
    destruidas = set()  
    visitadas = set()  

    # Función auxiliar para verificar ciudades desconectadas de Nueva York (ciudad 1)
    def verificar_desconexion(ciudad, destruidas):
        visitados = set()

        # BFS para ver si alguna ciudad no puede conectarse a Ciudad 1
        def bfs(ciudad):
            queue = [ciudad]
            visitados.add(ciudad)
            while queue:
                actual = queue.pop(0)
                for vecino in grafo[actual]:
                    if vecino not in destruidas and vecino not in visitados:
                        visitados.add(vecino)
                        queue.append(vecino)

        bfs(1)  # Iniciar desde Ciudad 1

        # Las ciudades no visitadas están desconectadas de Nueva York
        desconectadas = set()
        for i in range(2, n + 1):
            if i not in visitados and i not in destruidas:
                desconectadas.add(i)

        return desconectadas

    # Simulación día a día
    nueva_york_destruida = False

    while heap or not nueva_york_destruida:
        # Limpiamos la cola de prioridad de ciudades destruidas
        while heap and (heap[0][1] in destruidas):
            heapq.heappop(heap)

        # Si ya no hay más ciudades que destruir, solo quedaría destruir Nueva York
        if not heap and not nueva_york_destruida:
            # Destruimos Nueva York
            dias += 1
            destruidas.add(1)
            nueva_york_destruida = True
        elif heap:
            # Seleccionamos la ciudad con mayor grado
            _, ciudad = heapq.heappop(heap)
            destruidas.add(ciudad)
            dias += 1

            # Eliminar sus conexiones
            for vecino in grafo[ciudad]:
                if vecino not in destruidas:
                    numero_calles[vecino] -= 1
                    heapq.heappush(heap, (-numero_calles[vecino], vecino))

            # Verificar si alguna ciudad se desconectó de Nueva York
            desconectadas = verificar_desconexion(1, destruidas)
            for ciudad_desconectada in desconectadas:
                destruidas.add(ciudad_desconectada)

        # Verificar si Nueva York fue destruida y ajustar la condición de salida
        nueva_york_destruida = 1 in destruidas

    return dias

# main
n, m = map(int, input().split())

# Verificar las restricciones
if not ((1 <= n <= 2 * 10**5) and ((n - 1) <= m <= 5 * 10**5)):
    raise ValueError("Los valores de n o m no cumplen con las restricciones")

calles = [tuple(map(int, input().split())) for entrada in range(m)] 

# Calcular y mostrar el número de días hasta que Nueva York sea destruida
print(alien_attack(n, m, calles))
