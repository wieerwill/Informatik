---
title: Grundlagen und diskrete Strukturen
---
# Aussagen
Aussagen sind Sätze die wahr oder falsch sind, d.h. der Wahrheitswert ist wahr oder falsch.
> "5 ist prim" -> Aussage, wahr \
> "dieser Satz ist falsch" -> keine Aussage

Für keine natürliche Zahl n>3 ist die Gleichung x^n+y^n=z^n in positiven ganzen Zahl lösbar ~ Fermatsche Ex-Vermutung

## Verknüpfungen von Aussagen
Seien p und q Aussagen, dass sind folgende Sätze auch Aussagen
- $p \wedge q$ "und"
- $p \vee q$ "oder"
- $\neg p$ "nicht"
- $p \rightarrow q$ "impliziert"
- $p \leftrightarrow q$ "genau dann wenn"

Der Wahrheitswert dieser Verknüpfung ergibt sich aus den Wahrheitswerten p,q wie folgt
| p | q | $p\wedge q$ | $p\vee q$ | $\neg q$ | $p\rightarrow q$ | $p\leftrightarrow q$ |
| -- | -- | -- | -- | -- | -- | -- |
| f | f | f | f | w | w | w |
| f | w | f | w | w | w | f |
| w | f | f | w | f | f | f |
| w | w | w | w | f | w | w |

Aussagenlogische Variablen: Variable die den Wert w oder f annimmt

Aussagenlogische Formel: Verknüpfung aussagenloser Variablen nach obrigen Muster

Belegung: Zuordnung von w/f an jede Variable einer aussagenlogischer Formel

Wahrheitswerteverlauf: Wahrheitswert der Aussagenformel in Abhängigkeit von der Belegung der Variable

Tautologie: Formel deren Wahrheitswerteverlauf konstant w ist

Kontradiktion: Formel deren Wahrheitswerteverlauf konstant f ist

Kontraposition: $(p\rightarrow q)\leftrightarrow (\neg q \rightarrow p)$ ist eine Tautologie
Modus Potens: $(p\vee (p\rightarrow q))\rightarrow q$ ist eine Tautologie

Äquivalenz: Zwei Formeln p,q sind äquivalent (bzw logisch äquivalent) wenn $p\leftrightarrow$ Tautologie ist. Man schreibt $p \equiv q$

Die Formel p impliziert die Formel q, wenn $p\rightarrow q$ eine Tautologie ist

## Regeln
- $p\wedge q \equiv q \wedge p$ (Kommutativ)
- $p\vee q \equiv q \vee p$ (Kommutativ)
- $p\wedge (q \wedge r) \equiv (p \wedge q) \wedge r$ (Assoziativ)
- $p\vee ( q \vee r) \equiv (p \vee q) \vee$ (Assoziativ)
- $p\wedge (q\vee r) \equiv (p\wedge q) \vee (p\wedge r)$ (Distributiv)
- $p\vee (q\wedge r) \equiv (p\vee q) \wedge (p\vee r)$ (Distributiv)
- $\neg(\neg q) \equiv q$ (Doppelte Verneinung)
- $\neg(p\wedge q) \equiv (\neg p) \wedge (\neg q)$ (de Morgansche)

Aussagenform über den Universen $U_1,...,U_n$: Satz mit Variablen $x_1,...,x_n$ der bei Ersetzung jedes x durch ein Objekt am $U_j$ stets zu einer Aussage wird.
Variablen können mehrfach auftreten, werden aber jeweils durch das gleiche Objekt (aus $U_j$) ersetzt.
- "x ist prim" ist eine Aussagenform über dem Universum $\N$ der natürlichen Zahlen
- "$x<y$" ist eine Aussagenform über dem Universum $\R$ der reellen Zahlen
- "x ist wahr" ist eine Aussagenform über dem Universum der Aussagen
- "x ist falsch" ist keine Aussagenform über dem Universum aller Sätze

Aussagenformen in einer Variable x aus dem Universum U heißen Prädikate von U. 
Aussagenformen in n Variablen $x_1,...,x_n$ aus dem Universum U heißen "n-stellige Prädikate" von U.
Nach Ersetzung von x im 2-stelligen Prädikat "$x<y$" etwa durch "17" entsteht das 1-stellige Prädikat "$17<y$".

Sei p(x) ein Prädikat über dem Universum U (z.B. p(x) ist "x ist prim")
- "$\forall x:p(x)$": ist die Aussage "für alle x aus U ist p(x) wahr"
- "$\exists x:p(x)$": ist die Aussage "es gibt ein x aus U für das p(x) wahr ist"

Leeres Universum U (U enthält keine Objekte)
- "$\forall x:p(x)$": ist wahr (für jedes Prädikat)
- "$\exists x:p(x)$": ist falsch (für jedes Prädikat)

Endliches Universum U, etwa aus Objekte $a_1,...,a_n$
- "$\forall x:p(x)$": bedeutet $p(a_1)\wedge p(a_2) \wedge ... \wedge p(a_n)$ ist wahr/falsch
- "$\exists x:p(x)$": bedeutet $p(a_1)\vee p(a_2) \vee .. \vee p(a_n)$ ist wahr/falsch

Regeln: Seien p,q Prädikate über U
- $(\forall x: (p(x) \wedge q(x)))\leftrightarrow (\forall x: p(x) \wedge \forall x: q(x))$
- $\exists x: (p(x) \vee q(x)) \leftrightarrow (\exists x: p(x) \vee \exists x: q(x))$
- $\neg (\forall x:p(x))\leftrightarrow \exists x: \neg p(x)$
- $\neg(\exists x:p(x))\leftrightarrow \forall x:\neg p(x)$
Schachtelung von Quantoren ($\forall, \exists)$. Sei $p(x,y)$ 2-stelliges Prädikat über$U_1, U_2$: $\forall x: \exists y:p(x,y)$. Achtung: Verschiedenartige Quantoren dürfen nicht getauscht werden! gleichartige Quantoren dürfen getauscht werden

