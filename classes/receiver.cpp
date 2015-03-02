#include "receiver.h"


/**
 * La clase TREE estaba mal hecha, me daba hasta errores de sintaxis, eliminé todo el contenido
 * pero dejé los archivos tree.h y tree.cpp.
 * Luego reemplazalos con el contenido nuevo.
 */

void Receiver::_setData(
        QString _algorithm,
        QString _preCondition,
        QString _postCondition,
        QString _invariant,
        QString _bound )
{

    /**
     * LOS PARÁMETROS SON LOS DATOS INGRESADOS EN EL FORMULARIO,
     * USALOS, CUANDO SE EJECUTE ESTA FUNCIÓN YA VAN A ESTAR SETEADOS
     * ESOS VALORES.
     */

    Parser parser;

    /**
     * Algorithm
     */
    ParsedData algorithm;
    parser.parse(_algorithm);
    parser.getAlgorithmData(algorithm);
    /**
     * precondition
     */
    QQueue<string> precondition;
    parser.parse(_preCondition);
    parser.getData(precondition);
    /**
     * postcondition
     */
    QQueue<string> postcondition;
    parser.parse(_postCondition);
    parser.getData(postcondition);
    /**
     * invariant
     */
    QQueue<string> invariant;
    parser.parse(_invariant);
    parser.getData(invariant);
    /**
     * bound
     */
    QQueue<string> bound;
    parser.parse(_bound);
    parser.getData(bound);


    GeneratorTest generador(precondition,postcondition,invariant,bound,algorithm);
    bool endProof = false;
    QQueue<std::string> test;
    generador.getTest(1,test,endProof);

    TreeAux ternaryTree;
    RefutationTree Refutation;

    Refutation.drawingTree(test,ternaryTree);
    QQueue<data> GUIData;
    ternaryTree.getTree(GUIData);

    this->_sendNodes(GUIData);

    cout << endl << "*---->SEPARACIÓN<----*" << endl;
}

void Receiver::_sendNodes(QQueue<data> nodes) {
    data nodeData;
    while ( ! nodes.empty() ) {
        nodeData = nodes.dequeue();
        this->node(
                nodeData.getCoordX(),
                nodeData.getCoordY(),
                nodeData.getFormula(),
                nodeData.isLiteral()
        );
    }

}
