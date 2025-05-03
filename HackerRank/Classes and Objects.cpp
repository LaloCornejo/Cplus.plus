#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long int
using namespace std;

class Student{
    private:
    int scores[5];

    public:
    void input();
    int calculateTotalScore();
};

void Student::input(){
    for(int i = 0 ; i<5 ; i++ ){
        cin>>scores[i];
    }
}

int Student::calculateTotalScore(){
    int sum = 0;
    for(int i = 0 ; i<5 ; i++ ){
        sum += scores[i];
    }
    return sum;
}

int main() {
    int n, kristenScore, count = 0;
    cin >> n;
    Student students[n];
    students[0].input();
    kristenScore = students[0].calculateTotalScore();

    for(int i = 1; i < n; i++ ){
        students[i].input();
        if( kristenScore < students[i].calculateTotalScore() ){
            count++;
        }
    }

    cout << count;
    return 0;
}

