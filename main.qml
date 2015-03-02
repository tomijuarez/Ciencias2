import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2
import QtGraphicalEffects 1.0

import "./resources/javascript/utils.js" as Utils;

ApplicationWindow {

    id: item;
    title: "Citröen espacial"
    height: 650
    width:  1000
    visible: true

    Rectangle {
        id: gv_

        width: parent.width
        height: parent.height
        color: "black"

        property bool menu_shown: false

        /* this rectangle contains the "menu" */
        Rectangle {
            id: menu_view_
            anchors.fill: parent
            color: "red";

            Image {
                anchors.fill: parent;
                source: "./resources/images/blur.jpg";
            }

            opacity: gv_.menu_shown ? 1 : 0
            Behavior on opacity { NumberAnimation { duration: 300 } }

            /* this is my sample menu content (TODO: replace with your own)  */

            Rectangle {
                id: capaSuperiorMenu
                width: parent.width
                height: 80

                color: "transparent"//#7c567a"

                anchors {
                    top: parent.top;
                }

                Rectangle {
                    height: parent.height
                    width: 160
                    color: "transparent"
                    anchors {
                        left: parent.left
                        leftMargin: 10
                    }

                    Rectangle {
                        id: botonAbrir
                        color: "transparent"
                        height: 40;
                        width: 150;

                        border.color: "white";
                        radius: 2;

                        anchors {
                            verticalCenter: parent.verticalCenter
                            horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            text: "Abrir archivo";
                            color: "white";
                            font.pixelSize: 17;
                            anchors {
                                verticalCenter: parent.verticalCenter
                                horizontalCenter: parent.horizontalCenter
                            }
                        }
                    }


                    scale: botAbr.pressed ? 1.1 : 1;

                    MouseArea { id: botAbr; anchors.fill: parent; }

                }

                Rectangle {
                    height: parent.height
                    width: 180
                    color: "transparent"

                    anchors {
                        left: parent.left;
                        leftMargin: parent.width/6
                    }

                    Rectangle {
                        id: botonGuardar
                        color: "transparent"
                        height: 40;
                        width: 150;

                        border.color: "white";
                        radius: 2;

                        anchors {
                            verticalCenter: parent.verticalCenter
                            horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            text: "Guardar archivo";
                            color: "white";
                            font.pixelSize: 17;
                            anchors {
                                verticalCenter: parent.verticalCenter
                                horizontalCenter: parent.horizontalCenter
                            }
                        }
                    }

                    scale: botGuar.pressed ? 1.1 : 1;

                    MouseArea { id: botGuar; anchors.fill: parent; }
                }


                Rectangle {
                    height: parent.height
                    width: 160
                    color: "transparent"
                    anchors {
                        left: parent.left
                        leftMargin: 340
                    }

                    Rectangle {
                        id: botonTutorial
                        color: "transparent"
                        height: 40;
                        width: 150;

                        border.color: "white";
                        radius: 2;

                        anchors {
                            verticalCenter: parent.verticalCenter
                            horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            text: "¿Cómo hago?";
                            color: "white";
                            font.pixelSize: 17;
                            anchors {
                                verticalCenter: parent.verticalCenter
                                horizontalCenter: parent.horizontalCenter
                            }
                        }
                    }


                    scale: botTut.pressed ? 1.1 : 1;

                    MouseArea { id: botTut; anchors.fill: parent; }
                }


                Rectangle {
                    height: parent.height
                    width: 160
                    color: "transparent"
                    anchors {
                        left: parent.left
                        leftMargin: 505
                    }

                    Rectangle {
                        id: botonIniciar
                        color: "transparent"
                        height: 40;
                        width: 150;

                        border.color: "white";
                        radius: 2;

                        anchors {
                            verticalCenter: parent.verticalCenter
                            horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            text: "¡Iniciar pruebas!";
                            color: "white";
                            font.pixelSize: 17;
                            anchors {
                                verticalCenter: parent.verticalCenter
                                horizontalCenter: parent.horizontalCenter
                            }
                        }

                    }


                    scale: botInic.pressed ? 1.1 : 1;

                    MouseArea {
                        id: botInic;
                        anchors.fill: parent;
                        onClicked: Utils.Verifier.fullInputs() ? Utils.Events.sendData() : Utils.Error.emptyData();
                    }
                }

                Rectangle {
                    height: parent.height
                    width: 40
                    color: "transparent"
                    anchors {
                        left: parent.left
                        leftMargin: 675
                    }

                    Rectangle {
                        id: botonArbolSimple
                        color: "transparent"
                        height: 40;
                        width: 40;

                        border.color: "white";
                        radius: 2;

                        anchors {
                            verticalCenter: parent.verticalCenter
                            horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            text: "AS";
                            color: "white";
                            font.pixelSize: 17;
                            anchors {
                                verticalCenter: parent.verticalCenter
                                horizontalCenter: parent.horizontalCenter
                            }
                        }

                    }


                    scale: botArb.pressed ? 1.1 : 1;

                    MouseArea {
                        id: botArb;
                        anchors.fill: parent;
                        onClicked: Utils.Verifier.fullInputs() ? Utils.Events.sendData() : Utils.Error.emptyData();
                    }
                }

                Rectangle {
                    height: parent.height
                    width: 40
                    color: "transparent"
                    anchors {
                        left: parent.left
                        leftMargin: 730
                    }

                    Rectangle {
                        id: botonSimplificacion
                        color: "transparent"
                        height: 40;
                        width: 40;

                        border.color: "white";
                        radius: 2;

                        anchors {
                            verticalCenter: parent.verticalCenter
                            horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            text: "SM";
                            color: "white";
                            font.pixelSize: 17;
                            anchors {
                                verticalCenter: parent.verticalCenter
                                horizontalCenter: parent.horizontalCenter
                            }
                        }

                    }


                    scale: botSimpl.pressed ? 1.1 : 1;

                    MouseArea {
                        id: botSimpl;
                        anchors.fill: parent;
                        onClicked: Utils.Verifier.fullInputs() ? Utils.Events.sendData() : Utils.Error.emptyData();
                    }
                }


                Rectangle {
                    height: parent.height
                    width: 40
                    color: "transparent"
                    anchors {
                        left: parent.left
                        leftMargin: 785
                    }

                    Rectangle {
                        id: botonVerificacion
                        color: "transparent"
                        height: 40;
                        width: 40;

                        border.color: "white";
                        radius: 2;

                        anchors {
                            verticalCenter: parent.verticalCenter
                            horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            text: "VP";
                            color: "white";
                            font.pixelSize: 17;
                            anchors {
                                verticalCenter: parent.verticalCenter
                                horizontalCenter: parent.horizontalCenter
                            }
                        }

                    }


                    scale: botver.pressed ? 1.1 : 1;

                    MouseArea {
                        id: botver;
                        anchors.fill: parent;
                        onClicked: Utils.Verifier.fullInputs() ? Utils.Events.sendData() : Utils.Error.emptyData();
                    }
                }


            } /**FIN BOTONES**/




            Rectangle {
                width: parent.width
                height: 700

                color: "transparent";

                anchors {
                    top: parent.top;
                    topMargin: 80;
                }


                ListView {

                    anchors { fill: parent; }
                    model: 5
                    delegate: Rectangle {

                        height: Utils.GUI.rectangleContainerSize(index);
                        width: parent.width;
                        color: "transparent"

                        Rectangle {

                            Rectangle {
                                width: 850;
                                height: 30;
                                color: "transparent";
                                anchors {
                                    left: parent.left;
                                    top: parent.top;
                                    topMargin: 10;
                                    leftMargin: 11;
                                }
                                Text {
                                    text: Utils.GUI.assignLabel(index);
                                    font.pixelSize: 19;
                                    font.family: "Verdana";
                                    color: "white";
                                }
                            }

                            Rectangle {
                                height: Utils.GUI.textAreaSize(index);
                                width: 850;
                                color: "transparent"

                                anchors {
                                    left: parent.left;
                                    top: parent.top;
                                    topMargin: 40;
                                    leftMargin: 12;
                                }


                                TextArea {
                                    height: Utils.GUI.textAreaSize(index);
                                    anchors.fill: parent
                                    anchors.margins: 3
                                    objectName: Utils.InputCollection.getId(index, this);

                                    style: TextAreaStyle {
                                        textColor: "white"
                                        selectionColor: "#9b59b6"
                                        selectedTextColor: "white"
                                        __stickyScrollbars: false;
                                        backgroundColor: "black";
                                    }

                                    opacity: 0.3;

                                    focus: true
                                    selectByMouse: true
                                    font.pixelSize: 20;

                                    onFocusChanged: Utils.GUI.cleanInputErrorState(this,index+1);
                                    onActiveFocusChanged: Utils.GUI.cleanInputErrorState(this,index+1);
                                    onActiveFocusOnPressChanged: Utils.GUI.cleanInputErrorState(this,index+1);
                                    onActiveFocusOnTabChanged: Utils.GUI.cleanInputErrorState(this,index+1);

                                }/*END -> TEXTAREA*/
                            }

                        } /*END -> COLUMN LAYOUT.*/
                    }
                }


            }
        }

        /* this rectangle contains the "normal" view in your app */
        Rectangle {
            id: normal_view_
            anchors.fill: parent

            /* this is what moves the normal view aside */
            transform: Translate {
                id: game_translate_
                x: 0
                Behavior on x { NumberAnimation { duration: 400; easing.type: Easing.OutQuad } }
            }

            /* Menu shadow */
            BorderImage {
                id: menu_shadow_
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.margins: -10
                z: -1 /* this will place it below normal_view_ */
                visible: gv_.menu_shown
                source: "./resources/images/shadow.png"
                border { left: 12; top: 12; right: 12; bottom: 12 }
            }

            Rectangle {
                id: menu_bar_
                anchors.top: parent.top
                width: parent.width;
                height: 50;
                color: "#f17c72"

                Rectangle {
                    id: menu_button_
                    anchors {
                        left: parent.left;
                        verticalCenter: parent.verticalCenter;
                        margins: 24
                    }
                    color: "transparent";
                    width: 30;
                    height: 30;
                    radius:3;
                    scale: ma_.pressed ? 1.2 : 1

                    Image {
                        anchors.fill: parent;
                        source: "./resources/images/menu.png";
                    }

                    MouseArea { id: ma_; anchors.fill: parent; onClicked: gv_.onMenu();  }
                }


                Rectangle {
                    /*Para los dos botones.*/
                    width: 300;
                    height: parent.height;
                    color: "transparent";
                    anchors {
                        right: parent.right
                    }

                    Rectangle {
                        color: "transparent";
                        height: 50;
                        width: 100;
                        anchors {
                            left: parent.left;
                            leftMargin: 25;
                        }

                        Rectangle {
                            id: anterior;
                            height: 30;
                            width: parent.width;
                            color: "transparent";
                            objectName: "prevTrigger";
                            radius: 3;
                            border.color: "white";

                            scale: efAnt.pressed ? 1.1 : 1;

                            anchors.centerIn: parent;

                            Text {
                                font.pixelSize: 16;
                                anchors.centerIn: parent;
                                color: "white";
                                text:  "Anterior"
                            }

                        }


                        MouseArea { id: efAnt; anchors.fill: parent; /*HACER ALGO.*/ }
                    }

                    Rectangle {
                        id: siguiente;
                        color: "transparent";
                        height: 50;
                        width: 100;
                        scale: efSig.pressed ? 1.1 : 1;
                        anchors {
                            left: parent.left;
                            leftMargin: 130;
                        }

                        Rectangle {
                            height: 30;
                            width: parent.width;
                            color: "transparent";
                            border.color: "white";
                            radius: 3;

                            anchors.centerIn: parent;
                            scale: efSig.pressed ? 1.1 : 1;
                            objectName: "nextTrigger";
                            signal _nextTest();

                            Text {
                                font.pixelSize: 16;
                                anchors.centerIn: parent;
                                color: "white";
                                text:  "Siguiente"
                            }
                        }

                        MouseArea { id: efSig; anchors.fill: parent; /*HACER ALGO.*/ }

                    }

                }

            }



            Canvas {
                height: 550;
                anchors.bottom: parent.bottom;
                width: parent.width;
                id: _canvas;

                Component.onCompleted: {
                    Utils.TreeSetup.setValues(_canvas, _canvas.width, getContext("2d"));
                }
            }

            /* put this last to "steal" touch on the normal window when menu is shown */
            MouseArea {
                anchors.fill: parent
                enabled: gv_.menu_shown
                onClicked: gv_.onMenu();
            }
        }

        /* this functions toggles the menu and starts the animation */
        function onMenu()
        {
            game_translate_.x = gv_.menu_shown ? 0 : gv_.width * 0.9
            gv_.menu_shown = !gv_.menu_shown;
        }
    }

    Connections {
        property int index: 0
        target: eventsManager;
        onNode: {
            _canvas.requestPaint();
            if ( index == 0 )
                Utils.Tree.drawRoot(formula);
            else
                Utils.Tree.drawNode(formula, y, x);
            index++;
        }
    }
}
