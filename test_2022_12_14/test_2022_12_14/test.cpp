//#include <iostream>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		if (!head || !head->next) {
//			return head;
//		}
//		ListNode* newHead = reverseList(head->next);
//		head->next->next = head;
//		head->next = nullptr;
//		return newHead;
//	}
//};
//
//int main()
//{
//	ListNode n1(1);
//	ListNode n2(2);
//	ListNode n3(3);
//	ListNode n4(4);
//	n1.next = &n2;
//	n2.next = &n3;
//	n3.next = &n4;
//	n4.next = nullptr;
//	ListNode* ret = Solution().reverseList(&n1);
//	while (ret)
//	{
//		cout << ret->val << endl;
//		ret = ret->next;
//	}
//	return 0;
//}

#include <iostream>
using namespace std;
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
//class Solution {
//public:
//	Node* copyRandomList(Node* head) {
//		Node* cur = head;
//		while (cur)
//		{
//			Node* copyNode = new Node(cur->val);
//			copyNode->next = cur->next;
//			cur->next = copyNode;
//			cur = cur->next->next;
//		}
//		cur = head;
//		while (cur)
//		{
//			Node* copyNode = cur->next;
//			if (cur->random == nullptr)
//				copyNode->random = nullptr;
//			else
//				copyNode->random = cur->random->next;
//			cur = cur->next->next;
//		}
//		cur = head;
//		Node* copyHead = head->next;
//		while (cur)
//		{
//			Node* nextNode = cur->next;
//			cur->next = nextNode->next;
//			cur = cur->next;
//			if (cur)
//				nextNode->next = cur->next;
//			else
//				nextNode->next = nullptr;
//		}
//		return copyHead;
//	}
//};
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return nullptr;
		if (cacheNode.find(head) == cacheNode.end())
		{
			Node* copyNode = new Node(head->val);
			cacheNode[head] = copyNode;
			copyNode->next = copyRandomList(head->next);
			copyNode->random = copyRandomList(head->random);
		}
		return cacheNode[head];
	}
private:
	unordered_map<Node*, Node*> cacheNode;
};
int main()
{
	Node* n1 = new Node(7);
	Node* n2 = new Node(13);
	Node* n3 = new Node(11);
	Node* n4 = new Node(10);
	Node* n5 = new Node(1);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = nullptr;
	n1->random = nullptr;
	n2->random = n1;
	n3->random = n5;
	n4->random = n3;
	n5->random = n1;
	Node* ret = Solution().copyRandomList(n1);
	return 0;
}