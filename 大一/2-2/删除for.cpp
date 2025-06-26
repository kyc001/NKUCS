#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // isspace 函数需要这个头文件

/**
 * @brief 跳过输入文件流中的空白字符。
 * @param fin 要读取的输入文件流。
 */
void skipWhitespace(std::ifstream& fin) {
    // 查看下一个字符，如果是空白字符就消耗掉它。
    while (!fin.eof() && std::isspace(fin.peek())) {
        fin.get();
    }
}

/**
 * @brief 消耗并丢弃一个由圆括号括起来的代码块，如 ( ... )。
 * 这个函数能正确处理嵌套的圆括号。
 * @param fin 要读取的输入文件流。
 */
void consumeParenthesesBlock(std::ifstream& fin) {
    skipWhitespace(fin);

    if (fin.peek() != '(') {
        // 这表示源文件中有语法错误，但我们仍然尝试继续。
        return;
    }
    fin.get(); // 消耗掉开头的 '('

    int parenLevel = 1;
    while (!fin.eof() && parenLevel > 0) {
        char ch = fin.get();
        if (ch == '(') {
            parenLevel++;
        } else if (ch == ')') {
            parenLevel--;
        }
    }
}

/**
 * @brief 消耗并丢弃一个 C++ 语句。
 * 这可能是一个由花括号 { ... } 包围的代码块语句，
 * 或一个以分号 ; 结尾的单行语句。
 * @param fin 要读取的输入文件流。
 */
void consumeStatement(std::ifstream& fin) {
    skipWhitespace(fin);

    if (fin.peek() == '{') {
        // 这是一个代码块语句，例如 for(...) { ... }
        fin.get(); // 消耗掉开头的 '{'
        int braceLevel = 1;
        while (!fin.eof() && braceLevel > 0) {
            // 注意：这个简化的解析器不处理包含花括号的注释或字符串，
            // 但对于这个问题来说已经足够了。
            char ch = fin.get();
            if (ch == '{') {
                braceLevel++;
            } else if (ch == '}') {
                braceLevel--;
            }
        }
    } else {
        // 这是一个单行语句，例如 for(...) statement;
        // 消耗所有字符，直到找到结束的分号。
        while (!fin.eof() && fin.get() != ';') {
            // 继续消耗字符。
        }
    }
}

int main() {
    std::string inFilename;
    std::cout << "请输入要处理的 C++ 文件的文件名: ";
    std::cin >> inFilename;

    // (2) 检查文件是否存在并可以打开。
    std::ifstream fin(inFilename);
    if (!fin.is_open()) {
        std::cerr << "错误: 无法打开文件 '" << inFilename << "'。请检查文件名是否正确或文件是否存在。" << std::endl;
        return 1; // 指示错误
    }

    // (3) 创建新文件名并打开输出文件。
    std::string outFilename = "new" + inFilename;
    std::ofstream fout(outFilename);
    if (!fout.is_open()) {
        std::cerr << "错误: 无法创建输出文件 '" << outFilename << "'。" << std::endl;
        fin.close(); // 在退出前关闭输入文件
        return 1; // 指示错误
    }

    char ch;
    std::string word;

    // 逐字符读取输入文件以保留格式。
    while (fin.get(ch)) {
        if (std::isalpha(ch) || ch == '_') {
            // 可能的关键字或标识符的开头
            word = ch;
            // 贪婪地读取标识符的其余部分
            while (!fin.eof() && (std::isalnum(fin.peek()) || fin.peek() == '_')) {
                word += fin.get();
            }

            // (3) 检查这个词是否是 "for"
            if (word == "for") {
                // 这是一个 for 循环。我们必须消耗并丢弃它。
                consumeParenthesesBlock(fin);
                consumeStatement(fin);
            } else {
                // 这是一个常规的单词，所以将它写入输出。
                fout << word;
            }
        } else {
            // 该字符不是标识符的一部分（例如，空白、#、;、{ 等符号）
            // 直接将其写入输出以保留它。
            fout.put(ch);
        }
    }

    std::cout << "处理完成！已移除所有的 for 语句。" << std::endl;
    std::cout << "结果已保存到文件: " << outFilename << std::endl;

    // 关闭文件，清理资源。
    fin.close();
    fout.close();

    return 0; // 指示成功
}
