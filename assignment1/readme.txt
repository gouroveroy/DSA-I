There are five source file in the directory named 2105017.Brief explanation about the main puspose of the source files below.

1.Arr.cpp:

The main purpose of this code is to implement a dynamic list data structure using an array. The class named "List" represents the list and provides various methods to manipulate the elements within the list.

The key features and functionality of this code include:

Dynamic resizing: The list automatically adjusts its size by doubling the chunk size whenever the current size is not sufficient to accommodate new elements.

Insertion and deletion: The code allows inserting new elements at the current position and removing elements from the current position within the list. It handles boundary cases such as removing the last element or an element from the beginning of the list.

Navigation and position tracking: The code provides methods to move the current position within the list, such as moving to the start, end, previous position, or next position. It also allows setting the current position explicitly using the "moveToPos" method.

Accessing list information: The code includes methods to retrieve the length of the list, the current position, and the value at the current position.

Printing the list: The code includes a method to print the elements of the list in a readable format.

Overall, the purpose of this code is to provide a basic implementation of a dynamic list using an array and offer essential operations to manipulate and
navigate through the list.

2.LL.cpp:

The main purpose of this code is to implement a dynamic list data structure using an array. The class named "List" represents the list and provides various methods to manipulate the elements within the list.

The key features and functionality of this code include:

Dynamic resizing: The list automatically adjusts its size by doubling the chunk size whenever the current size is not sufficient to accommodate new elements.

Insertion and deletion: The code allows inserting new elements at the current position and removing elements from the current position within the list. It handles boundary cases such as removing the last element or an element from the beginning of the list.

Navigation and position tracking: The code provides methods to move the current position within the list, such as moving to the start, end, previous position, or next position. It also allows setting the current position explicitly using the "moveToPos" method.

Accessing list information: The code includes methods to retrieve the length of the list, the current positio
You sent
n.

Printing the List: The code includes a method to print the elements of the list in a readable format. It distinguishes the current position within the list by using "|" symbol.

Overall, the purpose of this code is to provide a basic implementation of a doubly linked list and offer essential operations to manipulate and navigate through the list efficiently.

3.main.cpp:

The main purpose of this code is to provide an interactive program that demonstrates the functionality of the List class. It allows the user to perform various operations on the list by entering commands and parameters through the standard input.

The code starts by taking two input values, K and X, representing the number of initial elements to be added to the list and the initial size of the list, respectively. Then, it creates an instance of the List class called "L" with the specified initial size and initializes it with the given elements.

After initializing the list, the code enters a loop where it prompts the user for the number of subsequent operations (S). It then iterates S times, reading a command (Q) and a parameter (P) for each operation.

Based on the command entered, the code calls the corresponding method from the List class and performs the desired operation. For example, commands 1, 2, 3, 4, 5, 6, 7, 8, 9, and 10 correspond to the methods insert, remove, moveToStart, moveToEnd, prev, next, print_list and length, currPos, moveToPos, and getValue, respectively.

After each operation, the code prints the updated list using the print_list method and displays additional information, such as the removed value or the current position, depending on the command.

The program continues to loop until all the specified operations have been performed. Finally, it exits gracefully by returning 0.

Overall, the purpose of this code is to provide a user-friendly interface to interact with the List class and demonstrate the functionality of the implemented list data structure.

4.Task_2.cpp:

The main purpose of this code is to demonstrate the functionality of the List class by providing an interactive program that allows the user to perform operations on a list.

The code starts by reading two input values, K and X, from the user. K represents the number of initial elements to be added to the list, and X represents the initial size of the list. Then, an instance of the List class called "L" is created with the specified initial size.

Next, the code enters a loop where it reads the number of subsequent operations (S) from the user. It then iterates S times, reading a command (Q) and a parameter (P) for each operation.

Based on the command entered, the code performs different operations on the list. For example, if the command is 1, the code calls the clear() method of the List class to remove all elements from the list. If the command is 2, the code calls the append(P) method to add the parameter value P to the end of the list. If the command is 3, the code calls the Search(P) method to search for the value P in the list and returns its index.

After each operation, the code prints the updated list using the print_list() method and displays additional information, such as the search result or a placeholder (-1) depending on the command.

The program continues to loop until all the specified operations have been performed. Finally, it exits gracefully by returning 0.

Overall, the purpose of this code is to provide a user-friendly interface to interact with the List class, demonstrate its functionality, and showcase specific operations such as clearing the list, appending elements, and searching for values within the list.

5.Task_3.cpp:

The main purpose of this code is to simulate a parking garage system. The program allows the user to interact with the system by entering commands and parameters.

The code starts by reading three input values: X, Y, and Z. X represents a maximum value, Y represents the number of parking slots (courses), and Z represents the maximum capacity of each parking slot.

Next, the code initializes an array of List objects called "crsList" with a size of Y. These List objects represent the parking slots.

The code then enters a loop where it reads a series of input values for each parking slot. It reads a line of space-separated numbers as a string and extracts the individual numbers to initialize the corresponding List object.

After initializing the List objects, an integer array called "garage" is created to store the current state of the parking slots. The garage array holds the values of the parked cars in the slots.

The program then calls the print() function to display the initial state of the parking slots by iterating over the garage array and the List objects.

Next, the program enters another loop where it waits for user input. The user can enter three commands: "req", "ret", or "end".

If the command is "req", the program checks for the next available parking slot (course) with a non-empty list and removes the smallest value from that list.

If the command is "ret", the program expects an additional parameter indicating the car to be returned. The program searches for the next available parking slot (course) with a list capacity of less than Z, and inserts the car at the appropriate position.

If the command is "end", the program terminates.

After each command, the print() function is called again to display the updated state of the parking slots.

Overall, the code simulates a parking garage system where cars can be requested and returned to different parking slots. It uses List objects to represent the parking slots and provides a user-friendly interface to interact with the system.