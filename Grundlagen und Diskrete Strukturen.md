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

## Äqivalenzrelation
Sei A Menge, $C\wp (A)$ Menge von teilmengen von A. C heißt Partition von A, falls gilt:
1. $UC=A$ d.h. jedes $x\in A$ liegt in (wenigstens) einem $y\in C$
2. $\varemtpy \not in C$ d.h. jedes $y\in C$ enthält (wenigstens) ein Element von A
3. $X \cap Y = \varemtpy$ f.a. $X\not \in Y$ aus C

Zwei Mengen $X\cap Y = \varemtpy$ heißten disjunkt. 
Die Elemente von C heißten Teile, Klassen oder Partitionen.
Satz: Sei ~ Äquivalenzrelation auf A. Für $x\in A$ betrachtet $[x]_{/~}:={y\in A: y~x}$. Dann ist {[x]_{/~}:x\in A}= C_{/~}$ Partition von A. Die Elemente $[x]_{/~}$ von $C_{/~}$ heißen Äquivalenzklassen.

Wichtiges Bsp: Restklassen modulo m\
$m\not \in \Z, m \geq 2$; Für $x,y \in \Z$ schreibe $x \equiv y$ mod m ("x konvergent y modulo m") falls $m | (x-y)$. $\equiv (mod m)$ ist eine binäre Relation auf $\Z$
"$\equiv§ transitiv" aus $x=y mod m$ und $y\equiv z mod m$ folgt $\rightarrow m| x-z$

Somit ist $\equiv(mod m)$ eine Äquivalenzrelation. Ihre Äquivalenzklassen heißen Restklassen mod m

Ein Graph $G=(V,E)$ ist ein Paar bestehend aus einer Menge V und $Eßsubseteq {x,y: x\not = y$ aus V $}$.
Zu $a,b\in V$ heißt eine Folge $P=x_1,..,x_n$ von paarweise verschiedenen Ebenen mit $a=x_0, b=x_j; x_{j-1},x_i \in E{a*i \in b*j}$ ein a,b-Weg der Länge l oder Weg a nach b. Durch a~b gibt es einen a,b-Weg in G, wird eine Äquivalenzrelation auf V definiert, denn:
- "~ reflexiv": es ist $x~x$, denn $P=x$ ist ein x,x-Weg in G
- "~ symetrisch": aus $x~y$ folgt, es gibt einen x,y-Weg $\rightarrow$ es gibt einen y,x-Weg $y~x$
- "~ transitiv": aus $x~y$ und $y~x$ folgt, es gibt einen x,y-Weg und einen y,x-Weg
Die Äquivalenzklassen von $~_G$ erzeugen die Zusammenhangskomponenten von G

Satz: Sei C eine Partition von A, dann wird durch $x~_G y \leftrightarrow$ es gibt ein $X\in C$ mit $x,y\in X$ eine Äquivalenzrelation auf A definiert.

## (Halb) Ordnungen
Sei also $leq$ eine Ordnung auf X. Seo $A\subseteq X, b\in X$
- b minimal in A $\leftrightarrow b\in A$ und $(c\leq b \rightarrow c=b f.a. c\in A)$
- b maximal in A $\leftrightarrow b\in A$ und $(b\leq c \rightarrow b=c f.a. c\in A)$
- b kleinstes Element in A $\leftrightarrow b\in A$ und $(b\leq c f.a. c\in A)$
- b größtes Element in A $\leftrightarrow b\in A$ und $(c\leq b f.a. c\in A)$
- b untere Schranke von A $\leftrightarrow b\leq c f.a. c\in A$
- b obere Schranke von A $\leftrightarrow c\leq b f.a. c\in A$
- b kleinste obere Schranke von A $\leftrightarrow b ist kleinstes Element von ${b'\in X:$ b' obere Schranke von A $}$ auch Supremum von A; $\lor A = b$
- b größte untere Schranke von A $\leftrightarrow b ist das größte Element von ${b'\in X:$ b' untere Schranke von A $}$ auch Infinium von A; $\land A = b$
kleinstes und größtes Element sind jew. eindeutig bestimmt (falls existent)

Satz: Sei X Menge. $\subseteq$ ist Ordnung auf $\wp(X)$. Ist $O\subseteq \wp(X)$, so ist $sup O=\bigcup O$ und $inf O=\bigcap O$

