#include "parsingtree.h"

ParsingTree::ParsingTree() {
    this->_root = NULL;
}

ParsingTree::~ParsingTree() {

}

void ParsingTree::pushSymbol(string data) {
        cout<< data <<endl;
        _TreeNode* node = new _TreeNode;
        node->data = data;
        node->leftNode = NULL;
        node->rightNode= NULL;
        this->_auxList.push_back(node);


}

void ParsingTree::pushLogicOperator(string data){
    cout<< data <<endl;
    _TreeNode * node = new _TreeNode;
    node->data = data;
    node->rightNode = this->_auxList.last();
    this->_auxList.removeLast();

    //binarios
    if ( ( data == "||" ) || ( data == "&&" ) || ( data == "->" ) || ( data == "<->" )) {

         node->leftNode = this->_auxList.last();
         this->_auxList.removeLast();

    }

    //unarios
    if ( ( data == "!" ) || ( data == "()" ) || ( data == "$" ) || ( data=="@" ) || ( data == "#" )  ){

        node->leftNode= NULL;

    }

    if(data == "()"){
        while(! this->_auxList.empty() ){
            if((this->_auxList.last()->data == "@" || this->_auxList.last()->data == "#")){
                _TreeNode* nodeAux = this->_auxList.last();
                this->_auxList.removeLast();
                nodeAux->rightNode->rightNode = node;
                node = nodeAux;

            }
            else
             {
                _TreeNode* nodeAux = this->_auxList.last();
                this->_auxList.removeLast();
                nodeAux->rightNode->rightNode->rightNode = node;
                node = nodeAux;
            }
        }
   }

    this->_auxList.push_back(node);

}

void ParsingTree::printTree() {
    this->_root = this->_auxList.last();
    this->_printTree(this->_root);
}

void ParsingTree::_printTree(ParsingTree::_TreeNode* tree) {
    if (tree == NULL)
        return;

    _printTree(tree->leftNode);

    if ( tree->data == "()" ) {
        cout << "(";
        _printTree(tree->rightNode);
        cout << ")";
    }
    else if ( tree->data == "$" ) {
        cout << " ! ( ";
        _printTree(tree->rightNode);
        cout << " ) ";
    }
    else {
        cout << tree->data + " ";
        _printTree(tree->rightNode);
    }
}

void ParsingTree::toQueue(QQueue<string> & entireFormula) {
    this->_root = this->_auxList.last();

    this->_toQueue(entireFormula, this->_root);

}

void ParsingTree::_toQueue(QQueue<string> & entireFormula, ParsingTree::_TreeNode * tree) {
    if (tree == NULL)
        return;

    this->_toQueue(entireFormula, tree->leftNode);

    if ( tree->data == "()" ) {
        entireFormula.enqueue("(");
        this->_toQueue(entireFormula, tree->rightNode);
        entireFormula.enqueue(")");
    }
    else if ( tree->data == "$" ) {
        entireFormula.enqueue("!");
        entireFormula.enqueue("(");
        this->_toQueue(entireFormula, tree->rightNode);
        entireFormula.enqueue(")");
    }
    else {
     entireFormula.enqueue(tree->data);
     this->_toQueue(entireFormula, tree->rightNode);
    }
}

void ParsingTree::clear(){

    this->_auxList.clear();
    this->_root = NULL;

}
