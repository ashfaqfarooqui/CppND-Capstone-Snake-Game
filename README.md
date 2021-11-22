# CPPND: Capstone Snake Game Example
In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

# Features added
1. The program takes as input the user name
2. The program asks the user if they would like to play again.
3. Score made by the user is tracked and stored in a file.
4. If there is a new highest this is reported to the user.
5. Before termination the top 5 scores are displayed out.
6. The game has been modified to accommodate two players
7. Player 2 plays with the following keys: 
   w- Up
   a- Down
   s- Left
   d- Right
   
   
# File structure
The following is a helicopter view of the different classes:

- Controller -- Handles user input while playing the game for both players
- Game --  the main class the initializes the Snake object and executes the game steps, places food and checks if there is a collision between the two snakes. 
- Renderer --  responsible for displaying and UI for the game
- Player --  Holds information about the player and corresponding score
- Score -- this class handles reading the previous scores and checks if a new highest is made. It also stores the scores into the scores.txt file.

# Specifications met
1. All three points related to "Loops, Functions, I/O"
2. First five points of OOP.
3. First point in memory Management