Satz: Die Teilbarkeitsrelation | ist Ordnung auf den natürlichen Zahlen $\N$. Es gibt $sup(a,b)=kgV(a,b)$ (kleinstes gemeinsames Vielfaches) und $inf(a,b)=ggT(a,b)$ (größtes gemeinsames Vielfaches)

## Hesse Diagramm
Darstellung einer Ordnung $\subseteq$ auf X
1. Im Fall $x\subseteq y$ zeichne x "unterhalb" von y in die Ebene
2. Gilt $x\subseteq y (x\not = y)$ und folgt aus $x \subseteq z \subseteq y$ stets $x=z$ oder $y=z$ so wird x mit y "verbunden"

## Zoonsche Lemma
Zu jeder Menge und für jede Ordnung $\leq$ auf X mit der Eigenschaft, dass jede nicht-leere Kette nach der beschränkt ist, gibt es ein maximales Element.

## Wohlordnungssatz
Jede Menge lässt sich durch eine Ordnung $\subseteq$ so ordnen, dass jede nichtleere Teilmenge von X darin ein kleinstes Element ist

# Induktion
X ist eine Menge, $X:=X\vee {X}$\
M Menge heißt induktiv $:\leftrightarrow \varempty \in M \wedge \forall X \in M$  $X^+ \in M$
Ist O eine Menge von induktiven Mengen, $O\pm O$ dann ist auch $\bigcap O$ induktiv. Insbesondere ist der Durchschnitt zweier induktiver Mengen induktiv. Es gibt eine induktive Menge M: $M =\bigcap {A \in \wp(M): A induktiv}$.
Sei M' irgendeine (andere) induktive Menge $\rightarrow M \cap M'$ ist induktive Teilmenge von M. $\N_M$ ist der Durchschnitt über alle induktiven Teilmengen von M $\N_M \subseteq M\cap M' \subseteq M'$. Folglich ist $\N_m$ Teilmenge jeder induktiven Menge.

## Satz I (Induktion I)
Sei p(n) ein Prädikat über $\N$. Gelte p(0) und $p(n)\rightarrow p(n^+)$ f.a. $n\in \N$ dann ist p(n) wahr f.a. $n\in N$. Schreibe $x=y:\leftrightarrow x\in y \vee x=y$

## Satz II (Induktion II)
Sei p(n) ein Prädikat über $\N$, gelte ($\forall x < n: p(x9))\rightarrow p(n)$ f.a. $n\in \N$. Damit ist p(n) wahr für alle $n\in \N$.

# Funktionen
Seien A,B Mengen: Eine Relation $f\subseteq A x B$ heißt Funktion. A nach B ("$f:A\rightarrow B$") falls es zu jedem $x\in A$ genau ein $y\in B$ mit $(x,y)\in f$ gibt. Dieses y wird mit $f(x) bezeichnet.

Satz: $f:A\rightarrow B, g:A\rightarrow B$; dann gilt $f=g \leftrightarrow f(x)=g(x)$. Sei $f:A\rightarrow B$ Funktion
1. f heißt injektiv $\leftrightarrow$ jedes y aus B hat höchstens ein Urbild
2. f heißt subjektiv $\leftrightarrow$ jedes y aus B hat wenigstens ein Urbild
3. f heißt bijektiv $\leftrightarrow$ jedes y aus B hat genau ein Urbild

Ist $f:A\rightarrow B$ bijektive Funktion, dann ist auch $f^{-1}\subseteq BxA$ bijektiv von B nach A, die Umkehrfunktion von f.
Man nennt f dann Injektion, Surjektion bzw Bijektion
- f injektiv $\leftrightarrow (f(x)=f(y)\rightarrow x=y)$ f.a. $x,y\in A$ oder $(x\not = y \rightarrow f(x)\not = f(y))$
- f surjektiv $\leftrightarrow$ Zu jedem $x\in B$ existiert ein $x\in A$ mit $f(x)=y$
- f bijektiv $\leftrightarrow$ f injektiv und surjektiv

Sind $f:A\rightarrow B$ und $g:B\rightarrow C$ Funktionen, so wird durch $(g \circ f)(x):=g(f(x))$ eine Funktion $g \circ f: A \rightarrow C$ definiert, die sog. Konkatenation/Hintereinanderschaltung/Verkettung/Verkopplung von f und g (gesprochen "g nach f").

Satz: $f:A\rightarrow B, g:B\rightarrow C$ sind Funktionen. Sind f,g bijektiv, so ist auch $g \circ f: A\rightarrow C$ bijektiv

