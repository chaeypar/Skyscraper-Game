# 4x4 Sky Scraper Solver

&nbsp;This is a solver of the 4x4 version skyscraper game.

## What is Sky Scraper?

&nbsp;Sky Scraper is a game that everyone can enjoy. Each number outside the grid represents the number of building seen from that point. The objective of the game is to place all the numbers in the grid which represent the height of buildings. In 4x4 version game, the height of the skyscrapers is from 1 to 4 and skyscrapers on the same row or column should have unique heights.  

## Updates

&nbsp;If there are any updates, those will be listed here.

## Installation

&nbsp;Clone this repository with the command below.
```
git clone https://github.com/chaeypar/Skyscraper-Game-Solver
```

## How to use

1) After clone the repositofy, move to the directory 'Skyscraper-Game-Solver' and compile with the command below.
```
cd Skyscraper-Game-Solver
gcc -Wall -Wextra -Werror check.c find.c map.c print.c setting.c valid.c main.c -o solver
```

2) You can find solver file in the same directory now. 

3) Execute the file with the additional argument. The argument should consist of 16 numbers and each number represents the number outside the grid. The order should be upper side, lower side, left side and right side. Each side consists of 4 digits. Note that you need to use only one double quotation mark here. For example, If you want to get the solution for the image below, you need to excecute the solver file as follows.
```
./solver "2 3 3 1 3 2 1 3 2 1 2 3 1 2 3 2"
```

## Links

https://www.puzzle-skyscrapers.com/

## Version

-If there are any bugs, feel free to issue the git-report.
-This is a 4x4 version Skyscraper Solver and NxN version solver will be updated soon.
-Not the solver but the game itself will be updated soon.

## Contact

Feel free to contact me if there is any question.
-Chaeyeon Park (kidsland09@snu.ac.kr)