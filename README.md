# Alx project task 0x19. C language - Stacks, Queues - LIFO, FIFO

## The goal of this project is to create an interpreter for Monty ByteCodes files.


### About Monty Language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. 

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.

### The monty program

**Usage:**

**`./monty filename`**

where **filename** is the path to the file containing Monty byte code ending with **.m**

**Supported operations:**

| Command | Description |
| --- | :-------------------------------------------------: |
| push | push an element onto the stack |
| pop | remove the top element from the stack |
| pall | print all elements on the stack |
| pint | print the top element |
| swap | swap position of top and sescond top element on the stack |
| add | perform addition of top and second top element on the stack |
| sub | like add but perform substraction |
|div | like add but perform division |
|mul | like add but perform multiplication |
|mod | like add but perform modulus |
|pchar | print the ascii representation of the top element on the stack |
| pstr | print all the element on the stack as a string |
| rotl | rotate the element to the to the left |
| rotr | perform right rotation |
| nop | perform nothing |
| stack | set the mode to stack |
| queue | set the mode to queue |

### Author

_Bello Abdulsamad_
