#pragma once
#include <iostream>
using namespace std;

class Array_List
{
public:
	int* data = nullptr;
	int count = 0;
public:
	void AddNode(int _data); // 추가
	void InsertNode(int _index, int _data); // 값 삽입(순서 == _index)
	void InsertNode(int _index, int _count, int _data); // 값 삽입(순서 == _index, 갯수 == _count)
	void UpdateNode(int _index, int _data); // 데이터 변경 (순서 == _index)
	void DeleteNodeData(int _data); // 값 제거(값 == _data)
	void DeleteIndex(int _index); // 값 제거(순서 == _index)
	void ClearAllNode(); // 모든 값 삭제
	int GetNodeData(int _index); // 원하는 값의 정보 불러오기 (순서 == _index)
	int GetListSize(); // 현재 List크기
	bool IsEmpty(); // 현재 데이터가 비어 있는지 아닌지
	void PrintAll(); // 모든 node 출력
public:
	Array_List();
	~Array_List();
};

