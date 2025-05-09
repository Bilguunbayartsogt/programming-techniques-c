# Exercise 4

Write a C program to compute either the area of a circle or of a square, based on the choice
and inputs of the user. The user is requested to type a set of characters and numbers from
keyboard, in a specific order. The first character should be Q for square or I for circle. In case
it is a square, the user can decide whether the area should be computed given the value of the
diagonal or of the side of the square, by specifying its respective length after the character D
or S. In case it is a circle, the user can decide whether the area should be computed given the
value of the diameter or of the radius by specifying its respective length after the character D
or R, respectively. All the values inserted by the user should be integer, the computed area
should be a float.

For example, if the user types Q D10, the program should compute the area of a square with
diagonal equal to 10 and print the following on the screen:

The area of the square with diagonal 10 is 50.0

## Suggestions:
a) Define a constant PI for the value 3.14 with #define. Remember: with #define there are
no ‘=’ and no ‘;’
b) Acquire the input of the user. Careful: you need to acquire single characters and numeric
values from keyboard...
c) Compute the value of the area (float) based on the acquired input
d) Print the result on screen.
## Remember: 
Square: Area = S*S = D*D/2, Circle: Area = pi*R*R = pi*D*D/4
