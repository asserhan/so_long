# so_long

## Description

Project of the 42 school common core curriculum. The goal is to create a proof of concept of a 2D game using the [MinilibX](https://github.com/42Paris/minilibx-linux) graphic library and the ANSI C language.

This project is a simple game where the player must collect all the items on the map and reach the exit, the player can only move horizontally and vertically, the map is composed of walls, empty spaces, collectible items and the exit, the player loses if he collides with an enemy.

This project is build for educational purposes and you are free to use it as you wish.

If you are a 42 student, feel free to use this project as a reference, but remember: ** you need to understand the code to use it ** and maybe this is not compliant with that last subject you are working on, so be careful.

### MLX

The MinilibX is a simple X-Window programming API in C, designed for students, suitable for beginners.

## Code style

The code style used in this project is the [Norminette](https://github.com/42School/norminette) 
created by the 42 school and used in all related ANSI C projects in the context of the school.


<br>


## Installation

Before compiling the project it is necessary to install MLX library a guide can be found
in the [MinilibX](https://github.com/42Paris/minilibx-linux) repository.

**<em> this command will clone the project and the Libft submodule </em>**


</br>

This project is divided into two parts, the **mandatory** and the **bonus**.


To compile the **mandatory** part (character movement and item collection) use:
```sh
make
```

<p align="center">
<img src="https://github.com/andersonhsporto/ft-so_long/blob/main/img/Peek%2003-11-2021%2000-16.gif" width="800px" alt="mandatory"/><br>
</p>

To compile the **bonus** part (animation, movement counter and enemies) use:

```sh
make bonus
```
<p align="center">
<img src="https://github.com/andersonhsporto/ft-so_long/blob/main/img/Peek%2003-11-2021%2000-23.gif" width="400px" alt="bonus"/><br>
</p>

## Usage

After compiling the project, the executable file with the name **so_long** will be created, to run the game call the executable passing the map as an argument:

Example:

```sh
./so_long map.ber
```
**<em> some maps and the map used to generate the header image can be found in the maps folder </em>**
