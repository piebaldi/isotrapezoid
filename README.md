# IsoTrapezoid
3 geometric shapes to be utilized

## A graphical user-interface for drawing 3 different polygons
This program was written for an excercise given in class. It allows the creation of isotrapezoids, rhombuses and rectangles

# Overview
The program utilizes features that are characteristic of C++: classes, objects and polymorphism, as well as virtual functions and inheritance. It also uses Doxygen comments for documentation.

# How to use
It is given a main for testing the classes. However, it requires the operator ">>" to be defined in the subclasses in order to work properly (in the given ones it has been defined). This is because the ">>" operator has to be of the specific object.

In the main.cpp there is a test that is capable of performing different actions depending on the user input:

Creates a rectangle object, it asks the user for the parameters
Creates a rhombus object, it asks the user for the parameters
Creates an isotrapezoid object, it asks the user for the parameters
Draws all object created
Exit the program
It should be noted that the "Draw" functions and "Draw" options do not actually draw the polygons, they are just a placeholder.

 # How to install
Af ter downloading all the source files, you can run the following commands in the terminal thanks to the Makefile:

run "make" to generate an executable.
run "make run" to generate an executable and run it
run "make clean" to remove all .o and the executable
Executing the "test" file will run the program

# Documentation
To generate documentation,

run "Doxygen" in the terminal. It will create some folders.
open the "html" directory and search for "index" It should then show the doxygen docuemntation
# Authors
Matteo Caroleo S5216938 Pietro Baldi S5331899
