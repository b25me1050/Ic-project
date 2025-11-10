# Word Replacement in a Text File using C

Indian Institute of Technology (IIT)

## 🎯 Objective
To develop a simple and efficient C program that reads a text file and replaces all occurrences of a specified word with another given word.  
The program supports:
 1.Case-insensitive replacement  
 2.Whole-word replacement (only full words are replaced, not parts of other words)  
 3.Efficient handling of large text files

## 🧠 Problem Description
Manually replacing words in large text files is time-consuming.  
Normal find-and-replace tools may replace parts of other words (like “pineapple” when replacing “apple”).  
This project solves that issue using C programming — ensuring only correct word matches are replaced efficiently.



## ⚙️ Algorithm
1. Start the program.  
2. Take input for file names, old word, and new word.  
3. Ask for case-insensitive and whole-word options.  
4. Open the input file in read mode and output file in write mode.  
5. Read the file line by line.  
6. Search and replace the word based on user options.  
7. Write each modified line to the output file.  
8. Repeat until end of file.  
9. Close files and display success message.  

🧩 Features
✅ Case-insensitive word replacement  
✅ Whole-word match option  
✅ Efficient file handling (works with large files)  
✅ Simple, modular C code  

---

 💻 Sample Input/Output

**Input File:**
```
Apple is sweet. apples are fruits.
Pineapple is not an apple.
```

**Replace Word:** apple → mango  
**Case-insensitive:** Yes  
**Whole-word:** Yes  

**Output File:**
```
Mango is sweet. mangoes are fruits.
Pineapple is not a mango.
```

---

## 🧰 Technologies Used
- Language: C  
- Concepts: File Handling, Strings, Loops, Conditional Statements  
- Compiler: GCC   

---

## 🚀 How to Run
1. Save the program as `word_replace.c`.  
2. Compile it using:  
   ```bash
   gcc word_replace.c -o word_replace
   ```
3. Run the executable:  
   ```bash
   ./word_replace
   ```
4. Follow the on-screen instructions to enter file names and options.  


## 📈 Applications
 1.Text file editing tools  
 2.Data cleaning and preprocessing  
 3.Automated report correction  



## 🔮 Future Enhancements
- Add graphical user interface (GUI).  
- Support multiple word replacements.  
- Add undo/redo functionality.  


