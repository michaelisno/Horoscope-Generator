#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Zodiac 
{
    string name;
    int startMonth, startDay, endMonth, endDay;
};

Zodiac zodiacs[] = {
    {"Aries", 3, 21, 4, 19},
    {"Taurus", 4, 20, 5, 20},
    {"Gemini", 5, 21, 6, 20},
    {"Cancer", 6, 21, 7, 22},
    {"Leo", 7, 23, 8, 22},
    {"Virgo", 8, 23, 9, 22},
    {"Libra", 9, 23, 10, 22},
    {"Scorpio", 10, 23, 11, 21},
    {"Sagittarius", 11, 22, 12, 21},
    {"Capricorn", 12, 22, 1, 19},
    {"Aquarius", 1, 20, 2, 18},
    {"Pisces", 2, 19, 3, 20}
};
string horoscopes[] = {
    "Today is a great day to start a new project!",
    "You might receive good news from an unexpected source.",
    "Take time to relax and enjoy the small things.",
    "Trust your instincts in making decisions today.",
    "Someone close to you may need your support.",
    "A new opportunity is on the horizon.",
    "Embrace change, as it could lead to growth.",
    "A pleasant surprise might come your way soon.",
    "Your hard work is about to pay off.",
    "Focus on your goals and stay persistent.",
    "Today is a great day for creativity.",
    "You might meet someone who changes your perspective."
};

bool isDateInRange(int month, int day, int startMonth, int startDay, int endMonth, int endDay);

int main() 
{
    while (true) 
    {
        srand(static_cast<unsigned int>(time(0)));

        int month, day;
        cout << "Enter your birth month (1-12): ";
        cin >> month;
        cout << "Enter your birth day (1-31): ";
        cin >> day;

        string userZodiac = "Unknown";
        for (Zodiac z : zodiacs)
        {
            if (isDateInRange(month, day, z.startMonth, z.startDay, z.endMonth, z.endDay))
            {
                userZodiac = z.name;
                break;
            }
        }

        if (userZodiac != "Unknown")
        {
            cout << "Your zodiac sign is: " << userZodiac << endl;

            int randomIndex = rand() % 12;
            cout << "Horoscope: " << horoscopes[randomIndex] << endl;
        }
        else
        {
            cout << "Invalid date entered. Please try again." << endl;
        }


        string choice;
        cout << "Do you want to exit or continue? (e/c): " << endl;
        cin >> choice;

        if (choice == "e")
            break;
    }

    return 0;
}

bool isDateInRange(int month, int day, int startMonth, int startDay, int endMonth, int endDay)
{
    if (month == startMonth && day >= startDay) return true;
    if (month == endMonth && day <= endDay) return true;
    if (month > startMonth && month < endMonth) return true;
    return false;
}
