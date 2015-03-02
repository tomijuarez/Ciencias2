#include "treeaux.h"

TreeAux::TreeAux() {
     this->_constants.enqueue("A");
     this->_constants.enqueue("B");
     this->_constants.enqueue("C");
     this->_constants.enqueue("D");
     this->_constants.enqueue("E");
     this->_constants.enqueue("F");
     this->_constants.enqueue("G");
     this->_constants.enqueue("H");
     this->_constants.enqueue("I");
     this->_constants.enqueue("J");
     this->_constants.enqueue("K");

     this->_ConstE = this->_constants.dequeue();
     this->_ConstU = this->_ConstE;
     this->_CuantConst = NULL;
}


void TreeAux::setTree(std::string formula)
{
    Coordinate coord;
    coord.setCoord(0,1);
    _treeNode* node = this->_newNode(formula);
    node->coord = coord;
    this->_leaves.enqueue(node);
    this->_tree.enqueue(node);
}


void TreeAux::_insertOrdered(_treeNode* node,int Y)
{
    QQueue<_treeNode*>::iterator it = this->_tree.begin();
    _treeNode* aux;
    bool found = false;
    //itero hasta encontrar el mismo nivel
    while( (it != this->_tree.end()) && (!found) )
    {
        aux = *it;
        if(aux->coord.getCoordY() == Y)
            found = true;
        else
            it++;
    }
    // si no encontre es porque es nuevo en el nivel
    if( found == false)
    {
       this->_tree.enqueue(node);
    }
    else
    {
        // sino busco la prox posicion en X libre
        while( (it != this->_tree.end()) && ((aux->coord.getCoordY() == Y) ) )
        {

            it++;
            aux = *it;
        }
        this->_tree.insert(it,node);
    }
}

// Genera un nuevo node del arbol
TreeAux::_treeNode* TreeAux::_newNode(std::string formula)
{
    _treeNode* node = new _treeNode;
    node->formula = formula;
    node->father = NULL;
    node->isLiteral = false;
    return node;
}

TreeAux::_treeNode* TreeAux::_findSheet(std::string formula)
{
    QQueue<_treeNode*>::iterator it = this->_leaves.begin();
    _treeNode* aux;
    //bucle de busquedad
    while(it != this->_leaves.end()){
        aux = *it;
        if(aux->formula == formula)
            return aux;
        else
            it++;
    }

    return NULL;
}

void TreeAux::_deleteSheet(QQueue<_treeNode *> & Leaves, std::string formula,Coordinate coord)
{
    QQueue<_treeNode*>::iterator it = Leaves.begin();
    _treeNode* aux;
    bool found = false;
    //bucle de busquedad
    while(it != Leaves.end() && (!found)){
        aux = *it;
        if((aux->formula == formula) && (aux->coord.getCoordX() == coord.getCoordX()) && (aux->coord.getCoordY() == coord.getCoordY()))
            found = true;
        else
            it++;
    }

    std::cout<<"Elimino la siguiente formula: "<<(*it)->formula<<std::endl;
    Leaves.erase(it);
}

bool TreeAux::_isLiteral(std::string formula)
{
    int pos = 0;
    int aux = 0;
    bool found = false;

    while(pos <= formula.size() && (found == false)){

        if(formula[pos] == '{')
            aux++;

        if(formula[pos] == '}')
            aux--;

        if(formula[pos] == '&' || formula[pos] == '|' || (formula[pos] == '<' && formula[pos+1] == '-' && formula[pos+2] == '>') || (formula[pos] == '-' && formula[pos+1] == '>') )
            found = true;

        pos++;

    }

    if(found == true)
        return false;
    else
        return true;

}

