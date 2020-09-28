# include <iostream>
# include <vector>

using namespace std;

int main(){
    vector<int> count(10,0);
    for (int i {0}; i<count.size(); i++) {
        cout << i << ": " << count[i] << endl;
    }
    return 0;
}
