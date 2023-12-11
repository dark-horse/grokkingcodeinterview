#pragma once

using namespace std;

#include<vector>
#include<stack>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/64c151c7505e25aa946412b6 */
/*
** Given an array of integers temperatures representing daily temperatures,
** your task is to calculate how many days you have to wait until a warmer temperature.
** If there is no future day for which this is possible, put 0 instead.
**
** Examples
** Input: temperatures = [70, 73, 75, 71, 69, 72, 76, 73]
** Output: [1, 1, 4, 2, 1, 1, 0, 0]
** Explanation: The first day's temperature is 70 and the next day's temperature is 73 which is warmer.
** So for the first day, you only have to wait for 1 day to get a warmer temperature.
** Hence, the first element in the result array is 1.
** The same process is followed for the rest of the days.
**
** Input: temperatures = [73, 72, 71, 70]
** Output: [0, 0, 0, 0]
** Explanation: As we can see, the temperature is decreasing every day. So, there is no future day with a warmer temperature. Hence, all the elements in the result array are 0.
**
** Input: temperatures = [70, 71, 72, 73]
** Output: [1, 1, 1, 0]
** Explanation: For the first three days, the next day is warmer.
** But for the last day, there is no future day with a warmer temperature.
** Hence, the result array is [1, 1, 1, 0].
*/

class dailyTemperaturesClass
{
public:
    static vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> res;
        for (int i = 0; i < temperatures.size(); i++)
        {
            bool found = false;
            for (int j = i + 1; j < temperatures.size(); j++)
            {
                found = temperatures[j] > temperatures[i];
                if (found)
                {
                    res.push_back(j - i);
                    break;
                }
            }

            if (!found) res.push_back(0);
        }

        return res;
    }

    static vector<int> dailyTemperaturesFast(vector<int>& temperatures)
    {
        vector<int> res = vector<int>(temperatures.size(), 0);
        if (temperatures.size() == 1)
        {
            return res;
        }

        if (temperatures.size() == 2)
        {
            res[0] = temperatures[1] > temperatures[0] ? 1 : 0;
            return res;
        }

        stack<pair<int, int>> tempsStack;
        tempsStack.push(std::make_pair(temperatures[0], 0));

        for (int i = 1; i < temperatures.size(); i++)
        {
            while (!tempsStack.empty() && temperatures[i] > tempsStack.top().first)
            {
                res[tempsStack.top().second] = i - tempsStack.top().second;
                tempsStack.pop();
            }

            tempsStack.push(std::make_pair(temperatures[i], i));
        }

        return res;
    }
};