// Study_Pointer.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

#include <iostream>

void step1();
void step2();
void step3();
void step4();
void step5();
void step6();
void step7();
void step8();
void step9();

int main()
{
    std::cout <<   "■Step1\n";
    step1();
    std::cout << "\n■Step2\n";
    step2();
    std::cout << "\n■Step3\n";
    step3();
    std::cout << "\n■Step4\n";
    step4();
    std::cout << "\n■Step5\n";
    step5();
    std::cout << "\n■Step6\n";
    step6();
    std::cout << "\n■Step7\n";
    step7();
    std::cout << "\n■Step8\n";
    step8();
    std::cout << "\n■Step9\n";
    step9();
}

/// <summary>
/// numberのアドレスを出力するには？
/// </summary>
void step1()
{
    std::cout << "---Pointer.---\n";

    int number = 10;

    printf("%d\n", number);
    std::cout << number << std::endl;
    printf("\n");

    printf("0x%x\n", number);
    std::cout << "0x" << std::hex << number << std::endl;
    printf("\n");

    printf("%d\n", (int)&number);
    printf("\n");

    printf("0x%p\n", &number);
    std::cout << "0x" << std::hex << &number << std::endl;
    printf("\n");
}

/// <summary>
/// ポインタの差す先
/// </summary>
void step2()
{
    int number = 10;
    int* pNumber = &number;

    printf("numperのアドレス            = 0x%X\n", &number);
    printf("pointerの指すアドレス       = 0x%p\n", pNumber);
    printf("pointerの指すアドレスの中身 = %d\n", *pNumber);

    // ポインタはアドレスを指し示す。
}

/// <summary>
/// ポインタへの代入
/// </summary>
void step3()
{
    int number = 10;
    int* pNumber = &number;

    printf("numperのアドレス             = 0x%X\n", &number);
    printf("ポインタの指すアドレス       = 0x%p\n", pNumber);
    printf("ポインタの指すアドレスの中身 = %d\n", *pNumber);

    printf("\n");
    *pNumber = 20;
    printf("numperの中身                 = %d\n", number);
    printf("ポインタの中身               = %d\n", *pNumber);

    // 変数の先も、その変数を指すポインタの先も、同じものを指していることがわかる。
}

/// <summary>
/// ポインタのインクリメント
/// </summary>
void step4()
{
    int integerList[4] = { 10, 20, 30, 40 };
    char characterList[4] = { 'a', 'b', 'c', 'd' };

    int* pInt = integerList;
    char* pChar = characterList;

    printf("\nポインタのアドレスは？\n");
    printf("pInt address = 0x%p\n", pInt);
    printf("pChar address = 0x%p\n", pChar);

    printf("\nポインタの差すアドレスの中身は？\n");
    printf("intList[0] = %d\n", *pInt);
    printf("charList[0] = %c\n", *pChar);

    printf("\nポインタのインクリメントすると？\n");
    pInt++;
    pChar++;
    printf("\nポインタのアドレスは？\n");
    printf("pInt address = 0x%p\n", pInt);
    printf("pChar address = 0x%p\n", pChar);
    printf("\nポインタの差すアドレスの中身は？\n");
    printf("intList[0] = %d\n", *pInt);
    printf("charList[0] = %c\n", *pChar);

    // intポインタの指し示すアドレスはどれだけ進んだ？
    // charポインタの指し示すアドレスはどれだけ進んだ？

}

/// <summary>
/// ポインタのポインタとは
/// </summary>
void step5()
{
    int intValue = 10;
    int* pInt = &intValue;
    int** ppInt = &pInt;

    printf("pIntのアドレスは 0x%p\n", &pInt);
    printf("ppIntの指し示す先は 0x%p\n", ppInt);
}


void customMalloc(void** buffer, int allocateSize);

/// <summary>
/// ■step6
/// ポインタのポインタの実利用
/// </summary>
void step6()
{
    // ポインタのポインタって何に使うの？
    // →指し示す先にアドレスを入れてほしいときに使う。

    int allocateSize = 1024;
    void* allocateAddress = NULL;

    customMalloc(&allocateAddress, allocateSize);
    printf("(呼び出し元)確保したバッファのアドレス = 0x%p\n", allocateAddress);

    // 動的メモリ解放
    free(allocateAddress);
}

