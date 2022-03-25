
#include <bt_node.h>
using namespace util;

template <typename T> 
void Print(const std::vector<BTNode<T>*>& level_list);

int main (){
    int sample1[] = {1, 2, 3, 4, -1, -1, 6};
    // BTNode<int>* root = MakeTreeLevelwise();
    BTNode<int>* root = MakeTreeFromArray(sample1);
    // LevelOrderTraversal<int, int>(root, Print);

    LevelOrderTraversal<int, int>(root, 0, Print);
    return 0;
}

template <typename T> 
void Print(const std::vector<BTNode<T>*>& level_list){
    for (int i = 0; i<level_list.size(); ++i){
        if (level_list[i]==NULL){
            std::cout << "NULL ";
        } else {
            std::cout << level_list[i]->data_ << " ";
        }
    }
    std::cout << std::endl;
}
