import heapq

# Función para mostrar el estado de las conexiones al final de cada día
def mostrar_estado(grafo, destruidas, n, dia):
    print(f"\nEstado al final del día {dia}:")
    for i in range(1, n + 1):
        if i in destruidas:
            print(f"Ciudad {i} destruida.")
        else:
            conectadas = [vecino for vecino in grafo[i] if vecino not in destruidas]
            print(f"Ciudad {i} conectada a: {conectadas}")
    
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
    for i in range(2, n + 1):  # Evitamos ciudad 1 (Nueva York)
        heapq.heappush(heap, (-numero_calles[i], i))  # Guardamos (grado negativo, ciudad)

    dias = 0
    destruidas = set()  # Ciudades destruidas
    visitadas = set()  # Ciudades que ya fueron procesadas

    # Función auxiliar para verificar ciudades desconectadas de Nueva York (ciudad 1)
    def verificar_desconexion(ciudad, destruidas):
        visitados = set()

        # BFS para ver si alguna ciudad no puede conectarse a Nueva York (Ciudad 1)
        def bfs(ciudad):
            queue = [ciudad]
            visitados.add(ciudad)
            while queue:
                actual = queue.pop(0)
                for vecino in grafo[actual]:
                    if vecino not in destruidas and vecino not in visitados:
                        visitados.add(vecino)
                        queue.append(vecino)

        bfs(1)  # Iniciar desde Nueva York (Ciudad 1)

        # Las ciudades no visitadas están desconectadas de Nueva York
        desconectadas = set()
        for i in range(2, n + 1):
            if i not in visitados and i not in destruidas:
                desconectadas.add(i)

        return desconectadas

    # Mostrar el estado inicial antes de empezar los días
    print("Estado inicial:")
    mostrar_estado(grafo, destruidas, n, dias)

    # Simulación día a día
    continuar = True
    while continuar and heap:
        # Limpiamos la cola de prioridad de ciudades destruidas
        while heap and (heap[0][1] in destruidas):
            heapq.heappop(heap)

        # Verificar si todavía hay ciudades para procesar
        continuar = len(heap) > 0

        if continuar:
            # Seleccionamos la ciudad con mayor grado
            _, ciudad = heapq.heappop(heap)
            destruidas.add(ciudad)
            dias += 1

            # Eliminar sus conexiones
            for vecino in grafo[ciudad]:
                if vecino not in destruidas:
                    numero_calles[vecino] -= 1
                    heapq.heappush(heap, (-numero_calles[vecino], vecino))

            # Mostrar el estado del grafo después de cada día
            mostrar_estado(grafo, destruidas, n, dias)

            # Verificar si alguna ciudad se desconectó de Nueva York
            desconectadas = verificar_desconexion(1, destruidas)
            if desconectadas:
                for ciudad in desconectadas:
                    if ciudad not in destruidas:
                        destruidas.add(ciudad)
                # Volver a mostrar el estado después de eliminar las desconectadas
                mostrar_estado(grafo, destruidas, n, dias)

            # Condición para terminar si Nueva York ha sido destruida
            continuar = 1 not in destruidas

    # Finalmente destruimos Nueva York si no fue destruida antes
    if 1 not in destruidas:
        dias += 1
        destruidas.add(1)
        mostrar_estado(grafo, destruidas, n, dias)

    return dias

# main
n, m = map(int, input().split())

# Verificar las restricciones
if not ((1 <= n <= 2 * 10**5) and ((n - 1) <= m <= 5 * 10**5)):
    raise ValueError("Los valores de n o m no cumplen con las restricciones")

calles = [tuple(map(int, input().split())) for entrada in range(m)] 

# Calcular y mostrar el número de días hasta que Nueva York sea destruida
resultado = alien_attack(n, m, calles)
print(f"\nNúmero total de días hasta que Nueva York fue destruida: {resultado}")
