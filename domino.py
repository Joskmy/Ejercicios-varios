import random

class FichaDomino:
    def __init__(self, izquierda, derecha):
        self.izquierda = izquierda
        self.derecha = derecha

    def __str__(self):
        return f"[{self.izquierda}|{self.derecha}]"

    def rotar(self):
        self.izquierda, self.derecha = self.derecha, self.izquierda

class Jugador:
    def __init__(self, nombre):
        self.nombre = nombre
        self.fichas = []

    def __str__(self):
        return f"Fichas de {self.nombre}: {[str(ficha) for ficha in self.fichas]}"

    def tiene_ficha(self, ficha):
        return ficha in self.fichas

    def jugar_ficha(self, ficha, tablero, lado):
        if not self.tiene_ficha(ficha):
            print("No tienes esta ficha.")
            return False

        if not tablero.es_movimiento_valido(ficha, lado):
            print("Movimiento inválido.")
            return False

        self.fichas.remove(ficha)
        tablero.agregar_ficha(ficha, lado)
        print(f"{self.nombre} jugó la ficha: {ficha} en el lado {lado}.")
        return True

class Tablero:
    def __init__(self):
        self.fichas = []

    def __str__(self):
        if not self.fichas:
            return "Tablero: (Vacío)"
        return "Tablero: " + " ".join(str(ficha) for ficha in self.fichas)

    def es_movimiento_valido(self, ficha, lado):
        if not self.fichas:
            return True
        
        if lado == 'izquierda':
            if ficha.derecha == self.fichas[0].izquierda:
                return True
        elif lado == 'derecha':
            if ficha.izquierda == self.fichas[-1].derecha:
                return True

        ficha.rotar()
        if lado == 'izquierda':
            if ficha.derecha == self.fichas[0].izquierda:
                return True
        elif lado == 'derecha':
            if ficha.izquierda == self.fichas[-1].derecha:
                return True

        ficha.rotar()
        return False

    def agregar_ficha(self, ficha, lado):
        if not self.fichas:
            self.fichas.append(ficha)
        elif lado == 'izquierda':
            self.fichas.insert(0, ficha)
        elif lado == 'derecha':
            self.fichas.append(ficha)
        else:
            print("Lado inválido.")


def repartir_fichas(jugadores, num_fichas):
    todas_las_fichas = [FichaDomino(i, j) for i in range(7) for j in range(i, 7)]
    random.shuffle(todas_las_fichas)

    for jugador in jugadores:
        jugador.fichas = todas_las_fichas[:num_fichas]
        todas_las_fichas = todas_las_fichas[num_fichas:]

def puede_jugar(jugadores, tablero):
    for jugador in jugadores:
        for ficha in jugador.fichas:
            for lado in ['izquierda', 'derecha']:
                if tablero.es_movimiento_valido(ficha, lado):
                    return True
    return False

def main():
    num_jugadores = int(input("Ingrese el número de jugadores (2-4): "))
    if num_jugadores < 2 or num_jugadores > 4:
        print("¡Número de jugadores inválido!")
        return

    jugadores = [Jugador(input(f"Ingrese el nombre del Jugador {i+1}: ")) for i in range(num_jugadores)]

    repartir_fichas(jugadores, 7)
    tablero = Tablero()

    jugador_actual = 0
    while puede_jugar(jugadores, tablero):
        print(f"\nTurno de {jugadores[jugador_actual].nombre}")
        print(tablero)
        print(jugadores[jugador_actual])

        indice_ficha = int(input("Ingrese el índice de la ficha para jugar (-1 para pasar): "))
        if indice_ficha == -1:
            jugadores[jugador_actual].fichas.append(random.choice([FichaDomino(i, j) for i in range(7) for j in range(i, 7)]))
        else:
            lado = input("Ingrese el lado para colocar la ficha (izquierda/derecha): ").upper()
            if jugadores[jugador_actual].jugar_ficha(jugadores[jugador_actual].fichas[indice_ficha], tablero, lado):
                print("Ficha jugada exitosamente.")

        jugador_actual = (jugador_actual + 1) % num_jugadores

    ganador = min(jugadores, key=lambda jugador: sum(ficha.izquierda + ficha.derecha for ficha in jugador.fichas))
    print(f"\n¡Juego terminado! {ganador.nombre} gana con la menor cantidad total de puntos.")

if __name__ == "__main__":
    main()
