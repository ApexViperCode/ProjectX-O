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






<!DOCTYPE html>
<html lang="ar" dir="rtl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>مكتبة أمثلة C++</title>
    <style>
        body {
            background-color: #090d16;
            color: #e2e8f0;
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            margin: 0;
            padding: 20px;
        }

        .container {
            max-width: 800px;
            margin: 40px auto;
        }

        h1 {
            text-align: center;
            color: #38bdf8;
            text-shadow: 0 0 10px rgba(56, 189, 248, 0.4);
            margin-bottom: 30px;
        }

        .search-box input {
            width: 100%;
            padding: 15px 20px;
            font-size: 16px;
            background: rgba(15, 23, 42, 0.8);
            border: 1px solid rgba(56, 189, 248, 0.4);
            border-radius: 12px;
            color: #fff;
            backdrop-filter: blur(10px);
            outline: none;
            box-sizing: border-box;
            box-shadow: 0 4px 20px rgba(0, 0, 0, 0.5);
        }

        .search-box input:focus {
            border-color: #38bdf8;
            box-shadow: 0 0 15px rgba(56, 189, 248, 0.4);
        }

        .results-grid {
            margin-top: 30px;
            display: flex;
            flex-direction: column;
            gap: 20px;
        }

        .card {
            background: rgba(30, 41, 59, 0.7);
            border: 1px solid rgba(255, 255, 255, 0.1);
            border-radius: 12px;
            padding: 20px;
            backdrop-filter: blur(10px);
            box-shadow: 0 8px 32px 0 rgba(0, 0, 0, 0.37);
        }

        .card h3 {
            margin-top: 0;
            color: #38bdf8;
        }

        .card p {
            color: #94a3b8;
            font-size: 14px;
        }

        pre {
            background: #030712;
            padding: 15px;
            border-radius: 8px;
            overflow-x: auto;
            direction: ltr;
            text-align: left;
            color: #4ade80;
            font-family: 'Courier New', Courier, monospace;
            font-size: 14px;
            border: 1px solid rgba(255, 255, 255, 0.05);
        }
    </style>
</head>
<body>

    <div class="container">
        <h1>بحث أمثلة C++</h1>
        
        <!-- مربع البحث -->
        <div class="search-box">
            <input type="text" id="searchInput" placeholder="ابحث عن مثال (مثل: for, if, while, array)...">
        </div>

        <!-- حاوية عرض النتائج -->
        <div id="resultsContainer" class="results-grid"></div>
    </div>

    <script>
        // قاعدة بيانات الأمثلة
        const cppExamples = [
            {
                keyword: "for",
                title: "حلقة التكرار For Loop",
                description: "تستخدم لتكرار تنفيذ كتلة برمجية عدد محدد من المرات.",
                code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    for(int i = 1; i <= 5; i++) {\n        cout << "الرقم: " << i << endl;\n    }\n    return 0;\n}`
            },
            {
                keyword: "if",
                title: "جملة الشرط If Statement",
                description: "تستخدم لاتخاذ قرار وتنفيذ كود معين إذا تحقق شرط محدد.",
                code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int grade = 85;\n    if(grade >= 50) {\n        cout << "ناجح!" << endl;\n    } else {\n        cout << "راسب!" << endl;\n    }\n    return 0;\n}`
            },
            {
                keyword: "while",
                title: "حلقة التكرار While Loop",
                description: "تكرر تنفيذ الكود طالما أن الشرط المكتوب يحقق القيمة (True).",
                code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int count = 1;\n    while(count <= 3) {\n        cout << "العداد: " << count << endl;\n        count++;\n    }\n    return 0;\n}`
            },
            {
                keyword: "array",
                title: "المصفوفات Arrays",
                description: "تستخدم لتخزين مجموعة من القيم من نفس النوع في متغير واحد.",
                code: `#include <iostream>\nusing namespace std;\n\nint main() {\n    int numbers[3] = {10, 20, 30};\n    cout << "العنصر الأول: " << numbers[0] << endl;\n    return 0;\n}`
            }
        ];

        const searchInput = document.getElementById('searchInput');
        const resultsContainer = document.getElementById('resultsContainer');

        // دالة لعرض الأمثلة
        function displayExamples(examplesToDisplay) {
            resultsContainer.innerHTML = ""; 
            
            if (examplesToDisplay.length === 0) {
                resultsContainer.innerHTML = `<p style="text-align: center; color: #94a3b8;">لم يتم العثور على أي مثال مطابق...</p>`;
                return;
            }

            examplesToDisplay.forEach(item => {
                const card = document.createElement('div');
                card.classList.add('card');
                card.innerHTML = `
                    <h3>${item.title}</h3>
                    <p>${item.description}</p>
                    <pre><code>${item.code}</code></pre>
                `;
                resultsContainer.appendChild(card);
            });
        }

        // عرض كل الأمثلة عند فتح الصفحة افتراضياً
        displayExamples(cppExamples);

        // الحدث عند الكتابة في مربع البحث
        searchInput.addEventListener('input', (e) => {
            const searchText = e.target.value.toLowerCase().trim();
            
            const filtered = cppExamples.filter(item => 
                item.keyword.toLowerCase().includes(searchText) ||
                item.title.toLowerCase().includes(searchText) ||
                item.description.toLowerCase().includes(searchText)
            );
            
            displayExamples(filtered);
        });
    </script>
</body>
</html>
