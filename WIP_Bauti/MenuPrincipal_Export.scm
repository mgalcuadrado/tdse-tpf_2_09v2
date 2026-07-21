{
  "graph": {
    "cells": [
      {
        "position": {
          "x": 0,
          "y": 0
        },
        "size": {
          "height": 10,
          "width": 10
        },
        "type": "Statechart",
        "id": "_Ug9EoIIhEfGOTMWB8C9Phg",
        "attrs": {
          "name": {
            "text": "MenuPrincipal Export"
          },
          "specification": {
            "text": "// Use the event driven execution model.\n// Switch to cycle based behavior\n// by specifying '@CycleBased(200)'.\n@EventDriven\n\n// Use @SuperSteps(yes) to enable\n// super step semantics.\n@SuperSteps(no)\r\n\n\ninterface:\n\tvar tipo_pincel: integer\n\tvar save_slot: integer\n\tvar load_slot: integer\n\t\n\t// Botones Aceptar - Retroceder\n\tin event boton1rojo\n\tin event boton2negro\n\t\n\t// Botones Rojos WASD para moverse\n\tin event boton_w\n\tin event boton_a\n\tin event boton_d\n\tin event boton_s\n\t \n"
          }
        },
        "z": 0
      },
      {
        "position": {
          "x": 10,
          "y": 226
        },
        "size": {
          "width": 2633,
          "height": 1907
        },
        "type": "Region",
        "attrs": {
          "priority": {
            "text": 1
          },
          "name": {
            "text": "Menu"
          }
        },
        "embeds": [
          "_I0k7QIJcEfGOTMWB8C9Phg",
          "_QCcP0IO_EfGtx6X-y8aBtw",
          "_Ug9rvIIhEfGOTMWB8C9Phg",
          "_x2IAIIInEfGOTMWB8C9Phg",
          "_1J4FUIImEfGOTMWB8C9Phg",
          "_Y60DAIIwEfGOTMWB8C9Phg",
          "_43wewIJGEfGOTMWB8C9Phg",
          "_JT5hEIJHEfGOTMWB8C9Phg",
          "_pf7jsIJHEfGOTMWB8C9Phg",
          "_hdYRQIJBEfGOTMWB8C9Phg",
          "_emvbUIJBEfGOTMWB8C9Phg",
          "_wiOwgIJBEfGOTMWB8C9Phg",
          "_B7Eu0IJGEfGOTMWB8C9Phg",
          "_omajwIIxEfGOTMWB8C9Phg",
          "_CVPkgIJVEfGOTMWB8C9Phg",
          "_O-TWwIJVEfGOTMWB8C9Phg",
          "_no_kUIJUEfGOTMWB8C9Phg",
          "_GAhUsIJbEfGOTMWB8C9Phg",
          "_-Vgg4IJGEfGOTMWB8C9Phg",
          "_H-KdMIJHEfGOTMWB8C9Phg",
          "_Kq_P0IJHEfGOTMWB8C9Phg",
          "_WQFOMIJIEfGOTMWB8C9Phg",
          "_yeFQ0IJPEfGOTMWB8C9Phg",
          "_a896cIJQEfGOTMWB8C9Phg",
          "_d_iTkIJQEfGOTMWB8C9Phg",
          "_Ye1EEIJQEfGOTMWB8C9Phg",
          "_iTvTsIJQEfGOTMWB8C9Phg",
          "_ag7sQIIwEfGOTMWB8C9Phg",
          "_-d__cIJPEfGOTMWB8C9Phg",
          "_TxwQ8IJQEfGOTMWB8C9Phg"
        ],
        "id": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1
      },
      {
        "position": {
          "x": 72,
          "y": 401
        },
        "size": {
          "height": 15,
          "width": 15
        },
        "type": "Entry",
        "entryKind": "Initial",
        "attrs": {},
        "embeds": [
          "_ehE5MISnEfG0gtUZw0t-iA"
        ],
        "id": "_Ug9rvIIhEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 2
      },
      {
        "position": {
          "x": 34,
          "y": 573
        },
        "size": {
          "width": 836,
          "height": 994
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Menu",
            "fontSize": 11
          }
        },
        "embeds": [
          "_1J4FU4ImEfGOTMWB8C9Phg"
        ],
        "id": "_1J4FUIImEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 2
      },
      {
        "position": {
          "x": 1949,
          "y": 565
        },
        "size": {
          "width": 647,
          "height": 591
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujo",
            "fontSize": 11
          }
        },
        "embeds": [
          "_emvbU4JBEfGOTMWB8C9Phg"
        ],
        "id": "_emvbUIJBEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 2
      },
      {
        "position": {
          "x": 1513,
          "y": 647
        },
        "size": {
          "width": 349,
          "height": 509
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujos Guardados",
            "fontSize": 11
          }
        },
        "embeds": [
          "_B7FV4IJGEfGOTMWB8C9Phg"
        ],
        "id": "_B7Eu0IJGEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 2
      },
      {
        "position": {
          "x": 96,
          "y": 1798
        },
        "size": {
          "height": 291,
          "width": 417
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Secuencia",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_H-KdMIJHEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 2
      },
      {
        "position": {
          "x": 877,
          "y": 663
        },
        "size": {
          "width": 299,
          "height": 523
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Guardado Dibujos",
            "fontSize": 11
          }
        },
        "embeds": [
          "_WQF1QIJIEfGOTMWB8C9Phg"
        ],
        "id": "_WQFOMIJIEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 2
      },
      {
        "position": {
          "x": 1310,
          "y": 813
        },
        "size": {
          "height": 109,
          "width": 181
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Guardado",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_-d__cIJPEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 2
      },
      {
        "position": {
          "x": 37,
          "y": 618
        },
        "size": {
          "width": 830,
          "height": 946
        },
        "type": "Region",
        "attrs": {
          "priority": {
            "text": 1
          },
          "name": {
            "text": "r1"
          }
        },
        "embeds": [
          "_DqAt8IInEfGOTMWB8C9Phg",
          "_GlWrcIIsEfGOTMWB8C9Phg",
          "_aAkq0IIoEfGOTMWB8C9Phg",
          "_LpdwcIIqEfGOTMWB8C9Phg",
          "_2WJHUIIqEfGOTMWB8C9Phg",
          "_XQmZYIIvEfGOTMWB8C9Phg",
          "_EJxEsIIqEfGOTMWB8C9Phg",
          "_KryAMIIqEfGOTMWB8C9Phg",
          "_wBiDwIIsEfGOTMWB8C9Phg",
          "_MkWZcIIsEfGOTMWB8C9Phg",
          "_dpwbMIIsEfGOTMWB8C9Phg",
          "_8aj08II3EfGOTMWB8C9Phg",
          "_bSV34IIsEfGOTMWB8C9Phg",
          "_fkwIQIIsEfGOTMWB8C9Phg",
          "_qeyM4IIsEfGOTMWB8C9Phg",
          "_16ATAIIsEfGOTMWB8C9Phg",
          "_4nl6oIIsEfGOTMWB8C9Phg",
          "_2FmNEIIuEfGOTMWB8C9Phg",
          "_9I6JsIIsEfGOTMWB8C9Phg",
          "_Da3TEIL1EfGDZZFhttciyw",
          "_l_6y4IJCEfGOTMWB8C9Phg",
          "_ydK9wIJCEfGOTMWB8C9Phg",
          "_OL9wIIIvEfGOTMWB8C9Phg",
          "_WiQYzYJHEfGOTMWB8C9Phg",
          "_WiQY0IJHEfGOTMWB8C9Phg",
          "_WiQY3oJHEfGOTMWB8C9Phg",
          "_WiQY8IJHEfGOTMWB8C9Phg",
          "_WiQY_oJHEfGOTMWB8C9Phg",
          "_0_eLEIL1EfGDZZFhttciyw",
          "_e6Av0IL1EfGDZZFhttciyw",
          "_kxqfsIL1EfGDZZFhttciyw",
          "_sRRcMIJCEfGOTMWB8C9Phg",
          "_fz48MIJHEfGOTMWB8C9Phg"
        ],
        "id": "_1J4FU4ImEfGOTMWB8C9Phg",
        "parent": "_1J4FUIImEfGOTMWB8C9Phg",
        "z": 3
      },
      {
        "position": {
          "x": 1952,
          "y": 610
        },
        "size": {
          "width": 641,
          "height": 543
        },
        "type": "Region",
        "attrs": {
          "priority": {
            "text": 1
          },
          "name": {
            "text": "r1"
          }
        },
        "embeds": [
          "_tDRWMIPJEfGtx6X-y8aBtw",
          "_p3NYEIJDEfGOTMWB8C9Phg",
          "_rmiAoIJDEfGOTMWB8C9Phg",
          "_qTedUIJDEfGOTMWB8C9Phg",
          "_0gPNIIPAEfGtx6X-y8aBtw",
          "_9vCfAIPAEfGtx6X-y8aBtw",
          "_Fts-sIPBEfGtx6X-y8aBtw",
          "_TKzdAIPBEfGtx6X-y8aBtw",
          "_Ykb0IIPBEfGtx6X-y8aBtw",
          "_wJOwoIPAEfGtx6X-y8aBtw",
          "_3zMLoIPAEfGtx6X-y8aBtw",
          "_5VuVYIPAEfGtx6X-y8aBtw",
          "_-9tRkIPAEfGtx6X-y8aBtw",
          "_AuujQIPBEfGtx6X-y8aBtw",
          "_G9Yd4IPBEfGtx6X-y8aBtw",
          "_QsnjUIPBEfGtx6X-y8aBtw",
          "_UMotcIPBEfGtx6X-y8aBtw",
          "_Wb72kIPBEfGtx6X-y8aBtw"
        ],
        "id": "_emvbU4JBEfGOTMWB8C9Phg",
        "parent": "_emvbUIJBEfGOTMWB8C9Phg",
        "z": 3
      },
      {
        "position": {
          "x": 1516,
          "y": 692
        },
        "size": {
          "width": 343,
          "height": 461
        },
        "type": "Region",
        "attrs": {
          "priority": {
            "text": 1
          },
          "name": {
            "text": "r1"
          }
        },
        "embeds": [
          "_E_1gUIJGEfGOTMWB8C9Phg",
          "_E_1gUYJGEfGOTMWB8C9Phg",
          "_E_1gUoJGEfGOTMWB8C9Phg",
          "_E_1gWYJGEfGOTMWB8C9Phg",
          "_USvCoIJGEfGOTMWB8C9Phg",
          "_E_1gXYJGEfGOTMWB8C9Phg",
          "_E_1gYIJGEfGOTMWB8C9Phg",
          "_E_1gZIJGEfGOTMWB8C9Phg",
          "_E_1gaIJGEfGOTMWB8C9Phg",
          "_E_1ga4JGEfGOTMWB8C9Phg",
          "_PPlR0IJGEfGOTMWB8C9Phg",
          "_E_1gc4JGEfGOTMWB8C9Phg",
          "_E_1gdoJGEfGOTMWB8C9Phg",
          "_E_1geoJGEfGOTMWB8C9Phg",
          "_JKLZ0IJGEfGOTMWB8C9Phg",
          "_LchP4IJGEfGOTMWB8C9Phg",
          "_SFH7kIJGEfGOTMWB8C9Phg"
        ],
        "id": "_B7FV4IJGEfGOTMWB8C9Phg",
        "parent": "_B7Eu0IJGEfGOTMWB8C9Phg",
        "z": 3
      },
      {
        "position": {
          "x": 880,
          "y": 708
        },
        "size": {
          "width": 293,
          "height": 475
        },
        "type": "Region",
        "attrs": {
          "priority": {
            "text": 1
          },
          "name": {
            "text": "r1"
          }
        },
        "embeds": [
          "_XxsyIIJIEfGOTMWB8C9Phg",
          "_XxsyIYJIEfGOTMWB8C9Phg",
          "_XxsyIoJIEfGOTMWB8C9Phg",
          "_XxsyJYJIEfGOTMWB8C9Phg",
          "_XxsyKYJIEfGOTMWB8C9Phg",
          "_XxsyLYJIEfGOTMWB8C9Phg",
          "_XxtZAoJIEfGOTMWB8C9Phg",
          "_XxtZBoJIEfGOTMWB8C9Phg",
          "_XxtZCoJIEfGOTMWB8C9Phg",
          "_XxtZDYJIEfGOTMWB8C9Phg",
          "_XxtZEYJIEfGOTMWB8C9Phg",
          "_XxtZFYJIEfGOTMWB8C9Phg",
          "_XxtZGIJIEfGOTMWB8C9Phg",
          "_XxtZHIJIEfGOTMWB8C9Phg",
          "_XxtZIIJIEfGOTMWB8C9Phg",
          "_XxtZI4JIEfGOTMWB8C9Phg",
          "_XxtZJ4JIEfGOTMWB8C9Phg"
        ],
        "id": "_WQF1QIJIEfGOTMWB8C9Phg",
        "parent": "_WQFOMIJIEfGOTMWB8C9Phg",
        "z": 3
      },
      {
        "position": {
          "x": 86,
          "y": 666
        },
        "size": {
          "height": 15,
          "width": 15
        },
        "type": "Entry",
        "entryKind": "ShallowHistory",
        "attrs": {},
        "embeds": [
          "_ehJKoISnEfG0gtUZw0t-iA"
        ],
        "id": "_DqAt8IInEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 168,
          "y": 690
        },
        "size": {
          "height": 77,
          "width": 205
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Limpiar Tablero",
            "fontSize": 11
          },
          "specification": {
            "text": "entry / tipo_pincel = 0"
          }
        },
        "embeds": [],
        "id": "_aAkq0IIoEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 222,
          "y": 816
        },
        "size": {
          "height": 53,
          "width": 118
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Guardar Dibujo",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_EJxEsIIqEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 497,
          "y": 666
        },
        "size": {
          "height": 59,
          "width": 105
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Are you sure?",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_MkWZcIIsEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 509,
          "y": 735
        },
        "size": {
          "height": 62,
          "width": 89
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Borrado",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_bSV34IIsEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 223,
          "y": 924
        },
        "size": {
          "height": 60,
          "width": 116
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Cargar dibujo",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_qeyM4IIsEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 220,
          "y": 1051
        },
        "size": {
          "height": 73,
          "width": 121
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Nuevo Dibujo",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_2FmNEIIuEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 210,
          "y": 1456
        },
        "size": {
          "height": 75,
          "width": 120
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Modo Secuencia",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_l_6y4IJCEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 655,
          "y": 1355
        },
        "size": {
          "height": 53,
          "width": 160
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Tipo de Pencil",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_WiQYzYJHEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 205,
          "y": 1230
        },
        "size": {
          "height": 76,
          "width": 130
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Cambiar Pincel",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_e6Av0IL1EfGDZZFhttciyw",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 2010,
          "y": 661
        },
        "size": {
          "height": 15,
          "width": 15
        },
        "type": "Entry",
        "entryKind": "Initial",
        "attrs": {},
        "embeds": [
          "_ehdTsISnEfG0gtUZw0t-iA"
        ],
        "id": "_p3NYEIJDEfGOTMWB8C9Phg",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 2206,
          "y": 813
        },
        "size": {
          "height": 61,
          "width": 105
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dwg",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_qTedUIJDEfGOTMWB8C9Phg",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 1965,
          "y": 812
        },
        "size": {
          "height": 60,
          "width": 163
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Avanzar(Izquierda)",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_wJOwoIPAEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 2199,
          "y": 972
        },
        "size": {
          "height": 53,
          "width": 119
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Avanzar(Abajo)",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_5VuVYIPAEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 2406,
          "y": 813
        },
        "size": {
          "height": 58,
          "width": 135
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Avanzar(Derecha)",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_AuujQIPBEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 2199,
          "y": 685
        },
        "size": {
          "height": 69,
          "width": 118
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Avanzar(Subir)",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_QsnjUIPBEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 1987,
          "y": 984
        },
        "size": {
          "height": 70,
          "width": 146
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Seleccionar Tesela",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_Wb72kIPBEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 1528,
          "y": 722
        },
        "size": {
          "height": 15,
          "width": 15
        },
        "type": "Entry",
        "entryKind": "Initial",
        "attrs": {},
        "embeds": [
          "_ehmdoISnEfG0gtUZw0t-iA"
        ],
        "id": "_E_1gUIJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 1606,
          "y": 722
        },
        "size": {
          "height": 53,
          "width": 115
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujo 1",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_E_1gUoJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 1605,
          "y": 894
        },
        "size": {
          "height": 53,
          "width": 113
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujo 3",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_E_1gXYJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 1604,
          "y": 982
        },
        "size": {
          "height": 53,
          "width": 114
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujo 4",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_E_1gaIJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 1605,
          "y": 803
        },
        "size": {
          "height": 44,
          "width": 109
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujo 2",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_E_1gc4JGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 1605,
          "y": 1076
        },
        "size": {
          "height": 52,
          "width": 112
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujo 5",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_JKLZ0IJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 903,
          "y": 748
        },
        "size": {
          "height": 15,
          "width": 15
        },
        "type": "Entry",
        "entryKind": "Initial",
        "attrs": {},
        "embeds": [
          "_ehyq4ISnEfG0gtUZw0t-iA"
        ],
        "id": "_XxsyIIJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 977,
          "y": 748
        },
        "size": {
          "height": 53,
          "width": 115
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujo 1",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_XxsyIoJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 976,
          "y": 920
        },
        "size": {
          "height": 53,
          "width": 113
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujo 3",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_XxsyLYJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 975,
          "y": 1008
        },
        "size": {
          "height": 53,
          "width": 114
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujo 4",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_XxtZCoJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 976,
          "y": 829
        },
        "size": {
          "height": 53,
          "width": 109
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujo 2",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_XxtZFYJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "position": {
          "x": 979,
          "y": 1102
        },
        "size": {
          "height": 52,
          "width": 112
        },
        "type": "State",
        "attrs": {
          "name": {
            "text": "Dibujo 5",
            "fontSize": 11
          }
        },
        "embeds": [],
        "id": "_XxtZIIJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 4
      },
      {
        "type": "Note",
        "attrs": {
          "root": {
            "display": ""
          },
          "body": {
            "filter": {
              "args": {}
            }
          },
          "label": {
            "text": "Se piensa tipo_pincel como un exponente:\r\n\r\n2^0 / 2^1 / 2^2 / 2 ^ (tipo_pincel) * 2 ^ (tipo_pincel) de teselas"
          }
        },
        "position": {
          "x": 893,
          "y": 1462
        },
        "size": {
          "width": 443,
          "height": 74
        },
        "angle": 0,
        "linkable": false,
        "id": "_I0k7QIJcEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 900
      },
      {
        "type": "Note",
        "attrs": {
          "root": {
            "display": ""
          },
          "body": {
            "filter": {
              "args": {}
            }
          },
          "label": {
            "text": "Pincel Fijo en Modo Secuencia"
          }
        },
        "position": {
          "x": 343,
          "y": 1699
        },
        "size": {
          "width": 213,
          "height": 74
        },
        "angle": 0,
        "linkable": false,
        "id": "_QCcP0IO_EfGtx6X-y8aBtw",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 900
      },
      {
        "type": "Note",
        "attrs": {
          "root": {
            "display": ""
          },
          "body": {
            "filter": {
              "args": {}
            }
          },
          "label": {
            "text": "No hay menu de esto, es para visualizar"
          }
        },
        "position": {
          "x": 2352,
          "y": 675
        },
        "size": {
          "width": 122,
          "height": 71
        },
        "angle": 0,
        "linkable": false,
        "id": "_tDRWMIPJEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 900
      },
      {
        "type": "NodeLabel",
        "label": true,
        "size": {
          "width": 15,
          "height": 15
        },
        "position": {
          "x": 72,
          "y": 423
        },
        "attrs": {},
        "id": "_ehE5MISnEfG0gtUZw0t-iA",
        "parent": "_Ug9rvIIhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_Ug9rvIIhEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_1J4FUIImEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {},
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_x2IAIIInEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "NodeLabel",
        "label": true,
        "size": {
          "width": 15,
          "height": 15
        },
        "position": {
          "x": 86,
          "y": 688
        },
        "attrs": {
          "label": {
            "refX": "50%",
            "textAnchor": "middle",
            "refY": 0,
            "textVerticalAnchor": "top"
          }
        },
        "id": "_ehJKoISnEfG0gtUZw0t-iA",
        "parent": "_DqAt8IInEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_DqAt8IInEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_aAkq0IIoEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {},
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_GlWrcIIsEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_aAkq0IIoEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_EJxEsIIqEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_LpdwcIIqEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_aAkq0IIoEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_MkWZcIIsEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_2WJHUIIqEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_aAkq0IIoEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_l_6y4IJCEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XQmZYIIvEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_EJxEsIIqEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_aAkq0IIoEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_KryAMIIqEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_EJxEsIIqEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_qeyM4IIsEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_wBiDwIIsEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_EJxEsIIqEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_WQFOMIJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_Y60DAIIwEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_MkWZcIIsEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_bSV34IIsEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_dpwbMIIsEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_MkWZcIIsEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_aAkq0IIoEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton2negro"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_8aj08II3EfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_bSV34IIsEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_aAkq0IIoEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {},
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_fkwIQIIsEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_qeyM4IIsEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_EJxEsIIqEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_16ATAIIsEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_qeyM4IIsEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_2FmNEIIuEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_4nl6oIIsEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_qeyM4IIsEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_B7Eu0IJGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_43wewIJGEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_2FmNEIIuEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_qeyM4IIsEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_9I6JsIIsEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_2FmNEIIuEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_e6Av0IL1EfGDZZFhttciyw"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_Da3TEIL1EfGDZZFhttciyw",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_l_6y4IJCEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_e6Av0IL1EfGDZZFhttciyw"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_ydK9wIJCEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_l_6y4IJCEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_aAkq0IIoEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_OL9wIIIvEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_l_6y4IJCEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_H-KdMIJHEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_JT5hEIJHEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_WiQYzYJHEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_WiQYzYJHEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w [tipo_pincel < 2] / tipo_pincel += 1"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_WiQY0IJHEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_WiQYzYJHEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_WiQYzYJHEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w [tipo_pincel >=2] / tipo_pincel = 0"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_WiQY3oJHEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_WiQYzYJHEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_WiQYzYJHEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s [tipo_pincel <= 0] / tipo_pincel = 2"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_WiQY8IJHEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_WiQYzYJHEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_WiQYzYJHEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s [tipo_pincel > 0] / tipo_pincel -= 1"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 4
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_WiQY_oJHEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_WiQYzYJHEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_emvbUIJBEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 5
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_pf7jsIJHEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_WiQYzYJHEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_e6Av0IL1EfGDZZFhttciyw"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton2negro"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 6
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_0_eLEIL1EfGDZZFhttciyw",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_e6Av0IL1EfGDZZFhttciyw"
        },
        "target": {
          "id": "_2FmNEIIuEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_kxqfsIL1EfGDZZFhttciyw",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_e6Av0IL1EfGDZZFhttciyw"
        },
        "target": {
          "id": "_l_6y4IJCEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_sRRcMIJCEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_e6Av0IL1EfGDZZFhttciyw"
        },
        "target": {
          "id": "_WiQYzYJHEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_fz48MIJHEfGOTMWB8C9Phg",
        "parent": "_1J4FU4ImEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_1J4FUIImEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_emvbUIJBEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton2negro"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_hdYRQIJBEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "NodeLabel",
        "label": true,
        "size": {
          "width": 15,
          "height": 15
        },
        "position": {
          "x": 2010,
          "y": 683
        },
        "attrs": {
          "label": {
            "refX": "50%",
            "textAnchor": "middle",
            "refY": 0,
            "textVerticalAnchor": "top"
          }
        },
        "id": "_ehdTsISnEfG0gtUZw0t-iA",
        "parent": "_p3NYEIJDEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_p3NYEIJDEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_qTedUIJDEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {},
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_rmiAoIJDEfGOTMWB8C9Phg",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_qTedUIJDEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_wJOwoIPAEfGtx6X-y8aBtw"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_a"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_0gPNIIPAEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_qTedUIJDEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_5VuVYIPAEfGtx6X-y8aBtw"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_9vCfAIPAEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_qTedUIJDEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_AuujQIPBEfGtx6X-y8aBtw"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_d"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_Fts-sIPBEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_qTedUIJDEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_QsnjUIPBEfGtx6X-y8aBtw"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 4
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_TKzdAIPBEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_qTedUIJDEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_Wb72kIPBEfGtx6X-y8aBtw"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 5
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_Ykb0IIPBEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_wJOwoIPAEfGtx6X-y8aBtw"
        },
        "target": {
          "id": "_qTedUIJDEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {},
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_3zMLoIPAEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_5VuVYIPAEfGtx6X-y8aBtw"
        },
        "target": {
          "id": "_qTedUIJDEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {},
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_-9tRkIPAEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_AuujQIPBEfGtx6X-y8aBtw"
        },
        "target": {
          "id": "_qTedUIJDEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {},
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_G9Yd4IPBEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_QsnjUIPBEfGtx6X-y8aBtw"
        },
        "target": {
          "id": "_qTedUIJDEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {},
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_UMotcIPBEfGtx6X-y8aBtw",
        "parent": "_emvbU4JBEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_emvbUIJBEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_1J4FUIImEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton2negro"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_wiOwgIJBEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "NodeLabel",
        "label": true,
        "size": {
          "width": 15,
          "height": 15
        },
        "position": {
          "x": 1528,
          "y": 744
        },
        "attrs": {
          "label": {
            "refX": "50%",
            "textAnchor": "middle",
            "refY": 0,
            "textVerticalAnchor": "top"
          }
        },
        "id": "_ehmdoISnEfG0gtUZw0t-iA",
        "parent": "_E_1gUIJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gUIJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_E_1gUoJGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {},
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_E_1gUYJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gUoJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_E_1gc4JGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_E_1gWYJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gUoJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_JKLZ0IJGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_USvCoIJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gUoJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_emvbUIJBEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo / load_slot = 1"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_omajwIIxEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gXYJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_E_1gaIJGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_E_1gYIJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gXYJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_E_1gc4JGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_E_1gZIJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gXYJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_emvbUIJBEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo / load_slot = 3"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_CVPkgIJVEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gaIJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_E_1gXYJGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_E_1ga4JGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gaIJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_JKLZ0IJGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_PPlR0IJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gaIJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_emvbUIJBEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo / load_slot = 4"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_O-TWwIJVEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gc4JGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_E_1gUoJGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_E_1gdoJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gc4JGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_E_1gXYJGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_E_1geoJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_E_1gc4JGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_emvbUIJBEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo / load_slot = 2"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_no_kUIJUEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_JKLZ0IJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_E_1gaIJGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_LchP4IJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_JKLZ0IJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_E_1gUoJGEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_SFH7kIJGEfGOTMWB8C9Phg",
        "parent": "_B7FV4IJGEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_JKLZ0IJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_emvbUIJBEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo / load_slot = 5"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_GAhUsIJbEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_B7Eu0IJGEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_1J4FUIImEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton2negro"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_-Vgg4IJGEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_H-KdMIJHEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_1J4FUIImEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton2negro"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_Kq_P0IJHEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "NodeLabel",
        "label": true,
        "size": {
          "width": 15,
          "height": 15
        },
        "position": {
          "x": 903,
          "y": 770
        },
        "attrs": {
          "label": {
            "refX": "50%",
            "textAnchor": "middle",
            "refY": 0,
            "textVerticalAnchor": "top"
          }
        },
        "id": "_ehyq4ISnEfG0gtUZw0t-iA",
        "parent": "_XxsyIIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxsyIIJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_XxsyIoJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {},
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XxsyIYJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxsyIoJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_XxtZFYJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XxsyJYJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxsyIoJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_XxtZIIJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XxsyKYJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxsyIoJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_-d__cIJPEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo / save_slot = 1"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_yeFQ0IJPEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxsyLYJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_XxtZCoJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XxtZAoJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxsyLYJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_XxtZFYJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XxtZBoJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxsyLYJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_-d__cIJPEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo / save_slot = 3"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_a896cIJQEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxtZCoJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_XxsyLYJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XxtZDYJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxtZCoJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_XxtZIIJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XxtZEYJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxtZCoJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_-d__cIJPEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo / save_slot = 4"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_d_iTkIJQEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxtZFYJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_XxsyIoJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XxtZGIJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxtZFYJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_XxsyLYJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XxtZHIJIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxtZFYJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_-d__cIJPEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo / save_slot = 2"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_Ye1EEIJQEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxtZIIJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_XxtZCoJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_w"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XxtZI4JIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxtZIIJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_XxsyIoJIEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton_s"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 2
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_XxtZJ4JIEfGOTMWB8C9Phg",
        "parent": "_WQF1QIJIEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_XxtZIIJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_-d__cIJPEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton1rojo / save_slot = 5"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 3
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_iTvTsIJQEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_WQFOMIJIEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_EJxEsIIqEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {
              "text": {
                "text": "boton2negro"
              }
            },
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_ag7sQIIwEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      },
      {
        "type": "Transition",
        "attrs": {},
        "source": {
          "id": "_-d__cIJPEfGOTMWB8C9Phg"
        },
        "target": {
          "id": "_1J4FUIImEfGOTMWB8C9Phg"
        },
        "connector": {
          "name": "rounded"
        },
        "labels": [
          {
            "attrs": {},
            "position": {}
          },
          {
            "attrs": {
              "label": {
                "text": 1
              }
            }
          },
          {
            "attrs": {}
          },
          {
            "attrs": {}
          }
        ],
        "router": {
          "name": "orthogonal"
        },
        "vertices": [],
        "id": "_TxwQ8IJQEfGOTMWB8C9Phg",
        "parent": "_Ug9ru4IhEfGOTMWB8C9Phg",
        "z": 1000
      }
    ]
  },
  "genModel": {
    "generator": {
      "type": "create::c",
      "features": {
        "Outlet": {
          "targetProject": "",
          "targetFolder": "",
          "libraryTargetFolder": "",
          "skipLibraryFiles": "",
          "apiTargetFolder": ""
        },
        "LicenseHeader": {
          "licenseText": ""
        },
        "FunctionInlining": {
          "inlineReactions": false,
          "inlineEntryActions": false,
          "inlineExitActions": false,
          "inlineEnterSequences": false,
          "inlineExitSequences": false,
          "inlineChoices": false,
          "inlineEnterRegion": false,
          "inlineExitRegion": false,
          "inlineEntries": false
        },
        "OutEventAPI": {
          "observables": false,
          "getters": false
        },
        "IdentifierSettings": {
          "moduleName": "ModoSecuencia",
          "statemachinePrefix": "modoSecuencia",
          "separator": "_",
          "headerFilenameExtension": "h",
          "sourceFilenameExtension": "c"
        },
        "Tracing": {
          "enterState": false,
          "exitState": false,
          "generic": false
        },
        "Includes": {
          "useRelativePaths": false,
          "generateAllSpecifiedIncludes": false
        },
        "GeneratorOptions": {
          "userAllocatedQueue": false,
          "metaSource": false
        },
        "GeneralFeatures": {
          "timerService": false,
          "timerServiceTimeType": ""
        },
        "Debug": {
          "dumpSexec": false
        }
      }
    }
  }
}