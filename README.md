# 👨‍💻 **Informe sobre el Proyecto de Ajedrez en C++** :

### Introducción :

  El ajedrez es un juego estratégico y fascinante que ha cautivado a jugadores de todas las edades y culturas a lo largo de la historia. Con el objetivo   de desarrollar habilidades cognitivas, toma de decisiones y pensamiento estratégico, el ajedrez ofrece un desafío intelectual único que ha sido objeto     de estudio y desarrollo en el ámbito de la informática.

  En este informe, presentaremos un proyecto de ajedrez desarrollado en C++ utilizando programación orientada a objetos, sobrecarga de operadores y la     biblioteca estándar de C++ (STL). Exploraremos la problemática que motivó el proyecto, la solución propuesta y su implementación, así como el diseño del   proyecto utilizando un diagrama UML.

--- 

### 📚 Problemática :


El juego de ajedrez presenta una serie de desafíos en su implementación informática, especialmente en lo que respecta a la representación del tablero, la validación de movimientos de las piezas y la detección de condiciones de juego como jaque y jaque mate. Además, el proyecto debe ser lo suficientemente modular y flexible para permitir futuras expansiones y mejoras.
Solución Propuesta

Para abordar la problemática mencionada, se propuso desarrollar un proyecto de ajedrez en C++ utilizando principios de programación orientada a objetos. La implementación se basaría en la creación de clases para representar las piezas, el tablero y el juego en sí. Se utilizaría la sobrecarga de operadores para facilitar la manipulación de las piezas y la interacción con el tablero. Además, se aprovecharía la STL de C++ para simplificar tareas como el almacenamiento de piezas y la gestión de movimientos válidos.

---

## ⚙️ Diseño e Implementación :



- ### UML:

Posición para insertar la imagen del diagrama UML


- #### Clase Abstracta Piece y sus Herencias :

Se definine una clase abstracta Piece, que representa las características y comportamientos comunes a todas las piezas del ajedrez. Luego, fueron creadas sus clases derivadas para cada tipo de pieza: Pawn (Peón) , Rook (Torre) , Knight (Caballero) , Bishop (Alfil) , Queen (Reina) y King (Rey). Cada una de estas clases hereda de la clase Piece y define sus movimientos específicos según las reglas del ajedrez.



- #### Clase Board :

La clase Board es un componente esencial del sistema de ajedrez, responsable de representar y gestionar el tablero de juego. Esta clase contiene una matriz bidimensional que representa las casillas del tablero, donde cada casilla puede contener una instancia de la clase Piece que representa una ficha de ajedrez.

Entre los métodos más importantes de la clase Board, se encuentra el método print, el cual imprime el tablero de juego en la consola, mostrando la disposición actual de las piezas. Además, el método getPieceAt permite obtener la pieza en una posición específica del tablero, lo cual es útil para verificar el estado del tablero y las piezas en él.

La clase Board también implementa métodos para validar movimientos y realizar operaciones específicas, como la promoción de peones, la captura al paso y el enroque. Estas operaciones implican la manipulación de las piezas en el tablero y la verificación de las reglas del ajedrez para garantizar que los movimientos sean válidos y consistentes.

- #### Clase Player :

La clase Player en este contexto es responsable de representar a un jugador dentro de la partida. Cada instancia de la clase Player modela a los jugadores del juego de ajedrez, con atributos como el nombre y el color de las piezas que controlan (blancas o negras) y puede realizar movimientos en su turno de acuerdo con las reglas del ajedrez.

- #### Game :

La clase Game es el componente principal del sistema de ajedrez, encargado de coordinar el flujo del juego y gestionar las interacciones entre el tablero, los jugadores y las reglas del ajedrez. Esta clase contiene instancias de la clase Board y dos objetos de la clase Player, representando a los jugadores blanco y negro.
Entre los métodos más destacados de la clase Game, se encuentra el método proccessMove , el cual permite a los jugadores realizar movimientos válidos en el tablero. Por ejemplo, al llamar a este método con las coordenadas de inicio y fin de un movimiento, junto con el color del jugador que realiza el movimiento, se verifica si el movimiento es válido y se realiza en el tablero. En caso de ser inválido, se muestra un mensaje de error y se solicita al jugador que intente nuevamente.

Otro método importante es getKingPosition, el cual devuelve la posición del rey de un determinado color en el tablero. Este método es crucial para verificar si un jugador está en jaque o jaque mate , métodos que tambien gestiona esta clase . 

Además, la clase Game se encarga de gestionar los casos especiales y las validaciones difíciles del juego, delegando parte de esta responsabilidad en las clases Board y las herencias de Piece. Por ejemplo, al realizar un movimiento, se verifica si el camino está despejado (Board->checkPathClear) y si el movimiento es válido según las reglas del ajedrez, como la captura al paso, el enroque y la promoción de peones.

---


### 🌟 Conclusiones:

La implementación exitosa del proyecto no solo ha demostrado la versatilidad y potencia del lenguaje de programación C++, sino que también ha brindado una sólida comprensión de cómo estructurar y organizar un proyecto complejo en un entorno orientado a objetos. Desde la representación de las piezas del ajedrez como objetos individuales hasta la gestión del tablero y la lógica del juego, cada componente del proyecto ha sido diseñado y desarrollado con cuidado para garantizar su eficacia y coherencia.

Este proyecto no solo ha sido una demostración de habilidades técnicas, sino también una oportunidad para explorar la creatividad y la resolución de problemas. La capacidad de abordar desafíos como la validación de movimientos, la lógica de la captura al paso y la promoción de peones ha permitido un profundo entendimiento de los detalles intrincados del juego de ajedrez y cómo se pueden traducir eficazmente en código.

En última instancia, el proyecto de ajedrez en C++ ha sentado las bases para futuras expansiones y mejoras, sirviendo como una plataforma sólida para explorar aún más el mundo del ajedrez y la programación. Con una base bien establecida y una comprensión sólida de los principios fundamentales, se abre la puerta a nuevas posibilidades para mejorar la funcionalidad, agregar características adicionales y llevar el proyecto a nuevas alturas en el futuro.
