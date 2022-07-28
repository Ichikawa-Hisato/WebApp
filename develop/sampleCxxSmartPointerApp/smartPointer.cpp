#include <iostream>
#include <string>
#include <memory>
using namespace std;

//////////////////////////////////
////    shared_ptr example    ////
//////////////////////////////////
auto sample_shared_ptr = []() {
    std::shared_ptr<int> x = std::make_shared<int>(100); // int* x = new int(100); の代わり。所有者は1人。

    {
        std::shared_ptr<int> y = x; // 通常のポインタ同様、コピーすることで所有権が共有される
                                    // 所有者が2人に増える。
        std::cout << "shared_ptr:*y=" << *y << std::endl;
    } // y が破棄されて所有者が1人になる。

    std::cout << "shared_ptr:*x=" << *x << std::endl;

    return 0;
    // 所有者が0人になるので、 x のデストラクタで自動的に delete が行われる。
};

//////////////////////////////////
////    unique_ptr example    ////
//////////////////////////////////
auto sample_unique_ptr = []() {
    std::unique_ptr<int> x(new int(50)); // std::unique_ptr<int> y = x; // コピー出来ない。コンパイルエラー。

    std::cout << "unique_ptr:*x=" << *x << std::endl;

    return 0;
    // x が所有しているリソースが解放される。
};

auto sample_uniptr_move = []() {
    std::unique_ptr<int> x(new int(100));
    std::unique_ptr<int> y(std::move(x)); // ムーブは出来るため、所有権の移動は可能。所有権を移動したため、x は何も所有していない。

    std::cout << "move unique_ptr:*y=" << *y << std::endl;

    return 0;
    // y が所有しているリソースが解放される。
};

//////////////////////////////////
////    weak_ptr example      ////
//////////////////////////////////
auto sample_weak_ptr = []() {
    std::shared_ptr<int> sp = std::make_shared<int>(246);
    std::weak_ptr<int> wp = sp; // sp を監視対象として wp に登録する

    std::shared_ptr<int> sp2 = wp.lock(); // 有効な場合は sp とリソースを共有する sp2 が作られる
    if (sp2) {
        std::cout << *sp2 << std::endl;
    } else {
        std::cout << "リソースは解放済み" << std::endl;
    }

    return 0;
};

////////////////////////////////////
////            main            ////
////////////////////////////////////
int main(int argc, char *argv[])
{
    std::cout << "Sample Smart Pointer Applicattion" << std::endl;

    int return_code1 = sample_shared_ptr();
    int return_code2 = sample_unique_ptr();
    int return_code3 = sample_uniptr_move();
    int return_code4 = sample_weak_ptr();

    return 0;
}
