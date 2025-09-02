[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/GwfT-LSL)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19843838&assignment_repo_type=AssignmentRepo)
# File IO

## Learning Goals

In this assignment, you will:

- Read characters and integers from files.
- Handle file permissions and potential errors.
- Convert between characters and their ASCII values.
- Pass data by address between functions.
- Write results to output files.
- Practice separate compilation by using multiple source files.

---

## **Part 1: Reading Characters from a File**

### **Function 1: Counting Character Frequencies**

You need to implement the function:

```c
bool countChar(const char *filename, int *counts, int size);
```

### **Instructions:**

1. Open the file specified by `filename` for reading.
   - If the file cannot be opened, return `false` and **do not call** `fclose()`.
2. Initialize all elements of the `counts` array to zero.
3. Read each character from the file and update the count of each character in the `counts` array based on its ASCII value.
   - Example: If the file contains 'A', increment `counts['A']`.
4. Stop reading at the end of the file.
5. Do not assume that `size` is always 256.
6. Close the file using `fclose()` after processing if the file opened successfully.

### **Function 2: Printing Character Counts**

You also need to implement:

```c
void printCounts(const int *counts, int size);
```

### **Instructions:**

1. Iterate through each index ind from 0 to size - 1 (inclusive).
2. Check the value of counts[ind]. If counts[ind] is zero, skip printing for that index.
3. For each valid index, print in the format:

   ```p
   "ind, onechar, counts[ind]"
   ```
   - ind: The index of the array element.
   - onechar: Print the character if ind corresponds to a lowercase letter ('a' to 'z') or an uppercase letter ('A' to 'Z').
      If the index does not correspond to an alphabetic character, print a space character instead.
   - counts[ind]: The count value for that index.


---

## **Part 2: Reading and Summing Integers from a File**

### **Function 3: Adding Numbers from a File**

Implement the function:

```c
bool addFile(const char *filename, int *sum);
```

### **Instructions:**

1. Open the file specified by `filename` for reading.
   - If the file cannot be opened, return `false` and **do not call** `fclose()`.
2. Initialize `*sum` to zero.
3. Read integers from the file using `fscanf()` and accumulate the sum.
4. Stop reading at the end of the file.
5. Close the file using `fclose()` if it opened successfully.

### **Function 4: Writing the Sum to a File**

Implement the function:

```c
bool writeSum(const char *filename, int sum);
```

### **Instructions:**

1. Open the file specified by `filename` for writing.
   - If the file cannot be opened, return `false`.
2. Write the sum as an integer to the file using `fprintf()`.
3. Close the file using `fclose()`.

---

## **Files and Separate Compilation**

- Write your code for character-related operations (Part 1) in `filechar.c`.
- Write your code for integer-related operations (Part 2) in `fileint.c`.
- Ensure your functions are compiled and linked separately.

---

## **Testing Your Program**

- The Makefile provided includes several test cases. Example:

  ```plaintext
  make test1
  ```
Feel free to create more custom test cases as well.

---

## **Submission Requirements**

- Submit the following files to gradescope:
  - `filechar.c`, `fileint.c`
Do this through the use of the zip command:
  -  `zip hw02.zip filechar.c fileint.c`
