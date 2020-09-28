/** weak_ptr
 * - doesn't participate in owning the memory
 * - always created from shared_ptr
 * - doesn't change reference use count
 *
 *
 *
 */


# include<iostream>
# include<memory>

class B; //forward declaration

class A {
    std::shared_ptr<B> b_ptr;
public:
    void setB(std::shared_ptr<B> &b){
        b_ptr = b;
    }
    A(){std::cout << "A Constructor" << std::endl;}
    ~A(){std::cout << "A Destructor" << std::endl;}
};

class B {
    std::shared_ptr<A> a_ptr;
public:
    void setA(std::shared_ptr<A> &a){
        a_ptr = a;
    }
    B(){std::cout << "B Constructor" << std::endl;}
    ~B(){std::cout << "B Destructor" << std::endl;}
};


int main(){
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->setB(b);
    b->setA(a);
    return 0;
}