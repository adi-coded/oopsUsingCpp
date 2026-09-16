#include <iostream>
using namespace std;

class Rect{
int length,breadth;
public:
Rect(){
    cout<< "deafult constructor called"<<endl;
    length=0;
    breadth=0;
}
Rect(int x, int y){
    cout<< "parameterized constructor called" <<endl;
length=x;
breadth=y;
}
void setLength(int l){
    length=l;
}
void setBreadth(int b){
    breadth=b;
}
float area(){
    return length*breadth;
}
float peri(){
    return 2*(length+breadth);
}
void show(){
    cout<<"length: " << length <<", breadth: " << breadth <<endl;
    cout<<"Area: " << area() << ", perimeter: " << peri() <<endl;
}
};
int main(){
Rect r1;
r1.show();
Rect r2(2,4);
r2.show();

return 0;
}
