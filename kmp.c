//
// Created by ge on 2024/1/5.
//

#include <stdio.h>

/**
 *   algorithm kmp_table:
        input:
            an array of characters, W (the word to be analyzed)
        output:
            an array of integers, T (the table to be filled)

        define variables:
            an integer, pos ← 1 (the current position we are computing in T)
            an integer, cnd ← 0 (the zero-based index in W of the next character of the current candidate substring)

        let T[0] ← -1

        while pos < length(W) do
            if W[pos] = W[cnd] then
                let T[pos] ← T[cnd]
            else
                let T[pos] ← cnd
                while cnd ≥ 0 and W[pos] ≠ W[cnd] do
                    let cnd ← T[cnd]
            let pos ← pos + 1, cnd ← cnd + 1

        let T[pos] ← cnd (only needed when all word occurrences are searched)
 * @return
 */

int main() {

    return 0;
}