Negation: $\neg (\forall x \forall y \exists z \forall w \exists v: p(x,y,z)\rightarrow q(w,v)$
$\exists x \exists y \forall z \exists w \forall v: \neg (p(x,y,z)\rightarrow q(w,v))$

# Mengen
> Eine Menge ist eine Zusammenfassung bestimmter, wohlunterschiedener Objekte unserer Anschauung oder unseres Denkens. (Cantor)
Von jedem Objekt steht fest, ob es zur Menge gehört oder nicht.

Bsp: ${M,A,T,H,E,M,A,T,I,K} \approx {M,A,T,H,E,I,K}:$ Mengen der Buchstaben des Wortes Mathematik

## Probleme der naiven Mathematik
### Wunsch 1
"$x\in y$" soll Aussagenform über dem Universum U aller Mengen sein. D.h. für je zwei Mengen x und y ist entweder x ein Element von y oder nciht. D.h. "$x\in y$" ist ein 2-stelliges Prädikat über U.
### Wunsch 2
Ist p(x) ein Prädikat über U, so soll es eine Menge geben, die aus genau denjenigen Mengen x besteht, für die p(x) wahr ist. Bezeichnung ${x:p(x)$ ist wahr $}$.
Danach gäbe es eine Menge M, die aus genau denjenigen Mengen x mit $x\not \in x$ besteht: $M={x:x\not \in x}$.
D.h. Wunsch 1 und 2 führen zu einem Widerspruch in der Mengenlehre!\
Lösung: Aussonderung nur an bereits "gesicherten" Mengen\
#### Wunsch 2':
Ist A eine Menge und p(x) ein Prädikat über U, dann gilt es eine Menge B die aus genau denjenigen Mengen x aus A besteht, für die p(x) wahr ist. Bezeichnung: $B={x\in A:p(x) wahr}$.
Folgerung: die Gesamtheit aller Mengen ist selbst keine Menge, sonst findet man einen Widerspruch wie oben.

### Wunsch 3
Zwei Mengen x,y sind genau dann gleich wenn sie diesselben Elemente enthalten. D.h. $x=y: \leftrightarrow \forall z:(z\in x \leftrightarrow z\in y)$. Somit gilt für zwei Prädikate p(x), q(x) über U und jede Menge A: ${x\in A: p(x) wahr} = {x\in A: q(x) wahr}$ genau dann, wen q(x), p(x) den gleichen Wahrheitswert für jedes x aus A haben.

### Wunsch 0
Es gibt eine Menge. Ist A irgendeine Menge, so ist ${x \in A: \neg (x=x)}$ eine Menge ohne Elemente, die sogenannte leere Menge $\varemtpy$.

### Wunsch 4
Zu jeder Menge A gibt es eine Menge B, die aus genau denjenigen Mengen besteht, die Teilmengen von A sind. Dabei ist x eine Teilmenge von $y: \leftrightarrow \forall z:(z\in x \rightarrow z \in y) [x \subseteq y]$\
$B={x:x\subseteq A}=\wp(A)$ B heißt Potentmenge von A\
Bsp: $\wp({1,2,3}) = {\varempty, {1},{2},{3},{1,2},{1,3},{2,3},{1,2,3})$ (Daraus lässt sich ein Hesse-Diagramm zeichnen).

## Teilmengen
A Teilmenge von B $\leftrightarrow \forall x: (x\in A \rightarrow x \in B):\Rightarrow A\subseteq B$\
A Obermenge von B $\leftrightarrow \forall x: (x\in B \rightarrow x \in A):\Rightarrow A\supseteq B$\
Folglich $A=B \leftrightarrow A\subseteq B \wedge B\subseteq A$\
Schnittmenge von A und B: $A\cap B = {x: x\in A \wedge x\in B}$\
Vereinigungsmenge von A und B: $A\cup B = {x: x\in A \vee x\in B}$

Sei eine Menge (von Mengen) dann gibt es eine Menge die aus genau den Mengen besteht, die in jeder Menge von A enthalten sind (außer $A=\varemtpy$).
Ebenso gibt es Mengen die aus genau den Mengen besteht, die in wenigstens einer Menge aus A liegen. Die Existenz dieser Menge wird axiomatisch gefordert in ZFC:$ UA = {x: \exists z \in A: x \in z}$\

Seien A,B Mengen, dann sei $A/B:={x\in A: x\not \in B } = A\bigtriangleup B$\
De Moorgansche Regel: $\overline{A \cup B} = \overline{A} \cap \overline{B}$ und $\overline{A\cap B}=\overline{A}\cup \overline{B}$\
Das geordnete Paar (x,y) von Mengen x,y ist definiert durch ${{x},{x,y}}:={x,y}$\
A und B Mengen: $A x B:={(x,y):x\in A \wedge y \in B}$

# Relationen
$A={Peter, Paul, Marry}$ und $B={C++, Basic, Lisp}: $R\subseteq AxB$, etwa {(Peter,c++),(Paul, C++), (Marry,Lisp)}. Seien A,B Mengen: Eine Relation von A nach B ist eine Teilmenge R von AxB.\
$(x,y)\in R:$ x steht in einer Relation R zu y; auch xRy\
Ist A=B, so heißt R auch binäre Relation auf A

## binäre Relation
1. Allrelation $R:=AxA \subseteq AxA$
2. Nullrelation $R:=\varemtpy \subseteq AxA$
3. Gleichheitsrelation $R:={(x,y)... x=y}
4. $A=R$ $R:={(x,y)\in \R x \R, x \leq y}$
5. $A=\Z$ $R:={(x,y)\in \Z x \Z:$ x ist Teiler von y $}$ kurz: x|y

## Eigenschaften von Relationen
Sei $R\in AxA$ binäre Relation auf A
1. Reflexiv $\leftrightarrow$ xRx $\forall x \in A$
2. Symetrisch $\leftrightarrow xRy \rightarrow yRx$
3. Antisymetrisch $\leftrightarrow xRy \wedge yRx \rightarrow x=y$
4. Transitiv $\leftrightarrow xRy \wedge yRz \rightarrow xRz$
5. totale Relation $\leftrightarrow xRy \vee yRx  \forall x,y \in A$

- R heißt Äquivalenzrelation $\leftrightarrow$ R reflexiv, symetrisch und transitiv
- R heißt Ordnung $\leftrightarrow$ R reflexiv, antisymetrisch und transitiv
- R heißt Totalordnung \$leftrightarrow$ R Ordnung und total
- R heißt Quasiordnung $\leftrightarrow$ R reflexiv und transitiv


[...]


Seien M,I zwei Mengen. Eine FUnktion $f:I\rightarrow M$ von I nach M heißt auch Familie über der Indexmenge I auf M. Schreibweise $(m_i)_{i\in I}$ wobei $m_i=f(i)$. Damilien über $I=\N$ heißen Folgen (bzw. unendliche Folgen).
Eine (endliche) Folge ist eine Familie über einer endlichen Indexmenge I. Funktionen von ${1,...,n}$ in einer Menga A ($a_q,...,a_n\in A$) heißen n-Tupel. Für eine Mengenfamilie $(A_i)_{i\in A}$ sei ihr Produkt durch $\prod A_i={$ f: f Funktion von I nach $\bigcup A_i$ mit $f(i)\in A_i$ f.a. $i\in I}$. Ist allgemein $A_i=A$ konstant, so schreibe $\prod A_i=A^I={f:I\rightarrow R}$. Bezeichnung auch $2^{\N}$.

# Gruppen, Ringe, Körper
Eine Operation auf eine Menge A ist eine Funktion $f:AxA\rightarrow A$; schreibweise $xfy$. EIne Menge G mit einer Operation $\circ$ auf G heißt Gruppe, falls gilt:
1. $a\circ (b\circ c) = (a\circ b)\circ c$ freie Auswertungsfolge
2. es gibt ein $e\in G$ mit $a\circ e=a$ und $e\circ a=a$ f.a. $a\in G$. e heißt neutrales Element von G und ist eindeutig bestimmt
3. zu jedem $a\in G$ existiert ein $b\in G$ mit $a\circ b=e$ und $b\circ a=e$; wobei e ein neutrales Element ist. b ist durch a eindeutig bestimmt, denn gäbe es noch ein $c\in G$ mit $a\circ c=e$ folgt $b=b\circ e$. Schreibweise für dieses eindeutig durch a bestimmte b: $a^{-1}$

Eine Gruppe G mit $\circ$ wird auch mit $(G, \circ)$ bezeichnet. Sie heißt kommutativ bzw abelsch, falls neben 1.,2. und 3. außerdem gilt:
4. $a\circ b = b\circ a$ f.a. $a,b \in G$

Das neutrale Element aus 2. wird mit 1 bezeichnet. Im Fall der abelschen Gruppe benutzt man gerne "additive Schreibung": "+" statt "$\circ$" und "0" statt "1" (Bsp: $1*a = a*1 = a$)

Bsp: Sei X Menge und $S_X$ sei die Menge aller Bijektionen von X nach X. EIne Bijektion von X nach X heißt Permutation von X. $(S_X, \circ)$ ist eine Gruppe.


Zwei Gruppen $(G, \circ_G)$ und $(H,\circ_H)$ heißen isomorph, falls es einen Isomorphismus von $(G,\circ_G)$ nach $(H,\circ_H)$ gibt (bzw. von G nach H). Schreibweise $(G,\circ_G)\cong (H,\circ_H)$
- "$\cong$ reflexiv": $G\cong G$, denn $id_G$ ist ein Isomorphismus
- "$\cong$ symetrisch": aus $G\cong G$ folt: es exisitert ein bijektiver Homomorphismus
- "$\cong$ transitiv": sei $G\cong H$ und $H\cong J \rightarrow$ es gibt einen Isomorphismus $\phi:G\rightarrow H$ und $\psi:H\rightarrow J \rightarrow \phi\circ\psi:G\rightarrow J \rightarrow$ J ist bijektiv. $\phi\cric G$ ist Homomorphismus von G nach J und bijektiv also Isomorph

Satz: Jede Gruppe $(G,\circ)$ ist zu einer Untergruppe von $(S_G, \circ)$ isomorh

## Arithmetik von $\N$
$+: \N x \N \rightarrow \N$ wird definiert durch:
- $m+0:=m$ f.a. $m\in \N$ (0 ist neutral)
- $m+n$ sei schon definiert f.a. $m\in \N$ und ein gutes $n\in \N$
- $m+n^+:=(m+n)^+$ f.a. $m,n \in \N$
Satz: $m+n=n+m$ f.a. $m,n\in\N$ (Beweis induktiv über m)

Satz: $l+(m+n)=(l+m)+n$ f.a. $l,m,n\in\N$ (Klammern sind neutral bzgl +)

Satz (Streichungsregel): aus $a+n=b+n$ folgt $a=b$ f.a. $a,b,n\in\N$

## Analog: Multiplikation
$*: \N x \N \rightarrow \N$ wird definiert durch:
- $m*0:=0$ f.a. $m\in \N$
- $m*n^+=m*n+m$ f.a. $n\in\N$
Es gilt:
1. $m*n=n*m$ f.a. $n\in\N$
2. $m*(n*l)=(m*n)*l$ f.a. $m,n\in\N$
3. $m*1 = 1*m =m$ f.a. $m\in\N$
4. $a*n=b*n \rightarrow a=b$ f.a. $a,b\in\N, n\in\N/{0}$
5. $a*(b+c)=a*b+a*c$ (Distributivgesetz)

## Die ganzen Zahlen $\Z$
Durch $(a,b)~(c,d)\leftrightarrow a+d=b+c$ wird eine Äquivalenzrelation auf $\Nx\N$ definiert.
Die Äquivalenzklassen bzgl ~ heißen ganze Zahlen (Bezeichnung $\Z$, Bsp $17=[(17,0)]_{/~}$).
Wir definieren Operationen +, * auf $\Z$ durch
- $[(a,b)]_{/~} + [(c,d)]_{/~} = [(a+c, b+d)]_{/~}$
- $[(a,b)]_{/~} * [(c,d)]_{/~} = [(ac+bd, ad+bc)]_{/~}$
Zu zeigen ist: DIe auf der rechten Seite definierten Klassen hängen nicht von der Wahl der "Repräsentanten" der Klassen auf der linken Seite ab (Wohldefiniert).

Formal (für +): $[(a,b)]_{/~} = [(a',b')]_{/~}$ und $[(c,d)]_{/~} = [(c',d')]_{/~}$ impliziert $[(a,b)]_{/~} + [(c,d)]_{/~} = [(a'+c', b'+d')]_{/~}$. Aus der Vss konstant kommt $a+b'=b+a'$ und $c+d'=c'+d$. Dann folgt $a+c+b'+d'=b+d+a'+c'$, also $(a+c, b+d)~(a'+c',b'+d')$.

Satz: $\Z$ ist eine abelsche Gruppe (+ assoziativ, enhält neutrales Element, additiv Invers).
$[(a,0)]_{/~}$ wird als a notiert. $-[(a,0)]_{/~}=[(0,a)]_{/~}$ wird als -a notiert.
Anordnung: $[(a,b)]_{/~} \subseteq [(c,d)]_{/~} \leftrightarrow a+d\leq b+c$

Ein Ring R ist eine Menge mit zwei Operationen $+,*: \R x\R \rightarrow \R$ mit:
1. $a+(b+c) = (a+b)+c$ f.a. $a,b,c\in \R$
2. Es gibt ein neutrales Element $O\in \R$ mit $O+a=a+O=O$ f.a. $a\in\R$
3. zu jedem $a\in\R$ gibt es ein $-a\in \R$ mit $a+(-a)=-a+a=0$
4. $a+b=b+a$ f.a. $a,b\in\R$
5. $a*(b*c)=(a*b)*c)$ f.a. $a,b,c\in\R$
6. $a*(b+c)=a*b+a*c$ f.a. $a,b,c\in\R$
R heißt Ring mit 1, falls:
7. es gibt ein $1\in\R$ mit $a*1=1*a=a$ f.a. $a\in\R$
R heißt kommutativ, falls:
8. $a*b=b*a$ f.a. $a,b\in\R$
Ein kommutativer Ring mit $1\not=O$ heißt Körper, falls:
9. zu jedem $a\in\R$ gibt es ein $a^{-1}\in\R$ mit $a*a^{-1}=a^{-1}*a=1$

