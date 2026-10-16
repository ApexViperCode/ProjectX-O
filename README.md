🎮 Tic-Tac-Toe Game in C++
​A classic Tic-Tac-Toe game developed using C++, designed to deliver a fun and fast local 2-player competitive experience on the same device.
Features

​2-Player Mode: Play and strategize against a friend on the same screen in real time.
​Automatic Win/Draw Detection: Instant checks after every move to detect wins (horizontally, vertically, or diagonally) or a draw.
​Clean Board Display: Automatically updates the board layout after each turn to show moves clearly.
​Lightweight & Fast: Immediate execution and reliable programming logic powered by C++.

​Built With
​C++: Handles game logic, player turn management, and win/draw condition checks.

​How to Play
​Players get their respective symbols (Player 1 is X and Player 2 is O).
​Take turns entering the number corresponding to the slot where you want to place your mark.
​The game declares a winner when a player forms a line of 3 matching symbols, or ends in a draw if the board fills up completely.






const cppExamples = [
    {
        keyword: "variables",
        title: "1. Variables & Data Types",
        description: "Basic variable declarations such as integers, floats, characters, and strings.",
        code: `#include <iostream>\n#include <string>\nusing namespace std;\n\nint main() {\n    int age = 15;\n    double price = 19.99;\n    char grade = 'A';\n    string name = "Raman";\n    bool isCoding = true;\n\n    cout << name << " is " << age << " years old." << endl;\n    return 0;\n}`
    },
    {
        keyword: "cin cout",
        title: "2. Input and Output (cin / cout)",
        description: "How to print data and read input from the user using the console.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int num;\n    cout << "Enter a number: ";\n    cin >> num;\n    cout << "You entered: " << num << endl;\n    return 0;\n}`
    },
    {
        keyword: "if else",
        title: "3. If / Else Statements",
        description: "Making decisions and directing the program path based on a condition.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int score = 85;\n    if (score >= 50) {\n        cout << "Passed" << endl;\n    } else {\n        cout << "Failed" << endl;\n    }\n    return 0;\n}`
    },
    {
        keyword: "switch",
        title: "4. Switch Case Statement",
        description: "Useful for choosing between multiple specific predefined cases instead of nested if statements.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int day = 1;\n    switch(day) {\n        case 1: cout << "Sunday"; break;\n        case 2: cout << "Monday"; break;\n        default: cout << "Another day";\n    }\n    return 0;\n}`
    },
    {
        keyword: "for",
        title: "5. For Loop",
        description: "Repeating code execution for a specific and known number of times.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    for (int i = 1; i <= 5; i++) {\n        cout << "Number: " << i << endl;\n    }\n    return 0;\n}`
    },
    {
        keyword: "while",
        title: "6. While Loop",
        description: "Repeating code as long as a specified condition evaluates to True.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int i = 1;\n    while (i <= 3) {\n        cout << "Iteration " << i << endl;\n        i++;\n    }\n    return 0;\n}`
    },
    {
        keyword: "do while",
        title: "7. Do-While Loop",
        description: "Executing the code block at least once before checking the condition.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int x = 10;\n    do {\n        cout << "This will print at least once" << endl;\n    } while (x < 5);\n    return 0;\n}`
    },
    {
        keyword: "array",
        title: "8. 1D Arrays",
        description: "Storing multiple elements of the same data type in a sequential memory block.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int scores[3] = {90, 85, 95};\n    cout << "First element: " << scores[0] << endl;\n    return 0;\n}`
    },
    {
        keyword: "2d array",
        title: "9. 2D Arrays",
        description: "A table-like matrix defined by rows and columns.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int matrix[2][2] = {\n        {1, 2},\n        {3, 4}\n    };\n    cout << "Element at row 0, col 1: " << matrix[0][1] << endl;\n    return 0;\n}`
    },
    {
        keyword: "function",
        title: "10. Basic Functions",
        description: "Writing modular, reusable code blocks to organize your program.",
        code: `#include <iostream>\nusing namespace std;\n\nvoid sayHello() {\n    cout << "Welcome to C++!" << endl;\n}\n\nint main() {\n    sayHello();\n    return 0;\n}`
    },
    {
        keyword: "return function",
        title: "11. Function with Return Value",
        description: "A function that computes a result and returns it using the return keyword.",
        code: `#include <iostream>\nusing namespace std;\n\nint add(int a, int b) {\n    return a + b;\n}\n\nint main() {\n    int result = add(5, 7);\n    cout << "Sum: " << result << endl;\n    return 0;\n}`
    },
    {
        keyword: "struct",
        title: "12. Structures (Struct)",
        description: "Grouping different types of variables under a single custom structure name.",
        code: `#include <iostream>\nusing namespace std;\n\nstruct Person {\n    string name;\n    int age;\n};\n\nint main() {\n    Person p1 = {"Raman", 15};\n    cout << p1.name << " - " << p1.age << endl;\n    return 0;\n}`
    },
    {
        keyword: "pointer",
        title: "13. Pointers",
        description: "Variables that store the memory address of another variable.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int num = 42;\n    int* ptr = &num;\n\n    cout << "Value: " << *ptr << endl;\n    cout << "Memory Address: " << ptr << endl;\n    return 0;\n}`
    },
    {
        keyword: "reference",
        title: "14. References",
        description: "Creating an alias for an existing variable in memory.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int original = 100;\n    int &ref = original;\n\n    ref = 200;\n    cout << "Original value changed to: " << original << endl;\n    return 0;\n}`
    },
    {
        keyword: "string methods",
        title: "15. String Manipulation",
        description: "Using built-in functions like finding string length and accessing characters.",
        code: `#include <iostream>\n#include <string>\nusing namespace std;\n\nint main() {\n    string text = "Cyberpunk";\n    cout << "Length: " << text.length() << endl;\n    cout << "First character: " << text[0] << endl;\n    return 0;\n}`
    },
    {
        keyword: "class oop",
        title: "16. Classes & Objects (OOP)",
        description: "The foundation of Object-Oriented Programming to represent properties and behaviors.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Car {\npublic:\n    string brand;\n    void drive() {\n        cout << "Car is driving..." << endl;\n    }\n};\n\nint main() {\n    Car myCar;\n    myCar.brand = "BMW";\n    myCar.drive();\n    return 0;\n}`
    },
    {
        keyword: "constructor",
        title: "17. Constructor",
        description: "A special member function executed automatically when an object is created to initialize values.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Student {\npublic:\n    string name;\n    Student(string n) {\n        name = n;\n    }\n};\n\nint main() {\n    Student s1("Raman");\n    cout << s1.name << endl;\n    return 0;\n}`
    },
    {
        keyword: "inheritance",
        title: "18. Inheritance",
        description: "Passing properties and functions from a parent class to a child class.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Animal {\npublic:\n    void eat() { cout << "Eating..." << endl; }\n};\n\nclass Dog : public Animal {};\n\nint main() {\n    Dog d;\n    d.eat();\n    return 0;\n}`
    },
    {
        keyword: "vector",
        title: "19. Dynamic Vectors (Vector)",
        description: "A dynamic array that can change size and add elements at runtime.",
        code: `#include <iostream>\n#include <vector>\nusing namespace std;\n\nint main() {\n    vector<int> nums = {10, 20};\n    nums.push_back(30);\n\n    for(int n : nums) {\n        cout << n << " ";\n    }\n    return 0;\n}`
    },
    {
        keyword: "ternary operator",
        title: "20. Ternary Operator",
        description: "Writing a simple if-else statement in a single line.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int age = 18;\n    string status = (age >= 18) ? "Adult" : "Minor";\n    cout << status << endl;\n    return 0;\n}`
    }
];
