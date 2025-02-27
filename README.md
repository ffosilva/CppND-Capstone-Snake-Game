# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

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

## New Features

* Now the game starts only after a <ENTER> keypress

* There's no need of restarting the game for playing again

* Persistent high score (using file stream)

* Purple seed that reduces the speed in a half

* Score & high score on the window title

## Project Rubric

### README (All Rubric Points REQUIRED)

- [x] A README with instructions is included with the project

- [x] The README indicates which project is chosen.

- [x] The README includes information about each rubric point addressed.


### Compiling and Testing (All Rubric Points REQUIRED)

- [x] The submission must compile and run.

#### Loops, Functions, I/O

- [x] The project demonstrates an understanding of C++ functions and control structures.

- [x] The project reads data from a file and process the data, or the program writes data to a file. [(See highscore.cpp)](https://raw.githubusercontent.com/ffosilva/CppND-Capstone-Snake-Game/5ec18e1e99dae3adba9a1e2fcd737499f7b58dfa/src/highscore.cpp) 

- [x] The project accepts user input and processes the input.

#### Object Oriented Programming

- [x] The project uses Object Oriented Programming techniques.

- [x] Classes use appropriate access specifiers for class members.

- [x] Class constructors utilize member initialization lists.

- [ ] Classes abstract implementation details from their interfaces.

- [x] Classes encapsulate behavior.

- [ ] Classes follow an appropriate inheritance hierarchy.

- [x] Overloaded functions allow the same function to operate on different parameters.

- [ ] Derived class functions override virtual base class functions.

- [ ] Templates generalize functions in the project.

#### Memory Management

- [x] The project makes use of references in function declarations. [HERE](https://github.com/ffosilva/CppND-Capstone-Snake-Game/blob/5ec18e1e99dae3adba9a1e2fcd737499f7b58dfa/src/game.cpp#L39) and [HERE](https://github.com/ffosilva/CppND-Capstone-Snake-Game/blob/5ec18e1e99dae3adba9a1e2fcd737499f7b58dfa/src/highscore.cpp#L61) and more...

- [x] The project uses destructors appropriately.

- [x] The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.

- [ ] The project follows the Rule of 5.

- [ ] The project uses move semantics to move data, instead of copying it, where possible.

- [ ] The project uses smart pointers instead of raw pointers.

Concurrency

- [x] The project uses multithreading. [HERE](https://github.com/ffosilva/CppND-Capstone-Snake-Game/blob/5ec18e1e99dae3adba9a1e2fcd737499f7b58dfa/src/game.cpp#L17)

- [ ] A promise and future is used in the project.

- [x] A mutex or lock is used in the project. [HERE](https://github.com/ffosilva/CppND-Capstone-Snake-Game/blob/5ec18e1e99dae3adba9a1e2fcd737499f7b58dfa/src/game.cpp#L68) and [HERE](https://github.com/ffosilva/CppND-Capstone-Snake-Game/blob/5ec18e1e99dae3adba9a1e2fcd737499f7b58dfa/src/game.cpp#L91)

- [x] A condition variable is used in the project. [HERE](https://github.com/ffosilva/CppND-Capstone-Snake-Game/blob/5ec18e1e99dae3adba9a1e2fcd737499f7b58dfa/src/game.cpp#L20)


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
