#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class OutOfRangeException : public exception
{
public:
    OutOfRangeException(const string& msg) : m_msg(msg) {}

    const char* what() const noexcept override
    {
        return m_msg.c_str();
    }

private:
    string m_msg;
};

float calculateAverage(int mark1, int mark2, int mark3, int mark4)
{
    vector<int> marks = { mark1, mark2, mark3, mark4 };
    int sum = 0;

    for (int mark : marks)
    {
        if (mark < 0 || mark > 100)
        {
            throw OutOfRangeException("Mark is out of range: " + to_string(mark));
        }
        sum += mark;
    }

    return static_cast<float>(sum) / marks.size();
}

int main()
{
    bool a = true;
    while (a == true)
    {
    int mark1, mark2, mark3, mark4;
    char c;

    cout << "Enter marks for four courses (between 0-100):\n";
    cin >> mark1;
    cin >> mark2;
    cin >> mark3;
    cin >> mark4;

    try
    {
        float average = calculateAverage(mark1, mark2, mark3, mark4);
        cout << "Average: " << average << endl;

        cout << "Would you want to another marks (y/n)?" << endl;
        cin >> c;
        if (c == 'n')
        {
            a = false;
            cout << "See you next time." << endl;
        }
    }
    catch (const OutOfRangeException& e)
    {
        cout << "Exception caught: " << e.what() << endl;
        cout << "Would you want to another marks (y/n)?" << endl;
        cin >> c;
        if (c == 'n')
        {
            a = false;
            cout << "See you next time." << endl;
        }
    }
    }

    return 0;
}