void TreeAux::_insertInSheet(QQueue<_treeNode *> & tree,QQueue<_treeNode *> & Leaves, _treeNode *sheet, std::string formulaOne,std::string formulaTwo,unsigned int type){

    if(type == 3)
    {
        std::cout<<"Tipo 3"<<std::endl;
        std::cout<<"Nodo previo: "<<sheet->formula<<std::endl;
        std::cout<<formulaOne<<std::endl;
        std::cout<<"Coordenada Anterior: "<<"("<<sheet->coord.getCoordX()<<","<<sheet->coord.getCoordY()<<")"<<std::endl;


        //creo la coordenada
        int Y = sheet->coord.getCoordY()+1;
        //creo el nodo
        _treeNode* node = this->_newNode(formulaOne);
        node->father = sheet;
        Coordinate coord;
        coord.setCoord(sheet->coord.getCoordX(),Y);
        node->coord = coord;
        //elimino la "ex" hoja y lo agrego como nueva hoja del arbol
        this->_deleteSheet(Leaves,sheet->formula,sheet->coord);
        Leaves.enqueue(node);
        //lo agrego a los nodos del arbol
        if(this->_isLiteral(formulaOne) ){
            node->isLiteral = true;
        }
        this->_insertOrdered(node,Y);

    }
    else if(type == 2)
    {
        std::cout<<"Tipo 2"<<std::endl;
        std::cout<<"Nodo previo: "<<sheet->formula<<std::endl;
        std::cout<<formulaOne<<std::endl;
        std::cout<<formulaTwo<<std::endl;
        std::cout<<"Coordenada Anterior: "<<"("<<sheet->coord.getCoordX()<<","<<sheet->coord.getCoordY()<<")"<<std::endl;

        _treeNode* nodeOne = this->_newNode(formulaOne);
        _treeNode* nodeTwo = this->_newNode(formulaTwo);
        nodeOne->father = sheet;
        nodeTwo->father = nodeOne;
        int Y = sheet->coord.getCoordY()+1;
        Coordinate coordOne;
        Coordinate coordTwo;
        coordOne.setCoord(sheet->coord.getCoordX(),Y);
        coordTwo.setCoord(sheet->coord.getCoordX(),Y+1);

        nodeOne->coord = coordOne;
        nodeTwo->coord = coordTwo;

        if(this->_isLiteral(formulaOne) ){
            nodeOne->isLiteral = true;
        }
        if(this->_isLiteral(formulaTwo) ){
            nodeTwo->isLiteral = true;
        }
        this->_insertOrdered(nodeOne,Y);
        this->_insertOrdered(nodeTwo,Y+1);

        this->_deleteSheet(Leaves,sheet->formula,sheet->coord);

        Leaves.enqueue(nodeTwo);

    }
    else
    {

        std::cout<<"Tipo 1"<<std::endl;
        std::cout<<"Nodo previo: "<<sheet->formula<<std::endl;
        std::cout<<formulaOne<<std::endl;
        std::cout<<formulaTwo<<std::endl;
        std::cout<<"Coordenada Anterior: "<<"("<<sheet->coord.getCoordX()<<","<<sheet->coord.getCoordY()<<")"<<std::endl;

        _treeNode* nodeOne = this->_newNode(formulaOne);
        _treeNode* nodeTwo = this->_newNode(formulaTwo);
        nodeOne->father = sheet;
        nodeTwo->father = sheet;
        int Y = sheet->coord.getCoordY()+1;
        Coordinate coordOne;
        Coordinate coordTwo;
        coordOne.setCoord(sheet->coord.getCoordX()-1,Y);
        coordTwo.setCoord(sheet->coord.getCoordX()+1,Y);

        nodeOne->coord = coordOne;
        nodeTwo->coord = coordTwo;
        if(this->_isLiteral(formulaOne) ){
            nodeOne->isLiteral = true;
        }
        if(this->_isLiteral(formulaTwo) ){
            nodeTwo->isLiteral = true;
        }
        this->_insertOrdered(nodeOne,Y);
        this->_insertOrdered(nodeTwo,Y);
        this->_deleteSheet(Leaves,sheet->formula,sheet->coord);
        Leaves.enqueue(nodeOne);
        Leaves.enqueue(nodeTwo);

    }

}

bool TreeAux::_sameBranch(_treeNode *sheet, std::string formula)
{
    if(sheet != NULL)
    {
        if(sheet->formula == formula)
        {
            return true;
        }
        else
        {
            return this->_sameBranch(sheet->father,formula);
        }
    }
    else
        return false;
}

void TreeAux::_insertInLeaves(QQueue<_treeNode *> & tree, std::string formulaOne, std::string formulaTwo,unsigned int type,std::string previousFormula)
{
    QQueue<_treeNode*> auxQQueue = this->_leaves;
    QQueue<_treeNode*>::iterator it = auxQQueue.begin();
    _treeNode* auxNode;

    while(it != auxQQueue.end()){
        auxNode = *it;

        if( (this->_sameBranch(auxNode,previousFormula) ) == true)
        {
            this->_insertInSheet(tree,this->_leaves,auxNode,formulaOne,formulaTwo,type);
        }
        it++;
    }

    auxQQueue.clear();

}

