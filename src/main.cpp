#include <iostream>


using namespace std;

int main() {
    TEST x;
    cout << x.get_nom() << endl;
    cout << x.get_path_image() << endl;
    x.set_image("TEST");
    cout << x.get_path_image() << endl;
    cout << x.get_type() << endl;
    cout << x.get_description() << endl;
    cout << x.get_prix() << endl;
    cout << x.getMoment() << endl;


    return 0;
}