Satz: ist $f:A\rightarrow B$ bijektiv, so ist $f^{-1}$ eine Funktion B nach A. Mengen A,B, heißen gleichmächtig ($|A|=|B| \equiv A\cong B$) falls Bijektion von A nach B. $\cong$ ist auf jeder Menge von Mengen eine Äquivalenzrelation
- "$\cong$ reflexiv": $A\cong A$, denn $f:A\rightarrow A, f(x)=X$, ist Bijektion von A nach A
- "$\cong$ symetrisch": Aus $A\cong B$ folgt Bijektion von A nach B $\rightarrow B\cong A$
- "$\cong$ transitiv": Aus $A\cong B$ und $B\cong C$ folgt $A\cong C$

$|A|=|A|:|A|$ ist die Kordinalität von A, d.h. die kleisnte zu A gleichmächtige Ordinalzahö. Eine Ordinalzahl ist eine e-transitive Menge von e-transitiven Mengen. Eine Menge X heißt e-transitiv, wenn aus $a\in b$ und $b\in c$ stets $a\in c$ folgt.
Sei $A:=\N$ und $B={0,2,4,...}={n\in \N: 2|n}$, dann sind A und B gleichmächtig, denn $f:A\rightarrow B, f(x)=2x$ ist Bijektion von A nach B.
Eine Menge A heißt endlich, wenn sie gleichmächtig zu einer natürlichen Zahl ist; sonst heißt A unendlich.
Eine Menge A heißt Deckend-unendlich, falls es eine Injektion $f:A\rightarrow B$ gibt die nicht surjektiv ist.

Satz: A unendlich $\leftrightarrow$ A deckend-unendlich
A,B sind Mengen. A heißt höchstens so mächtig wie B, falls es eine Injektion von A nach B gibt. $|A|\leq |B|$ bzw $A\preceq B$. $\preceq$ ist Quasiordnung auf jeder Menge von Mengen.
- "\preceq$ reflexiv": Injektion von A nach A
- "\preceq$ transitiv": $A\preceq B$ und $B\preceq C$ folgt Injektion $f:A\rightarrow B$ und $g:B\rightarrow C$. Verkopplung $g \circ f \rightarrow A \preceq C$

Satz (Vergleichbarkeitssatz):
Für zwei Mengen A,B gilt $|A|\leq |B|$ oder $|B| \leq |A|$. Eine Relation f von A nach B heißt partielle Bijektion (oder Matching), falls es Teilmengen $A'\subseteq A$ und $B'\subseteq B$ gibt sodass f eine Bijektion von A' nach B' gibt.

Sei M die Menge aller Matchings von A nach B und wie jede Menge durch $\subseteq$ geordnet. Sei $K\subseteq M$ eine Kette von Matchings. K besitzt eine obere Schranke ($\bigcup K$) in M. Seien $(x,y);(x',y')$ zwei Zuordnungspfeile aus $\bigcup K$, zeige $x\not = x'$ und $y\not = y'$ dann folgt Matching.
Jede Kette von Matchings benutzt eine obere Schranke, die ebenfalls ein Matching ist $\rightarrow$ es gibt ein maximales Matching von A nach B, etwa h. Im Fall ($x\in A, y\in B$ mit $(x,y)\in h$) ist h eine Injektion von A nach B, d.h. $|A| \subseteq |B|$ andernfalls $y\in B, x\in A$ mit $(x,y)}\in h$ ist $h^{-1}$ eine Injektion von B nach A, d.h. $|B| \subseteq |A|$.

## Satz - Cantor/Schröder/Bernstein
Für zwei Mengen A,B gilt: Aus $|A|\subseteq |B|$ und $|B| \subseteq |A|$ folgt $|A| = |B|$.

Die Komponenten von f und g sind:
- endliche Kreise
- einseitig unendliche Wege
- beidseitig unendliche Wege

## Satz Cantor
Für jede Menge X gilt: $|X|\leq \wp(X)$ und $|X|\not = |\wp (X)|$. Z.B. ist $|\N|<|\R|$; zu $|\N|$ gleichmächtige Mengen nennt man abzählbar; unendliche nicht-abzählbare Mengen nennt man überzählbar.

## Kontinuitätshypothese
Aus $|\N|\leq |A| \leq |\R|$ folgt $|A|=|\N|$ oder $|A|=|\R|$ (keine Zwischengrößen)