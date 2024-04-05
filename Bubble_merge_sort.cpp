#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;
//template <typename T>
#define T float


void printVector(const vector<T>& vec) {
    
    cout << "Vetor: " << endl;
    for (T i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

void bubbleSort(vector<T>& vec) {

    int op = 0;
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < vec.size() - 1; ++i) {
            if (vec[i] > vec[i + 1]) {
                swap(vec[i], vec[i + 1]);
                swapped = true;
                op++;
            }
        }
    } while (swapped);


    cout << "operações: " << op << endl;
    printVector(vec);
}

void merge(vector<T> &vec, vector<T> &v1, vector<T> &v2) {
    auto siz1 = v1.size();
    auto siz2 = v2.size();
    size_t p1 = 0;
    size_t p2 = 0;

    while (p1 < siz1 && p2 < siz2) {
        if (v1.at(p1) < v2.at(p2))
        vec.push_back(v1.at(p1++));
        else
        vec.push_back(v2.at(p2++));
    }

    while (p1 < siz1) vec.push_back(v1.at(p1++));
    while (p2 < siz2) vec.push_back(v2.at(p2++));
}

int mergeSort(vector<T> &vec, int op) {
    if (vec.size() <= 1) return op;

    auto iter = vec.begin() + vec.size() / 2;
    vector<T> v1(vec.begin(), iter);
    vector<T> v2(iter, vec.end());

    op = mergeSort(v1, op);
    op = mergeSort(v2, op);

    vec.clear();
    merge(vec, v1, v2);
    op++;

    return op;
}



int main(){

    int total;
    float in;
    cout << "escreva o tamanho do vetor, <0 para vetor predefinido: ";
    cin >> total;
    vector<T> vec;

    if(total >0){
        cout << "insira os valores:" << endl;
        for(int i=0; i< total; i++){
            cin >> in;
            vec.push_back(in);
        }
    }else{
        vec = {42.921, 46.665, 93.524, 81.73, 95.372, 5.067, 87.333, 35.016, 59.74, 78.412, 99.418, 39.127, 61.749, 74.293, 87.542, 29.768, 98.536, 60.539, 48.96, 97.558, 70.616, 47.793, 34.232, 69.123, 96.247, 75.042, 31.16, 61.697, 47.073, 2.956};
    }


    vector<T> vec1 = vec;
    vector<T> vec2 = vec;

    cout << "Bubble sort:" << endl;
    bubbleSort(vec1);
    
    cout << "Merge sort:" << endl;
    cout << "operações: " << mergeSort(vec2, 0) << endl;
    printVector(vec2);

    return 0;
}