/// <summary>
/// 指定サイズ分のバッファを動的メモリから確保する.
/// 関数利用者がバッファを解放すること
/// </summary>
/// <param name="buffer">確保するバッファのアドレス</param>
/// <param name="allocateSize">確保するバッファのサイズ</param>
void customMalloc(void** buffer, int allocateSize)
{
    void *newBuffer = malloc(allocateSize);
    printf("(関数内)確保したバッファのアドレス = 0x%p\n", newBuffer);
    *buffer = newBuffer;

    // 分離して書いているが、
    //*buffer = malloc(allocateSize);
    // でOK
}

void customMallocSinglePointer(void* buffer, int allocateSize);
void* customMallocReturn(int allocateSize);
/// <summary>
/// ■step7
/// ダブルポインタじゃないとできない？
/// ダブルポインタを使わずにアドレスを教えてもらうには？
/// </summary>
void step7()
{
    int allocateSize = 1024;
    void* allocateAddress = NULL;

    // 引数ではもらえない。
    printf("ダブルポインタを使わずに渡してもらえる？\n");
    customMallocSinglePointer(allocateAddress, allocateSize);
    printf("(呼び出し元)確保したバッファのアドレス = 0x%p\n", allocateAddress);
    printf("アドレスは不一致\n");
    // 引数の値を変更することはできないので、関数呼び元へ確保したアドレスを伝えることはできない。

    printf("\n関数の戻りならアドレスを受け取れる？\n");
    // 関数の戻りでアドレスを返すのであれば、ダブルポインタを使う必要はない
    allocateAddress = customMallocReturn(allocateSize);
    printf("(呼び出し元)確保したバッファのアドレス = 0x%p\n", allocateAddress);

    // 動的メモリ解放
    free(allocateAddress);

}

/// <summary>
/// 引数で新しく確保したバッファのアドレスを伝えられるか
/// </summary>
/// <param name="buffer"></param>
/// <param name="allocateSize"></param>
void customMallocSinglePointer(void* buffer, int allocateSize)
{
    void* newBuffer = malloc(allocateSize);
    printf("(関数内)確保したバッファのアドレス = 0x%p\n", newBuffer);
    buffer = newBuffer;
}

void* customMallocReturn(int allocateSize)
{
    void* buffer = malloc(allocateSize);
    printf("(関数内)確保したバッファのアドレス = 0x%p\n", buffer);
    return buffer;
}

/// <summary>
/// ■step8
/// ポインタを配列のように使用してみる
/// </summary>
void step8()
{
    int* array = (int*)malloc(sizeof(int) * 10);
    array[0] = 3;
    array[1] = 5;

    // これは、int10個分のメモリを確保したので、
    // 配列のように無理やり使っている

}

void functionA();
void functionB();
void functionC();
/// <summary>
/// ■step9
/// 関数ポインタ
/// </summary>
void step9()
{
    // 関数ポインタとは、関数のアドレスを指し示す変数。
    // 実装した関数の本体も、メモリ上に展開されるため、
    // 該当アドレスを実行することで関数を実行可能、

    // 関数のアドレスだけを保持する仕組み

    void (*funcPointerA)() = functionA;
    void (*funcPointerB)() = functionB;
    void (*funcPointerC)() = functionC;

    printf("関数ポインタを直接実行\n");
    funcPointerA();
    funcPointerB();
    funcPointerC();

    printf("関数ポインタをリスト(関数テーブル)から実行\n");
    void (*funcList[])() = { functionA , functionB , functionC };
    funcList[0]();
    funcList[1]();
    funcList[2]();
}

void functionA()
{
    printf("Called %s\n", __FUNCTION__);
}
void functionB()
{
    printf("Called %s\n", __FUNCTION__);
}
void functionC()
{
    printf("Called %s\n", __FUNCTION__);
}