Bemerkung: $O$ kann kein multiplivativ inverses haben.

- Ist $\R$ ein Körper, so ist $\R*=\R\\{0}$ mit $*$ eine abelsche Gruppe.
- $\Z$ mit + und * ist ein kommutativer RIng mit $1\not=0$ aber kein Körper
- $\Q,\C,\R$ mit + und * ist ein Körper

## Division mt Rest in $\Z$
Satz: Zu $a,b\in\Z, b\not=0$, gibt es eindeutig bestimmte $q,r\in\Z$ mit $a=q*b+r$ und $0\leq q <|b|$ (d.h. $\Z$ ist ein euklidischer Ring). (Beweis über Induktion)

## Zerlegen in primäre Elemente
Satz: Jede ganze Zahl $n>0$ lässt sich bis auf die Reihenfolge der Faktoren eindeutig als Produkt von Primzahlen darstellen.

Beweis-Existenz mit Annahme: Der Satz gilt nicht, dann gibt es eine kleinste Zahl n die sich nicht als Produkt von Primzahlen schreiben lässt $\rightarrow$ n weder Primzahl noch 1 $\rightarrow n=m*l$ für $m,l>1 \rightarrow$ m und l sind Produkte von Primzahlen $\rightarrow m*l=$ Produkt von Primzahlen.

