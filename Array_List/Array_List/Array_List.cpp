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
	if (IsEmpty() || _index < 0 || GetListSize() < _index) return;
	
	int* newData = new int[count+1];

	for (int i = 0; i < _index; i++) {
		newData[i] = data[i];
	}

	newData[_index] = _data;

	for (int i = _index; i < count; i++) {
			newData[i+1] = data[i];
	}
	delete[] data;
	data = newData;
	count++;
}

void Array_List::InsertNode(int _index, int _count, int _data)
{
	if (IsEmpty() || _index < 0 || GetListSize() < _index) return;
	
	for (int i = 0; i < _count; i++) {
		InsertNode(_index, _data);
	}

}

void Array_List::UpdateNode(int _index, int _data)
{
	if (IsEmpty() || _index < 0 || _index > GetListSize()) return;
	data[_index] = _data;
}

void Array_List::DeleteNodeData(int _data)
{// 배열을 앞에서부터 하나씩 훑으면서 data[i]가 _data와 같은지 확인하고
//처음으로 같은 값을 발견한 그 순간의 인덱스 i를 기억
//그 i를 자기고 DeleteIndex(i)를 호출해서 그 위치의 원소를 삭제하고
//break로 루프를 멈추니까, 뒤에 같은 값이 더 있어도 더이상 지우지 않음.

	for (int i = 0; i < count; i++) {
		if (data[i] == _data) {
			DeleteIndex(i);
			break; // 제일 처음 만나는 데이터 하나만 지우고 braek;
		}
	}
}

void Array_List::DeleteIndex(int _index)
{
	if (IsEmpty() || _index < 0 || _index >= GetListSize()) return;
	int* newData = new int[count - 1];
	for (int i = 0; i < _index; i++) {
		newData[i] = data[i];
	}
	for (int i = _index; i < count-1; i++) {
		newData[i] = data[i + 1];
	}
	delete[] data;
	data = newData;
	count--;
}

void Array_List::ClearAllNode()
{
	if (data == nullptr) {
		return;
	}
	else {
		delete[] data;
		data = nullptr;
		count = 0;
	}
}

int Array_List::GetNodeData(int _index)
{
	return data[_index];
}

int Array_List::GetListSize()
{
	return count;
}

bool Array_List::IsEmpty()
{
	return count == 0;
}

void Array_List::PrintAll()
{
	if (IsEmpty()) {
		cout<< "data -> null" << endl;
		return;
	}
	cout << "data ->";
	
	for (int i = 0; i < count; i++) {
		cout << "[" << data[i] << "]" <<"->";
	}
	cout << " null";
	cout << endl;
}

Array_List::Array_List()
{
}

Array_List::~Array_List()
{
	ClearAllNode();
}
