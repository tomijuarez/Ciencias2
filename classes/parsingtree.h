#ifndef PARSINGTREE_H
#define PARSINGTREE_H

#include <QList>
#include <QQueue>
#include <iostream>

using namespace std;

class ParsingTree {
    public:
        ParsingTree();
        ~ParsingTree();
        void pushSymbol(string data);
        void pushLogicOperator(string data);
        void printTree();
        void clear();
        void toQueue( QQueue<string> & entireFormula );
    private:
        struct _TreeNode {
            string data;
            _TreeNode* leftNode;
            _TreeNode* rightNode;
        };
        QList<_TreeNode*> _auxList; //guarda el arbol en formación
        _TreeNode* _root; //pedir el ultimo elemento de la lista, ese es el arbol

        void _toQueue ( QQueue<string> & entireFormula, _TreeNode* _tree );
        void _printTree(_TreeNode* tree);
};

#endif // PARSINGTREE_H
