#include "pch.h"
#include "CppUnitTest.h"
#include "..\breathFirstSearch\levelOrderTraversal.h"
#include "..\breathFirstSearch\reverseOrderTraversal.h"
#include "..\breathFirstSearch\zigzagTraversal.h"
#include "..\breathFirstSearch\connectLevelOrderSiblings.h"
#include "..\breathFirstSearch\connectAllLevelOrderSiblings.h"
#include "..\breathFirstSearch\rightViewBinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace testsTreeBreathFirstSearch
{
    TEST_CLASS(treeBreathFirstSearchTests)
    {
		TEST_METHOD(checkLevelOrderTraversal)
		{
			vector<tuple<vector<int>, vector<vector<int>>>> testcases =
			{
				{{1, 2,4,INT32_MIN,INT32_MIN,5,INT32_MIN,INT32_MIN, 3, 6, INT32_MIN, INT32_MIN, 7,INT32_MIN,INT32_MIN} , {{1}, {2,3}, {4,5,6,7}}},
				{{12, 7,9,INT32_MIN,INT32_MIN,INT32_MIN,1,10, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN} , {{12}, {7,1}, {9,10,5}}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				int index = 0;
				auto input = levelOrderTraversal::vec2TreeNode(testcase, index);
				auto output = levelOrderTraversal::traverse(input);
				Assert::IsTrue(output == get<1>(testcases[i]));
			}
		}

		TEST_METHOD(checkReverseLevelOrderTraversal)
		{
			vector<tuple<vector<int>, vector<vector<int>>>> testcases =
			{
				{{1, 2,4,INT32_MIN,INT32_MIN,5,INT32_MIN,INT32_MIN, 3, 6, INT32_MIN, INT32_MIN, 7,INT32_MIN,INT32_MIN} , {{4,5,6,7}, {2,3} , {1} }},
				{{12, 7,9,INT32_MIN,INT32_MIN,INT32_MIN,1,10, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN} , {{9,10,5}, {7,1} , {12}}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				int index = 0;
				auto input = reverseLevelOrderTraversal::vec2TreeNode(testcase, index);
				auto output = reverseLevelOrderTraversal::traverse(input);
				Assert::IsTrue(output == get<1>(testcases[i]));
			}
		}

		TEST_METHOD(checkZigzagLevelOrderTraversal)
		{
			vector<tuple<vector<int>, vector<vector<int>>>> testcases =
			{
				{{1, 2,4,INT32_MIN,INT32_MIN,5,INT32_MIN,INT32_MIN, 3, 6, INT32_MIN, INT32_MIN, 7,INT32_MIN,INT32_MIN} , {{1}, {3,2}, {4,5,6,7}}},
				{{12, 7,9,INT32_MIN,INT32_MIN,INT32_MIN,1,10, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN} , {{12}, {1,7}, {9,10,5}}},
				{{12, 7,9,INT32_MIN,INT32_MIN,INT32_MIN,1,10,20, INT32_MIN, INT32_MIN,17, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN} , {{12}, {1,7}, {9,10,5}, {17, 20}}},
				{{12, 7,9,INT32_MIN,INT32_MIN,INT32_MIN,1,10,20, INT32_MIN, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN} , {{12}, {1,7}, {9,10,5}, {20}}},
				{{12, INT32_MIN,1,10,20, INT32_MIN, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN} , {{12}, {1}, {10,5}, {20}}},
				{{12, 10, INT32_MIN, INT32_MIN,5,1,20, INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN} , {{12}, {5,10}, {1}, {20}}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				int index = 0;
				auto input = zigzagOrderTraversal::vec2TreeNode(testcase, index);
				auto output = zigzagOrderTraversal::traverse(input);
				Assert::IsTrue(output == get<1>(testcases[i]));
			}
		}

		TEST_METHOD(checkConnectAllLevelOrderSiblings)
		{
			vector<int> input1 = { 1, 2,4,INT32_MIN,INT32_MIN,5,INT32_MIN,INT32_MIN, 3, 6, INT32_MIN, INT32_MIN, 7,INT32_MIN,INT32_MIN };
			int index1 = 0;
			auto tree1 = connectAllLevelOrderSiblings::vec2TreeNode(input1, index1);
			auto res1 = connectAllLevelOrderSiblings::connect(tree1);
			index1 = 0;
			auto expect1 = connectAllLevelOrderSiblings::vec2TreeNode(input1, index1);
			expect1->left->left->next = expect1->left->right;
			expect1->left->right->next = expect1->right->left;
			expect1->right->left->next = expect1->right->right;
			expect1->next = expect1->left;
			expect1->left->next = expect1->right;
			expect1->right->next = expect1->left->left;
			Assert::IsTrue(connectAllLevelOrderSiblings::compareTrees(res1, expect1));

			vector<int> input2 = { 12, 7,9,INT32_MIN,INT32_MIN,INT32_MIN,1,10, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN };
			int index2 = 0;
			auto tree2 = connectAllLevelOrderSiblings::vec2TreeNode(input2, index2);
			auto res2 = connectAllLevelOrderSiblings::connect(tree2);
			index2 = 0;
			auto expect2 = connectAllLevelOrderSiblings::vec2TreeNode(input2, index2);
			expect2->next = expect2->left;
			expect2->left->next = expect2->right;
			expect2->right->next = expect2->left->left;
			expect2->left->left->next = expect2->right->left;
			expect2->right->left->next = expect2->right->right;
			expect2->right->right->next = nullptr;
			Assert::IsTrue(connectAllLevelOrderSiblings::compareTrees(res2, expect2));

			vector<int> input3 = { 12, INT32_MIN,1,10,20, INT32_MIN, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN };
			int index3 = 0;
			auto tree3 = connectAllLevelOrderSiblings::vec2TreeNode(input3, index3);
			auto res3 = connectAllLevelOrderSiblings::connect(tree3);
			index3 = 0;
			auto expect3 = connectAllLevelOrderSiblings::vec2TreeNode(input3, index3);
			expect3->right->left->next = expect3->right->right;
			expect3->next = expect3->right;
			expect3->right->next = expect3->right->left;
			expect3->right->right->next = expect3->right->left->left;
			Assert::IsTrue(connectAllLevelOrderSiblings::compareTrees(res3, expect3));

			vector<int> input4 = { 6, 3, 1, INT32_MIN,9, INT32_MIN, INT32_MIN, 4, INT32_MIN, INT32_MIN};
			int index4 = 0;
			auto tree4 = connectAllLevelOrderSiblings::vec2TreeNode(input4, index4);
			auto res4 = connectAllLevelOrderSiblings::connect(tree4);
			index4 = 0;
			auto expect4 = connectAllLevelOrderSiblings::vec2TreeNode(input4, index4);
			expect4->next = expect4->left;
			expect4->left->next = expect4->left->left;
			expect4->left->left->next = expect4->left->right;
			expect4->left->right->next = expect4->left->left->right;
			Assert::IsTrue(connectAllLevelOrderSiblings::compareTrees(res4, expect4));
		}

		TEST_METHOD(checkConnectLevelOrderSiblings)
		{
			vector<int> input1 = { 1, 2,4,INT32_MIN,INT32_MIN,5,INT32_MIN,INT32_MIN, 3, 6, INT32_MIN, INT32_MIN, 7,INT32_MIN,INT32_MIN };
			int index1 = 0;
			auto tree1 = connectLevelOrderSiblings::vec2TreeNode(input1, index1);
			auto res1 = connectLevelOrderSiblings::connect(tree1);
			index1 = 0;
			auto expect1 = connectLevelOrderSiblings::vec2TreeNode(input1, index1);
			expect1->left->left->next = expect1->left->right;
			expect1->left->right->next = expect1->right->left;
			expect1->right->left->next = expect1->right->right;
			expect1->next = nullptr;
			expect1->left->next = expect1->right;
			expect1->right->next = nullptr;
			Assert::IsTrue(connectLevelOrderSiblings::compareTrees(res1, expect1));

			vector<int> input2 = { 12, 7,9,INT32_MIN,INT32_MIN,INT32_MIN,1,10, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN };
			int index2 = 0;
			auto tree2 = connectLevelOrderSiblings::vec2TreeNode(input2, index2);
			auto res2 = connectLevelOrderSiblings::connect(tree2);
			index2 = 0;
			auto expect2 = connectLevelOrderSiblings::vec2TreeNode(input2, index2);
			expect2->next = nullptr;
			expect2->left->next = expect2->right;
			expect2->right->next = nullptr;
			expect2->left->left->next = expect2->right->left;
			expect2->right->left->next = expect2->right->right;
			expect2->right->right->next = nullptr;
			Assert::IsTrue(connectLevelOrderSiblings::compareTrees(res2, expect2));

			vector<int> input3 = { 12, INT32_MIN,1,10,20, INT32_MIN, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN };
			int index3 = 0;
			auto tree3 = connectLevelOrderSiblings::vec2TreeNode(input3, index3);
			auto res3 = connectLevelOrderSiblings::connect(tree3);
			index3 = 0;
			auto expect3 = connectLevelOrderSiblings::vec2TreeNode(input3, index3);
			expect3->right->left->next = expect3->right->right;
			Assert::IsTrue(connectLevelOrderSiblings::compareTrees(res3, expect3));
		}

		TEST_METHOD(checkRightViewBinaryTree)
		{
			vector<tuple<vector<int>, vector<int>>> testcases =
			{
				{{1, 2,4,INT32_MIN,INT32_MIN,5,INT32_MIN,INT32_MIN, 3, 6, INT32_MIN, INT32_MIN, 7,INT32_MIN,INT32_MIN} , {1, 3, 7}},
				{{12, 7,9,INT32_MIN,INT32_MIN,INT32_MIN,1,10, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN} , {12,1,5}},
				{{12, 7,9,INT32_MIN,INT32_MIN,INT32_MIN,1,10,20, INT32_MIN, INT32_MIN,17, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN} , {12,1,5,17}},
				{{12, 7,9,INT32_MIN,INT32_MIN,INT32_MIN,1,10,20, INT32_MIN, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN} , {12,1,5,20}},
				{{12, INT32_MIN,1,10,20, INT32_MIN, INT32_MIN, INT32_MIN, 5,INT32_MIN,INT32_MIN} , {12, 1, 5, 20}},
				{{12, 10, INT32_MIN, INT32_MIN,5,1,20, INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN} , {12, 5, 1, 20}},
			};

			for (int i = 0; i < testcases.size(); i++)
			{
				auto testcase = get<0>(testcases[i]);
				int index = 0;
				auto input = rightViewBinaryTree::vec2TreeNode(testcase, index);
				auto output = rightViewBinaryTree::traverse(input);
				Assert::IsTrue(output == get<1>(testcases[i]));
			}
		}
	};
}