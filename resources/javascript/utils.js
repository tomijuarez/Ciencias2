/**
 * GUI class.
 */

var GUI = { };

GUI.setInputErrorState = function(_input) {
    _input.parent.color = "#e74c3c";
}

GUI.cleanInputErrorState = function (_input, index) {
    _input.parent.color = "transparent";
}

GUI.assignLabel = function ( _index ) {
    if ( _index == 0 )
        return "P R E C O N D I C I Ó N";
    if ( _index == 1 )
        return "P O S T C O N D I C I Ó N";
    if ( _index == 2 )
        return "I N V A R I A N T E";
    if ( _index == 3 )
        return "C O T A";

    return "A L G O R I T M O";
}

GUI.textAreaSize = function ( _index ) {
    if ( _index == 4 )
        return 100;
    return 40;
}

GUI.rectangleContainerSize = function ( _index ) {
    if ( _index == 4 )
        return 230;
    return 100;
}


/**
 * InputCollection class.
 */
var InputCollection = { };

InputCollection.inputs = [ ];

InputCollection._algorithm = null;
InputCollection._preCondition = null;
InputCollection._postCondition = null;
InputCollection._invariant = null;
InputCollection._bound = null;

InputCollection._associateInput = function (_index, _input) {
    if ( _index == 0 )
        this._preCondition = _input;
    if ( _index == 1 )
        this._postCondition = _input;
    if ( _index == 2 )
        this._invariant = _input;
    if ( _index == 3 )
        this._bound = _input;
    if ( _index == 4 )
        this._algorithm = _input;
}

InputCollection.getId = function (_index, _QMLComponent) {
    this.inputs.push(_QMLComponent);
    this._associateInput(_index, _QMLComponent);
    return "input-" + _index;
}


/**
 * Error class.
 */
var Error = { };

Error.emptyData = function() {
    InputCollection.inputs.forEach(function(_input) {
        if ( Verifier.inputIsNull(_input) ) {
            GUI.setInputErrorState(_input);
        }
    });
}

/**
 * Verifier class.
 */

String.prototype.isEmpty = function() {
    return (this.length === 0 || !this.trim());
};

var Verifier = { }

Verifier.inputIsNull = function ( input ) {
    var text = input.getText(0,input.length);
    return (text.isEmpty());
};

Verifier.fullInputs = function() {
    var _self = this
      , value = true
      ;

    InputCollection.inputs.some( function ( input ) {
        if ( value )
            value = !(_self.inputIsNull(input));
    });

    return value;
};

var Events = { };

Events.sendData = function() {
    console.log("Se envian todos los datos.");
    eventsManager._setData(
                InputCollection._algorithm.getText(
                    0, InputCollection._algorithm.length
                ),
                InputCollection._preCondition.getText(
                    0, InputCollection._preCondition.length
                ),
                InputCollection._postCondition.getText(
                    0, InputCollection._postCondition.length
                ),
                InputCollection._invariant.getText(
                    0, InputCollection._invariant.length
                ),
                InputCollection._bound.getText(
                    0, InputCollection._bound.length
                )
    );
};


var Tree = { };
var TreeSetup = { };

TreeSetup.canvas = null;
TreeSetup.context = null;
TreeSetup.canvasWidth = null;

TreeSetup.setValues = function (canvas, canvasWidth, context) {
    this.canvas = canvas;
    this.context = context;
    this.canvasWidth = canvasWidth;

    Tree = new TreeDrawer();
}

var TreeDrawer = (function(){
    var _depth   = 15
      , _breadth = 16
      , _rootX   = 500
      , _rootY   = 60
      , _context = TreeSetup.context
      , previousX = 0
      , previousY = 0
      , possibleX = 0
      , possibleY = 0
      , positionY = 0
      ;

    _context.textAlign = "center";
    _context.fillStyle = "black";
    _context.font      = "16px Verdana";

    var _drawText = function(partialText, x, y) {
        console.log("Se desea graficar"+partialText+" en " + x + " y "+y);
        _context.fillText(partialText, x, y);
    };

    var _drawSheet = function(sourceX, sourceY, destinyX, destinyY) {
        _context.moveTo(sourceX, sourceY);
        _context.lineTo(destinyX, destinyY);
        _context.stroke();
        console.log("linea desde (" + sourceX + "," + sourceY + ") hasta (" + destinyX + "," + destinyY + ")" );
    };

    return {
        drawRoot: function (value) {
            _drawText(value, _rootX, _rootY);
            possibleX = _rootX;
            possibleY = _rootY;
        },
        drawNode: function(value, row, position) {
            var stepX = 56;
            var stepY = 56;

            var x = _rootX + (stepX * position);
            var y = _rootY + (stepY * (row-1));

            _drawText(value, x, y);

            if ( row != positionY ) { //no son nodos hermanos.
                previousX = possibleX;
                previousY = possibleY;
            }

            _drawSheet(x, y - 16 , previousX, previousY + 10);

            positionY = row;
            possibleX = x;
            possibleY = y;
        }
    }
});
