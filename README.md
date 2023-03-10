# CS50x

<img src="https://github.com/jotavev/cs50x/blob/master/assets/Harvard_University_logo.jpg" alt="Harvard Logo" width="700"/>

CS50 is a face-to-face and online computer science course at Harvard University.  

This course is divided into weeks, and each week has a central topic and problem to solve.  

I made this repository to show the things studied in this course.  

___

## Lecture 0 (Scratch)

During week 0, we covered the fundamental principles of the computer world, including:
- How to computer represent data using binary 
- The definition of algorithms 
- Measuring the time to solve problems using the big-O notation
- Introduction to Scratch, a visual programming language

## Problem Set 0

In this class, I learned about Scratch, a visual programming language. As part of the course, we were given the freedom to solve a problem using Scratch, and I chose to create a game.

<img src="https://github.com/jotavev/cs50x/blob/master/assets/1pong_demo.gif" alt="Screenshot" width="350" />

My project is a retro game, similar to pong, but designed for single player. To play, click [here!](https://scratch.mit.edu/projects/778158229/)

___

## Lecture 1 (C language)

In this class, I learned the fundamentals of programming with C. I was able to apply concepts that I had already learned with Scratch to this text-based language, while also learning new concepts such as correctness, design, style, syntax, IDE, compiling, functions, arguments, return values, types, operators, conditional statements, loops, and variables.

## Problems Set 1

### Mario Pyramids 

the first problem set, is based in make a mario pyramid, using c.  

| Mario Pyramids|Program in c|
|:--------------------------------------------:| ---------------------------------------------- |
| <img src="./assets/mario2.png" width="300"/> | <img src="./assets/mario.gif"/> |

Can you check my solution clicking [here!](https://github.com/jotavev/cs50x/tree/master/lecture1/pset1/)

### Cash and Credit

The second problem set involves money.

Cash is a greedy algorithm used to minimize the number of coins required to give change to customers. The input is the value of the change, and the output is the number of coins that need to be dispensed.

| Cash                                        |
|---------------------------------------------|
| <img src="./assets/cash.gif"/> |



Credit is a program that checks credit card numbers. The program determines whether the input credit card number is invalid (returning `INVALID`) or, if valid, what type of card it is, returning `VISA`, `MASTERCARD`, or `AMEX` accordingly."

| Credit                                      |
|---------------------------------------------|
|  <img src="./assets/credit.gif"/> |

Can you check my solutions clicking [here!](https://github.com/jotavev/cs50x/tree/master/lecture1/pset1/)

___

## Lecture 2 (Arrays)

During the Lecture 2, I learned about:
- Debugging techniques and tools
- Command-line arguments (using argc and 
- Computer memory concepts, including what memory is, how to use arrays to store values, and their many applications.

## Problem set 2

This week, we were introduced to lab exercises, which are typically designed to help us practice specific concepts covered in class and/or introduce new concepts that will be used in the problem sets (psets)

### Lab 2: Scrabble

In this lab, I was tasked with implementing functions for a Scrabble game prompt, based on a given piece of code.

Scrabble is a word board game in which players create intersecting words on a board of numbered squares, using the letters on their game pieces to score points. The objective is to form words with higher scores, and players can earn extra points by utilizing special squares on the board. It's a popular game all over the world that requires both a good vocabulary and strategic thinking.

| Scrable |
|---|
| <img src="./assets/scrable.gif"/>|

### Readability

For this problem, I implemented a program that calculates the approximate grade level needed to comprehend some text, as described below.

| Readability |
|---|
| <img src="./assets/readability.gif"/>|


to do this I used the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

<pre>index = 0.0588 * L - 0.296 * S - 15.8</pre>

where `L` is the average number of letters per 100 words in the text, and `S` is the average number of sentences per 100 words in the text.

### Caesar

The story goes that Caesar used to "encrypt" (i.e., hide reversibly) confidential messages by shifting each letter in them by a fixed number of positions. For example, if the number were 1, he would write A as B, B as C, C as D...

to illustrate, here's how encryptiong `HELLO`with a key of 1 yields `IFMMP`:

| plaintext    | `H` | `E` | `L` | `L` | `O` |
|--------------|-----|-----|-----|-----|-----|
| + 1 key      |  1  |  1  |  1  |  1  |  1  | 
| = ciphertext | `I` | `F` | `M` | `M` | `P` |

For this problem, I implemented a program that encrypts messages using Caesar???s cipher, per the below.

| Caesar |
|---|
| <img src="./assets/caesar.gif"/>|

### Substituition

For this problem, I write a program that implements a substitution cipher, per the below.

| Substitution |
|---|
| <img src="./assets/substitution.gif"/>|

This program is similar to Caesar, but instead of choosing a fixed number to shift the letters, it uses a table with indexes arbitrarily defined by the user prompt.

Can you check my solutions clicking [here!](https://github.com/valentejorge/cs50x/tree/master/lecture2)

___

## Lecture 3 (Algorithms)

In Lecture 3, I learned about:
- A deeper understanding of Big-O notation
- Differences between linear and binary search
- Structuring custom data types
- Perfomance differences between sorting algorithms, including Bubble sort, Selection sort, and Merge sort
- Recursion 

### Lab 3: Sort

In this lab, I Analyze three compiled sorting programs to determine which algorithms they use.

I was provided with three already-compiled C programs: `sort1`, `sort2`, and `sort3`. Each program implements a different sorting algorithm, including `selection sort`, `bubble sort`, or `merge sort`. My task was to determine which sorting algorithm was used by each file. 

Multiple `.txt` files were provided, and each `.txt` file contained `n` lines of values, either reversed, shuffled, or sorted. I used the `time` Linux command the to run and analyze the time each program took to sort each file.

<details>
<summary>Click here to witness the power of technology in its most extravagant form! Get ready for a high-tech solution from another world!</summary>


| Ultra power Solution for Sort |
|---|
| <img src="./assets/sort.jpg"/>|
</details>

### Plurality 

For this task, I implemented a program that runs a plurality election, as shown below.

| Plurality |
|---|
| <img src="./assets/plurality.gif"/>|

### Runoff

For this task, I implemented a program that runs a runoff election, as shown below.

| Runoff |
|---|
| <img src="./assets/runoff.gif"/>|

A runoff election with ballots of three preferences is a type of preferential voting system in which voters rank the candidates in order of preference. If no candidate receives a majority of first preference votes in the initial count, then the candidate with the fewest first preference votes is eliminated, and their votes are transferred to the remaining candidates according to the next preference on each ballot. This process continues until one candidate has a majority of votes, and is declared the winner.

___

## Lecture 4 (Memory)

In Lecture 4, I learned about:
- Memory and memory layout in more depth
- Addresses and pointers
- Pointer arithmetic
- Hexadecimal and pixels
- Memory allocation
- Valgrind
- Garbage values

### Lab 4: Volume

For this task, I wrote a program to modify the volume of an `.wav` audio file.

<pre>
$ ./volume INPUT.wav OUTPUT.wav 2.0
</pre>

Where `INPUT.wav` is the name of an original audio file and `OUTPUT.wav` is the name of an audio file with a volume that has been scaled by the given factor (e.g., 2.0).

## Problem Set 4

### Filter

For this task, I implemented a program in C, that applies filters to BMPs, such as grayscale, sepia, blur, and reflected, modifying the pixels position or pixel colors of the input image to create a new output image with the desired effect.

<pre>
$ ./filter -g IMAGE.bmp GRAYSCALE.bmp
</pre>

where `IMAGE.bmp` is the name of an image file and `GRAYSCALE.bmp` is the name given to an output image file, now in black and white.

##### Grayscale

| Input | Output |
|-------|--------|
|<img src="/lecture4/pset4/filter-less/images/yard.bmp"  alt="1" width=300px height=200px >| <img src="/assets/yardGrayscale.bmp" alt="1" width=300px height=200px >|

##### Sepia

| Input | Output |
|-------|--------|
|<img src="/lecture4/pset4/filter-less/images/courtyard.bmp"  alt="1" width=300px height=200px >| <img src="/assets/courtyardSepia.bmp" alt="1" width=300px height=200px >|

##### Blur

| Input | Output |
|-------|--------|
|<img src="/lecture4/pset4/filter-less/images/stadium.bmp"  alt="1" width=300px height=200px >| <img src="/assets/stadiumBlur.bmp" alt="1" width=300px height=200px >|

##### Reflected

| Input | Output |
|-------|--------|
|<img src="/lecture4/pset4/filter-less/images/tower.bmp"  alt="1" width=300px height=200px >| <img src="/assets/towerReflected.bmp" alt="1" width=300px height=200px >|

### Recover

| Images | Program in c|
|:--------------------------------------------:| ---------------------------------------------- |
| <img src="./assets/recover.png" width="600"/> | <img src="./assets/recover.gif"/> |
___

## Lecture 5 ()