#include <iostream>
#include <queue>
#include <string>
#include <limits> 
#include <cstdlib> 

using namespace std;

// Structure to hold each quiz question
struct Question {
    string questionText;
    string choices[4];
    int correctAnswer;

// Function to clear the screen
void cls() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

// Function to convert letter choices to index (a=0, b=1, c=2, d=3)
int letterToIndex(char letter) {
    return letter - 'a';
}

int main() {
    queue<Question> quizQueue;
    int score = 0;

    // Adding 10 questions to the quiz queue
    quizQueue.push({"What is the time complexity of binary search?", 
                    {"O(log n)", "O(n)", "O(n^2)", "O(n log n)"}, 0});
    quizQueue.push({"Which data structure is a FIFO?", 
                    {"Stack", "Queue", "Array", "Linked List"}, 1});
    quizQueue.push({"What is the worst-case time complexity of quicksort?", 
                    {"O(log n)", "O(n log n)", "O(n^2)", "O(n)"}, 2});
    quizQueue.push({"What data structure is best for implementing a LIFO?", 
                    {"Stack", "Queue", "Array", "Tree"}, 0});
    quizQueue.push({"What is the space complexity of a hash table?", 
                    {"O(n^2)", "O(log n)", "O(n)", "O(1)"}, 2});
    quizQueue.push({"Which algorithm is used to find the shortest path in a graph?", 
                    {"Dijkstra's algorithm", "Merge Sort", "Binary Search", "Quicksort"}, 0});
    quizQueue.push({"Which data structure is most suitable for recursion?", 
                    {"Queue", "Array", "Stack", "Graph"}, 2});
    quizQueue.push({"Which traversal technique is used in Depth First Search?", 
                    {"Inorder", "Breadth First", "Level Order", "Depth First"}, 3});
    quizQueue.push({"What is the time complexity of inserting an element into a linked list?", 
                    {"O(1)", "O(log n)", "O(n)", "O(n log n)"}, 0});
    quizQueue.push({"In a balanced binary search tree, what is the height complexity?", 
                    {"O(n)", "O(log n)", "O(n^2)", "O(1)"}, 1});

    cout << "Welcome to the Data Structures and Algorithms Quiz Game!\n";
    cout << "Answer the questions by entering the letter of your choice (a-d).\n\n";

    // Iterate over each question in the queue
    while (!quizQueue.empty()) {
        Question currentQuestion = quizQueue.front(); 
        quizQueue.pop(); 

        // Display the question and choices
        cout << currentQuestion.questionText << endl;
        char choiceLetter = 'a';
        for (int i = 0; i < 4; i++) {
            cout << choiceLetter++ << ". " << currentQuestion.choices[i] << endl;
        }

        // Get user answer with error handling
        char answer;
        while (true) {
            cout << "Your answer: ";
            cin >> answer;

            // Convert to lowercase to allow uppercase inputs too
            answer = tolower(answer);

            // Check if input is a valid letter (a-d)
            if (answer < 'a' || answer > 'd') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Invalid choice. Please enter a letter between a and d.\n";
            } else {
                break;
            }
        }

        // Convert answer to an index
        int answerIndex = letterToIndex(answer);

        // Check if the answer is correct
        if (answerIndex == currentQuestion.correctAnswer) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect. The correct answer is: " 
                 << static_cast<char>('a' + currentQuestion.correctAnswer) << ". " 
                 << currentQuestion.choices[currentQuestion.correctAnswer] << "\n";
        }
        cout << endl;

        // Clear screen for the next question
        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cin.get();
        cls(); 
    }

    // Display final score
    cout << "Quiz complete! Your score is: " << score << " out of 10.\n";

    return 0;
}

