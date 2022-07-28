#include <iostream>
#include <string>
#include <memory>
using namespace std;

//////////////////////////////////
////    shared_ptr example    ////
//////////////////////////////////
auto sample_shared_ptr = []() {
    std::shared_ptr<int> x = std::make_shared<int>(100); // int* x = new int(100); �̑���B���L�҂�1�l�B

    {
        std::shared_ptr<int> y = x; // �ʏ�̃|�C���^���l�A�R�s�[���邱�Ƃŏ��L�������L�����
                                    // ���L�҂�2�l�ɑ�����B
        std::cout << "shared_ptr:*y=" << *y << std::endl;
    } // y ���j������ď��L�҂�1�l�ɂȂ�B

    std::cout << "shared_ptr:*x=" << *x << std::endl;

    return 0;
    // ���L�҂�0�l�ɂȂ�̂ŁA x �̃f�X�g���N�^�Ŏ����I�� delete ���s����B
};

//////////////////////////////////
////    unique_ptr example    ////
//////////////////////////////////
auto sample_unique_ptr = []() {
    std::unique_ptr<int> x(new int(50)); // std::unique_ptr<int> y = x; // �R�s�[�o���Ȃ��B�R���p�C���G���[�B

    std::cout << "unique_ptr:*x=" << *x << std::endl;

    return 0;
    // x �����L���Ă��郊�\�[�X����������B
};

auto sample_uniptr_move = []() {
    std::unique_ptr<int> x(new int(100));
    std::unique_ptr<int> y(std::move(x)); // ���[�u�͏o���邽�߁A���L���̈ړ��͉\�B���L�����ړ��������߁Ax �͉������L���Ă��Ȃ��B

    std::cout << "move unique_ptr:*y=" << *y << std::endl;

    return 0;
    // y �����L���Ă��郊�\�[�X����������B
};

//////////////////////////////////
////    weak_ptr example      ////
//////////////////////////////////
auto sample_weak_ptr = []() {
    std::shared_ptr<int> sp = std::make_shared<int>(246);
    std::weak_ptr<int> wp = sp; // sp ���Ď��ΏۂƂ��� wp �ɓo�^����

    std::shared_ptr<int> sp2 = wp.lock(); // �L���ȏꍇ�� sp �ƃ��\�[�X�����L���� sp2 �������
    if (sp2) {
        std::cout << *sp2 << std::endl;
    } else {
        std::cout << "���\�[�X�͉���ς�" << std::endl;
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
