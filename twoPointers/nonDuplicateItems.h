#pragma once
#include <vector>

using namespace std;

/*url: https://www.designgurus.io/course-play/grokking-the-coding-interview/doc/638e33feac0cc8a9358a25ac */
class nonDuplicateItems
{
public:
    static int remove(vector<int>& arr)
    {
        if (arr.size() <= 1) return arr.size();
        if (arr.size() == 2) return arr[0] == arr[1] ? 1 : 2;

        int cur = 0, next = 1;
        while (next < arr.size())
        {
            while (next < arr.size() && arr[next] == arr[cur]) next++;
            if (next == arr.size()) return cur + 1;
            cur++;
            arr[cur] = arr[next];
        }

        return cur + 1;
    }
};

