#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n' << endl;
}

void printThree(vector<int> A, vector<int> B, vector<int> C){
    cout << "Stack1: ";
    printArray(A);
    cout << "Stack2: ";
    printArray(B);
    cout << "Stack3: ";
    printArray(C);
    cout << "\n" << endl;
}

void hanoi(int n){
    vector<int> A;
    vector<int> B;
    vector<int> C;

    for(int i = n; i >= 1; i--){
        A.push_back(i);
    }

    vector<int> key = A;

    if(n % 2 == 0){
        printThree(A,B,C);
        while(C != key){
            if(B.size() == 0 || B.back() > A.back() && A.back() != 0){
                B.push_back(A.back());
                A.pop_back();
                printThree(A, B, C);
            }else if(A.size() == 0 || A.back() > B.back() && B.back() != 0){
                A.push_back(B.back());
                B.pop_back();
                printThree(A, B, C);
            }

            if(C.size() == 0 || C.back() > A.back() && A.back() != 0){
                C.push_back(A.back());
                A.pop_back();
                printThree(A, B, C);
            }else if(A.size() == 0 || A.back() > C.back() && C.back() != 0){
                A.push_back(C.back());
                C.pop_back();
                printThree(A, B, C);
            }

            if(C.size() == 0 || C.back() > B.back() && B.back() != 0){
                C.push_back(B.back());
                B.pop_back();
                printThree(A, B, C);
            }else if(B.size() == 0 || B.back() > C.back() && C.back() != 0){
                B.push_back(C.back());
                C.pop_back();
                printThree(A, B, C);
            }
        }
    } else {
        printThree(A,B,C);
        while(C != key){
            if(C.size() == 0 || C.back() > A.back() && A.back() != 0){
                C.push_back(A.back());
                A.pop_back();
                printThree(A, B, C);
            }else if(A.size() == 0 || A.back() > C.back() && C.back() != 0){
                A.push_back(C.back());
                C.pop_back();
                printThree(A, B, C);
            }

            if(B.size() == 0 || B.back() > A.back() && A.back() != 0){
                B.push_back(A.back());
                A.pop_back();
                printThree(A, B, C);
            }else if(A.size() == 0 || A.back() > B.back() && B.back() != 0){
                A.push_back(B.back());
                B.pop_back();
                printThree(A, B, C);
            }

            if(C.size() == 0 || C.back() > B.back() && B.back() != 0){
                C.push_back(B.back());
                B.pop_back();
                printThree(A, B, C);
            }else if(B.size() == 0 || B.back() > C.back() && C.back() != 0){
                B.push_back(C.back());
                C.pop_back();
                printThree(A, B, C);
            }
        }
    }
}
// AB AC BC
int main(){

    hanoi(4);

    return 0;
}
