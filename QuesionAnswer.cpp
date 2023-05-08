#include <iostream>
#include <string>
int main()
{
    std::string questions[5] = {"1. Who is bro? ", "2. What has bro created? ", "3. Do bro smoke? ", "4. Bro is a ..... ", "5. Bro loves ....."};
    std::string options[][4] = {{"A. Bro", "B. Man", "C. Woman", "D. Jayed"}, {"A. Keyboard", "B. Mouse", "C. Baby", "D. Nothing"}, {"A. Yes", "B. No", "C. Maybe", "D. Maybe Not"}, {"A. Pro-Coder", "B. Coder", "C. Dinosaur", "D. Sigma-Male"}, {"A. Code", "B. Women", "C. Cat", "D. Weed"}};
    char answers[] = {'A', 'A', 'B', 'A', 'A'};

    char userAnswer;
    int score = 0;
    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++)
    {
        std::cout << "****************************\n";
        std::cout << questions[i] << "\n\n";
        for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++)
        {
            std::cout << options[i][j] << '\n';
        }
        std::cout << "****************************\n\n";
        std::cout << "Answer : ";
        std::cin >> userAnswer;

        char userAns = toupper(userAnswer);
        if (userAns == answers[i])
        {
            score++;
        }
        else
        {
            std::cout << "Wrong!"
                      << "\n"
                      << answers[i] << " is the correct answer\n";
        }
        std::cout << "\n";
    }
    std::cout << "\n\nYour total score is : " << score;
    return 0;
}