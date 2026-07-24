#include "Array_List.h"

int main() {
	Array_List array;
	array.AddNode(1);
	array.AddNode(2);
	array.AddNode(4);
	array.InsertNode(2, 3);
	array.InsertNode(4, 2, 5);
	array.DeleteNodeData(4);
	array.DeleteIndex(1);
	array.PrintAll();
	return 0;
}