Eindeutigkeit mit Annahme: es gibt ein $n>0$ ohen eindeutige Primfaktorzerlegung (PFZ)$\rightarrow$ es gibt ein kleinstes $n>0$ ohne eindeutige PFZ. Kommt eine Primzahl p in beiden Zerlegungen vor, so hat auch $\frac{n}{p}$ zwei versch. PFZen. Man erhält die PFZ von $n'=(1_1-p_1)*b$ aus den PFZen von $q_1-p_1$ und b.. -> Eindeutig bestimmbar.

## Arithmetik im Restklassenring in $\Z$
Sei $m>1$ gegeben, $a\equiv b mod m \leftrightarrow m|a-b$ def. Relation auf $\Z$. Die Äquivalenzklasse zu a wird mit $\bar{a}$ bezeichnet, d.h. $\bar{a}=[a]_{/mod m}={x\in \Z: x\equiv a mod m}$, $\Z_m={\bar{a}:a\in\Z}$. Sei dazu $\bar{a}\in\Z_m$ beliebig.

Division mit Rest $\rightarrow$ es gibt eindeutig bestimmt q,r mit $a?q*m+r$ und $0\leq r < m \rightarrow a-r=q*m \rightarrow m| a-r \rightarrow a\equiv r mod m \rightarrow \bar{a}=\bar{r}$. Also tritt $\bar{a}$ in der Liste $\bar{0},\bar{1},...,\bar{m-1}$ auf. Aus $0\leq i < j \leq m-1$ folgt $\bar{i}\not=\bar{j}$. In der Liste $\bar{0},\bar{1},...,\bar{m-1}$ gibt es daher keine Wiederholungen $\rightarrow |\Z_M|=m$.

