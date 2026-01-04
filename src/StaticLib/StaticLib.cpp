#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
#include <stdlib.h> // qsort使うため、たくさんの要素がタイムアウトした。

static int compare_item(const void* a, const void* b)
{
    const item* ia = (const item*)a;
    const item* ib = (const item*)b;

    return ia->key - ib->key; 
}

// バブルソート(引数が不適切であればfalseを返す)
bool bubble_sort(item* begin, const item* end)
{
    if (begin == NULL || end == NULL || begin >= end) {
        return false;
    }

    size_t count = (size_t)(end - begin);

    qsort(begin, count, sizeof(item), compare_item);

    return true;
}
