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
    background: rgba(15, 23, 42, 0.7);
    border: 1px solid rgba(56, 189, 248, 0.3);
    border-radius: 12px;
    color: #fff;
    backdrop-filter: blur(10px);
    outline: none;
    box-sizing: border-box;
    transition: all 0.3s ease;
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
    background: rgba(30, 41, 59, 0.6);
    border: 1px solid rgba(255, 255, 255, 0.08);
    border-radius: 12px;
    padding: 20px;
    backdrop-filter: blur(10px);
    box-shadow: 0 8px 32px 0 rgba(0, 0, 0, 0.37);
    transition: transform 0.2s ease, border-color 0.2s ease;
}

.card:hover {
    border-color: rgba(56, 189, 248, 0.4);
    transform: translateY(-2px);
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