Wir definieren Operationen +,* auf $\Z_m$ durch $\bar{a}+\bar{b}:= \bar{a+b}$ und $\bar{a}*\bar{b}:=\bar{a*b}$ für $a,b\in\Z$. 
Wohldefiniert: aus $\bar{a}=\bar{a'}$ und $\bar{b}=\bar{b'}$ folgt $\bar{a+b}=\bar{a'+b'}$. Analog für Multiplikation.

Eigenschaften von $\Z$ mit +,* werden auf $\Z$ mit +,* "vererbt", z.B. Distributivgesetz.

Satz: Sei $m\geq 2$ dann ist $\Z_m$ mit +,* ein kommutativer Ring mit $\bar{1}\not=\bar{0}$. Genau dann ist $\Z_m$ sogar ein Körper, wenn m eine Primzahl ist.

Satz: Genau dann gibt es einen Körper mit n ELementen, wenn n eine Primzahl ist. D.h.. wenn $n=p^a$ ist für eine Primzahl p und $a\geq 1$.

## Konstruktion von $\Q$ aus $\Z$
Sei $M=\Zx(\Z\\{0}$ die Menge von Brüchen. Durch $(a,b)~(c,d)\leftrightarrowad=bc$ wird Äquivalenzrelation auf M durchgefühert. Schreibweise für die Äquivalenzklassen $\frac{a}{b}$ Die Elemente von $\Q:{\frac{a}{b}:a,b\in\Z, b\not=0}$ heißten rationale Zahlen.
Definiere Operationen +,* auf $\Q$ wie folgt:
- $\frac{a}{b}+\frac{c}{d} = \frac{ad+bc}{b*d}$ (wohldefiniert)
- $\frac{a}{b}*\frac{c}{d} = \frac{a*c}{b*d}$

Satz: $\Q$ mit +,* ist ein Körper.
Durch $\frac{a}{b}\leq\frac{c}{d}$ wird eine totale Ordnung auf $\Q$ definiert. Konstruktion von $\R$ aus $\Q$ mit Dedchin-Schnitten.

### Ring der formalen Potenzreihe
Sei k ein Körper (oder nur ein Ring mit 1+0). Eine Filge $(a_0, a_1,...,a:n)\in\K^{\N}$ mit Einträgen aus K heißt formale Potenzreihe. Die Folge (0,1,0,0,...) wird mit x bezeichnet. Statt $K^{\N}$ schreibt man $K[[x]]$. $(0_0,a_1,a_2,...)$ heißt Polynom in x, falls es ein $d\in\N$ gibt mit $a_j=0$ f.a. $j<n$. Die Menge aller Polynome wird mit $K[x]$ bezeichnet.

Satz: $K[[x]]$ wird mit +,* wie folgt zu einem kommutativen Ring mit $1\not=0$
- +: $(a_0,a_1,...) + (b_0,b_1,...) = (a_o+b_0, a_1+b_1, ...)$
- *: $(a_0,a_1,...) + (b_0,b_1,...) = (c_0, c_1,...)$ mit $c_K=\sum_{j=a}^{k} a_j*b_{k-j}$
Die formale Potenzreihe $(a,0,0,0,...)$ wird ebenfalls mit a bezeichnet.

Die bzgl $\leq$ minimalen Elemente von $B\{\perp}$ heißen Atom von B.
Satz: Sei $b\in B\{\perp}$ und $a_1,...,a_k$ dijenigen Atome a mit $a\leq b$, dann ist $b= a_1 \vee a_2 \vee ... \vee a_k$.

B mit $\vee, \wedge, \bar$ und $\dot{B}$ mit $\dot{\vee}, \dot{\wedge}, \dot{\bar}$ seien boolsche Algebren. Sie heißen isomorph, falls es einen Isomorphismus von B nach $\dot{B}$ gibt, d.h. eine Bijektion $\phi: B \rightarrow \dot{B}$ mit:
- $\phi(a\vee b) =\phi(a)\dot{\vee}\phi(b)$ f.a. $a,b \in B$
- $\phi(a\wedge b)=\phi(a)\dot{\wedge}\phi(b)$ f.a. $a,b\in B$
- $\phi(\bar{a}) = \dot{\bar{\phi(a)}}$ f.a. $a\in B$

Satz (Stone): Ist B mit $\vee, \wedge, \bar$ eine boolsche Algebra, B endlich und A die Menge ihrer Atome, so ist B isomorph zur boolschen Algebra $\wp(A)$ mit $\cap,\cup,\dot{\bar}$, wobei $\dot{\bar{X}}=A\\X$.
Also ist in jeder Teilmenge X von A Bild eines Elements von B unter $\phi$.

Satz: $\perp$, T sind durch die Bedingung 3 eindeutig bestimmt.

Satz: $\bar{a}$ ist durch die Bedingung 1,2,4 eindeutig bestimmt.

Lemma: Sei B mit $\vee, \wedge, \bar$ eine boolsche Algebra, dann gilt:
1. Dominanz
    - $a\vee T = T$ f.a. $a\in B$
    - $a\wedge \perp = \perp$ f.a. $a\in B$
2. Absorption
    - $a\vee(a\wedge b)= a$ f.a. $a,b\in B$
    - $a\wedge(a\vee b)= a$ f.a. $a,b\in B$
3. Streichungsregel
    - $a\wedge x = b\wedge x \rightarrow a=b$ f.a. $a,b,c \in B$
    - $a\wedge \bar{x} = b\wedge\bar{x} \rightarrow a=b$ f.a. $a,b,x \in B$
4. Assoziativität
    - $a\vee(b\vee c)=(a\vee b)\vee c$ f.a. $a,b,c\in B$
    - $a\wedge(b\wedge c)=(a\wedge b)\wedge c$ f.a. $a,b,c \in B$
5. De Moorgansche Regel
    - $\bar{a\vee b} = \bar{a}\wedge \bar{b}$ f.a. $a,b\in B$
    - $\bar{a\wedge b} = \bar{a}\vee \bar{b}$ f.a. $a,b\in B$

Satz: Durch $a\leq b:\leftrightarrow a\vee b=b$ wird eine Ordnung auf der boolschen Algebra B mit $\vee, \wedge, \bar$ definiert
- $a\vee b = sup{a,b}$
- $a\wedge b = inf{a,b}$
Es gilt $a\vee b= b \rightarrow a\wedge b = a\wedge(a\vee b)= a$
- $a\vee b$ ist obere Schranke von ${a,b}$, d.h. $a\leq a\vee b$, dann $a\vee(a\vee b)=a\vee b$
- $a\vee b$ ist kleinste obere Schranke, d.h. $a\leq z$ und $b\leq z$ folgt $a\vee b \leq z$

Sind $B, \dot{B}$ isomorph, so schreibe $B \cong \dot{B}$. Daraus folgt $\dot{B} \cong B$ und aus $B \cong \dot{B}$ und $\dot{B} \cong \ddot{B}$ folgt $B \cong \ddot{B}$.
Weiterhin besitzt jede boolsche Algebra mit genau n Atomen genau $2^n$ viele Elemente (denn sie ist isomorph zur boolschen Algebra).

Beispiel: Sei X eine endliche Menge von Variablen. Eine aussagenlogische Formel F in X ist:
- atomar: ""x" mit $x\in X$ oder "f" oder "w" oder
- zusammengesetzt: $(P\vee Q), (P \wedge Q), (\neg P)$ aus den Formeln P,Q
Der Wahrheitswert von F unter der Belegung $\beta: X\rightarrow {f,w}$ ergibt sich wie in Kapitel 1. Bezeichnung für den Wahrheitswert von F unter $\beta: W_F(\beta)$. Es gibt $2^{|x|}$ Belegungen.
Der Wahrheitswerteverlauf ist die so definierte Funktion $W_F:{f,w}^X\rightarrow{f,w}$. Folglich gibt es $2^{2^{|x|}}$ verscheidene Wahrheitswertverläufe für logische Formeln. Formeln F, F' heißen äquivalent, falls $W_F=W_{F'} \rightarrow$ es gibt $2^2^{|x|}$ verschiedene Äquivalenzklassen aussagenlogischer Formeln in X. Die Äquivalenzklassen werden mit $[F]_{/\equiv}$ bezeichnet.

