# TP INF224
Chloé Court

----
#
## Etape 4 :
Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?

> Il s'agit d'une méthode abstraite. Il faut donc la déclarer avec =0 à la fin de la déclaration de la méthode :
```
virtual void play() = 0;
```
Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?

> Il n'est plus possible d'instancier une classe avec des méthodes abstraites car elle devient une classe abstraite.

----
## Etape 5 :

Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?

> Il s'agit du polymorphisme.

Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?

> Il faut déclarer toutes les méthodes de la classe de base comme virtual, donc ici il faut déclarer play virtual.

Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.

> Le tableau doit contenir des pointeurs pour permettre la liaison dynamique. A titre de comparaison, en Java, la liaison est dynamique par défaut. 

----
## Etape 7 :
Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ?

> Il faut modifier la classe Film puisqu'elle contient un attribut étant un pointeur vers des objets alloués dynamiquement. Il faut ainsi que l'on crée une copie de l'objet dans le getter et le setter.


La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?

> Lors de la copie d'objet, seuls les pointeurs des variables de classe sont copiés. Ainsi deux pointeurs pointent sur le même objet, donc la modification de l'un des objets entraîne la modification de l'autre. Il nous faut redéfinir l'opérateur de copie pour implémenter la copie profonde d'objet.

----
## Etape 8
Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.

> La liste doit être une liste de pointeurs pour pouvoir allouer dynamiquement des objets de tailles variables. En Java, les objets sont traités sous forme de référence et alloués dynamiquement par défaut. 

----
## Etape 10

Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?

> Il faut restreindre l'accès à une seule classe avec les mots clés private ou protected pour les constructeurs. Il faut aussi mettre la classe Manager en friend pour les classes Photo, Video et Film.

----
## Etape 1 - Java Swing
> Lancez votre programme, cliquez plusieurs fois sur les deux premiers bouton, retaillez la fenêtre. Que constate-t'on ?
La fenêtre de texte est trop petite. On va utiliser un BorderLayout pour l'agrandir. 