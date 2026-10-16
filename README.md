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
        keyword: "smart_ptr unique_ptr",
        title: "1. Smart Pointers (std::unique_ptr)",
        description: "Exclusive ownership smart pointer that automatically deallocates dynamic memory when it goes out of scope, preventing memory leaks.",
        code: `#include <iostream>\n#include <memory>\nusing namespace std;\n\nclass Resource {\npublic:\n    Resource() { cout << "Resource Acquired\\n"; }\n    ~Resource() { cout << "Resource Destroyed\\n"; }\n    void sayHello() { cout << "Hello from Unique Resource!\\n"; }\n};\n\nint main() {\n    unique_ptr<Resource> res1 = make_unique<Resource>();\n    res1->sayHello();\n    // Ownership transfer using std::move\n    unique_ptr<Resource> res2 = move(res1);\n    if (!res1) cout << "res1 is now null after move.\\n";\n    res2->sayHello();\n    return 0;\n}`
    },
    {
        keyword: "shared_ptr",
        title: "2. Smart Pointers (std::shared_ptr)",
        description: "Shared ownership smart pointer that maintains a reference count, keeping the resource alive until all shared pointers pointing to it are destroyed.",
        code: `#include <iostream>\n#include <memory>\nusing namespace std;\n\nclass Node {\npublic:\n    int data;\n    shared_ptr<Node> next;\n    Node(int val) : data(val) { cout << "Node " << val << " created\\n"; }\n    ~Node() { cout << "Node " << data << " destroyed\\n"; }\n};\n\nint main() {\n    shared_ptr<Node> head = make_shared<Node>(10);\n    {\n        shared_ptr<Node> node2 = make_shared<Node>(20);\n        head->next = node2;\n        cout << "Reference count of node2: " << node2.use_count() << "\\n";\n    }\n    cout << "After inner scope, node still alive via head.\\n";\n    return 0;\n}`
    },
    {
        keyword: "move semantics rvalue",
        title: "3. Move Semantics & Rvalue References",
        description: "Optimizes performance by transferring ownership of dynamic resources instead of performing costly deep copies.",
        code: `#include <iostream>\n#include <utility>\nusing namespace std;\n\nclass Buffer {\n    size_t size;\n    int* data;\npublic:\n    Buffer(size_t s) : size(s), data(new int[s]) { cout << "Allocated memory.\\n"; }\n    // Move Constructor\n    Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {\n        other.size = 0;\n        other.data = nullptr;\n        cout << "Move Constructor: Ownership stolen.\\n";\n    }\n    ~Buffer() { delete[] data; }\n};\n\nint main() {\n    Buffer b1(1000);\n    Buffer b2(move(b1));\n    return 0;\n}`
    },
    {
        keyword: "lambda closures",
        title: "4. Lambda Expressions & Closures",
        description: "Anonymous inline function objects capable of capturing variables from their surrounding scope.",
        code: `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\nint main() {\n    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};\n    int threshold = 5;\n    \n    int count = count_if(numbers.begin(), numbers.end(), [threshold](int n) {\n        return n > threshold;\n    });\n    cout << "Elements greater than " << threshold << ": " << count << endl;\n    \n    // Generic lambda (C++14)\n    auto print = [](auto x) { cout << x << " "; };\n    for_each(numbers.begin(), numbers.end(), print);\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "function templates",
        title: "5. Function Templates & Specialization",
        description: "Writing generic function blueprints that operate on multiple data types with explicit template specialization support.",
        code: `#include <iostream>\n#include <string>\nusing namespace std;\n\ntemplate <typename T>\nT findMax(T a, T b) {\n    return (a > b) ? a : b;\n}\n\ntemplate <>\nconst char* findMax<const char*>(const char* a, const char* b) {\n    return (string(a) > string(b)) ? a : b;\n}\n\nint main() {\n    cout << "Max int: " << findMax(15, 42) << endl;\n    cout << "Max string: " << findMax("Alpha", "Beta") << endl;\n    return 0;\n}`
    },
    {
        keyword: "class templates",
        title: "6. Class Templates & Fixed Stack",
        description: "Creating generic container classes parameterized by type and non-type template arguments.",
        code: `#include <iostream>\nusing namespace std;\n\ntemplate <typename T, int Size>\nclass StackContainer {\n    T data[Size];\n    int top = -1;\npublic:\n    void push(T val) {\n        if (top < Size - 1) data[++top] = val;\n    }\n    T pop() {\n        if (top >= 0) return data[top--];\n        throw out_of_range("Stack Underflow!");\n    }\n};\n\nint main() {\n    StackContainer<int, 3> intStack;\n    intStack.push(100);\n    intStack.push(200);\n    cout << "Popped: " << intStack.pop() << endl;\n    return 0;\n}`
    },
    {
        keyword: "unordered_map hash table",
        title: "7. Hash Tables (std::unordered_map)",
        description: "Associative container storing key-value pairs with average O(1) time complexity for lookups using hash functions.",
        code: `#include <iostream>\n#include <unordered_map>\n#include <string>\nusing namespace std;\n\nint main() {\n    unordered_map<string, int> phoneBook;\n    phoneBook["Raman"] = 5551234;\n    phoneBook["Alex"] = 5559876;\n\n    string query = "Alex";\n    auto it = phoneBook.find(query);\n    if (it != phoneBook.end()) {\n        cout << it->first << "'s number is " << it->second << endl;\n    }\n    return 0;\n}`
    },
    {
        keyword: "unordered_set",
        title: "8. Hash Sets (std::unordered_set)",
        description: "Collection of unique keys stored in an unsorted hash-based structure allowing fast membership testing.",
        code: `#include <iostream>\n#include <unordered_set>\nusing namespace std;\n\nint main() {\n    unordered_set<int> uniqueIDs = {101, 102, 103, 101, 102};\n    uniqueIDs.insert(104);\n    \n    cout << "Unique elements: ";\n    for (int id : uniqueIDs) {\n        cout << id << " ";\n    }\n    cout << "\\nIs 103 present? " << (uniqueIDs.count(103) ? "Yes" : "No") << endl;\n    return 0;\n}`
    },
    {
        keyword: "operator overloading",
        title: "9. Operator Overloading",
        description: "Redefining standard operators (+, -, <<, etc.) to work naturally with custom user-defined classes.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Complex {\n    double real, imag;\npublic:\n    Complex(double r = 0, double i = 0) : real(r), imag(i) {}\n    \n    Complex operator + (const Complex& obj) {\n        return Complex(real + obj.real, imag + obj.imag);\n    }\n    void display() { cout << real << " + " << imag << "i\\n"; }\n};\n\nint main() {\n    Complex c1(3.0, 2.0), c2(1.5, 4.0);\n    Complex c3 = c1 + c2;\n    c3.display();\n    return 0;\n}`
    },
    {
        keyword: "exception handling",
        title: "10. Advanced Exception Handling",
        description: "Robust error management using try, catch blocks and standard runtime exceptions.",
        code: `#include <iostream>\n#include <stdexcept>\nusing namespace std;\n\ndouble divide(double num, double den) {\n    if (den == 0) throw runtime_error("Division by zero exception!");\n    return num / den;\n}\n\nint main() {\n    try {\n        cout << divide(10.0, 2.0) << endl;\n        cout << divide(5.0, 0.0) << endl;\n    } catch (const exception& e) {\n        cerr << "Caught exception: " << e.what() << endl;\n    }\n    return 0;\n}`
    },
    {
        keyword: "file io streams",
        title: "11. File Input/Output Streams",
        description: "Reading and writing persistent data streams to external storage files using fstream headers.",
        code: `#include <iostream>\n#include <fstream>\n#include <string>\nusing namespace std;\n\nint main() {\n    ofstream outFile("system_log.txt");\n    outFile << "System Boot Status: OK\\nNode ID: 404\\n";\n    outFile.close();\n\n    ifstream inFile("system_log.txt");\n    string line;\n    while (getline(inFile, line)) {\n        cout << line << endl;\n    }\n    inFile.close();\n    return 0;\n}`
    },
    {
        keyword: "polymorphism virtual",
        title: "12. Runtime Polymorphism & Virtual Functions",
        description: "Achieving dynamic method dispatch through base class pointers and virtual function overrides.",
        code: `#include <iostream>\n#include <vector>\nusing namespace std;\n\nclass Shape {\npublic:\n    virtual void draw() { cout << "Generic shape.\\n"; }\n    virtual ~Shape() {}\n};\n\nclass Circle : public Shape {\npublic:\n    void draw() override { cout << "Drawing Circle.\\n"; }\n};\n\nint main() {\n    vector<Shape*> shapes = { new Shape(), new Circle() };\n    for (Shape* s : shapes) {\n        s->draw();\n        delete s;\n    }\n    return 0;\n}`
    },
    {
        keyword: "abstract class interface",
        title: "13. Abstract Classes & Pure Virtual Functions",
        description: "Defining strict structural interfaces using pure virtual functions (= 0) that derived classes must implement.",
        code: `#include <iostream>\nusing namespace std;\n\nclass DatabaseConnection {\npublic:\n    virtual void connect() = 0;\n    virtual void disconnect() = 0;\n    virtual ~DatabaseConnection() {}\n};\n\nclass PostgreSQL : public DatabaseConnection {\npublic:\n    void connect() override { cout << "Connected to PostgreSQL.\\n"; }\n    void disconnect() override { cout << "Disconnected.\\n"; }\n};\n\nint main() {\n    DatabaseConnection* db = new PostgreSQL();\n    db->connect();\n    db->disconnect();\n    delete db;\n    return 0;\n}`
    },
    {
        keyword: "virtual inheritance diamond",
        title: "14. Virtual Inheritance & Diamond Problem",
        description: "Resolving ambiguity in multiple inheritance hierarchies where two base classes inherit from a common ancestor.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Device {\npublic:\n    int id = 777;\n};\nclass InputDevice : virtual public Device {};\nclass OutputDevice : virtual public Device {};\nclass SmartTerminal : public InputDevice, public OutputDevice {};\n\nint main() {\n    SmartTerminal term;\n    cout << "Terminal Device ID: " << term.id << endl;\n    return 0;\n}`
    },
    {
        keyword: "functors function objects",
        title: "15. Functors (Function Objects)",
        description: "Classes that overload the function call operator `operator()`, behaving like functions with internal states.",
        code: `#include <iostream>\nusing namespace std;\n\nstruct Accumulator {\n    int total = 0;\n    void operator()(int x) { total += x; }\n};\n\nint main() {\n    Accumulator acc;\n    acc(10);\n    acc(20);\n    acc(30);\n    cout << "Total accumulated sum: " << acc.total << endl;\n    return 0;\n}`
    },
    {
        keyword: "initializer_list",
        title: "16. Initializer Lists",
        description: "Enabling custom container classes to accept brace-enclosed initialization lists like standard containers.",
        code: `#include <iostream>\n#include <initializer_list>\nusing namespace std;\n\nclass CustomList {\n    int* data;\n    size_t size;\npublic:\n    CustomList(initializer_list<int> list) {\n        size = list.size();\n        data = new int[size];\n        size_t i = 0;\n        for (auto v : list) data[i++] = v;\n    }\n    ~CustomList() { delete[] data; }\n    void print() {\n        for (size_t i = 0; i < size; ++i) cout << data[i] << " ";\n        cout << endl;\n    }\n};\n\nint main() {\n    CustomList cl = {5, 10, 15, 20};\n    cl.print();\n    return 0;\n}`
    },
    {
        keyword: "variadic templates",
        title: "17. Variadic Templates",
        description: "Templates that accept an arbitrary number of arguments using parameter packs for metaprogramming.",
        code: `#include <iostream>\nusing namespace std;\n\nvoid printLog() {\n    cout << "[End]\\n";\n}\n\ntemplate <typename T, typename... Args>\nvoid printLog(T first, Args... args) {\n    cout << first << " ";\n    printLog(args...);\n}\n\nint main() {\n    printLog("Error code:", 404, "Module:", "Network", true);\n    return 0;\n}`
    },
    {
        keyword: "std::optional",
        title: "18. Optional Values (std::optional)",
        description: "Represents encapsulated values that may or may not be present, eliminating null-pointer hazards.",
        code: `#include <iostream>\n#include <optional>\nusing namespace std;\n\noptional<int> safeDivide(int a, int b) {\n    if (b == 0) return nullopt;\n    return a / b;\n}\n\nint main() {\n    auto res = safeDivide(20, 4);\n    if (res.has_value()) {\n        cout << "Result: " << res.value() << endl;\n    }\n    return 0;\n}`
    },
    {
        keyword: "std::variant",
        title: "19. Type-Safe Unions (std::variant)",
        description: "Represents a type-safe union holding one of several alternative types at any given time.",
        code: `#include <iostream>\n#include <variant>\n#include <string>\nusing namespace std;\n\nint main() {\n    variant<int, double, string> payload;\n    payload = 3.14159;\n    payload = "Cyberpunk OS";\n    \n    if (holds_alternative<string>(payload)) {\n        cout << "Payload string: " << get<string>(payload) << endl;\n    }\n    return 0;\n}`
    },
    {
        keyword: "std::any",
        title: "20. Type-Erased Containers (std::any)",
        description: "Container capable of holding single values of any arbitrary type safely.",
        code: `#include <iostream>\n#include <any>\n#include <string>\nusing namespace std;\n\nint main() {\n    any box = 99;\n    box = string("Encrypted Data");\n    \n    if (box.type() == typeid(string)) {\n        cout << "Box contains: " << any_cast<string>(box) << endl;\n    }\n    return 0;\n}`
    },
    {
        keyword: "custom sort lambda",
        title: "21. Custom Sorting with Lambda Comparators",
        description: "Sorting complex structures and custom objects using custom comparator lambdas in algorithms.",
        code: `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\nstruct Player {\n    string handle;\n    int score;\n};\n\nint main() {\n    vector<Player> leaderboard = { {"Apex", 1200}, {"Viper", 1500}, {"Code", 900} };\n    sort(leaderboard.begin(), leaderboard.end(), [](const Player& a, const Player& b) {\n        return a.score > b.score;\n    });\n    for (auto& p : leaderboard) {\n        cout << p.handle << ": " << p.score << endl;\n    }\n    return 0;\n}`
    },
    {
        keyword: "algorithm transform",
        title: "22. STL Algorithms (std::transform)",
        description: "Applying operations element-wise across containers and storing transformed outcomes efficiently.",
        code: `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\nint main() {\n    vector<int> src = {1, 2, 3, 4};\n    vector<int> dest(src.size());\n    \n    transform(src.begin(), src.end(), dest.begin(), [](int n) {\n        return n * n;\n    });\n    for (int v : dest) cout << v << " ";\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "rule of three five deep copy",
        title: "23. Rule of Three / Five (Deep Copy)",
        description: "Managing custom copy constructors, copy assignment operators, and destructors for raw memory safety.",
        code: `#include <iostream>\n#include <cstring>\nusing namespace std;\n\nclass ManagedString {\n    char* buffer;\npublic:\n    ManagedString(const char* s) {\n        buffer = new char[strlen(s) + 1];\n        strcpy(buffer, s);\n    }\n    // Copy Constructor (Deep Copy)\n    ManagedString(const ManagedString& other) {\n        buffer = new char[strlen(other.buffer) + 1];\n        strcpy(buffer, other.buffer);\n    }\n    ~ManagedString() { delete[] buffer; }\n    void show() { cout << buffer << endl; }\n};\n\nint main() {\n    ManagedString s1("Secure Session");\n    ManagedString s2 = s1;\n    s2.show();\n    return 0;\n}`
    },
    {
        keyword: "friend class functions",
        title: "24. Friend Classes & Encapsulation Bypass",
        description: "Granting external classes or functions direct access to private and protected class members.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Vault {\n    int secretKey = 9876;\n    friend class SecurityOfficer;\n};\n\nclass SecurityOfficer {\npublic:\n    void audit(Vault& v) {\n        cout << "Audited Secret Key: " << v.secretKey << endl;\n    }\n};\n\nint main() {\n    Vault v;\n    SecurityOfficer officer;\n    officer.audit(v);\n    return 0;\n}`
    },
    {
        keyword: "namespaces nested",
        title: "25. Nested Namespaces",
        description: "Organizing large codebases into hierarchical scopes to prevent global symbol naming collisions.",
        code: `#include <iostream>\nusing namespace std;\n\nnamespace SystemCore {\n    namespace Network {\n        void init() { cout << "Network subsystem online.\\n"; }\n    }\n}\n\nint main() {\n    SystemCore::Network::init();\n    return 0;\n}`
    },
    {
        keyword: "bitwise operations flags",
        title: "26. Bitwise Operations & Permission Flags",
        description: "Manipulating individual bits using logical bitwise operators (&, |, ^, <<, >>) for low-level flags.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    unsigned int READ = 4;    // 100\n    unsigned int WRITE = 2;   // 010\n    unsigned int EXEC = 1;    // 001\n\n    unsigned int permissions = READ | WRITE;\n    if (permissions & READ) {\n        cout << "Read access granted.\\n";\n    }\n    if (!(permissions & EXEC)) {\n        cout << "Execution access denied.\\n";\n    }\n    return 0;\n}`
    },
    {
        keyword: "memoization recursion",
        title: "27. Dynamic Programming & Memoization",
        description: "Optimizing recursive algorithms by caching computed subproblem outcomes to avoid redundant calculations.",
        code: `#include <iostream>\n#include <vector>\nusing namespace std;\n\nlong long fibMemo(int n, vector<long long>& memo) {\n    if (n <= 1) return n;\n    if (memo[n] != -1) return memo[n];\n    return memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);\n}\n\nint main() {\n    int n = 40;\n    vector<long long> memo(n + 1, -1);\n    cout << "Fibonacci(" << n << ") = " << fibMemo(n, memo) << endl;\n    return 0;\n}`
    },
    {
        keyword: "custom iterator range",
        title: "28. Custom Iterators & Range-Based For Support",
        description: "Building custom iterable classes compatible with range-based `for (auto x : container)` loops.",
        code: `#include <iostream>\nusing namespace std;\n\nclass CounterRange {\n    int start, stop;\npublic:\n    CounterRange(int s, int e) : start(s), stop(e) {}\n    struct Iterator {\n        int current;\n        bool operator!=(const Iterator& o) const { return current != o.current; }\n        int operator*() const { return current; }\n        Iterator& operator++() { ++current; return *this; }\n    };\n    Iterator begin() const { return {start}; }\n    Iterator end() const { return {stop}; }\n};\n\nint main() {\n    for (int n : CounterRange(1, 4)) {\n        cout << n << " ";\n    }\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::deque",
        title: "29. Double-Ended Queues (std::deque)",
        description: "Sequence container supporting fast insertion and deletion at both the beginning and the end.",
        code: `#include <iostream>\n#include <deque>\nusing namespace std;\n\nint main() {\n    deque<int> dq = {20, 30};\n    dq.push_front(10);\n    dq.push_back(40);\n    \n    cout << "Deque elements: ";\n    for (int n : dq) cout << n << " ";\n    cout << "\\nFront: " << dq.front() << " | Back: " << dq.back() << endl;\n    return 0;\n}`
    },
    {
        keyword: "multithreading mutex",
        title: "30. Multithreading & Mutex Locks",
        description: "Concurrent programming using std::thread and thread synchronization with std::mutex locks.",
        code: `#include <iostream>\n#include <thread>\n#include <mutex>\nusing namespace std;\n\nmutex mtx;\n\nvoid threadTask(int id) {\n    lock_guard<mutex> lock(mtx);\n    cout << "Thread " << id << " executing thread-safe task.\\n";\n}\n\nint main() {\n    thread t1(threadTask, 1);\n    thread t2(threadTask, 2);\n    t1.join();\n    t2.join();\n    cout << "All threads finished execution.\\n";\n    return 0;\n}`
    }
];
const additionalCppExamples = [
    {
        keyword: "std::list",
        title: "31. Doubly Linked List (std::list)",
        description: "Sequence container allowing non-contiguous memory allocation with fast constant-time insertions and deletions anywhere.",
        code: `#include <iostream>\n#include <list>\nusing namespace std;\n\nint main() {\n    list<int> l = {10, 20, 30};\n    l.push_front(5);\n    l.push_back(40);\n    cout << "List elements: ";\n    for (int n : l) cout << n << " ";\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::forward_list",
        title: "32. Singly Linked List (std::forward_list)",
        description: "Memory-efficient singly linked list supporting forward-only iteration and O(1) insertions at the front.",
        code: `#include <iostream>\n#include <forward_list>\nusing namespace std;\n\nint main() {\n    forward_list<int> fl = {3, 2, 1};\n    fl.push_front(4);\n    cout << "Forward list: ";\n    for (int n : fl) cout << n << " ";\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::set",
        title: "33. Sorted Unique Set (std::set)",
        description: "Associative container containing unique elements sorted automatically using strict weak ordering.",
        code: `#include <iostream>\n#include <set>\nusing namespace std;\n\nint main() {\n    set<int> s = {5, 1, 3, 1, 5};\n    s.insert(2);\n    cout << "Sorted unique set: ";\n    for (int n : s) cout << n << " ";\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::map",
        title: "34. Sorted Associative Map (std::map)",
        description: "Collection of key-value pairs sorted by unique keys with O(log n) search time complexity.",
        code: `#include <iostream>\n#include <map>\nusing namespace std;\n\nint main() {\n    map<string, int> scores;\n    scores["Apex"] = 95;\n    scores["Viper"] = 88;\n    for (auto& pair : scores) {\n        cout << pair.first << ": " << pair.second << endl;\n    }\n    return 0;\n}`
    },
    {
        keyword: "std::multiset",
        title: "35. Sorted Multiset (std::multiset)",
        description: "Associative container similar to set but allows storage of duplicate keys.",
        code: `#include <iostream>\n#include <set>\nusing namespace std;\n\nint main() {\n    multiset<int> ms = {10, 20, 10, 30, 20};\n    cout << "Count of 10s: " << ms.count(10) << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::multimap",
        title: "36. Sorted Multimap (std::multimap)",
        description: "Associative container mapping keys to multiple values while keeping keys sorted.",
        code: `#include <iostream>\n#include <map>\nusing namespace std;\n\nint main() {\n    multimap<int, string> mm;\n    mm.insert({1, "One"});\n    mm.insert({1, "Uno"});\n    cout << "Entries for key 1:\\n";\n    auto range = mm.equal_range(1);\n    for (auto it = range.first; it != range.second; ++it) {\n        cout << it->second << endl;\n    }\n    return 0;\n}`
    },
    {
        keyword: "std::priority_queue",
        title: "37. Priority Queue Heap (std::priority_queue)",
        description: "Container adaptor providing constant-time lookup of the largest (or smallest) element by default.",
        code: `#include <iostream>\n#include <queue>\nusing namespace std;\n\nint main() {\n    priority_queue<int> pq;\n    pq.push(10);\n    pq.push(50);\n    pq.push(20);\n    cout << "Top element (Max-Heap): " << pq.top() << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::queue",
        title: "38. Queue FIFO Adaptor (std::queue)",
        description: "Container adaptor implementing First-In, First-Out (FIFO) data structure operations.",
        code: `#include <iostream>\n#include <queue>\nusing namespace std;\n\nint main() {\n    queue<string> q;\n    q.push("First");\n    q.push("Second");\n    cout << "Front element: " << q.front() << endl;\n    q.pop();\n    cout << "New front after pop: " << q.front() << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::stack",
        title: "39. Stack LIFO Adaptor (std::stack)",
        description: "Container adaptor implementing Last-In, First-Out (LIFO) push and pop semantics.",
        code: `#include <iostream>\n#include <stack>\nusing namespace std;\n\nint main() {\n    stack<int> st;\n    st.push(100);\n    st.push(200);\n    cout << "Top of stack: " << st.top() << endl;\n    st.pop();\n    return 0;\n}`
    },
    {
        keyword: "std::bitset",
        title: "40. Fixed-Size Bitset (std::bitset)",
        description: "Compact fixed-size sequence representation optimized for bitwise manipulation operations.",
        code: `#include <iostream>\n#include <bitset>\nusing namespace std;\n\nint main() {\n    bitset<8> bits("10101010");\n    bits.flip(0);\n    cout << "Modified bitset: " << bits << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::valarray",
        title: "41. Numeric Array (std::valarray)",
        description: "Container optimized for high-performance mathematical array computations and slicing.",
        code: `#include <iostream>\n#include <valarray>\nusing namespace std;\n\nint main() {\n    valarray<double> arr = {1.0, 4.0, 9.0, 16.0};\n    valarray<double> result = sqrt(arr);\n    for (double v : result) cout << v << " ";\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::array",
        title: "42. Fixed-Size Aggregate Array (std::array)",
        description: "Zero-overhead wrapper container combining C-style array performance with STL iterators.",
        code: `#include <iostream>\n#include <array>\nusing namespace std;\n\nint main() {\n    array<int, 3> arr = {10, 20, 30};\n    cout << "Size: " << arr.size() << ", Element at 1: " << arr.at(1) << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::binary_search",
        title: "43. Binary Search Algorithm",
        description: "Efficiently checks whether an element exists within a sorted range in logarithmic time.",
        code: `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\nint main() {\n    vector<int> v = {2, 4, 6, 8, 10};\n    bool found = binary_search(v.begin(), v.end(), 6);\n    cout << "Is 6 found? " << (found ? "Yes" : "No") << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::accumulate",
        title: "44. Numeric Accumulation Algorithm",
        description: "Computes the sum or cumulative folding result across a sequence range.",
        code: `#include <iostream>\n#include <numeric>\n#include <vector>\nusing namespace std;\n\nint main() {\n    vector<int> v = {1, 2, 3, 4, 5};\n    int sum = accumulate(v.begin(), v.end(), 0);\n    cout << "Total sum: " << sum << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::inner_product",
        title: "45. Inner Product Algorithm",
        description: "Computes inner dot products or custom parallel accumulated operations over two ranges.",
        code: `#include <iostream>\n#include <numeric>\n#include <vector>\nusing namespace std;\n\nint main() {\n    vector<int> v1 = {1, 2, 3};\n    vector<int> v2 = {4, 5, 6};\n    int dot = inner_product(v1.begin(), v1.end(), v2.begin(), 0);\n    cout << "Dot product: " << dot << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::partial_sum",
        title: "46. Partial Sum Prefix Algorithm",
        description: "Calculates running prefix sums across a sequence range and stores outcomes.",
        code: `#include <iostream>\n#include <numeric>\n#include <vector>\nusing namespace std;\n\nint main() {\n    vector<int> v = {1, 2, 3, 4};\n    vector<int> res(4);\n    partial_sum(v.begin(), v.end(), res.begin());\n    for (int n : res) cout << n << " ";\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::adjacent_difference",
        title: "47. Adjacent Difference Algorithm",
        description: "Computes differences between adjacent pairs of elements in a range.",
        code: `#include <iostream>\n#include <numeric>\n#include <vector>\nusing namespace std;\n\nint main() {\n    vector<int> v = {2, 4, 8, 16};\n    vector<int> res(4);\n    adjacent_difference(v.begin(), v.end(), res.begin());\n    for (int n : res) cout << n << " ";\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::unique",
        title: "48. Remove Consecutive Duplicates (std::unique)",
        description: "Eliminates all consecutive duplicate elements from a range container sequence.",
        code: `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\nint main() {\n    vector<int> v = {1, 1, 2, 2, 3, 3};\n    auto it = unique(v.begin(), v.end());\n    v.erase(it, v.end());\n    for (int n : v) cout << n << " ";\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::rotate",
        title: "49. Range Rotation Algorithm",
        description: "Rotates the order of elements in a range so that a specified element becomes the first element.",
        code: `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\nint main() {\n    vector<int> v = {1, 2, 3, 4, 5};\n    rotate(v.begin(), v.begin() + 2, v.end());\n    for (int n : v) cout << n << " ";\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::partition",
        title: "50. Range Partition Algorithm",
        description: "Reorders elements in a range based on a predicate condition such that matching elements appear first.",
        code: `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\nint main() {\n    vector<int> v = {1, 2, 3, 4, 5, 6};\n    partition(v.begin(), v.end(), [](int n) { return n % 2 != 0; });\n    for (int n : v) cout << n << " ";\n    cout << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::lower_bound",
        title: "51. Lower Bound Binary Search",
        description: "Finds the iterator to the first element that is greater than or equal to a given value in a sorted range.",
        code: `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\nint main() {\n    vector<int> v = {10, 20, 30, 40, 50};\n    auto it = lower_bound(v.begin(), v.end(), 25);\n    cout << "Lower bound value: " << *it << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::upper_bound",
        title: "52. Upper Bound Binary Search",
        description: "Finds the iterator to the first element that is strictly greater than a given value in a sorted range.",
        code: `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\nint main() {\n    vector<int> v = {10, 20, 30, 40, 50};\n    auto it = upper_bound(v.begin(), v.end(), 30);\n    cout << "Upper bound value: " << *it << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::minmax_element",
        title: "53. MinMax Element Locator",
        description: "Locates both the minimum and maximum elements in a single sequential range pass.",
        code: `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\nint main() {\n    vector<int> v = {42, 10, 99, 5, 77};\n    auto result = minmax_element(v.begin(), v.end());\n    cout << "Min: " << *result.first << " | Max: " << *result.second << endl;\n    return 0;\n}`
    },
    {
        keyword: "type_traits is_integral",
        title: "54. Compile-Time Type Traits (is_integral)",
        description: "Inspects compile-time type properties to verify whether a given type is an integral number.",
        code: `#include <iostream>\n#include <type_traits>\nusing namespace std;\n\ntemplate <typename T>\nvoid checkType(T val) {\n    if constexpr (is_integral_v<T>) {\n        cout << "Type is integer.\\n";\n    } else {\n        cout << "Type is non-integer.\\n";\n    }\n}\n\nint main() {\n    checkType(10);\n    checkType(3.14);\n    return 0;\n}`
    },
    {
        keyword: "type_traits is_floating_point",
        title: "55. Compile-Time Type Traits (is_floating_point)",
        description: "Verifies whether a template or variable type is a floating-point number at compile time.",
        code: `#include <iostream>\n#include <type_traits>\nusing namespace std;\n\nint main() {\n    cout << boolalpha;\n    cout << "Is double floating point? " << is_floating_point_v<double> << endl;\n    cout << "Is int floating point? " << is_floating_point_v<int> << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::enable_if",
        title: "56. SFINAE & std::enable_if",
        description: "Conditionally enables specific template overloads based on compile-time evaluation criteria.",
        code: `#include <iostream>\n#include <type_traits>\nusing namespace std;\n\ntemplate <typename T>\nenable_if_t<is_integral_v<T>, void> printValue(T val) {\n    cout << "Integer value: " << val << endl;\n}\n\nint main() {\n    printValue(100);\n    // printValue(3.14); // Fails compilation as expected\n    return 0;\n}`
    },
    {
        keyword: "std::conditional",
        title: "57. Compile-Time Type Conditional Selection",
        description: "Selects between two alternative types at compile time based on a boolean condition flag.",
        code: `#include <iostream>\n#include <type_traits>\nusing namespace std;\n\nint main() {\n    using SelectedType = conditional_t<true, double, int>;\n    SelectedType val = 5.5;\n    cout << "Selected value: " << val << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::remove_reference",
        title: "58. Type Modifier Removal (remove_reference)",
        description: "Strips reference qualifiers (& or &&) from a given type definition.",
        code: `#include <iostream>\n#include <type_traits>\nusing namespace std;\n\nint main() {\n    using RefType = int&;\n    using CleanType = remove_reference_t<RefType>;\n    cout << "Is reference removed? " << !is_reference_v<CleanType> << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::decay",
        title: "59. Type Decay Simulation",
        description: "Applies type transformations similar to function parameter passing decay (arrays to pointers, cv-qualifiers stripped).",
        code: `#include <iostream>\n#include <type_traits>\nusing namespace std;\n\nint main() {\n    using Decayed = decay_t<const int(&)[5]>;\n    cout << "Decayed to pointer? " << is_pointer_v<Decayed> << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::is_same",
        title: "60. Type Identity Comparison (std::is_same)",
        description: "Checks whether two types are completely identical at compile time.",
        code: `#include <iostream>\n#include <type_traits>\nusing namespace std;\n\nint main() {\n    cout << boolalpha;\n    cout << "Are int and long same? " << is_same_v<int, long> << endl;\n    cout << "Are int and int same? " << is_same_v<int, int> << endl;\n    return 0;\n}`
    },
    {
        keyword: "static_assert",
        title: "61. Compile-Time Assertions (static_assert)",
        description: "Triggers compilation errors with custom messages when compile-time conditions fail.",
        code: `#include <iostream>\nusing namespace std;\n\ntemplate <typename T>\nvoid processSize() {\n    static_assert(sizeof(T) >= 4, "Type size must be at least 4 bytes!");\n}\n\nint main() {\n    processSize<int>();\n    return 0;\n}`
    },
    {
        keyword: "constexpr functions",
        title: "62. Compile-Time Evaluation (constexpr)",
        description: "Enables functions and variables to be evaluated and computed entirely at compile time.",
        code: `#include <iostream>\nusing namespace std;\n\nconstexpr int computeFactorial(int n) {\n    return (n <= 1) ? 1 : (n * computeFactorial(n - 1));\n}\n\nint main() {\n    constexpr int val = computeFactorial(5);\n    cout << "Compile-time factorial: " << val << endl;\n    return 0;\n}`
    },
    {
        keyword: "consteval immediate functions",
        title: "63. Immediate Functions (consteval)",
        description: "Ensures that a function is strictly evaluated at compile time and never at runtime.",
        code: `#include <iostream>\nusing namespace std;\n\nconsteval int square(int n) {\n    return n * n;\n}\n\nint main() {\n    constexpr int result = square(10);\n    cout << "Consteval result: " << result << endl;\n    return 0;\n}`
    },
    {
        keyword: "constinit variables",
        title: "64. Static Initialization (constinit)",
        description: "Ensures that variables with static or thread storage duration are initialized at compile time.",
        code: `#include <iostream>\nusing namespace std;\n\nconstinit int globalCounter = 42;\n\nint main() {\n    cout << "Constinit counter: " << globalCounter << endl;\n    return 0;\n}`
    },
    {
        keyword: "explicit keyword constructor",
        title: "65. Explicit Constructors",
        description: "Prevents unintended implicit type conversions and constructor conversions.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Distance {\n    double meters;\npublic:\n    explicit Distance(double m) : meters(m) {}\n    double get() const { return meters; }\n};\n\nint main() {\n    // Distance d = 15.5; // Error: implicit conversion prevented\n    Distance d(15.5);\n    cout << "Distance: " << d.get() << endl;\n    return 0;\n}`
    },
    {
        keyword: "mutable keyword",
        title: "66. Mutable Member Variables",
        description: "Allows member variables to be modified even inside const member functions or const objects.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Logger {\n    mutable int accessCount = 0;\npublic:\n    void log() const {\n        accessCount++;\n        cout << "Logged access count: " << accessCount << endl;\n    }\n};\n\nint main() {\n    const Logger l;\n    l.log();\n    l.log();\n    return 0;\n}`
    },
    {
        keyword: "volatile keyword",
        title: "67. Volatile Hardware Specifier",
        description: "Informs the compiler that a variable's value can change unexpectedly via hardware or external threads, preventing cache optimizations.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    volatile int* hwRegister = reinterpret_cast<volatile int*>(0xFF10);\n    // *hwRegister = 1;\n    cout << "Volatile pointer declared successfully.\\n";\n    return 0;\n}`
    },
    {
        keyword: "override specifier",
        title: "68. Virtual Override Specifier",
        description: "Explicitly verifies that a derived class method successfully overrides a virtual base class function.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Base {\npublic:\n    virtual void execute() { cout << "Base execute\\n"; }\n};\n\nclass Derived : public Base {\npublic:\n    void execute() override { cout << "Derived execute\\n"; }\n};\n\nint main() {\n    Derived d;\n    d.execute();\n    return 0;\n}`
    },
    {
        keyword: "final specifier",
        title: "69. Final Specifier",
        description: "Prevents further class inheritance or overriding of virtual methods in derived classes.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Base {\npublic:\n    virtual void run() final { cout << "Final run method\\n"; }\n};\n\nclass Derived : public Base {\n    // void run() override {} // Error: cannot override final function\n};\n\nint main() {\n    Base b;\n    b.run();\n    return 0;\n}`
    },
    {
        keyword: "default delete member functions",
        title: "70. Defaulted & Deleted Functions",
        description: "Explicitly controls generation of special member functions using `= default` and `= delete`.",
        code: `#include <iostream>\nusing namespace std;\n\nclass NonCopyable {\npublic:\n    NonCopyable() = default;\n    NonCopyable(const NonCopyable&) = delete;\n    NonCopyable& operator=(const NonCopyable&) = delete;\n};\n\nint main() {\n    NonCopyable nc1;\n    // NonCopyable nc2 = nc1; // Error: copy constructor deleted\n    cout << "NonCopyable object created.\\n";\n    return 0;\n}`
    },
    {
        keyword: "delegating constructors",
        title: "71. Delegating Constructors",
        description: "Allows a constructor to call another constructor within the same class to reduce code duplication.",
        code: `#include <iostream>\nusing namespace std;\n\nclass ServerConfig {\n    int port;\n    string host;\npublic:\n    ServerConfig(int p, string h) : port(p), host(h) {}\n    ServerConfig() : ServerConfig(8080, "localhost") {}\n    void show() { cout << host << ":" << port << endl; }\n};\n\nint main() {\n    ServerConfig cfg;\n    cfg.show();\n    return 0;\n}`
    },
    {
        keyword: "inheriting constructors",
        title: "72. Inheriting Base Constructors",
        description: "Uses the `using` declaration to inherit base class constructors directly in derived classes.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Base {\npublic:\n    Base(int x) { cout << "Base constructor with value: " << x << endl; }\n};\n\nclass Derived : public Base {\npublic:\n    using Base::Base;\n};\n\nint main() {\n    Derived d(99);\n    return 0;\n}`
    },
    {
        keyword: "structured bindings",
        title: "73. Structured Bindings",
        description: "Unpacks tuples, pairs, structures, and arrays directly into distinct named variables.",
        code: `#include <iostream>\n#include <tuple>\nusing namespace std;\n\nint main() {\n    tuple<int, string, double> t(1, "Apex", 98.6);\n    auto [id, name, score] = t;\n    cout << "ID: " << id << ", Name: " << name << ", Score: " << score << endl;\n    return 0;\n}`
    },
    {
        keyword: "inline variables",
        title: "74. Inline Variables",
        description: "Allows global variables to be defined directly inside header files without incurring multiple definition linker errors.",
        code: `#include <iostream>\nusing namespace std;\n\ninline int globalSystemVersion = 2026;\n\nint main() {\n    cout << "Inline System Version: " << globalSystemVersion << endl;\n    return 0;\n}`
    },
    {
        keyword: "static_cast",
        title: "75. Compile-Time Type Casting (static_cast)",
        description: "Performs safe compile-time type conversions between related types (like numeric types or pointers up hierarchies).",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    double pi = 3.14159;\n    int truncated = static_cast<int>(pi);\n    cout << "Truncated integer: " << truncated << endl;\n    return 0;\n}`
    },
    {
        keyword: "dynamic_cast",
        title: "76. Polymorphic Runtime Casting (dynamic_cast)",
        description: "Performs safe runtime type-checked downcasting in polymorphic class inheritance hierarchies.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Base {\npublic:\n    virtual ~Base() {}\n};\nclass Derived : public Base {\npublic:\n    void specialTask() { cout << "Derived task executed.\\n"; }\n};\n\nint main() {\n    Base* b = new Derived();\n    if (Derived* d = dynamic_cast<Derived*>(b)) {\n        d->specialTask();\n    }\n    delete b;\n    return 0;\n}`
    },
    {
        keyword: "const_cast",
        title: "77. Const Qualifier Casting (const_cast)",
        description: "Adds or removes const or volatile qualifiers from pointers and references.",
        code: `#include <iostream>\nusing namespace std;\n\nvoid printModified(const int* ptr) {\n    int* mutablePtr = const_cast<int*>(ptr);\n    *mutablePtr = 500;\n}\n\nint main() {\n    int val = 100;\n    printModified(&val);\n    cout << "Modified value: " << val << endl;\n    return 0;\n}`
    },
    {
        keyword: "reinterpret_cast",
        title: "78. Low-Level Bit Reinterpretation (reinterpret_cast)",
        description: "Converts between completely unrelated pointer and data types at the bit level.",
        code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int val = 65;\n    char* cPtr = reinterpret_cast<char*>(&val);\n    cout << "Reinterpreted pointer address value\\n";\n    return 0;\n}`
    },
    {
        keyword: "placement new",
        title: "79. Placement New Operator",
        description: "Constructs an object at a pre-allocated raw memory address.",
        code: `#include <iostream>\nusing namespace std;\n\nclass Test {\npublic:\n    Test() { cout << "Test constructed in place.\\n"; }\n    ~Test() { cout << "Test destroyed.\\n"; }\n};\n\nint main() {\n    char buffer[sizeof(Test)];\n    Test* t = new (buffer) Test();\n    t->~Test();\n    return 0;\n}`
    },
    {
        keyword: "std::allocator",
        title: "80. Custom Memory Allocation (std::allocator)",
        description: "Standard allocator interface for separating memory allocation from object construction.",
        code: `#include <iostream>\n#include <memory>\nusing namespace std;\n\nint main() {\n    allocator<int> alloc;\n    int* p = alloc.allocate(1);\n    alloc.construct(p, 555);\n    cout << "Allocated value: " << *p << endl;\n    alloc.destroy(p);\n    alloc.deallocate(p, 1);\n    return 0;\n}`
    },
    {
        keyword: "std::async std::future",
        title: "81. Asynchronous Tasks (std::async & std::future)",
        description: "Runs tasks asynchronously in separate threads and retrieves results via futures.",
        code: `#include <iostream>\n#include <future>\nusing namespace std;\n\nint computeAsync() {\n    return 42;\n}\n\nint main() {\n    future<int> fut = async(launch::async, computeAsync);\n    cout << "Async result: " << fut.get() << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::promise",
        title: "82. Asynchronous Promise Communication",
        description: "Provides a mechanism to store a value or exception to be retrieved asynchronously by a future.",
        code: `#include <iostream>\n#include <future>\n#include <thread>\nusing namespace std;\n\nvoid worker(promise<int>& p) {\n    p.set_value(99);\n}\n\nint main() {\n    promise<int> prom;\n    future<int> fut = prom.get_future();\n    thread t(worker, ref(prom));\n    cout << "Promise value: " << fut.get() << endl;\n    t.join();\n    return 0;\n}`
    },
    {
        keyword: "std::packaged_task",
        title: "83. Packaged Task Wrapping",
        description: "Wraps any callable target so that its execution result can be retrieved asynchronously via a future.",
        code: `#include <iostream>\n#include <future>\n#include <thread>\nusing namespace std;\n\nint main() {\n    packaged_task<int(int, int)> task([](int a, int b) { return a + b; });\n    future<int> fut = task.get_future();\n    thread t(move(task), 10, 20);\n    cout << "Packaged task result: " << fut.get() << endl;\n    t.join();\n    return 0;\n}`
    },
    {
        keyword: "std::atomic",
        title: "84. Atomic Lock-Free Variables",
        description: "Provides lock-free thread-safe operations on shared scalar variables across multiple threads.",
        code: `#include <iostream>\n#include <atomic>\n#include <thread>\nusing namespace std;\n\natomic<int> counter(0);\n\nvoid increment() {\n    for (int i = 0; i < 1000; ++i) counter++;\n}\n\nint main() {\n    thread t1(increment), t2(increment);\n    t1.join(); t2.join();\n    cout << "Atomic counter total: " << counter << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::condition_variable",
        title: "85. Thread Condition Variables",
        description: "Enables threads to wait until notified by another thread meeting specific criteria.",
        code: `#include <iostream>\n#include <thread>\n#include <mutex>\n#include <condition_variable>\nusing namespace std;\n\nmutex mtx;\ncondition_variable cv;\nbool ready = false;\n\nvoid runTask() {\n    unique_lock<mutex> lock(mtx);\n    cv.wait(lock, [] { return ready; });\n    cout << "Worker thread resumed.\\n";\n}\n\nint main() {\n    thread t(runTask);\n    {\n        lock_guard<mutex> lock(mtx);\n        ready = true;\n    }\n    cv.notify_one();\n    t.join();\n    return 0;\n}`
    },
    {
        keyword: "std::this_thread::sleep_for",
        title: "86. Thread Sleep Delays",
        description: "Suspends execution of the current thread for specified time intervals.",
        code: `#include <iostream>\n#include <thread>\n#include <chrono>\nusing namespace std;\n\nint main() {\n    cout << "Sleeping for 100ms...\\n";\n    this_thread::sleep_for(chrono::milliseconds(100));\n    cout << "Awake!\\n";\n    return 0;\n}`
    },
    {
        keyword: "std::recursive_mutex",
        title: "87. Recursive Mutex Locks",
        description: "Mutex lock that can be safely locked multiple times by the same owning thread.",
        code: `#include <iostream>\n#include <thread>\n#include <mutex>\nusing namespace std;\n\nrecursive_mutex rtx;\n\nvoid recursiveTask(int count) {\n    rtx.lock();\n    cout << "Count: " << count << endl;\n    if (count > 0) recursiveTask(count - 1);\n    rtx.unlock();\n}\n\nint main() {\n    recursiveTask(2);\n    return 0;\n}`
    },
    {
        keyword: "std::shared_mutex",
        title: "88. Reader-Writer Shared Mutex",
        description: "Provides shared read-lock access and exclusive write-lock access for concurrency optimization.",
        code: `#include <iostream>\n#include <shared_mutex>\n#include <thread>\nusing namespace std;\n\nshared_mutex smtx;\nint sharedData = 10;\n\nvoid reader() {\n    shared_lock<shared_mutex> lock(smtx);\n    cout << "Read data: " << sharedData << endl;\n}\n\nint main() {\n    thread t(reader);\n    t.join();\n    return 0;\n}`
    },
    {
        keyword: "std::call_once",
        title: "89. Thread-Safe Once Initialization",
        description: "Guarantees that a specified callable function is executed exactly once across threads.",
        code: `#include <iostream>\n#include <mutex>\n#include <thread>\nusing namespace std;\n\nonce_flag flag;\n\nvoid init() {\n    cout << "Initialized once.\\n";\n}\n\nvoid worker() {\n    call_once(flag, init);\n}\n\nint main() {\n    thread t1(worker), t2(worker);\n    t1.join(); t2.join();\n    return 0;\n}`
    },
    {
        keyword: "std::filesystem path",
        title: "90. Filesystem Paths Manipulation",
        description: "Cross-platform filesystem path construction, parsing, and directory management.",
        code: `#include <iostream>\n#include <filesystem>\nusing namespace std;\nnamespace fs = std::filesystem;\n\nint main() {\n    fs::path p = "/home/raman/project/main.cpp";\n    cout << "Filename: " << p.filename() << " | Extension: " << p.extension() << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::filesystem exists",
        title: "91. Filesystem Existence Checks",
        description: "Checks whether files, directories, or symlinks exist on storage media.",
        code: `#include <iostream>\n#include <filesystem>\nusing namespace std;\nnamespace fs = std::filesystem;\n\nint main() {\n    fs::path p = "system_log.txt";\n    cout << "Does log exist? " << (fs::exists(p) ? "Yes" : "No") << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::filesystem create_directory",
        title: "92. Directory Creation",
        description: "Programmatically creates new folder directories in the local filesystem storage.",
        code: `#include <iostream>\n#include <filesystem>\nusing namespace std;\nnamespace fs = std::filesystem;\n\nint main() {\n    fs::path dir = "logs_dir";\n    if (fs::create_directory(dir)) {\n        cout << "Directory created successfully.\\n";\n    }\n    return 0;\n}`
    },
    {
        keyword: "std::chrono duration",
        title: "93. Chrono Time Durations",
        description: "Represents time intervals and durations using high-precision ratio units.",
        code: `#include <iostream>\n#include <chrono>\nusing namespace std;\n\nint main() {\n    using namespace chrono;\n    seconds sec(10);\n    milliseconds ms = duration_cast<milliseconds>(sec);\n    cout << "10 seconds in milliseconds: " << ms.count() << "ms\\n";\n    return 0;\n}`
    },
    {
        keyword: "std::chrono high_resolution_clock",
        title: "94. High-Resolution Benchmarking Clocks",
        description: "Measures execution durations with maximum available system clock precision.",
        code: `#include <iostream>\n#include <chrono>\nusing namespace std;\n\nint main() {\n    auto start = chrono::high_resolution_clock::now();\n    // Do work...\n    auto end = chrono::high_resolution_clock::now();\n    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);\n    cout << "Execution time: " << duration.count() << " microseconds\\n";\n    return 0;\n}`
    },
    {
        keyword: "std::pair",
        title: "95. Heterogeneous Pair (std::pair)",
        description: "Combines two heterogeneous values into a single distinct aggregate object.",
        code: `#include <iostream>\n#include <utility>\nusing namespace std;\n\nint main() {\n    pair<string, int> item("Code", 404);\n    cout << "Key: " << item.first << ", Value: " << item.second << endl;\n    return 0;\n}`
    },
    {
        keyword: "std::tuple",
        title: "96. Heterogeneous Tuple (std::tuple)",
        description: "Fixed-size collection holding arbitrary numbers of heterogeneous values.",
        code: `#include <iostream>\n#include <tuple>\nusing namespace std;\n\nint main() {\n    tuple<int, char, string> t(7, 'A', "C++");\n    cout << "First tuple element: " << get<0>(t) << endl;\n    return 0;\n}`
    },
    {
        keyword: "define macros preprocessor",
        title: "97. Preprocessor Macro Definitions",
        description: "Defines constant macros and macro functions using preprocessor directives.",
        code: `#include <iostream>\nusing namespace std;\n\n#define SQUARE(x) ((x) * (x))\n#define VERSION 2026\n\nint main() {\n    cout << "Version: " << VERSION << ", Square of 5: " << SQUARE(5) << endl;\n    return 0;\n}`
    },
    {
        keyword: "ifdef conditional compilation",
        title: "98. Conditional Compilation Directives",
        description: "Controls code compilation blocks based on defined preprocessor symbols.",
        code: `#include <iostream>\nusing namespace std;\n\n#define DEBUG_MODE\n\nint main() {\n    #ifdef DEBUG_MODE\n    cout << "Debug mode is active.\\n";\n    #endif\n    return 0;\n}`
    },
    {
        keyword: "extern C linkage",
        title: "99. External C Linkage Specification",
        description: "Disables C++ name mangling to allow seamless integration and linkage with C libraries.",
        code: `#include <iostream>\nusing namespace std;\n\nextern "C" {\n    void cFunction() {\n        cout << "Called from C linkage scope.\\n";\n    }\n}\n\nint main() {\n    cFunction();\n    return 0;\n}`
    },
    {
        keyword: "namespace aliases",
        title: "100. Namespace Aliases",
        description: "Creates convenient shorthand aliases for long or deeply nested namespaces.",
        code: `#include <iostream>\nusing namespace std;\n\nnamespace VeryLongSystemNamespace {\n    void display() { cout << "Namespace alias active.\\n"; }\n}\n\nnamespace sys = VeryLongSystemNamespace;\n\nint main() {\n    sys::display();\n    return 0;\n}`
    }
];