Sei $B:={[F]_{/\equiv}}:$ F aussagenlogische Formel in X $}$ die Menge aller Äquivalenzklassen aussagenlogischer Formeln in X.
- $[P]_{/\equiv} \vee [Q]_{/\equiv} = [(P\vee Q)]_{/\equiv}$
- $[P]_{/\equiv} \wedge [Q]_{/\equiv} = [(P\wedge Q)]_{/\equiv}$
- $\bar{[P]_{/\equiv}} = [-(P)]_{/\equiv}$
liefert die boolsche Algebra auf B
- $\perp = [f]_{/\equiv}$ = Menge der Kontradiktionen von X
- $T = [w]_{/\equiv}$ = Menge der Tautologien von X

Ordnung $\leq$ auf B: $[P]_{/\equiv} \leq [Q]_{/\equiv} \leftrightarrow [P]_{/\equiv} \wedge [Q]_{/\equiv} \rightarrow$ Die Atome von B sind genau die Klassen zu Formel P mit $W_p^{-1}({w})=1$. Kanonische Repräsentaten für diese Atome sind die Min-Terme.
Zu jeder aussagenlogischen Formel f kann man die Atome $[P]_{/\equiv}$ mit $[P]_{/\equiv} \leq [F]_{/\equiv}$ betrachten, wobei P Min-Terme sind.

Satz Jede Formel ist äquivalent zu einer Formel in DNF (disjunkte normal Form)

Coatome der boolschen Algebra B mit $\vee, \wedge, \bar$ := Atome der dualen boolschen Algebra B mit $\vee, \wedge, \bar$

Ist $b\in B$ und $a_1,...,a_k$ die Coatome a mit $b\leq a$ so gibt $b=a_1 \wedge ... \wedge a_k$. Max-Terme sind "$x_1\vee ... \vee x_k$" und alle j die durch Ersetzung einiger $x_j$ durch $\neg x_j$ daraus hervorgehen und sind die kanonische Repräsentation der Coatome von B.

