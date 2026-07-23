#include "Array_List.h"

/*
용어 구분
자료구조	값 하나를 담는 단위 이름
Array / ArrayList	원소(element)
Linked List	노드(node)
Tree	노드(node)
*/

void Array_List::AddNode(int _data) // 동작 방식이 스택의 push와 비슷하다.ArrayList 자체가 스택 메모리를 쓰지 않느다. 
{
	count++; //array안에 값을 넣기 위해 갯수 증가
	int* newData = new int[count]; // 갯수 증가한 array를 newData 포인터(주소값을 저장하는 포인터 변수)
	newData[count - 1] = _data; // 마지막에 넣고자 하는 값을 넣음.
	if (data == nullptr) {
		data = newData; // for문으로 써서 값을 각 원소(element)에 넣어주지 않아도 되어서 바로 data에 넣어준다.
	}
	else {
		for (int i = 0; i < count - 1; i++) {
			newData[i] = data[i]; // 원래 있던 data안에 있던 값들은 newData에 각각 대응해서 넣어준다.
		}
		delete[] data; // 힙에 할당했던 메모리 공간 자체를 시스템에 반환, data가 가리키고 있는 메모리 블록 전체를 이제 안 쓸 거니 가져가라는 뜻
		data = newData; // data가 새 메모리를 가리키도록 변경.
	}
}

void Array_List::InsertNode(int _index, int _data)
{
	count++;
	int* newData = new int[count];
	newData[_index] = _data;
	for (int i = 0; i < count; i++) {
		if (i < _index) {
			newData[i] = data[i];
		}
		else if(i > _index){
			newData[i + 1] = data[i];
		}
		else {
			i--;
		}
	}
	delete[] data;
	data = newData;
}

void Array_List::InsertNode(int _index, int _count, int _data)
{
}

void Array_List::UpdateNode(int _index, int _data)
{
}

void Array_List::DeleteNodeData(int _data)
{
}

void Array_List::DeleteIndex(int _index)
{
}

void Array_List::ClearAllNode()
{
}

int Array_List::GetNodeData(int _index)
{
	return 0;
}

int Array_List::GetListSize()
{
	return 0;
}

bool Array_List::IsEmpty()
{
	return false;
}

void Array_List::PrintAll()
{
}

Array_List::Array_List()
{
}

Array_List::~Array_List()
{
}
