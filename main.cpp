#include <iostream>
#include <string>
#include "expressionTree.h"

using namespace std;

int main() {
    expressionTree et;

    try {
        // Samples
        cout << "Expression: 35 27 + 3 *" << endl;
        cout << "Result: " << et.evaluateExpression("35 27 + 3 *") << endl;

        cout << "Expression: 23 30 15 * /" << endl;
        cout << "Result: " << et.evaluateExpression("23 30 15 * /") << endl;

        cout << "Expression: 34 24 12 7 / * + 23 -" << endl;
        cout << "Result: " << et.evaluateExpression("34 24 12 7 / * + 23 -") << endl;

        cout << "Expression: 3 7 + 14 *" << endl;
        cout << "Result: " << et.evaluateExpression("3 7 + 14 *") << endl;
    } catch (const runtime_error &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
