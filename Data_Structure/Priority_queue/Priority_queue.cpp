#include <iostream>
#include <typeinfo>
#include <vector>
#include <stdexcept>

template <typename T>
class priority_queue {
    public:
    void push(T const& elem){
        elems.push_back(elem);
        int index = elems.size() - 1;
        while(true) {
            int tmp = index - 1;
            tmp /= 2;
            if(elems[tmp] < elem) {
                T temp = elems[tmp];
                elems[tmp] = elems[index];
                elems[index] = temp;
                index == tmp; 
            } else break;
        }
    }
    void pop() {
        T tmp = elems.back();
        elems.back() = elems.front();
        elems.front() = tmp;
        elems.pop_back();
        int index = 0;
        int size = elems.size();
        while(index*2+2 <= size) {
            int kid_1 = index * 2 + 1, kid_2 = index * 2 + 2;
            int kid = kid_1 ? kid_2 : elems[kid_1] >= elems[kid_2];
            if(elems[index] < elems[kid]) {
                T temp = elems[kid];
                elems[kid] = elems[index];
                elems[index] = temp;
                index = kid; 
            } else break;
        }
    }
    T top() const {
        if(elems.empty()) throw std::out_of_range("fuck you");
        else return elems.front();
    }
    bool empty() const {
        return elems.empty();
    }
    private:
    std::vector<T> elems;
};

//drivers
int main() {
    priority_queue<int> pq;
    pq.push(0);
    pq.push(1);
    pq.push(2);
    pq.push(123);
    pq.pop();
    pq.pop();
    pq.top();
    std::cout << pq.top() << std::endl;
    return 0;
}

