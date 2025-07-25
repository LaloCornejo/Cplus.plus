#include<iostream>

#define ll long long

using namespace std;

class Box {
    private:
        int length, breadth, height;
    public:
        Box() { 
            length = 0;
            breadth = 0;
            height = 0;
        }
        Box(int l, int b, int h) {
            length = l;
            breadth = b;
            height = h;
        }
        Box(const Box &B) {
            length = B.length;
            breadth = B.breadth;
            height = B.height;
        }
        int getLength() { return length; }
        int getBreadth() { return breadth; }
        int getHeight() { return height; }
        long long CalculateVolume() { return (ll)length * breadth * height; }

        bool operator<(Box& B) {
            if(length < B.length) {
                return true;
            } else if(length == B.length) {
                if(breadth < B.breadth) {
                    return true;
                } else if(breadth == B.breadth) {
                    if(height < B.height) {
                        return true;
                    }
                }
            }
            return false;
        }

        friend ostream& operator<<(ostream& out, Box& B) {
            out << B.length << " " << B.breadth << " " << B.height;
            return out;
        }
};

int main(){
    
}