Satz: Jede aussagenlogische Formel ist äquivalent zu einer Formel in konjunktiver Normalform (KNF), d.h. zu einer Formel $P_1\wedge ... \wedge P_n$, worin die $P_j$ Max-Terme sind.


# Diskrete Wahrscheinlichkeitsräume
Ein (endlicher, diskreter) Wahrscheinlichkeitsraum ist ein Paar $(\Omega, p)$ bestehnd aus einer endlichen Menge $\Omega$ und einer Funktion $p:\Omega \rightarrow [0,1]\in \R$ mit $\sum_{\omega \in \Omega} p(\omega)=1$. Jeder derartige p heißt (Wahrscheinlichtkeits-) Verteilung auf $\Omega$. Die Elemente aus $\Omega$ heißen Elementarereignis, eine Teilmenge A von $\Omega$ heißt ein Ereignis; seine Wahrscheinlichkeit ist definiert durch $p(A):=\sum_{\omega in A} p(\omega)$.
$A=\varemtpy$ und jede andere Menge $A\subseteq \Omega$ mit $p(A)=0$ heißt unmöglich (unmögliches Ereignis).
$A=\Omega$ und jede andere Menge $A\subseteq \Omega$ mit $p(A)=1$ heißt sicher (sicheres Ereignis).
Es gilt für Ereignisse $A,B,A_1,...,A_k$:
1. $A\subseteq B \rightarrow p(A)\leq p(B)$ denn $p(A)=\sum p(\omega) \leq \sum p(\omega) = p(B)$
2. $p(A\cup B) \rightarrow p(A)+p(B)-p(A\cap B)$
3. Sind $A_1,...,A_k$ paarweise disjunkt (d.h. $A_i \cap A_J=\varemtpy$ für $i\not =j$) so gilt $p(A_1 \cup ... cup A_k)= p(A_1)+...+p(A_k)$
4. $p(\Omega \\ A):=$ Gegenereigns von $A=1-p(A)$
5. $p(A_1,...,A_k) \leq p(A_1)+...+p(A_k)$

## Beispiel: Würfelwurf 
- ungezinkt:
  - $\Omega = {1,2,3,4,5,6}$
  - $p=(\frac{1}{6},\frac{1}{6},\frac{1}{6},\frac{1}{6},\frac{1}{6},\frac{1}{6})$
  - d.h. $p(\omega)=\frac{1}{6}$ f.a. $\omega \in \Omega$
- gezinkt:
  - $\Omega = {1,2,3,4,5,6}$
  - $p=(\frac{1}{4}, \frac{1}{10}, \frac{1}{5}, \frac{1}{4}, \frac{1}{10}, \frac{1}{10})=(25%, 10%, 20%, 25%, 10%, 10%)$
  - $p({\oemga \in \Omega: \omega gerade})=p({2,4,6})=p(2)+p(4)+p(6)= \frac{1}{10}+ \frac{1}{4}+ \frac{1}{10} = \frac{9}{20}$


Satz: Sind $(\Omega, p_1),...,(\Omega, p_m)$ Wahrscheinlichkeitsräume so ist durch $p((\omega_1,...,\omega_m))=\prod p_i(\omega_i)$ eine Verteilung auf $\Omega = \Omega_1 x ... x \Omega_m = {(\omega_1,...,\omega_m): \omega \in \Omega, f.a. i\in{1,...,m}}$. Für $A_1\subseteq \Omega_1, A_2\subseteq \Omega_2,...,A_m\subseteq \Omega_m$ gilt $p(A_1x...xA_m)=\prod p_i(A_i)$.
$(\Omega, p)$ heißt Produktraum von $(\Omega_1, p_1),...$.

$(\Omega, p)$ Wahrscheinlichkeitsraum; $A,B\in \Omega$ heißen (stochastisch) unabhängig, falls $p(A\cap B) = p(A)*p(B)$.
Bespiel: $p(A\cap B) = p({i,j}) =p_1{i}*p_2{j} = p(A)*p(B)$ für das Ereignis "der 1. Würfel zeigt i, der 2. Würfel zeigt j"

## Bedingte Wahrscheinlichkeiten
$(\Omega, p)$ Wahrscheinlichkeitsraum, $B\subseteq \Omega$ ("bedingtes Ereignis") mit $p(B)>0$, dann ist $p_B:B\rightarrow [0,1]; p_B(\omega)=\frac{p(\omega)}{p(B)}$ eine Verteilung auf B, denn $\sum p_b(\omega)=\sum \frac{p(\omega)}{p(B)}=\frac{1}{p(B)} \sum p(\omega)= \frac{1}{p(B)} p(B)= 1$.
$p_B$ ist die durch B bedingte Verteilung. Für $A\subseteq \Omega$ gilt $p_B(A\cap B)=\sum p_B(\omega)=\sum\frac{p(\omega)}{p(B)}= \frac{p(A\cap B)}{p(B)}:= p(A|B)$ ("p von A unter B") bedingte Wahrscheinlichkeit von A unter B.

Satz (Bayer): $p(A|B)=\frac{p(B|A)*p(A)}{p(B)}$ wobei $p_A, p_B \geq 0$

Satz (Totale Wahrscheinlichkeit): Seien $A_1, ...,A_k$ paarweise disjunkt, $\bigcup A_j=\Omega, p(A_i)>0, B\subseteq \Omega$, dann gilt $p(B)=\sum p(B|A_i)*p(A_i)$.

Satz (Bayer, erweitert): $A_1,...,A_k,B$ wie eben, $p(B)>0$. Für $i\in {1,...,k}$ gilt $p(A_i|B)=\frac{p(B|A_i)*p(A_i)}{\sum p(B|A_j)*p(A_j)}$