void TreeAux::_insertTypeA_cuant(QQueue<_treeNode*> &tree,std::string formula,std::string previousFormula,bool E)
{
    _treeNode* aux = this->_findSheet(previousFormula);

    if(aux == NULL)
    {
        this->_insertInLeaves(tree,formula,"empty",3,previousFormula);

    }
    else
    {
       this->_insertInSheet(tree,this->_leaves,aux,formula,"empty",3);
       aux = this->_findSheet(previousFormula);

       while(aux  != NULL)
       {
             this->_insertInSheet(tree,this->_leaves,aux,formula,"empty",3);
             aux = this->_findSheet(previousFormula);
       }

    }
    this->admisConst(E);
}

void TreeAux::_insertTypeA(QQueue<_treeNode *> &tree, std::string formulaOne, std::string formulaTwo,std::string previousFormula)
{
    _treeNode* aux = this->_findSheet(previousFormula);

    if(aux == NULL)
    {
        this->_insertInLeaves(tree,formulaOne,formulaTwo,2,previousFormula);
    }
    else
    {
       this->_insertInSheet(tree,this->_leaves,aux,formulaOne,formulaTwo,2);
       aux = this->_findSheet(previousFormula);

       while(aux  != NULL)
       {
             this->_insertInSheet(tree,this->_leaves,aux,formulaOne,formulaTwo,2);
             aux = this->_findSheet(previousFormula);
       }
    }
}

void TreeAux::_insertTypeB(QQueue<_treeNode *> &tree, std::string formulaOne, std::string formulaTwo,std::string previousFormula)
{
    _treeNode* aux = this->_findSheet(previousFormula);

    if(aux == NULL)
    {
        this->_insertInLeaves(tree,formulaOne,formulaTwo,1,previousFormula);
    }
    else
    {
       this->_insertInSheet(tree,this->_leaves,aux,formulaOne,formulaTwo,1);
       aux = this->_findSheet(previousFormula);

       while(aux  != NULL)
       {
             this->_insertInSheet(tree,this->_leaves,aux,formulaOne,formulaTwo,1);
             aux = this->_findSheet(previousFormula);
       }
    }
}


void TreeAux::addFormulas(unsigned int type, std::string ConclusionOne, std::string ConclusionTwo,std::string previousFormula,bool E)
{
    if(type == 1){
        this->_insertTypeB(this->_tree,ConclusionOne,ConclusionTwo,previousFormula);
    }
    else if(type == 2)
    {
        this->_insertTypeA(this->_tree,ConclusionOne,ConclusionTwo,previousFormula);
    }
    else
    {
        this->_insertTypeA_cuant(this->_tree,ConclusionOne,previousFormula,E);
    }
}

/***************************************************** Funciones de la administracion de las ramas *****************************/

TreeAux::_Branch* TreeAux::_newBranch(_treeNode* sheet,unsigned int num)
{
    _Branch* node = new _Branch;
    node->branch = sheet;
    node->num = num;
    node->close = false;
    node->view = false;
    node->nextBranch = NULL;
}

void TreeAux::_insertBranch(_Branch* & branches, _Branch* branch){
    if(branches == NULL)
        branches = branch;
    else
        this->_insertBranch(branches->nextBranch,branch);
}

void TreeAux::_generateBranches()
{
    QQueue<_treeNode*>::iterator it = this->_leaves.begin();
    _treeNode* aux;
    _Branch* node;
    unsigned int branch = 1;

    while(it != this->_leaves.end())
    {
     aux = *it;
     node = this->_newBranch(aux,branch);

     this->_insertBranch(this->_branches,node);

     branch++;
     it++;
    }
}

void TreeAux::generateBranches()
{
    this->_branches = NULL;
    this->_generateBranches();
    this->_nextBranch = this->_branches;
    this->_endBranches = false;
}

void TreeAux::_copy(_treeNode* sheet, QList<std::string> &branches)
{
    if(sheet != NULL)
    {
        if(sheet->isLiteral == true)
            branches.push_back(sheet->formula);
        this->_copy(sheet->father,branches);
    }

}

void TreeAux::getBranches(QList<std::string> & branches)
{
   if(this->_endBranches == false)
   {
      this->_currentBranch = this->_nextBranch;
      this->_currentBranch->view = true;
      this->_copy(this->_nextBranch->branch,branches);

      if(this->_nextBranch->nextBranch != NULL)
        this->_nextBranch = this->_nextBranch->nextBranch;
      else
        this->_endBranches = true;
   }
}

void TreeAux::closeBranch(){
    this->_currentBranch->close = true;
}

