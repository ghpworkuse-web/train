#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "queue.h"
using namespace std;
//const char* a = "hhhhhh";
//void generate_rolling_numbers() {//15
//    int numbers[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
//
//    while (1) {
//        for (int start = 0; start < 16; start++) {
//            for (int i = 0; i < 5; i++) {
//                int index = (start + i) % 16;
//                //LCD_WriteData(numbers[index]);
//                cout << numbers[index] << " ";
//            }
//            printf("\n");
//        }
//    }
//}
//
//int main()
//{
////    generate_rolling_numbers();
//    return 0;
//}

///直接搞成一个循环队列,此时类中成员变量要加上前驱指针和后驱指针
///判定规则，front追赶end，，为空时两者相等，end位置的前一个元素是最后一个元素
#define Initvalue 4
typedef struct Queue
{
	int* c;
	int size;
	int front;
	int end;
	int capacity;
}Queue;
void initqueue(Queue *q)
{
	q->front = 0;
	q->end = 0;
	q->size = 0;
	q->c = (int*)malloc(Initvalue + 1);//这里注意开辟容量和实际显示容量的不同，capaccity位置也可以放元素
	q->capacity = Initvalue;
}
bool empty(Queue* q)
{
	if (q->front == q->end)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int size(Queue* q)
{
	return q->size;
}

bool front(Queue* q, int& key)
{
	if (empty(q))
	{
		return false;
	}
	else key = q->c[q->front];
	return true;
}

bool back(Queue* q, int& key)
{
	if (empty(q))
	{
		return false;
	}
	else key = q->c[q->end - 1];
	return true;
}
bool full(Queue* q)
{
	if (q->end == q->capacity && q->front == 0)
	{
		return true;
	}
	if (q->end < q->front && q->end + 1 == q->front)
	{
		return true;
	}
	return false;
}

bool pop(Queue* q, int& key)
{
	//判断是否为空
	if (empty(q))
	{
		return false;
	}
	else
	{
		if (q->end > 0)
		{
			key = q->c[q->end];
			q->end--;
		}
		else
		{
			key = q->c[q->end];
			q->end = q->capacity;
		}
		return true;
	}
}


void reserve(Queue* q)
{
	//重新开一片空间，将元素全部遍历进去
	int* a = (int*)malloc(q->capacity * 2 + 1);
	int k = 0;
	while (!empty(q))
	{
		int key = 0;
		 pop(q,key);//替换
		 a[k] = key;
		 k++;
	}
	free(q->c);
	q->c = a;//这里可以这样搞不，等会儿试一下
	q->capacity *= 2;
	q->front = 0;
	q->end = q->size;
}
int push(Queue* q, int key)
{
	if (full(q))
	{
		reserve(q);
	}
	else
	{
		if (q->end == q->capacity)
		{
			q->c[q->capacity] = key;//放在最后一个位置，然后重置end
			q->end = 0;
		}
		else
		{
			q->c[q->end] = key;
			q->end++;
		}
	}
	return key;
}
void print(Queue* q)
{
	for (int i = 0; i < q->capacity; i++)
	{
		cout << q->c[i] << " ";
	}
	cout << endl;
}
int main()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	initqueue(q);
	

	return 0;
}