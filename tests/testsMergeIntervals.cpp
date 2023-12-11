#include "pch.h"
#include "CppUnitTest.h"
#include "..\mergeIntervals\mergeIntervals.h"
#include "..\mergeIntervals\minimumMeetingRooms.h"
#include "..\mergeIntervals\maxCPULoad.h"
#include "..\mergeIntervals\employeeFreeTime.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace testsMergeIntervals
{
	TEST_CLASS(slidingWindowTests)
	{
		TEST_METHOD(checkMergeIntervals)
		{
			vector<tuple<vector<mergeIntervals::Interval>, vector<mergeIntervals::Interval>>> testcases =
			{
				{{mergeIntervals::Interval(1,4), mergeIntervals::Interval(2,5), mergeIntervals::Interval(7,9)}, {mergeIntervals::Interval(1,5), mergeIntervals::Interval(7,9)}},
				{{mergeIntervals::Interval(1,2), mergeIntervals::Interval(2,5), mergeIntervals::Interval(5,9)}, {mergeIntervals::Interval(1,9)}},
				{{mergeIntervals::Interval(1,4), mergeIntervals::Interval(1,2), mergeIntervals::Interval(1,9)}, {mergeIntervals::Interval(1,9)}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = mergeIntervals::merge(get<1>(testcases[i]));
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
		}

		TEST_METHOD(checkMinimumMeetingRooms)
		{
			vector<tuple<vector<minimumMeetingRooms::Meeting>, int>> testcases =
			{
				{{minimumMeetingRooms::Meeting(4,5), minimumMeetingRooms::Meeting(2,3), minimumMeetingRooms::Meeting(2, 4), minimumMeetingRooms::Meeting(3, 5)}, 2},
				{{minimumMeetingRooms::Meeting(1,5)}, 1},
				{{minimumMeetingRooms::Meeting(1,5), minimumMeetingRooms::Meeting(1,6), minimumMeetingRooms::Meeting(1, 7)}, 3},
				{{minimumMeetingRooms::Meeting(1,4), minimumMeetingRooms::Meeting(1,5), minimumMeetingRooms::Meeting(2, 3)}, 3},
				{{minimumMeetingRooms::Meeting(1,5), minimumMeetingRooms::Meeting(2,7), minimumMeetingRooms::Meeting(3, 8), minimumMeetingRooms::Meeting(4, 9), minimumMeetingRooms::Meeting(5, 10)}, 4},
				{{minimumMeetingRooms::Meeting(1,5), minimumMeetingRooms::Meeting(4,5), minimumMeetingRooms::Meeting(2,7), minimumMeetingRooms::Meeting(3, 8), minimumMeetingRooms::Meeting(4, 9), minimumMeetingRooms::Meeting(5, 10)}, 5},
				{{minimumMeetingRooms::Meeting(1,2), minimumMeetingRooms::Meeting(2,3), minimumMeetingRooms::Meeting(3,4), minimumMeetingRooms::Meeting(5, 6), minimumMeetingRooms::Meeting(6, 7), minimumMeetingRooms::Meeting(7, 8)}, 1},
				{{minimumMeetingRooms::Meeting(1,7), minimumMeetingRooms::Meeting(2,3), minimumMeetingRooms::Meeting(3,4), minimumMeetingRooms::Meeting(5, 7), minimumMeetingRooms::Meeting(6, 7), minimumMeetingRooms::Meeting(7, 8)}, 3},
				{{minimumMeetingRooms::Meeting(1,4), minimumMeetingRooms::Meeting(2,5), minimumMeetingRooms::Meeting(7, 9)}, 2},
				{{minimumMeetingRooms::Meeting(6,7), minimumMeetingRooms::Meeting(2,4), minimumMeetingRooms::Meeting(8, 12)}, 1},
				{{minimumMeetingRooms::Meeting(1,4), minimumMeetingRooms::Meeting(2,3), minimumMeetingRooms::Meeting(3, 6)}, 2},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = minimumMeetingRooms::findMinimumMeetingRooms(testcase);
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
		}

		TEST_METHOD(checkMaxCPULoad)
		{
			vector<tuple<vector<maxCPULoad::Job>, int>> testcases =
			{
				{{maxCPULoad::Job(1,4,3), maxCPULoad::Job(1,4,3)}, 6},
				{{maxCPULoad::Job(1,4,3), maxCPULoad::Job(2,5,4), maxCPULoad::Job(7,9,6)}, 7},
				{{maxCPULoad::Job(6,7,3), maxCPULoad::Job(2,4,11), maxCPULoad::Job(8,12,15)}, 15},
				{{maxCPULoad::Job(1,4,2), maxCPULoad::Job(2,4,1), maxCPULoad::Job(3,6,5)}, 8},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = maxCPULoad::findMaxCPULoad(testcase);
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
		}

		TEST_METHOD(checkEmployeeFreeTime)
		{
			vector<tuple<vector<vector<employeeFreeTime::Interval>>, vector<employeeFreeTime::Interval>>> testcases =
			{
				{{{employeeFreeTime::Interval(1,3), employeeFreeTime::Interval(5,6)}, {employeeFreeTime::Interval(2,3), employeeFreeTime::Interval(6,8)}},{employeeFreeTime::Interval(3,5)}},
				{{{employeeFreeTime::Interval(1,3), employeeFreeTime::Interval(9,12)}, {employeeFreeTime::Interval(4,6), employeeFreeTime::Interval(8,9)}},{employeeFreeTime::Interval(3,4), employeeFreeTime::Interval(6,8)}},
				{{{employeeFreeTime::Interval(1,3), employeeFreeTime::Interval(9,12)}, {employeeFreeTime::Interval(2,4)}, {employeeFreeTime::Interval(6,8)}},{employeeFreeTime::Interval(4,6), employeeFreeTime::Interval(8,9)} },
				{{{employeeFreeTime::Interval(1,3)}, {employeeFreeTime::Interval(2,4)}, {employeeFreeTime::Interval(3,5), employeeFreeTime::Interval(7,9)}},{employeeFreeTime::Interval(5,7)} },
				{{{employeeFreeTime::Interval(1,3), employeeFreeTime::Interval(5,6)}, {employeeFreeTime::Interval(6,9), employeeFreeTime::Interval(10,11)}},{employeeFreeTime::Interval(3,5), employeeFreeTime::Interval(9,10)}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				auto res = employeeFreeTime::findEmployeeFreeTime(testcase);
				Assert::IsTrue(res == get<1>(testcases[i]));
			}
		}
	};
}