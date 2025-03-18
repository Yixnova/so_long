# so_long
https://github.com/user-attachments/assets/9a6f818a-4533-47d9-bc0e-5a050c5f93db
## Introduction
In this project, we will code a simple 2D game with a limited mlx library.

### Game
The game we choose must follow a set of rules. The executable ``so_long`` will take a map as the only argument and this map must be of file type ``.ber``. Any memory leak will invalidate the project. It must conform to the norm and be able to run under all conditions.

The file must also follow these rules:
- Our map should contain only the characters ``P`` *(player)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectible item)* and ``E`` *(exit)*.
- The map should be rectangular, i.e. all lines should be the same length
- The map must have at least one exit, one player and one collectible item
- The map must be closed, i.e. surrounded by walls

If any of these checks fail, the game should end with ``Error\n`` followed by a special message.

The objective is for the player(s) to collect all collectibles on the map before reaching an exit in the fewest number of steps possible

For the graphics part of the project we used a library called ``minilibx``. It's fairly basic and somewhat limited.


## Gameplay

https://github.com/user-attachments/assets/94bd104b-bb93-4009-9c47-016bc24193c2

https://github.com/user-attachments/assets/744b2d18-bea5-4b1d-b66c-d5b55f168efc

Pressing the ``ESC``/``Q`` key ends the game. If the arrow keys ``⬆️``,``⬅️``, ``⬇️``, ``➡️`` are pressed, the Player on the map will change its orientation and try to move in that direction. If the Player reaches the exit and there are no collectibles left, the game ends and the system automatically exits.

https://github.com/user-attachments/assets/783d3c25-ef56-4722-b266-41c0e77817cf