bool TreeAux::closeTree(){
      return this->_closeTree(this->_branches);
}

bool TreeAux::_closeTree(_Branch * branches)
{
       if(branches != NULL)
           return ((branches->close) && (this->_closeTree(branches->nextBranch)));
}



/************************************************************** Sector de adminsitracion de constantes ******************************************/
//Duda de como usar los cuantificadores en el arbol, es decir, la idea de como resolverlo esta, solo falta definir la duda teoria de como manejar esas situaciones
void TreeAux::_copyConst(QList<std::string> &list, _constCuant *constants){
    if(constants != NULL){
        list.push_back(constants->constant);
        this->_copyConst(list,constants->nextConst);
    }
}

void TreeAux::ConstU(QList<std::string> & L){
    this->_copyConst(L,this->_CuantConst);
}

void TreeAux::admisConst(bool E){
    if(E == true){

            std::string aux = this->_constants.dequeue();
            _constCuant* node = this->_newConst(this->_ConstE);
            this->_insertConst(this->_CuantConst,node);

            this->_ConstE = aux;
       }

    this->_printLista(this->_CuantConst);
}

void TreeAux::_insertConst(_constCuant* & constants, _constCuant* constant)
{
    if(constants == NULL)
        constants = constant;
    else
        this->_insertConst(constants->nextConst,constant);

}

TreeAux::_constCuant* TreeAux::_newConst(std::string constant)
{
    _constCuant* node = new _constCuant;
    node->constant = constant;
    node->nextConst = NULL;
    return node;

}

std::string TreeAux::ConstantE()
{
    return this->_ConstE;

}

std::string TreeAux::ConstantU()
{
    return this->_ConstU;
}

void TreeAux::getTree(QQueue<data> & Output)
{
    QQueue<_treeNode*>::iterator it = this->_tree.begin();
    while(it != this->_tree.end())
    {
        _treeNode* auxData= *it;
        data _node;
        _node.setData(auxData->formula,auxData->coord.getCoordX(),auxData->coord.getCoordY(),auxData->isLiteral);
        Output.enqueue(_node);
        it++;
    }
}

/************************************************************** Sector de Impresiones ******************************************/

void TreeAux::printTree()
{
    QQueue<_treeNode*>::iterator it = this->_tree.begin();
    _treeNode* aux;

    std::cout<<"****************************************************"<<std::endl;
    std::cout<<"Este es el árbol generado: "<<std::endl;

    while(it != this->_tree.end())
    {
     aux = *it;
     std::cout<<"Formula: "<<aux->formula<<" "<<"Coordenada: "<<"("<<aux->coord.getCoordX()<<","<<aux->coord.getCoordY()<<")"<<"   Este literal: "<<aux->isLiteral<<std::endl;
     it++;
    }
}


void TreeAux::printLeaves()
{
    QQueue<_treeNode*>::iterator it = this->_leaves.begin();
    _treeNode* aux;

    std::cout<<"****************************************************"<<std::endl;
    std::cout<<"Estas son las hojas del arbol: "<<std::endl;

    while(it != this->_leaves.end())
    {
     aux = *it;
     std::cout<<"Formula: "<<aux->formula<<" "<<"Coordenada: "<<"("<<aux->coord.getCoordX()<<","<<aux->coord.getCoordY()<<")"<<std::endl;
     it++;
    }
}

void TreeAux::_printBranch(_treeNode *branch){
    if(branch != NULL){

        std::cout<<" "<<branch->formula<<" "<<"->";
        this->_printBranch(branch->father);
    }
}

void TreeAux::_printLista(_constCuant* lista){
    if(lista != NULL){

        std::cout<<" "<<lista->constant<<" "<<"->";
        this->_printLista(lista->nextConst);
    }
}


void TreeAux::_printBranches(_Branch* branches)
{
    if(branches != NULL)
    {
        std::cout<<"*****************************************************"<<std::endl;
        std::cout<<"Rama numero: "<<branches->num<<std::endl;
        this->_printBranch(branches->branch);
        std::cout<<std::endl;
        std::cout<<"Esta cerrada la rama??: "<<branches->close<<std::endl;
        std::cout<<"Fue vista?? "<<branches->view<<std::endl;
        this->_printBranches(branches->nextBranch);
    }
}

void TreeAux::printBranches()
{
    std::cout<<"****************************************************"<<std::endl;
    std::cout<<"Estas son las ramas del arbol: "<<std::endl;
    this->_printBranches(this->_branches);
}


TreeAux::~TreeAux()
{

}

