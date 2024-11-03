#include "stuinfo.hpp"
#include <iostream>

void inputstu(stuinfo stu[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter student name: ";
        std::cin >> stu[i].name;

        std::cout << "Enter three scores for student " << stu[i].name << ": ";
        for (int j = 0; j < 3; j++)
        {
            std::cin >> stu[i].score[j];
        }
        double sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += stu[i].score[j];
        }
        stu[i].ave = sum / 3;
    }
}

void showstu(stuinfo stu[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Name: " << stu[i].name << std::endl;
        std::cout << "Scores: ";
        for (int j = 0; j < 3; j++)
        {
            std::cout << stu[i].score[j] << " ";
        }
        std::cout << std::endl;
        std::cout << "Average Score: " << stu[i].ave << std::endl;
    }
}