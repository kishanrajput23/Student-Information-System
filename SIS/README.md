HOW TO COMPILE 2 OR MORE .CPP FILES WHEN THEY ARE IN DIFFERNET DIRECTORIES.

1. Open a terminal or command prompt.

2. Navigate to the Project/ directory using the cd command.

3. Compile admin.cpp into an object file (admin.o) using the -c flag:

``````
g++ -c src/admin.cpp -o build/admin.o
``````
This will generate the admin.o object file in the build/ directory.

4. Compile main.cpp into another object file (main.o):

```
g++ -c main.cpp -o build/main.o
```

This will generate the main.o object file in the build/ directory.

5. Link both object files to create the final executable:

```
g++ build/main.o build/admin.o -o my_program
```

This will create the executable named my_program in the Project/ directory.

6. Run the executable:

``
./my_program
```

This will execute your program.

By following these steps, you can compile both main.cpp and admin.cpp, even if they are located in different directories. 

The key is to specify the correct file paths when compiling and linking the code. Additionally, make sure you have included the correct header file paths in your source files for proper compilation.

# Use of cin.peek() != '\n'

The purpose of using cin.peek() != '\n' is to validate that the input for admno is a valid integer. If the input contains non-numeric characters (e.g., "23sw"), the cin stream will not extract those characters, and cin.peek() will still hold the first non-numeric character in the input stream. This allows the code to detect invalid input and display an error message.