#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "assignment5_1.cpp"

using namespace std;

struct HeapElement {

    double value;
    HeapElement *parent;
    HeapElement *child1;
    HeapElement *child2;

    HeapElement()
    {

        value = 0.0;
        parent = NULL;
        child1 = NULL;
        child2 = NULL;
    }

};

class Heap {

private:
    HeapElement *head;

public:
    int counter;

    Heap()
    {
        head = NULL;
        counter = 0;
    }

    ~Heap()
    {
        releaseMemory(head);
    }

    void insert(double d) // O(log n)
    {
        counter++;
        if (head == NULL)
        {
            head = new HeapElement;
            head->value = d;
            return;
        }

        HeapElement *parent = head;
        HeapElement *iter = NULL;
        HeapElement *temp;
        srand(time(NULL));

        while (true)
        {
            if (rand() % 2 == 0)
            {
                temp = parent->child1;

                if (temp == NULL)
                {
                    temp = new HeapElement;
                    temp->value = d;
                    parent->child1 = temp;
                    temp->parent = parent;
                    break;
                }
                else
                {
                    parent = temp;
                }
            }
            else
            {
                temp = parent->child2;

                if (temp == NULL)
                {
                    temp = new HeapElement;
                    temp->value = d;
                    parent->child2 = temp;
                    temp->parent = parent;
                    break;
                }
                else
                {
                    parent = temp;
                }
            }
        }

        reorderHeapUpward(temp);
    }

    void printHeap(HeapElement *element) // O(n)
    {
        if (element != NULL)
        {
            cout << element->value << endl;
        }

        if (element->child1 != NULL)
        {
            printHeap(element->child1);
        }

        if (element->child2 != NULL)
        {
            printHeap(element->child2);
        }
    }

    void reorderHeapUpward(HeapElement *element) // O(log n)
    {
        if (element->parent == NULL)
        {
            return;
        }

        if (element->value < element->parent->value)
        {
            double temp = element->parent->value;
            element->parent->value = element->value;
            element->value = temp;
            reorderHeapUpward(element->parent);
        }

        return;
    }

    double top()
    {
        return this->head->value;
    }

    void pop_top() // O(log n)
    {
        counter--;
        if (head->child1 == NULL && head->child2 == NULL)
        {
            head = NULL;
            return;
        }

        HeapElement *leaf = head;
        srand(time(NULL));

        while (true)
        {
            if (rand() % 2 == 0)
            {
                if (leaf->child1 != NULL)
                {
                    leaf = leaf->child1;
                }
            }
            else
            {
                if (leaf->child2 != NULL)
                {
                    leaf = leaf->child2;
                }
            }

            if (leaf->child1 == NULL && leaf->child2 == NULL)
            {
                head->value = leaf->value;
                break;
            }
        }

        reorderHeapDownward(head);
    }

    void reorderHeapDownward(HeapElement *element) // O(log n)
    {
        if (element->child1 != NULL && element->child2 != NULL)
        {
            if (element->child1->value > element->child2->value)
            {
                double temp = element->value;
                element->value = element->child2->value;
                element->child2->value = temp;
                reorderHeapDownward(element->child2);
            }
        }

        if (element->child1 == NULL && element->child2 != NULL)
        {
            double temp = element->value;
            element->value = element->child2->value;
            element->child2->value = temp;
            reorderHeapDownward(element->child2);
        }

        if (element->child1 != NULL && element->child2 == NULL)
        {
            double temp = element->value;
            element->value = element->child1->value;
            element->child1->value = temp;
            reorderHeapDownward(element->child1);
        }

        if (element->child1 == NULL && element->child2 == NULL)
        {
            return;
        }
    }

    void releaseMemory(HeapElement *element) // O(1) to O(n)
    {
        if (element == NULL)
        {
            return;
        }

        if (element->child1 != NULL)
        {
            releaseMemory(element->child1);
        }

        if (element->child2 != NULL)
        {
            releaseMemory(element->child2);
        }

        delete element;
    }

    HeapElement* getHead()
    {
        return head;
    }
};



class Heap2 {

private:
    vector<double> heap;

public:
    Heap2()
    {
    }

    ~Heap2()
    {
    }

    void insert(double element)
    {
        heap.push_back(element);
        heapifyUp(heap.size() - 1);
    }

    double top()
    {
        double min = heap.front();
        return min;

    }

    void pop_top(){

        int length = heap.size();

        if(length == 0){
            return;
        }

        heap[0] = heap[length - 1];
        heap.pop_back();

        heapifyDown(0);
    }

    void print()
    {
        vector<double>::iterator pos = heap.begin();
        cout << "Heap = ";

        while ( pos != heap.end() )
        {
            cout << *pos << " ";
            ++pos;
        }
        cout << endl;
    }

    void heapifyUp(int index)
    {
        if(index == 0)
        {
            return;
        }

        int parentIndex = (index - 1)/2;

        if(heap[parentIndex] > heap[index])
        {
            double tmp = heap[parentIndex];
            heap[parentIndex] = heap[index];
            heap[index] = tmp;
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index)
    {
        int length = heap.size();

        int leftChildIndex = 2*index + 1;
        int rightChildIndex = 2*index  + 2;

        if(leftChildIndex >= length)
        {
            return;
        }

        int minIndex = index;

        if(heap[index] > heap[leftChildIndex])
        {
            minIndex = leftChildIndex;
        }

        if((rightChildIndex < length) && (heap[minIndex] > heap[rightChildIndex]))
        {
            minIndex = rightChildIndex;
        }

        if(minIndex != index)
        {
            double temp = heap[index];
            heap[index] = heap[minIndex];
            heap[minIndex] = temp;
            heapifyDown(minIndex);
        }
    }
};


int main()
{
    cout<<endl<<endl<<"Part 2"<<endl;

    Heap heap;
    DynamicDoubleArray arr;

    heap.insert(29);
    heap.insert(49);
    heap.insert(52);
    heap.insert(26);
    heap.insert(29);
    heap.insert(89);
    heap.insert(11);
    heap.insert(91);
    heap.insert(65);
    heap.insert(68);
    heap.insert(91);
    heap.insert(44);
    heap.insert(19);
    heap.insert(74);
    heap.insert(51);
    heap.insert(77);
    heap.insert(93);
    heap.insert(90);
    heap.insert(56);
    heap.insert(28);

    while (heap.counter != 0)
    {
        double num = heap.top();
        arr.push_back(num);
        heap.pop_top();
    }

    arr.printArray();

    cout<<endl<<endl<<"Part 2"<<endl;

    Heap2 heap2;

    heap2.insert(29);
    heap2.insert(49);
    heap2.insert(52);
    heap2.insert(26);
    heap2.insert(29);
    heap2.insert(89);
    heap2.insert(11);
    heap2.insert(91);
    heap2.insert(65);
    heap2.insert(68);
    heap2.insert(91);
    heap2.insert(44);
    heap2.insert(19);
    heap2.insert(74);
    heap2.insert(51);
    heap2.insert(77);
    heap2.insert(93);
    heap2.insert(90);
    heap2.insert(56);
    heap2.insert(28);

    heap2.print();
    heap2.pop_top();
    heap2.print();
    heap2.pop_top();
    heap2.print();

    return 0;
}