Bespiel: In einem Hut liegen drei beidseitig gefärbte Karten. Jemand zieht ("zufällig") eine Karte und leg sie mit einer ("zufälligen") Seite auf den Tisch. Karten rot/rot, rot/blau und blau/blau. Gegeben er sieht rot, wie groß ist die Wahrscheinlichkeit, dass die andere Seite auch rot ist?
p(unten rot | oben rot) = p(unten rot und oben rot)/p(oben rot) = $\frac{\p(\binom{r}{r})}{p(\binom{r}{r}\binom{r}{b})}=\frac{\frac{2}{6}}{\frac{3}{6}}=\frac{2}{3}$

Eine Funktion $X:\Omega \rightarrow \R$ heißt (reellwertige) Zufallsvariable. Weil $\Omega$ endlich ist, ist auch $X(\Omega)={X(\omega): \omega \in \Omega}\subseteq \R$ endlich. Durch $p_x(x):=p(X=x):=p({\omega \in \Omega: X(\omega)=x})$ wird ein Wahrscheinlichkeitsraum $(X(\Omega),p_x)$ definiert; denn $\sum p_x(x)=p(\Omega)=1$. $p_x$ heißt die von X induzierte Verteilung. $X(\Omega)$ ist meist erheblich kleiner als $\Omega$.
Beispiel: Augensumme beim Doppelwurf: $X:\Omega\rightarrow \R, X((i,j))=i+j \rightarrow X(\Omega)={2,3,4,...,12}$

Satz: Seien $(\Omega_1, p_1),(\Omega_2, p_2)$ Wahrscheinlichkeitsräume und $(\Omega, p)$ ihr Produktraum. Sei $X:\Omega_1\rightarrow\R,Y:\Omega_2\rightarrow \R$, fasse X,Y als ZVA in $\Omega$ zusammen $X((\omega_1,\omega_2))=X(\omega_1)$ und $Y((\omega_1,\omega_2))=Y(\omega_2)$; d.h. X,Y werden auf $\Omega$ "fortgesetzt". Dann sind X,Y stochastisch unabhängig in $(\Omega, p)$ (und $p(X=x)=p_1(X=x), p(Y=y)=p_2(Y=y)$).

## Erwartungswert, Varianz, Covarianz
Sei $X:\Omega\rightarrow \R$ ZVA im Wahrscheinlichkeitsraum $(\Omega, p)$. $E(X)=\sum_{x\in X(\Omega)}x p(X=x)=\sum_{\omega in Omega} X(\omega)p(\omega)$ "E verhält sich wie Integral"; E(x) heißt Erwartungswert von x.

Linearität des Erwartungswertes: $E(x+y)=E(x)+E(y)$ und $E(\alpha x)=\alpha E(x)$.
Ist $X:\Omega\rightarrow \R$ konstant gleich c, so ist $E(x)=\sum x*p(X=x)=c*p(X=x)=c*1=c$.

Die Varianz von X: $Var(X)=E((X-E(X))^2)$ heißt Varianz von X (um E(X)).
Die Covarianz: $Cov(X,Y)=E((X-E(X))*(Y-E(Y)))$ heißt Covarianz von X und Y.
Der Verschiebungssatz: $Cov(X,Y)=E(X*Y)-E(X)*E(Y)$
$Var(X)=Cov(X,X)=E(X*X)-E(X)E(X)=E(X^2)-(E(X))^2$

Seien X,Y stochastisch unabhängig ($\leftrightarrow p(X=x \wedge Y=y)=p(X=x)*p(Y=y)$)
$E(X)*E(Y)=\sum_{x\in X(\Omega)} x*p(X=x)* \sum_{y\in Y(\Omega)} y*p(Y=y)=\sum_{x\in X(\Omega)} \sum_{y\in Y(\Omega)} xy*p(X=x)p(Y=y)=\sum_{Z\in\R} z*p(X*Y=Z) = E(X*Y)$
Sind X,Y stochastisch unanhängig ZVA, so ist $E(X)*E(Y)=E(X*Y)$; folglich $Cov(X,Y)=0$

Satz: Seien X,Y ZVA, dann gilt $Var(X+Y)=Var(x)+Var(Y)+2*Cov(X,Y)$. Sind insbesondere X,Y unabhängig gilt: $Var(X+Y)=Var(X)+Var(Y)$.

Sei $(\Omega, p)$ Wahrscheinlichkeitsraum, $X:\Omega\rightarrow \R$ Zufallsvariable heißt Bernoulliverteilt im Parameter p falls $p(X=1)=p$ und $p(X=0)=1-p$, $p\in [0,1]$. $E(X)=\sum x*p(X=x)= 1*p(X=1)=p$
Für $X:\Omega\rightarrow {0,1}$ ist $X^2=X$: $Var(X)=E(X^2)-E(X)^2 = p-p^2 = p(1-p)=p*q$

## Binominalkoeffizienten
Sei N eine Menge, dann ist $\binom{N}{k}:={x\subseteq N:$ x hat genau k Elemente $(|x|=k)}$ für $k\in \N$. Für $n\in \N$ sei $\binom{n}{k}:=|(\binom{1,...,k}{k})$.

Satz: $\binom{n}{0}={n}{n}=1$ f.a. $n\geq 0$ $\binom{n}{k}=\binom{n-1}{k-1}+\binom{n-1}{k}$ f.a. $n\geq 0,k\geq 1, k\geq n-1$

Dür jede n-elementige Menge N ist $\binom{N}{0}={\varempty}, \binom{N}{n}={N}\rightarrow \binom{n}{0}=\bino{n}{n}=1$. Den zweiten Teil der Behauptung zeigt man induktiv über n.