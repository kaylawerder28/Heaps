#include <iostream>

using namespace std;



class Heap {

public:

	int*A;                                             // the array where the heap was made

	int last = -1;                                     // a counter

	Heap() {}

	Heap(int n) { A = new int[n]; }                    // creating the array and the size then setting it in the pointer

	int getParentIndex(int childIndex) {               // this is how we get the index of the parents node

		if (childIndex % 2 == 0) {                     // this is if the child is on the le

			return childIndex / 2 - 1;                 // to find the parent index the formula is CHILD -1 /P

		}

		else                                           // this is if the child is on the right

			return childIndex / 2;

	}



	void insert(int x) {                               // this is if we want to insert a new number

		last++;                                        // makes the array bigger

		A[last] = x;                                   // sets the last to the new number

		Heapify(last);                                 // sets it in order

	}

	void Heapify(int childIndex) {                     // this sets it heap in the proper order

		int parentIndex = getParentIndex(childIndex);  // finds the parent index

		while (parentIndex >= 0) {                     // checks if its in the array

			if (A[childIndex] > A[parentIndex]) {      // checks if the child is bigger then the parent if so

				int temp = A[childIndex];              // sets the child to a temp and continues to swap

				A[childIndex] = A[parentIndex];

				A[parentIndex] = temp;

			}

			childIndex = parentIndex;

			parentIndex = getParentIndex(childIndex);



		}

	}

	int search(int x) {                                // looks for a number

		for (int i = 0; i <= last; i++) {              // checks all the numbers

			if (A[i] == x)return i;                    // when number is found then returns that index

		}

		return -1;

	}



	void Delete(int x) {                               // this deletes the number that you want

		int index = search(x);                         // uses search to find it

		A[index] = A[last];                            // saves it to the last number so you can easily delete it

		// swap if you want to return the deleted value

		//int temp = A[index]; A[index] = A[last]; A[last] = temp;

		last--;                                        // deltes it

		HeapifyDown(index);                            // checks the order

	}

	void HeapifyDown(int parent) {                     //makes sure all the numbers under the ones that was delted is in order

		int largest = parent;                          // sets the parent to the largest

		int l = 2 * parent + 1;                        // this is how we find the left child

		int r = 2 * parent + 2;                        // finds the right child

		if (l <= last && A[l] > A[largest]) largest = l;  // this checks if the child is the last and if it is bigger then the parents, if so changes

		if (r <= last && A[r] > A[largest]) largest = r;

		if (largest != parent) {                          // this is then checks if the largest has changed then swaps the numbers so the largest is the new parent

			int temp = A[parent];

			A[parent] = A[largest];

			A[largest] = temp;

			parent = largest;

			HeapifyDown(parent);                         // calls again to keep fixing until completely ordered

		}

	}

	void HeapSort() {                                   // sorts the heap

		int* B = new int[last];                         // makes a new array to write over

		int size = last;

		for (int i = size; i >= 0; i--) {               // goes through the whole array

			B[i] = A[0];

			Delete(A[0]);

		}

		for (int i = 0; i <= size; i++) {

			A[i] = B[i];

		}

		last = size;



	}

	void print() {

		for (int i = 0; i <= last; i++)

			cout << A[i] << " ";

		cout << endl;

	}



};









int main() {

	Heap* heap = new Heap(20);

	heap->insert(10); heap->print();

	heap->insert(50); heap->print();

	heap->insert(20); heap->print();

	heap->insert(90); heap->print();

	heap->insert(40); heap->print();

	heap->insert(70); heap->print();

	heap->insert(60); heap->print();

	heap->insert(80); heap->print();

	heap->insert(20); heap->print();

	heap->insert(60); heap->print();

	heap->insert(100); heap->print();



	heap->HeapSort(); heap->print();





	//heap->Delete(90); heap->print();

	//heap->Delete(100); heap->print();



	getchar();

}