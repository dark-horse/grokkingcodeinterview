#pragma once

#include<vector>

/* url https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638f9b3e239cfbfb10ee82f3 */

/*
* Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array as objects, hence, we can’t count 0s, 1s, and 2s to recreate the array.
* The flag of the Netherlands consists of three colors: red, white and blue; and since our input array also consists of three different numbers that is why it is called Dutch National Flag problem.
*/

class dutchNationalFlag
{
public:
    static vector<int> sort(vector<int>& arr) {

        if (arr.size() <= 1) return arr;

        int left = 0, right = arr.size() - 1;
        while (left < arr.size() && arr[left] == 0) left++;
        while (right >= 0 && arr[right] == 2) right--;
        if (left >= right) return arr;

        for (int i = left; i <= right; i++)
        {
            int cur = arr[i];
            if (cur == 0)
            {
                // arr[left] cannot be 2 because we already visited arr[left]
                // and if it was 2 we would have swapped it with arr[right].
                // and arr[left] cannot be 0 because arr[left] is the first number in the 
                // list that is not 0.
                // arr[left] can be only 1;
                arr[i] = 1;
                arr[left] = 0;
                left++;
            }
            else if (cur == 2)
            {
                // arr[right] can be either 1 or 0 (it cannot be 2)
                if (arr[right] == 1)
                {
                    arr[i] = 1;
                }
                else
                {
                    // arr[right] can only be 0;
                    if (i > left) arr[i] = 1;
                    arr[left] = 0;
                    left++;
                }
                arr[right] = 2;
                while (arr[right] == 2) right--;
            }
        }

        return arr;
    }
};